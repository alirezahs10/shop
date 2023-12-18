#include "Product.hpp"

Product::Product(id_t _input_id, string _input_name, string _input_product_factory,
    count_t _input_count_of_buy, count_t _input_count_of_exist, count_t _input_count_of_off_sell,
    price_t _input_unit_buy_price, price_t _input_unit_sell_price, Time _input_made_time, time_t _input_remainder_time)
    :
    ID(_input_id, _input_name), _product_factory(_input_product_factory),
    _count_of_buy(_input_count_of_buy), _count_of_exist(_input_count_of_exist), _count_of_off_sell(_input_count_of_off_sell),
    _unit_buy_price(_input_unit_buy_price), _unit_sell_price(_input_unit_sell_price),
    _made_time(_input_made_time), _remainder_time(_input_remainder_time)
{
}

Product::Product(id_t _input_id, string _input_name, string _input_product_factory,
    count_t _input_count_of_buy, count_t _input_count_of_exist, count_t _input_count_of_off_sell,
    price_t _input_unit_buy_price, price_t _input_unit_sell_price, Time _input_made_time, time_t _input_remainder_time,
    vector<pair_t> _input_customer_list)
    :
    ID(_input_id, _input_name), _product_factory(_input_product_factory),
    _count_of_buy(_input_count_of_buy), _count_of_exist(_input_count_of_exist), _count_of_off_sell(_input_count_of_off_sell),
    _unit_buy_price(_input_unit_buy_price), _unit_sell_price(_input_unit_sell_price),
    _made_time(_input_made_time), _remainder_time(_input_remainder_time),
    _customer_list(_input_customer_list)
{
}

string Product::product_factory()
{
    return _product_factory;
}

price_t Product::unit_buy_price()
{
    return _unit_buy_price;
}

price_t Product::unit_sell_price()
{
    return _unit_sell_price;
}

count_t Product::count_of_buy()
{
    return _count_of_buy;
}

count_t Product::count_of_exist()
{
    return _count_of_exist;
}

count_t Product::count_of_off_sell()
{
    return _count_of_off_sell;
}

pair_t Product::customer_list(size_t _index)
{
    return _customer_list[_index];
}

vector<pair_t> Product::customer_list()
{
    return _customer_list;
}

string Product::made_time()
{
    return _made_time.complete();
}

time_t Product::remainder_time()
{
    return _remainder_time;
}
