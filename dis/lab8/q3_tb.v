`timescale 1ns/1ns
`include "q3.v"

module q3_tb;

	reg clk, rst;
	wire [4:0] q;

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

        rst = 1;
        #10 rst = 0;

        #200;

        $finish;
    end

endmodule