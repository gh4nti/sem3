`timescale 1ns/1ns
`include "a3.v"

module a3_tb;

	reg clk, rst;
	reg [3:0] a, y;

	a3 add3 (
		.clk(clk),
		.rst(rst),
		.a(a),
		.y(y)	
	);

	initial begin
		clk = 0;
		forever #5 clk = ~clk;
	end

	initial begin
		$dumpfile("a3_tb.vcd");
		$dumpvars(0, a3_tb);

		clk = 0;
		rst = 1;

		a = 4'b1011;

		#10;
		rst = 0;

		#100;

		$finish;
	end

endmodule