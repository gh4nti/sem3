module a1 (
	input clk, rst, x,
	output reg [3:0] q
);

	reg [3:0] j, k;

	always @(posedge clk or posedge rst) begin
		if (rst)
			q <= 4'b0000;
		else begin
			if (x == 1'b1) begin
				// up counting
				j[0] = 1;
				k[0] = 1;

				j[1] = q[0];
				k[1] = q[0];

				j[2] = q[0] & q[1];
				k[2] = q[0] & q[1];

				j[3] = q[0] & q[1] & q[2];
				k[3] = q[0] & q[1] & q[2];
			end else begin
				// down counting
				j[0] = 1;
				k[0] = 1;

				j[1] = ~q[0];
				k[1] = ~q[0];

				j[2] = ~q[0] & ~q[1];
				k[2] = ~q[0] & ~q[1];

				j[3] = ~q[0] & ~q[1] & ~q[2];
				k[3] = ~q[0] & ~q[1] & ~q[2];
			end
		end
	end
	
endmodule