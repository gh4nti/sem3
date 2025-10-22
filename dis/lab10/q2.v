module q2 (
	input wire clk, rst,
	output reg [3:0] q
);

	reg q0, q1, q2, q3;
	assign q = {q3, q2, q1, q0};

	// T flip-flop 0
	always @(negedge clk or posedge rst) begin
        if (rst) begin
            q0 <= 1'b0;
        end else begin
            q0 <= ~q0;
        end
    end

	// T flip-flop 1
	always @(negedge q0 or posedge rst) begin
        if (rst) begin
            q1 <= 1'b0;
        end else begin
            q1 <= ~q1;
        end
    end

	// T flip-flop 2
	always @(negedge q1 or posedge rst) begin
		if (rst) begin
			q2 <= 1'b0;
		end else begin
			q2 <= ~q2;
		end
	end

	// T flip-flop 3
	always @(negedge q2 or posedge rst) begin
		if (rst) begin
			q3 <= 1'b0;
		end else begin	
			q3 <= ~q3;
		end
	end

endmodule