class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        q.push(make_pair(root, make_pair(0,0)));

        while(!q.empty()){
            pair <TreeNode*, pair<int, int>> temp = q.front();
            q.pop();

            TreeNode *node = temp.first;
            int hd = temp.second.first; // hd = horizontal distance
            int level = temp.second.second;

            mp[hd][level].insert(node->val);

            if(node->left != NULL)
                q.push(make_pair(node->left, make_pair(hd-1, level+1)));
            if(node->right != NULL)
                q.push(make_pair(node->right, make_pair(hd+1, level+1)));
        }

        for(auto i : mp){
            vector<int> res;
            for(auto j : i.second){
                res.insert(res.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(res);
        }

        return ans;
    }
};
