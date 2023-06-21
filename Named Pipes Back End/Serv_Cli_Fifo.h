#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<signal.h>
#include <string.h>
char nomTube[]="Fifo1";
char nomTube2[]="Fifo2";
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
