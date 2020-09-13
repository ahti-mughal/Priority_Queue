#include<iostream>
#include"queue.h"

using namespace std;
int main(){
	
	Queue Q;
	int choice;
	do{
	cout << "\n\t||\t\t\tWELCOME USER\t\t||\n" << endl;
	cout << "\t||\t\t(1) ==> EnQueue.\t\t|| "<<endl;
	cout << "\t||\t\t(2) ==> DeQueue.\t\t|| " << endl;
	cout << "\t||\t\t(3) ==> Front.\t\t\t|| " << endl;
	cout << "\t||\t\t(4) ==> IsEmpty.\t\t|| " << endl;
	cout << "\t||\t\t(5) ==> IsFull.\t\t\t|| " << endl;
	cout << "\t||\t\t(6) ==> Find.\t\t\t|| " << endl;
	cout << "\t||\t\t(7) ==> Size.\t\t\t|| " << endl;
	cout << "\t||\t\t(8) ==> Display.\t\t|| " << endl;
	cout << "\t||\t\t(9) ==> Exit.\t\t\t|| " << endl;
	bool r = false; string c;
	do {
	cout << "\n\t\t\tEnter Your Choice ==>> ";
	cin >> ws;
	getline(cin, c);
	int i = 0;
	if (c[i] == '+')
		i++;
	while (i<c.length()) {
		if (!isdigit(c[i]))
		{
			r = true;
			break;
		}
		else {
			r=false;
		}
		i++;
	}
	} while (r);
		choice = stoi(c);
	switch (choice)
	{
	case 1:
		if (!Q.IsFull())
			Q.EnQueue();
		else
			cout << "-> Queue is Full <-";
		break;
	case 2:
		if (!Q.IsEmpty())
			cout<<"Dequeued = [ "<<Q.DeQueue()<<" ]";
		else
			cout << "-> Queue is Empty <-";
		break;
	case 3:
		if(!Q.IsEmpty())
		cout<<"Front [ "<<Q.Front()<<" ]";
		else
			cout << "-> Queue is Empty <-";
		break;
	case 4:
		if (Q.IsEmpty())
		{
			cout << "-> Queue is Empty <-";
		}
		else
		{
			cout << "-> Queue is not Empty <-";	
		}
		break;
	case 5:
		if (Q.IsFull())
		{
			cout << "-> Queue is Full <-";
		}
		else {
			cout << "-> Queue is not Full <-";
		}
		break;
	case 6:
		if (!Q.IsEmpty())
			Q.Find();
		else
			cout << "-> Queue is Empty <-";
		break;
	case 7:
		cout<<"Size = [ "<<Q.Size()<<" ]";
		break;
	case 8:
		Q.Display();
		break;
	case 9:
		Q.Exit();
		break;
	default:
		break;
	}
		
	} while (choice != 9);

	system("pause");


}