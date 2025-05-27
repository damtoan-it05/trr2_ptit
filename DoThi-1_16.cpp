#include<iostream>
#include<cstring>
#include<vector>
#include<fstream>
using namespace std;
ifstream in("DT.INP");
ofstream out("DT.OUT");
int t,n,m,ra[105],vao[105];
vector<int> v[105];
void case1(){
    for(int i=1;i<=n;i++){
        out << vao[i] << " " << ra[i] << endl;
    }
}
void case2(){
    out << n << endl;
    for(int i=1;i<=n;i++){
        out << v[i].size() << " ";
        for(auto x : v[i]){
            out << x << " ";
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
        v[x1].push_back(x2);
        ra[x1]++;vao[x2]++;
    }
    if(t==1){
        case1();
    }
    else if(t==2){
        case2();
    }
}
int main(){
    test();
    return 0;
}