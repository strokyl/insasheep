/*
 * Milkymist SoC
 * Copyright (C) 2013 Fernand Lone-Sang
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

`timescale 1ns / 500ps
`define CLOCK_FREQUENCY 	80000000
`define BAUD_RATE				115200


module tb_system();

reg sys_clk;
reg sys_rst;

//-------------------------------------------------------------------
// Simulating system
//-------------------------------------------------------------------
wire clkin;

wire uart_rx;
wire uart_tx;

reg btnl;
reg btns;
reg btnr;
wire led0;

system dut (
	.clkin(clkin), 
	.uart_rx(uart_rx), 
	.uart_tx(uart_tx), 
	.btnl(btnl), 
	.btns(btns), 
	.btnr(btnr),
	.led0(led0)
);

//-------------------------------------------------------------------
// Simulating UART partner
//-------------------------------------------------------------------
reg [13:0] csr_a;
reg csr_we;
reg [31:0] csr_dw;
wire [31:0] csr_dr;

localparam STDIN = 32'h80000000;
localparam STDOUT = 32'h80000001;

localparam CSR_UART_RXTX = 14'h000;
localparam CSR_UART_DIVISOR = 14'h001;
localparam CSR_UART_STAT = 14'h002;
localparam CSR_UART_CTRL = 14'h003;
localparam CSR_UART_DEBUG = 14'h004;

localparam UART_STAT_THRE = 32'h00000001;
localparam UART_STAT_RX_EVT = 32'h00000002;
localparam UART_STAT_TX_EVT = 32'h00000004;

localparam UART_CTRL_RX_INT = 32'h00000001;
localparam UART_CTRL_TX_INT = 32'h00000002;
localparam UART_CTRL_THRU = 32'h00000004;

localparam UART_DEBUG_BREAK_EN = 32'h00000001;

uart #(
	.csr_addr(4'h0),
	.clk_freq(`CLOCK_FREQUENCY),
	.baud(`BAUD_RATE),
	.break_en_default(1'b1)
) tb_uart (
	.sys_clk(sys_clk),
	.sys_rst(sys_rst),

	.csr_a(csr_a),
	.csr_we(csr_we),
	.csr_di(csr_dw),
	.csr_do(csr_dr),

	.irq(uart_irq),
	.uart_rx(uart_tx),
	.uart_tx(uart_rx),
	.break()
);


//------------------------------------------------------------------
// Helper Functions
//------------------------------------------------------------------
task csr_write;
	input [13:0] address; 
	input [31:0] data;
	begin
		csr_a = address;
		csr_we = 1'b1;
		csr_dw = data;
		@(posedge sys_clk);
		
		csr_we = 1'b0;
		@(posedge sys_clk);
		
		@(posedge sys_clk);
	end
endtask

task csr_read;
	input  [13:0] address;
	output [31:0] data;
	begin
		csr_a = address;		
		csr_we = 1'b0;

		@(posedge sys_clk);
		@(posedge sys_clk); 
		data = csr_dr;
	end
endtask

reg [31:0] stat;
reg [31:0] data;
always @(posedge sys_clk)
begin
	if (uart_irq) begin
		// Read/Write from/to CSR_UART_STAT
		csr_read(CSR_UART_STAT, stat);
		csr_write(CSR_UART_STAT, stat);

		// Process RX Events
		if (stat & UART_STAT_RX_EVT) begin
			csr_read(CSR_UART_RXTX, data);
			$display( "[UART] R: %h (%c)", data, data[7:0]);
		end
	end
end

task uart_write;
	input [7:0] datab;
	reg [31:0] stat;
	begin
		csr_write(CSR_UART_RXTX, {24'b0, datab});
		$display( "[UART] W: %h (%c)", datab, datab[7:0]);

		csr_read(CSR_UART_STAT, stat);
		while (!(stat & UART_STAT_THRE)) begin
			csr_read(CSR_UART_STAT, stat);
		end
	end
endtask

task uart_init;
	reg [31:0] stat;
	begin
		// Ack any events
		csr_read(CSR_UART_STAT, stat);
		csr_write(CSR_UART_STAT, stat);

		// Enable Interrupts
		csr_write(CSR_UART_CTRL, UART_CTRL_RX_INT|UART_CTRL_TX_INT);
	end
endtask

//------------------------------------------------------------------
// Main Stimuli
//------------------------------------------------------------------

// Generate 80Mhz clock
always #6.25  sys_clk = ~sys_clk; 
assign clkin = sys_clk;

initial begin
	//$dumpfile("system.vcd");
	//$dumpvars(0, dut);

	// Initialize inputs
	sys_clk = 1'b0;
	sys_rst = 1'b0;

	btnr = 1'b0;
	btnl = 1'b0;
	btns = 1'b0;

	// UART I/O
	uart_init();

	//$finish;
end
      
endmodule
