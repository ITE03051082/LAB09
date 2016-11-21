#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<time.h>

void doprocessing (int sock) {
int i,j,k,l,a,b;
char *message,str[4],ans[4],rec[100];


for(k=0;k<4&&(ans[k]=rand()%10+48);k++)
	for(l=0;l<k;l++)
		ans[l]==ans[k]&&k--;
printf("Ans:%s\n",ans);


while(1)
{
a=0,b=0,i=0;
bzero(str,4);
read(sock,str,4);

for(;i<4;i++)
	for(j=0;j<4;j++)
		ans[i]==str[j]&&(i==j?a++:b++);

if(a==4)
{
	message="恭喜答～～～對了！";
	write(sock,message,strlen(message)+1);
	puts("The game is over.");
	exit(1);
}
else
{
	sprintf(rec,"%dA%dB",a,b);
	write(sock,rec,strlen(rec)+1);
	a=0,b=0;
}
}


}
