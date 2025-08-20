`timescale 1ns/1ns
`include "q2.v"

module q2_tb;
	reg [3:0] a, b;
    reg mode;
    wire [3:0] result;
    wire cout;

	q2 ques2 (
		.a(a),
		.b(b),
		.mode(mode),
		.result(result),
		.cout(cout)
	);

	integer i, j;

	initial begin
		$dumpfile("q2_tb.vcd");
		$dumpvars(0, q2_tb);

		a = 4'b0101; b = 4'b0011; mode = 0; #20; // 5 + 3 = 8
		a = 4'b1100; b = 4'b0111; mode = 1; #20; // 12 - 7 = 5
		a = 4'b1001; b = 4'b0110; mode = 0; #20; // 9 + 6 = 15
		a = 4'b0111; b = 4'b1010; mode = 1; #20; // 7 - 10 = -3
		a = 4'b1111; b = 4'b1111; mode = 0; #20; // 15 + 15 = 30

		$display("Test complete");
	end
endmodule