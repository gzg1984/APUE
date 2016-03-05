#include <sys/types.h>
#include "g_unix.h"

int main (int argc,char **argv)
{
    if (argc != 3 )
	{
	    err_quit("usage:%s < own id > <pathname>",basename(argv[0]));
	}

	if (( chown (argv[2],-1,atoi(argv[1])) ) <0 )
	{
	    err_sys("%s: error for %s", basename(argv[0]),argv[2]);
	}

	exit (0);
}
