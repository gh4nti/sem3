module q4 (
    input [3:0] a, b,
    input cin,
    output [3:0] sum,
    output cout
);
    wire [3:0] raw_sum;
    wire raw_cout;
    wire [4:0] bin_sum;
    wire [4:0] corrected_sum;

    fourbitadder add1 (
        .a(a),
        .b(b),
        .cin(cin),
        .sum(raw_sum),
        .cout(raw_cout)
    );

    assign bin_sum = {raw_cout, raw_sum};
    assign corrected_sum = (bin_sum > 9) ? (bin_sum + 6) : bin_sum;

    assign sum  = corrected_sum[3:0];
    assign cout = corrected_sum[4];
endmodule

module fourbitadder (
	input [3:0] a, b,
	input cin,
	output [3:0] sum,
	output cout
);
	assign {cout, sum} = a + b + cin;
endmodule