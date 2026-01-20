class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {  int val=0;
        int value=(val|val+1);
            while((value!=nums[i]) && val<nums[i])
            {  
                val++;
                 value=(val|val+1);

            }
            if(value==nums[i]){
                ans[i]=val;
            }
            else{
                ans[i]=-1;
            }

        }
        return ans;
        
    }
};