`timescale 1ns/1ns
`include "q1.v"

module q1_tb;

	reg clk, rst;
	wire [3:0] q;

	q1 ques1 (
		.clk(clk),
		.rst(rst),
		.q(q)
	);

	initial begin
		clk = 0;
		forever #5 clk = ~clk;
	end

	initial begin
		$dumpfile("q1_tb.vcd");
		$dumpvars(0, q1_tb);

		clk = 0;
        rst = 1;

		#15;
		rst = 0;

		#100;

		$finish;
	end

endmodule