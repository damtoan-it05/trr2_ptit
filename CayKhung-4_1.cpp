#include<iostream>
#include<fstream>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;

ifstream in("CK.INP");
ofstream out("CK.OUT");
int t,n,s;
int a[105][105],cx[105];

void DFS(int u){
    cx[u]=0;
    for(int i=1;i<=n;i++){
        if(cx[i]&&a[u][i]){
            if(i>u) out << u << " " << i << endl;
            else out << i << " " << u << endl;
            DFS(i);
        }
    }
}
void BFS(int u){
    queue<int> q;
    q.push(u);
    cx[u]=0;
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int i=1;i<=n;i++){
            if(cx[i]&&a[x][i]){
                cx[i]=0;
                if(i>x) out << x << " " << i << endl;
                else out << i << " " << x << endl;
                q.push(i);
            }
        }
    }
}
int main(){
    in >> t >> n >> s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            in >> a[i][j];
        }
    }
    memset(cx,1,sizeof(cx));
    out << n-1 << endl;
    if(t==1){
        DFS(s);
    }
    else if(t==2){
        BFS(s);
    }
    in.close();
    out.close();
}