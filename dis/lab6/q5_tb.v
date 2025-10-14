`timescale 1ns/1ns
`include "q5.v"

module q5_tb;
	reg [15:0] d;
	wire [3:0] y;

	q5 ques5 (
		.d(d),
		.y(y)
	);

	integer i;

	initial begin
		$dumpfile("q5_tb.vcd");
		$dumpvars(0, q5_tb);

		for (i = 0; i < 16; i = i + 1) begin
        	d = 16'b0;
        	d[i] = 1'b1; #20;
   		end

		d = 16'b0000_1001_0010_0011; #20; // d15=0, d12=1, d7=1, d1=1
		d = 16'b1111_0000_0000_0001; #20; // multiple high, d15 has priority

		d = 16'b0000_0000_0000_0000; #20;

		$display("Test complete");
	end
endmodule