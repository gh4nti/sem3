`timescale 1ns/1ns
`include "q1.v"

module q1_tb;

	reg clk, rst, si;
	wire so;

	q1 ques1 (
		.clk(clk),
		.rst(rst),
		.si(si),
		.so(so)
	);

	initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

	initial begin
		$dumpfile("q1_tb.vcd");
		$dumpvars(0, q1_tb);

        rst = 0;
        si = 0;

        #10;
        rst = 1;

        #10 si = 1;
        #10 si = 0;
        #10 si = 1;
        #10 si = 1;
        #10 si = 0;
        #10 si = 1;

        #60 si = 0;

        #50;
        $finish;
    end

endmodule