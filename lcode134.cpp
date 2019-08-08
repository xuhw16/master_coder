//lcode 134

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        if(n<=0)return -1;
        if(n==1&&gas[0]-cost[0]>=0)return 0;
        vector<int> tmp(n,0);
        for(int i=0;i<n;i++){
            tmp[i]=gas[i]-cost[i];
        }
        for(int i=0;i<n;i++){
            if(tmp[i]<0)continue;
            int route=i,tank=tmp[i];
            bool flag=false;
            while(tank>=0&&(++route%n!=i)){
                tank+=tmp[route%n];
                flag=true;
            }
            if(flag&&route%n==i)
                return i;
        }
        return -1;
    }
};