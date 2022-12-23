#include<iostream>
#include<limits>
int main(void)
{
	int n,i,facto=1;
	std::cout<<"entrer un nombre superieure a 0:  ";
	std::cin>>n;
	while(n<=0 )
	{
		std::cout<<"veuillez suivre les instructions \n";
    	std::cout<<"entrer un nombre superieure a 0:  ";
        std::cin>>n;
        while(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
			std::cout<<"erreur/ entrer un entier : \n";
		    std::cin>>n;
			
		}
        
    }
        if(n>0)
        {
        	for(i=1 ;i<=n ; i=i+1)
        	{
        		facto=facto * i;
            
			}
	    std::cout<<facto;
	   
			
		}
		
	
	
	
	return 0;
	
}