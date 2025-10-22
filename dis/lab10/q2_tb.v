`timescale 1ns/1ns
`include "q2.v"

module q2_tb;

	reg clk, rst;
	wire [3:0] q;

	q2 ques2 (
		.clk(clk),
		.rst(rst),
		.q(q)
	);

	initial begin
		clk = 0;
		forever #5 clk = ~clk;
	end

	initial begin
		$dumpfile("q2_tb.vcd");
		$dumpvars(0, q2_tb);

		clk = 0;
		rst = 1;

		#25;
		rst = 0;

		#400;

		$finish;
	end

endmodule