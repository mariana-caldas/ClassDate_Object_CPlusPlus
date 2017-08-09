#include <iostream>
#ifndef CLASS_SIMPLE_DATE 
#define CLASS_SIMPLE_DATE
using namespace std;

class mariDate
{
private:
	int Day;
	int Month;
	int Year;
	bool IsLeapYear = false; //default boolean in C++ is true

public:

	mariDate();
	mariDate(int, int, int);
	mariDate(mariDate *);
	~mariDate();
	void SetDay(int);
	int GetDay();
	void SetMonth(int);
	int GetMonth();
	void SetYear(int);
	int GetYear();
	void DisplayDate();
	bool CheckDay(int);
	bool CheckMonth(int);
	bool CheckYear(int);
};

//Default constructor
mariDate::mariDate()
{
	Day = 0;
	Month = 0;
	Year = 0;
}


//Overload constructor
mariDate::mariDate(int DayValue, int MonthValue, int YearValue)
{
	if (CheckDay(DayValue))
	{
		Day = DayValue;
	}
	else
	{
		Day = 1;
	}
	if (CheckMonth(MonthValue))
	{
		Month = MonthValue;
	}
	else
	{
		Month = 1;
	}
	if (CheckYear(YearValue))
	{
		Year = YearValue;
	}
	else
	{
		Year = 1;
	}
}

//Copy constructor
mariDate::mariDate(mariDate * RightDateObj)
{
	Day = RightDateObj->Day;
	Month = RightDateObj->Month;
	Year = RightDateObj->Year;
}

//Destructor
mariDate::~mariDate()
{

}

//Access Functions

int  mariDate::GetDay()
{
	return Day;
}
void mariDate::SetDay(int DayValue)
{
	Day = DayValue;
}

int  mariDate::GetMonth()
{
	return Month;
}
void mariDate::SetMonth(int MonthValue)
{
	Month = MonthValue;
}

int  mariDate::GetYear()
{
	return Year;
}
void mariDate::SetYear(int YearValue)
{
	Year = YearValue;
}
bool mariDate::CheckYear(int YearValue)
{
	if (YearValue < 1980 || YearValue > 2017)
	{
		cout << "Enter a year between 1980 and 2017\n";
		return false;
	}
	if (YearValue % 4 == 0 && (YearValue % 100 != 0 || YearValue % 400 == 0))
	{
		IsLeapYear = true;
	}
	return true;
}

bool mariDate::CheckMonth(int MonthValue)
{
	if (MonthValue < 1 || MonthValue > 12)
	{
		cout << "Enter a month between 1 and 12\n";
		return false;
	}
	if (MonthValue == 2 && IsLeapYear == true)
	{
		cout << "Attention: this is a leap year, remember that February (month 2) has 29 days.\n";
	}
	return true;
}
bool mariDate::CheckDay(int DayValue)
{
	if (DayValue < 1 || DayValue > 31)
	{
		cout << "Enter a day between 1 and 31\n";
		return false;
	}
	if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12 )
	{
		if (DayValue > 31)
		{
			cout << "The month you chose cannot have more than 31 days.\n";
			return false;
		}
	}
	if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
	{
		if (DayValue > 30)
		{
			cout << "The month you chose cannot have more than 30 days.\n";
			return false;
		}
	}
	if (Month == 2 && IsLeapYear == false && DayValue > 28)
	{
		cout << "Since it is not a leap year, February cannot have more than 28 days.\n";
		return false;
	}
	if (Month == 2 && IsLeapYear == true && DayValue > 29)
	{
		cout << "Since it is a leap year, February cannot have more than 29 days.\n";
		return false;
	}
	return true;
}

void mariDate::DisplayDate()
{
	cout << GetYear() << " / " << GetMonth() << " / " << GetDay() << endl;

}

#endif