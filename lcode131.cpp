//DFS+DP

class Solution {
public:
    vector<vector<int>> palind_dp(string s){
        int n=s.size();
        vector<vector<int>> res(n+1,vector<int>(n+1,0));
        for(int i=1;i<n+1;i++)
            res[i][i]=1;
        for(int i=2;i<n+1;i++){
            if(s[i-1]==s[i-2])
                res[i][i-1]=1;
        }
        for(int l=1;l<n;l++){
            for(int i=1;i<n-l+1;i++){
                int j=i+l;
                if(s[i-1]==s[j-1])
                    res[i][j]=res[i+1][j-1];
            }
        }
        return res;
    }
    void dfs(string s,vector<vector<string>> &res,vector<string> tmp,int idx,vector<vector<int>>& dp){
        if(idx==s.size()){
            res.push_back(tmp);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(dp[idx+1][i+1]){
                string t=s.substr(idx,i-idx+1);
                tmp.push_back(t);
                dfs(s,res,tmp,i+1,dp);
                tmp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        int n=s.size();
        if(n==0)return res;
        vector<vector<int>> dp=palind_dp(s);
        dfs(s,res,tmp,0,dp);
        return res;
    }
};