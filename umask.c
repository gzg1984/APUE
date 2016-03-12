#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "g_unix.h"

int main (int argc,char **argv)
{
	err_quit("DANGROUS code  ,do not RUN this ");

    if (argc != 3 )
	{
	    err_quit("usage:%s <filename1> <filename2>",basename(argv[0]));
	}

	umask(0);

    if (creat(argv[1],S_IRUSR|S_IWUSR | S_IRGRP |S_IWGRP |
					S_IROTH |S_IWOTH ) <0 )
	{
	    err_sys("creat err for %s",argv[1]);
	}

	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );

    if (creat(argv[2],S_IRUSR|S_IWUSR | S_IRGRP |S_IWGRP |
					S_IROTH |S_IWOTH ) <0 )
	{
	    err_sys("creat err for %s",argv[2]);
	}
	exit (0);
}
