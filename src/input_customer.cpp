#include "Main.hpp"

void scan_customer(vector<Customer>& customer)
{
	fstream all_customers, customer_file;
	string file_address, file_directory;
	count_t all_count, product_count;
	string temp_string;
	
	id_t customer_id, product_id;
	string customer_name;
	size_t temp_num, i, j;

	count_t count_of_given, count_of_not_given, product_need;
	price_t remainder_cost;
	vector<pair_t> product_list;

	file_directory = "DataBase/Customer/";
	all_customers.open("DataBase/Customer/Customer.txt", ios::in);
	all_customers >> temp_string >> all_count;

	if (all_count)
	{
		all_customers >> temp_string >> temp_string >> temp_string;
		for (i = 0; i < all_count; ++i)
		{
			all_customers >> temp_num >> customer_id;

			file_address = file_directory + to_string(customer_id) + ".txt";

			customer_file.open(file_address, ios::in);


			customer_file >>
				temp_string >> customer_id >>
				temp_string >> customer_name >>
				temp_string >> count_of_given >>
				temp_string >> count_of_not_given >>
				temp_string >> remainder_cost;

			customer_file >> temp_string >> temp_string >> product_count;
			if (product_count)
			{
				product_list.clear();
				product_list.reserve(product_count);
				customer_file >> temp_string >> temp_string >> temp_string;
				for (j = 0; j < product_count; ++j)
				{
					customer_file >> temp_num >> product_need >> product_id;
					product_list.push_back(pair_t(product_need, product_id));
				}
			}

			customer.push_back(Customer(customer_id, customer_name,
				count_of_given, count_of_not_given, remainder_cost, product_list));

			customer_file.close();
		}
	}
	all_customers.close();
}

void sign_customer(vector<Customer>& customer)
{
	id_t customer_id;
	string customer_name;

	count_t count_of_given, count_of_not_given;
	price_t remainder_cost;

	size_t n;

	cout << "<< bejaye fasele az \"_\" estefadeh konid! >>" << endl;
	cout << "Tedad forooshgah jadid: ";
	cin >> n;
	cout << "____________________" << endl;
	for (size_t i(0); i < n; ++i)
	{
		cout << "Num # " << i << endl;
		cout << "Code forooshgah: ";
		cin >> customer_id;
		cout << endl << "Name forooshgah: ";
		cin >> customer_name;
		cout << endl << "Tedad sefareshat tahvil dade shode: ";
		cin >> count_of_given;
		cout << endl << "Tedad taghazahaye tahvil dade nashode: ";
		cin >> count_of_not_given;
		cout << endl << "Bedehi: ";
		cin >> remainder_cost;

		cout << "____________________" << endl;
		customer.push_back(Customer(customer_id, customer_name,
			count_of_given, count_of_not_given, remainder_cost));
	}
}

void change_customer(vector<Customer>& customer)
{
	id_t customer_id;
	string customer_name;

	count_t count_of_given, count_of_not_given;
	price_t remainder_cost;

	vector<Customer>::iterator item;
	size_t index;

	cout << "<< bejaye fasele az \"_\" estefadeh konid! >>" << endl;
	cout << "Code forooshgah: ";
	cin >> customer_id;
	item = find(customer.begin(), customer.end(), customer_id);
	if (item == customer.end())
	{
		printf("Forooshgah moredenazar peyda nashod!\n");
	}
	else
	{
		index = item - customer.begin();
		cout << endl << "Name forooshgah: (" << item->name() << ") ";
		cin >> customer_name;
		cout << endl << "Tedad sefareshat tahvil dade shode: (" << item->count_of_given() << ")";
		cin >> count_of_given;
		cout << endl << "Tedad taghazahaye tahvil dade nashode: (" << item->count_of_not_given() << ") ";
		cin >> count_of_not_given;
		cout << endl << "Bedehi: (" << item->remainder_cost() << ") ";
		cin >> remainder_cost;
		customer[index] = Customer(customer_id, customer_name,
			count_of_given, count_of_not_given, remainder_cost, customer[index].product_list());
	}
}	