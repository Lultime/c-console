#include <iostream>

int main()
{
	int a, b,c;
	std::cout<<"entrer un nombre entier dans A ";
	std::cin>>a;
	c=a;
	std::cout<<"entrer un nombre entier dans B ";
	std::cin>>b;
	a=b;
	b=c;
	std::cout<<"la valeur de A est ";
	std::cout<<a<<"\n\n";
    std::cout<<"la valeur de B est ";
	std::cout<<b;
	
	
}