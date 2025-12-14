module dff (
	input wire clk, rst,
	input wire d,
	output reg q
);

	always @(posedge clk or negedge rst) begin
		if (!rst)
			q <= 1'b0;
		else
			q <= d;
	end

endmodule

module pipo4 (
	input wire clk, rst, en,
	input wire [3:0] d,
	output wire [3:0] q
);

	wire [3:0] q_int, dff_in;

	genvar i;

	generate
		for (i = 0; i < 4; i = i + 1) begin
			assign dff_in[i] = en ? d[i] : q_int[i];

			dff dff_i (
				.clk(clk),
				.rst(rst),
				.d(dff_in[i]),
				.q(q_int[i])
			);
		end
	endgenerate

	assign q = q_int;

endmodule

module decoder1to2 (
	input wire s,
	output wire [1:0] y
);

	assign y[0] = ~s;
	assign y[1] = s;

endmodule

module q1 (
	input wire clk, rst, s,
	input wire [3:0] data_in,
	output wire [3:0] a, b
);

	wire en_a, en_b;

	decoder1to2 dec (
		.s(s),
		.y({en_b, en_a})
	);

	pipo4 pipo (
		.clk(clk),
		.rst(rst),
		.en(en_b),
		.d(data_in),
		.q(b)
	);

endmodule