
all: client server

client: client.c
	gcc client.c -o client
server: server.c
	gcc server.c -o server
clean:
	rm -f *.o client server
.PHONY: all clean