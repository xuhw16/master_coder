class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==0)return 0;
        int res=-2147438647;
        vector<int> vres(n,0);
        vector<int> ires(n,0);
        vres[0]=nums[0];
        ires[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int vtemp=nums[i],itemp=nums[i];
            int vtemp1=nums[i]*vres[i-1],itemp1=nums[i]*ires[i-1];
            vres[i]=max(max(vtemp,vtemp1),itemp1);
            ires[i]=min(min(vtemp,vtemp1),itemp1);
        }
        for(int i=0;i<n;i++)
        {
            if(res<vres[i])
                res=vres[i];
        }
        return res;
    }
};
