#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int i,j,ip,jp,u,e=0;
int arr[85][2];
char ch;
void ran();
int main()
{
 int level,time,food=167,head=111,body=4,limit=31;
 clrscr();
 _setcursortype(_NOCURSOR);
 textcolor(7+BLINK); cprintf("Game %c%c%c\r\n\n",4,4,4); textcolor(7);
 printf("1.Easy\n2.Normal\n3.Hard\n");
 level=getch();
      if(level=='1') time=300;
 else if(level=='2') time=150;
 else if(level=='3') time=75;
 else
 { time=30; }
 clrscr();
 ran();

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
   //if(ch=='a') goto a;
   //if(ch=='d') goto d;
   if(ch=='s') goto s;
   if(ch=='w') goto w;
   if(ch=='q') exit(0);
  }
  for(u=1;u<=e+2;u++)
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
  for(u=e+3;u>=2;u--)
  {
   arr[u][1]=arr[u-1][1];
   arr[u][2]=arr[u-1][2];
  }
  if(arr[1][1]==3)
   arr[1][1]=21;
  else
   arr[1][1]=arr[1][1]-2;
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
  {if(e==limit){gotoxy(30,15); printf("you won"); sleep(6);getch(); exit(0);}
   e++;
   ip=i;   jp=j;
   do
   { ran(); }while((i==ip)&&(j==jp));
  }
  delay(time);
 }

 d:                                            //right
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
   //if(ch=='a') goto a;
   //if(ch=='d') goto d;
   if(ch=='s') goto s;
   if(ch=='w') goto w;
   if(ch=='q') exit(0);
  }
  for(u=1;u<=e+2;u++)
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
  for(u=e+3;u>=2;u--)
  {
   arr[u][1]=arr[u-1][1];
   arr[u][2]=arr[u-1][2];
  }
  if(arr[1][1]==21)
   arr[1][1]=3;
  else
   arr[1][1]=arr[1][1]+2;
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
  {if(e==limit){gotoxy(30,15); printf("you won"); sleep(6);getch(); exit(0);}
   e++;
   ip=i;   jp=j;
   do
   { ran(); }while((i==ip)&&(j==jp));
  }
  delay(time);
 }

 s:                                            //downward
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
   if(ch=='a') goto a;
   if(ch=='d') goto d;
   //if(ch=='s') goto s;
   //if(ch=='w') goto w;
   if(ch=='q') exit(0);
  }
  for(u=1;u<=e+2;u++)
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
  for(u=e+3;u>=2;u--)
  {
   arr[u][1]=arr[u-1][1];
   arr[u][2]=arr[u-1][2];
  }
  if(arr[1][2]==11)
   arr[1][2]=2;
  else
   arr[1][2]=arr[1][2]+1;
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
  {if(e==limit){gotoxy(30,15); printf("you won"); sleep(6);getch(); exit(0);}
   e++;
   ip=i;   jp=j;
   do
   { ran(); }while((i==ip)&&(j==jp));
  }
  delay(time);
 }

 w:                                            //upward
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
   if(ch=='a') goto a;
   if(ch=='d') goto d;
   //if(ch=='s') goto s;
   //if(ch=='w') goto w;
   if(ch=='q') exit(0);
  }
  for(u=1;u<=e+2;u++)
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
  for(u=e+3;u>=2;u--)
  {
   arr[u][1]=arr[u-1][1];
   arr[u][2]=arr[u-1][2];
  }
  if(arr[1][2]==2)
   arr[1][2]=11;
  else
   arr[1][2]=arr[1][2]-1;
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
  {if(e==limit){gotoxy(30,15); printf("you won"); sleep(6);getch(); exit(0);}
   e++;
   ip=i;   jp=j;
   do
   { ran(); }while((i==ip)&&(j==jp));
  }
  delay(time);
 }return 0;
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
