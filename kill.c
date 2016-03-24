/** v2.0  add kill -l **/
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>

extern const char *const sys_siglist[];

int main(int argc,char** argv)
{
	pid_t pid;
	int sig;

	if (argc = 2 && 0 == strcmp(argv[1] ,"-l"))
	{
	    killlist_main(argc,argv);
		return 0;
	}
	else if(argc < 3 )
	{
	    printf("need more args");
	}
	pid=atoi(argv[2]);
	sig=atoi(&(argv[1][1]));
	kill(pid,sig);
	return 0;
}

killlist_main(int argc,char** argv)
{
	int i = 1;
	for (i =1 ; sys_siglist[i]!=(void*)0; i++)
	{
	    printf("%d ) %s\n",i,sys_siglist[i] );
	}
	return 0;
}
