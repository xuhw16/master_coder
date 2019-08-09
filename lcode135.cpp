

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n<=0)return 0;
        vector<int> res_v(n,1);
        for(int i=0;i<n-1;i++){
            if(ratings[i]<ratings[i+1])
                res_v[i+1]=res_v[i]+1;
        }
        for(int i=n-1;i>0;i--){
            if(ratings[i-1]>ratings[i]){
                res_v[i-1]=max(res_v[i-1],res_v[i]+1);
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=res_v[i];
        }
        return sum;
    }
};