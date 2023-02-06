CC=gcc

web-client: web-client.c 
	$(CC) -o web-client web-client.c

server: server.c
	$(CC) -o server server.c
