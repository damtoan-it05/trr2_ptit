#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int t,n, a[105][105],deg[105];
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
                a[i][j]=0;a[j][i]=0;
            }
        }
    }
    cout << n << " " << v.size() << endl;
    for(int i=0;i<v.size();i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
}
void test(){
    cin >> t >> n;
    memset(deg,0,sizeof(deg));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            if(a[i][j]) deg[i]++;
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