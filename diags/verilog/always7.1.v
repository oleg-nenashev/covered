module main;

event a;
reg   b, c;

always @(a) 
  if( b ) c = 1'b1;

initial begin
	$dumpfile( "always7.1.vcd" );
	$dumpvars( 0, main );
	b = 1'b0;
	c = 1'b0;
	->a;
	#10;
	$finish;
end

endmodule
