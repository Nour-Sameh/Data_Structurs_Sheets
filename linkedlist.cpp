#include <iostream>
using namespace std;
struct node{
    node* next;
    int data;
};
class linked_list{
    node* head;
    node* tail;
    int cnt;
    public:
    linked_list(){
        make_null();
    }
    void make_null(){
        head=new node;  //create dummy node 
        head->next=NULL;
        tail=NULL;
        cnt=0;
    }
    node* END(){
        if(head->next==NULL)return head;
        return tail;
    }
    void Insert(int data,node*p){// insert after p
        if(p==NULL)p=END();
        node* newnode=new node;
        newnode->data=data;
        newnode->next=p->next;
        p->next=newnode;
        if(newnode->next==NULL)tail=newnode;
        cnt++;
    }

    void Delete(node* p){
        if(p==NULL||p==END()){
            cout<<"No Element to be deleted\n";
            return;
        }
        if(p->next==tail)tail=p;
        node* tmp=p->next;
        p->next=p->next->next;
        tmp->next=NULL;
        delete(tmp);
        cnt--;
    }

    node* Locate(int data){
        node* p=head;
        while(p->next!=NULL){
            if(p->next->data==data){
                return p;
            }
            p=p->next;
        }
        return NULL;
    }

    node* LocateInRange(int data,node*l,node*r){
        node* p=l;
        while(p->next!=NULL&&p->next!=r){
            if(p->next->data==data){
                return p;
            }
            p=p->next;
        }
        return END();
    }

    int retrive(node* p){
        if(p==NULL||p->next==NULL){
            return -1;
        }
        return p->next->data;
    }

    void print(){
        node* p=head->next;
        while(p!=NULL){
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }

    node* First(){return head;}

    node* Next(node* p){
        if(p==tail)return NULL;
        return p->next;
    }
    node* prev(node*p){
        if(p==head)return NULL;
        node* tmp=head;
        while(tmp!=NULL&&tmp->next!=p){
            tmp=tmp->next;
        }
        return tmp;
    }
    int Size(){return cnt;}
};

linked_list reverse(linked_list &l1){
    linked_list l2;
    node* pos=l1.prev(l1.END());
	while (pos!=NULL&&pos!=l1.First()){
		int x=l1.retrive(pos); 
		l2.Insert(x,l2.END());
		pos=l1.prev(pos);
	}
	return l2;
}

void purge(linked_list &a){
    node*i=a.First();
    while(a.Next(i)!=NULL){
        node* j=a.Next(i);
        node* prev_j=i;
        while(a.Next(j)!=NULL){
            if(a.retrive(i)==a.retrive(j)){
                a.Delete(prev_j);
                j=prev_j->next;
            } 
            else{
                prev_j=j;
                j=a.Next(j);
            }
        }
        i=a.Next(i);
    }
}


void removeoccur(linked_list &a,int data){
    node* pos=a.Locate(data);
    while(pos!=NULL){
        a.Delete(pos);
        pos=a.Locate(data);// for update
    }
}
void split(linked_list &L,linked_list &ev,linked_list &od){
    node* curr=L.First();
	while(curr!=NULL){
		int x=L.retrive(curr);
		if (x%2==0)
			ev.Insert(x,ev.END());
		else
			od.Insert(x,od.END());
 
		curr=L.Next(curr);
	}
}
linked_list concatinate(linked_list &l1,linked_list& l2){
    linked_list myll;
    node* curr=l1.First();
	while(curr!=l1.END()){
		int x=l1.retrive(curr);
		myll.Insert(x,myll.END()); 
		curr=l1.Next(curr);
	}
	curr=l2.First();
	while(curr!=l2.END()){
		int x=l2.retrive(curr);
		myll.Insert(x,myll.END());
		curr=l2.Next(curr);
	}
    return myll;
}
int Sum(linked_list a){
    int sum =0;
    
    
    node* tmp=a.First();
    while(tmp!=NULL){
        sum+=(a.retrive(tmp));
        tmp=a.Next(tmp);
    }
    return sum;
}
int main(){
    linked_list l ;
    //------------------Test Insert---------------------
    l.Insert(1,l.END());
    l.Insert(2,l.First());
    l.Insert(3,l.END());
    l.Insert(4,l.END());
    l.Insert(5,l.First());
    l.Insert(534,NULL);
    l.print();
    //----------------Split
    linked_list lEven,lOdd;
    split(l,lEven,lOdd);
    cout<<"all:";
    l.print();
    cout<<"Even:";
    lEven.print();
    cout<<"Odd:";
    lOdd.print();

    linked_list newL=concatinate(lEven,lOdd);
    cout<<"Concatenated linked list is:";
    newL.print();
    //-------------------Test locate------------------
    int x=2;
    node* pos=l.Locate(x);
    if (pos==l.END())
        cout<<x<<" does not exist"<<endl;
    else
        cout<<x<<" found at"<<endl;
    x=4;
    pos=l.Locate(x);
    if (pos==l.END())
        cout<<x<<" does not exist"<<endl;
    else
        cout<<x<<" found  "<<endl;
    x=100;
    pos=l.Locate(x);
    if (pos==l.END())
        cout<<x<<" does not exist"<<endl;
    else
        cout<<x<<" found"<<endl; 
    //----------------------reverse--------------
    linked_list l2=reverse(l);
    cout<<"linked list after reverse:";
    l2.print();
    //-----------------------------------------
    //---------------Purge----------------
    linked_list L3;
    L3.Insert(4,L3.First());
    L3.Insert(5,L3.First());
    L3.Insert(4,L3.First());
    L3.Insert(5,L3.First());
    L3.Insert(4,L3.First());
    L3.Insert(3,L3.First());
    L3.Insert(4,L3.First());
    L3.Insert(3,L3.First());
    L3.Insert(5,L3.First());
    L3.Insert(3,L3.First());

    cout<<"\nlinked list before removing all 3: ";
    L3.print();
    removeoccur(L3,3);
    cout<<"\nlinked list afer removing 3:   ";
    L3.print();
    cout<<"\nlinked list before purge:   ";
    L3.print();
    purge(L3);
    cout<<"\nlinked list after purge:   ";
    L3.print();
    //--------------------------------------------------
    cout<<"#elements in linked list is "<< L3.Size()<<endl;
    cout<<"sum "<<Sum(L3)<<endl;
    return 0;
}   
