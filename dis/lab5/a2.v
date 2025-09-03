module a2 (
    input wire [3:0] a, b,
    output wire lt, gt, eq
);
    
	wire lt_msb, gt_msb, eq_msb;
    wire lt_lsb, gt_lsb, eq_lsb;

    comp2bit c1 (.a(a[3:2]), .b(b[3:2]), .lt(lt_msb), .gt(gt_msb), .eq(eq_msb));
    comp2bit c2 (.a(a[1:0]), .b(b[1:0]), .lt(lt_lsb), .gt(gt_lsb), .eq(eq_lsb));

    assign lt = lt_msb | (eq_msb & lt_lsb);
    assign gt = gt_msb | (eq_msb & gt_lsb);
    assign eq = eq_msb & eq_lsb;

endmodule

module comp2bit (
	input wire [1:0] a, b,
	output reg lt, gt, eq
);

	always @(*) begin
		
		if (a < b) begin
			lt = 1; gt = 0; eq = 0;
		end
		
		else if (a > b) begin
			lt = 0; gt = 1; eq = 0;
		end
		
		else begin
			lt = 0; gt = 0; eq = 1;
		end
		
	end

endmodule