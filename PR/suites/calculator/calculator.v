`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:22:05 02/27/2013 
// Design Name: 
// Module Name:    calculator 
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
module calculator(
		input clk_100MHz,
		output operation_enable,
		output [7:0] c2oData,
		input [7:0] o2cData
    );

	reg [7:0] currentValue;

	always @(posedge clk_100MHz) begin
		currentValue <= o2cData;
	end
	
	assign c2oData = currentValue;
	assign operation_enable = 1'b1;

endmodule
