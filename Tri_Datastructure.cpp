#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *next[27];
    bool endmark;

    node()
    {
        for(int i=0; i<26; i++)
            next[i]=NULL;

        endmark=false;

    }
};


void build_trie(string str, int len ,node *curr)
{

    for(int i=0; i<len; i++)
    {
        int id=str[i]-'a';

        if(curr->next[id]==NULL)
            curr->next[id]=new node();

        curr=curr->next[id];
    }
    curr->endmark=true;
}

bool search_str(string str,int len ,node *curr)
{
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'a';

        if(curr->next[id]==NULL)
            return false;

        curr=curr->next[id];
    }
    return curr->endmark;
}

void delet(node *curr)
{
    for(int i=0; i<26; i++)
    {
        if(curr->next[i])
            delet(curr->next[i]);

    }
    delete(curr);
}




int main()
{

    string s[100],s1[100];
    int n,q;
    node *root= new node();

    printf("Enter the number of words to insert:\n");
    cin>>n;


    for(int i=0; i<n; i++)
    {
        cin>>s[i];
        build_trie(s[i],s[i].size(),root);
    }

    printf("Enter no. of the query: \n");
    cin>>q;

    for(int i=0; i<q; i++)
    {
        string s2;
        // cin>>s1[i];

        // bool x=search_str(s1[i],s1[i].size(),root);
        cin>>s2;
        bool x=search_str(s2,s2.size(),root);

        if(x==true)
            cout<<"String present"<<endl;
        else
            cout<<"Not present"<<endl;
    }

    delet(root);
    return 0;

}

/*
5
algo
algea
also
tom
to
*/
