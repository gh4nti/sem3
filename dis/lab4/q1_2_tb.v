`timescale 1ns/1ns
`include "q1_2.v"

module q1_2_tb();
	reg cin, a, b;
	wire s, cout;

	q1_2 ques1_2(cin, a, b, s, cout);
	integer i;
	initial begin
		$dumpfile("q1_2_tb.vcd");
		$dumpvars(0, q1_2_tb);

		for (i = 0; i < 8; i = i + 1) begin
            {cin, a, b} = i[2:0];
            #20;
        end

		$display("Test complete");
end endmodule