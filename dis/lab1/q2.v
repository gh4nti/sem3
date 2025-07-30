module q2(a, b, c, d, f, g);

	input a, b, c, d;
	output f, g;
	
	assign f = (~(a & b)) ^ c ^ d;
	assign g = ~(b | c | d);

endmodule
