class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
     int n=nums.size();
     int i=0;
     int j=n-1;
     sort(nums.begin(),nums.end());
     int ans=0;
     for(int val=0;val<n;val++)
     {
        while(nums[val]> (long long)nums[i]*k)i++;
        ans=max(ans,val-i+1);
     }
     return n-ans;
        
    }
};