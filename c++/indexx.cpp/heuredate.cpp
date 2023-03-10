#include<iostream>
#include<string>


using namespace std;
void date();

int main()
{
	
	date();

	return 0;
}
//ouvrir votre editeur en administrateur
void date () {
    string date;

    cout << "Entrez la date dans le format (mm-jj-aa): ";
    getline (cin, date);

    string commande = "date " + date;
    system(commande.c_str());
}


}