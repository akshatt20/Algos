class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n =nums.size();
        
        vector<long long> pref(n);
        for(int i=0;i<n;++i){
            pref[i] = (i>0?pref[i-1]:0) + nums[i];
        }
        
        vector<int> order(n, -1);
        int st = 0;
        int cnt = nums[0];
        for(int i=1;i<n;++i){
            if(nums[i]<=cnt){
                for(int j=st;j<i-1;++j){
                    order[j] = i - 1;
                }
                st = i;
                cnt = nums[i];
            } else {
                cnt = nums[i];
            }
        }
        for(int j=st;j<n-1;++j){
            order[j] = n - 1;
        }

        vector<int> dec_table(n, -1);
        st = 0;
        cnt = nums[0];
        for(int i=1;i<n;++i){
            if(nums[i]>=cnt){
                for(int j=st;j<i-1;++j){
                    dec_table[j] = i - 1;
                }
                st = i;
                cnt = nums[i];
            } else {
                cnt = nums[i];
            }
        }
       
        long long ans = -1e15;
        for(int i=0;i<n;++i){
            int p = order[i];
            int q = -1;
            int j = -1;
            if(p!=-1){
                q = dec_table[p];
                if(q!=-1){
                    j = order[q];
                    if(j!=-1){
                        long long s1 = pref[p] - (i>0?pref[i-1]:0);
                        long long s2 = pref[q] - pref[p];
                        long long s3 = max(pref[j] - pref[q], pref[q+1] - pref[q]);
                        
                        ans = max(ans, s1 + s2 + s3);
                    }
                }
            }
        }
        return ans;
    }
};