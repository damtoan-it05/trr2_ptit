#include<iostream>
#include<vector>
#include<cstring>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream ip("DT.INP");
ofstream op("DT.OUT");
int t,n,m, a[105][105],deg[105];
vector<pair<int,int>> v;
void case1(){
    for(int i=1;i<=n;i++){
        op << deg[i] << " ";
    }
}
void case2(){
    op << n << endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            op << a[i][j] << " ";
        }
        op << endl;
    }
}
void test(){
    ip >> t >> n;
    if(t==1){
        memset(deg,0,sizeof(deg));
        for(int i=1;i<=n;i++){
            int tmp1,tmp2;
            ip >> tmp1;
            for(int j=1;j<=tmp1;j++){
                ip >> tmp2;
                deg[i]++;
            }
        }
        case1();
    }
    else if(t==2){
        for(int i=1;i<=n;i++){
            int tmp1,tmp2;
            ip >> tmp1;
            for(int j=1;j<=tmp1;j++){
                ip >> tmp2;
                a[i][tmp2]=1;
            }
        }
        case2();
    }
    ip.close();
    op.close();
}
int main(){
    test();
    return 0;
}