#include <iostream>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        queue<TreeNode*>q;
        vector<int>v;
        q.push(root);
        if(root==NULL)
            return v;
        while(!q.empty()){
                TreeNode *t=q.front();
            v.push_back(t->val);
            q.pop();
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
        return v;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
