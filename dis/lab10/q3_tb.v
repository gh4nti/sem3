`timescale 1ns/1ns;
`include "q3.v"

module q3_tb;

	reg clk, rst;
	wire [2:0] q;

	q3 ques3 (
		.clk(clk),
		.rst(rst),
		.q(q)
	);

	initial begin
		clk = 0;
		forever #5 clk = ~clk;
	end

	initial begin
		$dumpfile("q3_tb.vcd");
		$dumpvars(0, q3_tb);

		clk = 0;
		rst = 1;

		#15;
		rst = 0;

		#120;

		$finish;
	end

endmodule