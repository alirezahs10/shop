#pragma once

#include "Header.hpp"

class ID
{
private:
	id_t _id;
	string _name;

public:
	ID();
	ID(id_t _input_id, string _input_name);

	void get_id(id_t _input_id);
	void get_name(string _input_name);

	bool operator==(id_t _input_id);
	bool operator==(string _input_name);

	id_t id() const;
	string name() const;
};