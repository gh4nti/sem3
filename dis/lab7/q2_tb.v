`timescale 1ns/1ns
`include "q2.v"

module q2_tb;

	reg clk;
	reg rst;
	reg t;
	wire q;

	q2 ques2 (
		.clk(clk),
		.rst(rst),
		.t(t),
		.q(q)
	);

	always #5 clk = ~clk;

	initial begin
		$dumpfile("q2_tb.vcd");
		$dumpvars(0, q2_tb);

		clk = 0;
		rst = 1;
		t = 0;

		#2 rst = 0;
		#5 rst = 1;

		#5 t = 1;
		#20 t = 0;
		#10 t = 1;

		#7 rst = 0;
		#5 rst = 1;

		#20 $finish;

		$display("Test complete");
	end

endmodule