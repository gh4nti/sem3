`timescale 1ns/1ns
`include "a2.v"

module a2_tb;

	reg [3:0] a, b;
	wire lt, gt, eq;

	a2 add2 (
		.a(a),
		.b(b),
		.lt(lt),
		.gt(gt),
		.eq(eq)
	);

	integer i, j;

	initial begin
		$dumpfile("a2_tb.vcd");
        $dumpvars(0, a2_tb);

		for (i = 0; i < 16; i = i + 1) begin
			for (j = 0; j < 16; j = j + 1) begin
				a = i;
				b = j;
				#20;
			end
		end

		$display("Test complete");
	end

endmodule