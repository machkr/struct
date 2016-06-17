#include "DynQueue.h"
#include "DynStack.h"

int main()
{
	DynQueue<int> x = DynQueue<int>(5);
	//DynStack<int> y = DynStack<int>(2);

	x.enqueue(5);
	x.display();
	x.enqueue(4);
	x.enqueue(3);
	x.enqueue(2);
	x.enqueue(1);
	x.enqueue(0);
	x.enqueue(-1);
	x.display();

	x.dequeue();
	x.display();
	x.dequeue();
	x.display();
	x.dequeue();
	x.display();

	x.enqueue(100);
	x.display();

	x.enqueue(100);
	x.enqueue(100);
	x.enqueue(100);
	x.enqueue(7);
	x.display();

	x.erase(100);
	x.display();

	//cout << "Let's see if we can delete all FOUR 100's!!" << endl;
	//x.erase(100);
	//x.display();

	//y.push(1);
	//y.push(0);
	//y.push(1);
	//y.push(0);
	//y.push(1);
	//y.push(0);
	//y.display();

	//y.erase(1);
	//y.display();

	//y.clear();
	//y.display();

	cin.get();
	return 0;
}