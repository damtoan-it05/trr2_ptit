#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
ifstream in("TK.INP");
ofstream out("TK.OUT");
int n,a[105][105],b[105][105],x[105];
void ktao(){
    for(int i=1;i<=n;i++) x[i]=1;
}
void dfs(int u){
    stack<int> s;
    s.push(u);
    x[u]=0;
    while(!s.empty()){
        int c=s.top();
        s.pop();
        for(int i=1;i<=n;i++){
            if(b[c][i]&& x[i]){
                x[i]=0;
                s.push(c);
                s.push(i);
                break;
            }
        }
    }
}
bool bfs(int u){
    queue<int> q;
    q.push(u);
    x[u]=0;
    int cnt=1;
    while(!q.empty()){
        int s=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(a[s][i]&& x[i]){
                x[i]=0;
                q.push(i);
                cnt++;
            }
        }
    }
    return cnt==n;
}
int strong_connected(){
    ktao();
    for(int i=1;i<=n;i++){
        if(!bfs(i)) return 0;
        else ktao();
    }
    return 1;
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
    return tplt == 1;
}
int main(){
    in >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            in >> a[i][j];
            if(a[i][j]){
                b[i][j]=b[j][i]=1;
            }
        }
    }
    if(strong_connected()) out << "1";
    else if(connected()) out << "2";
    else out << "0";
    in.close();
    out.close();
}