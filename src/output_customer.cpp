#include "Main.hpp"

void show_customer(vector<Customer>& customer)
{
	cout << "tedad_forooshgah: " << customer.size() << endl << "____________________" << endl;
	for (size_t i(0); i < customer.size(); ++i)
	{
		cout << "Num # " << i + 1 << endl;
		cout <<
			"code_forooshgah: " << customer[i].id() << endl <<
			"name_forooshgah: " << customer[i].name() << endl <<
			"tedad_sefareshat_tahvil_dade_shode: " << customer[i].count_of_given() << endl <<
			"tedad_taghazahaye_tahvil_dade_nashode: " << customer[i].count_of_not_given() << endl <<
			"bedehi: " << customer[i].remainder_cost() << endl;
		
		cout << endl << "tedad_list_kala: " << customer[i].product_list().size() << endl;
		if (customer[i].product_list().size())
		{
			cout << "num\ttedad\tcode_kala" << endl;
			for (size_t j(0); j < customer[i].product_list().size(); ++j)
			{
				cout << j + 1 << "\t" <<
					customer[i].product_list(j).first << "\t" <<
					customer[i].product_list(j).second << endl;
			}
		}
		cout << "____________________" << endl;
	}
}