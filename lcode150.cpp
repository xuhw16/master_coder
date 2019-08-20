class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        if(n<=0)return 0;
        int res=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            string temp=tokens[i];
            int a=0,b=0,c=0;
            if(temp.size()>1||(temp[0]>='0'&&temp[0]<='9')){
                a=stoi(temp.c_str());
                    st.push(a);
            }
            else
            switch(temp[0]){
                case '+':
                    a=st.top();
                    st.pop();
                    b=st.top();
                    st.pop();
                    c=a+b;
                    st.push(c);
                    break;
                case '-':
                    a=st.top();
                    st.pop();
                    b=st.top();
                    st.pop();
                    c=b-a;
                    st.push(c);
                    break;
                case '*':
                    a=st.top();
                    st.pop();
                    b=st.top();
                    st.pop();
                    c=a*b;
                    st.push(c);
                    break;
                case '/':    
                    a=st.top();
                    st.pop();
                    b=st.top();
                    st.pop();
                    c=b/a;
                    st.push(c);
                    break;}
        }
        return st.top();
    }
};