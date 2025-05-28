#include"server.h"
#include<stdlib.h>

struct server server_constructor(int domain, int protocol, int service, u_long interface, int port, int backlog, void (*launch)(struct server* serv)){
    struct server serv;
    
    serv.domain = domain;
    serv.protocol = protocol;
    serv.service = service;
    serv.interface = interface;
    serv.port = port;
    serv.backlog = backlog;
    
    serv.address.sin_addr.s_addr = htonl(interface);
    serv.address.sin_port = htons(port);
    serv.address.sin_family = domain;
    serv.socket = socket(domain, service, protocol);

    if(serv.socket <= 0){
        perror("connection failed!!\n");
        exit(1);
    }
    if(bind(serv.socket, (struct sockaddr*)&serv.address, sizeof(serv.address)) < 0){
        perror("binding failed!!\n");
        exit(2);
    }
    if(listen(serv.socket, serv.backlog)<0){
        perror("listening failed!!\n");
        exit(3);
    }

    serv.launch = launch;

    return serv;
}



