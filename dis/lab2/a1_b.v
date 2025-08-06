module a1_b(a, b, c, d, f);
	input a, b, c, d;
	output f;

	assign f = (~a | d) & (a | ~c | d) & (a | ~b | c | ~d);
endmodule