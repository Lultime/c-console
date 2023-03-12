#include<iostream>
#include<ctime>

using namespace std;
int main(void)
{
	
	int year, month,day;
	
	
	time_t currenttime=time(0);
	tm* ltm=localtime(&currenttime);
	
	
	year= 1900 + ltm->tm_year;
	month=1 + ltm->tm_mon;
	day=ltm->tm_mday;
	
	cout<< month <<"/"<<day<<"/"<<year;
}