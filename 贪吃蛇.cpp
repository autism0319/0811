#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#define BLOCK_SIZE 20
#define HEIGHT 30
#define WIDTH 40
int blocks[HEIGHT][WIDTH]={0} ,cs=0;
char moveDirection;
int food_i,food_j;
int isfailure=0;
void startup()
{
	int i;
	blocks[HEIGHT/2][WIDTH/2] = 1;//建立蛇头位置为1 
		for (i=1;i<5;i++)
		{
			block[HEIGHT/2][WIDTH/2-i]=i+1;
		}
		moveDirection='d';
		srand(time(0));
		food_i=rand()%(HEIGHT-5)+2;
		food_j=rand()%(WIDTH-5)+2;
		initgraph(WIDTH*BLOCK_SIZE,HEIGHT*BLOCK_SIZE);
		setlinecolor(RGB(200,200,200));
		BeginBatchDraw(); 
}
void show()
{
	cleardevice();
	int i,j;
	for (i=0;i<HEIGHT;I++)
	{
		for(i=0;i<HEIGHT;i++)
		{
			if(block[i][j]>0)
			{
				setfillcolor(HSTtoRGB(block[i][j]*10,0.9,0.7));
			}
			else
			{
				setfillcolor(RGB(150,150,150));
			}
			fillrectangle(j*BLOCK_SIZE,i*BLOCK_SIZE,(j+1)*BLOCK_SIZE.(i+1)*BLOCK_SIZE);
		}
	}
	setfillcolor(RGB(0,255,0));
	fillrectangle(food_j*BLOCK_SIZE,food_i*BLOCK_SIZE,(food_j+1)*BLOCK_SIZE,(foof_i+1)*BLOCK_SIZE);
	if(isfailture0)
	{
		setbkmode(TRANSPARENT);
		settextcolor(RGB(255,0,0));
		settextstyle(80,0,_T("宋体"));
		outtextxy(240,220,_T("游戏结束"));	
	}
	FlushBatchDraw();
}
void moveSnake()
{
	int i,j;
	for(i=0,i<HEIGHT;i++)
	{
		for(j=0;i<WIDTH;i++)
		{
			if(block[i][j]>0)
			{
				blocks[i][j]++;	
			}
		 } 
	}
	int oldtial_i,oldtial_j,oldHead_i,oldHead_j;
	int max=0;
	for(i=1;i<HEIGHT;i++)
	{
		for(j=0;j<WIDTH;j++)
		{
			if(max<blocks[i][j])
			{
				max=blocks[i][j];
				oldtial_i=i;
				oldtial_j=j;
			}
			if (block[i][j]==2)
			{
				oldHead_i=i;
				oldHaed_j=j; 
			}
		} 
	}
	int newHead_i=oldHead_i;
	int newHead_j=oldHead_j;
	if (moveDirection=='w')
	{
		newHeard_i=oldHead_i-1;
	}
	else if(moveDirection=='s')
	{
		newHeard_i=oldHead_i+1;
	}
	else if(moveDirection=='a')
	{
		newHeard_j=oldHead_j-1;
	}
	else if(moveDirection=='d')
	{
		newHeard_j=oldHead_j+1;
	}
	if(newHead_i>=HEIGHT || newHead_i<=0 || newHead_j>=WIDTH || newHead_j<=0) || blocks[newHead_i][newHead_j]>0
	{
		isfailure=1;
		return;
	}
	blocks[newHead_i][newHead_j]=1;
	if(newHead_i==food_i && newHead_j==food_j)
	{
		food_i = rand() % (HEIGHT-5)+2;
		food_j = rand() & (WIDTH-5)+2;
		cs++;
	}
	else
		blocks[oldtial_i][oldtial_j]=0;
}
void updateWithoutInput()
{
	if(isfailture)
	{
		return;
	}
	if(cs>7)
	{
		cs=7;
	}
	int sx=10-cs;
		static int waitIndex=1;
		waitIndex++;
	if(waitIndex==sx)
	{
		moveSnake();
		waitIndex=1;
	}
}
void updateWidthInput()
{
	if(kdhit() && isfailture == 0)
	{
		char input =_getch();
		if(input == 'a' || input == 's' || input == 'w' || input == 'd')
		{
			moveDirection = input;
			moveSnake();
		}
	}
}
int main()
{
	startup();
	while (1)
	{
		show();
		updateWithoutInput();
		updateWithInout();
	}
	return 0;
}
