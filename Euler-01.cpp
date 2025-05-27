#include<bits/stdc++.h>
using namespace std;
int t,n,m,u;
int a[105][105],chuaxet[105];
vector<int> v[105];
void dfs(int k){
    chuaxet[k]=0;
    for(auto x : v[k]){
        if(chuaxet[x]){
            dfs(x);
        }
    }
}
bool lienthong(){
    memset(chuaxet,1,sizeof(chuaxet));
    int tplt=0;
    for(int i=1;i<=n;i++){
        if(chuaxet[i]){
            tplt++;
            dfs(i);
        }
    }
    return tplt==1;
}
int isEuler(){
    if(!lienthong()) return 0;
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
    vector<int> v1;
    while(!s.empty()){
        int x=s.top(), i=1;
        while(i<=n&&a[x][i]==0) i++;
        if(a[x][i]&&i<=n){
                s.push(i);
                a[x][i]=0;
                a[i][x]=0;
            }
        else{
            s.pop();
            v1.push_back(x);
        }
    }
    for(int j=v1.size()-1;j>=0;j--){
        cout << v1[j] << " ";
    }
}
void test(){
    int x,y;
    cin >> t >> n >> m;
    if(t==1){
        for(int i=0;i<m;i++){
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
            a[x][y]=1;a[y][x]=1;
        }
        cout << isEuler();
    }
    else if(t==2){
        cin >> u;
        for(int i=0;i<m;i++){
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
            a[x][y]=1;a[y][x]=1;
        }
        Euler(u);
    }
}
int main(){
    int t=1;
    while(t--){
        test();
        return 0;
    }
}