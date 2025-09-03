`timescale 1ns/1ns
`include "q1.v"

module q1_tb;
	reg [3:0] a, b;
	wire a_gt_b, a_eq_b, a_lt_b;

	q1 ques1 (
		.a(a),
		.b(b),
		.a_gt_b(a_gt_b),
		.a_eq_b(a_eq_b),
		.a_lt_b(a_lt_b)
	);

	initial begin
		$dumpfile("q1_tb.vcd");
		$dumpvars(0, q1_tb);

		// test cases
		a = 4'b0000; b = 4'b0000; #20; // equal
        a = 4'b0101; b = 4'b0011; #20; // a > b
        a = 4'b0011; b = 4'b0101; #20; // a < b
        a = 4'b1111; b = 4'b1010; #20; // a > b
        a = 4'b1000; b = 4'b1000; #20; // equal

		$display("Test complete");
	end
endmodule