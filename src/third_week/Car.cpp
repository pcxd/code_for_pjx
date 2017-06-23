#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Size 3   //车库容量
#define price 5  //每分钟的计费标准

typedef struct
{
	int hour;
	int minute;
} Time;            //简单模拟时间信息，记录小时和分钟

typedef struct
{
	char num[20];
	Time reachtime;
	Time leavetime;
} platenum;          //通过结构来保存来车的车牌号，到达时间，离开时间(plantnum为车牌号的英文)

typedef struct stack
{
	platenum car[Size];
	int top;
} Stack; //模拟车栈

typedef struct Node
{
	platenum data;
	struct Node *next;
} QueueNode;                      //结点的定义

typedef struct
{
	QueueNode *front;
	QueueNode *rear;
} Queue, *linkQueue;          //定义队列结点  模拟通道


int InitStack(Stack *S)   //初始化栈
{
	S->top = -1;
	return 1;
}

void Push(Stack *S, platenum &x)      //进栈操作
{


	S->top++;
	S->car[S->top] = x;
	printf("&&&&&&");
	//printf("进站成功!\n");


}

void Pop(Stack *S, platenum &x)     //出栈操作
{
	if (S->top == -1)
		printf("空栈，无法出栈!");
	x = S->car[S->top];
	S->top--;
	//printf("出栈成功!\n");
}

int WhetherEmpty(Stack *S)    //判断栈空
{
	if (S->top == -1)
		return 1;
	else
		return 0;
}

int InitQueue(Queue *Q)    //初始化便道
{
	Q->front = (QueueNode *)malloc(sizeof(QueueNode));   //申请节点
	if (Q->front != NULL)
	{
		Q->rear = Q->front;
		Q->front->next = NULL;
		return 1;
	}
	else return 0;
}

int EnterQ(Queue *Q, platenum x)     //进便道
{
	QueueNode *newNode;
	newNode = (QueueNode *)malloc(sizeof(QueueNode));
	if (newNode != NULL)
	{
		newNode->data = x;
		newNode->next = NULL;
		Q->rear->next = newNode;
		Q->rear = newNode;
		return 1;
	}
	else return 0;
}

int DeleteQ(Queue *Q, platenum x)     //出便道
{
	QueueNode *p;
	p = Q->front->next;
	if (Q->front == Q->rear)    //判断便道是否有车
		return 0;
	x = p->data;
	if (p->next == Q->rear)
	{
		Q->rear = Q->front;
		Q->front->next = NULL;
	}
	Q->front->next = p->next;
	free(p);
	return 1;
}

void Lpush(Stack *S, platenum x)
{
	Push(S, x);             //进临时栈

}

/*void LPop(Stack *S, platenum x)
{
	Pop(S, x);
}
*/
int Arrive(Stack *S, Queue *Q) //车辆到达
{
	platenum x;
	int a;
	printf("输入车牌号：");
	scanf("%s", x.num);
	printf("请输入进车场的时间：");
	scanf("%d:%d", &x.reachtime.hour, &x.reachtime.minute);
	if (S->top == Size - 1)
	{
		printf("停车场已满，已经进入便道\n");
		a = EnterQ(Q, x);                            //递归调用进便道操作
		if (a == 1)
		{
			printf("OK\n");
		}
		else
			printf("No!\n");
	}
	else
	{
		Push(S, x);
	}
	return 1;
}

int Departure(Stack *S,Stack *S1)              //车辆离开操作
{
	platenum a;
	int parktime, paytime;
	char x[20];
	Time leavetime;
	Stack *p;
//	p = (Stack *)malloc(sizeof(Stack));
//	InitStack(p);
	printf("请输入要离去的车牌号：");
	scanf("%s", x);
	if (S->top == -1)
	{
		printf("目前停车场为空！");
	}
	else
		while (strcmp(S->car[S->top].num, x) != 0)   //匹配函数，是否输入的信息与车场信息匹配
		{	
			Pop(S, a);
			Push(S1, a);
		}
	
	printf("请输入要离开的时间：");
	scanf("%d:%d", &leavetime.hour, &leavetime.minute);

	parktime = (leavetime.hour - S->car[S->top].reachtime.hour) * 60 + (leavetime.minute - S->car[S->top].reachtime.minute);
	if (leavetime.hour - S->car[S->top].reachtime.hour >= 10)   paytime = 10;
	else if (leavetime.minute - S->car[S->top].reachtime.minute <= 30)   paytime = leavetime.hour - S->car[S->top].reachtime.hour;
	else paytime = leavetime.hour - S->car[S->top].reachtime.hour + 1;
	printf("其在停车场内停留时间为%d分钟，实际按照%d小时计费，所需金额为：%d元。\n", parktime, paytime, paytime * price);
	S->top--;


	printf("该车已出车场\n");
	while (S1->top>-1)
	{	printf("ssadsadsa");
		Pop(S1, a);
		Push(S, a);
	}
	
	/*if (S->top !=maxsize-1&&Q->front != Q->rear)
	{
		a = Q->front->next->data;

		printf("从便道进入停车场的车牌号：%s", a.num);
		printf("此车进车场的时间为：%d:%d", leavetime.hour, leavetime.minute);
		//scanf("%d:%d", &a.reachtime.hour, &a.reachtime.minute);
		Push(S, a);
		DeleteQ(Q, Q->front->next->data);
	}*/ 
	if (S->top == -1)            //如果到结束了，还没有找到，则输出信息
	{
		printf("停车场查无此车\n");  //有问题，是否注释 
		return 1;
	}
}

void Print1(platenum x)                   //简单的输出操作
{
	printf("车牌号：%s\n", x.num);
	printf("进车场的时间：%d:%d\n", x.reachtime.hour, x.reachtime.minute);
	printf("\n-----------------\n");
}

void Print(Stack *S)//打印车场信息
{
	platenum x;
	int point = S->top;              //从栈头开始
	if (S->top == -1)
		printf("车场没有车辆登记进入!\n");
	else
	{
		while (point != -1)
		{
			printf("\n-----------------\n");
			printf("车目前所在位置为：%d\n", point);
			x = S->car[point];           // 把依次扫描到的信息赋值给x
			Print1(x);                 //调用输出函数
			point--;                    //输出所有的车场信息
		}
		//printf("车场信息显示成功\n");
	}
}

void PrintQ(Queue *Q)     //打印便道车辆信息
{
	QueueNode *p;
	p=(QueueNode *)malloc(sizeof(Queue));  //申请结点
	p = Q->front->next;
	if (Q->front != Q->rear)               /*判断通道上是否有车*/
	{

		//printf("\n等待车辆的车牌号为:  ");
		while (p != NULL)
		{
			printf("\n目前在便道的车辆的车牌号为:  ");            //判断是否到结尾
			printf("%s   ", p->data.num);
			p = p->next;              //如果没找到，继续向下找
		}

		printf("\n");
	}
	else
		printf("\n\t\t\t便道里没有车。\n");

}

int Search(Stack *S)              //按车牌号查找车辆信息
{
	char x[20];
	Time leavetime;
	Stack *p = NULL;
	platenum a;
	int point1 = S->top;
	int point2 = S->top;
	printf("想要查找的车牌号为：");
	scanf("%s", x);
	while (point1 != -1 && point2 != -1)
	{
		if (strcmp(S->car[point1].num, x) == 0)    //匹配函数，是否输入的信息与车场信息匹配
		{

			for (; point1 != S->top; point1++, point2++)       //扫描直到结束
				S->car[point1] = S->car[point2];    //如果找到了 ，输出信息
			printf("该车在停车场\n");
			point2 = -1;
		}
		else
		{
			point2 = point1;
			point1--;
		}
	}

	if (point1 == -1)            //如果到结束了，还没有找到，则输出信息
	{
		printf("停车场查无此车");
		return 1;
	}
}

void printGraph()
{
	int i;
	printf("\n");
	for (i = 0; i<80; i++) printf("-");
	printf("\n\t\t\t------请选择操作序号------");
	printf("\n\n\t\t\t  ----车辆到达请选1----");
	printf("\n\n\t\t\t  ----车辆离开请选2----");
	printf("\n\n\t\t\t  --查询停车场信息请选3--");
	printf("\n\n\t\t\t  --查询便道信息请选4--");
	printf("\n\n\t\t\t  --按车牌号查找请选5--");
	printf("\n\n\t\t\t  ----退出系统请选0----");
	printf("\n\n");
	for (i = 0; i<80; i++) printf("-");
}

int main()
{

	Queue *Q;
	Stack *S = NULL;
	Stack *S1 = NULL;
	S = (Stack *)malloc(sizeof(Stack));
	S1 = (Stack *)malloc(sizeof(Stack));        //申请栈节点
	Q = (linkQueue)malloc(sizeof(Queue));        //申请便道节点
	int i;
	InitQueue(Q);                   //初始化调用
	InitStack(S);//初始化调用
	InitStack(S1); 
	printf("\n--------------------------欢迎光临安徽建筑大学停车场--------------------------\n");
	printf("                   每小时收费5元,停车不满半小时不收费（50元封顶）     ");
	printGraph();
	while (1)
	{
		printf("\n请选择你想要的操作");
		scanf("%d", &i);
		switch (i)
		{
			case 1:
				Arrive(S, Q);   //到达函数
				break;
			case 2:
				Departure(S,S1);  //离开函数
				break;
			case 3:
				Print(S);   //打印车场信息函数
				break;
			case 0:
				exit(1);    //退出
				break;
			case 4:
				PrintQ(Q);   //打印队列函数
				break;
			case 5:
				Search(S);   //查找函数
				break;
			default:
				printf("您的输入有误，请重新输入");
				printGraph();   //输入提示信息
		}
	} 
	return 0; 
}

