#include <iostream>
#include <algorithm>
#include "WalkingTout.h"

#define MAXN 3

using namespace std;

int main()
{
	string excname, guidname;
	int d, m, y;
	int time;
	int cost;
	int guidpayment = 0;
	WalkingTout walkingtour[MAXN];
	for (int i = 0; i < MAXN; i++)
	{
		cout << "Tour name:";
		cin >> excname;
		walkingtour[i].setExcursionName(excname);
		cout << "Date(dd/mm/yyyy): ";
		scanf_s("%d.%d.%d", &d, &m, &y);
		walkingtour[i].setDate(d, m, y);
		cout << "Time: ";
		cin >> time;
		walkingtour[i].setTime(time);
		cout << "Cost: ";
		cin >> cost;
		walkingtour[i].setCost(cost);
		cout << "Guid Name: ";
		cin >> guidname;
		walkingtour[i].setGuidName(guidname);
		cout << "Guid payment in %: ";
		cin >> guidpayment;
		walkingtour[i].setGuidPayment(guidpayment);
	}
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN - i; j++) 
		{
			if (walkingtour[j].getCost()*walkingtour[j].getGuidPayment()/100 > walkingtour[j+1].getCost() * walkingtour[j+1].getGuidPayment() / 100)
			{
				swap(walkingtour[j], walkingtour[j + 1]);
			}
		}
	}
	for (int i = 0; i < MAXN; i++)
	{
		cout << "Excursion name: " << walkingtour[i].getExcursionName() << endl
			<< "Date: " << walkingtour[i].getDate() << endl
			<< "Time: " << walkingtour[i].getTime() << endl
			<< "Cost: " << walkingtour[i].getCost() << endl
			<< walkingtour[i].getGuidName() << " has "
			<< walkingtour[i].getCost() * walkingtour[i].getGuidPayment() / 100 << "$\n";
	}
}
