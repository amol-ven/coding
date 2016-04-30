#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int sock;
	struct sockaddr_in server, client;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock==-1)
	{
		printf("Error opening socket\n");
		exit(1);	
	}
	server.sin_family = AF_INET;
	server.sin_port   = htons(10000);
	server.sin_addr.s_addr = INADDR_ANY;
	bzero(&server.sin_zero, 8);
	
	int len = sizeof(struct sockaddr_in);
	
	if(bind(sock, (struct sockaddr *)&server, len)==-1 )
	{
		printf("Error binding socket\n");
		exit(1);	
	}
	
	if(listen(sock, 5)==-1)
	{
		printf("Error on listen\n");
		exit(1);	
	}
	int cli;
	char mes[] = "\nHello from Amol's server. Bye..\n\n";
	while(1)
	{
		if(cli=accept(sock, (struct sockaddr *)&client, &len)==-1)
		{
			printf("Error on accept\n");
			exit(1);	
		}
		printf("len=%d", len);
		int sent = send(cli, mes, strlen(mes), 0);
		printf("sent %d bytes to %s", sent, inet_ntoa(client.sin_addr));
		close(cli);
	}
	
}
