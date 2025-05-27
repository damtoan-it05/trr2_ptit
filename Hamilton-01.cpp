#include<iostream>
#include<vector>
using namespace std;
int n,k,a[105][105],cx[105],x[105];
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
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cx[i]=1;
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    x[1]=k;cx[k]=0;
    Hmt(2);
    cout << v.size() << endl;
    if(v.size()){
        for(string x : v){
            cout << x << endl;
        }
    }
}