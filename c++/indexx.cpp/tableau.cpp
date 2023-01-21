#include<iostream>
using namespace std;
int main(void)
{
	int tab[6];
	int i,somme;
	for(i=0;i<6;i++)
	{
	cout<<"entrer un nombre : ";
	cin>>tab[i];
	somme+=tab[i];	
	}
	
	for(i=0;i<6;i++)
	{
		cout<<tab[i]<<"\t";
		
	}
	cout<<"\n";
	cout<<"la somme est :"<<somme;
	
	return 0;
}