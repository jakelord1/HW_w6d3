#pragma once
#include "Base.h"
#include <string>
using namespace std;
class Venicle
{
	double petrol_amount;
	double tank_volume;
public:
	Venicle(double petrolamount, double tankvolume) { petrol_amount = petrolamount; tank_volume = tankvolume; };
	double getTankVolume() { return tank_volume; }
	double getPetrolAmount() { return petrol_amount; }
	virtual void arrive(); 
	virtual bool leave();
};

class Bus : public Venicle
{
	int people;
	int max_people;
public:
	Bus(int peopl, int maxpeople, double petrol, double max_petrol) : Venicle(petrol, max_petrol) { people = peopl; max_people = maxpeople; };
	int getPeopleCount() { return people; };
	int getMaxPeople() { return max_people; };
	void arrive();
	bool leave();
};

class Truck : public Venicle
{
	double goods;
	double max_goods;
public:
	Truck(double good, double maxgoods, double petrol, double max_petrol) : Venicle(petrol, max_petrol) { goods = good; max_goods = maxgoods; };
	double getPeopleCount() { return goods; };
	double getMaxPeople() { return max_goods; };
	void arrive();
	bool leave();
};