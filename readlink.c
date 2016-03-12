#include <sys/types.h>
#include <sys/stat.h>
#include "g_unix.h"

int main (int argc,char ** argv)
{
    int i=0;
    int bufsize=0;
	struct stat buf;
	char linkbuf[TEMPSTR_LENTH]={0};

	for ( i = 1 ; i< argc;i++)
	{
		if(lstat (argv[i],&buf)<0 )
		{
		    err_ret ("lstat error");
			continue;
		}

		#ifdef S_ISLNK
		if(S_ISLNK(buf.st_mode)) 
		{
		    if ( 1 > (bufsize=readlink(argv[i],linkbuf,TEMPSTR_LENTH)))
			{
			    err_sys("readlink() err!");
			}
			else
			{
				printf ("%*.*s\n", bufsize,bufsize,linkbuf);
			}
		}
		else
		#endif
		{
		    printf ("%s\n", " can not readlink ");
		}
	}
	exit (0);
}
