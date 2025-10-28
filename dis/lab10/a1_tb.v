`timescale 1ns/1ns
`include "a1.v"

module a1_tb;

	reg clk, rst, x;
	wire [3:0] q;

	a1 add1 (
		.clk(clk),
		.rst(rst),
		.x(x),
		.q(q)
	);

	initial begin
		clk = 0;
		forever #5 clk = ~clk;
	end

	initial begin
		$dumpfile("a1_tb.vcd");
		$dumpvars(0, a1_tb);

		clk = 0;
        rst = 1;
		x = 1;

		#10;
		rst = 0;

		x = 1;
		#100;

		w = 0;
		#100;

		$finish;
	end

endmodule