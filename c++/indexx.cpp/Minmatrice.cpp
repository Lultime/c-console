#include<iostream>

int main(void)
{
	int i,j,nl,nc,maxi=100,A[maxi][maxi],mini;
	
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
	mini=A[0][0];
	for(i=0;i<nl;i++)
	{
		
		for(j=0;j<nc;j++){
		
		if(mini>A[0][0])
		{
			mini=A[i][j];
		
		}

		}
		std::cout<<"\n";
		
	}
	std::cout<<"le plus petit nombre est : "<<mini;
	
	return 0;
}