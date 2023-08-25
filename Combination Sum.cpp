class Solution {
public:
    vector<vector<int> >v;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ans;
        func(candidates,target,0,ans);
        return v;
    }
    void func(vector<int>& candidates,int target,int i,vector<int>& ans)
    {
        if(target==0)
        {
            v.push_back(ans);
            return;
        }
        if(i==candidates.size())
        {
            return;
        }
        int j=i;
        // for(int j=i;j<candidates.size();j++)
        // {
            if(target-candidates[j]>=0)
            {
                ans.push_back(candidates[j]);
                func(candidates,target-candidates[j],j,ans);
                ans.pop_back();
            }
            func(candidates,target,j+1,ans);
       // }
        return;
    }
};
