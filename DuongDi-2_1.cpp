#include<iostream>
#include<cstring>
#include<vector>
#include<fstream>
#include<stack>
using namespace std;
ifstream in("DT.INP");
ofstream out("DT.OUT");
int t,n,v,u,a[105][105],cx[105],cnt=0,ok=1;
vector<int> v1;
void dfs(int x1){
    cx[x1] = 0;
    v1.push_back(x1);
    if(x1 == u){
        ok = 0;
        for(auto x : v1) out << x << " ";
        return;
    }
    for(int i=1; i<=n; i++){
        if(cx[i] && a[x1][i]){
            dfs(i);
            if(!ok) return;
        }
    }
    v1.pop_back();
}
void case1(){
    for(int i=1;i<=n;i++){
        if(a[v][i]){
            if(a[i][u]){
                cnt++;
            }
        }
    }
    out << cnt;
}
void case2(){
    dfs(v);
    if(ok) out << "0";
}
void test(){
    in >> t >> n >> v >> u;
    for(int i=1;i<=n;i++){
        cx[i]=1;
        for(int j=1;j<=n;j++){
            in >> a[i][j];
        }
    }
    if(t==1){
        case1();
    }
    else {
        case2();
    }
    in.close();
    out.close();
}
int main(){
    test();
    return 0;
}