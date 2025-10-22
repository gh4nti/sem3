module a1 (
	input clk, x,
	output reg a, b
);

	wire JA, KA, JB, KB;

	assign JA = ~a & (b ^ ~x);
    assign KA =  a & (b ^ ~x);
    assign JB =  x & ~b;
    assign KB =  a & b;

	always @(posedge clk) begin
        // JK flip-flop A
		case ({JA, KA})
            2'b10: a <= 1'b1;
            2'b01: a <= 1'b0;
            2'b11: a <= ~a;
            default: a <= a;
        endcase

        // JK Flip-Flop B
        case ({JB, KB})
			2'b10: b <= 1'b1;
			2'b01: b <= 1'b0;
			2'b11: b <= ~b;
			default: b <= b;
		endcase
	end

endmodule