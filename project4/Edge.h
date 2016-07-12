#pragma once
#include "Vertex.h"

template <class Type>
class Edge 
{
	private:
		// If directed graph, v1 -> v2
		Vertex<Type> * v1;
		Vertex<Type> * v2;
		int weight;
		
	public:
		Edge(Vertex<Type> * v1_, Vertex<Type> * v2_, int weight_) :
			v1(v1_),
			v2(v2_),
			weight(weight_)
		{}

		Vertex<Type>* getVertex1() { return v1; }
		Vertex<Type>* getVertex2() { return v2; }
		int getWeight() { return weight; }

};
