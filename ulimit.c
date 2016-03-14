#include <sys/time.h>
#include <sys/resource.h>
#include <g_unix.h>

#define doit(name) pr_limit(#name,name)

static void pr_limit(char *name,int resource)
{
    struct rlimit limit;
	if ( getrlimit(resource,&limit) <0)
	{
	    err_sys("getrlimit error for %s",name);
	}
	printf("%-14s  ",name);
	if( limit.rlim_cur == RLIM_INFINITY)
	{
	    printf( "(infinite)  ");
	}
	else
	{
	    printf( "%10ld  ",limit.rlim_cur);
	}
	if ( limit.rlim_max == RLIM_INFINITY )
	{
	    printf(" (infinite)\n");
	}
	else
	{
	    printf( "%10ld\n",limit.rlim_max);
	}
}

int main(int argc,char** argv)
{
    int i=0;
	struct rlimit rl;
	struct
	{
	    char name[128];
	    int num;
	}resource[11]={
	{ "core file size          (blocks, -c)", RLIMIT_CORE },
	{ "data seg size           (kbytes, -d)", RLIMIT_DATA},
	{ "file size               (blocks, -f)", RLIMIT_FSIZE},
	{ "max locked memory       (kbytes, -l)", RLIMIT_MEMLOCK},
	{ "max memory size         (kbytes, -m) ", RLIMIT_RSS},
	{ "open files                      (-n)", RLIMIT_NOFILE},
	{ "open files                      (-n)", RLIMIT_OFILE},
	{ "stack size              (kbytes, -s)", RLIMIT_STACK},
	{ "cpu time               (seconds, -t)", RLIMIT_CPU},
	{ "max user processes              (-u)", RLIMIT_NPROC},
	};
	#ifdef RLIMIT_VMEM
	doit(RLIMIT_VMEM);
	#endif
	#ifdef RLIMIT_NPROC 
	doit(RLIMIT_NPROC);
	#endif

	for ( i=0;i<10;i++)
	{
		getrlimit(resource[i].num,&rl);
		if( rl.rlim_cur == -1 )
		{
			printf("%s %s(%d)\n",
					resource[i].name,"unlimited",rl.rlim_max);
		}
		else
		{
			printf("%s %d(%d)\n",
					resource[i].name,rl.rlim_cur ,rl.rlim_max);
		}
	}
	return 0;

}

