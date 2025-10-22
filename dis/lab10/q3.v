module q3 (
	input wire clk, rst,
	output reg [2:0] q
);

	wire [2:0] t;
	assign t[2] = q[1] & q[0];
	assign t[1] = q[0];
	assign t[0] = (~q[1] & ~q[0]) | (q[2] & q[1]);

	always @(posedge clk or posedge rst) begin
        if (rst) begin
            q <= 3'b000;
        end else begin
            q[0] <= q[0] ^ t[0];
            q[1] <= q[1] ^ t[1];
            q[2] <= q[2] ^ t[2];
        end
    end

endmodule