#include <stdio.h>
#define IP "142.250.195.46"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 8181

int main(){
    int s, c;
    char buff[512];
    char* data;
    socklen_t addrlen;
    struct sockaddr_in srv, cli;
    memset(&srv, 0, sizeof(srv));
    memset(&cli, 0, sizeof(cli));
    s = socket(AF_INET, SOCK_STREAM, 0);
    if(s<0){
        printf("socket failed!!\n");
        return -1;
    }
    srv.sin_family = AF_INET;
    srv.sin_addr.s_addr = 0;
    srv.sin_port = htons(PORT);
    
    if(bind(s, (struct sockaddr*)&srv, sizeof(srv))){
        printf("bind failed!!\n");
        close(s);
        return -1;
    }
    if(listen(s, 5)){
        printf("listen failed!!!\n");
        close(s);
        return -1;
    }
    printf("Listening to 0.0.0.0 on port %d\n", PORT);
    addrlen = 0;
    c = accept(s, (struct sockaddr*)&srv, &addrlen);
    if(c < 0){
        printf("accept failed!!\n");
        close(s);
        return -1;
    }
    printf("Connection established");
    read(c, buff, 511);
    data = "httpd v1.0\n";
    write(c, buff, strlen(data));
    close(s);
    close(c);
    return 0;
}

