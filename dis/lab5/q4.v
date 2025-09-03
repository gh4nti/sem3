module q4 (
	input wire [15:0] d,
	input wire [3:0] s,
	output wire f
);

	wire f0, f1;

    mux8to1 m1 (.d(d[7:0]), .s(s[2:0]), .f(f0));
    mux8to1 m2 (.d(d[15:8]), .s(s[2:0]), .f(f1));

    mux2to1 m3 (.d({f1, f0}), .s(s[3]), .f(f));

endmodule

module mux2to1 (
	input wire [1:0] d,
	input wire s,
	output reg f
);

	always @(*) begin
		if (s == 0)
			f = d[0];
		else
			f = d[1];
	end

endmodule

module mux8to1 (
	input wire [7:0] d,
	input wire [2:0] s,
	output reg f
);

	always @(*) begin
		case (s)
            3'b000: f = d[0];
            3'b001: f = d[1];
            3'b010: f = d[2];
            3'b011: f = d[3];
            3'b100: f = d[4];
            3'b101: f = d[5];
            3'b110: f = d[6];
            3'b111: f = d[7];
            default: f = 1'b0;
        endcase
	end

endmodule