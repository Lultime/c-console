#include<iostream>


int main(void)
{
	int i,j,nl,nc,maxi=100 ,A[maxi][maxi];
	
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
	//supposons qu on n etait pas au courantt du nombre de ligne et de colonne 
	//logique permettant de le deduire
	for(i=0;i<maxi/2;i++)
	{
		
		for(j=0;j<maxi/2;j++){
	     j++;
	     if(A[i][j]==0){
	     	break;
		 }
		 i++;
		 if(A[i][j]==0)
		 {
		 	break;
		 }
		
		}
	}
		std::cout<<"\n";
		std::cout<<"nombre de ligne"<<i<<"\n";
		std::cout<<"nombre de colonne"<<j<<"\n";
		if(i==j){
			std::cout<<"c est une matrice carre";
		}else{
			std::cout<<"c est pas une matrice carre";
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