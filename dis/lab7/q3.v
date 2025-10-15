module q3 (
	input wire clk, rst, j, k,
	output reg q
);

	always @(posedge clk) begin
		if (rst)
			q <= 1'b0;
		else begin
			case ({j, k})
				2'b00: q <= q;
				2'b01: q <= 1'b0;
				2'b10: q <= 1'b1;
				2'b11: q <= ~q;
			endcase
		end
	end

endmodule