#include<string>
#include<iostream>
using namespace std;
class Queue
{
public:

	void EnQueue();
	string DeQueue();
	string Front();
	bool IsEmpty();
	bool IsFull();
	void Find();
	int Size();
	void Display();
	void Exit();


	Queue();
	~Queue(){

	}

private:

	string** A;
	int front;
	int rear;
	int max;
	int size;
	int data;
	int priority;



};