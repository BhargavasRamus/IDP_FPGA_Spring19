`timescale 1 ps / 1 ps
// synopsys translate_on
module add (
	dataa,
	datab,
	cout,
	overflow,
	result);

	input	[10:0]  dataa;
	input	[10:0]  datab;
	output	reg  cout;
	output	reg  overflow;
	output reg	[10:0]  result;

  
  always @(dataa or datab) begin
    {cout,result} = dataa + datab;
    
    if((dataa[10]==datab[10])&&(datab[10]==result[10])&&(dataa[10]==result[10]))
      overflow = 1;
    else  if((dataa[10]==datab[10])&&(datab[10]!=result[10])&&(dataa[10]!=result[10])) begin
      overflow = 0;
    end
    else begin
      overflow = 1;
    end
      
  end
      

endmodule
