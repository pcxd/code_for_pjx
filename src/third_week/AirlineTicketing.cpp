#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<iostream>
#define MAXSIZE 5
typedef struct wat_ros
{
char name[10];
int req_amt;
struct wat_ros*next;
}
qnode,*qptr;
typedef struct pqueue
{
	qptr front;
	qptr rear;
}linkqueue;
typedef struct ord_ros
{
	char name[10];
	int ord_amt;
	int grade;
struct ord_ros*next;
}linklist;
struct airline
{
	char ter_name[10];
	char air_num[10];
	char time[10];
char pri[7];
int tkt_amt;
int tkt_sur;
linklist *order;
linkqueue wait;
}lineinfo;
struct airline *start;



void display(struct airline *info)
{
	printf("%8s\t%3s\t%s\t\t%4s\t%3d\t%10d\n",info->ter_name,info->air_num,info->time,
info->pri,info->tkt_amt,info->tkt_sur);
}


void list()                             //output list
{
	struct airline*info;
	int i=0;
	info=start;
printf("终点站名\t航班号\t飞行时间\t票价\t乘员定额\t余票量\n");
while(i<MAXSIZE)
{
display(info);
info++;
i++;
}
printf("\n\n");
}



void search()
{
	struct airline*info,*find();
char name[10];
int i=0;
info=start;
printf("请输入要抵达城市的名称:");
scanf("%s",name);
while(i<MAXSIZE)
{
	if(!strcmp(name,info->ter_name))
	{
		break;
	}
	info++;
	i++;
}
if(i>=MAXSIZE)
{
	printf("对不起，没有这条航线!\n");
}
else
{
	printf("终点站名\t航班号\t飞行时间\t票价\t乘员定额\t余票量\n");
	display(info);
}
}
struct airline *find()
{
	struct airline *info;
    char number[10];
    int i=0;
    info=start;
    printf("请输入航班号:");
    scanf("%s",number);
    while(i<MAXSIZE)
{
	if(!strcmp(number,info->air_num))
	{
return info;
}
	info++;
i++;
}
printf("对不起，没有这条航线!\n");
return NULL;
}
void prtlink()
{
	linklist *p;
	struct airline *info;
	info=find();
	p=info->order;
if(p!=NULL)
{
	printf("客户姓名??订票数额??舱位等级\n");
	while(p)
	{
		printf("%s\t\t%d\t%d\n",p->name,p->ord_amt,p->grade);
		p=p->next;
}
}
else
printf("该航线没有客户信息!\n");
}
linklist *insertlink(linklist *head,int amount,char name[],int grade)
{
	linklist *p1,*new1;
	p1=head;
new1=(linklist*)malloc(sizeof(linklist));
if(!new1)
{
printf("\nOut of memory!!\n");
return NULL;
}
strcpy(new1->name,name);
new1->ord_amt=amount;
new1->grade=grade;
new1->next=NULL;
if(head==NULL)
{
	head=new1;
	new1->next=NULL;
}
else
{
head=new1;
}
new1->next=p1;
return head;
}
linkqueue appendqueue(linkqueue q,char name[],int amount)
{
qptr new1;
new1=(qptr)malloc(sizeof(qnode));
strcpy(new1->name,name);
new1->req_amt=amount;
new1->next=NULL;
if(q.front==NULL)
{
	q.front=new1;
}
else
{
q.rear->next=new1;
}
q.rear=new1;
return q;
}
void order()
{
	struct airline *info;
int amount,grade;
char name[10];
info=start;
if(!(info=find()))
{
	return;
}
printf("请输入您需要的票数:");
scanf("%d",&amount);
if(amount>info->tkt_amt)
{
	printf("\n对不起，您输入票数已经超过乘员定额!");
	return;
}
if(amount<=info->tkt_sur)
{
	int i;
printf("请输入您的姓名:");
scanf("%s",name);
printf("请输入您需要的舱位等级(1,2或):");
scanf("%d",&grade);
info->order=insertlink(info->order,amount,name,grade);
for(i=0;i<amount;i++)
{
printf("%s的座位号是:%d\n",name,info->tkt_amt-info->tkt_sur+i+1);
}
info->tkt_sur-=amount;
printf("\n祝您乘坐愉快!\n");
}
else
{
	char r;
printf("\n没有这么多票了，您需要排队等候吗?(Y/N)");
r=getch();
printf("%c",r);
if(r=='Y'||r=='y')
{
printf("\n请输入您的姓名:");
scanf("%s",name);
info->wait=appendqueue(info->wait,name,amount);
printf("\n注册排队成功!\n");
}
else
{
	printf("\n欢迎您再次订购！\n");
}
}
}
void return_tkt()
{
	struct airline *info;
	qnode *t,*back,*f,*r;
	int grade;
linklist *p1,*p2,*head;
char cusname[10];
if(!(info=find()))
{
return;
}
head=info->order;
p1=head;
printf("请输入你的姓名:");
scanf("%s",cusname);
while(p1!=NULL)
{
	if(!strcmp(cusname,p1->name))
	{
		break;
}
	p2=p1;
	p1=p1->next;
}
if(p1==NULL)
{
	printf("对不起，您没有订过票!\n");
	return;
}
else
{
	if(p1==head)
	{
		head=p1->next;
}
	else
{
p2->next=p1->next;
	}
info->tkt_sur+=p1->ord_amt;
grade=p1->grade;
printf("%s退票成功!\n",p1->name);
free(p1);
}

info->order=head;
f=(info->wait).front;
r=(info->wait).rear;
t=f;
while(t)
{
	if(info->tkt_sur>=info->wait.front->req_amt)
	{
	int i;
info->wait.front=t->next;
printf("%s订票成功!\n",t->name);
for(i=0;i<t->req_amt;i++)
{
	printf("%s的座位号是:%d\n",t->name,(info->tkt_sur)-i);
}
info->tkt_sur-=t->req_amt;
info->order=insertlink(info->order,t->req_amt,t->name,grade);
free(t);
break;
}
	back=t;
		t=t->next;
if((info->tkt_sur)>=(t->req_amt)&&t!=NULL)
{
int i;
back->next=t->next;
printf("%s订票成功!\n",t->name);
for(i=0;i<t->req_amt;i++)
{
	printf("<%s>'s seat number is:%d\n",t->name,(info->tkt_sur)-i);
}
info->tkt_sur-=t->req_amt;
info->order=insertlink(info->order,t->req_amt,t->name,grade);
free(t);break;
}
if(f==r)
{
	break;
}
}
}
int menu_select()
{
int c;
char s[20];
printf("\t订票系统\n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("1.查看航线信息\n");
printf("2.查看已订票客户信息\n");
printf("3.查询航线\n");
printf("4.办理订票业务\n");
printf("5.办理退票业务\n");
printf("6.退出系统\n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
do
{
printf("请选择(1-6):");
scanf("%s",s);
c=atoi(s);
}
while(c<1||c>6);
return c;
}


int main()
{
	struct airline air[MAXSIZE]=
	{
    {"beijing","1","1200","860",30,30,},
    {"shanghai","2","1000","770",20,20,},
    {"london","3","1330","960",10,10,},
    {"harbin","4","1700","760",50,50,},
    {"dalian","5","1400","550",40,40,}
    };
    start=air;
    for(;;)
    {
    system("cls");
    switch(menu_select())
    {
    case 1:list();
		   break;
    case 2:prtlink();
		   break;
    case 3:search();
		   break;
    case 4:order();
		   break;
    case 5:return_tkt();
    break;
    case 6:printf("\n感谢您的使用,再见!\n");
    exit(0);
    }
    printf("\n任意键继续...\n");
    getch();
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<iostream>
#define MAXSIZE 5
typedef struct wat_ros
{
char name[10];
int req_amt;
struct wat_ros*next;
}
qnode,*qptr;
typedef struct pqueue
{
	qptr front;
	qptr rear;
}linkqueue;
typedef struct ord_ros
{
	char name[10];
	int ord_amt;
	int grade;
struct ord_ros*next;
}linklist;
struct airline
{
	char ter_name[10];
	char air_num[10];
	char time[10];
char pri[7];
int tkt_amt;
int tkt_sur;
linklist *order;
linkqueue wait;
}lineinfo;
struct airline *start;



void display(struct airline *info)
{
	printf("%8s\t%3s\t%s\t\t%4s\t%3d\t%10d\n",info->ter_name,info->air_num,info->time,
info->pri,info->tkt_amt,info->tkt_sur);
}


void list()                             //output list
{
	struct airline*info;
	int i=0;
	info=start;
printf("终点站名\t航班号\t飞行时间\t票价\t乘员定额\t余票量\n");
while(i<MAXSIZE)
{
display(info);
info++;
i++;
}
printf("\n\n");
}



void search()
{
	struct airline*info,*find();
char name[10];
int i=0;
info=start;
printf("请输入要抵达城市的名称:");
scanf("%s",name);
while(i<MAXSIZE)
{
	if(!strcmp(name,info->ter_name))
	{
		break;
	}
	info++;
	i++;
}
if(i>=MAXSIZE)
{
	printf("对不起，没有这条航线!\n");
}
else
{
	printf("终点站名\t航班号\t飞行时间\t票价\t乘员定额\t余票量\n");
	display(info);
}
}
struct airline *find()
{
	struct airline *info;
    char number[10];
    int i=0;
    info=start;
    printf("请输入航班号:");
    scanf("%s",number);
    while(i<MAXSIZE)
{
	if(!strcmp(number,info->air_num))
	{
return info;
}
	info++;
i++;
}
printf("对不起，没有这条航线!\n");
return NULL;
}
void prtlink()
{
	linklist *p;
	struct airline *info;
	info=find();
	p=info->order;
if(p!=NULL)
{
	printf("客户姓名??订票数额??舱位等级\n");
	while(p)
	{
		printf("%s\t\t%d\t%d\n",p->name,p->ord_amt,p->grade);
		p=p->next;
}
}
else
printf("该航线没有客户信息!\n");
}
linklist *insertlink(linklist *head,int amount,char name[],int grade)
{
	linklist *p1,*new1;
	p1=head;
new1=(linklist*)malloc(sizeof(linklist));
if(!new1)
{
printf("\nOut of memory!!\n");
return NULL;
}
strcpy(new1->name,name);
new1->ord_amt=amount;
new1->grade=grade;
new1->next=NULL;
if(head==NULL)
{
	head=new1;
	new1->next=NULL;
}
else
{
head=new1;
}
new1->next=p1;
return head;
}
linkqueue appendqueue(linkqueue q,char name[],int amount)
{
qptr new1;
new1=(qptr)malloc(sizeof(qnode));
strcpy(new1->name,name);
new1->req_amt=amount;
new1->next=NULL;
if(q.front==NULL)
{
	q.front=new1;
}
else
{
q.rear->next=new1;
}
q.rear=new1;
return q;
}
void order()
{
	struct airline *info;
int amount,grade;
char name[10];
info=start;
if(!(info=find()))
{
	return;
}
printf("请输入您需要的票数:");
scanf("%d",&amount);
if(amount>info->tkt_amt)
{
	printf("\n对不起，您输入票数已经超过乘员定额!");
	return;
}
if(amount<=info->tkt_sur)
{
	int i;
printf("请输入您的姓名:");
scanf("%s",name);
printf("请输入您需要的舱位等级(1,2或):");
scanf("%d",&grade);
info->order=insertlink(info->order,amount,name,grade);
for(i=0;i<amount;i++)
{
printf("%s的座位号是:%d\n",name,info->tkt_amt-info->tkt_sur+i+1);
}
info->tkt_sur-=amount;
printf("\n祝您乘坐愉快!\n");
}
else
{
	char r;
printf("\n没有这么多票了，您需要排队等候吗?(Y/N)");
r=getch();
printf("%c",r);
if(r=='Y'||r=='y')
{
printf("\n请输入您的姓名:");
scanf("%s",name);
info->wait=appendqueue(info->wait,name,amount);
printf("\n注册排队成功!\n");
}
else
{
	printf("\n欢迎您再次订购！\n");
}
}
}
void return_tkt()
{
	struct airline *info;
	qnode *t,*back,*f,*r;
	int grade;
linklist *p1,*p2,*head;
char cusname[10];
if(!(info=find()))
{
return;
}
head=info->order;
p1=head;
printf("请输入你的姓名:");
scanf("%s",cusname);
while(p1!=NULL)
{
	if(!strcmp(cusname,p1->name))
	{
		break;
}
	p2=p1;
	p1=p1->next;
}
if(p1==NULL)
{
	printf("对不起，您没有订过票!\n");
	return;
}
else
{
	if(p1==head)
	{
		head=p1->next;
}
	else
{
p2->next=p1->next;
	}
info->tkt_sur+=p1->ord_amt;
grade=p1->grade;
printf("%s退票成功!\n",p1->name);
free(p1);
}

info->order=head;
f=(info->wait).front;
r=(info->wait).rear;
t=f;
while(t)
{
	if(info->tkt_sur>=info->wait.front->req_amt)
	{
	int i;
info->wait.front=t->next;
printf("%s订票成功!\n",t->name);
for(i=0;i<t->req_amt;i++)
{
	printf("%s的座位号是:%d\n",t->name,(info->tkt_sur)-i);
}
info->tkt_sur-=t->req_amt;
info->order=insertlink(info->order,t->req_amt,t->name,grade);
free(t);
break;
}
	back=t;
		t=t->next;
if((info->tkt_sur)>=(t->req_amt)&&t!=NULL)
{
int i;
back->next=t->next;
printf("%s订票成功!\n",t->name);
for(i=0;i<t->req_amt;i++)
{
	printf("<%s>'s seat number is:%d\n",t->name,(info->tkt_sur)-i);
}
info->tkt_sur-=t->req_amt;
info->order=insertlink(info->order,t->req_amt,t->name,grade);
free(t);break;
}
if(f==r)
{
	break;
}
}
}
int menu_select()
{
int c;
char s[20];
printf("\t订票系统\n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("1.查看航线信息\n");
printf("2.查看已订票客户信息\n");
printf("3.查询航线\n");
printf("4.办理订票业务\n");
printf("5.办理退票业务\n");
printf("6.退出系统\n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
do
{
printf("请选择(1-6):");
scanf("%s",s);
c=atoi(s);
}
while(c<1||c>6);
return c;
}


int main()
{
	struct airline air[MAXSIZE]=
	{
    {"beijing","1","1200","860",30,30,},
    {"shanghai","2","1000","770",20,20,},
    {"london","3","1330","960",10,10,},
    {"harbin","4","1700","760",50,50,},
    {"dalian","5","1400","550",40,40,}
    };
    start=air;
    for(;;)
    {
    system("cls");
    switch(menu_select())
    {
    case 1:list();
		   break;
    case 2:prtlink();
		   break;
    case 3:search();
		   break;
    case 4:order();
		   break;
    case 5:return_tkt();
    break;
    case 6:printf("\n感谢您的使用,再见!\n");
    exit(0);
    }
    printf("\n任意键继续...\n");
    getch();
    }
    return 0;
}

