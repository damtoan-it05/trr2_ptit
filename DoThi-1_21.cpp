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
    for(int i=0;i<v.size();i++){
        out << v[i].first << " " << v[i].second << " " << a[v[i].first][v[i].second]<< endl;
    }
}
void test(){
    in >> t >> n;
    memset(ra,0,sizeof(ra));
    memset(vao,0,sizeof(vao));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            in >> a[i][j];
            if(a[i][j]>0 && a[i][j]<51){
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
}
int main(){
    test();
    return 0;
}