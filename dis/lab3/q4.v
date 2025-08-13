module q4(a, b, c, d, f);
    input a, b, c, d;
    output f;

	// f = a'd + b'd'
	
    // inverters
    wire na, nb, nd;
    nand (na, a, a);
    nand (nb, b, b);
    nand (nd, d, d);

    // t1 = a'd
    wire nt1_tmp, t1;
    nand (nt1_tmp, na, d);
    nand (t1, nt1_tmp, nt1_tmp);

    // t2 = b'd'
    wire nt2_tmp, t2;
    nand (nt2_tmp, nb, nd);
    nand (t2, nt2_tmp, nt2_tmp);

    // f = t1 + t2
	wire nt1, nt2;
    nand (nt1, t1, t1);
    nand (nt2, t2, t2);

    nand (f, nt1, nt2);
endmodule
