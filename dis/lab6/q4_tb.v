`timescale 1ns/1ns
`include "q4.v"

module q4_tb;
	reg [3:0] d;
	wire [1:0] y;

	q4 ques4 (
		.d(d),
		.y(y)
	);

	integer i;

	initial begin
		$dumpfile("q4_tb.vcd");
		$dumpvars(0, q4_tb);

		for (i = 0; i < 16; i = i + 1) begin
			d = i; #20;
		end

		$display("Test complete");
	end
endmodule