#include <stdio.h>
int main (int argc,char** argv)
{
	int count=1;
	if (argc <2)
	{
		printf("need an argument (int)\n");
		return 0;
	}
	int a=atoi(argv[1]);
	switch (a%10)
	{
		while(1)
		{
			case 9:printf("case 9\t");
			       printf("count=%d\n",count++);
			       if ( --a == 0 ) break;
			case 8:printf("case 8\t");
			       printf("count=%d\n",count++);
			       if ( --a == 0 ) break;
			case 7:printf("case 7\t");
			       printf("count=%d\n",count++);
			       if ( --a == 0 ) break;
			case 6:printf("case 6\t");
			       printf("count=%d\n",count++);
			       if ( --a == 0 ) break;
			case 5:printf("case 5\t");
			       printf("count=%d\n",count++);
			       if ( --a == 0 ) break;
			case 4:printf("case 4\t");
			       printf("count=%d\n",count++);
			       if ( --a == 0 ) break;
			case 3:printf("case 3\t");
			       printf("count=%d\n",count++);
			       if ( --a == 0 ) break;
			case 2:printf("case 2\t");
			       printf("count=%d\n",count++);
			       if ( --a == 0 ) break;
			case 1:printf("case 1\t");
			       printf("count=%d\n",count++);
			       if ( --a == 0 ) break;
			case 0:printf("case 0\t");
			       printf("count=%d\n",count++);
			       if ( --a == 0 ) break;
		}
	}

	return  (0);
}
