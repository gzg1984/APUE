#include "g_unix.h"

int main (int argc,char **argv)
{
    if (argc != 2 )
	{
	    err_quit("usage:%s < dir name > ",basename(argv[0]));
	}

	if (( chdir (argv[1]) ) <0 )
	{
	    err_sys("%s: error for %s ",
				basename(argv[0]),argv[1]);
	}

	exit (0);
}
