#include "Main.hpp"

void scan_product(vector<Product>& product)
{
	id_t product_id, customer_id;
	string product_name, product_factory;

	price_t unit_buy_price; // bar asase rial
	price_t unit_sell_price; // koli ,na takhfif

	count_t count_of_buy, count_of_exist, count_of_off_sell, all_count, customer_count;
	vector<pair_t> customer_list;

	string made_time;
	time_t remainder_time; // bar asase rooz


	count_t customer_need;
	fstream all_products, product_file;
	string temp_string, code_kala, tarikh, file_address, file_directory;
	size_t i, j, temp_num;

	file_directory = "DataBase/Product/";
	all_products.open("DataBase/Product/Product.txt", ios::in);
	all_products >> temp_string >> all_count;

	if (all_count)
	{
		product.reserve(all_count);

		all_products >> temp_string >> temp_string >> temp_string;
		for (i = 0; i < all_count; ++i)
		{
			all_products >> temp_num >> product_id;
			
			file_address = file_directory + to_string(product_id) + ".txt";

			product_file.open(file_address, ios::in);
			product_file >>
				temp_string >> product_id >>
				temp_string >> product_name >>
				temp_string >> product_factory >>
				temp_string >> made_time >>
				temp_string >> remainder_time >>
				temp_string >> count_of_buy >>
				temp_string >> count_of_exist >>
				temp_string >> unit_buy_price >>
				temp_string >> unit_sell_price >>
				temp_string >> count_of_off_sell;
			
			product_file >> temp_string >> temp_string >> customer_count;
			if (customer_count)
			{
				customer_list.clear();
				customer_list.reserve(customer_count);
				product_file >> temp_string >> temp_string >> temp_string;
				for (j = 0; j < customer_count; ++j)
				{
					product_file >> temp_num >> customer_need >> customer_id;
					customer_list.push_back(pair_t(customer_need, customer_id));
				}
			}
			
			product.push_back(Product(product_id, product_name, product_factory, count_of_buy, count_of_exist,
				count_of_off_sell, unit_buy_price, unit_sell_price, Time(made_time), remainder_time, customer_list));

			product_file.close();
		}
	}
	all_products.close();
}

void sign_product(vector<Product>& product)
{
	id_t product_id;
	string product_name, product_factory;

	price_t unit_buy_price; // bar asase rial
	price_t unit_sell_price; // koli ,na takhfif

	count_t count_of_buy, count_of_exist, count_of_off_sell;
	vector<pair_t> customer_list;

	string made_time;
	time_t remainder_time; // bar asase rooz


	fstream all_products, product_file;
	string temp_string, code_kala, tarikh, file_address, file_directory;
	

	size_t n;
	cout << "<< bejaye fasele az \"_\" estefadeh konid! >>" << endl;
	cout << "Tedad kala jadid: ";
	cin >> n;
	cout << "____________________" << endl;
	for (size_t i(0); i < n; ++i)
	{
		cout << "Num # " << i << endl;
		cout << "Code kala: ";
		cin >> product_id;
		cout << endl << "Name kala: ";
		cin >> product_name;
		cout << endl << "Name karkhaneh tolid konande: ";
		cin >> product_factory;
		cout << endl << "Tarikh tolid (yyyy/mm/dd): ";
		cin >> made_time;
		cout << endl << "Modat engheza (bar asas rooz): ";
		cin >> remainder_time;
		cout << endl << "Tedad khridari shode: ";
		cin >> count_of_buy;
		cout << endl << "Tedad mojood dar anbar: ";
		cin >> count_of_exist;
		cout << endl << "Gheymat kharid: ";
		cin >> unit_buy_price;
		cout << endl << "Gheymat foroosh: ";
		cin >> unit_sell_price;
		cout << endl << "Tedad foroosh takhfifdar: ";
		cin >> count_of_off_sell;
		cout << "____________________" << endl;
		product.push_back(Product(product_id, product_name, product_factory, count_of_buy, count_of_exist,
				count_of_off_sell, unit_buy_price, unit_sell_price, Time(made_time), remainder_time));
	}
}

void change_product(vector<Product>& product)
{
	id_t product_id;
	string product_name, product_factory;

	price_t unit_buy_price, unit_sell_price;

	count_t count_of_buy, count_of_exist, count_of_off_sell;

	string made_time;
	time_t remainder_time; // bar asase rooz

	vector<Product>::iterator item;
	size_t index;
	
	cout << "<< bejaye fasele az \"_\" estefadeh konid! >>" << endl;
	cout << "Code kala: ";
	cin >> product_id;

	item = find(product.begin(), product.end(), product_id);
	if (item == product.end())
	{
		printf("Kala moredenazar peyda nashod!\n");
	}
	else
	{
		index = item - product.begin();
		cout << endl << "Name kala(" << item->name() << "): ";
		cin >> product_name;
		cout << endl << "Name karkhaneh tolid konande (" << item->product_factory() << "): ";
		cin >> product_factory;
		cout << endl << "Tarikh tolid (yyyy/mm/dd) (" << item->made_time() << "): ";
		cin >> made_time;
		cout << endl << "Modat engheza (bar asas rooz) (" << item->remainder_time() << "): ";
		cin >> remainder_time;
		cout << endl << "Tedad khridari shode (" << item->count_of_buy() << "): ";
		cin >> count_of_buy;
		cout << endl << "Tedad mojood dar anbar (" << item->count_of_exist() << "): ";
		cin >> count_of_exist;
		cout << endl << "Gheymat kharid (" << item->unit_buy_price() << "): ";
		cin >> unit_buy_price;
		cout << endl << "Gheymat foroosh (" << item->unit_sell_price() << "): ";
		cin >> unit_sell_price;
		cout << endl << "Tedad foroosh takhfifdar (" << item->count_of_off_sell() << "): ";
		cin >> count_of_off_sell;
		product[index] = Product(product_id, product_name, product_factory, count_of_buy, count_of_exist,
				count_of_off_sell, unit_buy_price, unit_sell_price, Time(made_time), remainder_time, item->customer_list());

	}	
}
