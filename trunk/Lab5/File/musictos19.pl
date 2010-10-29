use strict;
my $buffer;
my $page = 0;
my @nums;

open FILE, "explode.bin";
open W, ">stuff.s19";


binmode FILE;
while (read FILE, $buffer, 1) {
	push @nums, ord($buffer);
	
	if(@nums >= 32) {
		my $string = "S224";
		$string .= sprintf "%.2X", 0x20 + int($page/500);
		$string .= sprintf "%.4X", 0x8000 + int($page%500)*32;
		
		foreach (@nums) {
			$string .= sprintf "%.2X", $_;
		}
		$string .= checksum($string);
		
		print W $string, "\n";
		
		#print W "#pragma CONST_SEG name$page\n";
		#print W "const char song", $page, "[", scalar(@nums), "] = {\n";
		
		#for my $i (0..@nums - 2) {
		#	print W "$nums[$i],\n";
		#}
		#print W "$nums[-1]};\n\n";
		
		@nums = ();
		$page++;
	}
}

if(@nums) {
	my $string = "S224";
	$string .= sprintf "%.2X", 0x20 + int($page/500);
	$string .= sprintf "%.4X", 0x8000 + int($page%500)*32;
	
	for my $i (0..31) {
		if(defined($nums[$i])) {
			$string .= sprintf "%.2X", $_;
		}
		else {
			$string .= "00";
		}
	}
	$string .= checksum($string);
	
	print W $string, "\n";
}

print W "S804000000FB\n";


sub checksum {
	my $string = shift;
	my $sum = 0;
	
	for my $i (1..length($string)/2) {
		my $byte = substr($string, $i*2, 2);
		$sum += hex($byte);
	}
	
	return sprintf "%.2X", ((~($sum&0xFF))&0xFF);
}