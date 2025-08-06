`timescale 1ns/1ns
`include "q2_a.v"

module q2_a_tb();
	reg a, b, c, d;
	wire f;

	q2_a ques2_a(a, b, c, d, f);
	initial begin

		$dumpfile("q2_a_tb.vcd");
		$dumpvars(0, q2_a_tb);
		
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