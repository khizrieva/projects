object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 402
  ClientWidth = 530
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Edit1: TEdit
    Left = 64
    Top = 176
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object memo1: TMemo
    Left = 288
    Top = 216
    Width = 185
    Height = 89
    TabOrder = 1
  end
  object RadioButton1: TRadioButton
    Left = 56
    Top = 48
    Width = 113
    Height = 17
    Caption = 'chebushev'
    TabOrder = 2
  end
  object RadioButton2: TRadioButton
    Left = 56
    Top = 88
    Width = 113
    Height = 17
    Caption = 'monomial basis'
    TabOrder = 3
  end
  object Button1: TButton
    Left = 288
    Top = 328
    Width = 75
    Height = 25
    Caption = #1076#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 4
    OnClick = Button1Click
  end
  object Memo2: TMemo
    Left = 56
    Top = 264
    Width = 185
    Height = 89
    TabOrder = 5
  end
  object Button2: TButton
    Left = 408
    Top = 328
    Width = 75
    Height = 25
    Caption = 'calculate'
    TabOrder = 6
    OnClick = Button2Click
  end
  object Memo3: TMemo
    Left = 288
    Top = 121
    Width = 185
    Height = 89
    TabOrder = 7
  end
end
