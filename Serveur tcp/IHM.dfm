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
    Top = 41
    Width = 41
    Height = 33
  end
  object BtnServ: TButton
    Left = 8
    Top = 144
    Width = 129
    Height = 33
    Caption = 'Lancer le Serveur'
    TabOrder = 0
    OnClick = BtnServClick
  end
  object EdtIp: TEdit
    Left = 8
    Top = 80
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '192.168.65.9'
  end
  object EdtPort: TEdit
    Left = 8
    Top = 107
    Width = 121
    Height = 21
    NumbersOnly = True
    TabOrder = 2
    Text = '1024'
  end
  object MemoConnexions: TMemo
    Left = 288
    Top = 80
    Width = 225
    Height = 164
    Lines.Strings = (
      'Logs:')
    ScrollBars = ssVertical
    TabOrder = 3
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 536
    Top = 32
  end
end
