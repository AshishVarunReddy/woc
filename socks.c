#include <stdio.h>
#define IP "142.250.195.46"
#define PORT 80
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(){
    char buf[512] = {0};
    char *data;
    data = "HEAD / HTTP/1.0\n\n";



    int s = socket(AF_INET, SOCK_STREAM, 0);
    if(s < 0){
        printf("socket not connected\n");
        return -1;
    }   //  struct sock_addr_in addr;
   // addr.sin_addr.s_addr = inet_addr(IP);
    //addr.sin_port = htons(PORT);
    //addr.sin_family = AF_INET;

    struct sockaddr_in addr = {
        AF_INET,
        htons(PORT),
        inet_addr(IP)
    };

    if(connect(s, &addr, sizeof(addr)) < 0){
        printf("connect error...\n");
        close(s);
        return -1;
    }
    write(s, data, strlen(data));
    read(s, buf, 511);

    printf("\n%s\n", buf);

    close(s);
    return 0;
    
}
