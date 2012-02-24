#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<stdarg.h>
struct queueNode {
int data;
 struct queueNode *nextPtr; };

typedef struct queueNode node;
typedef queueNode *queunodeptr;
 
 /* function prototypes */
void printQueue(queunodeptr,bool flag=0);
 int isEmpty(queunodeptr);
 char dequeue(queunodeptr *, queunodeptr *);//�������� ����� � �����
 void enqueue (queunodeptr *, queunodeptr *, char);//��������� ����� � �����
  void enqueue (queunodeptr *, queunodeptr *, int);
 void instructions (void);
 void ( *pointer )(void);
 int f(int n,int a, ...);
using namespace std;
int main () {
	queunodeptr headPtr = NULL, tailPtr = NULL;
	
	int item;
	int choice;
	char choice_push;
	char value1;
	cout<<"What do you want to enter integer or char (i/c)";
	cin>>choice_push;
	if(choice_push=='c'){
	pointer = &instructions; /* ����� ����� ������� */
pointer();
	cout<<"? ";
	cin>>choice;
	while (choice !=4) {
		switch(choice) {
		case 1 :
			cout<<"Enter a value: ";
			cin>>choice_push;
			enqueue(&headPtr, &tailPtr,choice_push);
			printQueue(headPtr,1);
			break;
		case 2 :
			if (! isEmpty(headPtr)) {
				choice_push = dequeue(&headPtr, &tailPtr);
				cout<<choice_push<<" has been dequeued."<<endl;
			}
			printQueue(headPtr,1);
            break;
		default:
			cout<<"Invalid choice."<<endl<<endl;
			pointer = &instructions; /* ����� ����� ������� */
pointer();
			break; }
		cout<<"?";
		cin>>choice;}
		cout<<"End of run."<<endl;
	}else{
		pointer = &instructions; /* ����� ����� ������� */
pointer();
	cout<<"? ";
	cin>>choice;
	while (choice !=4) {
		switch(choice) {
		case 1 :
			cout<<"Enter a value: ";
			cin>>item;
			enqueue(&headPtr, &tailPtr,item);
			printQueue(headPtr);
			break;
		case 2 :
			if (! isEmpty(headPtr)) {
				item = dequeue(&headPtr, &tailPtr);
				cout<<item<<" has been dequeued."<<endl;
			}
			printQueue(headPtr);
            break;
			case 3:cout<<"Counting sum of 5 elements :8,3,4,5,6"<<endl;
			value1=f(5,8,3,4,5,6);
			enqueue(&headPtr, &tailPtr,	value1);
			printQueue(headPtr);
			break;
		default:
			cout<<"Invalid choice."<<endl<<endl;
			pointer = &instructions; /* ����� ����� ������� */
pointer();
			break; }
		cout<<"?";
		cin>>choice;}
		cout<<"End of run."<<endl;
	}
		return 0;
}

void instructions(void)
{
	cout<<"Enter your choice:\n"
   " 1 to add an item to the queue\n" 
   " 2 to remove an item from the queue\n"  "3 sum of elements\n"
		"4 to end program\n"; }

void enqueue(queunodeptr *headPtr, queunodeptr *tailPtr,char value) {
	queunodeptr newPtr;
	newPtr =new node;// ��������� ������ �����
	if (newPtr != NULL) { 
		newPtr->data = static_cast<int>(value); //��������� �������� ��� ��������� ��������� � �����
		newPtr->nextPtr = NULL;
 if (isEmpty(*headPtr))//�������� �� ����� �����
	 *headPtr = newPtr; 
 else
    (*tailPtr)->nextPtr = newPtr;
     *tailPtr = newPtr; } 
	else
	cout<<value<<" not inserted. No memory available."<<endl;
 }
void enqueue(queunodeptr *headPtr, queunodeptr *tailPtr,int value) {
	queunodeptr newPtr;
	newPtr =new node;// ��������� ������ �����
	if (newPtr != NULL) { 
		newPtr->data = value; //��������� �������� ��� ��������� ��������� � �����
		newPtr->nextPtr = NULL;
 if (isEmpty(*headPtr))//�������� �� ����� �����
	 *headPtr = newPtr; 
 else
    (*tailPtr)->nextPtr = newPtr;
     *tailPtr = newPtr; } 
	else
	cout<<value<<" not inserted. No memory available."<<endl;
 }
char dequeue(queunodeptr *headPtr, queunodeptr *tailPtr) {//������� ������� ������ ����� � �����
	char value;
	queunodeptr tempPtr;
    value = (*headPtr)->data;//�������� ���
    tempPtr = *headPtr;// ��������� ����� ���'��
    *headPtr = (*headPtr)->nextPtr;//*headPtr ����� �� ����� ������ ����� �����
	if (*headPtr == NULL) *tailPtr = NULL;// ���� *headPtr ����� �� 0 ���������� *tailPtr �� 0
	free(tempPtr); // ��������� ���� ���'�� �� ���� ����� tempPtr
	return value; }

int isEmpty(queunodeptr headPtr) {
	return headPtr == NULL; }

void printQueue(queunodeptr currentPtr,bool flag) {
	if (currentPtr == NULL)

		cout<<"Queue is empty."<<endl<<endl;
	else {
cout<<"The queue is : "<<endl;
 while (currentPtr != NULL) {
	 if(flag==true){
			printf("%c -->",currentPtr->data);}
			else{
				cout<< currentPtr->data<<"-->";}
	 currentPtr = currentPtr->nextPtr;	 }
 cout<<"NULL"<<endl<<endl; }
}
int f(int n, int a, ...){
	 va_list p; int sum=0;            //--���������� ���������
    va_start(p, n); int b;           //--������������� ���������
  while(n--)           
    {
		b=va_arg(p,int);
		sum=sum+b;
	}
	va_end(p);
	return sum;
	}
