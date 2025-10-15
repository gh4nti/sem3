`timescale 1ns/1ns
`include "a2.v"

module a2_tb;

	reg clk, rst;
	wire [7:0] t;

	a2 add2 (
		.clk(clk),
		.rst(rst),
		.t(t)
	);

	initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

	initial begin
		$dumpfile("a2_tb.vcd");
		$dumpvars(0, a2_tb);

        rst = 1;
        #10;
        rst = 0;

        #200;

        $finish;
    end

endmodule