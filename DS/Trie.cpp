

#define alpsize 26

int geti(char s){re (int)(s-'a');}


class Trie
{
    struct node {
     node* child[alpsize];
     int occur;
    };
   
   public:
    node* root;
    Trie(){root=new node();root->occur=0;}
    
    void insert(string s);
    void remove(string s);
    int search(string s);
};
  
void Trie::insert(string s)
{
    node* cur=root;
    cur->occur++;
    
    for(int i=0;i<s.length();i++)
    {
        int x=geti(s[i]);
        if(cur->child[x]==NULL)cur->child[x]=new node();
        cur->child[x]->occur++;
        cur=cur->child[x];
    }
}

void Trie::remove(string s)
{
    node* cur=root;
    cur->occur--;
    node* temp;
    
    for(int i=0;i<s.length();i++)
    {
        
        int x=geti(s[i]);
        temp=cur->child[x];
        temp->occur--;
    }
    
}

int Trie::search(string s)
{
    node* cur=root;
    
    for(int i=0;i<s.length();i++)
    {
        int x=geti(s[i]);
        if(cur->child[x]==NULL)re 0;
        cur=cur->child[x];
    }
    re cur->occur;//for prefix count or re 1 for found
}
    
int main()
{
    Trie t;
    t.insert("ddfada");
    t.insert("ddfda");
    t.insert("fsad");
    int p=t.search("dd");
    couts(p);
}
