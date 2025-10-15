module a2(
    input clk, rst,
    output [7:0] t
);

    wire [3:0] q;

    johnson_counter_4bit counter (
        .clk(clk),
        .rst(rst),
        .q(q)
    );

    assign t[0] = ~q[3] & ~q[2] & ~q[1] & ~q[0];
    assign t[1] = ~q[3] & ~q[2] & ~q[1] &  q[0];
    assign t[2] = ~q[3] & ~q[2] &  q[1] &  q[0];
    assign t[3] = ~q[3] &  q[2] &  q[1] &  q[0];
    assign t[4] =  q[3] &  q[2] &  q[1] &  q[0];
    assign t[5] =  q[3] &  q[2] &  q[1] & ~q[0];
    assign t[6] =  q[3] &  q[2] & ~q[1] & ~q[0];
    assign t[7] =  q[3] & ~q[2] & ~q[1] & ~q[0];

endmodule


module johnson_counter_4bit(
    input clk, rst,
    output reg [3:0] q
);

    always @(posedge clk) begin
        if (rst)
            q <= 4'b0000;
        else
            q <= {~q[3], q[3:1]};
    end

endmodule