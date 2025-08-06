`timescale 1ns/1ns
`include "q1_b.v"

module q1_b_tb();
	reg a, b, c, d;
	wire f;

	q1_b ques1_b(a, b, c, d, f);
	initial begin

		$dumpfile("q1_b_tb.vcd");
		$dumpvars(0, q1_b_tb);
		
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