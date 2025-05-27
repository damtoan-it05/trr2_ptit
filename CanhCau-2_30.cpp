#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;
ifstream in("TK.INP");
ofstream out("TK.OUT");
int n,a[105][105],x[105];
vector<pair<int,int>> v;
void ktao(){
    for(int i=1;i<=n;i++) x[i]=1;
}
void bfs(int u){
    queue<int> q;
    q.push(u);
    x[u]=0;
    while(!q.empty()){
        int c=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(a[c][i]&& x[i]){
                x[i]=0;
                q.push(i);
            }
        }
    }
}
int connected(){
    int tplt=0;
    for(int i=1;i<=n;i++){
        if(x[i]){
            tplt++;
            bfs(i);
        }
    }
    return tplt;
}
void duyet(){
    ktao();
    int x1=connected();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]){
                ktao();
                a[i][j]=0; 
                int x2 = connected();
                if(x1 < x2){
                    v.push_back({i,j});
                }
                a[i][j]=1;
            }
        }
    }
}
int main(){
    in >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            in >> a[i][j];
        }
    }
    duyet();
    sort(v.begin(),v.end());
    out << v.size() << endl; 
    for(auto x:v){
        out << x.first << " " << x.second << endl;
    }
    in.close();
    out.close();
    return 0;
}