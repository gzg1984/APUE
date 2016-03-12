#include <sys/utsname.h>
#include "g_unix.h"


/**
struct utsname
  {
    char sysname[65];
    char nodename[65];
    char release[65];
    char version[65];
    char machine[65];
    char __domainname[65];
  };
**/


int main(int argc ,char** argv)
{
    struct utsname un;

    if ( 0 > uname(&un) )
	{
	    err_quit("%s:err",basename(argv[0]));    
	}
	if ( argc == 1 )
	{
	    printf("%s\n", un.sysname);
	}
	/**
	else if( argc==2 && (0 ==strcmp(argv[1],"-a") ))
	**/
	else if( argc==2 && !strcmp(argv[1],"-a") )
	{
	    printf("%s %s %s %s %s %s\n", 
			un.sysname,
			un.nodename,
			un.release,
			un.version,
			un.machine, 
			un.__domainname);
	}
	else if( argc==2 && !strcmp(argv[1],"-r") )
	{
	    printf("%s\n", un.release);
	}
	else if( argc==2 && !strcmp(argv[1],"-v") )
	{
	    printf("%s\n", un.version );
	}
	else if( argc==2 && !strcmp(argv[1],"-n") )
	{
	    printf("%s\n", un.nodename  );
	}
	else if( argc==2 && !strcmp(argv[1],"-m") )
	{
	    printf("%s\n", un.machine);
	}
	else
	{
	    printf( "无效选项\n" );
	}

	return 0;
}
