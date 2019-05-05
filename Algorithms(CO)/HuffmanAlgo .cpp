#include<iostream>
#include<map>
#include<queue>
#include<vector>

using namespace std;


struct node{

    char ch;
    int freq;
    node *left ,*right;
};

    priority_queue< node*,vector<node*>,greater<node*> >pq;
    map<char ,int >frq;
    map<char,string>HuffmanCode;

node* getNode(char ch,int freq,node *left,node *right){

    node* leaf=new node();

    leaf->ch=ch;
    leaf->freq=freq;
    leaf->left=left;
    leaf->right=right;

    return leaf;
}

void encode(node* root,string str,map<char ,string>&HuffmanCode){

    if(root==NULL)
        return ;
     if((root->left)==NULL && (root->right)==NULL)
      HuffmanCode[root->ch]=str;

    encode(root->left,str+"0",HuffmanCode);
    encode(root->right,str+"1",HuffmanCode);

}

/*void decode(node* root,int &index,string encodedString){

    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
        cout<< root->ch;
        return;

    index++;
    if(encodedString[index]=='0')
        decode(root->left,index,encodedString);
    else
        decode (root->right,index,encodedString);

}*/


void HuffmanTree(string str){

    for(int i=0;str[i];i++)
       {
            frq[str[i]]++;
       }


    for( map<char,int >:: iterator it =frq.begin(); it!=frq.end();it++){

        pq.push(getNode(it->first,it->second,NULL,NULL));
        //pq.push(leaf);
    }

    while( pq.size()!=1){

        node *left=pq.top(); pq.pop();
        node *right=pq.top();pq.pop();

        int sum=left->freq+right->freq;
        pq.push(getNode('\0',sum,left,right));


    }
    node *root =pq.top();
    pq.pop();


    encode(root,"",HuffmanCode);


    for(map<char,string>::iterator it=HuffmanCode.begin();it!=HuffmanCode.end();it++){

        cout<< it->first<<"\t"<< it->second<<endl;
    }

    string encodedString="";

    for(int i=0;str[i];i++){

        encodedString+=HuffmanCode[str[i]];
    }
    cout<< "Encoded String : "<< encodedString <<endl;

    int index=-1;
    /*while(index<(int)encodedString.size()-1){

        decode(root,index,encodedString);
    }*/

}


int main(){

    string str="Huffman Algorithm";

    HuffmanTree(str);

    return 0;
}
