module q1_b(a, b, c, d, f);
	input a, b, c, d;
	output f;

	assign f = (~b & d) | (b & ~c & ~d) + (~b & c & ~d);

endmodule