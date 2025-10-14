module q4 (
	input [3:0] d,
	output reg [1:0] y
);

	always @(*) begin
		casex (d)
			4'b1xxx: y = 2'b11;
			4'b01xx: y = 2'b10;
			4'b001x: y = 2'b01;
			4'b0001: y = 2'b00;
			4'b0000: y = 2'b00;
			default: y = 2'bxx;
		endcase
	end
	
endmodule