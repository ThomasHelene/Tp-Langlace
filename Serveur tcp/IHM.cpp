//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IHM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
  serv= new Serveur(this,EdtIp->Text.c_str(),EdtPort->Text.ToInt());
  serv->GetTemperature(50);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnServClick(TObject *Sender)
{

	if(serv->Lancer())
	{
	 Shape1->Brush->Color=clLime;
	 MemoConnexions->Lines->Add("Le Serveur est lanc�.");
	}

Timer1->Enabled=true;


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
// On v�rifie si le client est toujours connect�.
// On actualise du coup la couleur du cercle , en fonction de l'�tat de la connexion
	if(serv->GetEtatClient()==true)
	{
	   Shape2->Brush->Color=clLime;
	   MemoConnexions->Lines->Add(serv->Reception());

	}
	else
	{
		Shape2->Brush->Color=clRed;
    }
}
//---------------------------------------------------------------------------
