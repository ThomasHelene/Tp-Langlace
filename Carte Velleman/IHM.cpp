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
carte = new K8055(0);
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
LblTemp->Caption=carte->GetTemperature(2);

}
//---------------------------------------------------------------------------
