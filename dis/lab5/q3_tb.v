`timescale 1ns/1ns
`include "q3.v"

module q3_tb;

	reg [15:0] d;
	reg [3:0] s;
	wire f;

	q3 ques3 (
		.d(d),
		.s(s),
		.f(f)
	);

	initial begin
		$dumpfile("q3_tb.vcd");
		$dumpvars(0, q3_tb);

		d = 16'b1010_1100_1111_0001;

		// test cases
        s = 4'b0000; #20;  // f = d[0]
        s = 4'b0001; #20;  // f = d[1]
        s = 4'b0010; #20;  // f = d[2]
        s = 4'b1111; #20;  // f = d[15]

		$display("Test complete");
	end

endmodule