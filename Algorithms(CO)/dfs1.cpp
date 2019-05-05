#include<bits/stdc++.h>
#define MAX 200

using namespace std;

int color[MAX];
int prv[200];
int d[MAX];
int f[MAX];
int t=0;



vector<int>vec[20];

void dfs(int u){

    color[u]=1;
    t++;
    d[u]=t;

    for(int i=0; i<vec[u].size() ; i++){

        if(color[vec[u][i]]==0){
            prv[vec[u][i]]=u;
            dfs(vec[u][i]);
        }
    }

    t++;
    f[u]=t;
    color[u]=2;

}


int main(){


    int t;
    cin>>t;
    while(t--){

        int n,e;
        cin>> n>>e;
        t=0;

        memset(color,0,sizeof color);
        memset(prv,-1,sizeof prv);
        memset(d,-1,sizeof d);
        memset(f,-1,sizeof f);

        int u=n;
        int x,y;

        while(e--){

            cin>>x>>y;

            vec[x-1].push_back(y-1);
            vec[y-1].push_back(x-1);
            cout<<x<<y<<endl;

        }
        for(int i=0; i<n;i++){
            cout<<"color"<<color[i]<<endl;
            for(int j= 0;j<vec[i].size();j++)
                cout<<vec[i][j]+1<<" ";
            cout<<endl;
        }

        for(int i=0;i<n;i++){

            if(color[i]==0) dfs(i);
        }

       for(int j=0;j<n;j++){

            cout<< color[j]<<endl;
        }
        for(int h=0;h<20;h++){

            vec[h].clear();
        }
    }


    return 0;
}


