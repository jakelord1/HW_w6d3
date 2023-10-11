#include <iostream>
#include <string>
#include "Base.h"
#include "Venicle.h"
using namespace std;

int Base::people_on_base = 50;
int Base::venicles_on_base = 7;
double Base::petrol_on_base = 500;
double Base::goods_on_base = 15;

int main()
{
    Base base;
    Venicle* bus;
    bus = new Bus(12,30,45,90);
    Venicle* truck;
    truck = new Truck(1, 4, 20, 80);

    base.Show();
    bus->arrive();
    truck->arrive();
    base.Show();

    cout << bus->leave() << endl;
    base.Show();
    cout << truck->leave() << endl;
    base.Show();
}
