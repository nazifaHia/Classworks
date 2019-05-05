#include <iostream>  
#include<stdio.h>
#include<string.h> 

using namespace std;  
    
bool mp[250][250],vis[250],flag[250];  
int dfn[250],low[250];    
int tim,n,count;  
      
    void dfs(int u,int pre)  
    {  
        vis[u] = 1;  
        dfn[u] = low[u] = tim++;  
      
        int k = 0;  
        for(int v = 1; v <= n; ++v)  
        {  
            if(!mp[u][v]) continue;  
            if(!vis[v])  
            {  
                ++k;  
                dfs(v,u);  
                low[u] = min(low[u],low[v]);  
                if((u == 1 && k == 2) || (u != 1 && low[v] >= dfn[u]))  
                    flag[u] = 1;  
            }  
            
            else low[u] = min(low[u],dfn[v]);  
        }  
        count += flag[u];  
    }  
      
    void initialize()  
    {  
        memset(mp,0,sizeof(mp));  
        memset(flag,0,sizeof(flag));  
        memset(vis,0,sizeof(vis));  
        count = tim = 0;  
    }  
      
    int main()  
    {  
       
        int u,v;  
        while(cin>>n)  
        {  
        	if(n==0) break;
            initialize();  
            while(cin>>u)  
            {  
            	if(u==0) break;
                while(getchar() != '\n')  
                {  
                    cin>>v; 
                    mp[u][v] = mp[v][u] = 1;  
                }  
            }  
      
            dfs(1,1);  
      
            cout<<count<<endl;
        }  
      
        return 0;  
    }  
