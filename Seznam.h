#include "Kontakt.h"
#include <list>
class Seznam
{
public:
  Seznam();
	~Seznam();
	void PridaniKontaktu(string j, string p, string c);
	void ZobrazeniZaznamu();
	void VytvoreniSouboru(string cesta, string nazev);
	void CteniSouboru(string cesta, string nazev);
	int VelikostSeznamu();
	void ZapisDoSouboru(string cesta, string nazev);
	void SmazaniKontaktu(int index);	
private:
	list <Kontakt>zaznam;
	list <Kontakt>::iterator K;
	list <Kontakt>::iterator L;
};

