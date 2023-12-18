#pragma once

#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

class Time
{
private:
	time_t _day;
	time_t _month;
	time_t _year;

	string _complete; // yyyy/mm/dd

public:
	Time() { now(); }
	Time(string _input_time)
		:
		_complete(_input_time)
	{
		change();
	}
	Time(const Time& _obj)
		:
		_complete(_obj._complete)
	{
		change();
	}
	~Time() {}

	time_t day() { return _day; }
	time_t month() { return _month; }
	time_t year() { return _year; }

	string complete() { return _complete; }

	void change()
	{
		_year = stoi(_complete.substr(0, 4));
		_month = stoi(_complete.substr(5, 2));
		_day = stoi(_complete.substr(8, 2));
	}

	void now()
	{
		string _computer_cpptime, _month;
		auto givemetime = chrono::system_clock::to_time_t(chrono::system_clock::now());
		_computer_cpptime = ctime(&givemetime); //"Fri Jan 14 00:02:41 2019"; // "Fri Jan 14 00:02:41 2019"

		// set date
		//* set month
		_month = _computer_cpptime.substr(4, 3);

		if (_month == "Jan") { _month = "01"; }
		else if (_month == "Feb") { _month = "02"; }
		else if (_month == "Mar") { _month = "03"; }
		else if (_month == "Apr") { _month = "04"; }
		else if (_month == "May") { _month = "05"; }
		else if (_month == "Jun") { _month = "06"; }
		else if (_month == "Jul") { _month = "07"; }
		else if (_month == "Aug") { _month = "08"; }
		else if (_month == "Sep") { _month = "09"; }
		else if (_month == "Oct") { _month = "10"; }
		else if (_month == "Nov") { _month = "11"; }
		else { _month = "12"; }

		//* set year
		_complete = _computer_cpptime.substr(20, 4);
		//* set day
		_complete += ('/' + _month + '/' + _computer_cpptime.substr(8, 2));

		// calculate date on uint16_t type
		change();
	}

	void insert(string _input_obj)
	{
		_complete = _input_obj.substr(0, 10);
		change();
	}

	void insert_date(string _input_obj_date)
	{
		insert(_input_obj_date);
	}

	uint64_t operator-(Time _right_obj) // base on seconds
	{
		Time _left_obj(_complete);
		if (_complete == _right_obj._complete) { return 0; }
		else if (_complete < _right_obj._complete) { swap(_left_obj, _right_obj); }

		int64_t _diff, _obj_1_coef, _obj_2_coef;
		_obj_1_coef = _obj_2_coef = 2592000;
		_diff = (_left_obj._day - _right_obj._day) * 86400;

#ifdef Month_30
		_diff += (_left_obj._month - _right_obj._month) * 2592000; // each month has 30 days
		_diff += (_left_obj._year - _right_obj._year) * 31104000; // each year has 360 days
#else
		switch (_left_obj._month)
		{
		case 2:
			_obj_1_coef = 2419200;
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			_obj_1_coef = 2678400;
			break;
		}

		switch (_right_obj._month)
		{
		case 2:
			_obj_2_coef = 2419200;
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			_obj_2_coef = 2678400;
			break;
		}

		_diff += (_left_obj._month * _obj_1_coef) - (_right_obj._month * _obj_2_coef);
		_diff += (_left_obj._year - _right_obj._year) * 31536000; // each year has 365 days
#endif

		return _diff;
	}

	int64_t minus_by_day(Time _right_obj)
	{
		Time _left_obj(_complete);
		return (_left_obj - _right_obj) / 86400;
	}

	Time operator=(Time _obj)
	{
		_day = _obj._day;
		_month = _obj._month;
		_year = _obj._year;

		_complete = _obj._complete;

		return _obj;
	}

	bool operator<(Time _right_obj) { return (_complete < _right_obj._complete); }
	bool operator>(Time _right_obj) { return (_complete > _right_obj._complete); }
	bool operator<=(Time _right_obj) { return (_complete <= _right_obj._complete); }
	bool operator>=(Time _right_obj) { return (_complete >= _right_obj._complete); }
	bool operator==(Time _right_obj) { return (_complete == _right_obj._complete); }
};