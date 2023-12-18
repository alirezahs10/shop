#include "Customer.hpp"

Customer::Customer(id_t _input_id, string _input_name, count_t _input_count_of_given, count_t _input_count_of_not_given, price_t _input_remainder_cost)
    :
    ID(_input_id, _input_name), _count_of_given(_input_count_of_given), _count_of_not_given(_input_count_of_not_given), _remainder_cost(_input_remainder_cost)
{
}

Customer::Customer(id_t _input_id, string _input_name, count_t _input_count_of_given, count_t _input_count_of_not_given, price_t _input_remainder_cost, vector<pair_t> _input_product_list)
    :
    ID(_input_id, _input_name), _count_of_given(_input_count_of_given), _count_of_not_given(_input_count_of_not_given), _remainder_cost(_input_remainder_cost), _product_list(_input_product_list)
{
}

count_t Customer::count_of_given()
{
    return _count_of_given;
}

count_t Customer::count_of_not_given()
{
    return _count_of_not_given;
}

price_t Customer::remainder_cost()
{
    return _remainder_cost;
}

pair_t Customer::product_list(size_t _index)
{
    return _product_list[_index];
}

vector<pair_t> Customer::product_list()
{
    return _product_list;
}
