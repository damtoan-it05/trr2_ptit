#include<bits/stdc++.h>
using namespace std;
int t,n,u;
int a[105][105],b[105][105],chuaxet[105];
vector<int> v[105];
void dfs(int k){
    chuaxet[k]=0;
    for(int i=1;i<=n;i++){
        if(chuaxet[i]&&b[k][i]){
            dfs(i);
        }
    }
}
//kiem tra lien thong yeu
bool lienthong(){
    memset(chuaxet,1,sizeof(chuaxet));
    int tplt=0;
    for(int i=1;i<=n;i++){
        if(chuaxet[i]){
            tplt++;
            dfs(i);
        }
    }
    return tplt==1;
}
// kiem tra euler nua euler
int isEuler(){
    if(!lienthong()) return 0;
    int  c1=0, c2=0, c3=0;
    for (int i=1;i<=n;i++)
	{
        int ra=0, vao=0;
		for (int j=1;j<=n;j++){
            ra+=a[i][j];
            vao+=a[j][i];
        }
        if(ra-vao==1) c1++;
        else if(vao-ra==1) c2++;
        else if(ra==vao) c3++;
	}
    if(c1==1 && c2==1 && c3==n-2) return 2;
    if(c3==n) return 1;
    return 0;
}
// in chu trinh euler
void Euler(int u){
    stack<int> s;
    s.push(u);
    vector<int> v1;
    while(!s.empty()){
        int x=s.top(), i=1;
        while(i<=n&&a[x][i]==0) i++;
        if(a[x][i]&&i<=n){
                s.push(i);
                a[x][i]=0;
                a[i][x]=0;
            }
        else{
            s.pop();
            v1.push_back(x);
        }
    }
    for(int j=v1.size()-1;j>=0;j--){
        cout << v1[j] << " ";
    }
}
void test(){
    int k,c;
    cin >> t >> n;
    if(t==1){
        for(int i=1; i<=n; i++){
            int k;
            cin >> k;
            for(int j=1; j<=k; j++){
                int x;
                cin >> x;
                a[i][x]=1;
                b[i][x]=b[x][i]=1;
            }
        }
        cout << isEuler();
    }
    else if(t==2){
        cin >> u;
        for(int i=1;i<=n;i++){
            cin >> k;
            for(int j=1;j<=k;j++){
                cin >> c;
                a[i][c]=1;
            }
        }
        Euler(u);
    }
}
int main(){
    test();
    return 0;
}