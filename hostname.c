#include "g_unix.h"

int main(int argc ,char** argv)
{
    char buf[TEMPSTR_LENTH]={0};

	if (argc == 1)
	{
		if( 0> gethostname(buf,TEMPSTR_LENTH) )
		{
			err_quit("%s:err",basename(argv[0]));
		}
		else
		{
			printf("%s\n",buf);
		}
	}
	else
	{
	    if ( 0 > sethostname(argv[1],strlen(argv[1])) )
		{
			err_quit("%s:err",basename(argv[0]));
		}
		else
		{
		    /** next step **/
		}
	}

	return 0;
}
