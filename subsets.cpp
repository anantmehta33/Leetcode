class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>vec;
        vector<vector<int> > myVec=function(nums,nums.size(),vec);
        sort(myVec.begin(), myVec.end());
        myVec.erase(unique(myVec.begin(), myVec.end()), myVec.end());
        return myVec;
        
    }
    vector<vector <int> > function(vector<int>nums,int n,vector<vector<int>> &vec)
    {
        if (n==0)
        {
            vector<int>v;
            vec.push_back(v);
            return vec;
        }
        vector<vector<int>>c=function(nums,n-1,vec);
        for(auto it: c)
        {
            vector<int>temp=it;
            temp.push_back(nums[n-1]);
            vec.push_back(temp);
        }
        vector<int>temp;
        temp.push_back(nums[n-1]);
        vec.push_back(temp);
        return vec;
    }
};
