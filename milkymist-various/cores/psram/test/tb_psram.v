`timescale 1ns / 1ps

module tb_psram();

reg sys_clk;
reg sys_rst;

reg [31:0] wb_adr_i;
wire [31:0] wb_dat_o;
reg [31:0] wb_dat_i;
reg [3:0] wb_sel_i;
reg wb_stb_i;
reg wb_cyc_i;
wire wb_ack_o;
reg wb_we_i;

wire [22:0] psram_adr;
wire psram_oe_n;
wire psram_we_n;
wire psram_ce_n;
wire psram_cre;
wire psram_wait;
wire psram_adv_n;
wire psram_clk;
wire psram_lb;
wire psram_ub;

`ifdef PSRAM_SPLIT_INOUT
wire [15:0] psram_di;
wire [15:0] psram_do;
assign psram_dq = psram_oe_n ? psram_do : 16'bz;
assign psram_di = psram_dq;
`else
wire [15:0] psram_dq;
`endif

cellram psram (
	.clk(psram_clk),
	.adv_n(psram_adv_n),
	.cre(psram_cre),
	.o_wait(psram_wait),
	.ce_n(psram_ce_n),
	.oe_n(psram_oe_n),
	.we_n(psram_we_n),
	.ub_n(psram_ub),
	.lb_n(psram_lb),
	.addr(psram_adr),
	.dq(psram_dq)
);

psram #(
	.adr_width(23)
) dut (
	.sys_clk(sys_clk), 
	.sys_rst(sys_rst), 

	.wb_adr_i(wb_adr_i), 
	.wb_dat_o(wb_dat_o), 
	.wb_dat_i(wb_dat_i), 
	.wb_sel_i(wb_sel_i), 
	.wb_stb_i(wb_stb_i), 
	.wb_cyc_i(wb_cyc_i), 
	.wb_ack_o(wb_ack_o), 
	.wb_we_i(wb_we_i), 

	.psram_adr(psram_adr), 
`ifdef PSRAM_SPLIT_INOUT
	.psram_di(psram_di), 
	.psram_do(psram_do), 
`else
	.psram_dq(psram_dq), 
`endif
	.psram_oe_n(psram_oe_n), 
	.psram_we_n(psram_we_n), 
	.psram_ce_n(psram_ce_n), 
	.psram_cre(psram_cre), 
	.psram_wait(psram_wait), 
	.psram_adv_n(psram_adv_n), 
	.psram_clk(psram_clk), 
	.psram_lb(psram_lb), 
	.psram_ub(psram_ub)
);

// Generate 80Mhz clock
always #6.25  sys_clk = ~sys_clk; 

task wbread;
	input [31:0] address;
	begin
		wb_adr_i = address;
		wb_cyc_i = 1'b1;
		wb_stb_i = 1'b1;
		
        /* Wait for 1/2 clock in order to avoid boundary cases */
        #6.25;

		/* Let the core release its ack */
		wait(wb_ack_o);

		$display("Read address %h completed, result %h", address, wb_dat_o);
		
		/* Let the core release its ack */
		#12.5
		
		wb_cyc_i = 1'b0;
		wb_stb_i = 1'b0;
	end
endtask

task wbwrite;
	input [31:0] address;
    input [31:0] data;
	begin
		wb_adr_i = address;
        wb_dat_i = data;
		wb_cyc_i = 1'b1;
		wb_stb_i = 1'b1;
		wb_we_i  = 1'b1;

        /* Wait for 1/2 clock in order to avoid boundary cases */
        #6.25;

		/* Let the core release its ack */
		wait(wb_ack_o);
	
        /* wait for one clock before asserting */
        #12.5 $display("%d Write %h at address %h completed", $realtime, data, address);

		wb_cyc_i = 1'b0;
		wb_stb_i = 1'b0;
		wb_we_i  = 1'b0;
	end
endtask


initial begin
	// $dumpfile("psram.vcd");

	sys_clk = 1'b0;
	sys_rst = 1'b1;

	wb_adr_i = 32'h00000000;
	wb_dat_i = 32'h00000000;
	wb_sel_i = 4'h0;
	wb_stb_i = 1'b0;
	wb_cyc_i = 1'b0;
	wb_we_i = 1'b0;

	#25 sys_rst = 1'b0;

	// Wait for the core to be configured
	#151000;

    // Test for consecutive 4 bytes write
 	wb_sel_i = 4'b1111;
    wbwrite(32'h0000fff0, 32'h00010203);
    wbwrite(32'h0000fff4, 32'h04050607);

    // Test for one byte write
    wb_sel_i = 4'b0001;
    wbwrite(32'h0000fff8, 32'h00000008);
    wb_sel_i = 4'b0010;
    wbwrite(32'h0000fff9, 32'h00000900);
    wb_sel_i = 4'b0100;
    wbwrite(32'h0000fffa, 32'h000a0000);
    wb_sel_i = 4'b1000;
    wbwrite(32'h0000fffb, 32'h0b000000);

    // Test for two bytes write
    wb_sel_i = 4'b0011;
    wbwrite(32'h0000fffc, 32'h00000c0d);
    wb_sel_i = 4'b1100;
    wbwrite(32'h0000fffe, 32'h0e0f0000);

	// Test for consecutive 4 bytes read
    wb_sel_i = 4'b1111;
    wbread(32'h0000fff0);
    wbread(32'h0000fff4);

    // Test for one byte write
    wb_sel_i = 4'b0001;
    wbread(32'h0000fff8);
    wb_sel_i = 4'b0010;
    wbread(32'h0000fff9);
    wb_sel_i = 4'b0100;
    wbread(32'h0000fffa);
    wb_sel_i = 4'b1000;
    wbread(32'h0000fffb);

    // Test for two bytes write
    wb_sel_i = 4'b0011;
    wbread(32'h0000fffc);
    wb_sel_i = 4'b1100;
    wbread(32'h0000fffe);

    // TODO: check tCEM violation
	#25;

	$finish;
end
      
endmodule
