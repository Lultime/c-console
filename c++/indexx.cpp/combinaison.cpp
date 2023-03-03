#include<iostream>
using namespace std;
int combinaison(int a ,int b);
int main(int argc, char** argv)
{
	
	int a,b,n=0,ni;
	cout<<"entrer la valeur de a ";
	cin>>a;
	cout<<"entrer la valeur de b b>a";
	cin>>b;
	while(b<a  || b<0)
	{
		cout<<"entrer la valeurs b>a ";
		cin>>b;
		
	}
	while( a<0 )
	{
		cout<<"entrer la valeurs b>a" ;
		cin>>a;
	}
	
	ni=combinaison(a,b);
	cout<<ni;
	
	return 0;
}

int combinaison(int a,int b)
{
	
int comb,fac1=1,fac2=1,div,i,fac3,j,c,cc;
div=(b-a);
cout<<div<<"\n";
if(a==1 ||a==0)
{
  return 1;	
}else
{
	for(i=1;i<=a;i++)
	{
		fac1=fac1*i;
	}
	cout<<fac1<<"\n";
}
if(b==1 ||b==0)
{
  return 1;	
}else
{
	for(j=1;j<=b;j++)
	{
		fac2=fac2*j;
	}
	cout<<fac2<<"\n";
}

if(div==1 ||div==0)
{
  return 1;	
}else
{
	for(c=1;c<=div;c++)
	{
		fac3=fac3*c;
	}
	cout<<fac3<<"\n";
}
cc=fac1*fac3;

return fac2/cc;;
}