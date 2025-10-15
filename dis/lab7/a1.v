module a1 (
	input wire clk, rst, t,
	output reg q
);

	always @(negedge clk) begin
		if (rst)
			q <= 1'b0;
		else if (t)
			q <= ~q;
		else
			q <= q;
	end

endmodule