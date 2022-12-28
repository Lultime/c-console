#include<iostream>

int main()
{
	int a, n, b,c,temp,multi;
	std::cout<<"entrer un nombre ";
	std::cin>>n;
	a=n;
	std::cout<<"entrer un autre nombre ";
	std::cin>>n;
	b=n;
	c=n;
	//on vide a avec la variable temp
	temp=a;
	a=b ;
	b=temp;
	
	//on fait la multiplication de b * c 
	multi=b*c;
	std::cout<<"Avant inversement et multiplication on a A="<<b<< " et B,C="<<a<<","<<c;
		std::cout<<"\n\n";
	std::cout<<"Apres inversement et multiplication on a: \n";
	std::cout<<"l inverse de A est "<<a;
		std::cout<<"\n";
    std::cout<<"la multiblication de B,C est B.C="<<multi;


}