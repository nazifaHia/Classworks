#include<bits/stdc++.h>

using namespace std;


int priority(char symbol){

    switch(symbol){

    case '+':
    case'-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default :
        return 0;


    }
}


int main(){

    stack<char>myStack;
    vector<char>output;
    string str;

    int c;
    cin>>c;

    while(c--){

        cin>>str;
        for(int i=0;i<str.length();i++){
            if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='^'){

                while(!myStack.empty() && priority(myStack.top())>=priority(str[i])){

                    output.push_back(myStack.top());
                    myStack.pop();

                }
                myStack.push(str[i]);
            }

            else if(str[i]=='('){

               myStack.push(str[i]);
            }
            else if(str[i]==')'){

                if(myStack.top()!='('){
                    output.push_back(myStack.top());
                    myStack.pop();
                }
                myStack.pop();
            }
            else
                output.push_back(str[i]);
        }
        while(!myStack.empty() ){
            output.push_back(myStack.top());
            myStack.pop();
        }

        for(int i=0;i<output.size();i++){

            cout<<output[i];

        }
        cout<<endl;
        while(!output.empty()){

            output.pop_back();
        }

    }

    return 0;
}
