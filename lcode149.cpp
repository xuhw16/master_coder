class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int res=0;
        if(n<=2)return n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp=2;
                vector<int> p1=points[i],p2=points[j];
                vector<bool> fg(n,0);
                fg[i]=1;
                fg[j]=1;
                if(p1[0]==p2[0]){
                    for(int k=0;k<n;k++){
                        if(fg[k]==0&&points[k][0]==p1[0])
                            temp++;
                    }
                    if(temp>res)
                        res=temp;
                }
                else{
                    double slop=double(p1[1]-p2[1])/(p1[0]-p2[0]);
                    for(int k=0;k<n;k++){
                        if(fg[k]==0&&abs(points[k][1]-slop*(points[k][0]-p1[0])-p1[1])<1e-8&&abs(points[k][1]-slop*(points[k][0]-p2[0])-p2[1])<1e-8)
                            temp++;
                    }
                    if(temp>res)
                        res=temp;
                }
            }
        }
        return res;
    }
};