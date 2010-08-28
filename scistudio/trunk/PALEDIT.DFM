object WndPalEdit: TWndPalEdit
  Left = 194
  Top = 109
  BorderStyle = bsDialog
  Caption = 'Palette Editor'
  ClientHeight = 366
  ClientWidth = 290
  Color = clBtnFace
  Constraints.MinHeight = 364
  Constraints.MinWidth = 208
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object imPal: TImage
    Left = 0
    Top = 22
    Width = 290
    Height = 242
    Align = alClient
    OnMouseDown = imPalMouseDown
  end
  object Panel1: TPanel
    Left = 0
    Top = 264
    Width = 290
    Height = 70
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    object Shape1: TShape
      Left = 5
      Top = 19
      Width = 47
      Height = 49
    end
    object Label1: TLabel
      Left = 61
      Top = 21
      Width = 23
      Height = 13
      Caption = 'Red:'
    end
    object Label2: TLabel
      Left = 61
      Top = 37
      Width = 33
      Height = 13
      Caption = 'Green:'
    end
    object Label3: TLabel
      Left = 61
      Top = 53
      Width = 24
      Height = 13
      Caption = 'Blue:'
    end
    object Label4: TLabel
      Left = 101
      Top = 21
      Width = 18
      Height = 13
      Caption = '000'
    end
    object Label5: TLabel
      Left = 101
      Top = 37
      Width = 18
      Height = 13
      Caption = '000'
    end
    object Label6: TLabel
      Left = 101
      Top = 53
      Width = 18
      Height = 13
      Caption = '000'
    end
    object Shape2: TShape
      Left = 125
      Top = 21
      Width = 15
      Height = 13
    end
    object Shape3: TShape
      Left = 125
      Top = 37
      Width = 15
      Height = 13
    end
    object Shape4: TShape
      Left = 125
      Top = 53
      Width = 15
      Height = 13
    end
    object Label9: TLabel
      Left = 0
      Top = 0
      Width = 290
      Height = 16
      Align = alTop
      AutoSize = False
      Caption = ' Index: 123/234'
      Color = 16553730
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
      Layout = tlCenter
    end
    object SpeedButton1: TSpeedButton
      Left = 6
      Top = 21
      Width = 45
      Height = 46
      Flat = True
      OnClick = Button1Click
    end
    object Button1: TButton
      Left = 148
      Top = 41
      Width = 142
      Height = 25
      Caption = 'Select Colour'
      TabOrder = 0
      OnClick = Button1Click
    end
    object CheckBox1: TCheckBox
      Left = 148
      Top = 21
      Width = 117
      Height = 17
      Caption = 'Colour Is Important'
      TabOrder = 1
      OnClick = CheckBox1Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 334
    Width = 290
    Height = 32
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object Bevel1: TBevel
      Left = 0
      Top = 0
      Width = 290
      Height = 2
      Align = alTop
      Shape = bsTopLine
    end
    object Button4: TButton
      Left = 221
      Top = 5
      Width = 69
      Height = 25
      Caption = 'OK'
      TabOrder = 0
      OnClick = Button4Click
    end
    object Button3: TButton
      Left = 148
      Top = 5
      Width = 69
      Height = 25
      Caption = 'Cancel'
      TabOrder = 1
      OnClick = Button3Click
    end
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 290
    Height = 22
    ButtonWidth = 96
    EdgeBorders = []
    Flat = True
    HotImages = WndMain.ilEditBarsH
    Images = WndMain.ilEditBars
    List = True
    ShowCaptions = True
    TabOrder = 2
    Wrapable = False
    object ToolButton1: TToolButton
      Left = 0
      Top = 0
      Caption = 'Load From File'
      ImageIndex = 1
      OnClick = ToolButton1Click
    end
    object ToolButton2: TToolButton
      Left = 96
      Top = 0
      Caption = 'Save To File'
      ImageIndex = 2
      OnClick = ToolButton2Click
    end
    object ToolButton3: TToolButton
      Left = 192
      Top = 0
      Caption = 'Save To Game'
      ImageIndex = 2
      OnClick = ToolButton3Click
    end
  end
  object ColorDialog1: TColorDialog
    Ctl3D = True
    Options = [cdFullOpen, cdAnyColor]
    Left = 232
    Top = 80
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 200
    OnTimer = Timer1Timer
    Left = 232
    Top = 112
  end
end
