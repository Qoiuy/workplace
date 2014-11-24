#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<string.h>
int main()
{
	int sockfd;
	struct sockaddr_in servaddr;
	char sendline[4096];

	sockfd = socket(AF_INET,SOCK_STREAM,0);

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(6666);
	connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	
	printf("send msg to server : /n");
	fgets(sendline, 4096, stdin);
	send(sockfd, sendline, strlen(sendline), 0);

	close(sockfd);
	return 0;
}
