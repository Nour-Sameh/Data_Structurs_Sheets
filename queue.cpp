#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct node{
	int data;
	node* next;
};

class Queue{
private:
	node* front;
    node*back;
	int cnt;
public:
	Queue(){
		front=NULL;
		back=NULL;
		cnt=0;
	}
    bool is_Empty(){
        return front==NULL;
    }
    void Enqueue(int data){
        node* newnode=new node;
        newnode->data=data;
        newnode->next=NULL;
        if(cnt==0){
            back=newnode;
            front=back;
        }
        else{
            back->next=newnode;
            back=newnode;
        }
        cnt++;
    }
    int Dequeue(){
        if(is_Empty()){
            cout<<"queue is empty\n";
            
        }
        else{
            int x=front->data;
            node* tmp=front;
            front=front->next;
            delete(tmp);
            cnt--;
            if(cnt==0)back=NULL;
            return x;
        }
    }
    int First(){
		if(is_Empty()){
			cout<<"Queue is EMPTY";
			return -1;
		}
		return front->data;
	}
    void print(){
		if(is_Empty()){
			cout<<"queue is empty\n";
			return;
		}
		cout<<"front -> ";
		node* q=front;
		while(q!=NULL){
			cout<<q->data<<" ";
			q=q->next;
		}
		cout<<"<- back"<<endl;
	}
	int Size(){
		return cnt;
	}
};

int sum(Queue& Q){
	int s=0;
	Queue Q2;
	while(!Q.is_Empty()){
		Q2.Enqueue(Q.First());
		s+=Q.Dequeue();
	}
	while(!Q2.is_Empty())
		Q.Enqueue(Q2.Dequeue());

	return s;
}
Queue evenQue(Queue &Q){
	Queue Q2,Q3;
	while(!Q.is_Empty()){
		if(Q.First()%2==0){
			Q2.Enqueue(Q.First());
        }
		Q3.Enqueue(Q.First());
		Q.Dequeue();
	}
	while(!Q3.is_Empty())
		Q.Enqueue(Q3.Dequeue());
	return Q2;
}
// bool palindromeTest(stack<char> s,queue<char> q){   
// 	while(!q.empty()&& !s.empty()){
// 		if(s.top()!=q.front()){
// 			cout<<"Not palindrom"<<endl;
//             return false;
//         }
//         else{
//             q.pop();
//             s.pop();
//         }
//     }
// 	cout<<"palindrom"<<endl;
//     return true;
// }
int main(){
	Queue Q;
	Q.Enqueue(3);
	Q.print();
	Q.Enqueue(6);
	Q.print();
	Q.Enqueue(9);
	Q.print();
	Q.Dequeue();
	Q.print();
	Q.Dequeue();
	Q.print();
	Q.Enqueue(12);
	Q.print();
	Q.Enqueue(7);
	Q.print();
	Q.Enqueue(70);
	Q.print();
	Q.Dequeue();
	Q.print();
	Q.Enqueue(99);
	Q.print();

	cout << "sum = " << sum(Q) << endl;
	Q.print();
	Queue d=evenQue(Q);
	cout<<"Even Queue"<<endl;
	d.print();
	
	//------------- by build in librarys -------------------
	// char c;
    // queue<char> q;
	// stack<char> s;
    // for (int i = 0; i < 3; i++) {
    //     cin >> c;
    //     q.push(c);
	// 	s.push(c);
    // }
    
	// palindromeTest(s,q);

	return 0;
}