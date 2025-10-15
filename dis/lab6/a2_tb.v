`timescale 1ns/1ns
`include "a2.v"

module a2_tb;
	reg [4:0] a;
	reg en;
	wire [31:0] y;

	a2 add2 (
		.a(a),
		.en(en),
		.y(y)
	);

	integer i;

	initial begin
		$dumpfile("a2_tb.vcd");
		$dumpvars(0, a2_tb);

		en = 1;

		for (i = 0; i < 32; i = i + 1) begin
            a = i[4:0]; #20;
        end

		en = 0; a = 4'b1101; #20;

		$display("Test complete");
	end
endmodule