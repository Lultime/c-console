#include <iostream>

int main ()
{
	float moy,a;
	
	
	std::cout<<"entrer le 1er nombre ";
	std::cin>>a;
	moy=moy + a;
	std::cout<<"entrer le 2eme  nombre ";
	std::cin>>a;
	moy=moy + a;
	std::cout<<"entrer la 3eme nombre ";
	std::cin>>a;
	moy=moy + a;
	std::cout<<"entrer la 4eme nombre ";
	std::cin>>a;
	moy=moy + a;
	std::cout<<"entrer le 5eme nombre ";
	std::cin>>a;
	moy=(moy + a )/5;
	std::cout<<"la moyenne est ";
	std::cout<<moy;
	
}