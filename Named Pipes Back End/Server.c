#include"serv_cli_fifo.h"
#include"Handlers_Serv.h"
int main()
{
/*Declaration*/
struct ClientData CD;
struct ServerData SD;
while(1){
/*Initialisation du generateur aleatoirede nombres*/
srand(getpid());
SD.mypid=getpid();
/*Ouverture des tubes nommes*/
int desc=open(nomTube,O_RDONLY);
/*Installation des handlers*/
signal(SIGUSR1,fin_serveur);
/*Lecture d'une question*/
read(desc,&CD,sizeof(CD));
close(desc);
/*Envoie de la reponse*/
fh= fopen("outputserver1.txt","w");
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
fh= fopen("outputserver1.txt","a"); 
fputs (text4,fh);
fclose(fh);
}
fh= fopen("outputserver1.txt","a"); 
fputs ("Le client m'a avertit qu'il a recu le signal , c'est la fin de mon travail",fh);
fclose(fh);
for (int compteur = 0 ; compteur < CD.monentier ; compteur++)
{
SD.monentier = tabrandom[compteur];
printf("l'entier au hasard numero %d est %d \n",compteur,SD.monentier);
mkfifo(nomTube2,0644);
int desc2=open(nomTube2,O_WRONLY);
write(desc2,&SD,sizeof(SD));
}
/*Envoie du signal SIGUSR1 au client*/
kill(CD.mypid,SIGUSR1);
}
return 0;
}
