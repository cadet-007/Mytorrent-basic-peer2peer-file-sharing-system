#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

using namespace std;

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc,char *argv[])
{
    int sockfd,portno,n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    
    char buffer[1024];
    
    if(argc<3)
    {
        cout<<"Port Number or Host Name missing.Program terminated.\n"<<argv[0];
        exit(1);
    }
    portno=atoi(argv[2]);
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0)
        error("ERROR opening Socket");

    server=gethostbyname(argv[1]);
    if(server==NULL)
    {
        cout<<"ERROR no such host.";
    }
    bzero((char*) &serv_addr,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    bcopy((char*)server->h_addr,(char*) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port=htons(portno);
    if(connect(sockfd,(struct sockaddr*) &serv_addr,sizeof(serv_addr))<0)
        error("Connection Failed");
        
    while(1)
    {
        bzero(buffer,1024);
        cin.getline(buffer,1024);       
        n=write(sockfd,buffer,strlen(buffer));
         if(n<0)
            error("ERROR on Writing."); 
            
        bzero(buffer,1024);    
        n=read(sockfd,buffer,1024);
        if(n<0)
            error("ERROR on Reading.");
        cout<<"Server: "<<buffer<<endl;    
            
        int i=strncmp("Bye",buffer,3);
        if(i==0)
        break;
    }    

    close(sockfd);

    return 0;
}
