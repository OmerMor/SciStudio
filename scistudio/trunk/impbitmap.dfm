object DlgImpBitmap: TDlgImpBitmap
  Left = 192
  Top = 107
  BorderStyle = bsDialog
  Caption = 'Import Visual Bitmap'
  ClientHeight = 272
  ClientWidth = 330
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
  object Bevel1: TBevel
    Left = 4
    Top = 24
    Width = 322
    Height = 192
  end
  object Image1: TImage
    Left = 5
    Top = 25
    Width = 320
    Height = 190
    OnMouseDown = Image1MouseDown
    OnMouseMove = Image1MouseMove
    OnMouseUp = Image1MouseUp
  end
  object ToolBar3: TToolBar
    Left = 0
    Top = 0
    Width = 330
    Height = 22
    ButtonWidth = 92
    EdgeBorders = []
    Flat = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -9
    Font.Name = 'Tahoma'
    Font.Style = []
    HotImages = WndMain.ilEditBarsH
    Images = WndMain.ilEditBars
    List = True
    ParentFont = False
    ParentShowHint = False
    ShowCaptions = True
    ShowHint = True
    TabOrder = 0
    Wrapable = False
    object ToolButton2: TToolButton
      Left = 0
      Top = 0
      AllowAllUp = True
      Caption = 'Select Bitmap'
      ImageIndex = 105
      OnClick = ToolButton2Click
    end
    object ToolButton5: TToolButton
      Tag = 12
      Left = 92
      Top = 0
      Hint = 'A line which has a max length of 240'
      AllowAllUp = True
      Caption = 'Paste Bitmap'
      ImageIndex = 7
      Style = tbsCheck
      OnClick = ToolButton5Click
    end
    object ToolButton3: TToolButton
      Tag = 11
      Left = 184
      Top = 0
      Hint = 'An absolute line'
      AllowAllUp = True
      Caption = 'Modify Bitmaps'
      ImageIndex = 106
      Style = tbsCheck
    end
    object ToolButton6: TToolButton
      Left = 276
      Top = 0
      Width = 8
      Caption = 'ToolButton6'
      ImageIndex = 52
      Style = tbsSeparator
    end
  end
  object Button1: TButton
    Left = 252
    Top = 220
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 172
    Top = 220
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 2
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 248
    Width = 330
    Height = 24
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = True
    OnDrawPanel = StatusBarDrawPanel
  end
  object BGOpenDialog: TOpenPictureDialog
    Filter = 'Bitmaps (*.bmp)|*.bmp'
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Left = 256
    Top = 99
  end
end
