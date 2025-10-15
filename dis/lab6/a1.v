module a1 (
	input [1:0] a,
	input en,
	output [3:0] y
);
	
	wire [3:0] hi_en, y_temp;

	decoder2to4 d0 (.a(a[1:0]), .en(~en), .y(hi_en));
	decoder2to4 d1 (.a(a[1:0]), .en(hi_en[0]), .y(y[3:0]));
	decoder2to4 d2 (.a(a[1:0]), .en(hi_en[1]), .y(y[7:4]));
	decoder2to4 d3 (.a(a[1:0]), .en(hi_en[2]), .y(y[11:8]));
	decoder2to4 d4 (.a(a[1:0]), .en(hi_en[3]), .y(y[15:12]));

endmodule

module decoder2to4 (
    input [1:0] a,
    input en,
    output reg [3:0] y
);
    
	always @(*) begin
        if (en) begin
            case (a)
                2'b00: y = 4'b0001;
                2'b01: y = 4'b0010;
                2'b10: y = 4'b0100;
                2'b11: y = 4'b1000;
                default: y = 4'b0000;
            endcase
        end else begin
            y = 4'b0000;
        end
    
	end
endmodule
