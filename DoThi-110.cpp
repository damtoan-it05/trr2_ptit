#include<iostream>
#include<vector>
#include<cstring>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream in("DT.INP");
ofstream out("DT.OUT");
int t,n,m, a[105][105],b[105][105],deg[105];
vector<pair<int,int>> v;
void case1(){
    for(int i=1;i<=n;i++){
        out << deg[i] << " ";
    }
}
void case2(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(b[i][j]){
                v.push_back({i,j});
                b[i][j]=b[j][i]=0;
            }
        }
    }
    out << n << " " << v.size() << endl;
    for(int i=0;i<v.size();i++){
        out << v[i].first << " " << v[i].second << " " << a[v[i].first][v[i].second] << endl;
    }
}
void test(){
    in >> t >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            in >> a[i][j];
        }
    }
    if(t==1){
        memset(deg,0,sizeof(deg));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][j] >0 && a[i][j]<51){
                    deg[i]++;
                }
            }
        }
        case1();
    }
    else if(t==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][j] >0 && a[i][j]<51){
                    b[i][j]=b[j][i]=1;
                }
            }
        }
        case2();
    }
}
int main(){
    test();
    return 0;
}