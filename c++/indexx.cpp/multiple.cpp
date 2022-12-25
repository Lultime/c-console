#include<iostream>

//pour chaque valeur entrer par l utilisateur ,afficher la table de multiplication de cette valeur

int main(void)
{
	int multi, n,i=0;
  std::cout<<"entrer le nombre : ";	
  std::cin>>n;
  do{
    multi=n*i; 
 	std::cout<<n<<" x "<<i <<" = "<<multi<<"\n";
 	++i;
  }
  
  while(i<10);	
	
	return 0;
}