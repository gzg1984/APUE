#include <sys/types.h>
#include "g_unix.h"

int main (int argc,char **argv)
{
    if (argc != 3 )
	{
	    err_quit("usage:%s < own id > <pathname>",basename(argv[0]));
	}

	if (( chown (argv[2],atoi(argv[1]),-1) ) <0 )
	{
	    err_sys("chown error for %s", argv[2]);
	}

	exit (0);
}
