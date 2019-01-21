#include<bits/stdc++.h>
using namespace std;
const int alphabet_size=26+1;
struct node
{
    struct node *children[alphabet_size];
    bool isEndofword;
};
struct node *getnewnode()
{
    struct node *newnode=new node;
    newnode->isEndofword=false;
    for(int i=0;i<alphabet_size;i++)
        newnode->children[i]=NULL;
    return newnode;
};
void insert(struct node *root,string word)
{
    struct node *current=root;
    for(int i=0;i<word.length();i++)
    {
        int index=word[i]-'a';
        if(current->children[index]==NULL)
            current->children[index]=getnewnode();
        current=current->children[index];
    }
    current->isEndofword=true;
}
bool search(struct node *root,string key)
{
    struct node *current=root;
    for(int i=0;i<key.length();i++)
    {
        int index=key[i]-'a';
        if(current->children==NULL)return false;
        current=current->children[index];
    }
    return(current!=NULL&&current->isEndofword);
}
int main()
{
    string words[8]={"the","this","them","boy","a","karim","ans","any"};
    struct node *root=getnewnode();
    for(int i=0;i<8;i++)insert(root,words[i]);
    for(int i=0;i<8;i++)
    {
        string key;
        cin>>key;
        cout<<search(root,key)<<"\n";
    }
    return 0;
}
