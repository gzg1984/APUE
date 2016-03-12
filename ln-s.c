#include <sys/types.h>
#include "g_unix.h"

int main (int argc,char **argv)
{
    if (argc != 3 )
	{
	    err_quit("usage:%s < source file > < new link >",basename(argv[0]));
	}

	if (( symlink (argv[1],argv[2] ) ) <0 )
	{
	    err_sys("%s: error for %s to %s",
			basename(argv[0]),argv[1],argv[2]);
	}

	exit (0);
}
