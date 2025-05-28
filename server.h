#ifndef Server_h
#define Server_h

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>


struct server{
    int protocol;
    int domain;
    int service;
    u_long interface;
    int port;
    int backlog;
    int socket;

    struct sockaddr_in address;
    void (*launch)(struct server* serv);
};


struct server server_constructor(int domain, int protocol, int service, u_long interface, int port, int backlog, void (*launch)(struct server* serv));

#endif
