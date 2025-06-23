#include<iostream>
#include<unistd.h>
#include<queue>
using namespace std;
class Patient{
public:
	Patient(){}
struct Node{
	int data;
	string name;
	int severity;
	Node*next;
};
Node*front=NULL;
Node*rear=NULL;
void Enqueue(int severity,string name,int data){
	Node* temp=new Node();
	temp->data=data;
	temp->severity=severity;
	temp->name=name;
	temp->next=NULL;
	if(rear==NULL){
		front=rear=temp;
		return;
	}
	rear->next=temp;
	rear=temp;
}
void Dequeue(){
	if(front==NULL){
	cout<<"No patients record !"<<endl;
	return;
    }
    Node* temp=front;
    	front=front->next;
    	delete temp;
}
void Display(){
	if(front==NULL){
		cout<<"\nNothing to Display";
		return;
	}
	Node* temp=front;
	while(temp!=NULL){
	cout<<temp->data<<" "<<temp->name<<" "<<temp->severity<<endl;
	temp=temp->next;
	  }
   }
};
int main(){
	int choice,severity;
	int data;
	string name;
    Patient high;
	Patient low;
    do{
    	cout<<"--------Hospital management--------- :";
    	cout<<"\n1.Add patient :";
    	cout<<"\n2.Remove patient data:";
    	cout<<"\n3.Display patient Record :";
    	cout<<"\n4.Exit:";
	    cout<<"\nEnter your choice :";
	    cin>>choice;
	    switch(choice){
	    	case 1:
	    		system("cls");
		        cout<<"Enter patient name :";
            	cin>>name;
				cout<<"Enter severity 1 for Critical Patient || (any num of Non-Critical):";
				cin>>severity;
	    		if(severity==1){
	    			high.Enqueue(severity,name,data);
			}
		        low.Enqueue(severity,name,data);
		        break;
			case 2:
				system("cls");
				if(high.front!=NULL){
				high.Dequeue();
				}
				low.Dequeue();
				break;
			case 3:
				system("cls");
				cout<<"Displaying Data of Patients :";
				cout<<"\nHigh priority Pateints :";
				if(severity==1){
				high.Display();
				}else{
				cout<<"\nLow priority Patients :";
				low.Display();
				}
				break;
			case 4:
				system("cls");
				cout<<"\nExiting";
				for(int i=0;i<3;i++){
					cout<<".";
					sleep(2);
				}
				return 0;
				break;
			default:
				cout<<"\n\n Invalid input !!";
		}
	}while(choice!=4);
}