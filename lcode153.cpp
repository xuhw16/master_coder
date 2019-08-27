class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        int start=0,end=n-1;
        while(start<end){
            int mid=(start+end)/2;
            if(nums[mid]>nums[start])
            {
                start=mid;
            }
            else if(nums[mid]<nums[start])
            {
                end=mid;
            }
            else
            {            
                return nums[mid]<nums[end]?nums[0]:nums[end];
            }
        }
        return nums[end];
    }
};
 