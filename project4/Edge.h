#pragma once
#include "Vertex.h"

template <class Type>
class Vertex;

template <class Type>
class Edge 
{
	public:
		Vertex<Type> * v;
		double weight;
};
