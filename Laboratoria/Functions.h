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


void del_x(node*& H, int x) { //Usuwanie elementu o wartoœci listy jednostronnie wi¹zanej

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


void del_x2(node*& H, int x) { //Usuwanie elementu o wartoœci listy jednostronnie wi¹zanej

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
float countAverage(node* H) { //4. Obliczanie œredniej na stosie + 6. Oblicz wartoœæ œredni¹ na liœcie jednostronnie wi¹zanej.
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


void del_all_x(node*& H, int x) { //5. Usuwanie wszyskich elelementów o wskazanej wartoœci w liœcie jednostronnie wi¹zanej
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

void del_highersThanAverge(node*& H) { //7. Usuwanie wszyskich elelementów wiêkszych ni¿ œrednia
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

void copyElementsAsValue(node*& H) { //9. Kopiowanie elementu za siebie tyle razy w zale¿noœci od wartoœci elementu
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


//Laboratoria 2 - Zadania z zajêæ
void delEverySecond(node*& H) { //Zadanie 1: Usuwanie co drugiego elementu (Zaczynaj¹c od pierwszego)
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

void copyElementsIfEven(node*& H) { //Zadanie 2:  Kopiowanie elementu za siebie jeœli jest parzysty
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

void delEveryEven(node*& H) {  //3. Usuniêcie ka¿dego parzystego elementu.
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
		DelListElement(H); //Usuniêcie wartownika
	}
}


void changeXwithXNext(node*& H, int x) //Zadanie 4. Zamieñ X ze swoim nastêpnikiem
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
		DelListElement(H); //Usuniêcie wartownika
	}
}

//Laboratioria 2 - Zadanie domowe
void reverseList(node*& H) { //Funkcja pomocnicza, wiele razy u¿ywanana w zadaniach poni¿ej
	node* p = NULL;
	while (H != NULL) {
		add(p, H->val);
		H = H->next;
	}
	H = p;
}

void delBetweenXandY(node*& H, int x, int y) {  //Usuñ elementy pomiêdzy X i Y
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

void moveBetweenXandYToEnd(node*& H, int x, int y) {  //Przesuñ wszystko pomiêdzy X i Y na koniec
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

void copyReversedToEnd(node*& H) {  //Skopiuj listê na koniec w odrwotnej kolejnoœci
	if (H != NULL) {

		node* p = H;
		node* copy = p;

		reverseList(copy);
		while (p->next != NULL) { p = p->next; }
		p->next = copy;

	}
}

void moveHigherToTheStart(node*& H) {  //ZnajdŸ maksymalny element na liœcie i przenieœ go na pocz¹tek
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

void changeFirstWithLast(node*& H) { //Zamieñ element pierwszy z ostatnim na liœcie
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
void evenToEnd(node*& H) {  //Jeœli suma dwóch liczb jest parzysta, przenosimy je na koniec
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


void fromHigherToLower(node*& H) {   //Sortowanie - od najwiêkszej do najmniejszej
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



void avergeToEnd(node*& H) {  //2. Elementy wiêksze od œredniej na koniec listy

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

void deleteFibonacci(node*& H) {  //3. Usun¹æ wszystkie elementy które wchodz¹ w sk³ad elementów ci¹gu Fibonnaciego
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