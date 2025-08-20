`timescale 1ns/1ns
`include "q4.v"

module q4_tb;
    reg [3:0] a, b;
    reg cin;
    wire [3:0] sum;
    wire cout;

    q4 ques4 (
        .a(a),
        .b(b),
        .cin(cin),
        .sum(sum),
        .cout(cout)
    );

    initial begin
        $dumpfile("q4_tb.vcd");
        $dumpvars(0, q4_tb);

        a = 4'd5; b = 4'd3; cin = 0; #20; // 5 + 3 = 8
        a = 4'd9; b = 4'd4; cin = 0; #20; // 9 + 4 = 13
        a = 4'd7; b = 4'd8; cin = 1; #20; // 7 + 8 + 1 = 16
        a = 4'd0; b = 4'd0; cin = 0; #20; // 0 + 0 + 0 = 0
        a = 4'd6; b = 4'd9; cin = 0; #20; // 6 + 9 = 15

        $display("Test complete");
    end
endmodule
