module a1 (
	input wire [31:0] d,
	input wire [4:0] s,
	output wire f
);

	wire [3:0] f_temp;

    mux8to1 m1 (.d(d[7:0]), .s(s[2:0]), .f(f_temp[0]));
    mux8to1 m2 (.d(d[15:8]), .s(s[2:0]), .f(f_temp[1]));
    mux8to1 m3 (.d(d[23:16]), .s(s[2:0]), .f(f_temp[2]));
    mux8to1 m4 (.d(d[31:24]), .s(s[2:0]), .f(f_temp[3]));

    mux8to1 m5 (.d({4'b0000, f_temp}), .s({2'b00, s[4:3]}), .f(f));

endmodule

module mux8to1 (
    input wire [7:0] d,
	input wire [2:0] s,
    output reg f
);
    
	always @(*) begin
        if (s == 3'b000) f = d[0];
        else if (s == 3'b001) f = d[1];
        else if (s == 3'b010) f = d[2];
        else if (s == 3'b011) f = d[3];
        else if (s == 3'b100) f = d[4];
        else if (s == 3'b101) f = d[5];
        else if (s == 3'b110) f = d[6];
        else f = d[7];
    end

endmodule