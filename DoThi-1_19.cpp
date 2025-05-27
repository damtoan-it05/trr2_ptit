#include<iostream>
#include<cstring>
#include<vector>
#include<fstream>
using namespace std;
ifstream in("DT.INP");
ofstream out("DT.OUT");
int t,n,m,ra[105],vao[105],a[105][105];
vector<pair<int,int>> v;
void case1(){
    for(int i=1;i<=n;i++){
        out << vao[i] << " " << ra[i] << endl;
    }
}
void case2(){
    out << n << " " << v.size() << endl;
    for(int j=0;j<v.size();j++)
        out << v[j].first << " " << v[j].second << endl;
}
void test(){
    in >> t >> n;
    memset(ra,0,sizeof(ra));
    memset(vao,0,sizeof(vao));
    for(int i=1;i<=n;i++){
        int x1,x2;
        in >> x1;
        for(int j=1;j<=x1;j++){
            in >> x2;
            v.push_back({i,x2});
            ra[i]++;vao[x2]++;
        }
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