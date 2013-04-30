`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:58:57 04/07/2013 
// Design Name: 
// Module Name:    clk_divisor 
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
module clk_divisor(
	input clk_in,
	output reg clk_out
    );
	 parameter divisor=100000000;
	 
	 reg [26:0] counter = 27'b0;
	 
	 always @(posedge clk_in) begin
		if(counter == divisor/2) begin 
			clk_out <= ~clk_out;
			counter <= 27'b0;
		end
		else
			counter <= counter+1;
	end

endmodule
