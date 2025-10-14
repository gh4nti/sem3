module q3 (
	input [3:0] a,
	input en,
	output [15:0] y
);

	wire [3:0] b0, b1, b2, b3;

	decoder2to4 d0 (.a(a[1:0]), .en(en & (a[3:2] == 2'b00)), .y(b0));
	decoder2to4 d1 (.a(a[1:0]), .en(en & (a[3:2] == 2'b01)), .y(b1));
	decoder2to4 d2 (.a(a[1:0]), .en(en & (a[3:2] == 2'b10)), .y(b2));
	decoder2to4 d3 (.a(a[1:0]), .en(en & (a[3:2] == 2'b11)), .y(b3));

	assign y = {b3, b2, b1, b0};
	
endmodule

module decoder2to4 (
	input [1:0] a,
	input en,
	output reg [3:0] y
);

	always @(*) begin
		if (en) begin
			case (a)
				2'b00: y = 4'b1110;
				2'b01: y = 4'b1101;
				2'b10: y = 4'b1011;
				2'b11: y = 4'b0111;
				default: y = 4'b1111;
			endcase
		end else begin
			y = 4'b1111;
		end
	end

endmodule