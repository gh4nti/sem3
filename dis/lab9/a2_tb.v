`timescale 1ns/1ns
`include "a2.v"

module a2_tb;

	reg clk, rst, x;
	wire y;

	a2 add2 (
		.clk(clk),
		.rst(rst),
		.x(x),
		.y(y)
	);

	initial begin
		clk = 0;
		forever #5 clk = ~clk;
	end

	initial begin
		$dumpfile("a2_tb.vcd");
		$dumpvars(0, a2_tb);

		rst = 1; x = 0; #10;
		rst = 0; x = 0; #10;
		x = 1; #10;
		x = 0; #10;
		x = 1; #10;
		x = 1; #10;
		x = 0; #10;
		rst = 1; #10;
		rst = 0; x = 1; #10;
		x = 0; #10;

		$finish;
	end

endmodule