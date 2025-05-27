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
vector<int> v;
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
            if(a[c][i]&& x[i]){
                x[i]=0;
                s.push(c);
                s.push(i);
                break;
            }
        }
    }
}
int connected(){
    int tplt=0;
    for(int i=1;i<=n;i++){
        if(x[i]){
            tplt++;
            dfs(i);
        }
    }
    return tplt;
}
void duyet(){
    ktao();
    int x1=connected();
    for(int i=1;i<=n;i++){
        ktao();
        x[i]=0;
        int x2=connected();
        if(x1<x2){
            v.push_back(i);
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
    for(int x:v){
        out << x << " ";
    }
    in.close();
    out.close();
}