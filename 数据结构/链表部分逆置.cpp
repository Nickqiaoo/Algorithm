#include <iostream>  
using namespace std;  
struct List  
{  
    int num;  
    List *next;  
};  
List *head;  
void reverse(int begin, int end, List *&head)  
{  
    List *b;  
    int sum=0;  
    b=head;  
    while(1)  
    {  
      if(begin==0)//需要三个指针，前两个分别指向要逆置的两个节点，第三个指向后面的一个节点  
       {  
           List *k=head;  
           List *x=head->next,*y;  
           for(int i=0;i<end-begin;i++)//循环逆置  
           {  
               if(x->next!=NULL)  
                   y=x->next;  
               else  
                   y=NULL;  
               x->next=k;  
               k=x;  
               x=y;  
           }  
           head=k;  
           b->next=y;  
           break;  
       }  
       else if (sum==begin-1)//同上  
       {  
           List *bb=b->next;  
           List *k=bb;  
           List *x=bb->next,*y=x;  
           for(int i=0;i<end-begin;i++)  
           {  
               if(x->next!=NULL)  
               y=x->next;  
               else  
                   y=NULL;  
               x->next=k;  
               k=x;  
               x=y;  
           }  
           b->next=k;  
           bb->next=y;  
           break;  
       }  
       else  
       {  
           if(b->next!=NULL){  
            b=b->next;  
            sum++;}  
        }  
         
   }  
}  
List *Create()  
{  
    List *p = NULL;  
    List *q = NULL;  
    head = NULL;  
    for ( int i = 0; i < 10; i++ ) {  
        p = new List;  
        p->num = i * 2;  
        if ( head == NULL ) {  
            head = p;  
        }  
        else {  
            q->next = p;  
        }  
        q = p;  
    }  
  
    if ( head != NULL ) {  
        q->next = NULL;  
    }  
  
    return head;  
}  
void displayList(List *head)  
{  
    while ( head != NULL ) {  
        cout << head->num;  
        head = head->next;  
        if ( head != NULL ) {  
            cout << "->";  
        }  
    }  
    cout << endl;  
}  
  
int main() {  
    Create();  
    int begin, end;  
    cin >> begin >> end;  
    reverse(begin, end, head);  
    displayList(head);  
    return 0;  
}  