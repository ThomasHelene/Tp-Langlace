object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 300
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 8
    Top = 0
    Width = 41
    Height = 33
  end
  object Shape2: TShape
    Left = 8
    Top = 52
    Width = 41
    Height = 33
  end
  object Label1: TLabel
    Left = 64
    Top = 8
    Width = 61
    Height = 13
    BiDiMode = bdLeftToRight
    Caption = 'Etat Serveur'
    ParentBiDiMode = False
  end
  object Label2: TLabel
    Left = 64
    Top = 60
    Width = 50
    Height = 13
    Caption = 'Etat Carte'
  end
  object Label3: TLabel
    Left = 32
    Top = 117
    Width = 143
    Height = 13
    Caption = 'Entrez l'#39'adresse ip du Serveur'
  end
  object Label4: TLabel
    Left = 45
    Top = 170
    Width = 124
    Height = 13
    Caption = 'Entrez le Port du Serveur '
  end
  object Label5: TLabel
    Left = 448
    Top = 8
    Width = 31
    Height = 13
    Caption = 'Label5'
  end
  object BtnServ: TButton
    Left = 46
    Top = 224
    Width = 129
    Height = 33
    Caption = 'Lancer le Serveur'
    TabOrder = 0
    OnClick = BtnServClick
  end
  object EdtIp: TEdit
    Left = 48
    Top = 136
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '192.168.65.12'
  end
  object EdtPort: TEdit
    Left = 48
    Top = 189
    Width = 121
    Height = 21
    NumbersOnly = True
    TabOrder = 2
    Text = '1024'
  end
  object MemoConnexions: TMemo
    Left = 288
    Top = 101
    Width = 225
    Height = 164
    Lines.Strings = (
      'Logs:')
    ScrollBars = ssVertical
    TabOrder = 3
  end
  object BtnCarte: TButton
    Left = 200
    Top = 8
    Width = 209
    Height = 25
    Caption = 'Se Connecter '#224' la carte Velleman'
    TabOrder = 4
    OnClick = BtnCarteClick
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 536
    Top = 32
  end
end
