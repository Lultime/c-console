#include <iostream>

int main ()
{
    float l,L,surface,perimetre; 
    std::cout<<"Entrer la longueur ";
    std::cin>>l;
    std::cout<<"entrer la largeur ";
    std::cin>>L;
    surface= l * L;
    perimetre=( l + L) *2 ;
    std::cout<<"la surface du champ est ";
    std::cout<<surface<<std::endl;
    std::cout<<"le perimetre du champ est ";
    std::cout<<perimetre;
    
 
    return 0;

}
