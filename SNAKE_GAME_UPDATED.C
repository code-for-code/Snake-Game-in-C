#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define printf cprintf
//#define gotoxy(30,15) gotoxy(3,3)
int i,j,u,e=2;
int arr[85][2];
char ch;
void ran();
void main()
{
 int level,time,food=167,head=79,body=4,limit=30;
 clrscr();
 _setcursortype(_NOCURSOR);
 textcolor(WHITE);
 textbackground(BLACK);

 printf("Chase Feed Control ***\r\n");
 printf("1.Easy\r\n2.Normal\r\n3.Hard\r\n");
 scanf("%d",&level);
      if(level==1) time=300;
 else if(level==2) time=150;
 else if(level==3) time=75;
 else
 { time=30; }
 clrscr();
 ran();

 window(30,6,52,17);
 textcolor(BLACK);
 textbackground(WHITE);
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

 arr[1][1]=11; arr[1][2]=6;                       //master
 arr[2][1]=13; arr[2][2]=6;
 arr[3][1]=15; arr[3][2]=6;
 gotoxy(arr[1][1],arr[1][2]); printf("%c",head);  //master
 gotoxy(arr[2][1],arr[2][2]); printf("%c",body);
 gotoxy(arr[3][1],arr[3][2]); printf("%c",body);

 gotoxy(i,j); printf("%c",food);				 //food

 a:                                            //left
 while(1)
 {
  clrscr();
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
   //if(ch=='a') goto a;
   //if(ch=='d') goto d;
   if(ch=='s') goto s;
   if(ch=='w') goto w;
   if(ch=='q') exit(0);
  }
  for(u=1;u<=e;u++)
  {
   gotoxy(arr[u][1],arr[u][2]);
   printf("%c",body);
  }
  if(arr[1][1]==3)
  {
   gotoxy(21,arr[1][2]);
   printf("%c",head);		  //master
  }
  else
  {
   gotoxy(arr[1][1]-2,arr[1][2]);
   printf("%c",head);		  //master
  }
  gotoxy(i,j); printf("%c",food);		      //food
  for(u=e+1;u>=2;u--)
  {
   arr[u][1]=arr[u-1][1];
   arr[u][2]=arr[u-1][2];
  }
  if(arr[1][1]==3)
   arr[1][1]=21;
  else
   arr[1][1]=arr[1][1]-2;
  for(u=2;u<=e+1;u++)
  {
   if(arr[1][1]==arr[u][1]&&arr[1][2]==arr[u][2])
    {
     gotoxy(30,15);
     printf("Game Over");
     getch();
     exit(0);
    }
  }
  if(arr[1][1]==i&&arr[1][2]==j)
  {if(e==limit) { gotoxy(30,15); printf("you WON"); getch(); exit(0); }
   e++;
   ran();
  }
  delay(time);
 }

 d:                                            //right
 while(1)
 {
  clrscr();
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
   //if(ch=='a') goto a;
   //if(ch=='d') goto d;
   if(ch=='s') goto s;
   if(ch=='w') goto w;
   if(ch=='q') exit(0);
  }
  for(u=1;u<=e;u++)
  {
   gotoxy(arr[u][1],arr[u][2]);
   printf("%c",body);
  }
  if(arr[1][1]==21)
  {
   gotoxy(3,arr[1][2]);
   printf("%c",head);		  //master
  }
  else
  {
   gotoxy(arr[1][1]+2,arr[1][2]);
   printf("%c",head);		  //master
  }
  gotoxy(i,j); printf("%c",food);		     //food
  for(u=e+1;u>=2;u--)
  {
   arr[u][1]=arr[u-1][1];
   arr[u][2]=arr[u-1][2];
  }
  if(arr[1][1]==21)
   arr[1][1]=3;
  else
   arr[1][1]=arr[1][1]+2;
  for(u=2;u<=e+1;u++)
  {
   if(arr[1][1]==arr[u][1]&&arr[1][2]==arr[u][2])
    {
     gotoxy(30,15);
     printf("Game Over");
     getch();
     exit(0);
    }
  }
  if(arr[1][1]==i&&arr[1][2]==j)
  {if(e==limit) { gotoxy(30,15); printf("you WON"); getch(); exit(0); }
   e++;
   ran();
  }
  delay(time);
 }

 s:                                            //downward
 while(1)
 {
  clrscr();
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
   if(ch=='a') goto a;
   if(ch=='d') goto d;
   //if(ch=='s') goto s;
   //if(ch=='w') goto w;
   if(ch=='q') exit(0);
  }
  for(u=1;u<=e;u++)
  {
   gotoxy(arr[u][1],arr[u][2]);
   printf("%c",body);
  }
  if(arr[1][2]==11)
  {
   gotoxy(arr[1][1],2);
   printf("%c",head);		  //master
  }
  else
  {
   gotoxy(arr[1][1],arr[1][2]+1);
   printf("%c",head);		  //master
  }
  gotoxy(i,j); printf("%c",food);		     //food
  for(u=e+1;u>=2;u--)
  {
   arr[u][1]=arr[u-1][1];
   arr[u][2]=arr[u-1][2];
  }
  if(arr[1][2]==11)
   arr[1][2]=2;
  else
   arr[1][2]=arr[1][2]+1;
  for(u=2;u<=e+1;u++)
  {
   if(arr[1][1]==arr[u][1]&&arr[1][2]==arr[u][2])
    {
     gotoxy(30,15);
     printf("Game Over");
     getch();
     exit(0);
    }
  }
  if(arr[1][1]==i&&arr[1][2]==j)
  {if(e==limit) { gotoxy(30,15); printf("you WON"); getch(); exit(0); }
   e++;
   ran();
  }
  delay(time);
 }

 w:                                            //upward
 while(1)
 {
  clrscr();
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
   if(ch=='a') goto a;
   if(ch=='d') goto d;
   //if(ch=='s') goto s;
   //if(ch=='w') goto w;
   if(ch=='q') exit(0);
  }
  for(u=1;u<=e;u++)
  {
   gotoxy(arr[u][1],arr[u][2]);
   printf("%c",body);
  }
  if(arr[1][2]==2)
  {
   gotoxy(arr[1][1],11);
   printf("%c",head);		  //master
  }
  else
  {
   gotoxy(arr[1][1],arr[1][2]-1);
   printf("%c",head);		  //master
  }
  gotoxy(i,j); printf("%c",food);		      //food
  for(u=e+1;u>=2;u--)
  {
   arr[u][1]=arr[u-1][1];
   arr[u][2]=arr[u-1][2];
  }
  if(arr[1][2]==2)
   arr[1][2]=11;
  else
   arr[1][2]=arr[1][2]-1;
  for(u=2;u<=e+1;u++)
  {
   if(arr[1][1]==arr[u][1]&&arr[1][2]==arr[u][2])
    {
     gotoxy(30,15);
     printf("Game Over");
     getch();
     exit(0);
    }
  }
  if(arr[1][1]==i&&arr[1][2]==j)
  {if(e==limit) { gotoxy(30,15); printf("you WON"); getch(); exit(0); }
   e++;
   ran();
  }
  delay(time);
 }
}
void ran()
{
 randomize();
 i=random(20); i++;
 if(i%2==0) i++;
 if(i==1) i=13;
 j=random(10); j++;
 if(j==1) j=7;
}