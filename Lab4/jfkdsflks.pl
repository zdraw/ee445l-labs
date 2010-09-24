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
				<STDIN>;
				exit;
			}			
		}
}

my %states =   (5  => 9,
				6  => 5,
				10 => 6,
				9  => 10);

for my $i (0..@states-2) {
		if($states{$states[$i]} != $states[$i+1]) {
			print "$i: ", $states[$i], " -> ", $states[$i+1], "\n";
		}
}

print "Done\n";
<STDIN>;




__END__
   [0]           5 unsigned short
   [1]           9 unsigned short
   [2]          10 unsigned short
   [3]           6 unsigned short
   [4]           5 unsigned short
   [5]           9 unsigned short
   [6]          10 unsigned short
   [7]           6 unsigned short
   [8]           5 unsigned short
   [9]           9 unsigned short
   [10]         10 unsigned short
   [11]          6 unsigned short
   [12]          5 unsigned short
   [13]          9 unsigned short
   [14]         10 unsigned short
   [15]          6 unsigned short
   [16]          5 unsigned short
   [17]          9 unsigned short
   [18]         10 unsigned short
   [19]          6 unsigned short
   [20]          5 unsigned short
   [21]          9 unsigned short
   [22]         10 unsigned short
   [23]          6 unsigned short
   [24]          5 unsigned short
   [25]          9 unsigned short
   [26]         10 unsigned short
   [27]          6 unsigned short
   [28]          5 unsigned short
   [29]          9 unsigned short
   [30]         10 unsigned short
   [31]          6 unsigned short
   [32]          5 unsigned short
   [33]          9 unsigned short
   [34]         10 unsigned short
   [35]          6 unsigned short
   [36]          5 unsigned short
   [37]          9 unsigned short
   [38]         10 unsigned short
   [39]          6 unsigned short
   [40]          5 unsigned short
   [41]          9 unsigned short
   [42]         10 unsigned short
   [43]          6 unsigned short
   [44]          5 unsigned short
   [45]          9 unsigned short
   [46]         10 unsigned short
   [47]          6 unsigned short
   [48]          5 unsigned short
   [49]          9 unsigned short
   [50]         10 unsigned short
   [51]          6 unsigned short
   [52]          5 unsigned short
   [53]          9 unsigned short
   [54]         10 unsigned short
   [55]          6 unsigned short
   [56]          5 unsigned short
   [57]          9 unsigned short
   [58]         10 unsigned short
   [59]          6 unsigned short
   [60]          5 unsigned short
   [61]          9 unsigned short
   [62]         10 unsigned short
   [63]          6 unsigned short
   [64]          5 unsigned short
   [65]          9 unsigned short
   [66]         10 unsigned short
   [67]          6 unsigned short
   [68]          5 unsigned short
   [69]          9 unsigned short
   [70]         10 unsigned short
   [71]          6 unsigned short
   [72]          5 unsigned short
   [73]          9 unsigned short
   [74]         10 unsigned short
   [75]          6 unsigned short
   [76]          5 unsigned short
   [77]          9 unsigned short
   [78]         10 unsigned short
   [79]          6 unsigned short
   [80]          5 unsigned short
   [81]          9 unsigned short
   [82]         10 unsigned short
   [83]          6 unsigned short
   [84]          5 unsigned short
   [85]          9 unsigned short
   [86]         10 unsigned short
   [87]          6 unsigned short
   [88]          5 unsigned short
   [89]          9 unsigned short
   [90]         10 unsigned short
   [91]          6 unsigned short
   [92]          5 unsigned short
   [93]          9 unsigned short
   [94]         10 unsigned short
   [95]          6 unsigned short
   [96]          5 unsigned short
   [97]          9 unsigned short
   [98]         10 unsigned short
   [99]          6 unsigned short
