#include<iostream>
#include<vector>
#include<cstring>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream in("DT.INP");
ofstream out("DT.OUT");
int t,n,m, a[105][105],ra[105],vao[105];
vector<pair<int,int>> v;
void case1(){
    for(int i=1;i<=n;i++){
        out << vao[i] << " " << ra[i] << endl;
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
    memset(ra,0,sizeof(ra));
    memset(vao,0,sizeof(vao));
    for(int i=1;i<=m;i++){
        int x1,x2;
        in >> x1 >> x2;
        a[x1][x2]=1;
        ra[x1]++;vao[x2]++;
    }
    if(t==1){
        case1();
    }
    else if(t==2){
        case2();
    }
    in.close();
    out.close();
}
int main(){
    test();
    return 0;
}