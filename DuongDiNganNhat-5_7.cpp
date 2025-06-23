#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,s,t,a[105][105],pre[105];
const int INF=1e9;
void BN(){
    memset(pre,-1,sizeof(pre));
    vector<int> d(n+1,INF);
    d[s]=0;
    pre[s]=0;
    for(int k=1;k<=n-2;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][j]==0) continue;
                if(d[i]!=INF&&d[j]>d[i]+a[i][j]){
                    pre[j]=i;
                    d[j]=d[i]+a[i][j];
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] != 0 && d[i] != INF && d[j] > d[i] + a[i][j]){
                cout << -1; 
                return;
            }
        }
    }
    if(pre[t]==-1) cout << 0;
    else{
        vector<int> res;
        cout << d[t] << endl;
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
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    cin >> n >> s >> t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            if(a[i][j]==10000||i==j) a[i][j]=0;
        }
    }
    BN();
}