#include "ID.hpp"

ID::ID()
	:
	_id(0), _name("")
{}

ID::ID(id_t _input_id, string _input_name)
	:
	_id(_input_id), _name(_input_name)
{}

void ID::get_id(id_t _input_id)
{
	_id = _input_id;
}

void ID::get_name(string _input_name)
{
	_name = _input_name;
}

bool ID::operator==(id_t _input_id)
{
	return _id == _input_id;
}

bool ID::operator==(string _input_name)
{
	return _name == _input_name;
}

id_t ID::id() const
{
	return _id;
}

string ID::name() const
{
	return _name;
}