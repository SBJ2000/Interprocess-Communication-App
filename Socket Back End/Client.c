#include"serv_cli2.h"
int main()
{
int client_sock;
struct sockaddr_in addr;
/*Déclarations*/
struct ClientData CD;
struct ServerData SD;
CD.mypid=getpid();
//creation socket
client_sock = socket(AF_INET,SOCK_STREAM,0);
fh= fopen("outputclient2.txt","w");
if(fh==NULL)
{
printf("error opening file");
exit(1);
} 
fputs ("client socket created succefully\n",fh);
fclose(fh);
printf("client socket created succefully\n");
//connection au serveur
memset(&addr,'\n',sizeof(addr));
addr.sin_family = AF_INET;
addr.sin_port = htons(5000);
addr.sin_addr.s_addr=inet_addr("127.0.0.3");
bind(client_sock,(struct sockaddr*)&addr,sizeof(addr));
connect(client_sock,(struct sockaddr*)&addr,sizeof(addr));
printf("connected to server\n");
fh= fopen("outputclient2.txt","a");
if(fh==NULL)
{
printf("error opening file");
exit(1);
} 
fputs ("connected to server\n",fh);
fclose(fh);
//transfert des données
/*Construction et envoie d'une question*/
fh= fopen("outputclient2.txt","a");
if(fh==NULL)
{
printf("error opening file");
exit(1);
} 
char mypidtotext[100] ;
sprintf(mypidtotext, "%d", CD.mypid);
char text1[100] ="mon pid est  ";
strcat(text1, mypidtotext);
char text11[100]="\n";
strcat(text1, text11);
fputs (text1,fh);
fclose(fh);
printf("mon pid est %d \n",CD.mypid);
CD.nmax=NMax;
srand(getpid());
CD.monentier= 1 +rand()%(CD.nmax-1+1);
send(client_sock,&CD,sizeof(CD),0);
for (int compteur = 0 ; compteur < CD.monentier ; compteur++)
{
read(client_sock,&SD,sizeof(SD));
fh= fopen("outputclient2.txt","a");
if(fh==NULL)
{
printf("error opening file");
exit(1);
}
char serveurpidtotext[100] ;
sprintf(serveurpidtotext, "%d", SD.mypid);
char text2[100] ="le serveur  ";
strcat(text2, serveurpidtotext);
char text3[100] =" a renvoyer le nombre:  ";
strcat(text2,text3);
char monentiertotext[100] ;
sprintf(monentiertotext, "%d", SD.monentier);
strcat(text2,monentiertotext);
char text4[100]="\n";
strcat(text2,text4);
fputs (text2,fh);
fclose(fh);
/*Traitement locale de la réponse*/
printf("le serveur %d a renvoyer le nombre:%d \n",SD.mypid,SD.monentier);
}
//fermerture socket
close(client_sock);
printf("Disconnected from the server\n");
fh= fopen("outputclient2.txt","a");
if(fh==NULL)
{
printf("error opening file");
exit(1);
}
fputs ("Disconnected from the server\n",fh);
fclose(fh);
return 0;
}
