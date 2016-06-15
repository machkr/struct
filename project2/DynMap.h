#include <iostream>

using namespace std;

template <class K, class V>
class DynStack : public DynContainer {
	public:
		static const int INITIAL_SIZE = 8;
	private:
		V * array;
		int count;
		int initialSize;
		int arraySize;
		int hash(K const &key);
	
	public:
		void insert(K const &key, V const &val);
		V search(K const &key);
		void delete(K const &key);

		int size() const { return count; }
		bool empty() const { return count == 0; }
		int capacity() const { return arraySize; }
		int display() const;
		void clear();
}

