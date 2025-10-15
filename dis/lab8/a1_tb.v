`timescale 1ns/1ns
`include "a1.v"

module a1_tb;

	parameter n = 8;

	reg clk, rst, si;
	wire so;

	a1 #(.n(n)) add1 (
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
		$dumpfile("a1_tb.vcd");
		$dumpvars(0, a1_tb);

        rst = 1;
        si = 0;
        #10;
        rst = 0;

        #10 si = 1;
        #10 si = 0;
        #10 si = 1;
        #10 si = 1;
        #10 si = 0;
        #10 si = 1;
        #10 si = 0;
        #10 si = 0;

        #40 si = 0;

        #50 $finish;
    end

endmodule