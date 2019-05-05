#include <iostream>
#include<queue>
#include<functional>

using namespace std;


int main()
{
	int n;
	while(cin>> n,n)
	{
		if(n==0)
		{
			return 0;
		}
		priority_queue<int ,vector<int>,greater<int>> q;

		while(n--)
		{
			int x;
			cin>> x;
			q.push(x);
		}

		int total=0,cost=0;
		while(q.size()>1)
		{
			total=q.top();
			q.pop();
			total+=q.top();
			q.pop();
			cost+=total;
			q.push(total);
		}

		cout<< cost<<endl;
	}

	return 0;
}
