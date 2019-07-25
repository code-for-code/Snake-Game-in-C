#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int i,j,ip,jp,u,e=0;
int level,t,food=167,head=111,body=4,limit=31;
int arr[85][2];
char ch;
void step(int f1, int f2, int fx, int fy, char s);
void ran();

void main()
{
 clrscr();
 _setcursortype(_NOCURSOR);
 textcolor(7+BLINK); cprintf("Game %c%c%c\r\n\n",4,4,4); textcolor(7);
 printf("1.Easy\n2.Normal\n3.Hard\n");
 level=getch();
      if(level=='1') t=300;
 else if(level=='2') t=150;
 else if(level=='3') t=75;
 else
 { t=30; }
 ran();
 arr[1][1]=11; arr[1][2]=6;                       //master
 arr[2][1]=13; arr[2][2]=6;
 arr[3][1]=15; arr[3][2]=6;
 step(3,21,-2,0,'l');
}

void step(int f1, int f2, int fx, int fy, char s)
{
 while(1)
 {
  clrscr();   gotoxy(30,6);   printf("Points = %d",e);
  gotoxy(2,1);
  for(u=2;u<=22;u++)
   printf("%c",196);
  for(u=2;u<=11;u++)
  {
   gotoxy(1,u);  printf("%c",179);
   gotoxy(23,u); printf("%c",179);
  }
  gotoxy(2,12);
  for(u=2;u<=22;u++)
   printf("%c",196);
  if(kbhit()!=0)
  {
   ch=getch();
   if(ch=='q') exit(0);
   if(s=='d'||s=='u')
   {
    if(ch=='a') step(3,21,-2,0,'l');       //left
    if(ch=='d') step(21,3,+2,0,'r');       //right
   }
   if(s=='l'||s=='r')
   {
    if(ch=='s') step(11,2,0,+1,'d');       //downward
    if(ch=='w') step(2,11,0,-1,'u');       //upward
   }
  }
  for(u=1;u<=e+2;u++)
  {
   gotoxy(arr[u][1],arr[u][2]);
   printf("%c",body);
  }
  if(s=='l'||s=='r')
  {
   if(arr[1][1]==f1)
   {
    gotoxy(f2,arr[1][2]);
    printf("%c",head);		  //master
   }
   else
   {
    gotoxy(arr[1][1]+fx,arr[1][2]);
    printf("%c",head);		  //master
   }
  }
  if(s=='d'||s=='u')
  {
   if(arr[1][2]==f1)
   {
    gotoxy(arr[1][1],f2);
    printf("%c",head);		  //master
   }
   else
   {
    gotoxy(arr[1][1],arr[1][2]+fy);
    printf("%c",head);		  //master
   }
  }
  gotoxy(i,j); printf("%c",food);		      //food
  for(u=e+3;u>=2;u--)
  {
   arr[u][1]=arr[u-1][1];
   arr[u][2]=arr[u-1][2];
  }
  if(s=='l'||s=='r')
  {
   if(arr[1][1]==f1)
    arr[1][1]=f2;
   else
    arr[1][1]=arr[1][1]+fx;
  }
  if(s=='d'||s=='u')
  {
   if(arr[1][2]==f1)
    arr[1][2]=f2;
   else
    arr[1][2]=arr[1][2]+fy;
  }
  for(u=2;u<=e+3;u++)
  {
   if(arr[1][1]==arr[u][1]&&arr[1][2]==arr[u][2])
    {
     gotoxy(30,15);
     printf("Game Over");
     sleep(3); getch();
     exit(0);
    }
  }
  if(arr[1][1]==i&&arr[1][2]==j)
  {
   if(e==limit)
   {
    gotoxy(30,15);
    printf("you won");
    sleep(6); getch();
    exit(0);
   }
   e++;
   ip=i;
   jp=j;
   do
   { ran(); }while((i==ip)&&(j==jp));
  }
  delay(t);
 }
}

void ran()
{
 //randomize();
 i=random(20); i++;
 if(i%2==0) i++;
 if(i==1) i=13;
 j=random(10); j++;
 if(j==1) j=7;
}