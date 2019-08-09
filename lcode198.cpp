class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        vector<int> dp(n,0);
        if(n==1)return nums[0];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int tmp_max=0,idx=0;
            for(int j=0;j<i-1;j++)
            {
                if(tmp_max<dp[j]){
                    idx=j;
                    tmp_max=dp[j];
                }
            }
            dp[i]=dp[idx]+nums[i];
        }
        int res=0;
        for(int i=0;i<n;i++)
            res=res>dp[i]?res:dp[i];
        return res;
    }
};