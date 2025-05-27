#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
ifstream in("CT.INP");
ofstream out("CT.OUT");
int t,n,m,a[105][105],x[105];
void ktao(){
    for(int i=1;i<=n;i++) x[i]=1;
}
void dfs(int u){
    x[u]=0;
    for(int i=1;i<=n;i++){
        if(x[i]&&a[u][i]){
            dfs(i);
        }
    }
}
int connected(){
    ktao();
    int tplt=0;
    for(int i=1;i<=n;i++){
        if(x[i]){
            tplt++;
            dfs(i);
        }
    }
    return tplt==1;
}
int isEuler(){
    if(!connected()) return 0;
    int c=0,l=0;
    for(int i=1;i<=n;i++){
        int tmp=0;
        for(int j=1;j<=n;j++){
            tmp+=a[i][j];
        }
        if(tmp%2) l++;
        else c++;
    }
    if(l==2) return 2;
    else if(c==n) return 1;
    return 0;
}
void Euler(int u){
    stack<int> s;
    s.push(u);
    vector<int> v;
    while(!s.empty()){
        int c=s.top(),i=1;
        while(i<=n&&a[c][i]==0) i++;
        if(i<=n){
            s.push(i);
            a[c][i]=0;
            a[i][c]=0;
        }
        else{
            s.pop();
            v.push_back(c);
        }
    }
    for(int i=v.size()-1;i>=0;i--){
        out << v[i] << " ";
    }
}
void test(){
    in >> t >> n;
    if(t==1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                in >> a[i][j];
            }
        }
        out << isEuler();
    }
    else{
        in >> m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                in >> a[i][j];
            }
        }
        Euler(m);
    }
    in.close();
    out.close();
}
int main(){
    test();
    return 0;
}