`timescale 1ns/1ns
`include "q2.v"

module q2_tb;

	parameter n = 8;

	reg clk, rst;
	reg [n-1:0] d;
	wire [n-1:0] q;

	q2 ques2 (
		.clk(clk),
		.rst(rst),
		.d(d),
		.q(q)
	);

	initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

	initial begin
		$dumpfile("q2_tb.vcd");
		$dumpvars(0, q2_tb);

        rst = 0;
        d = 0;

        #10;
        rst = 1;
        #10;
        rst = 0;

        #10 d = 8'b10101010;
        #10 d = 8'b11110000;
        #10 d = 8'b00001111;
        #10 d = 8'b11001100;

        #10 rst = 1;
        #10 rst = 0;

        #10 d = 8'b11111111;

        #20 $finish;
    end

endmodule