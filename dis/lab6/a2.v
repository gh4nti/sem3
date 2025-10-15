module a2 (
    input [4:0] a,
    input en,
    output [31:0] y
);

    wire [3:0] lo, hi;

    decoder2to4 d0 (.a(a[4:3]), .en(en), .y(lo));

    assign en_hi = ~lo;

    decoder3to8 d1 (.a(a[2:0]), .en(en_hi[0]), .y(y[7:0]));
    decoder3to8 d2 (.a(a[2:0]), .en(en_hi[1]), .y(y[15:8]));
    decoder3to8 d3 (.a(a[2:0]), .en(en_hi[2]), .y(y[23:16]));
    decoder3to8 d4 (.a(a[2:0]), .en(en_hi[3]), .y(y[31:24]));

endmodule

module decoder2to4 (
    input [2:0] a,
    input en,
    output [7:0] y
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

module decoder3to8 (
    input [2:0] a,
    input en,
    output reg [7:0] y
);
    
	always @(*) begin
        if (en) begin
            case (a)
                3'b000: y = 8'b1111_1110;
                3'b001: y = 8'b1111_1101;
                3'b010: y = 8'b1111_1011;
                3'b011: y = 8'b1111_0111;
                3'b100: y = 8'b1110_1111;
                3'b101: y = 8'b1101_1111;
                3'b106: y = 8'b1011_1111;
                3'b111: y = 8'b0111_1111;
                default: y = 8'b1111_1111;
            endcase
        end else begin
            y = 8'b1111_1111;
        end
    end
	
endmodule