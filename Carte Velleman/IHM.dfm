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
  object CercleConnexion: TShape
    Left = 8
    Top = 0
    Width = 41
    Height = 49
    Shape = stCircle
  end
  object LblTexte: TLabel
    Left = 224
    Top = 36
    Width = 66
    Height = 13
    Caption = 'T'#233'mperature:'
  end
  object LblTemp: TLabel
    Left = 299
    Top = 36
    Width = 3
    Height = 13
  end
  object BtnConnexion: TButton
    Left = 40
    Top = 89
    Width = 75
    Height = 25
    Caption = 'Connexion'
    TabOrder = 0
    OnClick = BtnConnexionClick
  end
  object BtnTemp: TButton
    Left = 8
    Top = 120
    Width = 137
    Height = 25
    Caption = 'Avoir Temperature'
    TabOrder = 1
    OnClick = BtnTempClick
  end
end
