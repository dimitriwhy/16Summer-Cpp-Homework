#ifndef CMS_DATE
#define CMS_DATE
class Date{
private :
	int m_year, m_month, m_day;
public :
	Date(int year = 1,int month = 1,int day = 1);
	~Date();
	void setDate(int year = 1,int month = 1,int day = 1);
	void showDate();
	int getYear();
	int getMonth();
	int getDay();
	int maxDay();
};
#endif
