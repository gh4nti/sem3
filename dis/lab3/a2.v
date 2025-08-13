module a2(a, b, c, d, f);
	input a, b, c, d;
	output f;

	assign f = (~a & c) | (~a & ~d) | (a & ~b & ~c) | (c & ~d);
endmodule