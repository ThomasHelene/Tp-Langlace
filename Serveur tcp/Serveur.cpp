//---------------------------------------------------------------------------

#pragma hdrstop

#include "Serveur.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



Serveur::Serveur(TComponent* Owner,wchar_t * Ip, int Port)
{
	TCP=new TIdTCPServer(Owner);
	 TCP->Bindings->Add();
	TCP->Bindings->Items[0]->Port=Port;
	TCP->Bindings->Items[0]->IP=Ip;



		TCP->OnExecute = Execute;

	TCP->OnConnect = Connect;
	TCP->OnDisconnect=Disconnect;

}
void Serveur::GetTemperature(int temp)
{
   temperature=temp;
}
Serveur::~Serveur()
{
	delete TCP;

}
bool Serveur::Lancer()
{

	TCP->Active=true;

	  return true;

}

bool Serveur::GetEtatClient()
{
	return EtatConnexionClient ;

}


String Serveur::Reception()
{

	return RequeteClient;
}

void __fastcall Serveur::Execute(TIdContext* AContext)
{
		String test;
		test=temperature;
		test+="\n\r";
		RequeteClient=AContext->Connection->Socket->ReadLn().w_str();
		if(RequeteClient == L"temp")
		{

				AContext->Connection->Socket->Write(test);


		}

	}



void __fastcall Serveur::Connect(TIdContext* AContext)
{
	  EtatConnexionClient=true;
}

void __fastcall Serveur::Disconnect(TIdContext* AContext)
{
	  EtatConnexionClient=false;
}
