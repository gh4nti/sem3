module a1(a, b, c, f1, f2);

	input a, b, c;
	output f1, f2;
	
	assign f1 = (a & ~c) | (b & c) | (~b & ~c);
	assign f2 = (a | ~b | c) & (a | b | ~c) & (~a | b | ~c);

endmodule