`timescale 1ns/1ns
`include "q2.v"

module q2_tb;
	reg [3:0] d;
	reg [1:0] s;
	wire f;

	q2 ques2 (
		.d(d),
		.s(s),
		.f(f)
	);

	initial begin
		$dumpfile("q2_tb.vcd");
		$dumpvars(0, q2_tb);

		d = 4'b1010; // d[3]=1, d[2]=0, d[1]=1, d[0]=0

		// test cases
		s = 2'b00; #20;  // f = d[0] = 0
        s = 2'b01; #20;  // f = d[1] = 1
        s = 2'b10; #20;  // f = d[2] = 0
        s = 2'b11; #20;  // f = d[3] = 1

		$display("Test complete");
	end
endmodule