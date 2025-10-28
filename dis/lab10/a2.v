module a2 (
	input clk, rst,
	output reg [3:0] units, tens
);
	
	always @(posedge clk or posedge rst) begin
		if (rst) begin
			units <= 4'b0;
			tens <= 4'b0;
		end else begin
			if (units == 4'd9) begin
				units <= 4'b0;
				if (tens == 4'd9) begin
					tens <= 4'b0;
				end else
					tens <= tens + 4'b1;
			end else begin
				units <= units + 4'b1;
			end
		end
	end

endmodule