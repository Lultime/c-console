#include<iostream>


int main()
{
	int tva=30;
float p ,total ,qt;
std::cout<<"entrer le prix  de l exemplaire achete : ";
std::cin>>p;
std::cout<<"entrer la quandite achete: ";
std::cin>>qt;
std::cout<<"\n";
std::cout<<"le TVA est de 30%";
total=p*qt;
std::cout<<"\n";
std::cout<<"avant TVA le total est de "<<total;
tva=(p * 30)/100 ;
total=(tva + p ) *qt;
std::cout<<"\n";
std::cout<<"avec un  TVA  de:"<< tva;
std::cout<<"\n";
std::cout<<"apres TVA le total est de "<<total;
	
	
	
	return 0;
}