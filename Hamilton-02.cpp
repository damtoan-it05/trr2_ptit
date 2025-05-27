#include<iostream>
#include<vector>
using namespace std;
int n,m,u,a[105][105],cx[105],x[105];
vector<string> v;
void result(){
    string s="";
    for(int i=1;i<=n+1;i++){
        s+=to_string(x[i])+" ";
    }
    s.pop_back();
    v.push_back(s);
}
void Hmt(int s){
    for(int i=1;i<=n;i++){
        if(a[x[s-1]][i]){
            if(s==n+1&&i==x[1]){
                x[s]=i;
                result();
            }
            else if(cx[i]){
                x[s]=i;
                cx[i]=0;
                Hmt(s+1);
                cx[i]=1;
            }
        }
    }
}
int main(){
    cin >> n >> m >> u;
    int x1,x2;
    for(int i=1;i<=n;i++){
        cx[i]=1;
    }
    for(int i=1;i<=m;i++){
        cin >> x1 >> x2;
        a[x1][x2]=1;
        a[x2][x1]=1;
    }
    x[1]=u; cx[u]=0;
    Hmt(2);
    cout << v.size() << endl;
    for(string c : v){
        cout << c << endl;
    }
}