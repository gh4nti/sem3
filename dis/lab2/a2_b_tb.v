`timescale 1ns/1ns
`include "a2_b.v"

module a2_b_tb();
	reg a, b, c, d;
	wire f;

	a2_b add2_b(a, b, c, d, f);
	initial begin

		$dumpfile("a2_b_tb.vcd");
		$dumpvars(0, a2_b_tb);
		
		a = 1'b0; b = 1'b0; c = 1'b0; d = 1'b0;
		#20
		
		a = 1'b0; b = 1'b0; c = 1'b0; d = 1'b1;
		#20
		
		a = 1'b0; b = 1'b0; c = 1'b1; d = 1'b0;
		#20
		
		a = 1'b0; b = 1'b0; c = 1'b1; d = 1'b1;
		#20
		
		a = 1'b0; b = 1'b1; c = 1'b0; d = 1'b0;
		#20
		
		a = 1'b0; b = 1'b1; c = 1'b0; d = 1'b1;
		#20
		
		a = 1'b0; b = 1'b1; c = 1'b1; d = 1'b0;
		#20
		
		a = 1'b0; b = 1'b1; c = 1'b1; d = 1'b1;
		#20
		
		a = 1'b1; b = 1'b0; c = 1'b0; d = 1'b0;
		#20
		
		a = 1'b1; b = 1'b0; c = 1'b0; d = 1'b1;
		#20
		
		a = 1'b1; b = 1'b0; c = 1'b1; d = 1'b0;
		#20
		
		a = 1'b1; b = 1'b0; c = 1'b1; d = 1'b1;
		#20
		
		a = 1'b1; b = 1'b1; c = 1'b0; d = 1'b0;
		#20
		
		a = 1'b1; b = 1'b1; c = 1'b0; d = 1'b0;
		#20
		
		a = 1'b1; b = 1'b1; c = 1'b0; d = 1'b0;
		#20
		
		a = 1'b1; b = 1'b1; c = 1'b0; d = 1'b0;
		#20
		
		$display("Test complete");
	
end endmodule