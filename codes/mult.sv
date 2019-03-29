
`timescale 1 ps / 1 ps
// synopsys translate_on
module mult (
	dataa,
	datab,
	result);

	input	[8:0]  dataa;
	input	[7:0]  datab;
	output wire	[16:0]  result;

	assign result = dataa*datab;


endmodule