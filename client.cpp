#include<sys/types.h>
#include<sys/shm.h>
#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<cstring>
#include<stdlib.h>
#include"key.h"
using namespace std;
int main(int argc,char** argv)
{
	int key=shmget(KEY,1024,0666);
	char*shm=(char*)shmat(key,NULL,0);
        char buff[50];
	int fopen=open(argv[1],O_RDONLY);
	if(fopen==-1)
	{
		cout<<"Unable to open file\n";
		return -1;
	}
	int n=read(fopen,buff,sizeof(buff));
	buff[n]='\0';
	cout<<buff<<endl;
	cout<<n<<endl;
	close(fopen);
	int ctr=0;
	char arr[n];
	int j=0;
	for(int i=0;buff[i]!='\0';i++)
	{
		if(buff[i]>='0' && buff[i]<='9')
		{
			arr[j++]=buff[i]-48;
		}
		else
		n--;
	}
	int i=0;
	while(i<n)
	{
		cout<<arr[i++]<<" ";
	}
	memcpy(shm+1,arr,n+2);//idher n kyun ni sai kun k n to number hain array main end per 0 n+1 ok shukria
	char*s=shm;
	*shm='*';
	shmdt(shm);
	return 0;
}

