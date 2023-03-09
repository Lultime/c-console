#include <iostream>
#include <limits>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <String>
using namespace std;


//declaration des fonctions
void menu(void);
int facto (int rep);
int combinaison(int a,int b);
void produit_matrice(int A[100][100],int B[100][100],int nb);
void heure();
void date();
void close();
void decroissant(int A[100],int q);
void annagramme(string mot);
int main(int argc, char** argv)
 {
 	system("color 3E");
	menu();
 	
	return 0;
}
//definition des fonctions
void menu(void)
{
	int choix=0;
	do{
	
	
	
	cout<<"***** MENU PRINCIPAL*****\n\n";
	cout<<"[1]la combinaison de deux valeurs entieres\n";
	cout<<"[2] Factoriel \n";
	cout<<"[3]le produit deux matrices d'ordre\n";
	cout<<"[4]classer par ordre decroissant des valeurs saisies\n";
	cout<<"[5]l annagramme d un nom d une personne \n";
	cout<<"[6]changer l'heure de l'ordinateur\n";
	cout<<"[7]changer la date  de l'ordinateur\n";
	cout<<"[8]Eteindre l'ordinateur ?\n";
	cout<<"[9]Quitter\n\n";
	do{
	cout<<"faite votre choix\n";
	cin>>choix;
		
	}while(choix<1 || choix>10);
	
	switch(choix)
	{
		case 1:
	
			{
				int a,b,n=0,ni,comb,fac1=1,fac2=1,div,i,fac3=1,j,c,cc;
				char repp;
					cout<<"entrer la valeur de a ";
	cin>>a;
	cout<<"entrer la valeur de  b>a :";
	cin>>b;
	while(b<a  || b<0)
	{
		cout<<"entrer la valeurs b>a ";
		cin>>b;
		
	}
	while( a<0 )
	{
		cout<<"entrer la valeurs b>a: " ;
		cin>>a;
	}
				
				while(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
			std::cout<<"erreur/ entrer un entier : \n";
		    std::cin>>a;
			
		}
					while(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
			std::cout<<"erreur/ entrer un entier : \n";
		    std::cin>>b;
			
		}
				
				n=combinaison( a ,b);
				cout<<"Sa combinaison  est "<< n<<"\n\n";
				
				do{
						
						cout<<"Voulez vous recommencer\n";
						cout<<"Pressez [O] pour continuer ou [N] pour retourner au menu principale\n";
						cin>>repp;
					}while(repp=='o' || repp=='O');
					system("cls");
				if(repp=='o' || repp=='O')
				{
					break;	
				}
				
			  break;
			}
			
		case 2:
		
			{
				int val,m=0;
				char rep;
				
				cout<<"entrer la valeur :" ;
	           	cin>>val;
	
				
				while(std::cin.fail())
		           {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
			std::cout<<"erreur/ entrer un entier : \n";
		    std::cin>>val;
	            }
			m=facto(val);
			cout<<"son factoriel est :"<<m<<"\n\n";
				
				break;	
			}
		case 3:
		
			{
				int max=100,i,nb,j,k,cp,c,D1[max][max];
				int A[100][100],B[100][100];
				cout<<"entrer le nombre de ligne et de colonne pour les deux matrices:\n";
				cin>>nb;
				while(nb<2||nb>10)
				{
					cout<<"la valeur est incorrecte \n";
					cin>>nb;
				}
				
				for(int i=0; i<nb;i++)
				{
					for(int j=0;j<nb;j++){
						cout<<"A["<<i+1<<"]["<<j+1<<"]: ";
						cin>>A[i][j];
					}
				}
				cout<<"\n";
					
				for(int k=0; k<nb; k++)
				{
					for(int j=0; j<nb; j++){
						cout<<"B["<<k+1<<"]["<<j+1<<"]: ";
						cin>>B[k][j];
					}
				}
				cout<<"\n";
				for(int i=0; i<nb; i++){
					for(int j=0; j<nb; j++){
						
						cout<<A[i][j]<<"\t";
					
					}
					cout<<"\n";
				}
				
				cout<<"\n";
				for(int k=0; k<nb; k++){
					for(int j=0; j<nb; j++){
						
						cout<<B[k][j]<<"\t";
					
					}
					cout<<"\n";
				}
				
				cout<<"Le produit de la matrice A et B est: \n";
	           
			    produit_matrice(A, B,nb);
			    cout<<"\n";
				
				break;
			}
			
			case 4:
		
				{
				int q,i ,j ,maxe, max=100,temps;
                     int A[max];

                 cout<<"entrer quantite nombre : ";
                  cin>>q;
               cout<<"\n";
               	//enregistrement
                 for (j=0 ; j<q;j++)
                   {
	
                	cout<<"n"<<j<<" :";
                          	cin>>A[j];
                      }              
                    //affichage tableau
                for(j=0 ;j<q;j++)
                      {
                  	cout<<A[j]<<"\n";
                    }
                        cout<<"\n";
	    cout<<"tableau trie";
                decroissant(A,q);
                cout<<"\n";
               
				break;	
				}
				
			case 5:
			
				{
				   
			  string mot;
			  char m;
			  
			  cout<<"entrer un mot : ";
			  cin>>mot;
			  
			    cout<<"l une de ces Annagrammes est : ";	
			      annagramme(mot);
			      cout<<"\n";
			    	do{
	         	cout<<"voulez vous une autre :? o/n \n";
	      	    cin>>m;
	         	if(m=='N' || m=='n')
	         	{
		        	break;
	          	}
	       }while(next_permutation(mot.begin(),mot.end()));
				break;		
				}
			case 6:
			
				{
				  
				   
				       heure();
				  
				  break; 
				  	
				}
			case 7:
			
				{
				
				
			
			      date();
			
				break;	
				}
			case 8:
		
				{
				 
				    char re;
				    cout<<"Ete vous sur de vouloir eteindre le system O(oui) N(non) :";
				    cin>>re;
				if(re=='O'||'o')
				{
					 close();
					 
				}
				if(re=='N'||'n')
				break;
			
				}
			
		case 9:
		
			{
				char m;
				cout<<"voulez vous quitter l'application? Yes/No \n";
				cin>>m;
				
				if(m=='y'||'Y')
				{
					exit(0);
				}
				
			  break ;
				
			}
	default:{
	cout<<"erooor!!!!!!!\n";
		
		break;
	}
		
	}
}while(choix<=9);
}
	


//définition fonction factoriel

int facto(int val)
{
	int facto=1,j;
if(val==1 ||0)
{
  return 1;	
}else{



	for(j=1;j<=val;j++)
	{
		facto=facto*j;
	}
}
	
	return facto;
}
//definition combinaison 
int combinaison(int a,int b)
{
int n=0,comb,fac1=1,fac2=1,div,i,fac3=1,j,c,cc;
	
        
    
        
			

div=0;	

div=(b-a);


if(a==1 ||0)
{
  return 1;	
}else
{
	for(i=1;i<=a;i++)
	{
		fac1=fac1*i;
	}
	
}
if(b==1 ||0)
{
  return 1;	
}else
{
	for(j=1;j<=b;j++)
	{
		fac2=fac2*j;
	}
	
}

if(div==1 ||0)
{
  return 1;	
}else
{
	for(c=1;c<=div;c++)
	{
		fac3=fac3*c;
	}

}

cc=fac1*fac3;

comb= fac2/cc;

	
	return comb;
}


//definition produit de matrice

void produit_matrice(int A[100][100],int B[100][100],int nb)
{
	int i,j,k ,max=100,D1[100][100],cp;
for(int i=0; i<nb; i++){

	for (j=0; j<nb; j++)
	{
		cp=0;
		for (k=0; k<nb; k++)
		{
			cp=cp +A[i][k] * B[k][j];
		}
	D1[i][j]=cp;
}
	
}

cout<<"\n";

for(int i=0; i<nb; i++){

	for (j=0; j<nb; j++)
	{
	cout<< D1[i][j]<<"\t";
}
 cout<<"\n";	
}
  
}


//date


void heure() {
    
    string commande,heures;
    
    commande = "time" + heures;
    system(commande.c_str());
}

void date () {
    string date;

    cout << "Entrez la date dans le format (mm-jj-aa): ";
    getline (cin, date);

    string commande = "date " + date;
    system(commande.c_str());
}

//eteindre

void close ()
{
	system("shutdown -s");
}



//nombre decroissante
void decroissant(int A[100],int q)
{
	
	int i,j,maxe,max=100,temps,a;

for(i=0; i<q-1 ; i++)
{
	maxe=i;
	
	for(j=(i+1);j<q;j++)
	
		
			if(A[j]>A[maxe])maxe=j;
			
	
	
     		
	 temps=A[i];
	 A[i]=A[maxe];
	 A[maxe]=temps;
	
}
//affichaje tableau trie
cout<<"\n";

for(a=0 ;a<q;a++)
{
	cout<<A[a]<<"\t";
}

}

//annagramme

void annagramme(string mot)
{
	
	std::sort(mot.begin(),mot.end());
	cout<<mot;
	

}

