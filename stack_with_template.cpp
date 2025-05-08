#include<iostream>
#include<string.h>
using namespace std;

template<typename T>
struct node{
    T element;
    node* next;
};

template<typename T>
class stack{
    node<T>* top;
    int cnt;
public:
    void makenull(){
        top = NULL;
        cnt = 0;
    }
    stack(){
        makenull();
    }
    bool is_empty(){
        return(top==NULL);
    }
    void push(T val){
        node<T>* newnode=new node<T>;
        newnode->element=val;
        newnode->next=top;
        top=newnode;
        cnt++;
    }
    T pop(){
        if(is_empty())return T();
        T val=top->element;
        node<T>* temp=top;
        top=top->next;
        delete(temp);
        cnt--;
        return val;
    }
    T TOP(){
        if(is_empty())return T();
        return top->element;
    }
    void print(){
        node<T>* p=top;
        while(p!=NULL){
            cout<<p->element<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    int size(){
        return cnt;
    }
    
};

bool Balance(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='{'||s[i]=='['||s[i]=='(')st.push(s[i]);
        else{
            if(st.is_empty())return false;
            else if(s[i]=='}'||s[i]==']'||s[i]==')'){
                if(s[i]=='}'&&st.TOP()!='{')return false;
                if(s[i]==')'&&st.TOP()!='(')return false;
                if(s[i]==']'&&st.TOP()!='[')return false;
                st.pop();
            }
            else continue;// if number
        }
    }
    if(st.is_empty())return true;
    return false;
}

void con_to_bin(int x){
    stack<int> st;
    int r;
    while(x!=0){
        r=x%2;
        st.push(r);
        x=x/2;
    }
    while(!st.is_empty()){
        cout<<st.pop();
    }
    cout<<endl;
}
void rerange(stack<int>&st){
    stack<int> ev,od;
    while(!st.is_empty()){
        int x=st.pop();
        if(x%2){
            od.push(x);
        }
        else {
            ev.push(x);
        }
    }
    st.makenull();
    while(!ev.is_empty())st.push(ev.pop());
    while(!od.is_empty())st.push(od.pop());
}
int sum(stack<int>& st) {
	stack<int> st2;
	int s=0;
	while(!st.is_empty()) {
		st2.push(st.TOP());
		s+=st.pop();
	}
    // علشان املاها تاني
	while(!st2.is_empty()) {
		st.push(st2.pop());
	}
	return s;
}

int max(stack<int>& st) {
	stack <int>st2;
	st2.push(st.TOP());
	int mx=st.pop();
	while(!st.is_empty()) {
		st2.push(st.TOP());
		if(mx<st.TOP())
			mx=st.TOP();
		st.pop();
	}

	while(!st2.is_empty()) {
		st.push(st2.pop());
	}

	return mx;
}
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.print();
    cout<<s.pop()<<endl;
    cout<<s.TOP()<<endl;
    s.print();

    string test="{[()]}";
    cout<<(Balance(test)?"Balanced":"Not Balanced")<<endl;
    
	cout << sum(s)<<endl;
	s.print();

	cout << max(s)<<endl;
	s.print();
    return 0;
}
