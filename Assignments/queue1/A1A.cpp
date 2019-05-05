#include<bits/stdc++.h>
#include<queue>


using namespace std;

int main(){

    int n;
    while(cin>>n){

        if(n==0) break;

        priority_queue<int ,vector<int>,greater<int> > q;

         while(n--){

            int x;
            cin>>x;
            q.push(x);

        }
        int Count=0,total=0;
        while(q.size()>1){

            int a=q.top();
            total=a;
            q.pop();
            int b=q.top();
            total+=b;
            q.pop();
            Count+=total;
            q.push(total);

        }
        cout<<Count<<endl;
    }

    return 0;
}
