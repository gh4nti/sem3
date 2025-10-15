module q3 (
	input clk, rst,
	output reg [4:0] q
);

	always @(posedge clk) begin
		if (rst)
			q <= 5'b00000;
		else
			q <= {~q[4], q[4:1]};
	end
	
endmodule