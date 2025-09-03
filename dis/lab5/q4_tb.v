`timescale 1ns/1ns
`include "q4.v"

module q4_tb;

	reg [15:0] d;
	reg [3:0] s;
	wire f;

	q4 ques4 (
		.d(d),
		.s(s),
		.f(f)
	);

	initial begin
		$dumpfile("q4_tb.vcd");
		$dumpvars(0, q4_tb);

		d = 16'b1101_0110_1001_1110;

		// test cases
        s = 4'b0000; #10;  // f = d[0]
        s = 4'b0011; #10;  // f = d[3]
        s = 4'b1001; #10;  // f = d[9]
        s = 4'b1111; #10;  // f = d[15]

		$display("Test complete");
	end

endmodule