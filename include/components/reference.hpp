#pragma once

namespace components
{

template <typename component_value>
class reference
{
public:
	class impl
	{
	public:
	   virtual component_value& operator*() = 0;
	   virtual component_value* operator->() = 0;
	};
private:
	impl& impl_value;
public:
	reference(impl& impl_value) :
	   impl_value(impl_value)
	{}

	component_value& operator*()
	{
	   return *impl_value;
	}

	component_value* operator->()
	{
	   return impl_value.operator->();
	}
};

}