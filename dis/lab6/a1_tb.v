`timescale 1ns/1ns
`include "a1.v"

module a1_tb;
	reg [3:0] a;
	reg en;
	wire [15:0] y;

	a1 add1 (
		.a(a),
		.en(en),
		.y(y)
	);

	integer i;

	initial begin
		$dumpfile("a1_tb.vcd");
		$dumpvars(0, a1_tb);

		en = 1;

		for (i = 0; i < 16; i = i + 1) begin
        	a = i; #20;
    	end

		en = 0; a = 4'b1101; #20;

		$display("Test complete");
	end
endmodule