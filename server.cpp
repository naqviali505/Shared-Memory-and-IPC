#include<sys/types.h>
#include<sys/shm.h>
#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<cstring>
#include<stdlib.h>
#include "key.h"
using namespace std;
int main(int argc,char** argcv)
{
        
	int key=shmget(KEY,1024,IPC_CREAT|0666);
	cout<<key<<" KEY"<<endl;
	char*shmem=(char*)shmat(key,NULL,0);
	char*s;
	int i=0,sum=0;
	cout<<"ANA CHAHIAY\n";
	*shmem=0;
	while(*shmem!='*')
		sleep(1);
	for(s=shmem+1;;s++)
	{
		if(*s==0)
		break;
		cout<<"*s"<<int(*s)<<" ";
		sum=sum+ *s;
		i++;
		cout<<"i"<<i<<endl;
	}
	cout<<endl;
	cout<<"Sum is "<<sum<<" and count is "<<i<<endl;
	cout<<"Average is "<<sum<<"/"<<i<<"= "<<sum/i<<endl;	
	shmdt(shmem);
	shmctl(key, IPC_RMID, NULL);
	return 0;	
}
