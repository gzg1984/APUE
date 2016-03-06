#include <sys/types.h>
#include <sys/stat.h>
#include "g_unix.h"

int main (int argc,char **argv)
{
    struct stat statbuf;

    if (argc != 3 )
	{
	    err_quit("usage:%s <mod> <pathname>",basename(argv[0]));
	}
	/**
	else if(4 != strlen(argv[1]))
	{
	    err_quit("<mod> length must be 4");
	}
	**/

    if (stat(argv[2],&statbuf) < 0 )
	{
	    err_sys("stat error for %s",argv[2]);
	}

	/**
	if ( chmod(argv[2],(statbuf,st_mod &~S_IXGRP) | S_ISGID  ) <0 )
	if ( chmod(argv[2],S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH ) <0 )
	**/
	if (( chmod(argv[2],atoi(argv[1])) ) <0 )
	{
	    err_sys("chmod error for %s", argv[2]);
	}

	exit (0);
}
