#pragma once

#include "ID.hpp"

class Product : public ID 
{
private:
	string _product_factory;

	price_t _unit_buy_price; // bar asase rial
	price_t _unit_sell_price; // koli ,na takhfif

	count_t _count_of_buy;
	count_t _count_of_exist;
	count_t _count_of_off_sell;
	vector<pair_t> _customer_list;

	Time _made_time;
	time_t _remainder_time; // bar asase rooz
public:
	Product(id_t _input_id, string _input_name, string _input_product_factory,
		count_t _input_count_of_buy, count_t _input_count_of_exist, count_t _input_count_of_off_sell,
		price_t _input_unit_buy_price, price_t _input_unit_sell_price,
		Time _input_made_time, time_t _input_remainder_time);

	Product(id_t _input_id, string _input_name, string _input_product_factory,
		count_t _input_count_of_buy, count_t _input_count_of_exist, count_t _input_count_of_off_sell,
		price_t _input_unit_buy_price, price_t _input_unit_sell_price,
		Time _input_made_time, time_t _input_remainder_time,
		vector<pair_t> _input_customer_list);


	string product_factory();

	price_t unit_buy_price(); // bar asase rial
	price_t unit_sell_price(); // koli ,na takhfif

	count_t count_of_buy();
	count_t count_of_exist();
	count_t count_of_off_sell();

	pair_t customer_list(size_t _index);
	vector<pair_t> customer_list();

	string made_time();
	time_t remainder_time(); // bar asase rooz
};