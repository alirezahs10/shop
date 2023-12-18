#include "Main.hpp"

void show_product(vector<Product>& product)
{
	cout << "tedad_kala : " << product.size() << endl << "____________________" << endl;
	for (size_t i(0); i < product.size(); ++i)
	{
		cout << "Num # " << i + 1 << endl;
		cout <<
			"code_kala: " << product[i].id() << endl <<
			"name_kala: " << product[i].name() << endl <<
			"karkhane_tolid_konande: " << product[i].product_factory() << endl <<
			"tarikhe_tolid: " << product[i].made_time() << endl <<
			"modat_zaman_engheza: " << product[i].remainder_time() << endl <<
			"tedad_kharidari_shode: " << product[i].count_of_buy() << endl <<
			"tedad_mojood_dar_anbar: " << product[i].count_of_exist() << endl <<
			"gheymat_kharid_har_vahed: " << product[i].unit_buy_price() << endl <<
			"gheymat_foroosh_har_vahed: " << product[i].unit_sell_price() << endl <<
			"tedad_mavared_forookhte_shode_be_soorat_takhfifdar" << product[i].count_of_off_sell() << endl;

		cout << endl << "tedad_list_forooshgah: " << product[i].customer_list().size() << endl;
		if (product[i].customer_list().size())
		{
			cout << "num\ttedad\tcode_forooshgah" << endl;
			for (size_t j(0); j < product[i].customer_list().size(); ++j)
			{
				cout << j + 1 << "\t"
					<< product[i].customer_list(j).first << "\t"
					<< product[i].customer_list(j).second << endl;
			}
		}
		cout << "____________________" << endl;
	}
}
