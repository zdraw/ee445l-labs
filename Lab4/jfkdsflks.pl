use strict; 

my @states;
my $index = -1;

while(<DATA>) {
		if(/^\s+\[(\d+)\]\s+(\d+) unsigned short$/) {
			if($1 == $index + 1) {
				$index = $1;
				push @states, $2;
			}
			else {
				print "$1 after $index failed\n";
				exit;
			}			
		}
}

my %statesforward = (  
						5  => 6,
						6  => 10,
						10 => 9,
						9  => 5
					);
my %statesbackward = (
						5  => 9,
						6  => 5,
						10 => 6,
						9  => 10
					);

for my $i (0..@states-2) {
		if($i % 14 < 7) {
			if($statesforward{$states[$i]} != $states[$i+1]) {
				print "$i: ", $states[$i], " -> ", $states[$i+1], "\n";
			}
		}
		else {
			if($statesbackward{$states[$i]} != $states[$i+1]) {
				print "$i: ", $states[$i], " -> ", $states[$i+1], "\n";
			}
		}
}

print "Done\n";




__END__
   [0]           5 unsigned short
   [1]           6 unsigned short
   [2]          10 unsigned short
   [3]           9 unsigned short
   [4]           5 unsigned short
   [5]           6 unsigned short
   [6]          10 unsigned short
   [7]           9 unsigned short
   [8]          10 unsigned short
   [9]           6 unsigned short
   [10]          5 unsigned short
   [11]          9 unsigned short
   [12]         10 unsigned short
   [13]          6 unsigned short
   [14]          5 unsigned short
   [15]          6 unsigned short
   [16]         10 unsigned short
   [17]          9 unsigned short
   [18]          5 unsigned short
   [19]          6 unsigned short
   [20]         10 unsigned short
   [21]          9 unsigned short
   [22]         10 unsigned short
   [23]          6 unsigned short
   [24]          5 unsigned short
   [25]          9 unsigned short
   [26]         10 unsigned short
   [27]          6 unsigned short
   [28]          5 unsigned short
   [29]          6 unsigned short
   [30]         10 unsigned short
   [31]          9 unsigned short
   [32]          5 unsigned short
   [33]          6 unsigned short
   [34]         10 unsigned short
   [35]          9 unsigned short
   [36]         10 unsigned short
   [37]          6 unsigned short
   [38]          5 unsigned short
   [39]          9 unsigned short
   [40]         10 unsigned short
   [41]          6 unsigned short
   [42]          5 unsigned short
   [43]          6 unsigned short
   [44]         10 unsigned short
   [45]          9 unsigned short
   [46]          5 unsigned short
   [47]          6 unsigned short
   [48]         10 unsigned short
   [49]          9 unsigned short
   [50]         10 unsigned short
   [51]          6 unsigned short
   [52]          5 unsigned short
   [53]          9 unsigned short
   [54]         10 unsigned short
   [55]          6 unsigned short
   [56]          5 unsigned short
   [57]          6 unsigned short
   [58]         10 unsigned short
   [59]          9 unsigned short
   [60]          5 unsigned short
   [61]          6 unsigned short
   [62]         10 unsigned short
   [63]          9 unsigned short
   [64]         10 unsigned short
   [65]          6 unsigned short
   [66]          5 unsigned short
   [67]          9 unsigned short
   [68]         10 unsigned short
   [69]          6 unsigned short
   [70]          5 unsigned short
   [71]          6 unsigned short
   [72]         10 unsigned short
   [73]          9 unsigned short
   [74]          5 unsigned short
   [75]          6 unsigned short
   [76]         10 unsigned short
   [77]          9 unsigned short
   [78]         10 unsigned short
   [79]          6 unsigned short
   [80]          5 unsigned short
   [81]          9 unsigned short
   [82]         10 unsigned short
   [83]          6 unsigned short
   [84]          5 unsigned short
   [85]          6 unsigned short
   [86]         10 unsigned short
   [87]          9 unsigned short
   [88]          5 unsigned short
   [89]          6 unsigned short
   [90]         10 unsigned short
   [91]          9 unsigned short
   [92]         10 unsigned short
   [93]          6 unsigned short
   [94]          5 unsigned short
   [95]          9 unsigned short
   [96]         10 unsigned short
   [97]          6 unsigned short
   [98]          5 unsigned short
   [99]          6 unsigned short
