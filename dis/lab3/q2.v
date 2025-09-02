module q2(a, b, c, d, f);
	input a, b, c, d;
	output f;

	// f = (a' + b') * (c' + d') * (b' + d)

	// inverters
	wire na, nb, nc, nd;
	nor (na, a, a);
	nor (nb, b, b);
	nor (nc, c, c);
	nor (nd, d, d);

	// t1 = (a' + b')
	wire nt1_tmp, t1;
	nor (nt1_tmp, na, nb);
	nor (t1, nt1_tmp, nt1_tmp);

	// t2 = (c' + d')
	wire nt2_tmp, t2;
	nor (nt2_tmp, nc, nd);
	nor (t2, nt2_tmp, nt2_tmp);

	// t3 = (b' + d)
	wire nt3_tmp, t3;
	nor (nt3_tmp, nb, d);
	nor (t3, nt3_tmp, nt3_tmp);

	// f = t1 * t2 * t3
	wire nt1, nt2, nt3;
	nor (nt1, t1, t1);
	nor (nt2, t2, t2);
	nor (nt3, t3, t3);
	
	nor (f, nt1, nt2, nt3);

endmodule