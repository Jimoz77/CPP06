#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
Data::Data(int id, const std::string& name) : _id(id), _name(name)
{
	std::cout << "Data created with: id: " << _id << " name: " << _name << "\n\n";
}

Data::Data(const Data &other) : _id(other._id), _name(other._name)
{

}

Data& Data::operator=(const Data &other)
{
	if(this != &other)
	{
		_id = other._id;
		_name = other._name;
	}
	return (*this);
}

int Data::getid() const
{
	return(_id);
}

const std::string& Data::getname() const
{
	return(_name);
}

Data::~Data()
{

}
