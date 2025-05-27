#include<iostream>
#include<cstring>
#include<vector>
#include<fstream>
#include<queue>
using namespace std;
ifstream in("DT.INP");
ofstream out("DT.OUT");
int t,n,v,u,a[105][105],cx[105],d[105];
vector<int> v1;
void bfs(int x1){
    queue<int> q;
    q.push(x1);
    cx[x1]=0;
    while(!q.empty()){
        int x2=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(cx[i]&& a[x2][i]){
                cx[i]=0;
                q.push(i);
                d[i]=x2;
            }
        }
    }
}
void duongdi(){
    if(d[v]==0){
        out << "0";
        return;
    }
    else{
        v1.push_back(v);
        int x1=d[v];
        while(x1!=u){
            v1.push_back(x1);
            x1=d[x1];
        }
        v1.push_back(u);
    }
}
void case1(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[u][i]&&a[i][v]){
            cnt++;
        }
    }
    out << cnt;
}
void case2(){
    bfs(u);
    duongdi();
    for(int i=v1.size()-1;i>=0;i--){       
        out << v1[i] << " ";
    }
}
void test(){
    in >> t >> n >> u >> v;
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