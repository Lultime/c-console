#include<iostream>

// table multiplication avec le boucle for
//if var%2==0; il est paire


int main(void)
{
int n;
std::cout<<"entrez un nombre compris entre o et 20 : ";
std::cin>>n;

while(n<0 || n>20)
{
	std::cout<<"le nombre doit etre comprix entre 0 et 20 \n";
	
	std::cout<<"entrez un nombre compris entre o et 20 : ";
	std::cin>>n;

}
if(n>=10){
     std::cout<<"le nombre est valide";
}else{
	std::cout<<"le nombre est invalide";
}

return 0;
}