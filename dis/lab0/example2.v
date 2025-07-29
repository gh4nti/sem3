module example2(x1, x2, x3, x4, f, g, h);

	input x1, x2, x3, x4;
	output f, g, h;
	
	and (i, x1, x3);
	and (j, x2, x4);
	or (g, i, j);
	
	not (k, x3);
	not (l, x2);
	
	or (m, x1, k);
	or (n, x4, l);
	and (h, m, n);
	
	or (f, g, h);

endmodule