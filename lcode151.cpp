class Solution {
public:
    string swapString(string &s,int start,int end)
    {
        string res=s;
        while(start<end)
        {
            char ctemp=res[start];
            res[start]=res[end];
            res[end]=ctemp;
            start++;
            end--;
        }
        return res;
    }
    string reverseWords(string s) {
        int n=s.size();
        string res;
        if(n==0)return res;
        string tempres=swapString(s,0,n-1);
        int start=0,end=0;
        while(start<n&&end<n)
        {
            if(tempres[start]==' ')
            {
                start++;
                continue;
            }
            else
            {
                end=start;
                while(end<n&&tempres[end]!=' ')
                    end++;
                string tempstring=tempres.substr(start,end-start);
                tempstring=swapString(tempstring,0,tempstring.size()-1);
                res+=tempstring;
                if(end!=n)res+=" ";
                start=end;
            }
        }
        if(res[res.size()-1]==' ')return res.substr(0,res.size()-1);
        return res;
    }
};