#pragma once
#include <string>

using namespace std;

template <class Type>
class Vertex 
{
	private:
		string name;
		Type data;
	
	public:
		Vertex(string name_, Type data_) :
			name(name_),
			data(data_)
		{}
		
		string getName() { return name; }

		Type getData() { return data; }

};


