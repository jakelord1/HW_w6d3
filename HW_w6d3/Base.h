#pragma once
#include <iostream>
using namespace std;
class Base
{
public:
	static int people_on_base;
	static int venicles_on_base;
	static double petrol_on_base;
	static double goods_on_base;
	void Show() { cout << people_on_base << '\t' << venicles_on_base << '\t' << petrol_on_base << '\t' << goods_on_base << endl; }
};


