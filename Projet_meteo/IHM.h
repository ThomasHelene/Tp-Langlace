//--------------------------------------------------------------------------//
//----- Développé par Vuillemenot Kevin ------------------------------------//
//----- Groupe : Valentini, Helene, Ranaldi, Vuillemenot -------------------//
//----- Classe de BTS SN2 --------------------------------------------------//
//----- Dans le cadre du projet météo --------------------------------------//
//----- Classe TForm1 (IHM) ------------------------------------------------//
//--------------------------------------------------------------------------//

//---------------------------------------------------------------------------
#ifndef IHMH
#define IHMH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPServer.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "Serveur.h"
#include "Carte.h"
#include <IdCmdTCPServer.hpp>
//---------------------------------------------------------------------------

class TForm1 : public TForm
{
	// Composants gérés par l'EDI
	__published:
		TButton *BtnServ;
		TShape *Shape1;
		TEdit *EdtIp;
		TEdit *EdtPort;
		TTimer *Timer1;
		TMemo *MemoConnexions;
		TShape *Shape2;
		TLabel *Label1;
		TLabel *Label2;
		TLabel *Label3;
		TLabel *Label4;
		TButton *BtnCarte;
		TLabel *Label5;

		void __fastcall BtnServClick(TObject *Sender);
		void __fastcall Timer1Timer(TObject *Sender);
		void __fastcall BtnCarteClick(TObject *Sender);

	private:

		// Déclarations utilisateur
		Serveur *serv;
		K8055 * carte;
		int temperature;

	public:

		// Déclarations utilisateur
		__fastcall TForm1(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
