object DlgPicCommand: TDlgPicCommand
  Left = 296
  Top = 189
  Width = 316
  Height = 292
  BorderStyle = bsSizeToolWin
  Caption = 'Picture Command History'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 0
    Top = 0
    Width = 308
    Height = 17
    Align = alTop
    Alignment = taCenter
    AutoSize = False
    Caption = 'Select position you would like to seek to in the picture.'
    Layout = tlCenter
    WordWrap = True
  end
  object Label2: TLabel
    Left = 0
    Top = 17
    Width = 308
    Height = 19
    Align = alTop
    Alignment = taCenter
    AutoSize = False
    Caption = 'To delete the selected step, click the "delete" button.'
    Layout = tlCenter
    WordWrap = True
  end
  object Label3: TLabel
    Left = 0
    Top = 36
    Width = 308
    Height = 30
    Align = alTop
    Alignment = taCenter
    AutoSize = False
    Caption = 
      'To delete all the steps after and including the selected step, c' +
      'lick the "crop" button.'
    Layout = tlCenter
    WordWrap = True
  end
  object Panel1: TPanel
    Left = 0
    Top = 234
    Width = 308
    Height = 31
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    object Panel2: TPanel
      Left = 54
      Top = 0
      Width = 254
      Height = 31
      Align = alRight
      BevelOuter = bvNone
      TabOrder = 0
      object Button1: TButton
        Left = 17
        Top = 4
        Width = 75
        Height = 25
        Caption = 'Delete'
        TabOrder = 0
        OnClick = Button1Click
      end
      object Button2: TButton
        Left = 92
        Top = 4
        Width = 75
        Height = 25
        Caption = 'Crop'
        TabOrder = 1
        OnClick = Button2Click
      end
      object Button3: TButton
        Left = 175
        Top = 4
        Width = 75
        Height = 25
        Caption = 'OK'
        Default = True
        TabOrder = 2
        OnClick = Button3Click
      end
    end
  end
  object ListBox: TListBox
    Left = 0
    Top = 66
    Width = 308
    Height = 168
    Align = alClient
    ItemHeight = 13
    TabOrder = 1
    OnClick = ListBoxClick
    OnKeyDown = ListBoxKeyDown
  end
end
