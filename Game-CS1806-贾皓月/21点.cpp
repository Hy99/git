/*
这个版本没有AI，只能两人进行游戏。 
而且双方的点数是可见的，主要是闲家可以看到庄家的点数。
我又不能不输出点数，不然没法作出抉择 
解决方法我只能想到 在庄家和闲家交替的节点输出一串"\n"
我也是这么做的。 
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void xipai(int poker[]);
void fapai(int *i,int *point,char order,int poker[]) ;
void line(void);
int main(void)
{
	//游戏基础操作说明
	line();//输出40个"*"的分割线 
	printf("\t 21点线上赌场 \n");
	printf("\t 基础操作   \n");
	printf("\ty键为跟牌\n  \tn键为取消跟牌\n");
	printf("\n\t  现在，游戏开始\n");
	line();
	
	//创建一副扑克并初始化 
	int poker[52];
	int i,x,a;
	for(i=0;i<10;i++)
	{
		poker[4*i]=poker[4*i+1]=poker[4*i+2]=poker[4*i+3]=i+1;
	}
	for(x=40;x<52;x++)
	{poker[x]=10;}
	
	//此处有一个洗牌函数
	printf("\t开始洗牌！\n");
	xipai(poker);
	line();
	
	//开始发牌
	int pz,px;//庄家闲家的点数
	
	pz=poker[1];
	px=poker[2];/*发两张牌必然不会爆牌，
	所以第一轮直接发两张没有询问的必要。
	第一张在这里发，第二张在发牌函数里发。*/ 
	
	int iz,ix;//发牌计数
	char orderz,orderx;//输入记录 
	
	printf("\t现在给庄家发牌。\n");
	iz=2;//该发第三张牌 
	fapai(&iz,&pz,orderz,poker);
	line();
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	
	printf("\t现在给闲家发牌。\n");
	ix=iz;
	fapai(&ix,&px,orderx,poker);
	line();
	
	printf("\t开始结算\n");
	line(); 
	//结算
	printf("\t");
	printf("游戏结束！\n\t庄家的点数是%d，闲家的点数是%d：",pz,px);
	if(pz>21) 
	{   if(px>21)
		{printf("庄家赢！");}
		else
		{printf("闲家赢！");} 
	}
	else{
		if(px>21)
		{printf("庄家赢！");}
		else
		{	if(px>pz)
			{printf("闲家赢！");}
			else
			{printf("庄家赢");} 
		}
	}
	printf("\n");
	line();
	getchar();
	getchar(); 
	
	return 0;
}

void xipai(int poker[])
{
	int i,r,temp;
	srand(time(NULL));
	for(i=0;i<52;i++)
    {
        r=(rand()%(52-i))+i;
        temp=poker[i];
        poker[i]=poker[r];
        poker[r]=temp;
    }
}

void fapai(int *i,int *point,char order,int poker[])
{
	*point=*point+poker[*i];
	printf("\t是否再次要牌？,现在你的点数是%d\n",*point);
	scanf("\t%c",&order);
	*i=*i+1;
	while(order=='y')//关于这里为什么没用do while，因为我用do while的时候总是报错，让我在大括号前面加东西 
	{
		*point=*point+poker[*i];
		printf("\t是否再次要牌？,现在你的点数是%d\n",*point);
		scanf("\t%c",&order);
		*i=*i+1;
	}
}
void line(void)
{
	printf("\n\t");
	int i;
	for(i=1;i<=40;i++)
	{
		printf("*");
	}
	printf("\n\n");
}
