#include<iostream>


int main(void)
{
	int i,j,nl,nc,n,maxi=100,A[maxi][maxi];
	
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
		
			for(i=0;i<nl;i++)
	{
		for(j=0;j<nc;j++){
		std::cout<<A[j][i]<<"\t";

		}
				std::cout<<"\n";
		
	}
	
	
	
	
	
	
return 0;	
}