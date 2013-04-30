`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:57:53 04/07/2013 
// Design Name: 
// Module Name:    operator 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module operator(
	input clk_100MHz,
	input operation_enable,
	input [7:0] data_in,
	output reg [7:0] data_out
    );
	 
	wire clk_1Hz;
	clk_divisor #(10000000) divisor0(clk_100MHz, clk_1Hz);
	
	 
	 always @(posedge clk_1Hz) begin
		if(operation_enable)
			data_out <= data_in + 1;
	end

endmodule

