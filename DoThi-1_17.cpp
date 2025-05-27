#include<iostream>
#include<cstring>
#include<vector>
#include<fstream>
using namespace std;
ifstream in("DT.INP");
ofstream out("DT.OUT");
int t,n,m,ra[105],vao[105];
vector<pair<int,int>> v;
void case1(){
    for(int i=1;i<=n;i++){
        out << vao[i] << " " << ra[i] << endl;
    }
}
void case2(){
    out << n << " " << v.size() << endl;
    for(int i=1;i<=n;i++){
        for(int j=0;j<v.size();j++){
            if(i==v[j].first) out << "1 ";
            else if(i==v[j].second) out << "-1 ";
            else out << "0 ";
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
        v.push_back({x1,x2});
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