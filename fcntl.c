#include <fcntl.h>
#include "g_unix.h"

void set_fl(int fd, int flags)
{
    int val;
	if (( val= fcntl (fd,F_GETFL,0)) <0 ) 
	{
	   err_sys ("fcntl F_GETFL error");
	}

	val |= flags;  /** turn on flags **/

	if (fcntl (fd, F_SETFL,val ))
	{
	    err_sys ("fcntl F_SETFL error");
	}
}


void clr_fl(int fd, int flags)
{
    int val;
	if (( val= fcntl (fd,F_GETFL,0)) <0 ) 
	{
	   err_sys ("fcntl F_GETFL error");
	}

	val &= ~flags;  /** turn flags off **/

	if (fcntl (fd, F_SETFL,val ))
	{
	    err_sys ("fcntl F_SETFL error");
	}
}
