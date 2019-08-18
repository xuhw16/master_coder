class Solution {
public:
    bool compare(string &s,int i,int j){
        int n=s.size();
        while(i<n&&j<n){
            if(s[i]>s[j])return true;
            if(s[i]<s[j])return false;
            i++;
            j++;
        }
        return false;
    }
    
    string lastSubstring(string s) {
        int idx=0,n=s.size();
        char s_t=s[0];
        vector<int> v_idx;
        char st=s[0];
        for(int i=1;i<n;i++){
            if(s[i]>st)st=s[i];
         }
        for(int i=0;i<n;i++)
            if(s[i]==st)
                v_idx.push_back(i);
        if(v_idx.size()==n)return s;
        vector<int> dp(v_idx.size(),0);
        int s_idx=v_idx[0];
        for(int i=1;i<v_idx.size();i++){
            int j=v_idx[i];
            if(compare(s,j,s_idx)){
                s_idx=j;
            }
        }
       return s.substr(s_idx);
    }
};