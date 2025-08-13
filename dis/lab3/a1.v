module a1(a, b, c, d, f);
	input a, b, c, d;
	output f;

	// f = a'd' + bd' + cd' + a'bc

	// inverters
	wire na, nd;
	nand (na, a, a);
	nand (nd, d, d);

	// t1 = a'd'
	wire nt1_tmp, t1;
	nand (nt1_tmp, na, nd);
	nand (t1, nt1_tmp, nt1_tmp);

	// t2 = bd'
	wire nt2_tmp, t2;
	nand (nt2_tmp, b, nd);
	nand (t2, nt2_tmp, nt2_tmp);
	
	// t3 = cd'
	wire nt3_tmp, t3;
	nand (nt3_tmp, c, nd);
	nand (t3, nt3_tmp, nt3_tmp);

	// t4 = a'bc
	wire nt4_tmp, t4;
	nand (nt4_tmp, na, b, c);
	nand (t4, nt4_tmp, nt4_tmp);

	// f = t1 + t2 + t3 + t4
	wire nt1, nt2, nt3, nt4;
	nand (nt1, t1, t1);
	nand (nt2, t2, t2);
	nand (nt3, t3, t3);
	nand (nt4, t4, t4);

	nand (f, nt1, nt2, nt3, nt4);
endmodule