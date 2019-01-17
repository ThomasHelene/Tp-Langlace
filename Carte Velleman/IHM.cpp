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
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnConnexionClick(TObject *Sender)
{
// Cr�ation de l'Objet
	carte = new K8055(0);

// on v�rifie si l'on est connect� � la carte
	if(carte->GetEtatConnexion())
	{
	 CercleConnexion->Brush->Color=clLime;
	}
	else
	{
        CercleConnexion->Brush->Color=clRed;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnTempClick(TObject *Sender)
{
	if(carte->GetEtatConnexion())
	{
		LblTemp->Caption=carte->GetTemperature(2);
	}

}
//---------------------------------------------------------------------------

