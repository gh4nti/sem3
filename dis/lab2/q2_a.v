module q2_a(a, b, c, d, f);
	input a, b, c, d;
	output f;

	assign f = (b | c) & (c | d) & (~b | ~c | d);
endmodule