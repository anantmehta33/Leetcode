class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>vec;
        function(vec,0,nums);
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        return vec;
    }
    void function(vector<vector<int>>&vec,int idx,vector<int>&nums)
    {
      if(idx==nums.size())
      {
          vec.push_back(nums);
          return;
      }
      for(int i=idx;i<nums.size();i++)
      {
          swap(nums[i],nums[idx]);
          function(vec,idx+1,nums);
          swap(nums[i],nums[idx]);
      }
      return;
    }
};
