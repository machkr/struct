#pragma once
#include "Vertex.h"

template <class Type>
class Vertex;

template <class Type>
class Edge 
{
	public:
		Vertex<Type> *from;
		Vertex<Type> *to;
		double weight;

		Edge(string name1, string name2, double weight_)
		{
			try { from = vertices.search(name1); }
			catch (const underflow_error& e)
			{
				throw underflow_error("Vertex " + name1 + " cannot be found");
			}

			try { to = vertices.search(name2); }
			catch (const underflow_error& e)
			{
				throw underflow_error("Vertex " + name2 + " cannot be found");
			}

			weight = weight_;
		}

		Edge(Vertex<Type> v1, Vertex<Type> v2, double weight_) : from(v1), to(v2), weight(weight_) {}
};
