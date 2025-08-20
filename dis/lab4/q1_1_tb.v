`timescale 1ns/1ns
`include "q1_1.v"

module q1_1_tb();
	reg a, b;
	wire sum, carry;

	q1_1 ques1_1(a, b, sum, carry);
	integer i, j;
	initial begin
		$dumpfile("q1_1_tb.vcd");
		$dumpvars(0, q1_1_tb);

		for (i = 0; i < 2; i = i + 1) begin
            for (j = 0; j < 2; j = j + 1) begin
                a = i[0];
                b = j[0];
                #20;
            end
        end

		$display("Test complete");
end endmodule