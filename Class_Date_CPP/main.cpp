#include <iostream>
#include "SimpleDate.h"
using namespace std;

void main()
{
	int year;
	int month;
	int day;

	mariDate FirstDate;

	cout << "Enter the year: ";
	cin >> year;
	if (!FirstDate.CheckYear(year)) //if the Check Condition is false.
	{
		system("pause");
		return;
	}
	FirstDate.SetYear(year);

	cout << "Enter the month: ";
	cin >> month;
	if (!FirstDate.CheckMonth(month))
	{
		system("pause");
		return;
	}
	FirstDate.SetMonth(month);

	cout << "Enter the day: ";
	cin >> day;
	if (!FirstDate.CheckDay(day))
	{
		system("pause");
		return;
	}
	FirstDate.SetDay(day);

	FirstDate.DisplayDate();
	system("pause");
}