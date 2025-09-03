module q3 (
	input wire [15:0] d,
	input wire [3:0] s,
	output wire f
);

	wire [3:0] f_temp;

	mux4to1 m1 (.d(d[3:0]), .s(s[1:0]), .f(f_temp[0]));
    mux4to1 m2 (.d(d[7:4]), .s(s[1:0]), .f(f_temp[1]));
    mux4to1 m3 (.d(d[11:8]), .s(s[1:0]), .f(f_temp[2]));
    mux4to1 m4 (.d(d[15:12]), .s(s[1:0]), .f(f_temp[3]));

	mux4to1 m5 (.d(f_temp), .s(s[3:2]), .f(f));

endmodule

module mux4to1 (
	input wire [3:0] d,
	input wire [1:0] s,
	output wire f
);
	
	assign f = (s == 2'b00) ? d[0] : (s == 2'b01) ? d[1] : (s == 2'b10) ? d[2] : d[3];

endmodule