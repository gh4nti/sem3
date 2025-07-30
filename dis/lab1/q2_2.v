module q2_2(a, b, c, d, f, g);

	input a, b, c, d;
	output f, g;
	
	nand (i, a, b);
	xor (f, c, d, i);
	nor (g, b, c, d);

endmodule