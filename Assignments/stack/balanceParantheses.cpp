#include<iostream>
#include<stack>
#include<string>


using namespace std;


int main(void)
{
	int n;
	cin>>n;
	string a;
	getline(cin,a);
	stack<char> checker;
	
	while(n--)
	{
		string s;
		getline(cin,s);
		//getline(cin,a);
		//char a;
		
		
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='('|| s[i]=='[')
			{
				checker.push(s[i]);
			}	
			else if(s[i]==')')
			{
				if( checker.empty()||checker.top()!='(')
				{
					checker.push(s[i]);
					break;
				}
				
				checker.pop();
			}
			
			else if(s[i]==']')
			{
				if(checker.empty()|| checker.top()!='[')
				{
					checker.push(s[i]);
					break;
				}
				checker.pop();
			}
			
			
		}
		if(checker.empty())
		{
			cout<<"Yes"<<endl;
		
		}

		else cout<< "No"<<endl;

		
	}		
	

	
	return 0;
}
