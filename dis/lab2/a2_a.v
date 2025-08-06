module a2_a(a, b, c, d, f);
	input a, b, c, d;
	output f;

	assign f = c | (a & d);
endmodule