`timescale 1ns/1ns
`include "q2.v"

module q2_tb;
	reg [3:0] a;
	reg en;
	wire [15:0] y;

	q2 ques2 (
		.a(a),
		.en(en),
		.y(y)
	);

	integer i;

	initial begin
		$dumpfile("q2_tb.vcd");
		$dumpvars(0, q2_tb);

		en = 1;

		for (i = 0; i < 16; i = i + 1) begin
        	a = i; #20;
    	end

		en = 0; a = 4'b1101; #20;

		$display("Test complete");
	end
endmodule