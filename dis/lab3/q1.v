module q1(a, b, c, d, f);
	input a, b, c, d;
	output f;

	// f = a'c' + a'd + bc' + bd

	// inverters
	wire na, nc;
	nand (na, a, a);
	nand (nc, c, c);

	// t1 = a'c'
	wire nt1_tmp, t1;
	nand (nt1_tmp, na, nc);
	nand (t1, nt1_tmp, nt1_tmp);

	// t2 = a'd
	wire nt2_tmp, t2;
	nand (nt2_tmp, na, d);
	nand (t2, nt2_tmp, nt2_tmp);

	// t3 = bc'
	wire nt3_tmp, t3;
	nand (nt3_tmp, b, nc);
	nand (t3, nt3_tmp, nt3_tmp);

	// t4 = bd
	wire nt4_tmp, t4;
	nand (nt4_tmp, b, d);
	nand (t4, nt4_tmp, nt4_tmp);

	// f = t1 + t2 + t3 + t4
	wire nt1, nt2, nt3, nt4;
	nand (nt1, t1, t1);
	nand (nt2, t2, t2);
	nand (nt3, t3, t3);
	nand (nt4, t4, t4);

	nand (f, nt1, nt2, nt3, nt4);

endmodule