/**
  unlink的这种特性经常被程序用来确保即使是在程序崩溃时，它所创建的临时文件也不会
  遗留下来。进程用 open或creat创建一个文件，然后立即调用 unlink。因为该文件仍旧是打开的，
  所以不会将其内容删除。只有当进程关闭该文件或终止时（在这种情况下，内核关闭该进程所
  打开的全部文件）   ，该文件的内容才被删除。
  **/

#include <sys/types.h>
#include "g_unix.h"

int main (int argc,char **argv)
{
    if (argc != 2 )
	{
	    err_quit("usage:%s < file name  > ",basename(argv[0]));
	}

	if (( unlink (argv[1] ) ) <0 )
	{
	    err_sys("unlink error for %s ",argv[1]);
	}

	exit (0);
}
