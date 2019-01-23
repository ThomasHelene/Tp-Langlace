//--------------------------------------------------------------------------//
//----- D�velopp� par Vuillemenot Kevin ------------------------------------//
//----- Groupe : Valentini, Helene, Ranaldi, Vuillemenot -------------------//
//----- Classe de BTS SN2 --------------------------------------------------//
//----- Dans le cadre du projet m�t�o --------------------------------------//
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

			// Ev�nements
		   int Temperature;
		   bool EtatConnexion;

		   // M�thode Priv�e qui r�cup�re et traite la temp�rature envoy�e par la carte
		   void LectureTemperature(int Canal);


	public:

		// Constructeur qui ouvre la connexion � la carte
		K8055(int AdresseCarte);

		// Destructeur qui ferme la connexion � la carte
		~K8055();

		// M�thode Publique renvoyant l'�tat de la connexion
		bool GetEtatConnexion();

		//M�thode Publique qui renvoye la temp�rature
		int GetTemperature(int Canal);
};

#endif
