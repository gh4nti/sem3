`timescale 1ns/1ns
`include "q3.v"

module q3_tb;
	reg [3:0] a;
	reg en;
	wire [15:0] y;

	q3 ques3 (
		.a(a),
		.en(en),
		.y(y)
	);

	integer i;

	initial begin
		$dumpfile("q3_tb.vcd");
		$dumpvars(0, q3_tb);

		en = 1;

		for (i = 0; i < 16; i = i + 1) begin
        	a = i; #20;
    	end

		en = 0; a = 4'b1010; #20;

		$display("Test complete");
	end
endmodule