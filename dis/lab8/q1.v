module q1 (
	input clk, rst, si,
	output so
);

	wire [5:0] q;

	dff dff0 (.clk(clk), .rst(rst), .d(si), .q(q[0]));
	dff dff1 (.clk(clk), .rst(rst), .d(q[0]), .q(q[1]));
	dff dff2 (.clk(clk), .rst(rst), .d(q[1]), .q(q[2]));
	dff dff3 (.clk(clk), .rst(rst), .d(q[2]), .q(q[3]));
	dff dff4 (.clk(clk), .rst(rst), .d(q[3]), .q(q[4]));
	dff dff5 (.clk(clk), .rst(rst), .d(q[4]), .q(q[5]));

	assign so = q[5];

endmodule

module dff (
	input clk, rst, d,
	output reg q
);

	always @(posedge clk or negedge rst) begin
		if (!rst)
			q <= 1'b0;
		else
			q <= d;
	end

endmodule