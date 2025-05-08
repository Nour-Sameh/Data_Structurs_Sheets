#include <iostream>
using namespace std;

class Array{
    private:
        int* arr;
        int cap;
        int last;
    public:
        Array( ){
		arr=new int[100];
		cap=100;
		last=-1;
		}
        Array(int n){
            arr=new int[n];
            cap=n;
            last=-1;
        }
        void makenull(){last=-1;}

        int END(){return last+1;}

        bool isFull(){return last==cap-1;}

        bool isEmpty(){return last==-1;}

        int First(){return 0;}

        int Next(int p){return p+1;}

        int prev(int p){return p-1;}

        int Size(){return END();}

        void Insert(int p,int data){
            if(isFull()){
                cout<<"array is full!\n";
            }
            else if(p<0||p>last+1){
                cout<<"out of range!\n";
            }
            else{
                for(int i=last;i>=p;i--){
                    arr[i+1]=arr[i];
                }
                arr[p]=data;
                last++;
            }
        }

        void Delete(int p){
            if(isEmpty()){
                cout<<"array is already empty!\n";
            }
            else if(p<0||p>last){
                cout<<"out of range!\n";
            }
            else{
                for(int i=p;i<last;i++){
                    arr[i]=arr[i+1];
                }
                last--;
            }
        }

        int Locate(int data){
            for(int i=0;i<=last;i++){
                if(arr[i]==data)
                    return i;
            }
            return -1;
        }

        int locateInRange(int l,int r,int data){
            // if (l > last+1 || l < 0) 
			//     cout << l<<":pos is out of range"<<last; 
		    // if (r > last+1 || l< 0 || r<l) 
			//     cout << l<<":pos is out of range"<<last; 
            for(int i=l;i<=r;i++){
                if(arr[i]==data)
                    return i;
            }
            return -1;
        }

        int retrive(int p){
            if(p<0||p>last){
                cout<<"out of range \t";
                return -1;
            }
            return arr[p];
        }

        void print(){
            for(int i=0;i<=last ;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

Array reverse(Array &a1){
    Array a2(a1.Size());
    int j=0;
    for(int i=a1.END()-1;i>=a1.First();i--,j++){
        a2.Insert(j,a1.retrive(i));
    }
    return a2;
}

void purge(Array &a){//PURGE removes duplicate elements from array a 
    for(int i=a.First();i<a.END();i++){
        for(int j=i+1;j<a.END();j++){
            if(a.retrive(i)==a.retrive(j)){
                a.Delete(j);
                j--;
            }
        }
    }
}

void removeoccur(Array &a,int data){
    int pos=a.Locate(data);
    while(pos!=-1){
        a.Delete(pos);
        pos=a.Locate(data);// for update
    }
}
void split(Array &a,Array &ev,Array &od){
    for(int i=a.First();i<a.END();i++){
        int x=a.retrive(i);
        if(x%2){
            od.Insert(od.END(),x);
        }
        else{
            ev.Insert(ev.END(),x);
        }
    }
}
Array concatinate(Array &a,Array& b){
    Array myarr(a.Size()+b.Size());
    int j=0;
    for(int i=a.First();i<a.END();i++,j++){
        myarr.Insert(j,a.retrive(i));
    }
    for(int i=b.First();i<b.END();i++,j++){
        myarr.Insert(j,b.retrive(i));
    }
    return myarr;
}
int Sum(Array a){
    int sum =0;
    for(int i=a.First();i<a.END();i++){
        sum+=(a.retrive(i));
    }
    return sum;
}
int main(){
	Array l(10);
	//------------------Test Insert---------------------
	l.Insert(l.END(),1);
	l.Insert(l.First(),2);
	l.Insert(l.END(),3);
	l.Insert(l.END(),4);
	l.Insert(l.First(),4);
	//----------------Split
	Array lEven(10),lOdd(10);
	split(l,lEven,lOdd);
	cout<<"all:";
	l.print();
	cout<<"Even:";
	lEven.print();
	cout<<"Odd:";
	lOdd.print();
	
	Array newL=concatinate(lEven,lOdd);
	cout<<"Concatenated Array is:";
	newL.print();
	//-------------------Test locate------------------
	int x=2;
	int pos=l.Locate(x);
	if(pos==-1)
		cout<<x<<" does not exist"<<endl;
	else
		cout<<x<<" found at "<<pos<<endl;
	x=4;
    pos=l.Locate(x);
	if (pos==-1)
		cout<<x<<" does not exist"<<endl;
	else
		cout<<x<<" found at "<<pos<<endl;
	x=100;
    pos=l.Locate(x);
	if (pos==-1)
		cout<<x<<" does not exist"<<endl;
	else
		cout<<x<<" found at "<<pos<<endl;
	
	//----------------------reverse--------------
	Array l2=reverse(l);
	cout<<"Array after reverse:";
	l2.print();
	//-----------------------------------------
	//---------------Purge----------------
	Array L3(10);
	L3.Insert(L3.First(),1);
	L3.Insert(L3.First(),2);
	L3.Insert(L3.First(),1);
	L3.Insert(L3.First(),3);
	L3.Insert(L3.First(),3);
	L3.Insert(L3.First(),2);
	L3.Insert(L3.First(),4);
	L3.Insert(L3.First(),2);
	L3.Insert(L3.First(),6);
	L3.Insert(L3.First(),3);
	cout<<"\nArray before removing all 3: ";
	L3.print();
	removeoccur(L3,3);
	cout<<"\nArray afer removing 3:   ";
	L3.print();
	cout<<"\nArray before purge:   ";
	L3.print();
	purge(L3); 
	cout<<"\nArray after purge:   ";
	L3.print();
	//--------------------------------------------------
	cout<<"#elements in Array is "<< L3.Size()<<endl;
	cout<<"sum "<<Sum(L3)<<endl;
	return 0;
}  