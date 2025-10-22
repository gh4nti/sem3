module a2 (
	input wire clk, rst, x,
	output wire y
);

	reg a, b;
	wire SA, RA, SB, RB;

	assign SA = b & x;
	assign RA = ~b & ~x;

	assign SB = x;
	assign RB = a & b & ~x;

	assign y = ~x | (a & b);

	always @(posedge clk or posedge rst) begin
		if (rst) begin
			 a <= 1'b0;
			 b <= 1'b0;
		end

		else begin
			// SR flip-flop A
			case ({SA, RA})
				2'b00: a <= a;
				2'b01: a <= 1'b0;
				2'b10: a <= 1'b1;
				2'b11: a <= 1'bx;
			endcase

			// SR flip-flop B
			case ({SB, RB})
				2'b00: b <= b;
				2'b01: b <= 1'b0;
				2'b10: b <= 1'b1;
				2'b11: b <= 1'bx;
			endcase
		end
	end

endmodule