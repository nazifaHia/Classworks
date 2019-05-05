#include<bits/stdc++.h>

#define inf 10000

using namespace std;

int graph[101][101];
int tree[101];
int cost[101];
int prev[101];
int trCost[101];
int c;

int initialize(int c){

    for(int i=0;i<c;i++){

        tree[i]=0;
        cost[i]=inf;
        trCost[i]=inf;
        prev[i]=-1;
    }

}

int extractMin(){

    int Min=inf,index=-1;

    for(int i=0;i<c;i++){
        if(tree[i]==0 && cost[i]<Min ){
            Min=cost[i];
            index=i;
        }

    }
    return index;


}

void prims(int s){
    cost[s]=0;
    trCost[s]=0;

    for(int i=0;i<c;i++){

        int u=extractMin();
        cout<<u+1<<endl;
        tree[u]=1;

       if(u!=s)
       {
           int a=prev[u];
           trCost[u]=max(cost[u],trCost[a]);
       }

        for(int j=0;j<c;j++){
            if(graph[u][j]!=inf&& tree[j]==0 && cost[j]>graph[u][j]){

                prev[j]=u;
                cost[j]=graph[u][j];
            }
        }
    }
}

int main(){

    int s,q;
    int cnt=0;


    while(cin>>c>>s>>q){
    cnt++;

    if(c==0&&s==0&&q==0) break;
        for(int i=0;i<c;i++){
            for(int j=0;j<c;j++){

                graph[i][j]=inf;

            }
        }
        int f=0,l=0,d=0;

        for(int i=0;i<s;i++){
             cin>>f>>l>>d;
             graph[f-1][l-1]=d;
             graph[l-1][f-1]=d;

             //cout<<graph[l-1][f-1]<<endl;

        }
        cout<< "Case #"<< cnt<<endl;
        for(int i=0;i<q;i++){
            int t=0,e=0;
            initialize(c);
            cin>>t>>e;

            /*for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){

                cout<<graph[i][j]<<endl;

            }
        }*/
            prims(t-1);
            if(trCost[e-1]==inf){
				cout << "no path" << endl;
			}
			else cout <<trCost[e-1] << endl;
        }

    }


    return 0;
}
