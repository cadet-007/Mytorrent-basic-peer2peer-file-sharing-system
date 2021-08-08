#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

using namespace std;

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc,char *argv[])
{
    if(argc<2)
    {
        cout<<"Port Number missing.Program terminated.\n";
        exit(1);
    }
    
    int sockfd,newsockfd,portno,n;
    char buffer[1024];
    
    struct sockaddr_in serv_addr,cli_addr;
    socklen_t clilen;
    
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0)
    { 
        error("ERROR opening Socket");
    }
    
    bzero((char*) &serv_addr,sizeof(serv_addr));
    portno=atoi(argv[1]);
    
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=INADDR_ANY;
    serv_addr.sin_port=htons(portno);
    
    if(bind(sockfd,(struct sockaddr*) &serv_addr,sizeof(serv_addr))<0)
        error("Binding Failed.");  
        
    listen(sockfd,5);
    clilen=sizeof(cli_addr);
    
    newsockfd=accept(sockfd,(struct sockaddr*) &cli_addr,&clilen); 
    if(newsockfd<0)
        error("ERROR on Accept");
   
    while(1)
    {
        bzero(buffer,1024);
        n=read(newsockfd,buffer,1024);
        if(n<0)
            error("ERROR on Reading.");
        cout<<"Client: "<<buffer<<endl;
        bzero(buffer,1024);
        cin.getline(buffer,1024);
        
        n=write(newsockfd,buffer,strlen(buffer));
         if(n<0)
            error("ERROR on Writing."); 
            
        int i=strncmp("Bye",buffer,3);
        if(i==0)
        break;
        
    }
    
    close(newsockfd);
    close(sockfd);
                      
    return 0;
}    

