module q2 (
	input clk, x,
	output reg a, b
);

	wire TA, TB;

	assign TA = b & ~x;
	assign TB = ~x | (~a & b);

	always @(posedge clk) begin
		if (TA)
			a <= ~a;
		else
			a <= a;

		if (TB)
			b <= ~b;
		else
			b <= b;
	end
	
endmodule