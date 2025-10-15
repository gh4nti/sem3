`timescale 1ns/1ns
`include "q1.v"

module q1_tb;

	reg clk;
	reg rst;
	reg d;
	wire q;

	q1 ques1 (
		.clk(clk),
		.rst(rst),
		.d(d),
		.q(q)
	);

	always #5 clk = ~clk;

	initial begin
		$dumpfile("q1_tb.vcd");
		$dumpvars(0, q1_tb);

		clk = 0;
        rst = 0;
        d = 0;

		#2 rst = 1;
		#5 rst = 0;

		#5 d = 1;
		#10 d = 0;
		#10 d = 1;

		#7 rst = 1;
		#5 rst = 0;

		#10 d = 1;
        #10 d = 0;

		#20 $finish;

		$display("Test complete");
	end

endmodule