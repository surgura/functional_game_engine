#pragma once

#include "reference.hpp"
#include <list>

namespace components
{

template <typename component_value>
class table
{
public:
	struct row;
	class reference_impl : public reference<component_value>::impl
	{
	   friend class table;
	   typename std::list<row>::iterator container_iter;
	public:
	   reference_impl(typename std::list<row>::iterator container_iter) :
		  container_iter(container_iter)
	   {}

	   component_value& operator*() override
	   {
			return container_iter->value;
	   }

	   component_value* operator->() override
	   {
			return &container_iter->value;
	   }
	};
private:

	struct row
	{
	   component_value value;
	   reference_impl this_ref;
	};

	std::list<row> rows;
public:
	class iterator
	{
	   typename std::list<row>::iterator iter;
	public:
	   iterator(typename std::list<row>::iterator iter) :
		  iter(iter)
	   {}

	   reference<component_value> operator*()
	   {
			return { iter->this_ref };
	   }
	   
	   bool operator !=(iterator const& other)
	   {
			return iter != other.iter;
	   }

	   void operator ++()
	   {
			iter++;
	   }
	};
	
	reference_impl& add(component_value&& item)
	{
	   rows.push_front({ item, { rows.end() } });
	   rows.front().this_ref = { rows.begin() };
	   return rows.front().this_ref;
	}

	void remove(reference_impl& contained_component)
	{
	   rows.erase(contained_component.container_iter);
	}

	iterator begin()
	{
	   return { rows.begin() };
	}

	iterator end()
	{
	   return { rows.end() };
	}
};

}