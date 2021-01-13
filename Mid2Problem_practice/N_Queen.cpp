#include<bits/stdc++.h>
using namespace std;
bool visit[100][100];
bool go(vector<vector<int>>&v,int sx,int sy, int dx,int dy,int r, int c){

    if(sx<0 || sx>=r || sy>=c || v[sx][sy]==0 || visit[sx][sy]==true){
        return false;
    }

    visit[sx][sy]=true;

    if(sx==dx && sy==dy){
        return true;
    }



    if(go(v,sx,sy+1,dx,dy,r,c))
        return true;

    return false;
}
int main(){
    int r, c;
    cin >> r>> c;
    vector<vector<int >>v(r,vector<int>(c));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            cin>>v[i][j];
    }
    memset(visit,false,sizeof(visit));
    go(v,0,0,r-1,c-1,r,c);
     for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            cout<<visit[i][j]<<"\t";
            cout<<endl;
    }

    return 0;
}
