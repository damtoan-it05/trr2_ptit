#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,s,t,pre[105];
const int INF=1e9;
vector<pair<int,int>> v[105];
void dijkstra(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> d(n+1,INF);
    d[s]=0;
    pre[s]=s;
    pq.push({0,s});
    while(!pq.empty()){
        auto tmp=pq.top();pq.pop();
        int u=tmp.second,w=tmp.first;
        if(w>d[u]) continue;
        for(auto it:v[u]){
            int x=it.first;
            if(d[x]>d[u]+it.second){
                d[x]=d[u]+it.second;
                pre[x]=u;
                pq.push({d[x],x});
            }
        }
    }
    if(d[t]==INF) cout << 0;
    else{
        cout << d[t] << endl;
        vector<int> res;
        int tmp=t;
        while(tmp!=s){
            res.push_back(tmp);
            tmp=pre[tmp];
        }
        res.push_back(s);
        reverse(res.begin(),res.end());
        for(int x:res){
            cout << x << " ";
        }
    }
}
int main(){
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    cin >> n >> s >> t;
    int x;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> x;
            if(x>0&&x<=50) v[i].push_back({j,x});
        }
    }
    dijkstra();
}