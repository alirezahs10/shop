#include "ID.hpp"

class Customer : public ID
{
private:
	count_t _count_of_given;
	count_t _count_of_not_given;
	price_t _remainder_cost;
	vector<pair_t> _product_list;

public:
	Customer(id_t _input_id, string _input_name,
		count_t _count_of_given, count_t _count_of_not_given,
		price_t _input_remainder_cost);

	Customer(id_t _input_id, string _input_name,
		count_t _count_of_given, count_t _count_of_not_given,
		price_t _input_remainder_cost,
		vector<pair_t> _input_product_list);

	count_t count_of_given();
	count_t count_of_not_given();
	price_t remainder_cost();
	pair_t product_list(size_t _index);
	vector<pair_t> product_list();
};
