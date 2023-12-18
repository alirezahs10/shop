#include "Main.hpp"

int main()
{
	vector<Product> product;
	vector<Customer> customer;
	int n;

	system("md DataBase");
	system("md DataBase\\Customer");
	system("md DataBase\\Product");
	system("cls");

	cout << "///Welcom///" << endl;

	scan_customer(customer);
	scan_product(product);
	
	while (true)
	{
		system("cls");
		cout << "<<<menu>>>" << endl;
		cout << "1.Sabt forooshgah jadid" << endl;
		cout << "2.taghiir moshakhasat forooshgah" << endl;
		cout << "3.Sabt mavade ghazaee jadid" << endl;
		cout << "4.taghiir moshakhasat mavade ghazaee" << endl;
		cout << "5.namayesh moshakhsat forooshgah ha" << endl;
		cout << "6.namayesh moshakhsat mavade ghazaee" << endl;
		cout << "0.khorooj" << endl;
		cout << "______________________________" << endl;
		cout << "lotfan gozineh mored nazar khod ra vared konid :: ";
		cin >> n;
		system("cls");
		switch (n)
		{
		case 1:
		{
			sign_customer(customer);
			break;
		}
		case 2:
		{
			change_customer(customer);
			break;
		}
		case 3:
		{
			sign_product(product);
			break;
		}
		case 4:
		{
			change_product(product);
			break;
		}
		case 5:
		{
			show_customer(customer);
			break;
		}
		case 6:
		{
			show_product(product);
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
		{
			cout << endl << "gozineh mored nazar yaft nashod\a" << endl;
			break;
		}
		}
		cout << endl;
		system("pause");
	}


}