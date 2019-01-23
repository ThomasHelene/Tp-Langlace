//--------------------------------------------------------------------------//
//----- D�velopp� par Vuillemenot Kevin -----------------*------------------//
//----- Groupe : Valentini, Helene, Ranaldi, Vuillemenot -------------------//
//----- Classe de BTS SN2 --------------------------------------------------//
//----- Dans le cadre du projet m�t�o --------------------------------------//
//----- Comportement des m�thodes de la classe Serveur ---------------------//
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

// M�thode qui r�cup�re la temp�rature
void Serveur::GetTemperature(int temp)
{
   temperature = temp ;
}

// Destructeur qui ce deconnecte du serveur
Serveur::~Serveur()
{
	delete TCP ;
}

// M�thode qui change l'�v�nement TCP en VRAI
bool Serveur::Lancer()
{
	TCP->Active = true ;
	return true ;
}

// M�thode qui retourne l'�tat de la connexion avec le client
bool Serveur::GetEtatClient()
{
	return EtatConnexionClient ;
}

// M�thode qui retourne l'�v�nement RequeteClient
String Serveur::Reception()
{
	return RequeteClient ;
}

// M�thode qui �xecute la connexion au serveur avec un socket
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

// retourne l'�tat vrai � la connexion serveur
void __fastcall Serveur::Connect(TIdContext* AContext)
{
	  EtatConnexionClient=true  ;
}

// retourne l'�tat faux � la connexion serveur
void __fastcall Serveur::Disconnect(TIdContext* AContext)
{
	  EtatConnexionClient=false ;
}

