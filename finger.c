#include <pwd.h>
#include <stdio.h>
int main(int argc ,char** argv)
{
    struct passwd* ppwd;

    if( argc == 1 )
	{
	   ppwd=getpwuid(getuid()); 
	}
	else
	{
	   ppwd=getpwnam(argv[1]); 
	}

	printf("Login: %s\t\t\t\tName: %s\n",
			ppwd->pw_name,ppwd->pw_gecos);
	printf("Directory: %s\t\t\tShell: %s\n",
				ppwd->pw_dir ,ppwd->pw_shell);
	printf("pw_passwd:%s\n",ppwd->pw_passwd);
	printf("pw_uid:%d\n",ppwd->pw_uid);
	printf("pw_gid:%d\n",ppwd->pw_gid);

	return 0;
}
