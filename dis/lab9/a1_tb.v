`timescale 1ns/1ns
`include "a1.v"

module a1_tb;
    reg clk, x;
    wire a, b;

    a1 add1 (
		.clk(clk),
		.x(x),
		.a(a),
		.b(b)
	);

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        $dumpfile("a1_tb.vcd");
		$dumpvars(0, a1_tb);

        x = 0; #30;
        x = 1; #30;
        x = 0; #30;
        x = 1; #30;
        
		$finish;
    end
endmodule