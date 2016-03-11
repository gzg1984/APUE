#include <sys/types.h>
#include <sys/stat.h>
#include "g_unix.h"

int main (int argc,char ** argv)
{
    int i;
	struct stat buf;
	char *ptr;

	for ( i = 1 ; i< argc;i++)
	{
	    printf("%s:",argv[i]);
		if(lstat (argv[i],&buf)<0 )
		{
		    err_ret ("lstat error");
			continue;
		}
		if(S_ISREG(buf.st_mode)) 
		{
			ptr="regular";
		}
		else
		if(S_ISDIR(buf.st_mode)) ptr="directory";
		else
		if(S_ISCHR(buf.st_mode)) ptr="character special";
		else
		if(S_ISBLK(buf.st_mode)) ptr="block special";
		else
		if(S_ISFIFO(buf.st_mode)) ptr="fifo";
		#ifdef S_ISLNK
		else
		if(S_ISLNK(buf.st_mode)) ptr="symbolic link";
		#endif
		#ifdef S_ISSOCK
		else
		if(S_ISSOCK(buf.st_mode)) ptr="socket";
		#endif
		else
		{
		    ptr=" ** unknown mode **";
		}
		printf ("\t%s\tdev=%d/%d",
				ptr,major(buf.st_dev),minor(buf.st_dev));
		if( S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
		{
		    printf ("\t(%s)\trdev=%d/%d ",
				(S_ISCHR(buf.st_mode)) ? "character":"block",
				major(buf.st_rdev),minor(buf.st_rdev));
		}

		printf("\n");
	}
	exit (0);
}
