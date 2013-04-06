#include <iostream>
#include <string>
#include <fstream>
#include <list>
using namespace std;
#include "Seznam.h"

Seznam::Seznam()
{
  
}
Seznam::~Seznam()
{
	
}
void Seznam::PridaniKontaktu(string j, string p, string c)
{
	Kontakt novykontakt;

	bool chybnecislo=false;
	for(int i=0;i<c.length();i++)
	{
		if(c[i]!='1' && c[i]!='2' && c[i]!='3' && c[i]!='4' && c[i]!='5' && c[i]!='6' && c[i]!='7' && c[i]!='8' && c[i]!='9' )
		{
			chybnecislo=true;
		}
	}
	if(chybnecislo)
		c="N/A";
	
	novykontakt.cislo=c;
	novykontakt.jmeno=j;
	novykontakt.prijmeni=p;
	this->zaznam.push_back(novykontakt);
		
}
void Seznam::ZobrazeniZaznamu()
{

	for(K=zaznam.begin();K!=zaznam.end();K++)
	{
		cout<<"Jmeno: "<<K->jmeno<<endl;
		cout<<"Prijmeni: "<<K->prijmeni<<endl;
		cout<<"Cislo: "<<K->cislo<<endl;
		cout<<"************************"<<endl;
	}
	
}
void Seznam::VytvoreniSouboru(string cesta, string nazev)
{
	string  pripona=".txt";
	fstream soubor(cesta + nazev + pripona,ios::out | ios::app);
	
	soubor.close();
}
void Seznam::CteniSouboru(string cesta, string nazev)
{
	string pripona=".txt";
	fstream soubor(cesta+nazev+pripona,ios::in);

	if(!soubor.is_open())
	{
		cout<<"Soubor nebyl nalezen"<<endl;
		return;
	}
	int pocetradku=0;
	while(!soubor.eof())
	{
		pocetradku++;
		string jmeno;
		string prijmeni;
		string cislo;
		
		getline(soubor,jmeno,';');
		getline(soubor,prijmeni,';');
		getline(soubor,cislo);

		if(jmeno.empty() && prijmeni.empty() && cislo.empty())
		{
			cout<<"Seznam je prazdny"<<endl;
			return;
		}
		else
		{
			PridaniKontaktu(jmeno,prijmeni,cislo);
		}
	}
	soubor.close();
}
int Seznam::VelikostSeznamu()
{
	return zaznam.size();
}
void Seznam::ZapisDoSouboru(string cesta, string nazev)
{
	string  pripona=".txt";
	fstream soubor(cesta + nazev + pripona,ios::out | ios::app);
	
	list <Kontakt>tmp;
	tmp=zaznam;
	int size=tmp.size();
	int i=0;
	for(K=tmp.begin();K!=tmp.end();K++)
	{	i++;
		soubor<<K->jmeno<<";"<<K->prijmeni<<";"<<K->cislo<<endl;
		
		if(i==size)
			soubor<<K->jmeno<<";"<<K->prijmeni<<";"<<K->cislo;
	}
	
	soubor.close();

}
void Seznam::SmazaniKontaktu(int index)
{
	if(index<0 || index>=zaznam.size() || cin.fail())
		cout<<"spatny index"<<endl;
	else if(index==0)
	{
		zaznam.erase(zaznam.begin());
	}
	else
	{
		L=zaznam.begin();
		int i=0;
		while(i<index && L!=zaznam.end())
		{
			i++;
			L++;
		}
		zaznam.erase(L);
	}
	
	

	
}
