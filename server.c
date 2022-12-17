#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdlib.h>

int main() {
	int sockfd;
		
	struct sockaddr_in { 
		short sin_family; // e.g. AF_INET 
		unsigned short sin_port; // e.g. htons(3490)‏ 
		struct in_addr sin_addr; // see struct in_addr below 
		char sin_zero[8]; // zero this if you want to 
	}; 

	struct in_addr { 
		unsigned long s_addr; // load with inet_aton()‏ 
	};

	printf("Hello World \n");

	// Create socket
	if ((sockfd = socket (AF_INET, SOCK_STREAM, 0) < 0)) {
		printf ("Error while creating the socket\n");
		exit(1);
	};

	bzero (&my_addr, sizeof(my_addr));
	my_addr.sin_family = AF_INET; // match the socket() call
	my_addr.sin_port = htons(5100); // specify port to listen on
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY); //allow the server to accept a client connection on any interface

 
	// Bind
	int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
	
	// Listen
	int listen (int sockfd, int backlog);
	
	// Accept
	int accept (int sockfd, struct sockaddr *fromaddr, socklen_t *addrlen);

	return 0;
}
