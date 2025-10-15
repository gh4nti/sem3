module a1 #(
	parameter n = 8
) (
	input clk, rst, si,
	output so
);

	reg [n-1:0] q;

	always @(posedge clk) begin
		if (rst)
			q <= {n{1'b0}};
		else
			q <= {q[n-2:0], si};
	end

	assign so = q[n-1];
	
endmodule