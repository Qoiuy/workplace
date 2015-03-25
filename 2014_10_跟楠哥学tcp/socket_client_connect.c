#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<string.h>
int main()
{
	int sockfd;
	struct sockaddr_in servaddr;

	sockfd = socket(AF_INET,SOCK_STREAM,0);

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(6666);
	connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	
	close(sockfd);
	return 0;
}
