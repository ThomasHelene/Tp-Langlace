//--------------------------------------------------------------------------//
//----- Développé par Vuillemenot Kevin ------------------------------------//
//----- Groupe : Valentini, Helene, Ranaldi, Vuillemenot -------------------//
//----- Classe de BTS SN2 --------------------------------------------------//
//----- Dans le cadre du projet météo --------------------------------------//
//----- Classe Carte -------------------------------------------------------//
//--------------------------------------------------------------------------//

//---------------------------------------------------------------------------
#ifndef CarteH
#define CarteH
#include "K8055D.h"
//---------------------------------------------------------------------------

class K8055
{
	private:

			// Evénements
		   int Temperature;
		   bool EtatConnexion;

		   // Méthode Privée qui récupère et traite la température envoyée par la carte
		   void LectureTemperature(int Canal);


	public:

		// Constructeur qui ouvre la connexion à la carte
		K8055(int AdresseCarte);

		// Destructeur qui ferme la connexion à la carte
		~K8055();

		// Méthode Publique renvoyant l'état de la connexion
		bool GetEtatConnexion();

		//Méthode Publique qui renvoye la température
		int GetTemperature(int Canal);
};

#endif
