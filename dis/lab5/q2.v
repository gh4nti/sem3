module q2 (
	input wire [3:0] d,
	input wire [1:0] s,
	output wire f
);

	wire f0, f1;

	mux2to1 m1 (.d({d[1], d[0]}), .s(s[0]), .f(f0));
    mux2to1 m2 (.d({d[3], d[2]}), .s(s[0]), .f(f1));

    mux2to1 m3 (.d({f1, f0}), .s(s[1]), .f(f));

endmodule

module mux2to1 (
	input wire [1:0] d,
	input wire s,
	output reg f
);

	always @(*) begin
		if (s == 0)
			f = d[0];
		else
			f = d[1];
	end

endmodule