#include <cstdlib>
#include <iostream>
#include <stack>
#include<stdio.h>
using namespace std;
typedef char ElementType;

typedef struct BiTreeNode
{
    ElementType data;
    struct BiTreeNode* Lchild;
    struct BiTreeNode* Rchild;
}BiTreeNode, *BiTree;
void creatBiTree(BiTree &T)
{
    char data;
    data=getchar();
    if(data=='#')
    {
        T=NULL;
    }
    else
    {
        T=new BiTreeNode;
        T->data=data;
        creatBiTree(T->Lchild);
        creatBiTree(T->Rchild);
    }
}
void inOrderTraverse(BiTree &T)
{
    if(T)
    {
        inOrderTraverse(T->Lchild);
        printf("%c ",T->data);
        inOrderTraverse(T->Rchild);
    }
}
void inOrderTraverse2(BiTree &T)
{
    stack<BiTree>s;
    BiTree P=T;
    while(P||!s.empty())
    {
        if(P)
        {
            s.push(P);
            P=P->Lchild;
        }
        else
        {
            P=s.top();
            s.pop();
            printf( "%c ",P->data);
            P=P->Rchild;
        }
    }
}
int main()
{
    BiTree T= NULL;
    creatBiTree(T);
    printf("in order is:");
    inOrderTraverse(T);
    printf("\n");
    return 0;
}
