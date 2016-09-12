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

		Edge() :
			v(nullptr),
			weight(0)
		{}

		Edge(Vertex<Type>* v_, double weight_) :
			v(v_),
			weight(weight_)
		{}

		Edge(const Edge<Type>& other) :
			v(other.v),
			weight(other.weight)
		{}

		bool operator==(const Edge<Type>& rhs)
		{
			return (v == rhs.v && weight == rhs.weight);
		}

		Edge<Type>& operator=(const Edge<Type>& rhs)
		{
			v = rhs.v;
			weight = rhs.weight;
			return *this;
		}
};
