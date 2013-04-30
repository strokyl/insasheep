module inout_switch #(
	parameter data_width = 16
) (
	output slv_oe,
	input [data_width-1:0] slv_di,
	output reg [data_width-1:0] slv_do,

	input m0_ce,
	input m0_oe,
	output reg [data_width-1:0] m0_di,
	input [data_width-1:0] m0_do,

	input m1_ce,
	input m1_oe,
	output reg [data_width-1:0] m1_di,
	input [data_width-1:0] m1_do
);

assign slv_oe = (m0_ce & m0_oe) | (m1_ce & m1_oe);

always @(*) begin
	if (m0_ce) begin
		slv_do = m0_do;
		m0_di  = slv_di;
//		m1_di  = {data_width{1'bz}};
	end
	else if (m1_ce) begin
		slv_do = m1_do;
//		m0_di  = {data_width{1'bz}};
		m1_di  = slv_di;
	end
// 	else begin
// 		slv_do = {data_width{1'bz}};
// 		m0_di  = {data_width{1'bz}};
// 		m1_di  = {data_width{1'bz}};
// 	end 
end

endmodule
