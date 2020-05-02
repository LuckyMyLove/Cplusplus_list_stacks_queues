#include <iostream>

using namespace std;


struct node {
	int val;
	node* next;
};


void add(node*& H, int x) {
	node* p = new node;
	p->val = x;
	p->next = H;
	H = p;
}


void show(node* H) {
	node* p = H;
	//cout << "HEAD->";

	while (p != NULL) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}


void del_x(node*& H, int x) { //Usuwanie elementu o warto�ci listy jednostronnie wi�zanej

	if (H != NULL)
	{
		node* p = H;

		if (H->val == x)
		{
			H = p->next;
			delete p;
		}
		else
		{
			while (p->next != NULL && p->next->val != x)
				p = p->next;

			if (p->next != NULL) {
				node* p1 = p->next;
				p->next = p1->next;
				delete p1;
			}
		}
	}
}


void DelListElement(node*& H) { //Usuwanie pierwszego elementu
	if (H != NULL) {
		node* p = H;
		H = p->next;
		delete p;
	}
}


void del_x2(node*& H, int x) { //Usuwanie elementu o warto�ci listy jednostronnie wi�zanej

	if (H != NULL) {

		if (H->val == x) {
			DelListElement(H);
		}

		else {
			node* p = H;
			while (p->next != NULL && p->next->val != x) {
				p = p->next;
				if (p->next != NULL) {
					DelListElement(p->next);
				}
			}
		}
	}
}




//Stack

void push(node*& H, int x) {
	node* p = new node;
	p->val = x;
	p->next = H;
	H = p;
}

void pop(node*& H) {
	if (H != NULL) {
		node* p = H;
		H = p->next;
		delete p;
	}
}


//Queue
void enqueue(node*& Q, node*& T, int x) {
	node* p = new node;
	p->val = x;
	p->next = NULL;

	if (Q == NULL) Q = T = p;
	else {
		T->next = p;
		T = T->next;
	}

}

void dequeue(node*& Q, node*& T) {
	if (Q != NULL) {
		node* p = Q;
		Q = Q->next;
		delete p;
	}
	if (Q == NULL) T = Q;
}

void top(node*& Q) {
	if (Q != NULL) cout << Q->val << endl;
}



//Laboratoria 1 - Zadanie domowe
float countAverage(node* H) { //4. Obliczanie �redniej na stosie + 6. Oblicz warto�� �redni� na li�cie jednostronnie wi�zanej.
	node* p = H;
	float allValues = 0;
	float allElements = 0;

	while (p != NULL) {
		allValues += p->val;
		++allElements;
		p = p->next;
	}
	return allValues / allElements;
}


void del_all_x(node*& H, int x) { //5. Usuwanie wszyskich elelement�w o wskazanej warto�ci w li�cie jednostronnie wi�zanej
	if (H != NULL) {

		node* p = H;
		do{
			if (p->next->val == x) {
				DelListElement(p->next);
				continue;
			}
			p = p->next;
		} while (p->next != NULL);

		if(H->val == x) DelListElement(H);
	}
}

void del_highersThanAverge(node*& H) { //7. Usuwanie wszyskich elelement�w wi�kszych ni� �rednia
	float averge = countAverage(H);
	if (H != NULL) {

		node* p = H;
		do {
			if (p->next->val > averge) {
				DelListElement(p->next);
				continue;
			}
			p = p->next;
		} while (p->next != NULL);

		if (H->val > averge) DelListElement(H);
	}

}



void copyElements(node*& H) { //8. Kopiowanie elementu za siebie
	if (H != NULL) {
		node* p = H;

		while (p != NULL)
		{
			node* p1 = new node;
				p1->next = p->next;
				p1->val = p->val;
				p->next = p1;
				p = p->next->next;
		}
	}
}

void copyElementsAsValue(node*& H) { //9. Kopiowanie elementu za siebie tyle razy w zale�no�ci od warto�ci elementu
	if (H != NULL) {
		node* p = H;

		while (p != NULL)
		{
			for (int i = 0; i < p->val-1; i++) {
				node* p1 = new node;
				p1->next = p->next;
				p1->val = p->val;
				p->next = p1;
				p = p->next;
			}
			p = p->next;
		}
	}
}
//Laboratoria 1 - Zadanie domowe - KONIEC


//Laboratoria 2 - Zadania z zaj��
void delEverySecond(node*& H) { //Zadanie 1: Usuwanie co drugiego elementu (Zaczynaj�c od pierwszego)
	if (H != NULL && H->next != NULL) {
		node* p = H;

		while (p->next != NULL && p->next->next != NULL) {
			p = p->next;
			node* p1 = p->next;
			p->next = p1->next;
			delete p1;
		}
		DelListElement(H);
	}
}

void copyElementsIfEven(node*& H) { //Zadanie 2:  Kopiowanie elementu za siebie je�li jest parzysty
	if (H != NULL) {
		node* p = H;

		while (p != NULL)
		{
			if (p->val % 2 == 0) {
				node* p1 = new node;
				p1->next = p->next;
				p1->val = p->val;
				p->next = p1;
				p = p->next;
			}
			p = p->next;
		}
	}
}

void delEveryEven(node*& H) {  //3. Usuni�cie ka�dego parzystego elementu.
	if (H != NULL) {
		add(H, 0); //Wartownik
		node* p = H;
		do {
			if (p->next->val % 2 == 0) {
				node* p1 = p->next;
				p->next = p1->next;
				delete p1;
				continue;
			}

			p = p->next;
		} while (p->next != NULL);
		DelListElement(H); //Usuni�cie wartownika
	}
}


void changeXwithXNext(node*& H, int x) //Zadanie 4. Zamie� X ze swoim nast�pnikiem
{
	if (H != NULL && H->next != NULL)
	{
		add(H, 0); //Wartownik
		node* p = H;

		do {
			if (p->next->val == x) {
				node* p1 = p;
				node* p2 = p->next;

				p1->next = p2->next;
				p2->next = p2->next->next;
				p1->next->next = p2;
				p1 = p1->next;
				break;
			}

			p = p->next;
		} while (p->next != NULL);
		DelListElement(H); //Usuni�cie wartownika
	}
}

//Laboratioria 2 - Zadanie domowe
void reverseList(node*& H) { //Funkcja pomocnicza, wiele razy u�ywanana w zadaniach poni�ej
	node* p = NULL;
	while (H != NULL) {
		add(p, H->val);
		H = H->next;
	}
	H = p;
}

void delBetweenXandY(node*& H, int x, int y) {  //Usu� elementy pomi�dzy X i Y
	if (H != NULL && H->next != NULL) {
		node* p = H;

		do {
			if (p->val == x) {
				if (p->next->val == y) break;

				node* p1 = p->next;
				p->next = p1->next;
				delete p1;
				continue;
			}


			p = p->next;
		} while (p->next != NULL);
	}
}

void moveBetweenXandYToEnd(node*& H, int x, int y) {  //Przesu� wszystko pomi�dzy X i Y na koniec
	if (H != NULL && H->next != NULL) {
		add(H, 0);
		node* p = H;
		node* copy = NULL;

		do {
			if (p->val == x) {
				if (p->next->val == y) break;
				add(copy, p->next->val);

				node* p1 = p->next;
				p->next = p1->next;
				delete p1;
				continue;
			}


			p = p->next;
		} while (p->next != NULL);
		while (p->next != NULL) { p = p->next; }
		reverseList(copy);
		p->next = copy;

		DelListElement(H);
	}
}

void copyReversedToEnd(node*& H) {  //Skopiuj list� na koniec w odrwotnej kolejno�ci
	if (H != NULL) {

		node* p = H;
		node* copy = p;

		reverseList(copy);
		while (p->next != NULL) { p = p->next; }
		p->next = copy;

	}
}

void moveHigherToTheStart(node*& H) {  //Znajd� maksymalny element na li�cie i przenie� go na pocz�tek
	if (H != NULL && H->next != NULL) {
		add(H, 0);
		node* p = H;
		float max = 0;

		while (p->next != NULL) {
			p = p->next;
			if (p->val > max) max = p->val;
		}

		p = H;

		do {
			if (p->next->val == max) {
				node* p1 = p->next;
				p->next = p1->next;
				delete p1;
				continue;
			}

			p = p->next;
		} while (p->next != NULL);

		DelListElement(H);
		add(H, max);
	}
}

void changeFirstWithLast(node*& H) { //Zamie� element pierwszy z ostatnim na li�cie
	if (H != NULL && H->next != NULL) {
		add(H, 0);
		node* p = H;
		float first = p->next->val, last = 0;

		while (p->next != NULL) {
			last = p->next->val;
			p = p->next;
		}

		p = H;

		do {
			if (p->val == 0 && p->next->val == first) p->next->val = last;
			else if (p->next->val == last) p->next->val = first;

			p = p->next;
		} while (p->next != NULL);


		DelListElement(H);
	}
}

//Laboratoria 2 - KONIEC

//Laboratioria 3 
void evenToEnd(node*& H) {  //Je�li suma dw�ch liczb jest parzysta, przenosimy je na koniec
	if (H != NULL && H->next != NULL) {
		add(H, 0);
		node* p = H;
		node* p1 = NULL;

		do {
			if ((p->next->val + p->next->next->val)% 2 == 0){
				add(p1, p->next->val);
				add(p1, p->next->next->val);

				node* p2 = p->next;
				p->next = p2->next;
				delete p2;

				p2 = p->next;
				p->next = p2->next;
				delete p2;
				continue;
			}

			p = p->next;
		} while (p->next != NULL && p->next->next != NULL);

		reverseList(p1);
		p->next->next = p1;
		DelListElement(H);
	}
}


void fromHigherToLower(node*& H) {   //Sortowanie - od najwi�kszej do najmniejszej
	if (H != NULL) {
		node* p = H;
		H = NULL;
		moveHigherToTheStart(p);
		add(H, p->val);

		while (p->next != NULL) {
			p = p->next;
			moveHigherToTheStart(p);
			add(H, p->val);		
		} 

		reverseList(H);
	}
}

//Laboratioria 3 - Zadanie domowe

void H1_x_H2(node*& H) {  //1. H1 = H<x, H2 = H>2, wynik -> H1 -> x -> H2
	if (H != NULL) {
		int x = H->val;
		node* p = H;
		node* H1 = NULL;
		node* H2 = NULL;

		while (p->next != NULL) {
			p = p->next;
			if (p->val < x)add(H1, p->val);
			if (p->val > x)add(H2, p->val);
		}

		p = H2;
		add(p, x);
		add(p, H1->val);

		while (H1->next != NULL) {
			H1 = H1->next;
			add(p, H1->val);
		}
		H = p;
	}
}



void avergeToEnd(node*& H) {  //2. Elementy wi�ksze od �redniej na koniec listy

	if (H != NULL && H->next != NULL) {
		float averge = countAverage(H);
		cout << "Srednia: " << averge << endl;
		add(H, 0);
		node* p = H;
		node* copy = NULL;

		do {
			if (p->next->val > averge) {
				add(copy, p->next->val);

				node* p1 = p->next;
				p->next = p1->next;
				delete p1;
				continue;
			}


			p = p->next;
		} while (p->next != NULL);
		while (p->next != NULL) { p = p->next; }
		reverseList(copy);
		p->next = copy;

		DelListElement(H);
	}
}

void deleteFibonacci(node*& H) {  //3. Usun�� wszystkie elementy kt�re wchodz� w sk�ad element�w ci�gu Fibonnaciego
	if (H != NULL) {
		add(H, 0);
		node* p = H;
		int a = 0, b = 1;


		do {
			for (int i = 0; i <= 10; i++)
			{
				b += a; 
				a = b - a;

				if (p->next->val == b && p->next->next != NULL) {		
						node* p1 = p->next;
						p->next = p1->next;
						delete p1;
						i = 1; a = 0, b = 1;
				}
			}

			p = p->next;
			a = 0, b = 1;
		} while (p->next != NULL);	

		DelListElement(H);
	}
}


//Laboratoria 3 - KONIEC