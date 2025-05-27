#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
ifstream in("CT.INP");
ofstream out("CT.OUT");
int t,n,m,a[105][105],b[105][105],x[105];
int ra[105],vao[105];
void ktao(){
    for(int i=1;i<=n;i++) x[i]=1;
}
void dfs(int u){
    x[u]=0;
    for(int i=1;i<=n;i++){
        if(x[i]&&b[u][i]){
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
        if(ra[i]-vao[i]==1 || vao[i]-ra[i]==1) l++;
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
                if(a[i][j]){
                    ra[i]++;vao[j]++;
                    b[i][j]=b[j][i]=1;
                }
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