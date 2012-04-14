#!/usr/bin/perl

open FH, "names.txt" or die $!;

my @names;
my $pos = 1;
my $sum = 0;

while( <FH> ) {
	@names = split(/\,/, $_);
}

foreach $name(sort @names) {
	$name = substr $name, 1, (length($name)-2);
	my $namesum = 0;
	@chars = split("", $name);

# compute score:
	foreach $c(@chars) {
		print $c, " ";
		$namesum += (ord($c) - 64);
	}
	$namesum = $namesum * $pos;
	print $namesum, "\n";
	$pos++;
	$sum += $namesum;
}

print $sum;
