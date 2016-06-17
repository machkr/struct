#pragma once
class DynContainer { 
	public:
		virtual int size() const;
		virtual bool empty() const;
		virtual int capacity() const;
		virtual int display() const;
		virtual void clear();
};

