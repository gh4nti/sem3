module q5 (
	input [15:0] d,
	output reg [3:0] y
);

	integer i;

	always @(*) begin
		y = 4'b0000;
		for (i = 15; i >= 0; i = i - 1) begin
			if (d[i]) begin
				y = i[3:0];
				break;
			end
		end
	end
	
endmodule