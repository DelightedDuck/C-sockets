#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

int main() {
	int sockfd;
	const int MAXLINE = 4096;
	const int PORT = 69;
	
	// Create socket
	if ((sockfd = socket (AF_INET, SOCK_STREAM, 0) < 0)) {
		printf ("Error while creating the socket\n");
		return -1;
	};

	bzero (&my_addr, sizeof(my_addr));
	sockaddr.sin_family = AF_INET; 
	sockaddr.sin_port = htons(PORT);
	//	sockaddr.sin_addr.s_addr = htonl(INADDR_ANY); //allow the server to accept a client connection on any interface

	// Bind
	if ((bind(sockfd, (struct sockaddr *)&my_addr, sizeof(my_addr)) > 0)) {
		printf("error while binding");
		return -1;
	}
	
	// Listen
	if ((listen(sockfd, MAXLINE) > 0)) {
		printf("failed to listen");
		return -1;
	}
	
	// Accept
	if ((accept(sockfd, (struct sockaddr *)&my_addr, sizeof(my_addr)) > 0)) {
		printf("failed to accept");
		return -1;
	}
	

	close(sockfd);
	return 0;
}
