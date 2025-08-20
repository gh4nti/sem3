module q2 (
	input [3:0] a,
	input [3:0] b,
	input mode,
	output [3:0] result,
	output cout
);
	wire [3:0] b_xor;

	assign b_xor = b ^ {4{mode}};

	fourbitadder adder (
        .a(a),
        .b(b_xor),
        .cin(mode),
        .sum(result),
        .cout(cout)
    );
endmodule

module fourbitadder (
	input [3:0] a,
	input [3:0] b,
	input cin,
	output [3:0] sum,
	output cout
);
	assign {cout, sum} = a + b + cin;
endmodule