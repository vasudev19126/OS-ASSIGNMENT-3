/* Name: Vasudev Singhal
   Roll_Number: 2019126 */
#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	long pid,tem,i=0;
	pid=fork();
	if(pid>0)
	{
		
		printf("%ld  %d\n",pid, (int)getpid());
		//pid=(int)getpid();
		syscall(440,12,1000000000);
		
		struct timeval t1,t2;
		gettimeofday(&t1,NULL);
		for(i=0;i<10000000000;i++);
		gettimeofday(&t2,NULL);		
		printf("\n%lf  this is time 1\n",(double)(t2.tv_usec-t1.tv_usec)/1000 + (double)(t2.tv_sec-t1.tv_sec)*1000);
		wait(NULL);
	}
	else
	{
		struct timeval t1,t2;
		gettimeofday(&t1,NULL);
		for(i=0;i<10000000000;i++);
		gettimeofday(&t2,NULL);
		printf("\n%lf  this is time 2\n",(double)(t2.tv_usec-t1.tv_usec)/1000 + (double)(t2.tv_sec-t1.tv_sec)*1000);
		

	}
	return 0;

}