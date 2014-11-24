#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
int main()
{
	int sockfd;

	sockfd = socket(AF_INET,SOCK_STREAM,0);

	
	close(sockfd);
	return 0;
}
