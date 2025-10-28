module a3 (
	input clk, rst,
	input [3:0] a,
	output reg [3:0] y
);

	reg [1:0] state;

	always @(posedge clk or posedge rst) begin
		if (rst)
			state <= 2'b00;
		else
			state <= state + 1'b1;
	end

	always @(*) begin
		case (state)
			2'b00: y = {a[2:0], a[3]};
			2'b01: y = {a[1:0], a[3:2]};
			2'b10: y = {a[0], a[3:1]};
			2'b11: y = ~a;
			default: y = 4'b0000;
		endcase
	end
	
endmodule