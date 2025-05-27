#include<iostream>
#include<vector>
#include<cstring>
#include<fstream>
using namespace std;
ifstream ip("DT.INP");
ofstream op("DT.OUT");
int t,n, a[105][105],deg[105];
vector<int> v[105];
void case1(){
    for(int i=1;i<=n;i++){
        op << deg[i] << " ";
    }
}
void case2(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]){
                v[i].push_back(j);
            }
        }
    }
    op << n << endl;
    for(int i=1;i<=n;i++){
        op << v[i].size() << " ";
        for(int x : v[i]){
            op << x << " ";
        }
        op << endl;
    }
}
void test(){
    ip >> t >> n;
    memset(deg,0,sizeof(deg));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ip >> a[i][j];
            if(a[i][j]) deg[i]++;
        }
    }
    if(t==1){
        case1();
    }
    else if(t==2){
        case2();
    }
    ip.close();
    op.close();
}
int main(){
    test();
    return 0;
}