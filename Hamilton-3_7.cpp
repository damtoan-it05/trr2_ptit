#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
ifstream in("CT.INP");
ofstream out("CT.OUT");
int n,u,a[105][105],x[105],cx[105];
vector<string>v;
void result(){
    string s="";
    for (int i = 1; i <=n+1; i++){
        s+=to_string(x[i])+" ";
    }
    s.pop_back();
    v.push_back(s);
}
void hmt(int h){
    for(int i=1;i<=n;i++){
        if(a[x[h-1]][i]){
            if(h==n+1&&i==x[1]){
                x[h]=i;
                result();
            }
            else if(cx[i]){
                x[h]=i;
                cx[i]=0;
                hmt(h+1);
                cx[i]=1;
            }
        }
    }
}
void test(){
    in >> n >> u;
    for(int i=1;i<=n;i++){
        cx[i]=1;
        for(int j=1;j<=n;j++){
            in >> a[i][j];
        }
    }
    x[1]=u;cx[u]=0;
    hmt(2);
    for(string c:v){
        out << c << endl;
    }
    out << v.size();
    in.close();
    out.close();
}
int main(){
    test();
    return 0;
}