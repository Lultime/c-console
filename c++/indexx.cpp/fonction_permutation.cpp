#include<iostream>
#include<String>
using namespace std;
float somme(float a,float b);


void permutation(float a,float b)
{
	int boite;
	boite=a;
	a=b;
	
	
cout<<a<<"\t";

cout<<boite;	
	
}
int main(int argu,char** argc)

{
	string var;
	float val1, val2;
	
	cout<<"entrer la premiere valeur : ";
	cin>>val1;
	cout<<"entrer la deuxieme valeur : ";
	cin>>val2;
	
	cout<<"Permut : ";
	cout<<"\n";
	
	permutation(val1,val2);
	return 0;
}