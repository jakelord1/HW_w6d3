#include "Venicle.h"

void Venicle::arrive()
{
	Base::people_on_base++;
	Base::venicles_on_base++;
}

bool Venicle::leave()
{
	if (Base::people_on_base != 0) {
		Base::people_on_base--;
	}
	else 
		return false;

	if (petrol_amount != tank_volume) {
		double p = tank_volume - petrol_amount;
		if (Base::petrol_on_base >= p) {
			Base::petrol_on_base -= p;
			petrol_amount = tank_volume;
		}
		else if (Base::petrol_on_base == 0) {
			return false;
		}
		else {
			petrol_amount += Base::petrol_on_base;
			Base::petrol_on_base = 0;
		}
	}
	return true;
}

void Bus::arrive()
{
	Venicle::arrive();
	Base::people_on_base += people;
	people = 0;
}

bool Bus::leave()
{
	if (Venicle::leave() && Base::people_on_base != 0) {
		if (Base::people_on_base >= max_people) {
			people = max_people;
			Base::people_on_base -= max_people;
		}
		else if (Base::people_on_base < max_people) {
			people = Base::people_on_base;
			Base::people_on_base = 0;
		}
		return true;
	}
	else
		return true;
}

void Truck::arrive()
{
	Venicle::arrive();
	Base::goods_on_base += goods;
}

bool Truck::leave()
{
	if (Venicle::leave() && Base::goods_on_base != 0) {
		if (Base::goods_on_base >= max_goods) {
			goods = max_goods;
			Base::goods_on_base -= max_goods;
		}
		else if (Base::goods_on_base < max_goods) {
			goods = Base::goods_on_base;
			Base::goods_on_base = 0;
		}
		return true;
	}
	else
		return true;
}
