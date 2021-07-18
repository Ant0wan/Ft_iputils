
#include <locale.h>
#include <stdlib.h>

#include "iputils_common.h"

int	main(int argc, char **argv)
{
	atexit(print);
	setlocale(LC_ALL, "");
	return 0;
}
