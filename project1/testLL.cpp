#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList<int> * ll = new LinkedList<int>();
	cout << "Created LinkedList" << endl;
    ll->push_back(2);
    cout << "front: " << ll->front() << endl;
    cout << "back: " << ll->back() << endl;

    ll->push_back(3);
    cout << "front: " << ll->front() << endl;
    cout << "back: " << ll->back() << endl;

    ll->push_front(1);
    cout << "front: " << ll->front() << endl;
    cout << "back: " << ll->back() << endl;

    ll->push_front(1);
    cout << "front: " << ll->front() << endl;
    cout << "back: " << ll->back() << endl;

    cout << "count(1): " << ll->count(1) << endl;
    cout << "Size before erase: " << ll->getSize();
    cout << "erase(1): " << ll->erase(1) << endl;
    cout << "Size after erase: " << ll->getSize();

    return 0;
}
