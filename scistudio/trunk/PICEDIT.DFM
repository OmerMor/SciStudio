object WndPicEdit: TWndPicEdit
  Left = 223
  Top = 173
  Width = 577
  Height = 375
  Caption = 'Picture Editor'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object CoolBar1: TCoolBar
    Left = 0
    Top = 0
    Width = 569
    Height = 97
    AutoSize = True
    Bands = <
      item
        Control = MenuBar1
        HorizontalOnly = True
        ImageIndex = -1
        MinHeight = 21
        Width = 183
      end
      item
        Break = False
        Control = Panel2
        ImageIndex = -1
        MinHeight = 21
        Width = 380
      end
      item
        Control = ToolBar1
        HorizontalOnly = True
        ImageIndex = -1
        MinHeight = 22
        Width = 157
      end
      item
        Break = False
        Control = ToolBar2
        ImageIndex = -1
        MinHeight = 22
        Width = 406
      end
      item
        Control = ToolBar4
        HorizontalOnly = True
        ImageIndex = -1
        MinHeight = 22
        Width = 565
      end
      item
        Control = ToolBar3
        ImageIndex = -1
        MinHeight = 22
        Width = 565
      end>
    object MenuBar1: TMenuBar
      Left = 9
      Top = 0
      Width = 170
      Height = 21
      Align = alNone
      AutoSize = True
      ButtonHeight = 21
      ButtonWidth = 63
      Constraints.MaxHeight = 21
      Constraints.MinWidth = 170
      Flat = True
      ShowCaptions = True
      TabOrder = 0
      Menu = MainMenu1
    end
    object ToolBar1: TToolBar
      Left = 9
      Top = 23
      Width = 144
      Height = 22
      Align = alNone
      EdgeBorders = []
      Flat = True
      HotImages = WndMain.ilEditBarsH
      Images = WndMain.ilEditBars
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      Transparent = True
      Wrapable = False
      object sbNew: TToolButton
        Left = 0
        Top = 0
        Hint = 'New Picture'
        ImageIndex = 0
        OnClick = New1Click
      end
      object sbOpen: TToolButton
        Left = 23
        Top = 0
        Hint = 'Open Picture'
        ImageIndex = 1
        OnClick = Open1Click
      end
      object sbSave: TToolButton
        Left = 46
        Top = 0
        Hint = 'Save Picture'
        ImageIndex = 2
        OnClick = Save1Click
      end
      object sbLoadBackground: TToolButton
        Left = 69
        Top = 0
        Hint = 'Import Background Image'
        ImageIndex = 3
        OnClick = LoadTracingImage1Click
      end
      object ToolButton8: TToolButton
        Left = 92
        Top = 0
        Width = 2
        ImageIndex = 5
        Style = tbsSeparator
      end
      object sbCopy: TToolButton
        Left = 94
        Top = 0
        Hint = 'Copy Screen Image To Clipboard'
        ImageIndex = 6
        OnClick = Copy1Click
      end
      object sbPasteBackground: TToolButton
        Left = 117
        Top = 0
        Hint = 'Paste Background Image'
        ImageIndex = 7
        OnClick = PasteTracingImage1Click
      end
    end
    object ToolBar4: TToolBar
      Left = 9
      Top = 47
      Width = 552
      Height = 22
      Align = alNone
      ButtonWidth = 69
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
      TabOrder = 2
      Wrapable = False
      object sbOff: TToolButton
        Left = 0
        Top = 0
        AllowAllUp = True
        Caption = 'Off'
        ImageIndex = 29
        Style = tbsCheck
        OnClick = ToolClick
      end
      object sbLine12: TToolButton
        Tag = 1
        Left = 69
        Top = 0
        Hint = 'An absolute line'
        AllowAllUp = True
        Caption = 'Line'
        ImageIndex = 9
        Style = tbsCheck
        OnClick = ToolClick
      end
      object sbLine7: TToolButton
        Tag = 2
        Left = 138
        Top = 0
        Hint = 'A line which has a max length of 240'
        AllowAllUp = True
        Caption = 'Short Line'
        ImageIndex = 51
        Style = tbsCheck
        OnClick = ToolClick
      end
      object sbLine3: TToolButton
        Tag = 3
        Left = 207
        Top = 0
        Hint = 'A line with a max length of 8 pixels'
        AllowAllUp = True
        Caption = 'Tiny Line'
        ImageIndex = 52
        Style = tbsCheck
        OnClick = ToolClick
      end
      object sbFill: TToolButton
        Tag = 4
        Left = 276
        Top = 0
        Hint = 'Flood fill'
        AllowAllUp = True
        Caption = 'Fill'
        ImageIndex = 10
        Style = tbsCheck
        OnClick = ToolClick
      end
      object sbPenAbs: TToolButton
        Tag = 5
        Left = 345
        Top = 0
        Hint = 'An absolute pen draw'
        AllowAllUp = True
        Caption = 'Pen'
        ImageIndex = 8
        Style = tbsCheck
        OnClick = ToolClick
      end
      object sbPenNear: TToolButton
        Tag = 6
        Left = 414
        Top = 0
        Caption = 'Near Pen'
        ImageIndex = 90
        OnClick = ToolClick
      end
      object sbPenClose: TToolButton
        Tag = 7
        Left = 483
        Top = 0
        Hint = 'An difference pen draw'
        AllowAllUp = True
        Caption = 'Close Pen'
        ImageIndex = 50
        Style = tbsCheck
        OnClick = ToolClick
      end
    end
    object Panel2: TPanel
      Left = 194
      Top = 0
      Width = 321
      Height = 21
      AutoSize = True
      BevelOuter = bvNone
      TabOrder = 3
      object Label1: TLabel
        Left = 0
        Top = 0
        Width = 48
        Height = 21
        Align = alLeft
        Caption = 'Screen:  '
        Constraints.MinHeight = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        Layout = tlCenter
      end
      object Bevel8: TBevel
        Left = 182
        Top = 0
        Width = 9
        Height = 21
        Align = alLeft
        Shape = bsSpacer
      end
      object Label3: TLabel
        Left = 191
        Top = 0
        Width = 50
        Height = 21
        Align = alLeft
        Caption = 'Palette:  '
        Constraints.MinHeight = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        Layout = tlCenter
      end
      object ToolBar5: TToolBar
        Left = 48
        Top = 0
        Width = 134
        Height = 21
        Align = alLeft
        ButtonHeight = 21
        ButtonWidth = 42
        EdgeBorders = []
        Flat = True
        ShowCaptions = True
        TabOrder = 0
        Transparent = True
        Wrapable = False
        object tbVisual: TToolButton
          Left = 0
          Top = 0
          Caption = 'Visual'
          Down = True
          Grouped = True
          ImageIndex = 0
          Style = tbsCheck
          OnClick = ScreenClick
        end
        object tbPriority: TToolButton
          Tag = 1
          Left = 42
          Top = 0
          Caption = 'Priority'
          Grouped = True
          ImageIndex = 1
          Style = tbsCheck
          OnClick = ScreenClick
        end
        object tbControl: TToolButton
          Tag = 2
          Left = 84
          Top = 0
          Caption = 'Control'
          Grouped = True
          ImageIndex = 2
          Style = tbsCheck
          OnClick = ScreenClick
        end
      end
      object ToolBar6: TToolBar
        Left = 241
        Top = 0
        Width = 80
        Height = 21
        Align = alLeft
        ButtonHeight = 21
        ButtonWidth = 19
        EdgeBorders = []
        Flat = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        ShowCaptions = True
        TabOrder = 1
        Transparent = True
        Wrapable = False
        object tbPal0: TToolButton
          Left = 0
          Top = 0
          Caption = ' 0 '
          Down = True
          Grouped = True
          ImageIndex = 0
          Style = tbsCheck
          OnClick = PaletteClick
        end
        object tbPal1: TToolButton
          Tag = 1
          Left = 19
          Top = 0
          Caption = ' 1 '
          Grouped = True
          ImageIndex = 1
          Style = tbsCheck
          OnClick = PaletteClick
        end
        object tbPal2: TToolButton
          Tag = 2
          Left = 38
          Top = 0
          Caption = ' 2 '
          Grouped = True
          ImageIndex = 2
          Style = tbsCheck
          OnClick = PaletteClick
        end
        object tbPal3: TToolButton
          Tag = 3
          Left = 57
          Top = 0
          Caption = ' 3 '
          Grouped = True
          ImageIndex = 3
          Style = tbsCheck
          OnClick = PaletteClick
        end
      end
    end
    object ToolBar2: TToolBar
      Left = 168
      Top = 23
      Width = 393
      Height = 22
      Align = alNone
      EdgeBorders = []
      Flat = True
      HotImages = WndMain.ilEditBarsH
      Images = WndMain.ilEditBars
      ParentShowHint = False
      ShowHint = True
      TabOrder = 4
      Transparent = True
      Wrapable = False
      object tbTracingBitmap: TToolButton
        Left = 0
        Top = 0
        AllowAllUp = True
        Caption = 'tbTracingBitmap'
        ImageIndex = 87
        OnClick = ShowTracingImage1Click
      end
      object tbPriLines: TToolButton
        Left = 23
        Top = 0
        AllowAllUp = True
        Caption = 'tbPriLines'
        ImageIndex = 89
        OnClick = ShowPriorityBars1Click
      end
      object ToolButton4: TToolButton
        Left = 46
        Top = 0
        Width = 8
        AllowAllUp = True
        Caption = 'ToolButton4'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButton1: TToolButton
        Tag = 8
        Left = 54
        Top = 0
        AllowAllUp = True
        Caption = 'ToolButton1'
        ImageIndex = 67
        Style = tbsCheck
        OnClick = ToolClick
      end
    end
    object ToolBar3: TToolBar
      Left = 9
      Top = 71
      Width = 552
      Height = 22
      Align = alNone
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
      TabOrder = 5
      Wrapable = False
      object ToolButton9: TToolButton
        Tag = 9
        Left = 0
        Top = 0
        Caption = 'Rectangle'
        Enabled = False
        ImageIndex = 13
        Style = tbsCheck
        OnClick = ToolClick
      end
      object ToolButton7: TToolButton
        Tag = 10
        Left = 92
        Top = 0
        Caption = 'Ellipse'
        Enabled = False
        ImageIndex = 11
        Style = tbsCheck
        OnClick = ToolClick
      end
      object ToolButton6: TToolButton
        Left = 184
        Top = 0
        Width = 8
        Caption = 'ToolButton6'
        ImageIndex = 52
        Style = tbsSeparator
      end
      object ToolButton2: TToolButton
        Left = 192
        Top = 0
        AllowAllUp = True
        Caption = 'Add Bitmap'
        Enabled = False
        ImageIndex = 105
        OnClick = ToolButton2Click
      end
      object ToolButton3: TToolButton
        Tag = 11
        Left = 284
        Top = 0
        Hint = 'An absolute line'
        AllowAllUp = True
        Caption = 'Modify Bitmaps'
        Enabled = False
        ImageIndex = 106
        Style = tbsCheck
        OnClick = ToolClick
      end
      object ToolButton5: TToolButton
        Tag = 12
        Left = 376
        Top = 0
        Hint = 'A line which has a max length of 240'
        AllowAllUp = True
        Caption = 'Set Priorities'
        Enabled = False
        ImageIndex = 108
        Style = tbsCheck
        OnClick = ToolClick
      end
    end
  end
  object ScrollBox1: TScrollBox
    Left = 0
    Top = 97
    Width = 569
    Height = 217
    Align = alClient
    Color = clAppWorkSpace
    ParentColor = False
    TabOrder = 1
    OnMouseMove = pbSurfaceMouseMove
    OnResize = ScrollBox1Resize
    object pbSurface: TPaintBox
      Left = 0
      Top = 0
      Width = 320
      Height = 190
      ParentShowHint = False
      ShowHint = False
      OnMouseDown = pbSurfaceMouseDown
      OnMouseMove = pbSurfaceMouseMove
      OnMouseUp = pbSurfaceMouseUp
      OnPaint = pbSurfacePaint
    end
  end
  object pnPicBar: TPanel
    Left = 0
    Top = 314
    Width = 569
    Height = 34
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 2
    OnResize = pnPicBarResize
    object Panel4: TPanel
      Left = 489
      Top = 2
      Width = 40
      Height = 30
      Align = alRight
      AutoSize = True
      BevelOuter = bvNone
      TabOrder = 0
      object SpeedButton8: TSpeedButton
        Left = 20
        Top = 0
        Width = 20
        Height = 30
        Flat = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -9
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000000000000000000000000000000000000FE00FEFE00FE
          FE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00
          FEFE00FEFE00FEFE00FEFE00FEFE00FE828282828282FE00FEFE00FEFE00FEFE
          00FEFE00FE828282828282FE00FEFE00FEFE00FEFE00FEFE00FEFE00FE000000
          000000828282828282FE00FEFE00FEFE00FE000000000000828282828282FE00
          FEFE00FEFE00FEFE00FE000000FF6060FF6060000000828282828282FE00FE00
          0000FF6060FF6060000000828282828282FE00FEFE00FEFE00FE000000FFC680
          FC9702FF6060000000828282828282000000FFC680FC9702FF60600000008282
          82828282FE00FEFE00FEFE00FE000000FFC680FC9702FF606000000082828282
          8282000000FFC680FC9702FF6060000000828282828282FE00FEFE00FEFE00FE
          000000FFC680FC9702FF6060000000828282828282000000FFC680FC9702FF60
          60000000828282828282FE00FEFE00FEFE00FE000000FFC680FC9702FF606000
          0000828282828282000000FFC680FC9702FF6060000000828282FE00FEFE00FE
          FE00FE828282000000FFC680FC9702000000828282FE00FE828282000000FFC6
          80FC9702000000828282FE00FEFE00FE828282000000FF6060FC9702FFC68000
          0000828282828282000000FF6060FC9702FFC680000000FE00FEFE00FE828282
          000000FF6060FC9702FFC680000000FE00FE828282000000FF6060FC9702FFC6
          80000000FE00FEFE00FEFE00FE000000FF6060FC9702FFC680000000FE00FEFE
          00FE000000FF6060FC9702FFC680000000FE00FEFE00FEFE00FE000000FF6060
          FC9702FFC680000000FE00FEFE00FE000000FF6060FC9702FFC680000000FE00
          FEFE00FEFE00FEFE00FE000000FFC680FFC680000000FE00FEFE00FEFE00FE00
          0000FFC680FFC680000000FE00FEFE00FEFE00FEFE00FEFE00FEFE00FE000000
          000000FE00FEFE00FEFE00FEFE00FEFE00FE000000000000FE00FEFE00FEFE00
          FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE
          00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE}
        ParentFont = False
        OnClick = SpeedButton8Click
      end
      object SpeedButton9: TSpeedButton
        Left = 0
        Top = 0
        Width = 20
        Height = 30
        Flat = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -9
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000000000000000000000000000000000000FE00FEFE00FE
          FE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00
          FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE82828282
          8282FE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE
          FE00FEFE00FEFE00FE000000000000828282828282FE00FEFE00FEFE00FEFE00
          FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE000000FF6060FF606000
          0000828282828282FE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE
          FE00FEFE00FE000000FFC680FC9702FF6060000000828282828282FE00FEFE00
          FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE000000FFC680FC
          9702FF6060000000828282828282FE00FEFE00FEFE00FEFE00FEFE00FEFE00FE
          FE00FEFE00FEFE00FEFE00FE000000FFC680FC9702FF60600000008282828282
          82FE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE00
          0000FFC680FC9702FF6060000000828282FE00FEFE00FEFE00FEFE00FEFE00FE
          FE00FEFE00FEFE00FEFE00FEFE00FE828282000000FFC680FC97020000008282
          82FE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE82828200
          0000FF6060FC9702FFC680000000FE00FEFE00FEFE00FEFE00FEFE00FEFE00FE
          FE00FEFE00FEFE00FE828282000000FF6060FC9702FFC680000000FE00FEFE00
          FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE000000FF6060FC
          9702FFC680000000FE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE
          FE00FEFE00FE000000FF6060FC9702FFC680000000FE00FEFE00FEFE00FEFE00
          FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE000000FFC680FFC68000
          0000FE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE
          FE00FEFE00FEFE00FE000000000000FE00FEFE00FEFE00FEFE00FEFE00FEFE00
          FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE
          00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE}
        ParentFont = False
        OnClick = SpeedButton9Click
      end
    end
    object Panel5: TPanel
      Left = 333
      Top = 2
      Width = 156
      Height = 30
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 1
      object ImgData: TImage
        Left = 0
        Top = 0
        Width = 156
        Height = 30
        Align = alClient
      end
    end
    object Panel6: TPanel
      Left = 258
      Top = 2
      Width = 75
      Height = 30
      Align = alLeft
      AutoSize = True
      BevelOuter = bvNone
      TabOrder = 2
      object SpeedButton10: TSpeedButton
        Left = 55
        Top = 0
        Width = 20
        Height = 30
        Flat = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -9
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000000000000000000000000000000000000FE00FEFE00FE
          FE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00
          FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE
          00FEFE00FE828282828282828282FE00FEFE00FEFE00FEFE00FEFE00FEFE00FE
          FE00FEFE00FEFE00FEFE00FEFE00FEFE00FE8282820000000000008282828282
          82FE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE82
          8282000000FF6060FF6060000000828282FE00FEFE00FEFE00FEFE00FEFE00FE
          FE00FEFE00FEFE00FEFE00FE828282000000FF6060FC9702FFC680000000FE00
          FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE828282000000FF
          6060FC9702FFC680000000FE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE
          FE00FEFE00FE828282000000FF6060FC9702FFC680000000FE00FEFE00FEFE00
          FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE000000FF6060FC9702FF
          C680000000FE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE
          FE00FEFE00FE000000FC9702FFC680000000828282828282FE00FEFE00FEFE00
          FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE000000FFC680FC9702FF
          6060000000828282828282FE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE
          FE00FEFE00FEFE00FE000000FFC680FC9702FF6060000000828282828282FE00
          FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE000000FF
          C680FC9702FF6060000000828282828282FE00FEFE00FEFE00FEFE00FEFE00FE
          FE00FEFE00FEFE00FEFE00FEFE00FE000000FFC680FC9702FF60600000008282
          82FE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE
          00FE000000FFC680FFC680000000FE00FEFE00FEFE00FEFE00FEFE00FEFE00FE
          FE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE000000000000FE00FEFE00
          FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE
          00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE}
        ParentFont = False
        OnClick = SpeedButton10Click
      end
      object SpeedButton11: TSpeedButton
        Left = 35
        Top = 0
        Width = 20
        Height = 30
        Flat = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -9
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          1800000000000003000000000000000000000000000000000000FE00FEFE00FE
          FE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00
          FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE82828282828282
          8282FE00FEFE00FEFE00FEFE00FE828282828282828282FE00FEFE00FEFE00FE
          FE00FEFE00FE828282000000000000828282828282FE00FEFE00FE8282820000
          00000000828282828282FE00FEFE00FEFE00FE828282000000FF6060FF606000
          0000828282FE00FE828282000000FF6060FF6060000000828282FE00FEFE00FE
          828282000000FF6060FC9702FFC680000000FE00FE828282000000FF6060FC97
          02FFC680000000FE00FEFE00FE828282000000FF6060FC9702FFC680000000FE
          00FE828282000000FF6060FC9702FFC680000000FE00FEFE00FE828282000000
          FF6060FC9702FFC680000000FE00FE828282000000FF6060FC9702FFC6800000
          00FE00FEFE00FEFE00FE000000FF6060FC9702FFC680000000FE00FEFE00FE00
          0000FF6060FC9702FFC680000000FE00FEFE00FEFE00FEFE00FE000000FC9702
          FFC680000000828282828282FE00FE000000FC9702FFC6800000008282828282
          82FE00FEFE00FEFE00FE000000FFC680FC9702FF606000000082828282828200
          0000FFC680FC9702FF6060000000828282828282FE00FEFE00FEFE00FE000000
          FFC680FC9702FF6060000000828282828282000000FFC680FC9702FF60600000
          00828282828282FE00FEFE00FEFE00FE000000FFC680FC9702FF606000000082
          8282828282000000FFC680FC9702FF6060000000828282828282FE00FEFE00FE
          FE00FE000000FFC680FC9702FF6060000000828282FE00FE000000FFC680FC97
          02FF6060000000828282FE00FEFE00FEFE00FEFE00FE000000FFC680FFC68000
          0000FE00FEFE00FEFE00FE000000FFC680FFC680000000FE00FEFE00FEFE00FE
          FE00FEFE00FEFE00FE000000000000FE00FEFE00FEFE00FEFE00FEFE00FE0000
          00000000FE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE
          00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FEFE00FE}
        ParentFont = False
        OnClick = SpeedButton11Click
      end
      object SpeedButton1: TSpeedButton
        Left = 0
        Top = 15
        Width = 35
        Height = 15
        Hint = 'Use to clear any picture data after the current position'
        Flat = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -9
        Font.Name = 'Tahoma'
        Font.Style = []
        Glyph.Data = {
          66030000424D66030000000000003600000028000000160000000C0000000100
          1800000000003003000000000000000000000000000000000000C8D0D4C8D0D4
          C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0
          D4C8D0D4C8D0D4C8D0D4C8D0D4828282C8D0D4C8D0D4C8D0D4C8D0D40000C8D0
          D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8
          D0D4C8D0D4C8D0D4C8D0D4C8D0D4000000808080828282C8D0D4C8D0D4C8D0D4
          0000C8D0D4C8D0D4C8D0D4C8D0D4828282828282828282C8D0D4C8D0D4828282
          C8D0D4C8D0D4C8D0D4828282828282000000FC9702000000828282828282C8D0
          D4C8D0D40000C8D0D4C8D0D4C8D0D40000000000000000008282828282820000
          00828282828282828282000000000000828282000000FFC68000000000000082
          8282828282C8D0D40000C8D0D4C8D0D4000000FFC680FC9702FC970200000000
          0000FC9702000000828282000000FC9702FC9702000000000000FFC680FFC680
          FC97020000008282828282820000C8D0D4000000FFC680000000000000000000
          FC9702000000FFC680000000000000FFC680000000000000FC9702000000FFFF
          FF000000000000FFC6800000008282820000000000FFFFFF000000828282C8D0
          D4C8D0D4000000000000FFFFFF000000000000FFFFFF000000000000FFC68000
          0000FFFFFF000000000000FFC6800000008282820000000000FFFFFF00000082
          8282C8D0D4C8D0D4828282000000FFFFFFFFC680000000FFFFFF000000000000
          FFC680000000FFFFFF000000000000FFC680000000C8D0D40000000000FFFFFF
          000000828282828282828282000000000000FFFFFF000000FFFFFF000000FFFF
          FFFFC680000000000000FFFFFFFFFFFFFFC680000000828282C8D0D40000C8D0
          D4000000FFFFFF000000000000000000FFC680000000000000C8D0D4000000C8
          D0D4000000000000C8D0D4C8D0D4000000000000000000C8D0D4C8D0D4C8D0D4
          0000C8D0D4C8D0D4000000FFFFFFFFFFFFFFC680000000828282C8D0D4C8D0D4
          C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0
          D4C8D0D40000C8D0D4C8D0D4C8D0D4000000000000000000C8D0D4C8D0D4C8D0
          D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8
          D0D4C8D0D4C8D0D40000}
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        OnClick = SpeedButton1Click
      end
      object SpeedButton2: TSpeedButton
        Left = 0
        Top = 0
        Width = 35
        Height = 15
        Hint = 'Use to clear any picture data after the current position'
        Flat = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -9
        Font.Name = 'Tahoma'
        Font.Style = []
        Glyph.Data = {
          FE030000424DFE0300000000000036000000280000001D0000000B0000000100
          180000000000C803000000000000000000000000000000000000C8D0D4C8D0D4
          828282828282828282828282C8D0D4C8D0D4C8D0D4C8D0D48282828282828282
          82C8D0D4828282C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4828282C8
          D0D4C8D0D4828282828282828282C8D0D400C8D0D40000000000000000000000
          00828282828282C8D0D4C8D0D400000000000000000082828200000082828282
          8282000000000000000000828282828282000000828282828282000000000000
          00000082828282828200000000FFC680FC9702FC9702FC970200000082828282
          8282000000FFC680FC9702FC9702000000FC9702000000000000FFC680FC9702
          FC9702000000000000FC9702000000000000FFC680FC9702FC9702000000C8D0
          D400000000FFC680000000000000000000FFC680000000000000FFFFFF000000
          000000000000000000FFC680000000FFFFFF000000000000000000000000FFC6
          80000000000000FFFFFF00000000000000000082828282828200000000FFC680
          000000828282C8D0D4000000FFC680000000FFFFFFFFC680FFC680FFC6800000
          00FFC680000000FFFFFFFFC680FFC680FFC680000000FFC680000000000000FF
          FFFFFFC680FFC680FFC68000000082828200000000FFFFFF000000828282C8D0
          D4000000FFC680000000FFFFFF000000000000FFC680000000FFC680000000FF
          FFFF000000000000FFC680000000FFC680000000000000FFFFFF000000000000
          FFFFFF000000C8D0D400000000FFFFFF000000828282828282000000FFC68000
          0000000000FFFFFFFFC680000000000000FFC680000000000000FFFFFFFFC680
          000000000000FFC680FFFFFF000000000000FFFFFFFFC680000000C8D0D4C8D0
          D400000000FFFFFF000000000000000000FFC680000000828282C8D0D4000000
          000000828282000000FFFFFF000000828282000000000000C8D0D4000000FFFF
          FF000000828282C8D0D4000000000000C8D0D4C8D0D4C8D0D400000000FFFFFF
          FFFFFFFFC680FFC680000000828282C8D0D4C8D0D4C8D0D4C8D0D4C8D0D40000
          00FFFFFF000000828282C8D0D4C8D0D4C8D0D4C8D0D4000000C8D0D4C8D0D4C8
          D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D400C8D0D40000000000000000000000
          00C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4000000FFFFFF00000082
          8282C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4
          C8D0D4C8D0D4C8D0D400C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8
          D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4000000C8D0D4C8D0D4C8D0D4C8D0D4
          C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0D4C8D0
          D400}
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        OnClick = SpeedButton2Click
      end
    end
    object Panel7: TPanel
      Left = 2
      Top = 2
      Width = 256
      Height = 30
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 3
      object sbPattern: TSpeedButton
        Tag = 2
        Left = 61
        Top = 0
        Width = 16
        Height = 15
        GroupIndex = 6
        Flat = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -9
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        Glyph.Data = {
          E6010000424DE60100000000000036000000280000000C0000000C0000000100
          180000000000B00100000000000000000000000000000000000000FF0000FF00
          00FF0080808080808080808080808000FF0000FF0000FF0000FF0000FF0000FF
          0000FF0000000000000000000000000080808000FF0000FF0080808080808080
          808000FF0000FF00000000FC9702FF6060000000808080808080000000000000
          00000080808000FF00808080000000FFC680FC97020000000000000000000000
          00FF6060000000808080000000000000000000000000000000FF6060FF606000
          0000000000FF6060000000808080000000FC9702FF6060000000000000FFC680
          FF6060000000000000FC9702000000808080000000FFC680FF60600000000000
          0000000000000000000000000000000000000000FF00000000FFC680FF606000
          000080808080808000000000000000000000000080808000FF00000000FFC680
          FC9702000000000000000000000000FC9702FF606000000080808000FF000000
          00000000000000FC9702FF6060000000000000FFC680FC970200000080808000
          FF0000FF0000FF00000000FFC680FC9702000000000000000000000000000000
          00FF0000FF0000FF0000FF0000000000000000000000000000FF0000FF0000FF
          0000FF0000FF0000FF00}
        ParentFont = False
        OnClick = ShapeSelectClick
      end
      object sbSolid: TSpeedButton
        Tag = 3
        Left = 61
        Top = 15
        Width = 16
        Height = 15
        GroupIndex = 6
        Flat = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -9
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        Glyph.Data = {
          E6010000424DE60100000000000036000000280000000C0000000C0000000100
          180000000000B00100000000000000000000000000000000000000FF00808080
          8080808080808080808080808080808080808080808080808080808080800000
          0000000000000000000000000000000000000000000000000000000000000080
          8080000000FFC680FF6060FF6060FF6060FF6060FF6060FF6060FF6060FF6060
          000000808080000000FFC6800000000000000000000000000000000000000000
          00FF6060000000808080000000FFC68000000000000000000000000000000000
          0000000000FF6060000000808080000000FFC680000000000000000000000000
          000000000000000000FF6060000000808080000000FFC6800000000000000000
          00000000000000000000000000FF6060000000808080000000FFC68000000000
          0000000000000000000000000000000000FF6060000000808080000000FFC680
          000000000000000000000000000000000000000000FF60600000008080800000
          00FFC680000000000000000000000000000000000000000000FF606000000080
          8080000000FFC680FFC680FFC680FFC680FFC680FFC680FFC680FFC680FFC680
          0000008080800000000000000000000000000000000000000000000000000000
          0000000000000000FF00}
        ParentFont = False
        OnClick = ShapeSelectClick
      end
      object Bevel3: TBevel
        Left = 43
        Top = 0
        Width = 2
        Height = 30
      end
      object sbSquare: TSpeedButton
        Tag = 1
        Left = 45
        Top = 15
        Width = 16
        Height = 15
        GroupIndex = 5
        Flat = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -9
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        Glyph.Data = {
          E6010000424DE60100000000000036000000280000000C0000000C0000000100
          180000000000B00100000000000000000000000000000000000000FF00808080
          8080808080808080808080808080808080808080808080808080808080800000
          0000000000000000000000000000000000000000000000000000000000000080
          8080000000FFC680FF6060FF6060FF6060FF6060FF6060FF6060FF6060FF6060
          000000808080000000FFC680FC9702FC9702FC9702FC9702FC9702FC9702FC97
          02FF6060000000808080000000FFC680FC9702FC9702FC9702FC9702FC9702FC
          9702FC9702FF6060000000808080000000FFC680FC9702FC9702FC9702FC9702
          FC9702FC9702FC9702FF6060000000808080000000FFC680FC9702FC9702FC97
          02FC9702FC9702FC9702FC9702FF6060000000808080000000FFC680FC9702FC
          9702FC9702FC9702FC9702FC9702FC9702FF6060000000808080000000FFC680
          FC9702FC9702FC9702FC9702FC9702FC9702FC9702FF60600000008080800000
          00FFC680FC9702FC9702FC9702FC9702FC9702FC9702FC9702FF606000000080
          8080000000FFC680FFC680FFC680FFC680FFC680FFC680FFC680FFC680FFC680
          0000008080800000000000000000000000000000000000000000000000000000
          0000000000000000FF00}
        ParentFont = False
        OnClick = ShapeSelectClick
      end
      object sbCircle: TSpeedButton
        Left = 45
        Top = 0
        Width = 16
        Height = 15
        GroupIndex = 5
        Flat = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -9
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        Glyph.Data = {
          E6010000424DE60100000000000036000000280000000C0000000C0000000100
          180000000000B00100000000000000000000000000000000000000FF0000FF00
          00FF0000FF0000FF0080808080808080808000FF0000FF0000FF0000FF0000FF
          0000FF0000FF0080808000000000000000000080808080808080808000FF0000
          FF0000FF0000FF00000000000000FF6060FF6060FF6060000000000000808080
          80808000FF0000FF00000000FFC680FFC680FC9702FC9702FC9702FF6060FF60
          6000000080808000FF0000FF00000000FFC680FC9702FC9702FC9702FC9702FC
          9702FF6060000000808080808080000000FFC680FC9702FC9702FC9702FC9702
          FC9702FC9702FC9702FF6060000000808080000000FFC680FC9702FC9702FC97
          02FC9702FC9702FC9702FC9702FF6060000000808080000000FFC680FC9702FC
          9702FC9702FC9702FC9702FC9702FC9702FF606000000000FF0000FF00000000
          FFC680FC9702FC9702FC9702FC9702FC9702FFC68000000080808000FF0000FF
          00000000FFC680FFC680FC9702FC9702FC9702FFC680FFC68000000000FF0000
          FF0000FF0000FF00000000000000FFC680FFC680FFC68000000000000000FF00
          00FF0000FF0000FF0000FF0000FF0000FF0000000000000000000000FF0000FF
          0000FF0000FF0000FF00}
        ParentFont = False
        OnClick = ShapeSelectClick
      end
      object Bevel2: TBevel
        Left = 77
        Top = 0
        Width = 2
        Height = 30
      end
      object sbVis: TSpeedButton
        Left = 0
        Top = 0
        Width = 14
        Height = 16
        Hint = 'Click To Set Visual Colour'
        AllowAllUp = True
        Flat = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -9
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        Glyph.Data = {
          4E010000424D4E010000000000003600000028000000090000000A0000000100
          180000000000180100000000000000000000000000000000000000FF0000FF00
          00FF0000FF0080808080808000FF0000FF0000FF000000FF0000FF0000FF0000
          000000000080808080808000FF0000FF000000FF0000FF00000000FFC680FF60
          6000000080808000FF0000FF000000FF0000FF00000000FFC680FF6060000000
          80808080808000FF000000FF00000000FFC680FC9702FC9702FF606000000080
          808000FF000000FF00000000FFC680FF6060FF6060FF60600000008080808080
          8000000000FFC680FF6060000000000000FFC680FF6060000000808080000000
          00FFC680FF6060000000000000FFC680FF606000000080808000000000FFC680
          FFC680000000000000FFC680FFC68000000000FF000000FF0000000000000000
          FF0000FF0000000000000000FF0000FF0000}
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        OnClick = sbVisClick
      end
      object sbPri: TSpeedButton
        Tag = 1
        Left = 14
        Top = 0
        Width = 14
        Height = 16
        Hint = 'Click To Set Priority Colour'
        AllowAllUp = True
        Flat = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -9
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        Glyph.Data = {
          4E010000424D4E010000000000003600000028000000090000000A0000000100
          180000000000180100000000000000000000000000000000000000FF0000FF00
          80808080808000FF0000FF0000FF0000FF0000FF000000FF0000000000000080
          808080808000FF0000FF0000FF0000FF0000000000FF6060FF60600000008080
          8080808080808000FF0000FF0000000000FFC680FF6060000000000000000000
          80808080808000FF0000000000FFC680FF6060FF6060FF6060FF606000000080
          808080808000000000FFC680FF6060FFC680FFC680FFC680FF60600000008080
          8000000000FFC680FF6060000000000000FFC680FF6060000000808080000000
          00FFC680FF6060FF6060FF6060FFC680FF606000000000FF0000000000FFC680
          FFC680FFC680FFC680FFC68000000000FF0000FF000000FF0000000000000000
          000000000000000000FF0000FF0000FF0000}
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        OnClick = sbPriClick
      end
      object sbCtl: TSpeedButton
        Tag = 2
        Left = 28
        Top = 0
        Width = 15
        Height = 16
        Hint = 'Click To Set Control Colour'
        AllowAllUp = True
        Flat = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -9
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        Glyph.Data = {
          4E010000424D4E010000000000003600000028000000090000000A0000000100
          180000000000180100000000000000000000000000000000000000FF0000FF00
          00FF0080808080808080808080808080808000FF000000FF0000FF0000000000
          00000000000000000000008080808080800000FF00000000FF6060FF6060FF60
          60FF6060FF606000000080808000000000FFC680FC9702FFC680FFC680FFC680
          FFC68000000000FF0000000000FFC680FF606000000000000000000000000000
          FF0000FF0000000000FFC680FF606000000080808080808080808080808000FF
          0000000000FFC680FF6060000000000000000000000000808080808080000000
          00FFC680FC9702FF6060FF6060FF6060FF60600000008080800000FF00000000
          FFC680FFC680FFC680FFC680FFC68000000000FF000000FF0000FF0000000000
          000000000000000000000000FF0000FF0000}
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        OnClick = sbCtlClick
      end
      object Bevel4: TBevel
        Left = 112
        Top = 0
        Width = 2
        Height = 30
      end
      object XLabel: TLabel
        Left = 118
        Top = 2
        Width = 28
        Height = 13
        Caption = 'X:320'
      end
      object YLabel: TLabel
        Left = 118
        Top = 14
        Width = 28
        Height = 13
        Caption = 'Y:199'
      end
      object Bevel5: TBevel
        Left = 150
        Top = 0
        Width = 2
        Height = 30
      end
      object PriLabel1: TLabel
        Left = 152
        Top = 1
        Width = 30
        Height = 13
        Alignment = taCenter
        AutoSize = False
        Caption = 'Pri:'
        WordWrap = True
      end
      object Bevel6: TBevel
        Left = 182
        Top = 0
        Width = 2
        Height = 30
      end
      object ColLabel1: TLabel
        Left = 184
        Top = 1
        Width = 31
        Height = 13
        Alignment = taCenter
        AutoSize = False
        Caption = 'Col:'
        WordWrap = True
      end
      object Bevel1: TBevel
        Left = 214
        Top = 0
        Width = 2
        Height = 30
      end
      object imCol: TImage
        Left = 0
        Top = 16
        Width = 42
        Height = 14
      end
      object AngleLabel: TLabel
        Left = 218
        Top = 3
        Width = 35
        Height = 26
        Alignment = taCenter
        AutoSize = False
        Caption = 'Angle: 0'
        WordWrap = True
      end
      object Bevel7: TBevel
        Left = 254
        Top = -1
        Width = 2
        Height = 30
      end
      object shCol: TShape
        Left = 200
        Top = 15
        Width = 13
        Height = 13
      end
      object ColLabel: TLabel
        Left = 185
        Top = 15
        Width = 14
        Height = 14
        Alignment = taCenter
        AutoSize = False
        Caption = '00'
        WordWrap = True
      end
      object shPri: TShape
        Left = 168
        Top = 15
        Width = 13
        Height = 13
      end
      object PriLabel: TLabel
        Left = 153
        Top = 15
        Width = 14
        Height = 14
        Alignment = taCenter
        AutoSize = False
        Caption = '00'
        WordWrap = True
      end
      object imNoCol: TImage
        Left = 21
        Top = 16
        Width = 14
        Height = 14
        AutoSize = True
        Picture.Data = {
          07544269746D6170E6000000424DE60000000000000076000000280000000E00
          00000E0000000100040000000000700000000000000000000000100000001000
          0000000000000000BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0
          C000808080000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFF
          FF00AFFFFFFFFFFFFF0088FAAAAAAAAA8F008A8FAAAAAAA8FF008AA8FAAAAA8F
          AF008AAA8FAAA8FAAF008AAAA8FA8FAAAF008AAAAA88FAAAAF008AAAAA88FAAA
          AF008AAAA8FA8FAAAF008AAA8FAAA8FAAF008AA8FAAAAA8FAF008A8FAAAAAAA8
          FF0088FAAAAAAAAA8F008888888888888A00}
        Transparent = True
        Visible = False
      end
      object Panel8: TPanel
        Left = 80
        Top = 1
        Width = 32
        Height = 28
        BevelInner = bvLowered
        BevelOuter = bvNone
        Color = clWindow
        TabOrder = 0
        object PenSizeE: TLabel
          Left = 2
          Top = 5
          Width = 13
          Height = 18
          Alignment = taCenter
          AutoSize = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          Layout = tlCenter
        end
        object UpDown1: TUpDown
          Left = 16
          Top = 1
          Width = 15
          Height = 26
          Min = 0
          Max = 7
          Position = 0
          TabOrder = 0
          Wrap = False
          OnClick = UpDown1Click
        end
      end
    end
    object Panel3: TPanel
      Left = 529
      Top = 2
      Width = 38
      Height = 30
      Align = alRight
      BevelOuter = bvNone
      TabOrder = 4
      object SpeedButton3: TSpeedButton
        Left = 0
        Top = 0
        Width = 38
        Height = 30
        Flat = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        Glyph.Data = {
          56040000424D560400000000000036000000280000001F0000000B0000000100
          180000000000200400000000000000000000000000000000000000FF0000FF00
          82828200FF0000FF0000FF0000FF0000FF0000FF0082828282828200FF0000FF
          0082828282828282828282828200FF0000FF0082828282828200FF0000FF0000
          FF0000FF0082828282828282828282828282828200FF0000000000FF00000000
          82828282828200FF0000FF0000FF0000FF000000000000008282828282820000
          0000000000000000000082828282828200000000000082828282828200FF0000
          FF00000000000000000000000000000000828282828282000000000000FF6060
          00000082828200FF0000FF0000FF00000000FF6060FF6060000000000000FC97
          02FC9702FC9702FC9702000000000000FF6060FF606000000082828200FF0000
          0000FC9702FC9702FC9702FC9702FC970200000000FF00000000000000FC9702
          00000082828200FF00828282828282000000FFC680FF6060000000FFC680FF60
          60000000000000FFC680FF6060000000FFC680FF6060000000828282000000FF
          C680FF606000000000000000000000000082828200FF00000000000000FC9702
          000000828282000000000000828282000000FFC680FF6060000000FFC680FF60
          60000000000000FFC680FF6060000000FFC680FF6060000000828282000000FF
          C680FF6060000000000000000000000000828282828282000000000000FC9702
          000000000000FFC680FF6060000000000000FFC680FF6060000000FFC680FF60
          60000000000000FFC680FF6060000000FFC680FF6060000000000000000000FF
          C680FC9702FC9702FC9702FF6060FF6060000000828282000000000000FC9702
          000000FFC680FC9702FC9702FF6060000000FFC680FF6060000000FFC680FF60
          60000000000000FFC680FF6060000000FFC680FC9702FC9702FF6060000000FF
          C680FF6060000000000000FC9702FFC68000000000FF00000000000000FC9702
          FFC680FC9702FC9702000000FFC680FC9702FC9702FF6060000000000000FC97
          02FC9702FC9702FC9702000000000000FFC680FFC680000000FFC68000000000
          0000FFC680FC9702FC9702FFC68000000000FF0000FF00000000000000FC9702
          FC9702FC9702000000828282000000FFC680FC9702FF60600000008282820000
          0000000000000000000000FF0000FF0000000000000000FF0000000000FF0000
          FF0000000000000000000000000000FF0000FF0000FF00000000000000FFC680
          FFC68000000082828200FF0000FF00000000FFC680FFC68000000000FF0000FF
          0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000
          FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000000000FF00000000
          00000000FF0000FF0000FF0000FF0000FF0000000000000000FF0000FF0000FF
          0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000
          FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF00000000}
        ParentFont = False
        OnClick = CommandHistory1Click
      end
    end
  end
  object MainMenu1: TMainMenu
    Images = WndMain.ilEditBars
    Left = 354
    Top = 98
    object File1: TMenuItem
      Caption = 'File'
      ImageIndex = 0
      object New1: TMenuItem
        Caption = '&New'
        ImageIndex = 0
        ShortCut = 16462
        OnClick = New1Click
      end
      object Open1: TMenuItem
        Caption = '&Open'
        ImageIndex = 1
        ShortCut = 16463
        OnClick = Open1Click
      end
      object Save1: TMenuItem
        Caption = '&Save'
        ImageIndex = 2
        ShortCut = 16467
        OnClick = Save1Click
      end
      object SaveAs1: TMenuItem
        Caption = 'Save &As'
        OnClick = SaveAs1Click
      end
      object SaveToGame1: TMenuItem
        Caption = 'Save To &Game'
        OnClick = SaveToGame1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Close1: TMenuItem
        Caption = '&Close'
        ImageIndex = 28
        OnClick = Close1Click
      end
    end
    object Edit1: TMenuItem
      Caption = 'Edit'
      object CommandHistory1: TMenuItem
        Caption = 'Command History'
        ImageIndex = 4
        ShortCut = 16456
        OnClick = CommandHistory1Click
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object Copy1: TMenuItem
        Caption = 'C&opy'
        ImageIndex = 6
        ShortCut = 16451
        OnClick = Copy1Click
      end
      object PasteTracingImage1: TMenuItem
        Caption = '&Paste Tracing Image'
        ImageIndex = 7
        ShortCut = 16470
        OnClick = PasteTracingImage1Click
      end
    end
    object Background1: TMenuItem
      Caption = 'Background'
      object LoadTracingImage1: TMenuItem
        Caption = '&Load Tracing Image'
        ImageIndex = 3
        OnClick = LoadTracingImage1Click
      end
      object N4: TMenuItem
        Caption = '-'
      end
      object ShowTracingImage1: TMenuItem
        Caption = 'Show Tracing Image'
        GroupIndex = 10
        ImageIndex = 87
        OnClick = ShowTracingImage1Click
      end
      object ShowPriorityBars1: TMenuItem
        Caption = 'Show &Priority Bars'
        GroupIndex = 11
        ImageIndex = 89
        OnClick = ShowPriorityBars1Click
      end
    end
    object Zoom1: TMenuItem
      Caption = 'Zoom'
      object NormalViewing1: TMenuItem
        Tag = 2
        Caption = '&Normal Viewing'
        OnClick = ZoomClick
      end
      object N5: TMenuItem
        Caption = '-'
      end
      object ZoomIn1: TMenuItem
        Caption = 'Zoom &In'
        ImageIndex = 24
        ShortCut = 16457
        OnClick = ZoomIn1Click
      end
      object ZoomOut1: TMenuItem
        Caption = 'Zoom &Out'
        ImageIndex = 25
        ShortCut = 16469
        OnClick = ZoomOut1Click
      end
      object Zoom2: TMenuItem
        Caption = '&Zoom...'
        ImageIndex = 67
        object N111: TMenuItem
          Tag = 1
          Caption = '&1:1'
          OnClick = ZoomClick
        end
        object N211: TMenuItem
          Tag = 2
          Caption = '&2:1'
          OnClick = ZoomClick
        end
        object N311: TMenuItem
          Tag = 3
          Caption = '&3:1'
          OnClick = ZoomClick
        end
        object N411: TMenuItem
          Tag = 4
          Caption = '&4:1'
          OnClick = ZoomClick
        end
        object N511: TMenuItem
          Tag = 5
          Caption = '&5:1'
          OnClick = ZoomClick
        end
        object N611: TMenuItem
          Tag = 6
          Caption = '&6:1'
          OnClick = ZoomClick
        end
        object N711: TMenuItem
          Tag = 7
          Caption = '&7:1'
          OnClick = ZoomClick
        end
        object N811: TMenuItem
          Tag = 8
          Caption = '&8:1'
          OnClick = ZoomClick
        end
        object N911: TMenuItem
          Tag = 9
          Caption = '&9:1'
          OnClick = ZoomClick
        end
        object N1011: TMenuItem
          Tag = 10
          Caption = '1&0:1'
          OnClick = ZoomClick
        end
        object N1111: TMenuItem
          Tag = 11
          Caption = '11:1'
          OnClick = ZoomClick
        end
        object N1211: TMenuItem
          Tag = 12
          Caption = '12:1'
          OnClick = ZoomClick
        end
        object N1311: TMenuItem
          Tag = 13
          Caption = '13:1'
          OnClick = ZoomClick
        end
        object N1411: TMenuItem
          Tag = 14
          Caption = '14:1'
          OnClick = ZoomClick
        end
        object N1511: TMenuItem
          Tag = 15
          Caption = '15:1'
          OnClick = ZoomClick
        end
        object N1611: TMenuItem
          Tag = 16
          Caption = '16:1'
          OnClick = ZoomClick
        end
      end
    end
  end
  object OpenDialog: TOpenDialog
    Filter = 'SCI Pic Resource (pic.*)|pic.*|All Files (*.*)|*.*'
    Left = 386
    Top = 98
  end
  object SaveDialog: TSaveDialog
    Filter = 'SCI Pic Resource (pic.*)|pic.*|All Files (*.*)|*.*'
    Options = [ofOverwritePrompt, ofEnableSizing]
    Left = 418
    Top = 98
  end
  object BGOpenDialog: TOpenPictureDialog
    Filter = 'Bitmaps (*.bmp)|*.bmp'
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Left = 450
    Top = 99
  end
end
