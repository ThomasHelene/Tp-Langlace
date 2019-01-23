//--------------------------------------------------------------------------//
//----- Développé par Vuillemenot Kevin ------------------------------------//
//----- Groupe : Valentini, Helene, Ranaldi, Vuillemenot -------------------//
//----- Classe de BTS SN2 --------------------------------------------------//
//----- Dans le cadre du projet météo --------------------------------------//
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


		// Méthode qui éxecute la connexion au serveur avec un socket
		void  __fastcall Execute(TIdContext* AContext);

		// retourne l'état vrai à la connexion serveur
		void __fastcall Connect(TIdContext* AContext);

		// retourne l'état faux à la connexion serveur
		void __fastcall Serveur::Disconnect(TIdContext* AContext);


	public:

		// Méthode qui retourne l'événement RequeteClient
		String Reception();


		// Constructeur qui ce connecte au serveur
		Serveur(TComponent* Owner,wchar_t*IP,int Port);

		// Destructeur qui ce deconnecte du serveur
		~Serveur();

		// Méthode qui change l'événement TCP en VRAI
		bool  Lancer();

		// Méthode qui retourne l'état de la connexion avec le client
		bool GetEtatClient();

		// Méthode qui récupère la température
		void GetTemperature(int temp);
};

#endif
