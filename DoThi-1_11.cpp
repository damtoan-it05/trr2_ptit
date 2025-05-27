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
    out << n << endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            out << a[i][j] << " ";
        }
        out << endl;
    }
}
void test(){
    in >> t >> n >> m;
    memset(deg,0,sizeof(deg));
    for(int i=1;i<=m;i++){
        int x1,x2,x3;
        in >> x1 >> x2 >> x3;
        a[x1][x2]=x3;a[x2][x1]=x3;
        deg[x1]++;deg[x2]++;
    }
    if(t==1){
        case1();
    }
    else if(t==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j&&a[i][j]==0) a[i][j]=10000;
            }
        }
        case2();
    }
}
int main(){
    test();
    return 0;
}