`timescale 1ns/1ns
`include "q1.v"

module q1_tb;

	reg clk, E, x;
	wire a, b;

	q1 ques1 (
		.clk(clk),
		.E(E),
		.x(x),
		.a(a),
		.b(b)
	);

	initial begin
		clk = 0;
		forever #5 clk = ~clk;
	end

	initial begin
		$dumpfile("q1_tb.vcd");
		$dumpvars(0, q1_tb);

		E = 0; x = 0; #10;
		E = 1; x = 1; #40;
		E = 1; x = 0; #40;
		E = 0; #20;

		$finish;
	end

endmodule