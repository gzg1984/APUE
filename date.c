#include <time.h>
#include <stdio.h>

int main(int argc ,char** argv)
{
    time_t cal;
	char buf[255]={0};
	char format[255]={0};

    if(argc == 1)
	{
	    strcpy(format,"%Y年 %m月 %d日 %A %X %Z");
	}

	if ( 0 > time(&cal) )
	{
		printf("%s:err",basename(argv[0]));
	}
	else
	{
		/** next step **/
	}


	struct tm *ptm;
    	ptm=gmtime(&cal);
	printf("%s\n",asctime(ptm));

	cal=mktime(ptm);
	printf("%s\n",ctime(&cal));

	ptm=localtime(&cal);
	strftime(buf,255,format,ptm);
	printf("%s\n",buf);

	return 0;
}
