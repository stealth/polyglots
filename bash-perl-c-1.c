#if PERL

=pod 2>/dev/null

perl $0

for i in 1 2 3 4 5; do
	echo "Hello shell"
	sleep 1
done
exit

=cut

#!/usr/bin/perl

exit if (fork() > 0);

system("cc $0;./a.out");

for (my $i = 0; $i < 5; ++$i) {
	print "Hello perl\n";
	sleep(1);
}

__END__
#else
#include <stdio.h>
#include <unistd.h>

int main()
{
	if (fork() > 0)
		return 0;
	for (int i = 0; i < 5; ++i) {
		printf("Hello C\n");
		sleep(1);
	}
	return 0;
}
#endif

