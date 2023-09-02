class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*,int>>q;
        map<int,int>mp;
        q.push({root,0});
        while(!q.empty())
        {
            pair<Node *,int>p=q.front();
            Node *curr=p.first;
            int num=p.first->data;
            int pos=p.second;
            mp[pos]=num;
            if(curr->left == 0 and curr->right == 0)
            {
                q.pop();
            }
            else if (curr->left == 0 and curr->right!=0)
            {
                q.pop();
                q.push({curr->right,pos+1});
            }
            else if (curr->left != 0 and curr->right==0)
            {
                q.pop();
                q.push({curr->left,pos-1});
            }
            else
            {
                q.pop();
                q.push({curr->left,pos-1});
                q.push({curr->right,pos+1});
            }
        }
        vector<int>vec;
        for(auto i:mp)
           vec.push_back(i.second);
         return vec;
    }
};
