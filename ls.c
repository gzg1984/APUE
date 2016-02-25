#include <sys/types.h>
#include <errno.h>
#include <dirent.h>
#include "g_unix.h"

#define SOPATH "/root/Desktop/g-Unix/lib/libapue.so"


int main(int argc,char** argv)
{
    DIR *dp;
	struct dirent *dirp;
	//void *dlopen(const char *filename, int flag);

	if ( argc != 2 )
	{
	    err_quit ( "a single argument (the directory name ) is required");
	}

	if ( ( dp = opendir ( argv[1] )) == NULL )
	{
	    fprintf(stderr,"%s:%s\n ",argv[0],strerror(errno));
	    perror(argv[0]);
	    err_sys ("can't open %s\n",argv[1]);
	}

	while ((dirp = readdir(dp)) != NULL)
	{
	    printf("%c[34;47m%s\n",'\033',dirp->d_name);
	}

	closedir(dp);
	exit(0);
}

