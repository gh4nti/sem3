module q1_2(cin, a, b, s, cout);
    input cin, a, b;
    output s, cout;

    assign s = a ^ b ^ cin;
    assign cout = (a & b) | (a & cin) | (b & cin);
endmodule