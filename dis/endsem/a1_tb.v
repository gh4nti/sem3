`timescale 1ns/1ns
`include "a1.v"

module a1_tb;

	reg clk, rst;
	reg [3:0] a, b;
	wire [3:0] q;
	integer i, j, err;
	wire [3:0] exp;

	a1 compmux4bit (
		.clk(clk),
		.rst(rst),
		.a(a),
		.b(b),
		.q(q)
	);

	initial begin
		clk = 0;
		forever #5 clk = ~clk;
	end

	initial begin
		
		$dumpfile("a1_tb.vcd");
		$dumpvars(0, a1_tb);

		rst = 0;
		a = 0; b = 0;
		err = 0;

		#12; rst = 1;

		for (i = 0; i < 16; i = i + 1) begin
			for (j = 0; j < 16; j = j + 1) begin
				a = i; b = j;

				if (a <= b)
					exp = a;
				else
					exp = b;
				
				@(negedge clk); #1;

				if (q !== exp)
					err = err + 1;
			end
		end

		if (err == 0)
			$display("All test cases passed!");
		else
			$display("%d test cases failed!", err);
		
		#10 $finish;

	end

endmodule