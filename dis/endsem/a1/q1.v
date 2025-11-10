// 2:1 mux
module mux2to1 (
	input [1:0] d,
	input s,
	output y
);

	assign y = (~s & d[0]) | (s & d[1]);

endmodule

// 4-bit comparator
module comp4bit (
	input [3:0] a, b,
	output a_gt_b, a_eq_b, a_lt_b
);

	wire [3:0] eq, gt, lt;

	// equality checks
	assign eq[0] = ~(a[0] ^ b[0]);
    assign eq[1] = ~(a[1] ^ b[1]);
    assign eq[2] = ~(a[2] ^ b[2]);
	assign eq[3] = ~(a[3] ^ b[3]);

	// greater than conditions
	assign gt[3] = a[3] & ~b[3];
    assign gt[2] = eq[3] & (a[2] & ~b[2]);
    assign gt[1] = eq[3] & eq[2] & (a[1] & ~b[1]);
    assign gt[0] = eq[3] & eq[2] & eq[1] & (a[0] & ~b[0]);

	// less than conditions
	assign lt[3] = ~a[3] & b[3];
    assign lt[2] = eq[3] & (~a[2] & b[2]);
    assign lt[1] = eq[3] & eq[2] & (~a[1] & b[1]);
    assign lt[0] = eq[3] & eq[2] & eq[1] & (~a[0] & b[0]);

	// output
	assign a_gt_b = gt[3] | gt[2] | gt[1] | gt[0];
    assign a_lt_b = lt[3] | lt[2] | lt[1] | lt[0];
    assign a_eq_b = eq[3] & eq[2] & eq[1] & eq[0];

endmodule

// T flip flop
module tff (
	input clk, rst,
	input t,
	output reg q
);

	always @(negedge clk) begin
		if (!rst)
			q <= 1'b0;
		else if (t)
			q <= ~q;
		else
			q <= q;
	end

endmodule

// 4-bit parallel shift register
module parallelreg4bit (
	input clk, rst,
	input [3:0] d,
	output reg [3:0] q
);

	wire [3:0] t;
	assign t = d ^ q;

	tff t0 (.clk(clk), .rst(rst), .t(t[0]), .q(q[0]));
	tff t1 (.clk(clk), .rst(rst), .t(t[1]), .q(q[1]));
	tff t2 (.clk(clk), .rst(rst), .t(t[2]), .q(q[2]));
	tff t3 (.clk(clk), .rst(rst), .t(t[3]), .q(q[3]));

endmodule

module q1 (
	input clk, rst,
	input [3:0] a, b,
	output [3:0] q
);

	wire lt, eq, gt;
	wire [3:0] lesser;
	wire s;

	comp4bit comp (
		.a(a),
		.b(b),
		.a_gt_b(gt),
		.a_eq_b(eq),
		.a_lt_b(lt)
	);
	
	mux2to1 m0 (.d({b[0], a[0]}), .s(lt), .y(lesser[0]));
	mux2to1 m1 (.d({b[1], a[1]}), .s(lt), .y(lesser[1]));
	mux2to1 m2 (.d({b[2], a[2]}), .s(lt), .y(lesser[2]));
	mux2to1 m3 (.d({b[3], a[3]}), .s(lt), .y(lesser[3]));

	parallelreg4bit preg (
		.clk(clk),
		.rst(rst),
		.d(lesser),
		.q(q)
	);

endmodule