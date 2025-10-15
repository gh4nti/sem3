`timescale 1ns/1ns
`include "q3.v"

module q3_tb;

	reg clk;
	reg rst;
	reg j;
	reg k;
	wire q;

	q3 ques3 (
		.clk(clk),
		.rst(rst),
		.j(j),
		.k(k),
		.q(q)
	);

	always #5 clk = ~clk;

	initial begin
		$dumpfile("q3_tb.vcd");
		$dumpvars(0, q3_tb);

		clk = 0;
        rst = 0;
        j = 0;
        k = 0;

		#3 rst = 1;
		#10 rst = 0;

		#5 j = 0; k = 1;
		#10 j = 1; k = 0;
		#10 j = 1; k = 1;
		#10 j = 0; k = 0;
		#10 j = 1; k = 1;

		#5 rst = 1;
		#10 rst = 0;

		#10 j = 1; k = 0;
		#10 j = 0; k = 1;
		#10 j = 1; k = 1;

		#20 $finish;

		$display("Test complete");
	end

endmodule