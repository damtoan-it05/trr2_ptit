#include<iostream>
#include<vector>
#include<cstring>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream ip("DT.INP");
ofstream op("DT.OUT");
int t,n,m, a[105][105],deg[105];
vector<int> v[105];
void case1(){
    for(int i=1;i<=n;i++){
        op << deg[i] << " ";
    }
}
void case2(){
    op << n << endl;
    for(int i=1;i<=n;i++){
        op << v[i].size() << " ";
        for(int x:v[i]){
            op << x << " ";
        }
        op << endl;
    }
}
void test(){
    ip >> t >> n >> m;
    memset(deg,0,sizeof(deg));
    for(int i=1;i<=m;i++){
        int tmp1,tmp2;
        ip >> tmp1 >> tmp2;
        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
        deg[tmp1]++;deg[tmp2]++;
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