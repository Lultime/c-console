#include<iostream>
#include<limits>

int main(void)
{
	int n;
	std::cout<<"entrer un nombre pair et superieur a 0: ";
	std::cin>>n;
	while(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
			std::cout<<"erreur/ entrer un entier : \n";
		    std::cin>>n;
			
		}
	while(n%2!=0 || n<=0)
	{
		std::cout<<"veuillez suivre les instructions \n";
		std::cout<<"entrer un nombre pair et superieur a 0 : ";
	    std::cin>>n;
		
	}
	if(n%2==0 && n>0)
	{
		std::cout<<"valeur correcte";
	}
	
	return 0;
}