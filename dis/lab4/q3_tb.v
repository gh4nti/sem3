`timescale 1ns/1ns
`include "q3.v"

module q3_tb;
    reg [1:0] a, b;
    wire [3:0] p;

    q3 ques3 (
        .a(a),
        .b(b),
        .p(p)
    );

    integer i, j;

    initial begin
		$dumpfile("q3_tb.vcd");
		$dumpvars(0, q3_tb);

        for (i = 0; i < 4; i = i + 1) begin
            for (j = 0; j < 4; j = j + 1) begin
                a = i[1:0];
                b = j[1:0];
                #20;
            end
        end

		$display("Test complete");
    end
endmodule