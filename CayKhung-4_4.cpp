#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
ifstream in("CK.INP");
ofstream out("CK.OUT");
int n,s;
int cx[105];
struct Node{
    int x,y,w;
};
vector<pair<int,int>> v[105];
void Prim(int a){
    int d=0;
    vector<Node> vm;
    cx[a]=0;
    while(vm.size()!= n-1){
        int nw=1e6,x1=0,y1=0;
        for(int i=1;i<=n;i++){
            if(cx[i]==0){
                for(auto it : v[i]){
                    if(cx[it.first]){
                        if(it.second < nw){
                            nw=it.second;
                            x1=it.first;
                            y1=i;
                        }
                    }
                }        
            }
        }
        vm.push_back({x1,y1,nw});
        d+=nw;
        cx[x1]=0;
    }
    out << d << endl;
    for(Node s:vm){
        if(s.x>s.y) swap(s.x,s.y);
        out << s.x << " " << s.y << " " << s.w << endl;
    }
}
int main(){
    in >> n >> s;
    int tmp;
    memset(cx,1,sizeof(cx));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            in >> tmp;
            if(tmp>0&&tmp<=50){
                v[i].push_back({j,tmp});
                v[j].push_back({i,tmp});
            }
        } 
    }
    Prim(s);
    in.close();
    out.close();
}