object DlgAddResource: TDlgAddResource
  Left = 194
  Top = 109
  BorderStyle = bsToolWindow
  Caption = 'Add Resource to Game'
  ClientHeight = 125
  ClientWidth = 192
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
  object Label2: TLabel
    Left = 8
    Top = 75
    Width = 128
    Height = 13
    Caption = 'Resource Number (0-999):'
    Color = clBtnFace
    ParentColor = False
    Transparent = True
  end
  object Label1: TLabel
    Left = 8
    Top = 48
    Width = 130
    Height = 13
    Caption = 'Save in Resource Package:'
    Color = clBtnFace
    ParentColor = False
    Transparent = True
  end
  object ResourceName: TLabel
    Left = 2
    Top = 4
    Width = 188
    Height = 17
    Alignment = taCenter
    AutoSize = False
    Layout = tlCenter
  end
  object Label3: TLabel
    Left = 2
    Top = 22
    Width = 188
    Height = 17
    Alignment = taCenter
    AutoSize = False
    Layout = tlCenter
  end
  object ButtonOK1: TButton
    Left = 22
    Top = 97
    Width = 69
    Height = 25
    Caption = '&OK'
    Default = True
    TabOrder = 0
    OnClick = ButtonOK1Click
  end
  object ButtonCancel1: TButton
    Left = 100
    Top = 97
    Width = 69
    Height = 25
    Caption = '&Cancel'
    TabOrder = 1
    OnClick = ButtonCancel1Click
  end
  object PackageEdit: TEdit
    Left = 141
    Top = 44
    Width = 29
    Height = 21
    AutoSize = False
    MaxLength = 2
    TabOrder = 2
    Text = '1'
    OnChange = NumberEditChange
  end
  object NumberEdit: TEdit
    Left = 141
    Top = 70
    Width = 29
    Height = 21
    AutoSize = False
    MaxLength = 3
    TabOrder = 3
    Text = '0'
    OnChange = NumberEditChange
  end
  object UpDown1: TUpDown
    Left = 169
    Top = 42
    Width = 16
    Height = 24
    Min = 0
    Max = 999
    Position = 0
    TabOrder = 4
    Wrap = False
    OnClick = UpDown1Click
  end
  object UpDown2: TUpDown
    Left = 169
    Top = 68
    Width = 16
    Height = 24
    Min = 0
    Max = 999
    Position = 0
    TabOrder = 5
    Wrap = False
    OnClick = UpDown2Click
  end
end
