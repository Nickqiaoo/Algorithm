#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
    int data;
    node *next;
    int x=0;
} ;
int num[1000];
int main()
{
    int m,n;
    memset(num,0,sizeof(num));
    node *head=NULL,*p=NULL,*q=NULL;
    int i=1;
    while(scanf("%d%d",&m,&n)!=EOF)//先按正常顺序建立链表
    {
        num[i]=n;
        i++;
        p=new node;
        p->data=m;
        if(head==NULL)
            head=p;
        else
            q->next=p;
        q=p;
        if(n==-1)
        break;
    }
    //q->next=NULL;
    i=1;
    p=head;
    while(p->next)//修改链表的指向
    {
        if(num[i]!=i+1)
        {
            if(num[i]==-1)
                break;
            q=head;
            for(int j=1;j<num[i];j++)
                q=q->next;
            p->next=q;
            break;
        }
        p=p->next;
        i++;
    }
    p=head;
    int flag=0;
    while(p->next)//判断某个节点是否被重复访问
    {
        if(!p->x)
            p->x=1;
        else
            {
                flag=1;
                break;
            }
        p=p->next;
    }
    if(flag)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}
