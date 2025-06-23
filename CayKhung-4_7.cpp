#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
int pre[105],sz[105];
vector<vector<int>> vm;
vector<vector<int>> c;
void makeset(){
    for(int i=1;i<=n;i++){
        pre[i]=i;
        sz[i]=1;
    }
}
int Findset(int u){
    if(u==pre[u]) return u;
    return pre[u]=Findset(pre[u]);
}
bool Union(int a,int b){
    a=Findset(a);
    b=Findset(b);
    if(a==b) return false;
    if(sz[a]<sz[b]){
        swap(a,b);
    }
    sz[a]+=sz[b];
    pre[b]=a;
    return true;
}
void Kruskal(){
    makeset();
    int d=0;
    sort(vm.begin(),vm.end());
    for(auto it:vm){
        int u=it[1],v=it[2];
        if (Union(u,v)){
            c.push_back({it[0],u,v});
            d+=it[0];
        }
    }
    cout << d << endl;
    for(auto it:c){
        cout << it[1] << " " << it[2] << " " << it[0] << endl;
    }
}
int main(){
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT","w", stdout);
    cin >> n >> m;
    int u,v,w;
    for(int i=1;i<=m;i++){
        cin >> u >> v >> w;
        vm.push_back({w,u,v});
    }
    Kruskal();
}