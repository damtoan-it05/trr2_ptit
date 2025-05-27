#include<iostream>
#include<vector>
using namespace std;
int n,k,a[105][105],cx[105],x[105],sum=10000;
string v;
void result(){
    int s=0;
    string tmp="";
    for(int i=1;i<=n;i++){
        s+=a[x[i]][x[i+1]];
    }
    if(s<sum){
        for(int i=1;i<=n+1;i++){
            tmp+=to_string(x[i])+" ";
        }
        tmp.pop_back();
        v=tmp;
        sum=s;
    }
}
void Hmt(int s){
    for(int i=1;i<=n;i++){
        if(a[x[s-1]][i] >0 && a[x[s-1]][i]<51){
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
    if(v.size()) {
        cout << sum << endl;
        cout << v;
    }
    else cout << "0";
}