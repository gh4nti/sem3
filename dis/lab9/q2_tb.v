`timescale 1ns/1ns
`include "q2.v"

module q2_tb;

	reg clk, x;
	wire a, b;

	q2 ques2 (
		.clk(clk),
		.x(x),
		.a(a),
		.b(b)
	);

	initial begin
		clk = 0;
		forever #5 clk = ~clk;
	end

	initial begin
		$dumpfile("q2_tb.vcd");
		$dumpvars(0, q2_tb);

		x = 0; #40;
        x = 1; #40;
        x = 0; #40;

		$finish;
	end

endmodule