module q3(a, b, c, d, f);
	input a, b, c, d;
	output f;

	// f = d * (a' + c')

	// inverters
	wire na, nc;
	nor (na, a, a);
	nor (nc, c, c);

	// t = a' + c'
	wire nt_tmp, t;
	nor (nt_tmp, na, nc);
	nor (t, nt_tmp, nt_tmp);

	// d'
	wire nd;
	nor (nd, d, d);

	// f = d * t
	wire nt;
	nor (nt, t, t);
	
	nor (f, nd, nt);
endmodule