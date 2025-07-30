module q1_2(a, b, c, d, f);

	input a, b, c, d;
	output f;
	
	and (i, a, b);
	or (k, i, c);
	or (l, i, c);
	not (x, k);
	and (m, x, d);
	or (n, l, d);
	and (f, m, n);

endmodule