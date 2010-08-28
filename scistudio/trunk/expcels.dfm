object DlgExpCels: TDlgExpCels
  Left = 294
  Top = 178
  BorderStyle = bsDialog
  Caption = 'Export Cels To Windows Bitmap'
  ClientHeight = 253
  ClientWidth = 342
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  Scaled = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 249
    Top = 12
    Width = 42
    Height = 13
    Caption = 'Spacing:'
  end
  object Button1: TButton
    Left = 262
    Top = 224
    Width = 75
    Height = 25
    Caption = 'Save'
    Default = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 178
    Top = 224
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = Button2Click
  end
  object ScrollBox1: TScrollBox
    Left = 7
    Top = 32
    Width = 329
    Height = 185
    TabOrder = 2
    object Image1: TImage
      Left = 0
      Top = 0
      Width = 105
      Height = 105
      Stretch = True
    end
  end
  object ebSpacing: TEdit
    Left = 298
    Top = 9
    Width = 33
    Height = 21
    MaxLength = 2
    TabOrder = 3
    Text = '1'
    OnChange = rbAllLoopsClick
  end
  object rbCurrentLoop: TRadioButton
    Left = 82
    Top = 10
    Width = 79
    Height = 17
    Caption = 'Current Loop'
    TabOrder = 4
    OnClick = rbAllLoopsClick
  end
  object rbAllLoops: TRadioButton
    Left = 10
    Top = 10
    Width = 71
    Height = 17
    Caption = 'All Loops'
    Checked = True
    TabOrder = 5
    TabStop = True
    OnClick = rbAllLoopsClick
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'bmp'
    Filter = 'Windows Bitmap (*.BMP)|*.bmp|All Files (*.*)|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 202
    Top = 2
  end
end
