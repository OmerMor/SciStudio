object DlgPrintPrev: TDlgPrintPrev
  Left = 192
  Top = 107
  Width = 544
  Height = 375
  BorderIcons = []
  Caption = 'Print Preview'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  Scaled = False
  WindowState = wsMaximized
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object SynEditPrintPreview1: TSynEditPrintPreview
    Left = 0
    Top = 38
    Width = 536
    Height = 291
    SynEditPrint = WndScriptEdit.SynEditPrint1
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 536
    Height = 38
    AutoSize = True
    ButtonHeight = 36
    ButtonWidth = 57
    Flat = True
    HotImages = WndMain.ilEditBarsH
    Images = WndMain.ilEditBars
    ShowCaptions = True
    TabOrder = 1
    object ToolButton1: TToolButton
      Left = 0
      Top = 0
      Caption = 'Print'
      ImageIndex = 41
      OnClick = ToolButton1Click
    end
    object ToolButton4: TToolButton
      Left = 57
      Top = 0
      Width = 8
      ImageIndex = 2
      Style = tbsSeparator
    end
    object BtnFirst: TToolButton
      Left = 65
      Top = 0
      Caption = 'First Page'
      ImageIndex = 93
      OnClick = BtnFirstClick
    end
    object ToolButton9: TToolButton
      Left = 122
      Top = 0
      Width = 4
      ImageIndex = 2
      Style = tbsSeparator
    end
    object BtnPrev: TToolButton
      Left = 126
      Top = 0
      Caption = 'Prev Page'
      ImageIndex = 91
      OnClick = BtnPrevClick
    end
    object ToolButton10: TToolButton
      Left = 183
      Top = 0
      Width = 4
      ImageIndex = 3
      Style = tbsSeparator
    end
    object BtnNext: TToolButton
      Left = 187
      Top = 0
      Caption = 'Next Page'
      ImageIndex = 92
      OnClick = BtnNextClick
    end
    object ToolButton11: TToolButton
      Left = 244
      Top = 0
      Width = 4
      ImageIndex = 4
      Style = tbsSeparator
    end
    object BtnLast: TToolButton
      Left = 248
      Top = 0
      Caption = 'Last Page'
      ImageIndex = 94
      OnClick = BtnLastClick
    end
    object ToolButton3: TToolButton
      Left = 305
      Top = 0
      Width = 8
      ImageIndex = 2
      Style = tbsSeparator
    end
    object ToolButton5: TToolButton
      Left = 313
      Top = 0
      Caption = 'Zoom In'
      ImageIndex = 24
      OnClick = ToolButton5Click
    end
    object ToolButton6: TToolButton
      Left = 370
      Top = 0
      Caption = 'Zoom Out'
      ImageIndex = 25
      OnClick = ToolButton6Click
    end
    object ToolButton7: TToolButton
      Left = 427
      Top = 0
      Width = 8
      ImageIndex = 4
      Style = tbsSeparator
    end
    object ToolButton2: TToolButton
      Left = 435
      Top = 0
      Caption = 'Close'
      ImageIndex = 28
      OnClick = ToolButton2Click
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 329
    Width = 536
    Height = 19
    Panels = <
      item
        Width = 100
      end
      item
        Width = 100
      end>
    SimplePanel = False
  end
end
