#include<iostream>
using namespace std;

int main(void)
{
	int max=100,A[max][max],i,j,nb,n,k,cp,c,B[max][max],D1[max][max];
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
				
				
	           
cout<<"\n";
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
	cout<<D1[i][j]<<"\t";
}
 cout<<"\n";	
}


				
	return 0;
}