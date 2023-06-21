#include"serv_cli2.h"
int main()
{
/*Declaration*/
struct ClientData CD;
struct ServerData SD;
int server_sock,new_sock;
struct sockaddr_in server_addr , new_addr;
pid_t child_pid;
/*Initialisation du generateur aleatoirede nombres*/
srand(getpid());
SD.mypid=getpid();
//creation socket
server_sock = socket(AF_INET,SOCK_STREAM,0);
fh= fopen("outputserver2.txt","w");
if(fh==NULL)
{
printf("error opening file");
exit(1);
} 
fputs ("server socket created succefully\n",fh);
fclose(fh);
printf("server socket created succefully\n");
//association @ip+n°port
memset(&server_addr,'\n',sizeof(server_addr));
server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(5000);
server_addr.sin_addr.s_addr=inet_addr("127.0.0.3");
int b=bind(server_sock,(struct sockaddr*)&server_addr,sizeof(server_addr));
if(b<0)
{
perror("Bind error\n");
exit(1);
}
fh= fopen("outputserver2.txt","a");
if(fh==NULL)
{
printf("error opening file");
exit(1);
} 
fputs ("Bind to port number\n",fh);
fputs ("listening ...\n",fh);
fclose(fh);
printf("Bind to port number\n");
//ecoute des cnx
listen(server_sock,5);
printf("listening ...\n");
//accept la cnx
while(1){
socklen_t addr_size =sizeof(new_addr);
new_sock = accept(server_sock,(struct sockaddr*)&new_addr,&addr_size);
if ((child_pid= fork())==0)
{
close(server_sock);
while(1)
{
fh= fopen("outputserver2.txt","a");
if(fh==NULL)
{
printf("error opening file");
exit(1);
} 
fputs ("client connected\n",fh);
fclose(fh);
printf("client connected\n");
//transfert des données
/*Lecture d'une question*/
recv(new_sock,&CD,sizeof(CD),0);


/*Envoie de la reponse*/
fh= fopen("outputserver2.txt","a");
if(fh==NULL)
{
printf("error opening file");
exit(1);
} 
printf("ecrivain %d a demandé du serveur: %d entiers au hasard\n",CD.mypid,CD.monentier);
char mypidtotext[100] ;
sprintf(mypidtotext, "%d", CD.mypid);
char text1[100] ="ecrivain ";
strcat(text1, mypidtotext);
char text2[100] =" a demandé du serveur: ";
strcat(text1, text2);
char monentiertotext[100] ;
sprintf(monentiertotext, "%d", CD.monentier);
strcat(text1, monentiertotext);
char text3[100] =" entiers au hasard\n";
strcat(text1, text3);
fputs (text1,fh);
fclose(fh);
int tabrandom[10];
char mynumbertext[100] ;
char mycompteurtext[100] ;
for (int compteur = 0 ; compteur < CD.monentier ; compteur++)
{
tabrandom[compteur] = 1 +rand()%(CD.nmax-1+1);
sprintf(mynumbertext, "%d", tabrandom[compteur]);
sprintf(mycompteurtext, "%d",compteur);
char text4[100] ="l'entier au hasard numero  ";
strcat(text4,mycompteurtext);
char text5[100]=" est ";
strcat(text4,text5);
strcat(text4,mynumbertext);
char text6[100]=" \n ";
strcat(text4,text6);
fh= fopen("outputserver2.txt","a"); 
fputs (text4,fh);
fclose(fh);
}
fh= fopen("outputserver2.txt","a"); 
fputs ("client disconnected \n",fh);
fclose(fh);
for (int compteur = 0 ; compteur < CD.monentier ; compteur++)
{
SD.monentier = tabrandom[compteur];
printf("l'entier au hasard numero %d est %d \n",compteur,SD.monentier);
write(new_sock,&SD,sizeof(SD));
}
//fermerture socket
close(new_sock);
close(server_sock);
printf("client disconnected \n");
exit(0);
}}}
return 0;
}
