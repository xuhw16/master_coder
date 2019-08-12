class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n=s.size(),max_s=0;
       unordered_set<string> udset;
        for(auto &it:wordDict){
            udset.insert(it);
            max_s=max_s>it.size()?max_s:it.size();
        }
        vector<int> dp_m(n+1,0);
        dp_m[0]=1;
        vector<vector<string>> dp(n+1,vector<string>());
        string temp;
        for(int i=0;i<n;i++){
            if(!dp_m[i])continue;
            string temp_m;
            for(int j=i;j<i+max_s&&j<n;j++){
                temp_m+=s[j];
                if(udset.count(temp_m))
                    dp_m[j+1]=1;
            }
        }
        if(!dp_m[n])return dp[0];
        for(int i=0;i<max_s&&i<n;i++){
            temp+=s[i];
            if(dp_m[i+1]&&udset.count(temp))
                dp[i+1].push_back(temp);
        }
        
        for(int i=1;i<n;i++){
            if(!dp_m[i])continue;
            string tmp;
            for(int j=i;j<i+max_s&&j<n;j++){
                tmp+=s[j];
                if(dp_m[j+1]&&udset.count(tmp)){
                  for(int k=0;k<dp[i].size();k++){
                            string temp_s=dp[i][k]+" ";
                           dp[j+1].push_back(temp_s+tmp);
                        }
                }
            }
        }
        return dp[n];
    }
};