#include<iostream>
#include<vector>
#include<cstring>
#include<fstream>
#include<queue>
#include<algorithm>
using namespace std;
ifstream ip("DT.INP");
ofstream op("DT.OUT");
int n, a[105][105],cx[105];
vector<int> v[105];
void bfs(int i,int lt){
    queue<int> q;
    q.push(i);
    cx[i]=0;
    v[lt].push_back(i);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int j=1;j<=n;j++){
            if(cx[j]&&a[x][j]){
                cx[j]=0;
                v[lt].push_back(j);
                q.push(j);
            }
        }
    }
    sort(v[lt].begin(),v[lt].end());
}
void lienthong(){
    int lt=0;
    memset(cx,1,sizeof(cx));
    for(int i=1;i<=n;i++){
        if(cx[i]){
            lt++;
            bfs(i,lt);
        }
    }
    op << lt << endl;
    for(int i=1;i<=lt;i++){
        for(auto k:v[i]){
            op << k << " ";
        }
        op << endl;
    }
}
void test(){
    ip >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ip >> a[i][j];
        }
    }
    lienthong();
}
int main(){
    test();
    ip.close();
    op.close();
    return 0;
}