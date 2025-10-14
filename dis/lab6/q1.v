module q1 (
	input [2:0] a,
	output [7:0] y
);

	wire [3:0] lo, up;

	decoder2to4 d0 (.a(a[1:0]), .en(~a[2]), .y(lo));
	decoder2to4 d1 (.a(a[1:0]), .en(a[2]), .y(up));

	assign y = {up, lo};

endmodule

module decoder2to4 (
	input [1:0] a,
	input en,
	output reg [3:0] y
);

	always @(*) begin
		if (en) begin
			if (a == 2'b00)
				y = 4'b0001;
			else if (a == 2'b01)
				y = 4'b0010;
			else if (a == 2'b10)
				y = 4'b0100;
			else
				y = 4'b1000;
		end else begin
			y = 4'b0000;
		end
	end

endmodule