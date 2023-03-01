#include<iostream>
#include<String>
using namespace std;
float somme(float a,float b);


float produit(float a,float b)
{
	int produit;
	produit=a * b;
	
	
	return produit;
	
}
int main(int argu,char** argc)

{
	string var;
	float val1, val2;
	
	cout<<"entrer la premiere valeur : ";
	cin>>val1;
	cout<<"entrer la deuxieme valeur : ";
	cin>>val2;
	
	cout<<"Le produit de ces deux nombres est : ";
	
	cout<<produit(val1,val2);
	return 0;
}