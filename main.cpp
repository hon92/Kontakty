#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "Seznam.h"
#include <vld.h>
#include <list>

void Menu(Seznam & arg);
void PridaniKontaktu(Seznam & arg);
void ZobrazeniKontaktu(Seznam & arg);
void NacteniDatzeSouboru(Seznam & arg);
void ZapsatDoSouboru(Seznam & arg);
void SmazaniKontaktu(Seznam & arg);

int main()
{
  Seznam MojeKontakty;
	
	Menu(MojeKontakty);
	return 0;
}

void Menu(Seznam & arg)
{
	
	int volba;
	cout<<endl;
	cout<<"Menu"<<endl;
	cout<<"1. Zobrazeni Seznamu"<<endl;
	cout<<"2. Pridani kontaktu"<<endl;
	cout<<"3. Smazani kontaktu"<<endl;
	cout<<"4. Nacist data ze souboru .txt"<<endl;
	cout<<"5. Zapsat kontakty do souboru"<<endl;
	cout<<"6. Ukonceni Programu"<<endl;
	cout<<endl;
	cout<<"Vase volba: ";
	cin>>volba;

	switch(volba)
	{
	case 1:
		ZobrazeniKontaktu(arg);
		Menu(arg);
		break;

	case 2:
		PridaniKontaktu(arg);
		Menu(arg);
		break;
	case 3:
		SmazaniKontaktu(arg);
		Menu(arg);
		break;
	case 4:
		NacteniDatzeSouboru(arg);
		Menu(arg);
		break;
	case 5:
		ZapsatDoSouboru(arg);
		Menu(arg);
		break;
	case 6:
		return;
	default:
		Menu(arg);

	}
	

}
void PridaniKontaktu(Seznam & arg)
{
	string jmeno,prijmeni,cislo;
	cout<<"Zadej jmeno: ";
	cin.ignore();
	getline(cin,jmeno);
	cout<<"Zadej prijmeni: ";
	getline(cin,prijmeni);
	cout<<"Zadej cislo: ";
	getline(cin,cislo);
		
	arg.PridaniKontaktu(jmeno,prijmeni,cislo);

}
void ZobrazeniKontaktu(Seznam & arg)
{
	cout<<"Vypis: "<<endl;
	arg.ZobrazeniZaznamu();
}
void NacteniDatzeSouboru(Seznam & arg)
{
	string cesta="";
	string nazev="SeznamKontaktu";
	cout<<"Zadej cestu k souboru: ";
	cin.ignore();
	getline(cin,cesta);
	cout<<"Zadej nazev souboru: ";
	getline(cin,nazev);

	arg.CteniSouboru(cesta,nazev);
}
void ZapsatDoSouboru(Seznam & arg)
{
	string cesta;
	string nazev="SeznamKontaktu";
	cout<<"Zadej cestu k souboru: ";
	cin.ignore();
	getline(cin,cesta);
	cout<<"Zadej nazev souboru: ";
	getline(cin,nazev);
	arg.ZapisDoSouboru(cesta,nazev);

}
void SmazaniKontaktu(Seznam & arg)
{
	int pozice;
	cout<<"Zadej pozici kterou chces smazat: ";
	cin>>pozice;
	arg.SmazaniKontaktu(pozice-1);
}
