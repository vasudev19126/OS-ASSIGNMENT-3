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
#include <sys/stat.h>


int main()
{
	long pid;
	pid=fork();
	if(pid<0){
		printf("forked failed");
		return 0;
	}
	else if(pid==0)
	{
		long int sys_return = syscall(440,(int)getpid(),10000000000);
		struct timeval t1,t2;
		gettimeofday(&t1,NULL);
		long i=0;
		for(i=0;i<10000000000;i++);
		gettimeofday(&t2,NULL);
		printf("\n%lf this is time of child\n",(double)(t2.tv_usec-t1.tv_usec)/1000 + (double)(t2.tv_sec-t1.tv_sec)*1000);
		printf("Syscall returned = %ld \n", sys_return);
		
	}
	else
	{
		
		struct timeval t1,t2;
		gettimeofday(&t1,NULL);
		long i=0;
		for(i=0;i<10000000000;i++);
		gettimeofday(&t2,NULL);
		printf("\n%lf this is time of parent\n",(double)(t2.tv_usec-t1.tv_usec)/1000 + (double)(t2.tv_sec-t1.tv_sec)*1000);
		wait(NULL);
		
	}
	return 0;

}