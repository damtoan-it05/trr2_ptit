#include<iostream>
#include<vector>
#include<cstring>
#include<fstream>
#include<algorithm>
using namespace std;
int t,n,m, a[105][105],deg[105];
vector<pair<int,int>> v;
void case1(){
    for(int i=1;i<=n;i++){
        cout << deg[i] << " ";
    }
}
void case2(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]){
                v.push_back({i,j});
                a[i][j]=a[j][i]=0;
            }
        }
    }
    cout << n << " " << v.size() << endl;
    for(int i=1;i<=n;i++){
        for(int j=0;j<v.size();j++){
            if(i==v[j].first || i==v[j].second) cout << "1 ";
            else cout << "0 ";
        }
        cout << endl;
    }
}
void test(){
    cin >> t >> n;
    if(t==1){
        memset(deg,0,sizeof(deg));
        for(int i=1;i<=n;i++){
            int tmp1,tmp2;
            cin >> tmp1;
            for(int j=1;j<=tmp1;j++){
                cin >> tmp2;
                deg[i]++;
            }
        }
        case1();
    }
    else if(t==2){
        for(int i=1;i<=n;i++){
            int tmp1,tmp2;
            cin >> tmp1;
            for(int j=1;j<=tmp1;j++){
                cin >> tmp2;
                a[i][tmp2]=1;
            }
        }
        case2();
    }
}
int main(){
    test();
    return 0;
}