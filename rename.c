#include <stdio.h>
#include "g_unix.h"

int main (int argc,char **argv)
{
    int i = 0;
	char oldname[TEMPSTR_LENTH]={0};
	char newname[TEMPSTR_LENTH]={0};
	char* pos=NULL;
	int len=strlen(argv[1]);

    if (argc < 4 )
	{
	    err_quit("usage:%s < old sub string > < new sub string > <filename...>",
				basename(argv[0]));
	}

	for (i = 3 ; i<argc;++i)
	{
	    strncpy(oldname,argv[i],TEMPSTR_LENTH);
		if (0 == (pos=strstr(oldname,argv[1])))
		{
		    continue;
		}
		else
		{
		    memset(newname,0,sizeof(newname));
			memcpy(newname,oldname,pos-oldname);
			strcat(newname,argv[2]);
			strcat(newname,pos+len);
		}
		if (( rename (oldname,newname) ) <0 )
		{
			/**
			err_sys("%s: error for %s to %s",
					basename(argv[0]) ,argv[1],argv[2]);
					**/
		}
	}
	

	exit (0);
}
