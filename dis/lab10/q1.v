module q1 (
	input wire clk, rst,
	output reg [3:0] q
);

	always @(posedge clk or posedge rst) begin
        if (rst) begin
            q <= 4'b0001;
        end else begin
            q[0] <= q[3];
            q[1] <= q[0];
            q[2] <= q[1];
            q[3] <= q[2];
        end
    end

endmodule