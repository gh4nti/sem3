module q2 #(
	parameter n = 8
) (
	input clk, rst,
	input [n-1:0] d,
	output reg [n-1:0] q
);

	always @(posedge clk) begin
		if (rst) begin
			q <= {n{1'b0}};
		end else begin
			q <= d;
		end
	end
	
endmodule