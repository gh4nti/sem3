module q1 (
	input clk, E, x,
	output reg a, b
);

	wire b_xnor;
	assign b_xnor = ~(b ^ x);

	wire JA, KA, JB, KB;

	assign JA = E & ~a & b_xnor;
	assign KA = E & a & b_xnor;

	assign JB = E & ~b;
	assign KB = E & b;

	always @(posedge clk) begin
		// flip-flop A
		case ({JA, KA})
			2'b10: a <= 1'b1;
			2'b01: a <= 1'b0;
			2'b11: a <= ~a;
			default: a <= a;
		endcase

		// flip-flop B
		case ({JB, KB})
			2'b10: b <= 1'b1;
			2'b01: b <= 1'b0;
			2'b11: b <= ~b;
			default: b <= b;
		endcase
	end
	
endmodule