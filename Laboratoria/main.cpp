#include <iostream>
#include "Functions.h"

using namespace std;


int main(){

	//List
	node* L1 = NULL;
	node* L2 = NULL;
	add(L2, 5);

	node* L3 = NULL;
	add(L3, 8);
	add(L3, 5);

	node* L4 = NULL;
	add(L4, 22);
	add(L4, 12);
	add(L4, 8);
	add(L4, 5);
	add(L4, 18);
	add(L4, 5);
	add(L4, 8);
	add(L4, 6);
	add(L4, 3);
	add(L4, 5);

	node* L5 = NULL;
	add(L5, 25);
	add(L5, 8);
	add(L5, 55);

	node* L6 = NULL;
	add(L6,25);
	add(L6,55);
	add(L6,8);

	node* L7 = NULL;
	add(L7, 25);
	add(L7, 75);
	add(L7, 25);	
	add(L7, 55);
	add(L7, 8);

	cout << "Przed uzyciem funkcji: ";
	show(L4);
	cout << endl << "Po uzyciu funkcji: ";
	changeFirstWithLast(L4);
	show(L4);


	//Stack
	//H = NULL;
	//cout << endl << "Stack:" << endl;
	//push(H, 5);
	//push(H, 10);
	//push(H, 15);
	//push(H, 20);
	//show(H);
	//cout << "4. Average of the given elements: " << countAverage(H) << endl; // 4.

	//cout << "8. Coping every element: "; //8.
	//copyElements(H);
	//show(H);

	//cout << endl;
	//H = NULL;
	//push(H, 2);
	//push(H, 3);
	//push(H, 4);
	//show(H);
	//cout << "9. Coping every element that many times as his value: "; //9.
	//copyElementsAsValue(H);
	//show(H);


	//Queue
	//cout << endl << "Queue:" << endl;
	//node* Q = NULL;
	//node* T = NULL;
	//enqueue(Q, T, 10);
	//enqueue(Q, T, 7);
	//top(Q);
	//dequeue(Q, T);
	//top(Q);


	return 0;
	system("PAUSE");
}
