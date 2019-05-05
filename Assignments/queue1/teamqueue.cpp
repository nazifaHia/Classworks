#include<iostream>
#include<queue>

using namespace std;

int main()
{
	queue<int>team[1001];
	int teamMembers[1000001];
	
	int T,t=1;
	int num;
	//cin>> T;
	//cout<<T;
	while(cin>>T)
	{
		for(int i=0;i<T;i++)
		{
			cin>> num;
			//cout<<num;
			for(int j=0;j<num;j++)
			{
				int name;
				cin>> name;
				teamMembers[name]=i;
			}
		}
	
	
	string command;
	queue <int> combinedQ;
	
	cout<< "Scenario#"<< t++<< ':'<< endl;
	 
	while(cin>> command )
	{

		if(command[0]=='E')
		{
			cin>> num;
			
			int teaM=teamMembers[num];
			
			if(team[teaM].empty())
			{
				combinedQ.push(teaM);
			}
			
			team[teaM].push(num);
				
		}		
		
 		
		else if(command[0]=='D') 
		{
			int teaM=combinedQ.front();
			//cout<< teaM;
			
			cout<< team[teaM].front()<<endl;
			team[teaM].pop();
			if(team[teaM].empty())
			{
				combinedQ.pop();
			}
		}
		if (command[0]=='S')
		{
			return 0;
		}
	}		
	
	}
	
	return 0;
}
