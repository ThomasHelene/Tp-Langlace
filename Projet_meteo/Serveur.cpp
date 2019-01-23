//--------------------------------------------------------------------------//
//----- Développé par Vuillemenot Kevin -----------------*------------------//
//----- Groupe : Valentini, Helene, Ranaldi, Vuillemenot -------------------//
//----- Classe de BTS SN2 --------------------------------------------------//
//----- Dans le cadre du projet météo --------------------------------------//
//----- Comportement des méthodes de la classe Serveur ---------------------//
//--------------------------------------------------------------------------//

//--------------------------------------------------------------------------//
#pragma hdrstop
#pragma package(smart_init)
#include "Serveur.h"
//--------------------------------------------------------------------------//

// Constructeur qui ce connecte au serveur
Serveur::Serveur(TComponent* Owner,wchar_t * Ip, int Port)
{
	TCP=new TIdTCPServer(Owner) ;
	TCP->Bindings->Add() ;
	TCP->Bindings->Items[0]->Port = Port ;
	TCP->Bindings->Items[0]->IP = Ip ;
	TCP->OnExecute = Execute ;
	TCP->OnConnect = Connect ;
	TCP->OnDisconnect=Disconnect ;
}

// Méthode qui récupère la température
void Serveur::GetTemperature(int temp)
{
   temperature = temp ;
}

// Destructeur qui ce deconnecte du serveur
Serveur::~Serveur()
{
	delete TCP ;
}

// Méthode qui change l'événement TCP en VRAI
bool Serveur::Lancer()
{
	TCP->Active = true ;
	return true ;
}

// Méthode qui retourne l'état de la connexion avec le client
bool Serveur::GetEtatClient()
{
	return EtatConnexionClient ;
}

// Méthode qui retourne l'événement RequeteClient
String Serveur::Reception()
{
	return RequeteClient ;
}

// Méthode qui éxecute la connexion au serveur avec un socket
void __fastcall Serveur::Execute(TIdContext* AContext)
{
	String test ;
	test = temperature ;
	test+= "\n\r" ;
	RequeteClient=AContext->Connection->Socket->ReadLn().w_str() ;

	if(RequeteClient == L"temp")
	{
		AContext->Connection->Socket->Write(test) ;
	}
}

// retourne l'état vrai à la connexion serveur
void __fastcall Serveur::Connect(TIdContext* AContext)
{
	  EtatConnexionClient=true  ;
}

// retourne l'état faux à la connexion serveur
void __fastcall Serveur::Disconnect(TIdContext* AContext)
{
	  EtatConnexionClient=false ;
}

