object WndGfxEdit: TWndGfxEdit
  Left = 233
  Top = 124
  Width = 457
  Height = 389
  Caption = 'View Editor'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Scaled = False
  Visible = True
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 13
  object ToolButton34: TToolButton
    Left = 36
    Top = 2
    Caption = #20
    ImageIndex = 18
    Style = tbsDropDown
  end
  object ToolButton35: TToolButton
    Left = 72
    Top = 2
    Caption = 'ToolButton3'
    ImageIndex = 17
    Style = tbsDropDown
  end
  object CoolBar1: TCoolBar
    Left = 0
    Top = 0
    Width = 449
    Height = 49
    AutoSize = True
    Bands = <
      item
        Control = MenuBar1
        ImageIndex = -1
        MinHeight = 21
        Width = 445
      end
      item
        Control = ToolBar1
        ImageIndex = -1
        MinHeight = 22
        Width = 445
      end>
    object MenuBar1: TMenuBar
      Left = 9
      Top = 0
      Width = 322
      Height = 21
      Align = alNone
      AutoSize = True
      ButtonHeight = 21
      ButtonWidth = 82
      Constraints.MaxHeight = 22
      Constraints.MinHeight = 21
      Flat = True
      ShowCaptions = True
      TabOrder = 0
      Menu = MainMenu1
    end
    object ToolBar1: TToolBar
      Left = 9
      Top = 23
      Width = 432
      Height = 22
      Align = alNone
      Caption = 'ToolBar1'
      EdgeBorders = []
      Flat = True
      HotImages = WndMain.ilEditBarsH
      Images = WndMain.ilEditBars
      TabOrder = 1
      object sbNew: TToolButton
        Left = 0
        Top = 0
        ImageIndex = 0
      end
      object sbOpen: TToolButton
        Left = 23
        Top = 0
        ImageIndex = 1
        OnClick = Open1Click
      end
      object sbSave: TToolButton
        Left = 46
        Top = 0
        ImageIndex = 2
        OnClick = Save1Click
      end
      object sbExport: TToolButton
        Left = 69
        Top = 0
        ImageIndex = 3
        OnClick = WindowsBitmap1Click
      end
      object ToolButton17: TToolButton
        Left = 92
        Top = 0
        Width = 8
        Caption = 'ToolButton17'
        ImageIndex = 8
        Style = tbsSeparator
      end
      object sbUndo: TToolButton
        Left = 100
        Top = 0
        ImageIndex = 4
        OnClick = Undo1Click
      end
      object sbRedo: TToolButton
        Left = 123
        Top = 0
        ImageIndex = 98
        OnClick = Redo1Click
      end
      object ToolButton18: TToolButton
        Left = 146
        Top = 0
        Width = 8
        Caption = 'ToolButton18'
        ImageIndex = 8
        Style = tbsSeparator
      end
      object sbCut: TToolButton
        Left = 154
        Top = 0
        ImageIndex = 5
        OnClick = Cut1Click
      end
      object sbCopy: TToolButton
        Left = 177
        Top = 0
        ImageIndex = 6
        OnClick = Copy1Click
      end
      object sbPaste: TToolButton
        Left = 200
        Top = 0
        ImageIndex = 7
        OnClick = Paste1Click
      end
      object tbSeperator: TToolButton
        Left = 223
        Top = 0
        Width = 8
        Caption = 'tbSeperator'
        ImageIndex = 8
        Style = tbsSeparator
      end
      object tbAnimate: TToolButton
        Left = 231
        Top = 0
        Caption = 'tbAnimate'
        ImageIndex = 26
        Visible = False
        OnClick = Animator1Click
      end
      object tbFontTest: TToolButton
        Left = 254
        Top = 0
        Caption = 'tbFontTest'
        ImageIndex = 49
        Visible = False
        OnClick = FontTester1Click
      end
      object tbViewFont: TToolButton
        Left = 277
        Top = 0
        Caption = 'tbViewFont'
        ImageIndex = 32
        Visible = False
        OnClick = ViewFontTable1Click
      end
    end
  end
  object pnTools: TPanel
    Left = 0
    Top = 49
    Width = 100
    Height = 313
    Align = alLeft
    AutoSize = True
    BevelOuter = bvNone
    UseDockManager = False
    DockSite = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBtnFace
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnDockDrop = pnToolsDockDrop
    OnDockOver = pnToolsDockOver
    object pnDrawingTools: TPanel
      Tag = 1
      Left = 0
      Top = 0
      Width = 100
      Height = 192
      Align = alTop
      BevelOuter = bvNone
      Caption = 'Drawing Tools'
      Constraints.MaxHeight = 192
      Constraints.MaxWidth = 100
      Constraints.MinHeight = 192
      Constraints.MinWidth = 100
      UseDockManager = False
      DragKind = dkDock
      DragMode = dmAutomatic
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnFace
      Font.Height = -9
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnEndDock = pnCoordsEndDock
      object ToolBar2: TToolBar
        Left = 1
        Top = 3
        Width = 48
        Height = 112
        Align = alNone
        Caption = 'ToolBar1'
        EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
        EdgeOuter = esNone
        Flat = True
        HotImages = WndMain.ilEditBarsH
        Images = WndMain.ilEditBars
        TabOrder = 0
        object sbPen: TToolButton
          Tag = 257
          Left = 0
          Top = 0
          Hint = 'Pen Tool'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 8
          OnClick = sbToolsClick
        end
        object sbReplace: TToolButton
          Tag = 258
          Left = 23
          Top = 0
          Hint = 'Colour Replace Pen Tool'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 63
          Wrap = True
          OnClick = sbToolsClick
        end
        object sbLine: TToolButton
          Tag = 259
          Left = 0
          Top = 22
          Hint = 'Line Tool'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 9
          OnClick = sbToolsClick
        end
        object sbFill: TToolButton
          Tag = 260
          Left = 23
          Top = 22
          Hint = 'Fill Tool'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 10
          Wrap = True
          OnClick = sbToolsClick
        end
        object sbRect: TToolButton
          Tag = 261
          Left = 0
          Top = 44
          Hint = 'Rectangle Tool'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 13
          OnClick = sbToolsClick
        end
        object sbFRect: TToolButton
          Tag = 262
          Left = 23
          Top = 44
          Hint = 'Filled Rectangle Tool'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 14
          Wrap = True
          OnClick = sbToolsClick
        end
        object sbRRect: TToolButton
          Tag = 263
          Left = 0
          Top = 66
          Hint = 'Round Rectangle Tool'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 30
          OnClick = sbToolsClick
        end
        object sbFRRect: TToolButton
          Tag = 264
          Left = 23
          Top = 66
          Hint = 'Filled Round Rectangle Tool'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 31
          Wrap = True
          OnClick = sbToolsClick
        end
        object sbEllipse: TToolButton
          Tag = 265
          Left = 0
          Top = 88
          Hint = 'Ellipse Tool'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 11
          OnClick = sbToolsClick
        end
        object sbFEllipse: TToolButton
          Tag = 266
          Left = 23
          Top = 88
          Hint = 'Filled Ellipse Tool'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 12
          OnClick = sbToolsClick
        end
      end
      object ToolBar3: TToolBar
        Left = 51
        Top = 3
        Width = 48
        Height = 90
        Align = alNone
        Caption = 'ToolBar1'
        EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
        EdgeOuter = esNone
        Flat = True
        HotImages = WndMain.ilEditBarsH
        Images = WndMain.ilEditBars
        TabOrder = 1
        object sbArrow: TToolButton
          Tag = 513
          Left = 0
          Top = 0
          Hint = 'Deselect Tool'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 29
          OnClick = sbToolsClick
        end
        object sbColGrab: TToolButton
          Tag = 514
          Left = 23
          Top = 0
          Hint = 'Colour Grabber Tool'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 15
          Wrap = True
          OnClick = sbToolsClick
        end
        object sbZoom: TToolButton
          Tag = 515
          Left = 0
          Top = 22
          Hint = 'Zoom In/Out'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 67
          OnClick = sbToolsClick
        end
        object sbScroll: TToolButton
          Tag = 516
          Left = 23
          Top = 22
          Hint = 'Scroll Canvas'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 64
          Wrap = True
          OnClick = sbToolsClick
        end
        object sbSelection: TToolButton
          Tag = 2565
          Left = 0
          Top = 44
          Hint = 'Select Region'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 61
          OnClick = sbToolsClick
        end
        object sbSelectionRZ: TToolButton
          Tag = 2566
          Left = 23
          Top = 44
          Hint = 'Resize Selected Region'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 65
          Wrap = True
          OnClick = sbToolsClick
        end
        object sbSelectionMove: TToolButton
          Tag = 2567
          Left = 0
          Top = 66
          Hint = 'Drag Selected Region'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 62
          OnClick = sbToolsClick
        end
        object sbSelectionCopy: TToolButton
          Tag = 2568
          Left = 23
          Top = 66
          Hint = 'Copy Selected Region'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 66
          OnClick = sbToolsClick
        end
      end
      object ToolBar4: TToolBar
        Left = 51
        Top = 95
        Width = 48
        Height = 68
        Align = alNone
        Caption = 'ToolBar1'
        EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
        EdgeOuter = esNone
        Flat = True
        HotImages = WndMain.ilEditBarsH
        Images = WndMain.ilEditBars
        TabOrder = 2
        object sbMoveUp: TToolButton
          Tag = 769
          Left = 0
          Top = 0
          Hint = 'Shift Canvas Up'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 19
          OnClick = Up1Click
        end
        object sbMoveDown: TToolButton
          Tag = 770
          Left = 23
          Top = 0
          Hint = 'Shift Canvas Down'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 18
          Wrap = True
          OnClick = Down1Click
        end
        object sbMoveLeft: TToolButton
          Tag = 771
          Left = 0
          Top = 22
          Hint = 'Shift Canvas Left'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 17
          OnClick = Left1Click
        end
        object sbMoveRight: TToolButton
          Tag = 772
          Left = 23
          Top = 22
          Hint = 'Shift Canvas Right'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 16
          Wrap = True
          OnClick = Right1Click
        end
        object sbFlipH: TToolButton
          Tag = 773
          Left = 0
          Top = 44
          Hint = 'Flip Canvas Horizontally'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 20
          OnClick = Horizontally1Click
        end
        object sbFlipV: TToolButton
          Tag = 774
          Left = 23
          Top = 44
          Hint = 'Flip Canvas Vertically'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 21
          OnClick = Vertically1Click
        end
      end
      object ToolBar6: TToolBar
        Left = 51
        Top = 165
        Width = 48
        Height = 24
        Align = alNone
        Caption = 'ToolBar1'
        EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
        EdgeOuter = esNone
        Flat = True
        HotImages = WndMain.ilEditBarsH
        Images = WndMain.ilEditBars
        TabOrder = 3
        object sbInvert: TToolButton
          Tag = 1025
          Left = 0
          Top = 0
          Hint = 'Invert Image'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 22
          OnClick = Invert1Click
        end
        object sbGrey: TToolButton
          Tag = 1026
          Left = 23
          Top = 0
          Hint = 'Grey Scale'
          AllowAllUp = True
          Grouped = True
          ImageIndex = 23
          OnClick = GreyScale1Click
        end
      end
      object ToolBar5: TToolBar
        Left = 1
        Top = 115
        Width = 48
        Height = 74
        Align = alNone
        ButtonHeight = 24
        ButtonWidth = 33
        EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
        EdgeOuter = esNone
        Flat = True
        Images = WndMain.ilStyles
        TabOrder = 4
        object sbPenStyle: TToolButton
          Left = 0
          Top = 0
          Hint = 'Shape Styles: Used when outlining shapes.'
          DropdownMenu = PenStyleMenu
          ImageIndex = 16
          Wrap = True
          Style = tbsDropDown
          OnClick = sbPenStyleClick
        end
        object sbBrushStyle: TToolButton
          Left = 0
          Top = 24
          Hint = 'Brush Style: Used to fill shapes and flood fills.'
          DropdownMenu = BrushStyleMenu
          ImageIndex = 0
          Wrap = True
          Style = tbsDropDown
          OnClick = sbBrushStyleClick
        end
        object sbPenWidth: TToolButton
          Tag = 1
          Left = 0
          Top = 48
          Hint = 'Pen Size: The width of shape outlines, pen draws and lines.'
          DropdownMenu = PenSizeMenu
          ImageIndex = 8
          Style = tbsDropDown
          OnClick = sbPenWidthClick
        end
      end
    end
    object pnPalette: TPanel
      Tag = 2
      Left = 0
      Top = 192
      Width = 100
      Height = 60
      Align = alTop
      BevelOuter = bvNone
      Caption = 'Palette'
      Constraints.MaxHeight = 160
      Constraints.MaxWidth = 100
      Constraints.MinHeight = 60
      Constraints.MinWidth = 100
      UseDockManager = False
      DragKind = dkDock
      DragMode = dmAutomatic
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnFace
      Font.Height = -9
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnEndDock = pnCoordsEndDock
      object pnCol: TPanel
        Left = 55
        Top = 4
        Width = 44
        Height = 52
        BevelInner = bvRaised
        BevelOuter = bvNone
        TabOrder = 0
        object shCol2: TShape
          Left = 19
          Top = 23
          Width = 20
          Height = 20
          Hint = 'The Background Colour'
          Brush.Color = 10526720
          ParentShowHint = False
          ShowHint = True
        end
        object shCol1: TShape
          Left = 4
          Top = 8
          Width = 20
          Height = 20
          Hint = 'The Foreground Colour'
          Brush.Color = clBlack
          ParentShowHint = False
          ShowHint = True
        end
        object sbSwapCols: TSpeedButton
          Left = 4
          Top = 28
          Width = 15
          Height = 15
          Hint = 'Exchange The Foreground and Background Colours'
          Flat = True
          Glyph.Data = {
            DE000000424DDE0000000000000076000000280000000D0000000D0000000100
            0400000000006800000000000000000000001000000010000000000000000000
            BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFF8FF
            F000FFFFFFFFC88FF000FFFFFFFFCC88F000FFFF8888CCC88000FFFCCCCCCCCC
            F000FFFC8FFFCCCFF000FFFC8FFFCCFFF000FFFC8FFFCFFFF000F88C8888FFFF
            F000CCCCCCCFFFFFF000FCCCCCFFFFFFF000FFCCCFFFFFFFF000FFFCFFFFFFFF
            F000}
          ParentShowHint = False
          ShowHint = True
          OnClick = sbSwapColsClick
        end
      end
      object pnPal: TPanel
        Left = 1
        Top = 4
        Width = 52
        Height = 52
        BevelInner = bvRaised
        BevelOuter = bvNone
        TabOrder = 1
        object imPal: TImage
          Left = 2
          Top = 2
          Width = 48
          Height = 48
          Hint = 'The Palette. Click to select a colour.'
          ParentShowHint = False
          ShowHint = True
          Stretch = True
          OnMouseDown = imPalMouseDown
        end
      end
    end
    object pnCoords: TPanel
      Tag = 3
      Left = 0
      Top = 286
      Width = 100
      Height = 27
      Align = alBottom
      BevelOuter = bvNone
      Caption = 'Coords'
      DragKind = dkDock
      DragMode = dmAutomatic
      TabOrder = 2
      OnEndDock = pnCoordsEndDock
      object Panel8: TPanel
        Left = 1
        Top = 5
        Width = 97
        Height = 18
        Caption = 'Panel8'
        TabOrder = 0
        object lbCoords: TLabel
          Left = 1
          Top = 1
          Width = 95
          Height = 16
          Align = alClient
          Alignment = taCenter
          Caption = 'X: 000  Y: 000'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBtnText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          Layout = tlCenter
        end
      end
    end
  end
  object ScrollBox1: TScrollBox
    Tag = 222
    Left = 100
    Top = 49
    Width = 145
    Height = 313
    Align = alClient
    Color = clBtnShadow
    ParentColor = False
    TabOrder = 2
    OnClick = ScrollBox1Click
    OnMouseMove = pbSurfaceMouseMove
    object pbSurface: TPaintBox
      Tag = 111
      Left = 0
      Top = 0
      Width = 121
      Height = 201
      OnMouseDown = pbSurfaceMouseDown
      OnMouseMove = pbSurfaceMouseMove
      OnMouseUp = pbSurfaceMouseUp
      OnPaint = pbSurfacePaint
    end
  end
  object pnView: TPanel
    Left = 322
    Top = 49
    Width = 127
    Height = 313
    Align = alRight
    BevelOuter = bvNone
    Enabled = False
    TabOrder = 3
    Visible = False
    object lbLoop: TLabel
      Left = 67
      Top = 74
      Width = 28
      Height = 13
      Caption = '00/00'
    end
    object lbCel: TLabel
      Left = 67
      Top = 95
      Width = 28
      Height = 13
      Caption = '00/00'
    end
    object Label5: TLabel
      Left = 3
      Top = 121
      Width = 32
      Height = 13
      Caption = 'Width:'
    end
    object Label6: TLabel
      Left = 3
      Top = 145
      Width = 35
      Height = 13
      Caption = 'Height:'
    end
    object Label7: TLabel
      Left = 3
      Top = 169
      Width = 97
      Height = 13
      Caption = 'Transparent Colour:'
    end
    object Label8: TLabel
      Left = 83
      Top = 145
      Width = 10
      Height = 13
      Caption = 'Y:'
    end
    object Label9: TLabel
      Left = 83
      Top = 121
      Width = 10
      Height = 13
      Caption = 'X:'
    end
    object Label10: TLabel
      Left = 3
      Top = 209
      Width = 71
      Height = 13
      Caption = 'Loop Mirror of:'
    end
    object udLoop: TUpDown
      Tag = 1
      Left = 103
      Top = 72
      Width = 24
      Height = 16
      Min = 0
      Orientation = udHorizontal
      Position = 0
      TabOrder = 0
      Wrap = False
      OnClick = udLoopCelClick
    end
    object udCel: TUpDown
      Left = 103
      Top = 93
      Width = 24
      Height = 16
      Min = 0
      Orientation = udHorizontal
      Position = 0
      TabOrder = 1
      Wrap = False
      OnClick = udLoopCelClick
    end
    object edWidth: TEdit
      Left = 40
      Top = 117
      Width = 31
      Height = 21
      AutoSize = False
      TabOrder = 2
      Text = '000'
      OnExit = edWidthExit
      OnKeyPress = edWidthKeyPress
    end
    object edHeight: TEdit
      Left = 40
      Top = 141
      Width = 31
      Height = 21
      AutoSize = False
      TabOrder = 3
      Text = '000'
      OnExit = edHeightExit
    end
    object edY: TEdit
      Left = 96
      Top = 141
      Width = 31
      Height = 21
      AutoSize = False
      TabOrder = 4
      Text = '000'
      OnExit = edYExit
    end
    object edX: TEdit
      Left = 96
      Top = 117
      Width = 31
      Height = 21
      AutoSize = False
      TabOrder = 5
      Text = '000'
      OnExit = edXExit
    end
    object cbLoopMirror: TComboBox
      Left = 3
      Top = 224
      Width = 126
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 6
      OnChange = cbLoopMirrorChange
    end
    object Panel7: TPanel
      Left = 0
      Top = 0
      Width = 128
      Height = 66
      BevelOuter = bvNone
      TabOrder = 7
      object imCels: TImage
        Left = 0
        Top = 0
        Width = 128
        Height = 54
        Align = alClient
        OnMouseDown = imCelsMouseDown
      end
      object sbrCels: TScrollBar
        Left = 0
        Top = 54
        Width = 128
        Height = 12
        Align = alBottom
        PageSize = 0
        TabOrder = 0
        OnChange = sbrCelsChange
      end
    end
    object TPanel
      Left = 3
      Top = 184
      Width = 126
      Height = 22
      BevelOuter = bvNone
      BorderStyle = bsSingle
      TabOrder = 8
      object shpTCol: TShape
        Left = 0
        Top = 0
        Width = 88
        Height = 19
        Pen.Color = clNone
        Pen.Style = psClear
      end
      object btnTCol: TSpeedButton
        Left = 87
        Top = 0
        Width = 35
        Height = 18
        Caption = 'Set'
        OnClick = btnTColClick
      end
    end
    object tbLoopCel: TToolBar
      Left = 3
      Top = 69
      Width = 50
      Height = 42
      Align = alNone
      ButtonHeight = 21
      ButtonWidth = 37
      EdgeBorders = []
      EdgeInner = esNone
      EdgeOuter = esNone
      Flat = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ShowCaptions = True
      TabOrder = 9
      object ddLoop: TToolButton
        Left = 0
        Top = 0
        Caption = 'Loop:'
        DropdownMenu = pmLoop
        ImageIndex = 0
        Wrap = True
        Style = tbsDropDown
        OnClick = ddLoopClick
      end
      object ddCel: TToolButton
        Left = 0
        Top = 21
        Caption = 'Cel:'
        DropdownMenu = pmCel
        ImageIndex = 1
        Style = tbsDropDown
        OnClick = ddCelClick
      end
    end
    object pnVGAPal: TPanel
      Left = 0
      Top = 250
      Width = 127
      Height = 49
      BevelOuter = bvNone
      TabOrder = 10
      object SpeedButton1: TSpeedButton
        Left = 3
        Top = 20
        Width = 124
        Height = 29
        Caption = 'Change Palette'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        OnClick = SpeedButton1Click
      end
      object cbEmbedPalette: TCheckBox
        Left = 18
        Top = 0
        Width = 90
        Height = 17
        Caption = 'Embed Palette'
        TabOrder = 0
        OnClick = cbEmbedPaletteClick
      end
    end
  end
  object pnFont: TPanel
    Left = 245
    Top = 49
    Width = 77
    Height = 313
    Align = alRight
    BevelOuter = bvNone
    Enabled = False
    TabOrder = 4
    Visible = False
    object Panel6: TPanel
      Left = 0
      Top = 118
      Width = 77
      Height = 195
      Align = alClient
      BevelOuter = bvNone
      BorderStyle = bsSingle
      TabOrder = 0
      OnResize = Panel6Resize
      object imChars: TImage
        Left = 0
        Top = 0
        Width = 57
        Height = 191
        Align = alClient
        OnMouseDown = imCharsMouseDown
      end
      object sbrChars: TScrollBar
        Left = 57
        Top = 0
        Width = 16
        Height = 191
        Align = alRight
        Kind = sbVertical
        PageSize = 0
        TabOrder = 0
        OnChange = sbrCharsChange
      end
    end
    object Panel9: TPanel
      Left = 0
      Top = 0
      Width = 77
      Height = 118
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 1
      object GroupBox1: TGroupBox
        Left = 0
        Top = 0
        Width = 76
        Height = 81
        Caption = 'Char'
        TabOrder = 0
        object Label11: TLabel
          Left = 5
          Top = 39
          Width = 32
          Height = 13
          Caption = 'Width:'
        end
        object Label12: TLabel
          Left = 5
          Top = 60
          Width = 35
          Height = 13
          Caption = 'Height:'
        end
        object lbChar: TLabel
          Left = 5
          Top = 16
          Width = 40
          Height = 13
          Caption = '000/000'
        end
        object edChWidth: TEdit
          Left = 48
          Top = 35
          Width = 24
          Height = 21
          AutoSize = False
          TabOrder = 0
          Text = '000'
          OnExit = edChWidthExit
          OnKeyPress = edWidthKeyPress
        end
        object edChHeight: TEdit
          Left = 48
          Top = 56
          Width = 24
          Height = 21
          AutoSize = False
          TabOrder = 1
          Text = '000'
          OnExit = edChHeightExit
        end
        object udChar: TUpDown
          Tag = 1
          Left = 48
          Top = 14
          Width = 24
          Height = 16
          Min = 0
          Orientation = udHorizontal
          Position = 0
          TabOrder = 2
          Wrap = False
          OnClick = udCharClick
        end
      end
      object GroupBox2: TGroupBox
        Left = 0
        Top = 81
        Width = 76
        Height = 37
        Caption = 'Font'
        TabOrder = 1
        object Label13: TLabel
          Left = 5
          Top = 16
          Width = 35
          Height = 13
          Caption = 'Height:'
        end
        object edFnHeight: TEdit
          Left = 48
          Top = 12
          Width = 24
          Height = 21
          AutoSize = False
          TabOrder = 0
          Text = '000'
          OnExit = edFnHeightExit
        end
      end
    end
  end
  object MainMenu1: TMainMenu
    Images = WndMain.ilEditBars
    Left = 322
    Top = 32
    object File1: TMenuItem
      Caption = '&File'
      object New1: TMenuItem
        Caption = '&New'
        ImageIndex = 0
        object EGAView1: TMenuItem
          Caption = '&EGA View'
          OnClick = EGAView1Click
        end
        object VGAView1: TMenuItem
          Caption = '&VGA View'
          OnClick = VGAView1Click
        end
        object N128CharFont1: TMenuItem
          Caption = '&128 Char Font (SCI0)'
          OnClick = N128CharFont1Click
        end
        object N256CharFont1: TMenuItem
          Caption = '&256 Char Font (SCI1+)'
          OnClick = N256CharFont1Click
        end
        object N3ColourCursor1: TMenuItem
          Caption = '&3 Colour Cursor'
          OnClick = N3ColourCursor1Click
        end
        object N4ColourCursor1: TMenuItem
          Caption = '&4 Colour Cursor'
          OnClick = N4ColourCursor1Click
        end
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
      object N5: TMenuItem
        Caption = '-'
      end
      object Toolbars1: TMenuItem
        Caption = '&Toolbars'
        object DrawingTools1: TMenuItem
          Caption = 'Drawing Tools'
          Checked = True
          OnClick = DrawingTools1Click
        end
        object ColourSelection1: TMenuItem
          Caption = 'Colour Selection'
          Checked = True
          OnClick = ColourSelection1Click
        end
        object Coords1: TMenuItem
          Caption = 'Coords'
          Checked = True
          OnClick = Coords1Click
        end
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Exit1: TMenuItem
        Caption = '&Close'
        ImageIndex = 28
        OnClick = Exit1Click
      end
    end
    object Edit1: TMenuItem
      Caption = '&Edit'
      object Undo1: TMenuItem
        Caption = '&Undo'
        ImageIndex = 4
        ShortCut = 16474
        OnClick = Undo1Click
      end
      object Redo1: TMenuItem
        Caption = '&Redo'
        ShortCut = 16473
        OnClick = Redo1Click
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object Cut1: TMenuItem
        Caption = 'C&ut'
        ImageIndex = 5
        ShortCut = 16472
        OnClick = Cut1Click
      end
      object Copy1: TMenuItem
        Caption = 'C&opy'
        ImageIndex = 6
        ShortCut = 16451
        OnClick = Copy1Click
      end
      object Paste1: TMenuItem
        Caption = '&Paste'
        ImageIndex = 7
        ShortCut = 16470
        OnClick = Paste1Click
      end
      object Clear1: TMenuItem
        Caption = 'C&lear'
        OnClick = Clear1Click
      end
    end
    object Image2: TMenuItem
      Caption = '&Image'
      object Flip1: TMenuItem
        Caption = '&Flip'
        object Horizontally1: TMenuItem
          Caption = '&Horizontally'
          ImageIndex = 20
          OnClick = Horizontally1Click
        end
        object Vertically1: TMenuItem
          Caption = '&Vertically'
          ImageIndex = 21
          OnClick = Vertically1Click
        end
      end
      object Shift1: TMenuItem
        Caption = '&Shift'
        object Up1: TMenuItem
          Caption = '&Up'
          GroupIndex = 2
          ImageIndex = 19
          OnClick = Up1Click
        end
        object Down1: TMenuItem
          Caption = '&Down'
          GroupIndex = 2
          ImageIndex = 18
          OnClick = Down1Click
        end
        object Left1: TMenuItem
          Caption = '&Left'
          GroupIndex = 2
          ImageIndex = 17
          OnClick = Left1Click
        end
        object Right1: TMenuItem
          Caption = '&Right'
          GroupIndex = 2
          ImageIndex = 16
          OnClick = Right1Click
        end
        object N3: TMenuItem
          Caption = '-'
          GroupIndex = 2
        end
        object Options1: TMenuItem
          Caption = '&Options'
          GroupIndex = 2
          object WithLoop1: TMenuItem
            Caption = 'With &Loop'
            Checked = True
            GroupIndex = 1
            RadioItem = True
            OnClick = Shift1Click
          end
          object WithOutLoop1: TMenuItem
            Tag = 1
            Caption = 'With &Out Loop'
            GroupIndex = 1
            RadioItem = True
            OnClick = Shift1Click
          end
          object WithColour1: TMenuItem
            Tag = 2
            Caption = 'With &Colour'
            GroupIndex = 1
            RadioItem = True
            OnClick = Shift1Click
          end
        end
      end
      object Invert1: TMenuItem
        Caption = '&Invert'
        ImageIndex = 22
        OnClick = Invert1Click
      end
      object GreyScale1: TMenuItem
        Caption = '&Grey Scale'
        ImageIndex = 23
        OnClick = GreyScale1Click
      end
    end
    object ViewMenu: TMenuItem
      Caption = '&View'
      Visible = False
      object AddLoop2: TMenuItem
        Caption = '&Add Loop'
        object AddToEnd2: TMenuItem
          Caption = 'Add To &End'
          OnClick = AddToEndLoop1Click
        end
        object Append2: TMenuItem
          Caption = '&Append'
          OnClick = AppendLoop1Click
        end
        object Insert2: TMenuItem
          Caption = '&Insert'
          OnClick = InsertLoop1Click
        end
      end
      object DeleteLoop2: TMenuItem
        Caption = '&Delete Loop'
        OnClick = DeleteLoop1Click
      end
      object AddCel2: TMenuItem
        Caption = '&Add Cel'
        object AddToEnd1: TMenuItem
          Caption = 'Add To &End'
          OnClick = AddToEndCel1Click
        end
        object Append1: TMenuItem
          Caption = '&Append'
          OnClick = AppendCel1Click
        end
        object Insert1: TMenuItem
          Caption = '&Insert'
          OnClick = InsertCel1Click
        end
      end
      object DeleteCel2: TMenuItem
        Caption = '&Delete Cel'
        OnClick = DeleteCel1Click
      end
      object N6: TMenuItem
        Caption = '-'
        Visible = False
      end
      object Animator1: TMenuItem
        Caption = '&Animator'
        ImageIndex = 26
        OnClick = Animator1Click
      end
      object CharacterTester1: TMenuItem
        Caption = '&Character Tester'
        ImageIndex = 27
        Visible = False
      end
    end
    object FontMenu: TMenuItem
      Caption = '&Font'
      Visible = False
      object ViewFontTable1: TMenuItem
        Caption = '&View Font Table'
        ImageIndex = 32
        ShortCut = 16468
        OnClick = ViewFontTable1Click
      end
      object FontTester1: TMenuItem
        Caption = 'Font &Tester'
        ImageIndex = 49
        OnClick = FontTester1Click
      end
    end
    object CursorMenu: TMenuItem
      Caption = '&Cursor'
      Visible = False
      object SetHotSpot1: TMenuItem
        Caption = '&Set Hot Spot'
        object HotSpot001: TMenuItem
          Caption = 'Hot Spot (0,0)'
          GroupIndex = 1
          OnClick = HotSpot001Click
        end
        object HotSpot881: TMenuItem
          Caption = 'Hot Spot (8,8)'
          GroupIndex = 1
          OnClick = HotSpot001Click
        end
      end
    end
    object Zoom1: TMenuItem
      Caption = '&Zoom'
      object NormalViewing1: TMenuItem
        Tag = 2
        Caption = '&Normal Viewing'
        OnClick = Zoom1Click
      end
      object N4: TMenuItem
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
          OnClick = Zoom1Click
        end
        object N211: TMenuItem
          Tag = 2
          Caption = '&2:1'
          OnClick = Zoom1Click
        end
        object N311: TMenuItem
          Tag = 3
          Caption = '&3:1'
          OnClick = Zoom1Click
        end
        object N411: TMenuItem
          Tag = 4
          Caption = '&4:1'
          OnClick = Zoom1Click
        end
        object N511: TMenuItem
          Tag = 5
          Caption = '&5:1'
          OnClick = Zoom1Click
        end
        object N611: TMenuItem
          Tag = 6
          Caption = '&6:1'
          OnClick = Zoom1Click
        end
        object N711: TMenuItem
          Tag = 7
          Caption = '&7:1'
          OnClick = Zoom1Click
        end
        object N811: TMenuItem
          Tag = 8
          Caption = '&8:1'
          OnClick = Zoom1Click
        end
        object N911: TMenuItem
          Tag = 9
          Caption = '&9:1'
          OnClick = Zoom1Click
        end
        object N1011: TMenuItem
          Tag = 10
          Caption = '1&0:1'
          OnClick = Zoom1Click
        end
        object N1111: TMenuItem
          Tag = 11
          Caption = '11:1'
          OnClick = Zoom1Click
        end
        object N1211: TMenuItem
          Tag = 12
          Caption = '12:1'
          OnClick = Zoom1Click
        end
        object N1311: TMenuItem
          Tag = 13
          Caption = '13:1'
          OnClick = Zoom1Click
        end
        object N1411: TMenuItem
          Tag = 14
          Caption = '14:1'
          OnClick = Zoom1Click
        end
        object N1511: TMenuItem
          Tag = 15
          Caption = '15:1'
          OnClick = Zoom1Click
        end
        object N1611: TMenuItem
          Tag = 16
          Caption = '16:1'
          OnClick = Zoom1Click
        end
      end
    end
    object Import1: TMenuItem
      Caption = 'I&mport/Export'
      object WindowsBitmap1: TMenuItem
        Caption = 'Import Windows Bitmap (BMP)'
        ImageIndex = 3
        OnClick = WindowsBitmap1Click
      end
      object ExportCelsToBitmapBMP1: TMenuItem
        Caption = 'Export Cels To Bitmap (BMP)'
        Visible = False
        OnClick = ExportCelsToBitmapBMP1Click
      end
    end
  end
  object BrushStyleMenu: TPopupMenu
    BiDiMode = bdLeftToRight
    Images = WndMain.ilStyles
    ParentBiDiMode = False
    Left = 258
    Top = 1
    object Solid1: TMenuItem
      Caption = '&Solid'
      ImageIndex = 0
      OnClick = BrushStyle1Click
    end
    object Clear2: TMenuItem
      Tag = 1
      Caption = '&Clear'
      ImageIndex = 1
      OnClick = BrushStyle1Click
    end
    object BDiagonal1: TMenuItem
      Tag = 2
      Caption = '&BDiagonal'
      ImageIndex = 2
      OnClick = BrushStyle1Click
    end
    object FDiagonal1: TMenuItem
      Tag = 3
      Caption = '&FDiagonal'
      ImageIndex = 3
      OnClick = BrushStyle1Click
    end
    object Cross1: TMenuItem
      Tag = 4
      Caption = '&Cross'
      ImageIndex = 4
      OnClick = BrushStyle1Click
    end
    object DiagCross1: TMenuItem
      Tag = 5
      Caption = '&DiagCross'
      ImageIndex = 5
      OnClick = BrushStyle1Click
    end
    object Horizontal1: TMenuItem
      Tag = 6
      Caption = '&Horizontal'
      ImageIndex = 6
      OnClick = BrushStyle1Click
    end
    object Vertical1: TMenuItem
      Tag = 7
      Caption = '&Vertical'
      ImageIndex = 7
      OnClick = BrushStyle1Click
    end
  end
  object PenSizeMenu: TPopupMenu
    BiDiMode = bdLeftToRight
    Images = WndMain.ilStyles
    OwnerDraw = True
    ParentBiDiMode = False
    Left = 290
    Top = 2
    object N11: TMenuItem
      Tag = 1
      Caption = '&1'
      ImageIndex = 8
      OnClick = PenSize1Click
    end
    object N21: TMenuItem
      Tag = 2
      Caption = '&2'
      ImageIndex = 9
      OnClick = PenSize1Click
    end
    object N31: TMenuItem
      Tag = 3
      Caption = '&3'
      ImageIndex = 10
      OnClick = PenSize1Click
    end
    object N41: TMenuItem
      Tag = 4
      Caption = '&4'
      ImageIndex = 11
      OnClick = PenSize1Click
    end
    object N51: TMenuItem
      Tag = 5
      Caption = '&5'
      ImageIndex = 12
      OnClick = PenSize1Click
    end
    object N61: TMenuItem
      Tag = 6
      Caption = '&6'
      ImageIndex = 13
      OnClick = PenSize1Click
    end
    object N71: TMenuItem
      Tag = 7
      Caption = '&7'
      ImageIndex = 14
      OnClick = PenSize1Click
    end
    object N81: TMenuItem
      Tag = 8
      Caption = '&8'
      ImageIndex = 15
      OnClick = PenSize1Click
    end
  end
  object OpenDialog: TOpenDialog
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Left = 354
    Top = 2
  end
  object SaveDialog: TSaveDialog
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 386
    Top = 2
  end
  object PenStyleMenu: TPopupMenu
    BiDiMode = bdLeftToRight
    Images = WndMain.ilStyles
    OwnerDraw = True
    ParentBiDiMode = False
    Left = 322
    Top = 2
    object Solid2: TMenuItem
      Caption = '&Solid'
      ImageIndex = 16
      OnClick = PenStyle1Click
    end
    object Dash1: TMenuItem
      Tag = 1
      Caption = 'D&ash'
      ImageIndex = 17
      OnClick = PenStyle1Click
    end
    object Dot1: TMenuItem
      Tag = 2
      Caption = 'D&ot'
      ImageIndex = 18
      OnClick = PenStyle1Click
    end
    object DashDot1: TMenuItem
      Tag = 3
      Caption = '&Dash Dot'
      ImageIndex = 19
      OnClick = PenStyle1Click
    end
    object DashDotDot1: TMenuItem
      Tag = 4
      Caption = 'Dash Dot Do&t'
      ImageIndex = 20
      OnClick = PenStyle1Click
    end
    object Clear3: TMenuItem
      Tag = 5
      Caption = '&Clear'
      ImageIndex = 21
      OnClick = PenStyle1Click
    end
  end
  object tmrSelCel: TTimer
    Enabled = False
    Interval = 120
    OnTimer = tmrSelCelTimer
    Left = 354
    Top = 32
  end
  object tmrSelection: TTimer
    Enabled = False
    Interval = 200
    OnTimer = tmrSelectionTimer
    Left = 386
    Top = 32
  end
  object pmCel: TPopupMenu
    Left = 194
    Top = 2
    object AddCel1: TMenuItem
      Caption = '&Add Cel'
      object AddToEndCel1: TMenuItem
        Caption = 'Add To &End'
        OnClick = AddToEndCel1Click
      end
      object AppendCel1: TMenuItem
        Caption = '&Append'
        OnClick = AppendCel1Click
      end
      object InsertCel1: TMenuItem
        Caption = '&Insert'
        OnClick = InsertCel1Click
      end
    end
    object DeleteCel1: TMenuItem
      Caption = '&Delete Cel'
      OnClick = DeleteCel1Click
    end
  end
  object pmLoop: TPopupMenu
    Left = 226
    Top = 2
    object AddLoop1: TMenuItem
      Caption = '&Add Loop'
      object AddToEndLoop1: TMenuItem
        Caption = 'Add To &End'
        OnClick = AddToEndLoop1Click
      end
      object AppendLoop1: TMenuItem
        Caption = '&Append'
        OnClick = AppendLoop1Click
      end
      object InsertLoop1: TMenuItem
        Caption = '&Insert'
        OnClick = InsertLoop1Click
      end
    end
    object DeleteLoop1: TMenuItem
      Caption = '&Delete Loop'
      OnClick = DeleteLoop1Click
    end
  end
  object tmrSelChar: TTimer
    Enabled = False
    Interval = 120
    OnTimer = tmrSelCharTimer
    Left = 354
    Top = 66
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Filter = 'Bitmaps (*.bmp)|*.bmp'
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Left = 418
    Top = 2
  end
end
