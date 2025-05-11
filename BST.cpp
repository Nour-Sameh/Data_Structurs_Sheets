#include <iostream> 
using namespace std;

struct node{
    int data;
    node*left;
    node* right;

    node(int val,node*l,node*r){
        data=val;
        left=l;
        right=r;
    }
};  
class BST{
    public:
    node* root;
    BST(){root=NULL;}

    bool isEmpty(node* tmp){return tmp==NULL;}
    bool isleaf(node* tmp){return tmp->left==NULL&&tmp->right==NULL;}

    void insert(node* &tmp,int data){
        if(tmp==NULL){tmp = new node(data,NULL,NULL);}
        else if(tmp->data>data){
            return insert(tmp->left,data);
        }
        else{
            insert(tmp->right,data);
        }
    }
    void inorder(node* tmp){
    if(tmp==NULL){}
    inorder(tmp->left);
    cout << " " << tmp->data << " ";
    inorder(tmp->right);
    }
    void pre_order(node* tmp){
        if(tmp==NULL){}
        cout << " " << tmp->data << " ";
        inorder(tmp->left);
        inorder(tmp->right);
    }
    void post_order(node* tmp){
    if(tmp==NULL){}
    inorder(tmp->left);
    inorder(tmp->right);
    cout << " " << tmp->data << " ";
    }
    int height(node* tmp){
        if(tmp==NULL)return -1;
        int l=height(tmp->left);
        int r=height(tmp->right);
        return max(l,r)+1;
    }
    node*minnode(node*tmp){
    if(tmp==NULL||tmp->left==NULL)return tmp;
    minnode(tmp->left);
    }

    int maxdata(node*tmp){
        if(tmp==NULL||tmp->left==NULL)return tmp->data;
    minnode(tmp->right);
    }
    void remove(node*tmp,int data){
    if(tmp==NULL)return ;
    if(tmp->data>data)remove(tmp->left,data);
    else if(tmp->data<data)remove(tmp->right,data);
    else{
        if(tmp->left==NULL){
            node* de=tmp;
            tmp=tmp->right;
            delete(de);
        }
        else if(tmp->right==NULL){
            node* de=tmp;
            tmp=tmp->left;
            delete(de);
        }
        else{
            node* mn=minnode(tmp->right);
            tmp->data=mn->data;
            remove(tmp->right,mn->data);
        }

    }

    }
    node* Successor(node* ptr,int data){
        if(ptr == NULL)
			return NULL;

        if (ptr->right != NULL)
            return minnode(ptr->right);

        node* succ = NULL;
		node* curr = ptr;  
		while (curr != NULL) {
			if (data < curr->data) {
				succ = curr;
				curr = curr->left;
			}
			else if (data >= curr->data) 
				curr = curr->right;
    }
    return succ;
    }
};

int main()
{
	BST t;
	t.insert(t.root,110);
	t.insert(t.root,5);
	t.insert(t.root,100);
	t.insert(t.root,10);
	t.inorder(t.root);
	cout<<endl;

	cout<<"the height = "<<t.height(t.root)<<endl;
	t.remove(t.root,110);

	t.inorder(t.root);
	cout<<endl;

	cout<<t.Successor(t.root,100)->data<<endl;

	system("pause");
}