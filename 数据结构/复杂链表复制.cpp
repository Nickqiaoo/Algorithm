#include <iostream>

using namespace std;
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode* head1=new RandomListNode;
        head1=pHead;
        RandomListNode* p=new RandomListNode;
        RandomListNode* q=new RandomListNode;
        p=pHead;
        q=pHead;
        while(q!=NULL){
            p->next=q->next;
            p=p->next;
            q=q->next;
        }

    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
