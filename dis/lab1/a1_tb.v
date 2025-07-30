`timescale 1ns/1ns
`include "a1.v"

module a1_tb();
	reg a, b, c;
	wire f1, f2;

	a1 add1(a, b, c, f1, f2);
	initial begin

		$dumpfile("a1_tb.vcd");
		$dumpvars(0, a1_tb);
		
		a = 1'b0; b = 1'b0; c = 1'b0;
		#20
		
		a = 1'b0; b = 1'b0; c = 1'b1;
		#20
		
		a = 1'b0; b = 1'b1; c = 1'b0;
		#20
		
		a = 1'b0; b = 1'b1; c = 1'b1;
		#20
		
		a = 1'b1; b = 1'b0; c = 1'b0;
		#20
		
		a = 1'b1; b = 1'b0; c = 1'b1;
		#20
		
		a = 1'b1; b = 1'b1; c = 1'b0;
		#20
		
		a = 1'b1; b = 1'b1; c = 1'b1;
		#20
		
		$display("Test complete");
	
end endmodule