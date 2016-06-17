#pragma once
class DynContainer { 
	public:
		DynContainer(){};
		~DynContainer(){};
		virtual int size() const = 0;
		virtual bool empty() const = 0;
		virtual int capacity() const = 0;
		virtual void display() const = 0;
		virtual void clear() = 0;
};

