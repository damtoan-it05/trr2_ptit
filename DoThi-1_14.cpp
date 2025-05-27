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
    in >> t >> n;
    memset(ra,0,sizeof(ra));
    memset(vao,0,sizeof(vao));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            in >> a[i][j];
            if(a[i][j]){
                v.push_back({i,j});
                ra[i]++;vao[j]++;
            }
        }
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