`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:15:27 02/27/2013 
// Design Name: 
// Module Name:    displayer 
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
module displayer(
	input clk,
	input [7:0]data,
	output [7:0] led_out
    );

	reg [7:0] led_state = 7'b0;
	
	always @(posedge clk)
		led_state <= data;
	
	assign led_out = led_state;

endmodule
