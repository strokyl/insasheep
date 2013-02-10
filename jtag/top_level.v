//
// Copyright (C) 2009-2012 Chris McClelland
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

`define LOW_BYTE 0
`define HIGH_BYTE 1;

`define INIT_PROCESS							0
`define WAIT_COMMAND				 			1
`define LOAD_BASE_ADDRESS_BYTE0 			2
`define LOAD_BASE_ADDRESS_BYTE1 			3
`define LOAD_BASE_ADDRESS_BYTE2 			4
`define MULTIPLEX_COMMAND					5

`define WRITE_DATA							6
`define LOAD_LOW_BYTE_FROM_USB			7
`define LOAD_HIGH_BYTE_FROM_USB			8
`define SEND_DATA_TO_FLASH					9
`define UPDATE_STATUS						10
`define END_WRITING							11

`define READ_DATA								12
`define LOAD_DATA_FROM_FLASH				13
`define SEND_LOW_BYTE_TO_USB				14
`define CHANGE_BYTE_TO_USB					15
`define SEND_HIGH_BYTE_TO_USB				16


`define END_PROCESS							17








`define READ 0
`define WRITE 1
`define STOP_PROCESS 2

module
	top_level(
		// FX2 interface -----------------------------------------------------------------------------
		input  wire      fx2Clk_in,     // 48MHz clock from FX2
		output wire[1:0] fx2Addr_out,   // select FIFO: "10" for EP6OUT, "11" for EP8IN
		inout  wire[7:0] fx2Data_io,    // 8-bit data to/from FX2

		// When EP6OUT selected:
		output wire      fx2Read_out,   // asserted (active-low) when reading from FX2
		output wire      fx2OE_out,     // asserted (active-low) to tell FX2 to drive bus
		input  wire      fx2GotData_in, // asserted (active-high) when FX2 has data for us

		// When EP8IN selected:
		output wire      fx2Write_out,  // asserted (active-low) when writing to FX2
		input  wire      fx2GotRoom_in, // asserted (active-high) when FX2 has room for more data from us
		output wire      fx2PktEnd_out, // asserted (active-low) when a host read needs to be committed early
		
		output [25:0] flash_address,
		inout [15:0] flash_data,
		output flash_oe_n,
		output flash_we_n,
		output flash_ce,
		output flash_rst,
	
		//output wire[7:0]  sseg_out,
		//output wire[3:0]  anode_out
		
		//output wire start_led,
		//output wire done_led,
		input reset_btn
	);

	// Channel read/write interface -----------------------------------------------------------------
	wire[6:0]  chanAddr;  // the selected channel (0-127)

	// Host >> FPGA pipe:
	wire[7:0]  h2fData;   // data lines used when the host writes to a channel
	wire       h2fValid;  // '1' means "on the next clock rising edge, please accept the data on h2fData_out"
	reg        h2fReady;  // channel logic can drive this low to say "I'm not ready for more data yet"

	// Host << FPGA pipe:
	wire[7:0]  f2hData;   // data lines used when the host reads from a channel
	reg        f2hValid;  // channel logic can drive this low to say "I don't have data ready for you"
	wire       f2hReady;  // '1' means "on the next clock rising edge, put your next byte of data on f2hData_in"
	// ----------------------------------------------------------------------------------------------

	// Needed so that the comm_fpga_fx2 module can drive both fx2Read_out and fx2OE_out
	wire       fx2Read;
	
	wire [3:0] dots = 0;

	// Assert that there's always data for reading, and always room for writing
                                               //END_SNIPPET(registers)
	
	// CommFPGA module
	assign fx2Read_out = fx2Read;
	assign fx2OE_out = fx2Read;
	assign fx2Addr_out[1] = 1'b1;  // Use EP6OUT/EP8IN, not EP2OUT/EP4IN.
	comm_fpga_fx2 comm_fpga_fx2(
		// FX2 interface
		.fx2Clk_in(fx2Clk_in),
		.fx2FifoSel_out(fx2Addr_out[0]),
		.fx2Data_io(fx2Data_io),
		.fx2Read_out(fx2Read),
		.fx2GotData_in(fx2GotData_in),
		.fx2Write_out(fx2Write_out),
		.fx2GotRoom_in(fx2GotRoom_in),
		.fx2PktEnd_out(fx2PktEnd_out),

		// Channel read/write interface
		.chanAddr_out(chanAddr),
		.h2fData_out(h2fData),
		.h2fValid_out(h2fValid),
		.h2fReady_in(h2fReady),
		.f2hData_in(f2hData),
		.f2hValid_in(f2hValid),
		.f2hReady_out(f2hReady)
	);
	
	// Flash controller
	reg [4:0] state = `INIT_PROCESS;
	reg [23:0] base_address;
	reg [7:0] command;
	//reg process_started;
	//reg process_done;
	reg [15:0] data;
	reg [23:0] currentAddress;
	reg writing;
	reg reading;
	
	// The process is writing memory to flash
	reg write_flash;
	// The process is reading memory from flash
	reg read_flash;
	
	//reg transfer_to_usb;
	reg low_byte;
	
	//seven_seg sseven_s(fx2Clk_in, data, dots, sseg_out, anode_out);


	always @(posedge fx2Clk_in) begin
		if(reset_btn == 1)
			state <= `INIT_PROCESS;
		else begin
			case(state)
			`INIT_PROCESS: begin
				base_address <= 0;
				data <= 0;
				//process_started <= 0;
				//process_done <= 0;
				f2hValid <= 0;
				h2fReady <= 0;
				state <= `WAIT_COMMAND;
			end
			`WAIT_COMMAND: begin	
				write_flash <= 0;
				read_flash <= 0;
				writing <= 0;
				reading <= 0;
				h2fReady <= 1;
				f2hValid <= 0;
				if(chanAddr == 7'b0000000 && h2fValid == 1'b1) begin
					//process_started <= 1;
					command <= h2fData;
					h2fReady <= 0;
					state <= `LOAD_BASE_ADDRESS_BYTE0;
				end
			end
			
			`LOAD_BASE_ADDRESS_BYTE0: begin
				h2fReady <= 1;
				if(chanAddr == 7'b0000000 && h2fValid == 1'b1) begin
					base_address[7:0] <= h2fData;
					h2fReady <= 0;
					state <= `LOAD_BASE_ADDRESS_BYTE1;
				end
			end
			
			`LOAD_BASE_ADDRESS_BYTE1: begin
				h2fReady <= 1;
				if(chanAddr == 7'b0000000 && h2fValid == 1'b1) begin
					base_address[15:8] <= h2fData;
					h2fReady <= 0;
					state <= `LOAD_BASE_ADDRESS_BYTE2;
				end
			end
			`LOAD_BASE_ADDRESS_BYTE2: begin
				h2fReady <= 1;
				if(chanAddr == 7'b0000000 && h2fValid == 1'b1) begin
					base_address[23:16] <= h2fData;
					h2fReady <= 0;
					state <= `MULTIPLEX_COMMAND;
				end
			end
			
			`MULTIPLEX_COMMAND: begin
				if(command == `READ) begin
					read_flash <= 1;
					state <= `READ_DATA;
				end
				else if(command == `WRITE) begin
					write_flash <= 1;
					state <= `WRITE_DATA;
				end
				else if(command == `STOP_PROCESS) begin
					state <= `END_PROCESS;
				end
				else
					state <= `END_PROCESS;
			end
			
			
			//********* Beginning of the graph of writing ******
			`WRITE_DATA: begin
				currentAddress <= base_address;
				state <= `LOAD_LOW_BYTE_FROM_USB;
			end
			
			`LOAD_LOW_BYTE_FROM_USB: begin
				h2fReady <= 1;
				if(chanAddr == 7'b0000000 && h2fValid == 1'b1) begin
					data[7:0] <= h2fData;
					h2fReady <= 0;
					state <= `LOAD_HIGH_BYTE_FROM_USB;
				end
			end
			
			`LOAD_HIGH_BYTE_FROM_USB: begin
				h2fReady <= 1;
				if(chanAddr == 7'b0000000 && h2fValid == 1'b1) begin
					data[15:8] <= h2fData;
					writing <= 1;
					h2fReady <= 0;
					state <= `SEND_DATA_TO_FLASH;
				end
			end
			

			`SEND_DATA_TO_FLASH: begin
				// Effective write in flash
				writing <= 0;
				state <= `UPDATE_STATUS;
			end
			
			`UPDATE_STATUS: begin
				reading <= 1;
				state <= `END_WRITING;
			end
			
			`END_WRITING: begin
				reading <= 0;
				state <= `WAIT_COMMAND;
			end
			// END OF WRITING GRAPH
			
			
			
			//********* Beginning of the graph of reading ******
			// The ouput of the flash is enable through all the process.
			`READ_DATA: begin
				reading <= 1;
				currentAddress <= base_address;
				// Connect the low byte of data on f2hData(8 pins) bus
				low_byte <= 1;
				state <= `LOAD_DATA_FROM_FLASH;
			end
			
			`LOAD_DATA_FROM_FLASH: begin
				data <= flash_data;
				state <= `SEND_LOW_BYTE_TO_USB;
			end
			
			`SEND_LOW_BYTE_TO_USB: begin
				if(f2hReady == 1) begin
					f2hValid <= 1;
					reading <= 0;
					state <= `CHANGE_BYTE_TO_USB;
				end
			end
			
			`CHANGE_BYTE_TO_USB: begin
				f2hValid <= 0;
				low_byte <= 0;
				reading <= 1;
				state <= `SEND_HIGH_BYTE_TO_USB;
			end
			
			`SEND_HIGH_BYTE_TO_USB: begin
				if(f2hReady == 1) begin
					f2hValid <= 1;
					reading <= 0;
					state <= `WAIT_COMMAND;
				end
			end
			
			`END_PROCESS: begin
				//process_done <= 1;
			end
			
			endcase
		end
	end

	
	//assign start_led = process_started;
	//assign done_led = process_done;
	
	// Decides whether we have the bus, flash_data is a bidirectional bus
	assign flash_data = (write_flash)? data : 16'bZ;
	assign flash_address = currentAddress;
	
	//assign f2hReady = transfer_to_usb;
	assign f2hData = (low_byte)? data[7:0] : data[15:8];
	
	assign flash_ce = 0;
	assign flash_rst = 1;
	assign flash_we_n = !(write_flash && writing);
	assign flash_oe_n = !(read_flash) || !reading;
	
endmodule
