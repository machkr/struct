#include "DynQueue.h"
#include "DynStack.h"

int main()
{
	DynQueue<int> x = DynQueue<int>(5);
	DynStack<int> y = DynStack<int>(5);

	x.enqueue(5);
	x.enqueue(4);
	x.enqueue(3);
	x.enqueue(2);
	x.enqueue(1);
	x.enqueue(0);
	x.display();

	y.push(0);
	y.push(1);
	y.push(2);
	y.push(3);
	y.push(4);
	y.push(5);
	y.display();

	cin.get();
	return 0;
}