#include<iostream>
#include<unistd.h>
#include<conio.h>
#include<queue>
using namespace std;
class VipQueue{
public:
	VipQueue(){}
struct Node{
	int data;
	int Pqueue;
	Node*next;
};
Node*front=NULL;
int size=0;
void Pqueue(){
    if (size>=50) {
        cout << "All rooms are booked! Cannot add more." << endl;
        return;
    }
	int d,q;
	Node*newNode=new Node;
	newNode->data=d;
	newNode->Pqueue=q;
	cout<<"\nEnter your Booking (Priorty):";
	cin>>newNode->data;
	cout<<"Enter your Queue :";
	cin>>newNode->Pqueue;
	newNode->next=NULL;
	Node* temp=front;
	while(temp!=NULL){
		if(temp->data==newNode->data){
		cout<<newNode->data <<" "<<"Room has already booked."<<endl;
		delete newNode;
		return;
		}
	temp=temp->next;
	}
	if(front==NULL||q>front->Pqueue){
		newNode->next=front;
		front=newNode;
	}else{
		Node* temp=front;
		while(temp->next!=NULL&&temp->next->Pqueue>=q){
			temp=temp->next;
		}
		newNode->next=temp->next;
		temp->next=newNode;
	}
	size++;
	cout << "Added:"<<newNode->data<<" (Priority: "<<newNode->Pqueue<< ")"<<endl;
}
void Dequeue(){
	if(front ==NULL){
		cout<<"No seats booked yet"<<endl;
		return;
	}
	Node*temp=front;
		front=front->next;
		cout<<temp->data<<" "<<temp->Pqueue;
		delete temp;
}
void Peek(){
	if(front==NULL){
		cout<<"No Bookings yet"<<endl;
		return;
	}else{
	cout<<front->data<<" "<<front->Pqueue<<endl;
	}
}
void Display(){
	if(front==NULL){
	cout<<"Seats are available"	<<endl;
	return;
	}else{
    Node*temp=front;
    while(temp!=NULL){
    cout<<"\nBooking--Priority : ";
	cout<<temp->data<<" "<<temp->Pqueue;
	temp=temp->next;
	}
 	cout<<endl;
    } 
  }
};
class SQueue{
	public:
	SQueue(){}
	struct Node{
		int data;
		Node*next;
	};
	Node*front=NULL;
	Node*rear=NULL;
	int size=0;
	void Enqueue(){
		Node* newNode=new Node;
		if(size>=50){
			cout<<"All rooms are Booked.Sorry for the inconvenience"<<endl;
			return;
		}
		cout<<"\nEnter your Room no:";
		cin>>newNode->data;
		newNode->next=NULL;
	    Node* temp = front;
        while(temp != NULL){
        if(temp->data == newNode->data){
            cout << "Room " << newNode->data << " has already been booked. Kindly book another one."<<endl;
            delete newNode; 
            return;
        }
        temp = temp->next;
    }
		if(front==NULL){
			front=rear=newNode;
		}else{
			rear->next=newNode;
			rear=newNode;
		}
		size++;
		cout<<"Booked Room is :"<<newNode->data<<" "<<endl;
	}
	void Dequeue(){
		if(front==NULL){
			cerr<<"No Bookings yet"<<endl;
			return;
		}
		        Node*temp=front;
				front=front->next;
				delete temp;
	}
	void Display(){
		if(front==NULL){
			cout<<"No Bookings yet"<<endl;
			return;
		}else{
			Node* temp=front;
			while(temp!=NULL){
				cout<<"\nBooking : ";
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
	}
	void Peek(){
		if(front==NULL){
			cout<<"No Top Booking"<<endl;
			return ;
		}else{
			cout<<front->data;
		}
	}
};
int main(){
	VipQueue q;
	SQueue s;
	cout<<"Select Between (1 for {VIP} or Any Number):"<<endl;
		cout<<"\n--------Welcome to Hotel--------"<<endl;
		cout<<"\nVIP Lounge->              |       Executive Lounge ->";
		cout<<"\n1.Check in :              |       Check in :";
		cout<<"\n2.Return Booking:         |       Return Booking:";
		cout<<"\n3.Show Top     		  |  	  Show Top Booking :";
		cout<<"\n4.Display all Booking :   |       Display all Booking :";
		cout<<"\n5.Return to home :        | 	  Return to home :";
		cout<<"\n6.Exit :                  |  	  Exit :";
	int choice,choice2;
	cout<<"\nEnter Booking Criteria:";
	cin>>choice2;
	if(choice2==1){
	cout<<"Welcome to VIP lounge"<<endl;
	do{
		cout<<"\n--------Welcome to Hotel--------";
		cout<<"\n1.Check in :";
		cout<<"\n2.Return Booking:";
		cout<<"\n3.Show Top Booking :";
		cout<<"\n4.Display all Booking :";
		cout<<"\n5.Returning to Main UI :";
		cout<<"\n6.Exit :";
		cin>>choice;
		switch(choice){
			case 1:
				system("cls");
				cout<<"Loading";
			    for(int i=0;i<3;i++){
			    	cout<<".";
			    	sleep(1);
				}
				q.Pqueue();
				break;
				case 2:
				system("cls");
				cout<<"Loading";
			    for(int i=0;i<3;i++){
			    	cout<<".";
			    	sleep(1);
				}
					q.Dequeue();
					break;
				    	case 3:
				        system("cls");       
							cout<<"Loading";
			  				  for(int i=0;i<3;i++){
			    					cout<<".";
			    					sleep(1);
									}
				    	q.Peek();
				    	break;
					          case 4:
				              system("cls");   
							  cout<<"Loading";          
			  				  for(int i=0;i<3;i++){
			   				   cout<<".";
			    				sleep(1);
									}
						      q.Display();
					          break;
						           case 5 :
								   cout<<"Returning to Main function ";
								   for(int i=0;i<3;i++){
							             cout<<".";
							             sleep(2);
							            }
								   break;
								   case 6:
							       cout<<"\nExiting";
							       for(int i=0;i<3;i++){
						           cout<<".";
							       sleep(2);
							      }
							return 0;
							break;
							default:
								cout<<"\n\nInvalid Input";
								
		    }
	    }while(choice!=6);
    }else{
    	cout<<"Welcome To Executive lounge"<<endl;
    	int choice3;
    	do{
    	cout<<"\n--------Welcome to Hotel--------";
		cout<<"\n1.Check in :";
		cout<<"\n2.Return Booking:";
		cout<<"\n3.Show Top Booking :";
		cout<<"\n4.Display all Booking :";
		cout<<"\n5.Returning to Main UI:";
		cout<<"\n6.Exit :";
		cin>>choice3;
		switch(choice3){
			case 1:	
			system("cls");
			    cout<<"Loading";
			    for(int i=0;i<3;i++){
			    	cout<<".";
			    	sleep(1);
				}
				s.Enqueue();
				break;
				case 2:
					system("cls");
					cout<<"Loading";
			    for(int i=0;i<3;i++){
			    	cout<<".";
			    	sleep(1);
				}
					s.Dequeue();	
					break;
					case 3:
						system("cls");		
						cout<<"Loading";
			    for(int i=0;i<3;i++){
			    	cout<<".";
			    	sleep(1);
				}
						s.Peek();
						break;
						case 4:
							system("cls");	
							cout<<"Loading";		
			    for(int i=0;i<3;i++){
			    	cout<<".";
			    	sleep(1);
				}
							s.Display();
							break;
						      	case 5:
						      		cout<<"Returning to main ";
						      		for(int i=0;i<3;i++){
							             cout<<".";
							             sleep(2);
							            }
									   break;
									         case 6:
						     	             cout<<"\nExiting";
						    	             for(int i=0;i<3;i++){
							                 cout<<".";
							                 sleep(2);
							                 }
							                 return 0; 
							                 break;
							                     default:
							        	         cout<<"\n\nInvalid input !";
		    }
		}while(choice3!=6);
	}
}