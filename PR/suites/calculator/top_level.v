`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:09:32 02/27/2013 
// Design Name: 
// Module Name:    top_level 
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
	output [7:0] data_out);
endmodule

module top_level(
		input clk_100MHz,
		output [7:0] led_out
    );
	 
	 wire [7:0] data;
	 wire [7:0] operation_result;
	 wire operation_enable;

	
	 displayer displayer0(clk_100MHz, data, led_out);
	 
	 calculator calculator0(clk_100MHz, operation_enable, data, operation_result);
	 operator op0(clk_100MHz, operation_enable, data, operation_result);
endmodule




