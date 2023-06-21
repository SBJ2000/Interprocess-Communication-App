#include <stdio.h> //input et output
#include<stdlib.h> //exlt
#include<string.h> //bezero rensent
#include<unistd.h>//read revceive
#include<sys/types.h>
#include<sys/socket.h>//creation de socket
#include<netinet/in.h>//domaine internet
#include<arpa/inet.h>//@ip
#include<signal.h>

struct ClientData {   
  int mypid;           
  int monentier;
  int nmax;       
};
struct ServerData {   
  int mypid;           
  int monentier;       
};
int NMax=10;
FILE *fh;
