/*
3.23 Write a function that returns the number of nodes on a circular list,
given a pointer to one of the nodes on the list.
*/

#include <iostream>
using namespace std;

struct node {
	int item;
	node* next;
	node (int x, node* t) {
		item = x;
		next = t;
	}
};

typedef node *link;

link create_circular_list(int length);
void release_circular_list(link p);
int number_of_nodes(link p);

int main() {
	link first = create_circular_list(30);
	cout << "number of nodes: " << number_of_nodes(first) << endl;
	release_circular_list(first);
}

link create_circular_list(int length) {
	if (length <= 0) {
		return NULL;
	}
	link first = new node(0, NULL);
	first->next = first;
	link x = first;
	for (int i = 1; i < length; i++) {
		x = (x->next = new node(i, first));
	}
	return first;
}

void release_circular_list(link p) {
	link temp = NULL;
	while (p->next != NULL && p->next != p) {
		temp = p->next;
		p->next = temp->next;
		delete temp;
	}
	delete p;
	p = NULL;
}

int number_of_nodes(link p) {
	link temp = p;
	int cnt = 0;
	do {
		temp = temp->next;
		cnt++;
	} while (!(temp == p || temp == NULL));
	return cnt;
}

/*
number of nodes: 30
*/
