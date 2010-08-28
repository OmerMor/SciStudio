object Form1: TForm1
  Left = 192
  Top = 107
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'SCI0 Game Recover Utility'
  ClientHeight = 289
  ClientWidth = 409
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 409
    Height = 105
    Align = alTop
    Caption = 'Rebuild Map From Package'
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 24
      Width = 51
      Height = 13
      Caption = 'Package:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 8
      Top = 75
      Width = 69
      Height = 13
      Caption = 'Output Map:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 80
      Top = 75
      Width = 241
      Height = 13
      AutoSize = False
      Caption = 'resource.map'
    end
    object Button1: TButton
      Left = 328
      Top = 72
      Width = 75
      Height = 25
      Caption = 'Go!'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = Button1Click
    end
    object Edit1: TEdit
      Left = 64
      Top = 20
      Width = 265
      Height = 21
      TabOrder = 1
      Text = 'resource.001'
    end
    object CheckBox1: TCheckBox
      Left = 16
      Top = 48
      Width = 161
      Height = 17
      Caption = 'Backup existing map'
      Checked = True
      State = cbChecked
      TabOrder = 2
    end
    object Button4: TButton
      Left = 328
      Top = 18
      Width = 75
      Height = 25
      Caption = 'Browse...'
      TabOrder = 3
      OnClick = Button4Click
    end
  end
  object GroupBox2: TGroupBox
    Left = 0
    Top = 105
    Width = 409
    Height = 105
    Align = alTop
    Caption = 'Rebuild Package From Map'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Visible = False
    object Label4: TLabel
      Left = 80
      Top = 75
      Width = 241
      Height = 13
      AutoSize = False
      Caption = 'resource.001'
    end
    object Label5: TLabel
      Left = 8
      Top = 75
      Width = 69
      Height = 13
      Caption = 'Output Map:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label6: TLabel
      Left = 8
      Top = 24
      Width = 51
      Height = 13
      Caption = 'Package:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Button2: TButton
      Left = 328
      Top = 72
      Width = 75
      Height = 25
      Caption = 'Go!'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = Button2Click
    end
    object CheckBox2: TCheckBox
      Left = 16
      Top = 48
      Width = 161
      Height = 17
      Caption = 'Backup existing package'
      Checked = True
      State = cbChecked
      TabOrder = 1
    end
    object Edit2: TEdit
      Left = 64
      Top = 20
      Width = 265
      Height = 21
      TabOrder = 2
      Text = 'resource.map'
    end
    object Button5: TButton
      Left = 328
      Top = 18
      Width = 75
      Height = 25
      Caption = 'Browse...'
      TabOrder = 3
      OnClick = Button5Click
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 250
    Width = 409
    Height = 39
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object Label7: TLabel
      Left = 7
      Top = 5
      Width = 115
      Height = 13
      Caption = 'By Brian Provinciano'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label8: TLabel
      Left = 7
      Top = 19
      Width = 130
      Height = 13
      Caption = 'http://www.bripro.com'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsUnderline]
      ParentFont = False
    end
    object Button3: TButton
      Left = 320
      Top = 7
      Width = 89
      Height = 26
      Caption = 'Close'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = Button3Click
    end
  end
  object ListBox1: TListBox
    Left = 0
    Top = 210
    Width = 409
    Height = 40
    Align = alClient
    ItemHeight = 13
    TabOrder = 3
  end
  object OpenDialog1: TOpenDialog
    Filter = 'SCI Resource.map|resource.map'
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Left = 288
    Top = 48
  end
  object OpenDialog2: TOpenDialog
    Filter = 
      'SCI Resource package|resource.000;resource.001;resource.002;reso' +
      'urce.003;resource.004;resource.005;resource.006;resource.007;res' +
      'ource.008;resource.009'
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Left = 320
    Top = 48
  end
end
