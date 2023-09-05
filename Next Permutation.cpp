class Solution {
public:
    void nextPermutation(vector<int>& nums) {
     int bp=-1;
     for(int i=nums.size()-2;i>=0;i--)
     {
         if(nums[i]<nums[i+1])
         {
             bp=i;
             break;
         }
     }
     if(bp==-1)
     {
         reverse(nums.begin(),nums.end());
         return;
     }
     else
     {
         int mx_i=bp;
         for(int i=bp+1;i<nums.size();i++)
         {
             if(nums[i]>nums[bp])
             {
                 if(mx_i == bp)
                 {
                     mx_i=i;
                     continue;
                 }
                 if(nums[i]<nums[mx_i])
                      mx_i=i;
             }
         }
         swap(nums[bp],nums[mx_i]);
         sort(nums.begin()+bp+1,nums.end());
         cout << bp;
     }
     return;
    }
};
