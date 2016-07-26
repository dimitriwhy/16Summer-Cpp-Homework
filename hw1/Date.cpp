#include <iostream>
#include "date.h"
using namespace std;
int Date :: maxDay(){
	if (m_month == 2){
		if (m_year % 400 == 0) return 29;
		if (m_year % 4 == 0 && m_year % 100 != 0) return 29;
		return 28;
	}
	if (m_month == 4 || m_month == 6 || m_month == 9 || m_month == 11) return 30;
	return 31;
}
Date :: Date(int year,int month,int day) : m_year(year), m_month(month), m_day(day) {
	if (year < 1) m_year = 1;
	if (month > 12 || month <= 0) month = 1;
	if (day <= 0 || day > maxDay()) day = 1;
}
Date :: ~Date () {}
void Date :: showDate(){
	cout << "year=" <<m_year << " " << "month="<<m_month << " " << "day=" << m_day << endl;
}
int Date :: getYear(){
	return m_year;
}
int Date :: getMonth(){
	return m_month;
}
int Date :: getDay(){
	return m_day;
}
void Date :: setDate(int year,int month,int day){
	if (year < 0) m_year = 1;
	else m_year = year;
	if (month > 12 || month < 1) m_month = 1;
	else m_month = month;
	if (day < 1 || day > maxDay()) m_day = 1;
	else m_day = day;
}
int main(int argv,char *argc[]){
	Date a(2,2,2);
	a.showDate();
	a = Date(3);
	a.showDate();
	a = Date(4,5);
	a.showDate();
	cout << a.getYear() << " " << a.getMonth() << " " << a.getDay() << endl;
	a.setDate(7,8,9);
	a.showDate();
	return 0;
}
