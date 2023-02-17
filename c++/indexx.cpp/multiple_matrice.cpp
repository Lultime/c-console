#include<iostream>

int main(void)
{
	int i,j,nl,nc,A[10][10];
	
	std::cout<<"entrer nombre de lignes :";
	std::cin>>nl;
	std::cout<<"entrer nombre de colonnes :";
	std::cin>>nc;
	
	for(i=0;i<nl;i++)
	{
		for(j=0;j<nc;j++){
		std::cout<<"A["<<i<<"]["<<j<<"] : ";
		std::cin>>A[i][j];	
		}
		
	}
	std::cout<<"\n";
	for(i=0;i<nl;i++)
	{
		for(j=0;j<nc;j++){
		std::cout<<A[i][j]<<"\t";
		
		}
		std::cout<<"\n";
		
	}
	std::cout<<"\n";
	std::cout<<"Les elements de la diagonale principale sont : \n";
	for(i=0;i<nl;i++)
	{
		for(j=0;j<nc;j++){
		if (i==j)
		{
			std::cout<<A[i][j];
		}
		}
		std::cout<<"\t";
		
	}
	return 0;
}