module q2 (
	input [3:0] a,
	input en,
	output [15:0] y
);

	wire [7:0] lo, up;

	decoder3to8 d0 (.a(a[2:0]), .en(en & ~a[3]), .y(lo));
	decoder3to8 d1 (.a(a[2:0]), .en(en & a[3]), .y(up));

	assign y = {up, lo};

endmodule

module decoder3to8 (
	input [2:0] a,
	input en,
	output reg [7:0] y
);

	integer i;

	always @(*) begin
		y = 8'b0;
		if (en) begin
			for (i = 0; i < 8; i = i + 1) begin
				if (i == a)
                	y[i] = 1'b1;
            	else
                	y[i] = 1'b0;
        	end
		end
	end

endmodule