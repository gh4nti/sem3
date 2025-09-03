`timescale 1ns/1ns
`include "a1.v"

module a1_tb;
	
	reg [31:0] d;
	reg [4:0] s;
	wire f;

	a1 add1 (
		.d(d),
		.s(s),
		.f(f)
	);

	integer i;

	initial begin
		$dumpfile("a1_tb.vcd");
        $dumpvars(0, a1_tb);

		d = 32'hA5A5_A5A5;

		for (i = 0; i < 32; i = i + 1) begin
            s = i;
            #20;
		end

		$display("Test complete");
	end

endmodule