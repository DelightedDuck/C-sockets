#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define PORT 80
#define MAXLINE 4096

/*
todo:
fix failed connection
???
profit
*/

int main(int argc, char *argv[]) {
	int sockfd;
	int sendbytes;
	struct sockaddr_in serv_addr;
	char	sendline[MAXLINE];
	char	recvline[MAXLINE];
	
	if ( argc != 2 ) {
		printf("usage: %s <server address> \n", argv[0]);
		return -1;
	}	

	// Create socket
	if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
		printf ("Error while creating the socket\n");
		return -1;
	}
		
	bzero(&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port 	= htons(PORT);

	if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
		printf("inet_pton error for %s lol\n", argv[1]);	
		return -1;
	}	

	// Connect
	int c = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

	if (c < 0 ) {
		printf("Connection failed lol \n");
		return -1;
	}

	// Send HTTP header 
	sprintf(sendline, "GET / HTTP/1.1\r\n\r\n");
	sendbytes = strlen(sendline);
	
	// Write
	if (write(sockfd, sendline, sendbytes) != sendbytes) {
		printf("write error XD");
		return -1;
	}

	// Read response
	int n = read(sockfd, recvline, MAXLINE-1);

	if (n < 0){
		printf("failed to get response");
		return -1;
	}
	
	printf("got response from server\n\n");
	printf("%s\n", recvline);
	
	// Close
	close(sockfd);

	return 0;
}
