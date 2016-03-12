#include <stdio.h>
#include "g_unix.h"

int main (int argc,char **argv)
{
    if (argc != 3 )
	{
	    err_quit("usage:%s < old filename > < new filename >",
				basename(argv[0]));
	}

	if (( rename (argv[1],argv[2] ) ) <0 )
	{
	    err_sys("%s: error for %s to %s",
				basename(argv[0]) ,argv[1],argv[2]);
	}

	exit (0);
}
