#include"server.h"
#include<unistd.h>
#include<string.h>

void launch(struct server* serv){
    char buffer[256];
    char* hello = "HTTP/1.1 200 OK RIGHT! C'MON C'MON\r\n\r\n";
    socklen_t len = sizeof(serv->address);
    int new_socket;
    while(1){
    printf("Waiting for new connection.....\n");
    socklen_t len = sizeof(serv->address);
    new_socket = accept(serv->socket, (struct sockaddr*)&serv->address, &len);
    read(new_socket, buffer, 256);
    printf("%s\n", buffer);
    write(new_socket, hello, strlen(hello));
    close(new_socket);
    }
}

int main(){
    struct server serv = server_constructor(AF_INET, 0, SOCK_STREAM, INADDR_ANY, 80, 10, launch);
    serv.launch(&serv);
}
