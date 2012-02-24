#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct queueNode {
int data;
 struct queueNode *nextPtr; };

typedef struct queueNode node;
typedef queueNode *queunodeptr;
 
 /* function prototypes */
void printQueue(queunodeptr);
 int isEmpty(queunodeptr);
 char dequeue(queunodeptr *, queunodeptr *);//видалити вузол з черги
 void enqueue (queunodeptr *, queunodeptr *, char);//поставити вузол у чергу
 void instructions (void);
using namespace std;
int main () {
	queunodeptr headPtr = NULL, tailPtr = NULL;
	int choice;
	int item;
	instructions ();
	cout<<"? ";
	cin>>choice;
	while (choice !=3) {
		switch(choice) {
		case 1 :
			cout<<"Enter a value: ";
			cin>>item;
			enqueue(&headPtr, &tailPtr, item);
			printQueue(headPtr);
			break;
		case 2 :
			if (! isEmpty(headPtr)) {
				item = dequeue(&headPtr, &tailPtr);
				cout<<item<<" has been dequeued."<<endl;
			}
			printQueue(headPtr);
            break;
		default:
			cout<<"Invalid choice."<<endl<<endl;
			instructions(); 
			break; }
		cout<<"?";
		cin>>choice;}
		cout<<"End of run."<<endl;
		return 0;
}

void instructions(void)
{
	cout<<"Enter your choice:\n"
   " 1 to add an item to the queue\n" 
   " 2 to remove an item from the queue\n" " 3 to end\n"; }

void enqueue(queunodeptr *headPtr, queunodeptr *tailPtr,char value) {
	queunodeptr newPtr;
	newPtr =new node;// створення нового вузла
	if (newPtr != NULL) { 
		newPtr->data = value; //присвоєння значееня яке необхідно поставити у чергу
		newPtr->nextPtr = NULL;
 if (isEmpty(*headPtr))//перевірка чи черга пуста
	 *headPtr = newPtr; 
 else
    (*tailPtr)->nextPtr = newPtr;
     *tailPtr = newPtr; } 
	else
	cout<<value<<" not inserted. No memory available."<<endl;
 }

char dequeue(queunodeptr *headPtr, queunodeptr *tailPtr) {//функція видаляє перший вузол з черги
	char value;
	queunodeptr tempPtr;
    value = (*headPtr)->data;//зберегти дані
    tempPtr = *headPtr;// звільнення вільної пам'яті
    *headPtr = (*headPtr)->nextPtr;//*headPtr вказує на новий перший вузол черги
	if (*headPtr == NULL) *tailPtr = NULL;// якщо *headPtr вказує на 0 встановити *tailPtr на 0
	free(tempPtr); // вивільнити блок пам'яті на який вказує tempPtr
	return value; }

int isEmpty(queunodeptr headPtr) {
	return headPtr == NULL; }

void printQueue(queunodeptr currentPtr) {
	if (currentPtr == NULL)

		cout<<"Queue is empty."<<endl<<endl;
	else {
cout<<"The queue is : "<<endl;
 while (currentPtr != NULL) {
	 cout<< currentPtr->data<<"-->";
	 currentPtr = currentPtr->nextPtr;	 }
 cout<<"NULL"<<endl<<endl; }
}
