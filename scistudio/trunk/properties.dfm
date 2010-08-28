object DlgProperties: TDlgProperties
  Left = 192
  Top = 107
  BorderStyle = bsDialog
  Caption = 'Properties'
  ClientHeight = 316
  ClientWidth = 290
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 290
    Height = 281
    ActivePage = TabSheet1
    Align = alTop
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'General'
      object Label1: TLabel
        Left = 48
        Top = 20
        Width = 76
        Height = 13
        Caption = 'Resource Type:'
      end
      object Label2: TLabel
        Left = 8
        Top = 66
        Width = 41
        Height = 13
        Caption = 'Number:'
      end
      object Bevel1: TBevel
        Left = 8
        Top = 48
        Width = 265
        Height = 2
      end
      object Bevel2: TBevel
        Left = 8
        Top = 96
        Width = 265
        Height = 2
      end
      object Label4: TLabel
        Left = 8
        Top = 138
        Width = 78
        Height = 13
        Caption = 'Package Offset:'
      end
      object Bevel3: TBevel
        Left = 8
        Top = 168
        Width = 265
        Height = 2
      end
      object Label5: TLabel
        Left = 8
        Top = 186
        Width = 81
        Height = 13
        Caption = 'Encoded Length:'
      end
      object Label6: TLabel
        Left = 8
        Top = 210
        Width = 82
        Height = 13
        Caption = 'Decoded Length:'
      end
      object Label7: TLabel
        Left = 8
        Top = 234
        Width = 86
        Height = 13
        Caption = 'Encoding Method:'
      end
      object Label8: TLabel
        Left = 8
        Top = 114
        Width = 44
        Height = 13
        Caption = 'Package:'
      end
      object Image1: TImage
        Left = 8
        Top = 8
        Width = 32
        Height = 32
        Transparent = True
      end
      object cbResourceType: TComboBox
        Left = 128
        Top = 16
        Width = 145
        Height = 21
        Style = csDropDownList
        ItemHeight = 13
        TabOrder = 0
        OnChange = cbResourceTypeChange
      end
      object EdtResourceNumber: TEdit
        Left = 56
        Top = 62
        Width = 200
        Height = 21
        AutoSize = False
        MaxLength = 3
        TabOrder = 1
        OnChange = EdtResourceNumberChange
      end
      object UpDown1: TUpDown
        Left = 255
        Top = 60
        Width = 16
        Height = 24
        Min = 0
        Max = 999
        Position = 0
        TabOrder = 2
        Wrap = False
        OnClick = UpDown1Click
      end
      object PackageOffset: TEdit
        Left = 96
        Top = 134
        Width = 177
        Height = 21
        AutoSize = False
        ParentColor = True
        ReadOnly = True
        TabOrder = 3
      end
      object EncodedLength: TEdit
        Left = 96
        Top = 182
        Width = 177
        Height = 21
        AutoSize = False
        ParentColor = True
        ReadOnly = True
        TabOrder = 4
      end
      object DecodedLength: TEdit
        Left = 96
        Top = 206
        Width = 177
        Height = 21
        AutoSize = False
        ParentColor = True
        ReadOnly = True
        TabOrder = 5
      end
      object EncodingMethod: TEdit
        Left = 96
        Top = 230
        Width = 177
        Height = 21
        AutoSize = False
        ParentColor = True
        ReadOnly = True
        TabOrder = 6
      end
      object Package: TEdit
        Left = 96
        Top = 110
        Width = 177
        Height = 21
        AutoSize = False
        ParentColor = True
        ReadOnly = True
        TabOrder = 7
      end
    end
  end
  object BitBtn1: TButton
    Left = 135
    Top = 288
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    TabOrder = 1
    OnClick = BitBtn1Click
  end
  object BitBtn2: TButton
    Left = 215
    Top = 288
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = BitBtn2Click
  end
end
