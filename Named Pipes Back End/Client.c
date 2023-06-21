#include"serv_cli_fifo.h"
#include"Handlers_Cli.h"
int main()
{
/*Déclarations*/
struct ClientData CD;
struct ServerData SD;
CD.mypid=getpid();
/*Ouverture des tubes nomées*/
mkfifo(nomTube,0644);
int desc=open(nomTube,O_WRONLY);
/*Installation des handlers*/
signal(SIGUSR1,hand_reveil);
/*Construction et envoie d'une question*/
fh= fopen("outputclient1.txt","w");
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
write(desc,&CD,sizeof(CD));
/*Lecture de la réponse*/
for (int compteur = 0 ; compteur < CD.monentier ; compteur++)
{
int desc2=open(nomTube2,O_RDONLY);
read(desc2,&SD,sizeof(SD));
fh= fopen("outputclient1.txt","a");
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
/*Envoie du signal SIGUSR1au serveur*/
kill(SD.mypid,SIGUSR1);
fh= fopen("outputclient1.txt","a");
if(fh==NULL)
{
printf("error opening file");
exit(1);
}
fputs ("je me suis reveillé et j'ai recu la réponse",fh);
fclose(fh);
return 0;
}
