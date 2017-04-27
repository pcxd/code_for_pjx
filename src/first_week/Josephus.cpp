#include <iostream>
#include<stdio.h>
using namespace std;
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* NEXT;
} Node;
typedef struct Node *LinkList;
void CreatList(LinkList& L, int n){
	LinkList p = NULL,r;
	L= new Node;
	L->data= 1;
	r= L;
	for ( int i=1; i<n; i++ ){
		p= new Node;
		p->data= i+1;
		p->NEXT= NULL;
		r->NEXT= p;
		r= p;
	}
	r->NEXT= L;
}
void Josephus(LinkList head,int n,int m,int k){
	LinkList L= head, pre;
	for ( int i= 0; i < k-1; i++ ){
		pre = L;
		L = L->NEXT;
	}
	int j= 0;
	while ( L->NEXT!= L)     //判断是否还剩一个元素
	{
		if ( j == m)
		{
			pre->NEXT = L->NEXT;
			cout<<L->data<<'\t';
			j= 0;
			delete L;
			L= pre->NEXT ;
			continue;
		}
		j++;
		pre = L;
		L= L->NEXT;
	}
	cout<< L->data;
}

int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
	LinkList l1;
	CreatList(l1, n);
	Josephus(l1, n, m, k);
	return 0;
}
