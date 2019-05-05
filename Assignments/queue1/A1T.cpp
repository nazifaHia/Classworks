#include<bits\stdC++.h>

using namespace std;


int main(){

    queue<int> Team[101];
    int TeamMembers[100001];
    queue<int>combinedQ;
    int T;

    while(cin>>T){

        for(int i=0;i<T;i++){

            int numM;
            cin>>numM;

            for(int j=0;j<numM;j++){

                int member;
                cin>>member;

                TeamMembers[member]=i;

            }
        }


    string command;
    int t;
    while(cin>>command){

        if(command[0]=='E'){

            int member;
            cin>>member;

            t=TeamMembers[member];

            if(Team[t].empty()){

                combinedQ.push(t);
            }

            Team[t].push(member);

        }

        else if(command[0]=='D'){

            t=combinedQ.front();

            cout<<Team[t].front()<<endl;
            Team[t].pop();

            if(Team[t].empty()){

                combinedQ.pop();
            }

        }

        if(command[0]=='S'){

            return 0;
        }




    }


}

    return  0;
}
