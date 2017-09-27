//maintain array into linked list and perform basic operations on linked list
#include <iostream>
using namespace std;

struct linklist{
	int data;
	linklist *next;
};

linklist *head = NULL;   //global head pointer

linklist *createnode(int data){
	linklist *newnode = new linklist();
	newnode->data = data;
	newnode->next = NULL;

	return newnode;
}

void createlist(int data){
	linklist *newnode = createnode(data);
	if(head == NULL){
		head = newnode;
		return;
	}	
	else{
		linklist *temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
		return;
	}
}
void insertAtBeg(int data){
	linklist *newnode = createnode(data);
	if(head == NULL)
		head = newnode;
	else{
		newnode->next = head;
		head = newnode;
	}
	return;
}

void insertAtEnd(int data){
	linklist *newnode = createnode(data);
	if(head==NULL){
		head = newnode;
		return;
	}
	else{
		linklist *current = head;
		while(current->next != NULL)
		current = current->next;
	current->next = newnode;
	return;
	}
	
}

void deleteAtBeg(){
	linklist *temp = head;
	head = head->next ;
	delete(temp);
	return;
}

void deleteAtEnd(){
	linklist *current = head;
	while(current->next->next != NULL)
		current = current->next;
	linklist *temp = current->next;
	current->next = NULL;
	delete(temp);
}
int calLenthOfLinklist(){
	linklist *current = head ;
	int lenth = 0 ;
	while(current != NULL){
		lenth++;
		current = current->next ;
	}
	return lenth ; 
} 
void insertAtMid(int data){
	linklist *newnode = createnode(data);
	linklist *current = head ;
	int mid = (calLenthOfLinklist()/2 -1);	 
	while(mid--)
		current = current->next;
	newnode->next = current->next;
	current->next = newnode;
	return; 
}

void deleteAtMid(){
	linklist *current = head;
	int mid = (calLenthOfLinklist()/2 -1);
	while(mid--)
		current = current->next;
	linklist *temp = current->next;
	current->next = current->next->next;
	delete(temp);
}
void display(){
	linklist *temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next ; 
	}
	cout<<endl;
	return;
}

int main(){
	int size, midPosition;
	cout<<"enter size of array\n";
	cin>>size;
	midPosition = size/2 -1 ;
	int array[size];
	cout<<"enter array\n";
	for(int i=0; i<size; i++){
		cin>>array[i];
		createlist(array[i]);
	}
	insertAtBeg(56);
	insertAtEnd(99);
	display();
	deleteAtBeg();
	deleteAtEnd();
	insertAtMid(00);
	display();
	cout<<calLenthOfLinklist()<<endl;
	deleteAtMid();
	display();
	return 0;
}
