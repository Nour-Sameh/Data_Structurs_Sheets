#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
 struct node{
    int data;
    node* next;
};
#define N 11 //prime num
class hashTable{
    node* root[N];
    public:
    hashTable(){
        for(int i=0;i<N;i++){
            root[i]=NULL;
        }
    }
    void insert(int key){
        int i=key%N;
        node* newnode=new node;
        newnode->data=key;
        newnode->next=root[i];
        root[i]=newnode;
    }
    void Delete(int key){
        int i=key%N;
        node* prev=NULL;
        node*tmp=root[i];

        while(tmp!=NULL){
            if(tmp->data==key){
                if(prev==NULL){
                    root[i]=tmp->next;
                    delete(tmp);
                    return;
                }
                else{
                    prev->next=tmp->next;
                    delete(tmp);
                    return;
                }
            }
            prev=tmp;
            tmp=tmp->next;
        }
        cout<<key<<"is not found\n";
    }
    bool search(int key){
        int i=key%N;
        node*tmp=root[i];
        while(tmp!=NULL){
            if(tmp->data==key){
                return true;
            }
            tmp=tmp->next;
        }
        return false;
    }
    void print(){
        for(int i=0;i<N;i++){
            node* tmp=root[i];
            cout<<"index[ "<<i<<" ]:\t";
            while(tmp!=NULL){
                cout<<tmp->data<<" → ";;
                tmp=tmp->next;
            }
            cout<<"NULL\n";
        }
        cout<<endl;
    }
    node* retrive(int p){
        if(p<0||p>=N){
            cout<<"out of range! \n";
            return NULL;
        }
        return root[p];

    }
};
 int maxValue(hashTable &h,int i){
    node* head=h.retrive(i);
    if(head==NULL){
        cout<<"Empty no elements.\n";
        return -1;
    }
    int mx=head->data;
    while(head!=NULL){
        mx=max(mx,head->data);
        head=head->next;
    }
    return mx;
}
// o(nlog(n))
void SortSpecificPosition(hashTable &h,int i){
    vector<int>arr;
    node* tmp=h.retrive(i);
    while(tmp!=NULL){
        arr.push_back(tmp->data);
        tmp=tmp->next;
    }
    sort(arr.begin(),arr.end());
    node* temp=h.retrive(i);
    int x=0;
    while(temp!=NULL){
        temp->data=arr[x++];
        temp=temp->next;
    }
}
// o(n^2)
// void SortSpecificPosition(hashTable &T, int pos){
//     node* head = T.retrive(pos);
//     node* newList = NULL;
//     while (head != NULL) {
//         int maximum = maxValue(T,pos);

//         node* newNode = new node;
//         newNode->data = maximum;
//         newNode->next = newList;
//         newList = newNode;

//         T.Delete(maximum);
//         head = T.retrive(pos);
//     }
// }
int main()
{
    hashTable T;
    T.insert(22);
    T.insert(4);
    T.insert(66);
    T.insert(88);
	T.insert(27);
    T.insert(48);
    T.insert(5);
 
    T.print();
    cout << (T.search(48) ? "48 is found": "48 is not founcd")<<endl;
    cout << (T.search(22) ? "22 is found" : "22 is not founcd") << endl;
    cout << (T.search(3) ? "3 is found" : "3 is not found")<<endl;
    cout << "Hash table after insert 5\n";
    T.insert(49);
    T.print();
    cout << "hash table after delete 88\n";
    T.Delete(88);
    T.print();
	cout<<"Max for specific position"<<maxValue(T,0)<<endl;

	cout<<"Sort specific list in specific position"<<endl;
	SortSpecificPosition(T, 5);
	cout<<"List after sorting"<<endl;
	T.print();
    return 0;
}
