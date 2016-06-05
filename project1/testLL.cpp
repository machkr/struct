#include <iostream>
#include "CyclicLinkedList.h"

using namespace std;

int main() {
    CyclicLinkedList<int> * ll = new CyclicLinkedList<int>();
	cout << "Created LinkedList" << endl;
    ll->push_back(2);
    cout << "\npush_back(2)" << endl;
    cout << "front: " << ll->front() << endl;
    cout << "back: " << ll->back() << endl;

    ll->push_back(3);
    cout << "\npush_back(3)" << endl;
    cout << "front: " << ll->front() << endl;
    cout << "back: " << ll->back() << endl;

    ll->push_front(1);
    cout << "\npush_front(1)" << endl;
    cout << "front: " << ll->front() << endl;
    cout << "back: " << ll->back() << endl;

    ll->push_front(1);
    cout << "\npush_front(1)" << endl;
    cout << "front: " << ll->front() << endl;
    cout << "back: " << ll->back() << endl;

    cout << "\ncount(1): " << ll->count(1) << endl;
    cout << "Size before erase: " << ll->getSize() << endl;
    cout << "erase(1): " << ll->erase(1) << endl;
    cout << "Size after erase: " << ll->getSize() << endl;

    cout << "front: " << ll->front() << endl;
    cout << "back: " << ll->back() << endl;
	
    return 0;
}
