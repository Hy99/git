/*
����汾û��AI��ֻ�����˽�����Ϸ�� 
����˫���ĵ����ǿɼ��ģ���Ҫ���мҿ��Կ���ׯ�ҵĵ�����
���ֲ��ܲ������������Ȼû���������� 
���������ֻ���뵽 ��ׯ�Һ��мҽ���Ľڵ����һ��"\n"
��Ҳ����ô���ġ� 
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void xipai(int poker[]);
void fapai(int *i,int *point,char order,int poker[]) ;
void line(void);
int main(void)
{
	//��Ϸ��������˵��
	line();//���40��"*"�ķָ��� 
	printf("\t 21�����϶ĳ� \n");
	printf("\t ��������   \n");
	printf("\ty��Ϊ����\n  \tn��Ϊȡ������\n");
	printf("\n\t  ���ڣ���Ϸ��ʼ\n");
	line();
	
	//����һ���˿˲���ʼ�� 
	int poker[52];
	int i,x,a;
	for(i=0;i<10;i++)
	{
		poker[4*i]=poker[4*i+1]=poker[4*i+2]=poker[4*i+3]=i+1;
	}
	for(x=40;x<52;x++)
	{poker[x]=10;}
	
	//�˴���һ��ϴ�ƺ���
	printf("\t��ʼϴ�ƣ�\n");
	xipai(poker);
	line();
	
	//��ʼ����
	int pz,px;//ׯ���мҵĵ���
	
	pz=poker[1];
	px=poker[2];/*�������Ʊ�Ȼ���ᱬ�ƣ�
	���Ե�һ��ֱ�ӷ�����û��ѯ�ʵı�Ҫ��
	��һ�������﷢���ڶ����ڷ��ƺ����﷢��*/ 
	
	int iz,ix;//���Ƽ���
	char orderz,orderx;//�����¼ 
	
	printf("\t���ڸ�ׯ�ҷ��ơ�\n");
	iz=2;//�÷��������� 
	fapai(&iz,&pz,orderz,poker);
	line();
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	
	printf("\t���ڸ��мҷ��ơ�\n");
	ix=iz;
	fapai(&ix,&px,orderx,poker);
	line();
	
	printf("\t��ʼ����\n");
	line(); 
	//����
	printf("\t");
	printf("��Ϸ������\n\tׯ�ҵĵ�����%d���мҵĵ�����%d��",pz,px);
	if(pz>21) 
	{   if(px>21)
		{printf("ׯ��Ӯ��");}
		else
		{printf("�м�Ӯ��");} 
	}
	else{
		if(px>21)
		{printf("ׯ��Ӯ��");}
		else
		{	if(px>pz)
			{printf("�м�Ӯ��");}
			else
			{printf("ׯ��Ӯ");} 
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
	printf("\t�Ƿ��ٴ�Ҫ�ƣ�,������ĵ�����%d\n",*point);
	scanf("\t%c",&order);
	*i=*i+1;
	while(order=='y')//��������Ϊʲôû��do while����Ϊ����do while��ʱ�����Ǳ��������ڴ�����ǰ��Ӷ��� 
	{
		*point=*point+poker[*i];
		printf("\t�Ƿ��ٴ�Ҫ�ƣ�,������ĵ�����%d\n",*point);
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
