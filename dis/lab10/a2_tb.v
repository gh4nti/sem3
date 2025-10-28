`timescale 1ns/1ns
`include "a2.v"

module a2_tb;

	reg clk, rst;
	wire [3:0] units, tens;

	a2 add2 (
		.clk(clk),
		.rst(rst),
		.units(units),
		.tens(tens)	
	);

	initial begin
		clk = 0;
		forever #5 clk = ~clk;
	end

	initial begin
		$dumpfile("a2_tb.vcd");
		$dumpvars(0, a2_tb);

		clk = 0;
        rst = 1;
		
		#10;
		rst = 0;

		#1000;

		$finish;
	end

endmodule