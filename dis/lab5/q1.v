module q1 (
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