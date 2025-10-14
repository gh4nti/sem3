`timescale 1ns/1ns
`include "q1.v"

module q1_tb;
	reg [2:0] a;
	wire [7:0] y;

	q1 ques1 (
		.a(a),
		.y(y)
	);

	initial begin
		$dumpfile("q1_tb.vcd");
		$dumpvars(0, q1_tb);

		// test cases
		a = 3'b000; #20;
		a = 3'b001; #20;
		a = 3'b010; #20;
		a = 3'b011; #20;
		a = 3'b100; #20;
		a = 3'b101; #20;
		a = 3'b110; #20;
		a = 3'b111; #20;

		$display("Test complete");
	end
endmodule