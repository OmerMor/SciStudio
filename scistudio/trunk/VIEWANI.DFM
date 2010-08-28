object DlgViewAni: TDlgViewAni
  Left = 246
  Top = 138
  Width = 252
  Height = 245
  Caption = 'View Animator'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 0
    Top = 0
    Width = 244
    Height = 13
    Align = alTop
    Alignment = taCenter
    Layout = tlCenter
  end
  object TrackBar1: TTrackBar
    Left = 0
    Top = 195
    Width = 244
    Height = 23
    Align = alBottom
    Orientation = trHorizontal
    Frequency = 1
    Position = 0
    SelEnd = 0
    SelStart = 0
    TabOrder = 0
    ThumbLength = 12
    TickMarks = tmTopLeft
    TickStyle = tsAuto
    OnChange = TrackBar1Change
  end
  object Panel1: TPanel
    Left = 0
    Top = 13
    Width = 244
    Height = 23
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    object Label2: TLabel
      Left = 77
      Top = 0
      Width = 79
      Height = 23
      Align = alLeft
      Caption = 'Animation Delay:'
      Layout = tlCenter
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 77
      Height = 23
      Align = alLeft
      AutoSize = True
      EdgeBorders = []
      Flat = True
      HotImages = WndMain.ilEditBarsH
      Images = WndMain.ilEditBars
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        ImageIndex = 47
        OnClick = ToolButton1Click
      end
      object ToolButton2: TToolButton
        Left = 23
        Top = 0
        Enabled = False
        ImageIndex = 48
        OnClick = ToolButton2Click
      end
      object ToolButton3: TToolButton
        Left = 46
        Top = 0
        Enabled = False
        ImageIndex = 53
        OnClick = ToolButton3Click
      end
      object ToolButton4: TToolButton
        Left = 69
        Top = 0
        Width = 8
        ImageIndex = 54
        Style = tbsSeparator
      end
    end
    object TrackBar2: TTrackBar
      Left = 156
      Top = 0
      Width = 88
      Height = 23
      Align = alClient
      Min = 1
      Orientation = trHorizontal
      Frequency = 1
      Position = 1
      SelEnd = 0
      SelStart = 0
      TabOrder = 1
      ThumbLength = 16
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = TrackBar2Change
    end
  end
  object scbView: TScrollBox
    Left = 0
    Top = 36
    Width = 244
    Height = 159
    Align = alClient
    BorderStyle = bsNone
    TabOrder = 2
    object imgView: TImage
      Left = 0
      Top = 0
      Width = 65
      Height = 73
      Stretch = True
    end
    object shpView: TShape
      Left = 16
      Top = 24
      Width = 65
      Height = 65
      Brush.Style = bsClear
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 200
    OnTimer = Timer1Timer
    Left = 80
    Top = 88
  end
  object ImageList1: TImageList
    Left = 114
    Top = 78
  end
end
