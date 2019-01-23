//--------------------------------------------------------------------------//
//----- Développé par Vuillemenot Kevin ------------------------------------//
//----- Groupe : Valentini, Helene, Ranaldi, Vuillemenot -------------------//
//----- Classe de BTS SN2 --------------------------------------------------//
//----- Dans le cadre du projet météo --------------------------------------//
//----- Comportement des méthodes de la classe Carte -----------------------//
//--------------------------------------------------------------------------//

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma hdrstop
#include "Carte.h"
//---------------------------------------------------------------------------

// Constructeur qui ouvre la connexion à la carte
K8055::K8055(int AdresseCarte)
{
	if (OpenDevice(AdresseCarte))
	{
		EtatConnexion = true ;
	}
}

// Destructeur qui ferme la connexion à la carte
   K8055::~K8055()
{
	CloseDevice();
}

// Méthode Privée qui récupère et traite la température envoyée par la carte
void K8055::LectureTemperature(int Canal)
{
	int buffer;
	buffer=ReadAnalogChannel(Canal);
	Temperature=(buffer*90);
	Temperature=(Temperature/255);
	Temperature=(Temperature-30);
}

// Méthode Publique renvoyant l'état de la connexion
bool K8055::GetEtatConnexion()
{
	return EtatConnexion;
}

//Méthode Publique qui renvoye la température
int K8055::GetTemperature(int Canal)
{
	LectureTemperature(Canal);
	return Temperature;
}
