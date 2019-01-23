//--------------------------------------------------------------------------//
//----- D�velopp� par Vuillemenot Kevin ------------------------------------//
//----- Groupe : Valentini, Helene, Ranaldi, Vuillemenot -------------------//
//----- Classe de BTS SN2 --------------------------------------------------//
//----- Dans le cadre du projet m�t�o --------------------------------------//
//----- Comportement des m�thodes de la classe Carte -----------------------//
//--------------------------------------------------------------------------//

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma hdrstop
#include "Carte.h"
//---------------------------------------------------------------------------

// Constructeur qui ouvre la connexion � la carte
K8055::K8055(int AdresseCarte)
{
	if (OpenDevice(AdresseCarte))
	{
		EtatConnexion = true ;
	}
}

// Destructeur qui ferme la connexion � la carte
   K8055::~K8055()
{
	CloseDevice();
}

// M�thode Priv�e qui r�cup�re et traite la temp�rature envoy�e par la carte
void K8055::LectureTemperature(int Canal)
{
	int buffer;
	buffer=ReadAnalogChannel(Canal);
	Temperature=(buffer*90);
	Temperature=(Temperature/255);
	Temperature=(Temperature-30);
}

// M�thode Publique renvoyant l'�tat de la connexion
bool K8055::GetEtatConnexion()
{
	return EtatConnexion;
}

//M�thode Publique qui renvoye la temp�rature
int K8055::GetTemperature(int Canal)
{
	LectureTemperature(Canal);
	return Temperature;
}
