#include<iostream>

int main (void)
{
	int matrice[3][3], i ,j;
	for (i=0; i<3;i++)
	{
		for(j=0;j<3;j++)
		{
	     std::cout<<"Matrice ["<<i<<"]"<<"["<<j<<"] : ";
	     std::cin>>matrice[i][j];
		}
	
	}
	for (i=0; i<3;i++)
	{
		for(j=0;j<3;j++)
		{
	    std::cout<<matrice[i][j] <<"\t";
	     
		}
		std::cout<<"\n";
	
	}
	
	
}