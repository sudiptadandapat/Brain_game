#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#include<time.h>
#include<stdlib.h>
#include<process.h>
#include<ctype.h>
#include<string.h>

  typedef int BOOLEAN;
int mX,mY;
BOOLEAN lpress=0, rpress=0;
union REGS in,out;
int callmouse()
{
in.x.ax=1;
int86(51,&in,&out);
return 1;
}
void getstatus()
{
asm mov ax, 03h
asm int 33h
asm mov mX, cx
asm mov mY, dx
asm push bx
asm shr bx, 1
asm mov rpress, bx
asm pop bx
asm and bx, 0001h
asm mov lpress, bx
}
void posi(int &xpos, int & ypos)
{
in.x.ax=3;
int86(51,&in,&out);
xpos=out.x.cx;
ypos=out.x.dx;
}

void first()
{
int i,x,y;
for(i=0;i<500;i++)
{
x=random(590)+25;
y=random(430)+25;
int k = random(15)+1;
setcolor(k);
rectangle(x,y,x+25,y+25);
}
}
void load();
void level2();
void level1()
{
first();
delay(1000);
cleardevice();
randomize();
callmouse();
int x,y,i;int a,b,c=0;
for(i=0;i<20;i++)
{  cleardevice();
x=random(590)+25;
y=random(430)+25;
int ar[10]={x,y,x+25,y,x+25,y+25,x,y+25,x,y};
int k=random(14)+1;
setcolor(k);
setfillstyle(SOLID_FILL,k);
fillpoly(5,ar);
rectangle(x,y,x+25,y+25);
delay(1500);
getstatus();
if(lpress||rpress)
{ posi(a,b);
  if(a>=x &&a<=x+25 && b>=y && b<=y+25)
  {
  if(k==4)
  c=c+2;
  c++;
  }
}
cleardevice();
}
cleardevice();
first();
delay(1000);
cleardevice();int n;
gotoxy(35,7);
if(c>0)
c++;
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(150,20,"YOUR SCORE:");
cout<<c;
/*if(c<5)
{
outtextxy(150,150,"GAME OVER");
outtextxy(150,200,"Press any key to exit");
getch();
exit(0);
}*/
if(c>=5&&c<=10)
outtextxy(150,150,"Could Have Done Better");
else if(c>10&&c<=15)
outtextxy(150,150,"Well Done!");
else if(c>15&&c<=20)
outtextxy(150,150,"Excellent!");
outtextxy(100,200,"Press 1 to continue to next level");
outtextxy(100,250,"Press any other button to exit");
outtextxy(100,290,"YOUR CHOICE:");
gotoxy(35,21);
cin>>n;
if(n==1)
{cleardevice();
 settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
outtextxy(150,20,"LEVEL 2");
setcolor(RED);
settextstyle(SMALL_FONT,HORIZ_DIR,7);
outtextxy(0,60,"1)Random blocks of different colours will appear on the");
outtextxy(20,80,"screen .Click on as many as you can before they");
outtextxy(20,100,"disappear.");
outtextxy(0,130,"2)Do not click on the yellow blocks.A point will be ");
outtextxy(20,150,"deducted everytime you click on a yellow block");
outtextxy(0,180,"3)Red blocks have double points.");
setcolor(BLUE);
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(50,250,"PRESS 1 TO START GAME");
setcolor(CYAN);
outtextxy(0,310,"PRESS ANY OTHER KEY TO EXIT");
int n;
setcolor(WHITE);
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
outtextxy(0,360,"YOUR CHOICE :");
gotoxy(10,25);
int m;
cin>>m;
if(m==1)
{
 cleardevice();
 load();
 cleardevice();
 level2();
 }
 else
 exit(0);
}
else
exit(0);
}

void load()
{int i,k;
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(100,150,"LOADING...");
for(i=100;i<=400;i++)
{
k=random(14)+1;
setcolor(k);
rectangle(i,200,i+25,225);
delay(10);
}
}
void level3();
void level2()
{ int i,x,y,s,t,p,q,k; int xpos,ypos,n,c=0;
randomize();
callmouse();
for(i=0;i<20;i++)
{
x=random(590);
y=random(430);
s=random(590) + 25;
t=random(430)+25;
if(s>x-25&&s<x+25&&t>y-25&&t<y+25)
{
s=x+50;
t=y+50;
}
if(s>590||t>430)
{
s=x-50;
t=y-50;
}
int a[10]={s,t,s+25,t,s+25,t+25,s,t+25,s,t};
int ar[10]={x,y,x+25,y,x+25,y+25,x,y+25,x,y};
k=random(13)+1;
setcolor(14);
setfillstyle(SOLID_FILL,14);
fillpoly(5,a);
rectangle(s,t,s+25,t+25);
setcolor(k);
setfillstyle(SOLID_FILL,k);
fillpoly(5,ar);
rectangle(x,y,x+25,y+25);
delay(1500);
getstatus();
if(lpress||rpress)
{
posi(xpos,ypos);
if(xpos>=x &&xpos<=x+25 && ypos>=y && ypos<=y+25)
{
if(k==4)
c=c+2;
else
c++;
}
if(xpos>=s&& xpos<=s+25 && ypos>=t && ypos<=y+25)
c--;
}
cleardevice();
}
cleardevice();
first();
delay(1000);
cleardevice();
if(c>0)
c++;
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(150,20,"YOUR SCORE:");
gotoxy(35,7);
cout<<c;
if(c<5)
outtextxy(150,150,"Poor Performance");
if(c>=5&&c<=10)
outtextxy(150,150,"Could Have Done Better");
else if(c>10&&c<=15)
outtextxy(150,150,"Well Done!");
else if(c>15&&c<=20)
outtextxy(150,150,"Excellent!");
outtextxy(100,200,"Press 1 to continue to 3rd level");
outtextxy(100,250,"Press any other button to exit");
outtextxy(100,290,"YOUR CHOICE:");
gotoxy(35,21);
cin>>n;
if(n==1)
{
cleardevice();
settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
outtextxy(150,20,"LEVEL 3");
setcolor(RED);
settextstyle(SMALL_FONT,HORIZ_DIR,7);
outtextxy(0,60,"1)Random blocks of different colours will appear on the");
outtextxy(20,80,"screen .Click on as many as you can before they");
outtextxy(20,100,"disappear.");
outtextxy(0,130,"2)Do not click on the yellow blocks.A point will be ");
outtextxy(20,150,"deducted everytime you click on a yellow block");
outtextxy(0,180,"3)Red blocks have double points.");
setcolor(BLUE);
settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
outtextxy(50,250,"PRESS 1 TO START GAME");
setcolor(CYAN);
outtextxy(0,310,"PRESS ANY OTHER KEY TO EXIT");
setcolor(WHITE);
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
outtextxy(0,360,"YOUR CHOICE :");
gotoxy(10,25);
int m;
cin>>m;
if(m==1)
{
 cleardevice();
 load();
 cleardevice();
 level3();
 }
 else
 exit(0);
}

}
void level3()
{
int i,p,q,x,y,s,t,xpos,ypos,k,c=0;
for(i=0;i<20;i++)
{
p=random(560)+25;
q=random(430)+25;
x=random(560);
y=random(430);
s=random(560)+25;
t=random(430)+25;
if(s>x-25 && s<x+25 && t>y-25 && t<y+25)
{
s=x+50;
t=y+50;
}
if(s>590 || t>430)
{
s=x-50;
t=y-50;
}
if(p>x-25 && p<x+25 && q>y-25 && q<y+25)
{
p=x+50;
q=y+50;
}
if(s>590 || t>430)
{
p=x-50;
q=y-50;
}
int arr[10]={p,q,p+25,q,p+25,q+25,p,q+25,p,q};
int a[10]={s,t,s+25,t,s+25,t+25,s,t+25,s,t};
int ar[10]={x,y,x+25,y,x+25,y+25,x,y+25,x,y};
k=random(13)+1;
setcolor(14);
setfillstyle(SOLID_FILL,14);
fillpoly(5,a);
rectangle(s,t,s+25,t+25);
setcolor(k);
setfillstyle(SOLID_FILL,k);
fillpoly(5,ar);
rectangle(x,y,x+25,y+25);
setcolor(14);
setfillstyle(SOLID_FILL,14);
fillpoly(5,arr);
rectangle(p,q,p+25,q+25);
int xpos,ypos;
delay(1500);
getstatus();
if(lpress||rpress)
{
posi(xpos,ypos);
if(xpos>=x &&xpos<=x+25 && ypos>=y && ypos<=y+25)
{
if(k==4)
c=c+2;
else
c++;
}
if(xpos>=s&& xpos<=s+25 && ypos>=t && ypos<=y+25)
c--;
if(xpos>=p&& xpos<=p+25 && ypos>=q && ypos<=q+25)
c--;
}
cleardevice();
}
first();
delay(1000);
cleardevice();
if(c>0)
c++;
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(150,20,"YOUR SCORE:");
gotoxy(35,7);
cout<<c;
if(c<5)
outtextxy(150,150,"Poor Performance");
if(c>=5&&c<=10)
outtextxy(150,150,"Could Have Done Better");
else if(c>10&&c<=15)
outtextxy(150,150,"Well Done!");
else if(c>15&&c<=20)
outtextxy(150,150,"Excellent!");

}


void blockbuster()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");
setcolor(MAGENTA);
int i;
for( i=0; i<=639;i++)
{
setcolor(random(14)+1);
settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
outtextxy(i,200,"BLOCKBUSTER");
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
outtextxy(i+350,190,"TM");
delay(12);
cleardevice();
}
settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
outtextxy(150,20,"HOW TO PLAY");
setcolor(RED);
settextstyle(SMALL_FONT,HORIZ_DIR,7);
outtextxy(0,60,"1)Random blocks will appear on the screen and you have");
outtextxy(20,80,"to click on as many as you can before they disappear.");
outtextxy(0,110,"2)Only double clicking on blocks will get you points.");
outtextxy(0,140,"3)Red blocks have double points.");

setcolor(BLUE);
settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
outtextxy(50,250,"PRESS 1 TO START GAME");
setcolor(CYAN);
outtextxy(50,310,"PRESS 2 TO EXIT GAME");
int n;
setcolor(WHITE);
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
outtextxy(0,360,"YOUR CHOICE :");
for( i=0;i<24;i++)
cout<<"\n";
cin>>n;
switch(n)
{
case 1:
{
cleardevice();
level1();
break;
}
case 2:
exit(0);
}
getch();
 }





void intro()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");
setcolor(WHITE);

settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
outtextxy(200,100,"C O W S");
outtextxy(200,200," A N D");
outtextxy(200,300,"B U L L S");
delay(4000);
cleardevice();
 setcolor(YELLOW);

settextstyle(DEFAULT_FONT,HORIZ_DIR,2);

outtextxy(10,30,"BRUSH UP YOUR CODE BREAKING SKILLS!");
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
setcolor(BLUE);
outtextxy(0,70,"THE AIM IS TO GUESS A FOUR LETTER SECRET WORD");
outtextxy(0,90,"AND YOU GET A MAXIMUM OF TEN TRIES");
outtextxy(0,110,"BEGIN BY ENTERING A RANDOM WORD");
outtextxy(0,130,"(WITH NO REPEATING CHARACTERS)");
outtextxy(0,150,"AND THE SYSTEM WILL GENERATE HINTS:");
setcolor(YELLOW);
outtextxy(0,170,"THE NUMBER OF COWS GENERATED REPRESENTS:");
outtextxy(0,190,"CHARACTERS IN COMMON WITH THE SECRET WORD BUT IN WRONG POSITIONS ");
outtextxy(0,210,"AND THE NUMBER OF BULLS GENERATED REPRESENTS:");
outtextxy(0,230,"CHARACTERS IN THE WORD COMMON WITH THE SECRET WORD");
outtextxy(0,250," AND ALSO PRESENT IN CORRECT POSITIONS");
setcolor(BLUE);
outtextxy(0,270,"MAKE CALCULATED GUESSES SO ON ");
outtextxy(0,290,"BASED ON PREVIOUS HINTS");
outtextxy(0,310,"AND GET TO 4 BULLS IN MINIMUM TRIES!");
setcolor(YELLOW);
outtextxy(0,340,"PRESS 1 TO START AND ANYTHING ELSE TO EXIT");
for(int i=0;i<=25;i++)
cout<<endl;
int n;
cout<<"your choice:"<<endl;
cin>>n;
if(n!=1)
exit(0);
cleardevice();
closegraph();
  }

void cow()
{ clrscr();
intro();

  int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");
///array for storing words from text file////
char fname[50];

///variables for maintaining the count of words from file////
int numRecords = 0, repeat = 1;

///array for storing words from user////
char uname[50];

////defining pointer fptr for read/write data for data.txt//////
FILE *fptr;
char *name;

////if the text file is empty///
if ((fptr = fopen("data.txt","r")) == NULL) {
	printf("Error: Loading the file\n");
	exit(1);
}

//////counting how many words are there in the file and then store it in the numRecords\\\\
while(1) {
	if(fscanf(fptr,"%s ",&fname) == EOF)
		break;
	numRecords++;
}

rewind(fptr);



int ch=1;

//////extracting words from file one by one///
while ((repeat <= numRecords) && (ch==1)) {
setcolor(RED);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(30,50,"START GUESSING!");
cout<<endl;cout<<endl;
printf("You are playing for the word< %d > of the file \n",repeat);
	fscanf(fptr, "%s ", &fname);

////your 10 tries start from here////
for(int a=1;a<=10;a++)
{
//Entering guessing words

printf("\nTry:  %d ",a);cout<<endl;
cout<<"ENTER A WORD";
cout<<endl;

////storing the word entered by the user in uname array////
for(int x=0;x<4;x++)
cin>>uname[x] ;
cout<<endl;
for(int y=0;y<4;y++)
printf("  %c  ",uname[y]);
for(int i=0;i<=2;i++)
cout<<endl;
////calculating the number of matching letters by position////
int c=0,b=0;
for(int z=0;z<4;z++)
{  for(int j=0;j<4;j++)
{
   if(fname[z]==uname[j])

      c++; }
      if(fname[z]==uname[z])
      b++;

}

////printing no. of matches
cout<<b<<" BULLS  AND "<<c-b<<"  COWS";
for(int q=0;q<=4;q++)
cout<<endl;

//////if your guess is right/////
if(b==4)
{
printf("Your guess is right!!!");
cout<<endl<<endl;
break;

}

}
/////tries are over////
printf("Game over!!!  \n  Right word is:\n");
for(int k=0;k<4;k++)
printf("  %c",fname[k]);

   cout<<endl;
	repeat++;

printf("\n\nDo you want to play for the next word of file?   \n  1.Yes \n 2.No");
scanf("%d",&ch);
	}
 closegraph();


}





void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");
setcolor(YELLOW);
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(0,150,"TECHNOLOGY INNOVATION COMPETITION 2018");
setcolor(BLUE);

settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
outtextxy(0,250,"JALPAIGURI GOVERNMENT ENGINEERING COLLEGE");

delay(4000);
  cleardevice();
setcolor(YELLOW);
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
  outtextxy(100,100,"LETS START:PICK A GAME");
  setcolor(RED);
  outtextxy(0,200,"TYPE B FOR BLOCK_BUSTER");
  outtextxy(0,300,"TYPE C FOR COWS AND BULLS");

  for(int s=0;s<=27;s++)
  cout<<endl;cout<<"your choice:"<<endl;
  char w; cin>>w;
  if(w=='C')
  {
    cow();}
    if(w=='B')
    { blockbuster();}
    cleardevice();
    outtextxy(0,200,"THANKS FOR PLAYING!");
setcolor(MAGENTA);
outtextxy(50,250,"Made by :");
outtextxy(100,290,"MANIKA DALELA");
delay(5000);
  cleardevice();
  closegraph();
  getch();
  }