#include<iostream>


int main(void)
{
	int i,j,nl,nc,maxi=100 ,A[maxi][maxi],val;
	
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
	std::cout<<"rechercher une valeur : ";
	std::cin>>val;
		for(i=0;i<nl;i++)
	{
		for(j=0;j<nc;j++){
	     if(val==A[i][j]){
	     	std::cout<<"LA valeur recherche "<<val<<"  existe dans cette matrice ";
	     }
			 else{
			 	std::cout<<"la valeur recherche "<<val<<" n existe pas dans cette matrice ";
			 }
			 
	    break;
		 
		 	
		}
		break;
	}
	
	std::cout<<"\n";
	for(i=0;i<nl;i++)
	{
		for(j=0;j<nc;j++){
		std::cout<<A[i][j]<<"\t";
		
		}
		std::cout<<"\n";
		
	}
	
	
return 0;	
}