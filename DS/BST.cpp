//

class BST
{
    struct node {
     int data;
     node* left;
     node* right;
    };
    node* root=NULL;
    public:
    BST(){root=NULL;}
    bool empty()const{re root==NULL;};
    void insert(int);
    void remove(int);
    void inorder(node*);
    void pinorder();
    void preorder(node*);
    void ppreorder();
    void postorder(node*);
    void ppostorder();
};



void BST::insert(int d)
{
    node* t=new node;
    node* par;
    t->data=d;
    t->left=NULL;
    t->right=NULL;
    par=NULL;
    if(empty())root=t;
    else
    {
        node* cur;
        cur=root;
        while(cur)
        {
            par=cur;
            if(t->data>cur->data)cur=cur->right;
            else cur=cur->left;
        }
        if(t->data<par->data)par->left=t;
        else par->right=t;
        
    }
}

void BST::remove(int d)
{
    bool bo=0;
    
    if(empty())re ;
    
    node* cur;
    node* par;
    cur = root;
    
    while(cur)
    {
        if(cur->data==d){bo=1;break;}
        else 
        {
            par=cur;
            if(d>cur->data)cur=cur->right;
            else cur=cur->left;
        }
        
    }
    if(bo==0){/*not found */}
    
    //single child,leaf node or 2 children
    
    if((cur->left==NULL && cur->right!=NULL) ||(cur->left!=NULL && cur->right==NULL) )
    {
        if(cur->left==NULL && cur->right!=NULL)
        {
            if(par->left==cur)
            {
                par->left=cur->right;
                delete cur;
            }
            else
            {
                par->right=cur->right;
                delete cur;
            }
        }
        else
        {
            if(par->left==cur)
            {
                par->left=cur->left;
                delete cur;
            }
            else
            {
                par->right=cur->left;
                delete cur;
            }
        }
        re ;
    }
    if(cur->left==NULL && cur->right==NULL)//then this is a leaf node
    {
          if(par->right==cur)par->right=NULL;
          else par->left=NULL;
          
          delete cur;
          re;
    }
    
    if(cur->left!=NULL && cur->right!=NULL)
    {
        node* temp;
        temp=cur->right;
        
        if((temp->left==NULL) &&(temp->right==NULL))
        {
            cur=temp;
            delete temp;
            cur->right=NULL;
            
        }
        else
        {
            if((cur->right)->left!=NULL)
            {
                node* temp1;
                node* temp2;
                temp1=cur->right;
                temp2=(cur->right)->left;
                
                while((temp1->left)!=NULL)
                {
                    temp2=temp1;
                    temp1=temp1->left;
                }
                cur->data=temp1->data; 
                delete temp1;
                temp2->right=NULL;

            }
            else
            {
                node* temp1;
                temp1=cur->right;
                cur->data=temp1->data;
                cur->right=temp1->right;
                delete temp1;
            }
        }
        re ;
    }
  
}

void BST::inorder(node* x)
{
    if(x!=NULL)
    {
        if(x->left)inorder(x->left);
        cout<<x->data<<" ";
        if(x->right)inorder(x->right);
    }
    else re;
}

void BST::pinorder(){inorder(root);}

 void BST::postorder(node* x)
{
    if(x!=NULL)
    {
        if(x->left)postorder(x->left);
        if(x->right)postorder(x->right);
        cout<<x->data<<" ";
    }
    else re;
}
void BST::ppostorder(){postorder(root);}

 void BST::preorder(node* x)
{
    if(x!=NULL)
    {
        cout<<x->data<<" ";
        if(x->left)preorder(x->left);
        if(x->right)preorder(x->right);
        
    }
    else re;
}

void BST::ppreorder(){preorder(root);}
 
int main()
{
   
        
BST bt;
bt.insert(2);
bt.insert(5);
bt.insert(3);
bt.insert(7);
bt.insert(1);

bt.pinorder();
cout<<endl;
bt.ppostorder();
cout<<endl;
bt.ppreorder();

    
}
