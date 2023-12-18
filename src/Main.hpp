#pragma once

#include "Product.hpp"
#include "Customer.hpp"

void scan_product(vector<Product>& product);
void sign_product(vector<Product>& product);
void change_product(vector<Product>& product);

void scan_customer(vector<Customer>& customer);
void sign_customer(vector<Customer>& customer);
void change_customer(vector<Customer>& customer);

void show_product(vector<Product>& product);
void show_customer(vector<Customer>& customer);