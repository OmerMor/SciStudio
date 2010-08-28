object DlgAddWord: TDlgAddWord
  Left = 270
  Top = 314
  AutoSize = True
  BorderStyle = bsToolWindow
  Caption = 'Add Word'
  ClientHeight = 81
  ClientWidth = 222
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 222
    Height = 25
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label2: TLabel
      Left = 3
      Top = 6
      Width = 72
      Height = 13
      Caption = 'Group Number:'
    end
    object ComboBox1: TComboBox
      Left = 83
      Top = 2
      Width = 137
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 0
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 50
    Width = 222
    Height = 31
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    object Button1: TButton
      Left = 144
      Top = 3
      Width = 75
      Height = 25
      Caption = 'OK'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 67
      Top = 3
      Width = 75
      Height = 25
      Caption = 'Cancel'
      TabOrder = 1
      OnClick = Button2Click
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 25
    Width = 222
    Height = 25
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 2
    object Label1: TLabel
      Left = 3
      Top = 6
      Width = 29
      Height = 13
      Caption = 'Word:'
    end
    object Edit1: TEdit
      Left = 40
      Top = 2
      Width = 179
      Height = 21
      MaxLength = 255
      TabOrder = 0
    end
  end
end
