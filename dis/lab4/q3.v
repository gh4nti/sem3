module q3 (
    input [1:0] a,
    input [1:0] b,
    output [3:0] p
);

    wire pp0, pp1, pp3;
    wire c1, c2;

    // Partial products
    assign p[0] = a[0] & b[0];
    assign pp0  = a[1] & b[0];
    assign pp1  = a[0] & b[1];
    assign pp3  = a[1] & b[1];

    // Add partial products
    halfadder ha1 (pp0, pp1, p[1], c1);
    halfadder ha2 (pp3, c1, p[2], c2);

    assign p[3] = c2;

endmodule

module halfadder (
    input  a, b,
    output s, c
);
    assign s = a ^ b;
    assign c = a & b;
endmodule
