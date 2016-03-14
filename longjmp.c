#include <setjmp.h>
#include <stdio.h>

/**
gcc
or
gcc -O
will cause different result:

gcc -o longjmp longjmp.c
./longjmp
in f1();count=97,val=98,sum=99
after longjmp: count=97,val =98,sum=99


gcc -o longjmp longjmp.c -O
./longjmp
in f1();count=97,val=98,sum=99
after longjmp: count=2,val =3,sum=99

 **/
static void f1(int,int,int);
static void f2(void);

static jmp_buf jmpbuffer;

int main(int argc,char** argv)
{
    int  count;
	register int val;
	volatile int sum;

	count =2; val =3 ; sum =4 ;
	if( setjmp(jmpbuffer) !=0 )
	{
	    printf("after longjmp: count=%d,val =%d,sum=%d\n",
		    count,val,sum);
		return (0);
	}

	count=97;val=98;sum=99;
	f1(count,val,sum);

	return 0;

}

static void f1( int i,int j, int k )
{
      printf("in f1();count=%d,val=%d,sum=%d\n",i,j,k);
	  f2();
}

static void f2( void )
{
    longjmp(jmpbuffer,1);
}
