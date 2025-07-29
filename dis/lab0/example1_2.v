module example1_2(x1, x2, x3, f);
    input x1, x2, x3;
    output f;
    wire w1, w2, nx2;

    not (nx2, x2);
    and (w1, x1, x2);
    and (w2, nx2, x3);
    or (f, w1, w2);
endmodule