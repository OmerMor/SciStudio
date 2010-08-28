object DlgNewRoom: TDlgNewRoom
  Left = 216
  Top = 155
  BorderStyle = bsDialog
  Caption = 'New Room Script'
  ClientHeight = 179
  ClientWidth = 277
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  Scaled = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 3
    Top = 11
    Width = 71
    Height = 13
    Caption = 'Room Number:'
  end
  object Label2: TLabel
    Left = 125
    Top = 8
    Width = 27
    Height = 13
    Caption = 'Uses:'
  end
  object Label3: TLabel
    Left = 3
    Top = 104
    Width = 48
    Height = 13
    Caption = 'Directory:'
  end
  object Edit1: TEdit
    Left = 82
    Top = 8
    Width = 33
    Height = 21
    MaxLength = 3
    TabOrder = 0
    Text = '0'
    OnChange = Edit1Change
  end
  object CheckListBox1: TCheckListBox
    Left = 125
    Top = 24
    Width = 150
    Height = 89
    ItemHeight = 13
    Sorted = True
    TabOrder = 1
  end
  object GroupBox1: TGroupBox
    Left = 3
    Top = 32
    Width = 113
    Height = 65
    Caption = 'Pic Number'
    TabOrder = 2
    object Edit2: TEdit
      Left = 58
      Top = 36
      Width = 41
      Height = 21
      MaxLength = 3
      TabOrder = 0
      Text = '0'
    end
    object RadioButton1: TRadioButton
      Left = 8
      Top = 18
      Width = 97
      Height = 17
      Caption = 'Same As Script'
      Checked = True
      TabOrder = 1
      TabStop = True
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 8
      Top = 38
      Width = 48
      Height = 17
      Caption = 'Other'
      TabOrder = 2
      OnClick = RadioButton2Click
    end
  end
  object Edit3: TEdit
    Left = 3
    Top = 120
    Width = 213
    Height = 21
    Color = clBtnFace
    ReadOnly = True
    TabOrder = 3
  end
  object Button1: TButton
    Left = 216
    Top = 120
    Width = 59
    Height = 22
    Caption = 'Browse...'
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 120
    Top = 152
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    TabOrder = 5
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 200
    Top = 152
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 6
    OnClick = Button3Click
  end
end
