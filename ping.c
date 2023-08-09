#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "iputils_common.h"

#define t (1u << 8)
#define v (1u << 9)
#define w (1u << 9)
#define f (1u << 2)
#define l (1u << 3)
#define n (1u << 4)
#define p (1u << 5)
#define r (1u << 6)
#define s (1u << 7)

#define T (1u << 0)
#define W (1u << 1)



//    Set a single bit: test |= a
//    Clear a single bit: test &= ~a.
//    Check if bit set test & a.
//  -f -l -n -w -W -p -r -s -T --ttl --ip-timestamp flags

int main(int argc, char **argv)
{
	int flags, opt;
	int nsecs, tfnd;
//	atexit(print);
//	setlocale(LC_ALL, "");

	nsecs = 0;
	tfnd = 0;
	flags = 0;
	while ((opt = getopt(argc, argv, "ntv:?")) != -1) {
		switch (opt) {
		case '?':
			flags = 1;
			break;
		case 'n':
			flags = 1;
			break;
		case 't':
			nsecs = atoi(optarg); // segfault
			tfnd = 1;
			break;
		case 'v':
			break;
		default: /* '?' */
			fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",
				argv[0]);
			exit(EXIT_FAILURE);
		}
	}

	printf("flags=%d; tfnd=%d; nsecs=%d; optind=%d\n", flags, tfnd, nsecs,
	       optind);

	if (optind >= argc) {
		fprintf(stderr, "Expected argument after options\n");
		exit(EXIT_FAILURE);
	}

	printf("name argument = %s\n", argv[optind]);

	/* Other code omitted */

	exit(EXIT_SUCCESS);
}
