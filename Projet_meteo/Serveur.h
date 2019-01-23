//--------------------------------------------------------------------------//
//----- D�velopp� par Vuillemenot Kevin ------------------------------------//
//----- Groupe : Valentini, Helene, Ranaldi, Vuillemenot -------------------//
//----- Classe de BTS SN2 --------------------------------------------------//
//----- Dans le cadre du projet m�t�o --------------------------------------//
//----- Classe Serveur -----------------------------------------------------//
//--------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
#ifndef ServeurH
#define ServeurH
#include <vcl.h>
#include <IdTCPServer.hpp>
//---------------------------------------------------------------------------//

class Serveur
{
	private:

		// Evenements
		bool EtatConnexionClient ;
		TIdTCPServer *TCP ;
		String RequeteClient ;
		int temperature ;


		// M�thode qui �xecute la connexion au serveur avec un socket
		void  __fastcall Execute(TIdContext* AContext);

		// retourne l'�tat vrai � la connexion serveur
		void __fastcall Connect(TIdContext* AContext);

		// retourne l'�tat faux � la connexion serveur
		void __fastcall Serveur::Disconnect(TIdContext* AContext);


	public:

		// M�thode qui retourne l'�v�nement RequeteClient
		String Reception();


		// Constructeur qui ce connecte au serveur
		Serveur(TComponent* Owner,wchar_t*IP,int Port);

		// Destructeur qui ce deconnecte du serveur
		~Serveur();

		// M�thode qui change l'�v�nement TCP en VRAI
		bool  Lancer();

		// M�thode qui retourne l'�tat de la connexion avec le client
		bool GetEtatClient();

		// M�thode qui r�cup�re la temp�rature
		void GetTemperature(int temp);
};

#endif
