#include"queue.h"
 Queue::Queue() {
	front = -1;
	rear = -1;
	size = 0;
	max = 0;
	string m;
	do{///while max is less than 1
		 bool r;
		do {//while size is in character
			int i = 0;
			cout << "Enter size of Queue ==> ";
			cin >> m;
			while (i < (m.length())) {
				if (!isdigit(m[i])) {
					r = true;
					break;
				}
				else {
					r = false;
				}
				i++;

			}
		} while (r);//// character check
		if (stoi(m) > 99999)
			cout << "Alert!!!Too Much Big Size"<<endl;
		else
		max = stoi(m);

	} while (max < 1||stoi(m)>99999);//// less than 1 check
	A = new string* [2];
	for (int loop = 0; loop <= 1; loop++) {
		A[loop] = new string [max];
	}
	data = 0;
	priority = 1;
}
void Queue::EnQueue()
{

	if (size == 0) {
		front=(front+1)%max;
	}
	rear = (rear + 1) % max;
	size++;
	//////////////Input data//////////////
	int i = 0; bool r=false;
	string d,p;
	cout << "Enter Data to store in Queue ->";
	getline(cin, d);
	A[data][rear] = d;
	///////////////Input priority////////// 
	do {//while it has character
		i = 0;
		cout << " Enter Priority of this Data ->";
		getline(cin, p);
		if (p[0] == '-'||p[0]=='+') {
			i++;//skip first letter if it is - or +
		}
		while (i < (p.length())) {
			if (!isdigit(p[i])) {
				r = true; 
				break;}
			else if (i == p.length() - 1) {
				if (stoi(p) < 1) {
					cout << "Alert!!! Priority must be Greater than 0\n";
					r = true;
				}
				else
					r = false;
			}
			i++;
		}
	} while (r);
A[priority][rear] = p;
	//////////// Sort ///////////////////////////
	int tr = rear,tr1=rear;
	if (size > 1) {
		for (int loop = 1; loop<=size-1; loop++) {
			if ((--tr1) == -1) 
				tr1 = max - 1;
			if (stoi(A[priority][tr]) <= stoi(A[priority][tr1])) {
				string tp = A[priority][tr1];
				string td = A[data][tr1];
				A[priority][tr1] = A[priority][tr];
				A[data][tr1] = A[data][tr];
				A[priority][tr] = tp;
				A[data][tr] = td;
				if ((--tr) == -1) {
					tr = max - 1;
				}
			}
			else
				break;
		}
	}
	Display();
}
string  Queue::DeQueue()
{
	string y = A[data][front];
	--size;
	if (size > 0)
	front = (front + 1) % max;
	Display();
	return y;
}
string  Queue::Front()
{
	return A[data][front];
}
bool  Queue::IsEmpty()
{
	if (size == 0)
		return true;
	else
		return false;
}
bool  Queue::IsFull()
{
	if (size == max)
		return true;
	else
		return false;
}
void  Queue::Find()
{
	bool flag = true;
	cout << "Enter String to Find from the Queue -> ";
	string fs, p="0";
	getline(cin, fs);
	int tf = front;
	///////looop to check all elements
	for (int loop = 1; loop <= size; loop++) {
		////////////////string characters check//////////
		int length = 0;
		while (length <= fs.length()) {
			if (fs[length] != (A[data][tf])[length])
			{
				flag = false; break;
			}
			else {
				flag = true;
			}
			length++;
		}
		/////////////////////////////////////////
		if (flag) {
			p = A[priority][tf];
			flag = true;
			break;
		}
		else
		tf = (tf + 1) % max;
	}
	if (flag) {
		cout << "\t\t\t->Congratulations<-\nFound " << fs << " Sucessfully!!!\nPriority = [" << p << "]";
	}
	else {
		cout << "Alert!!!Entered String [ "<<fs<<" ] is not Found";
	}
}
int  Queue::Size()
{
	return max;

}
void  Queue::Display()
{
	/////////
	if (!IsEmpty()) {
		int fi = front;
		cout << " Queue\n -> ";
		for (int loop = 1; loop <= size; loop++) {
			cout << A[data][fi] << "[" << A[priority][fi] << "]" << " ";
			fi = (fi + 1) % max;
		}
		cout << " <-" << endl;
	}
	else
		cout << "-> Queue is Empty <-";
}
void  Queue::Exit()
{
	delete[] A;
	cout << "\n\n******************* Allah Hafiz ******************* \n\n";
}