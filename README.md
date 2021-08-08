# Mytorrent-basic-peer2peer-file-sharing-system

Project on Peer to Peer file sharing.

# 1.Client-Server Program.

1. Header files included. <Br/>
    1.1. iostream <Br/>
    1.2. stdio.h <Br/>
    1.3. stdlib.h <Br/>
    1.4. string.h <Br/>
    1.5. unistd.h <Br/>
    1.6. sys/types.h <Br/>
    1.7. sys/socket.h <Br/>
    1.8. netinet/in.h <Br/>
    1.9. netdb.h <Br/> <Br/>
    
2. Functions used in Server side. <Br/>
    2.1. Socket creation.    -->    sockfd=socket(AF_INET,SOCK_STREAM,0); <Br/>
    2.2. Binding socket to address and port number.    -->    bind(sockfd,(struct sockaddr*) &serv_addr,sizeof(serv_addr)); <Br/>
    2.3. Waiting for client to approach the server.    -->    listen(sockfd,5); <Br/>
    2.4. Establishing connection between server and client.    -->    newsockfd=accept(sockfd,(struct sockaddr*) &cli_addr,&clilen); <Br/>
    2.5. Reading sent message.    -->    read(newsockfd,buffer,1024); <Br/>
    2.6. Writing message.    -->    write(newsockfd,buffer,strlen(buffer)); <Br/> <Br/>
    
3. Functions used in Client side. <Br/>
    3.1. Socket creation.    -->    sockfd=socket(AF_INET,SOCK_STREAM,0); <Br/>
    3.2. Connecting with server.    -->    connect(sockfd,(struct sockaddr*) &serv_addr,sizeof(serv_addr); <Br/>
    3.3. Reading sent message.    -->    read(newsockfd,buffer,1024); <Br/>
    3.4. Writing message.    -->    write(newsockfd,buffer,strlen(buffer)); <Br/> <Br/>

# Reference

1. Beej’s guide for network programming. (https://beej.us/guide/bgnet/)
2. Advanced Programming in the UNIX Environment,3rd Edition. (https://1lib.in/book/2714429/9df329)
3. Think and Learn. (https://youtu.be/_lQ-3S4fJ0U)
4. Lecture 25 Socket Programming-II. (https://youtu.be/JExfKvUgrtI) 
5. Geeks for Geeks. (https://www.geeksforgeeks.org/socket-programming-cc/)
