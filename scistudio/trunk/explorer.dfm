object WndExplorer: TWndExplorer
  Tag = 1
  Left = 64
  Top = 25
  Width = 707
  Height = 482
  Caption = 'Game Explorer'
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
  WindowState = wsMaximized
  PixelsPerInch = 96
  TextHeight = 13
  object tbExplorer: TToolBar
    Left = 0
    Top = 0
    Width = 699
    Height = 28
    AutoSize = True
    ButtonHeight = 28
    ButtonWidth = 29
    EdgeBorders = []
    Flat = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -9
    Font.Name = 'Tahoma'
    Font.Style = []
    HotImages = ImageList1
    Images = ilExplorer
    ParentFont = False
    TabOrder = 0
    object tbAdd: TToolButton
      Left = 0
      Top = 0
      Caption = 'Add'
      ImageIndex = 0
      OnClick = tbAddClick
    end
    object tbExtract: TToolButton
      Left = 29
      Top = 0
      Caption = 'Extract'
      ImageIndex = 1
      OnClick = tbExtractClick
    end
    object tbDelete: TToolButton
      Left = 58
      Top = 0
      Caption = 'Delete'
      ImageIndex = 2
      OnClick = tbDeleteClick
    end
    object ToolButton4: TToolButton
      Left = 87
      Top = 0
      Width = 8
      Caption = 'ToolButton4'
      ImageIndex = 3
      Style = tbsSeparator
    end
    object tbEdit: TToolButton
      Left = 95
      Top = 0
      Caption = 'Edit'
      ImageIndex = 6
      OnClick = tbEditClick
    end
    object tbPropeties: TToolButton
      Left = 124
      Top = 0
      Caption = 'Propeties'
      ImageIndex = 4
      OnClick = tbPropetiesClick
    end
    object ToolButton7: TToolButton
      Left = 153
      Top = 0
      Width = 8
      Caption = 'ToolButton7'
      ImageIndex = 5
      Style = tbsSeparator
    end
    object tbRebuild: TToolButton
      Left = 161
      Top = 0
      Caption = 'Rebuild'
      ImageIndex = 3
      OnClick = tbRebuildClick
    end
    object ToolButton1: TToolButton
      Left = 190
      Top = 0
      Width = 8
      Caption = 'ToolButton1'
      ImageIndex = 7
      Style = tbsSeparator
    end
    object tbView: TToolButton
      Left = 198
      Top = 0
      Caption = 'View'
      DropdownMenu = popViewStyle
      ImageIndex = 5
      Style = tbsDropDown
      OnClick = tbViewClick
    end
    object ToolButton2: TToolButton
      Left = 242
      Top = 0
      Width = 8
      Caption = 'ToolButton2'
      ImageIndex = 6
      Style = tbsSeparator
    end
    object Label26: TLabel
      Left = 250
      Top = 0
      Width = 83
      Height = 28
      Caption = ' SCI Version:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      Layout = tlCenter
    end
    object lbSCIVersion: TLabel
      Left = 333
      Top = 0
      Width = 5
      Height = 28
      Caption = '-'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      Layout = tlCenter
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 28
    Width = 699
    Height = 427
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    object spResTypes: TSplitter
      Left = 113
      Top = 2
      Width = 3
      Height = 423
      Cursor = crHSplit
    end
    object spPreview: TSplitter
      Left = 456
      Top = 2
      Width = 3
      Height = 423
      Cursor = crHSplit
    end
    object PanelLV: TPanel
      Left = 116
      Top = 2
      Width = 340
      Height = 423
      Align = alLeft
      BevelInner = bvLowered
      BevelOuter = bvNone
      TabOrder = 0
      object lvResources: TListView
        Left = 1
        Top = 65
        Width = 338
        Height = 357
        Align = alClient
        BorderStyle = bsNone
        Columns = <
          item
            Caption = 'Name'
            Width = 80
          end
          item
            Caption = 'Number'
          end
          item
            Caption = 'Size'
          end
          item
            Caption = 'Package'
            Width = 30
          end
          item
            Caption = 'Offset'
            Width = 70
          end
          item
            Caption = 'Encoding'
            Width = 40
          end>
        HideSelection = False
        LargeImages = WndMain.ilResIcons
        MultiSelect = True
        RowSelect = True
        PopupMenu = popExplorer
        SmallImages = WndMain.ilResIconsS
        TabOrder = 0
        ViewStyle = vsReport
        OnChange = lvResourcesChange
        OnClick = lvResourcesClick
        OnColumnClick = lvResourcesColumnClick
        OnDblClick = lvResourcesDblClick
        OnEdited = lvResourcesEdited
        OnKeyPress = lvResourcesKeyPress
      end
      object pnResCap: TPanel
        Left = 1
        Top = 1
        Width = 338
        Height = 64
        Align = alTop
        TabOrder = 1
        object Panel14: TPanel
          Left = 1
          Top = 1
          Width = 336
          Height = 30
          Align = alTop
          AutoSize = True
          BevelOuter = bvNone
          BorderWidth = 2
          TabOrder = 0
          object Panel16: TPanel
            Left = 2
            Top = 2
            Width = 332
            Height = 26
            Align = alTop
            BevelOuter = bvNone
            TabOrder = 0
            object lblResType: TLabel
              Left = 31
              Top = 0
              Width = 218
              Height = 24
              AutoSize = False
              Caption = '-'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -16
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentFont = False
              Layout = tlCenter
            end
            object imgResType: TImage
              Tag = 44321
              Left = 2
              Top = 1
              Width = 25
              Height = 25
            end
            object Panel15: TPanel
              Left = 312
              Top = 0
              Width = 20
              Height = 26
              Align = alRight
              BevelOuter = bvNone
              TabOrder = 0
              object SpeedButton1: TSpeedButton
                Left = 0
                Top = 0
                Width = 20
                Height = 17
                Flat = True
                Glyph.Data = {
                  9E010000424D9E0100000000000036000000280000000A000000090000000100
                  2000000000006801000000000000000000000000000000000000C6C6C600C6C6
                  C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6
                  C600C6C6C6000000000000000000C6C6C600C6C6C600C6C6C600C6C6C6000000
                  000000000000C6C6C600C6C6C600C6C6C6000000000000000000C6C6C600C6C6
                  C6000000000000000000C6C6C600C6C6C600C6C6C600C6C6C600C6C6C6000000
                  0000000000000000000000000000C6C6C600C6C6C600C6C6C600C6C6C600C6C6
                  C600C6C6C600C6C6C6000000000000000000C6C6C600C6C6C600C6C6C600C6C6
                  C600C6C6C600C6C6C600C6C6C60000000000000000000000000000000000C6C6
                  C600C6C6C600C6C6C600C6C6C600C6C6C6000000000000000000C6C6C600C6C6
                  C6000000000000000000C6C6C600C6C6C600C6C6C6000000000000000000C6C6
                  C600C6C6C600C6C6C600C6C6C6000000000000000000C6C6C600C6C6C600C6C6
                  C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6
                  C600}
                OnClick = SpeedButton1Click
              end
            end
          end
        end
        object Panel17: TPanel
          Left = 1
          Top = 31
          Width = 336
          Height = 32
          Align = alClient
          BevelOuter = bvNone
          BorderWidth = 2
          TabOrder = 1
          object lblResTypeDesc: TLabel
            Left = 2
            Top = 2
            Width = 332
            Height = 13
            Align = alTop
            Caption = '-'
            WordWrap = True
          end
        end
      end
    end
    object pnResTypes: TPanel
      Left = 2
      Top = 2
      Width = 111
      Height = 423
      Align = alLeft
      BevelInner = bvLowered
      BevelOuter = bvNone
      TabOrder = 1
      object tvResTypes: TTreeView
        Left = 1
        Top = 20
        Width = 109
        Height = 402
        Align = alClient
        BorderStyle = bsNone
        Ctl3D = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        HideSelection = False
        Images = WndMain.ilTreeView
        Indent = 19
        ParentCtl3D = False
        ParentFont = False
        ReadOnly = True
        RightClickSelect = True
        TabOrder = 0
        OnChange = tvResTypesChange
        OnClick = tvResTypesClick
        OnEdited = tvResTypesEdited
      end
      object Panel6: TPanel
        Left = 1
        Top = 1
        Width = 109
        Height = 19
        Align = alTop
        TabOrder = 1
        object Label1: TLabel
          Left = 5
          Top = 3
          Width = 50
          Height = 13
          Caption = 'Resources'
          Color = clLime
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBtnText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          Transparent = True
          Layout = tlCenter
        end
        object Panel7: TPanel
          Left = 88
          Top = 1
          Width = 20
          Height = 17
          Align = alRight
          BevelOuter = bvNone
          TabOrder = 0
          object BtnCloseResTV: TSpeedButton
            Left = 0
            Top = 0
            Width = 20
            Height = 17
            Flat = True
            Glyph.Data = {
              9E010000424D9E0100000000000036000000280000000A000000090000000100
              2000000000006801000000000000000000000000000000000000C6C6C600C6C6
              C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6
              C600C6C6C6000000000000000000C6C6C600C6C6C600C6C6C600C6C6C6000000
              000000000000C6C6C600C6C6C600C6C6C6000000000000000000C6C6C600C6C6
              C6000000000000000000C6C6C600C6C6C600C6C6C600C6C6C600C6C6C6000000
              0000000000000000000000000000C6C6C600C6C6C600C6C6C600C6C6C600C6C6
              C600C6C6C600C6C6C6000000000000000000C6C6C600C6C6C600C6C6C600C6C6
              C600C6C6C600C6C6C600C6C6C60000000000000000000000000000000000C6C6
              C600C6C6C600C6C6C600C6C6C600C6C6C6000000000000000000C6C6C600C6C6
              C6000000000000000000C6C6C600C6C6C600C6C6C6000000000000000000C6C6
              C600C6C6C600C6C6C600C6C6C6000000000000000000C6C6C600C6C6C600C6C6
              C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6
              C600}
            OnClick = BtnCloseResTVClick
          end
        end
      end
    end
    object pnPreview: TPanel
      Left = 459
      Top = 2
      Width = 238
      Height = 423
      Align = alClient
      BevelOuter = bvLowered
      Color = clWindow
      TabOrder = 2
      object Panel8: TPanel
        Left = 1
        Top = 1
        Width = 236
        Height = 33
        Align = alTop
        TabOrder = 0
        object PreviewCaption: TLabel
          Left = 6
          Top = 4
          Width = 76
          Height = 23
          Caption = 'Preview'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          Transparent = True
        end
        object Panel10: TPanel
          Left = 215
          Top = 1
          Width = 20
          Height = 31
          Align = alRight
          BevelOuter = bvNone
          TabOrder = 0
          object SpeedButton2: TSpeedButton
            Left = 0
            Top = 0
            Width = 20
            Height = 17
            Flat = True
            Glyph.Data = {
              9E010000424D9E0100000000000036000000280000000A000000090000000100
              2000000000006801000000000000000000000000000000000000C6C6C600C6C6
              C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6
              C600C6C6C6000000000000000000C6C6C600C6C6C600C6C6C600C6C6C6000000
              000000000000C6C6C600C6C6C600C6C6C6000000000000000000C6C6C600C6C6
              C6000000000000000000C6C6C600C6C6C600C6C6C600C6C6C600C6C6C6000000
              0000000000000000000000000000C6C6C600C6C6C600C6C6C600C6C6C600C6C6
              C600C6C6C600C6C6C6000000000000000000C6C6C600C6C6C600C6C6C600C6C6
              C600C6C6C600C6C6C600C6C6C60000000000000000000000000000000000C6C6
              C600C6C6C600C6C6C600C6C6C600C6C6C6000000000000000000C6C6C600C6C6
              C6000000000000000000C6C6C600C6C6C600C6C6C6000000000000000000C6C6
              C600C6C6C600C6C6C600C6C6C6000000000000000000C6C6C600C6C6C600C6C6
              C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6
              C600}
            OnClick = SpeedButton2Click
          end
        end
      end
      object PreviewPC: TPageControl
        Left = 1
        Top = 34
        Width = 236
        Height = 388
        ActivePage = PicPage
        Align = alClient
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        HotTrack = True
        ParentFont = False
        ParentShowHint = False
        RaggedRight = True
        ShowHint = False
        Style = tsFlatButtons
        TabOrder = 1
        object ViewPage: TTabSheet
          Caption = 'View'
          TabVisible = False
          object scbView: TScrollBox
            Left = 128
            Top = 0
            Width = 100
            Height = 378
            Align = alClient
            BorderStyle = bsNone
            TabOrder = 0
            object imgView: TImage
              Left = 0
              Top = 0
              Width = 146
              Height = 151
            end
            object shpView: TShape
              Left = 40
              Top = 64
              Width = 65
              Height = 65
              Brush.Style = bsClear
            end
          end
          object Panel2: TPanel
            Left = 0
            Top = 0
            Width = 128
            Height = 378
            Align = alLeft
            BevelOuter = bvNone
            ParentColor = True
            TabOrder = 1
            object Label5: TLabel
              Left = 4
              Top = 106
              Width = 45
              Height = 13
              Caption = 'Mirror of:'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object TransColour: TShape
              Left = 80
              Top = 86
              Width = 41
              Height = 17
            end
            object Label9: TLabel
              Left = 4
              Top = 88
              Width = 70
              Height = 13
              Caption = 'Transparency:'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object Label3: TLabel
              Left = 4
              Top = 66
              Width = 35
              Height = 13
              Caption = 'Height:'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object Label4: TLabel
              Left = 4
              Top = 47
              Width = 32
              Height = 13
              Caption = 'Width:'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object CelStats: TLabel
              Left = 42
              Top = 21
              Width = 28
              Height = 13
              Caption = '00/00'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object LoopStats: TLabel
              Left = 42
              Top = 1
              Width = 28
              Height = 13
              Caption = '00/00'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object Label6: TLabel
              Left = 4
              Top = 1
              Width = 30
              Height = 13
              Caption = 'Loop: '
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object Label7: TLabel
              Left = 4
              Top = 21
              Width = 19
              Height = 13
              Caption = 'Cel:'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
            end
            object btnAnimateView: TSpeedButton
              Left = 0
              Top = 146
              Width = 65
              Height = 25
              AllowAllUp = True
              GroupIndex = 1
              Caption = 'Animate'
              OnClick = btnAnimateViewClick
            end
            object imVPal: TImage
              Left = 0
              Top = 200
              Width = 128
              Height = 160
            end
            object btnToBmp: TSpeedButton
              Left = 70
              Top = 146
              Width = 57
              Height = 25
              Caption = 'To Bmp'
              OnClick = btnToBmpClick
            end
            object Mirroring: TEdit
              Left = 5
              Top = 121
              Width = 116
              Height = 19
              Ctl3D = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentColor = True
              ParentCtl3D = False
              ParentFont = False
              ReadOnly = True
              TabOrder = 0
            end
            object CelHeight: TEdit
              Left = 43
              Top = 64
              Width = 26
              Height = 16
              AutoSize = False
              Ctl3D = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentColor = True
              ParentCtl3D = False
              ParentFont = False
              ReadOnly = True
              TabOrder = 1
            end
            object CelWidth: TEdit
              Left = 43
              Top = 45
              Width = 26
              Height = 16
              AutoSize = False
              Ctl3D = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentColor = True
              ParentCtl3D = False
              ParentFont = False
              ReadOnly = True
              TabOrder = 2
            end
            object SwitchCel_UpDn: TUpDown
              Left = 97
              Top = 20
              Width = 24
              Height = 16
              Min = 0
              Max = 0
              Orientation = udHorizontal
              Position = 0
              TabOrder = 3
              Wrap = False
              OnClick = SwitchLoop_UpDnClick
            end
            object SwitchLoop_UpDn: TUpDown
              Tag = 1
              Left = 97
              Top = 0
              Width = 24
              Height = 16
              Min = 0
              Max = 0
              Orientation = udHorizontal
              Position = 0
              TabOrder = 4
              Wrap = False
              OnClick = SwitchLoop_UpDnClick
            end
            object cbViewPal: TComboBox
              Left = 0
              Top = 179
              Width = 129
              Height = 21
              Style = csDropDownList
              ItemHeight = 13
              TabOrder = 5
              OnChange = cbViewPalChange
            end
          end
        end
        object PicPage: TTabSheet
          Caption = 'Picture'
          TabVisible = False
          object PicScrollBox: TScrollBox
            Left = 0
            Top = 0
            Width = 228
            Height = 378
            Align = alClient
            BorderStyle = bsNone
            TabOrder = 0
            object pnlPic: TPanel
              Left = 0
              Top = 0
              Width = 322
              Height = 336
              AutoSize = True
              BevelOuter = bvNone
              ParentColor = True
              TabOrder = 0
              object shpPic: TShape
                Left = 0
                Top = 0
                Width = 322
                Height = 192
              end
              object imgPic: TImage
                Left = 1
                Top = 1
                Width = 320
                Height = 190
              end
              object imPPal: TImage
                Left = 0
                Top = 196
                Width = 322
                Height = 56
              end
              object pnPicCtl: TPanel
                Left = 24
                Top = 256
                Width = 150
                Height = 80
                BevelOuter = bvNone
                ParentColor = True
                TabOrder = 0
                object VisualButton: TSpeedButton
                  Left = 0
                  Top = 0
                  Width = 50
                  Height = 21
                  GroupIndex = 123
                  Down = True
                  Caption = 'Visual'
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = [fsBold]
                  ParentFont = False
                  Spacing = 0
                  OnClick = btnPicScreenClick
                end
                object PriorityButton: TSpeedButton
                  Tag = 1
                  Left = 50
                  Top = 0
                  Width = 50
                  Height = 21
                  GroupIndex = 123
                  Caption = 'Priority'
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = [fsBold]
                  ParentFont = False
                  Spacing = 0
                  OnClick = btnPicScreenClick
                end
                object ControlButton: TSpeedButton
                  Tag = 2
                  Left = 100
                  Top = 0
                  Width = 50
                  Height = 21
                  GroupIndex = 123
                  Caption = 'Control'
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = [fsBold]
                  ParentFont = False
                  Spacing = 0
                  OnClick = btnPicScreenClick
                end
                object btnAnimatePic: TSpeedButton
                  Left = 0
                  Top = 55
                  Width = 73
                  Height = 25
                  AllowAllUp = True
                  GroupIndex = 1
                  Caption = 'Animate'
                  OnClick = btnAnimatePicClick
                end
                object Label22: TLabel
                  Left = 12
                  Top = 25
                  Width = 50
                  Height = 22
                  AutoSize = False
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
                object SpeedButton3: TSpeedButton
                  Left = 80
                  Top = 55
                  Width = 70
                  Height = 25
                  Caption = 'To Bmp'
                  OnClick = SpeedButton3Click
                end
                object ToolBar6: TToolBar
                  Left = 62
                  Top = 23
                  Width = 76
                  Height = 23
                  Align = alNone
                  ButtonHeight = 21
                  ButtonWidth = 19
                  EdgeBorders = []
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clBlue
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  ParentFont = False
                  ShowCaptions = True
                  TabOrder = 0
                  Transparent = True
                  Wrapable = False
                  object tbPal0: TToolButton
                    Left = 0
                    Top = 2
                    Caption = ' 0 '
                    Down = True
                    Grouped = True
                    ImageIndex = 0
                    Style = tbsCheck
                    OnClick = tbPal0Click
                  end
                  object tbPal1: TToolButton
                    Tag = 1
                    Left = 19
                    Top = 2
                    Caption = ' 1 '
                    Grouped = True
                    ImageIndex = 1
                    Style = tbsCheck
                    OnClick = tbPal0Click
                  end
                  object tbPal2: TToolButton
                    Tag = 2
                    Left = 38
                    Top = 2
                    Caption = ' 2 '
                    Grouped = True
                    ImageIndex = 2
                    Style = tbsCheck
                    OnClick = tbPal0Click
                  end
                  object tbPal3: TToolButton
                    Tag = 3
                    Left = 57
                    Top = 2
                    Caption = ' 3 '
                    Grouped = True
                    ImageIndex = 3
                    Style = tbsCheck
                    OnClick = tbPal0Click
                  end
                end
              end
            end
          end
        end
        object FontPage: TTabSheet
          Caption = 'Font'
          TabVisible = False
          object scrFont: TScrollBox
            Left = 0
            Top = 0
            Width = 255
            Height = 377
            Align = alClient
            BorderStyle = bsNone
            Color = clWhite
            ParentColor = False
            TabOrder = 0
            object imgFont: TImage
              Left = 0
              Top = 0
              Width = 169
              Height = 209
            end
          end
        end
        object CursorPage: TTabSheet
          Caption = 'Cursor'
          TabVisible = False
          object pnlCursor: TPanel
            Left = 0
            Top = 0
            Width = 145
            Height = 57
            BevelOuter = bvNone
            ParentColor = True
            TabOrder = 0
            object MouseHS: TLabel
              Left = 0
              Top = 44
              Width = 6
              Height = 13
              Align = alBottom
              Alignment = taCenter
              Caption = '0'
            end
            object Shape1: TShape
              Left = 55
              Top = 0
              Width = 34
              Height = 34
            end
            object imgCursor: TImage
              Left = 56
              Top = 1
              Width = 32
              Height = 32
            end
          end
        end
        object MemoPage: TTabSheet
          Caption = 'Script'
          TabVisible = False
          object PreviewMemo: TMemo
            Left = 0
            Top = 0
            Width = 255
            Height = 377
            Align = alClient
            BorderStyle = bsNone
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            ReadOnly = True
            ScrollBars = ssBoth
            TabOrder = 0
          end
        end
        object SoundPage: TTabSheet
          Caption = 'Sound'
          TabVisible = False
          object Label2: TLabel
            Left = 0
            Top = 169
            Width = 240
            Height = 39
            Align = alTop
            Caption = 
              'Simply click on the button below, then select File->Open from th' +
              'e SOUNDBOX menu and select the extracted sound!'
            WordWrap = True
          end
          object Label16: TLabel
            Left = 0
            Top = 0
            Width = 254
            Height = 39
            Align = alTop
            Caption = 
              'No sound preview is available. This version of SCI Studio does n' +
              'ot yet support the playing or editing of sounds.'
            WordWrap = True
          end
          object Label18: TLabel
            Left = 0
            Top = 52
            Width = 254
            Height = 39
            Align = alTop
            Caption = 
              'However, there is a tool available for creating and manipulating' +
              ' SCI sound resources. It was created by Ravi Iyengar, and is cal' +
              'led SOUNDBOX.'
            WordWrap = True
          end
          object Label21: TLabel
            Left = 0
            Top = 104
            Width = 252
            Height = 52
            Align = alTop
            Caption = 
              'To incoporate SOUNDBOX with SCI Studio, simply download it and p' +
              'lace it in the same directory SCI Studio is located in. You will' +
              ' then be able to execute it directly from within SCI Studio!'
            WordWrap = True
          end
          object Label19: TLabel
            Left = 0
            Top = 91
            Width = 3
            Height = 13
            Align = alTop
          end
          object Label23: TLabel
            Left = 0
            Top = 156
            Width = 3
            Height = 13
            Align = alTop
          end
          object Label24: TLabel
            Left = 0
            Top = 39
            Width = 3
            Height = 13
            Align = alTop
          end
          object Label25: TLabel
            Left = 0
            Top = 208
            Width = 3
            Height = 13
            Align = alTop
          end
          object Panel3: TPanel
            Left = 0
            Top = 221
            Width = 255
            Height = 76
            Align = alTop
            BevelOuter = bvNone
            ParentColor = True
            TabOrder = 0
            object Label20: TLabel
              Left = 14
              Top = 47
              Width = 193
              Height = 13
              Cursor = crHandPoint
              Caption = 'Click here to download SOUNDBOX.'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlue
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = [fsBold, fsUnderline]
              ParentFont = False
              OnClick = Label20Click
            end
            object Button1: TButton
              Left = 6
              Top = 3
              Width = 289
              Height = 33
              Caption = 'Click here to extract this sound and execute SOUNDBOX.'
              TabOrder = 0
              OnClick = Button1Click
            end
          end
        end
        object PageNoPrev: TTabSheet
          TabVisible = False
          object Label11: TLabel
            Left = 6
            Top = 3
            Width = 137
            Height = 16
            Caption = 'No preview available.'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Tahoma'
            Font.Style = [fsBold]
            ParentFont = False
          end
        end
        object PageNone: TTabSheet
          ImageIndex = 8
          TabVisible = False
          object LblPgNone: TLabel
            Left = 0
            Top = 0
            Width = 3
            Height = 13
            Align = alClient
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
        end
        object UnkComPage: TTabSheet
          ImageIndex = 9
          TabVisible = False
          object Label8: TLabel
            Left = 0
            Top = 0
            Width = 269
            Height = 23
            Align = alTop
            Alignment = taCenter
            Caption = 'Unknown Encoding Method!'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clRed
            Font.Height = -19
            Font.Name = 'Tahoma'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object Label10: TLabel
            Left = 0
            Top = 23
            Width = 261
            Height = 21
            Align = alTop
            Alignment = taCenter
            Caption = 'Resource file is most likely corrupt!'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -17
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
        end
        object ErrPage: TTabSheet
          ImageIndex = 10
          TabVisible = False
          object Label12: TLabel
            Left = 0
            Top = 23
            Width = 202
            Height = 42
            Align = alTop
            Alignment = taCenter
            Caption = 'Resource file is most likely missing or corrupt!'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -17
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            WordWrap = True
          end
          object Label13: TLabel
            Left = 0
            Top = 0
            Width = 260
            Height = 23
            Align = alTop
            Alignment = taCenter
            Caption = 'Unable to extract resource!'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clRed
            Font.Height = -19
            Font.Name = 'Tahoma'
            Font.Style = [fsBold]
            ParentFont = False
          end
        end
        object PageGameInfo: TTabSheet
          ImageIndex = 12
          TabVisible = False
          object Panel5: TPanel
            Left = 0
            Top = 0
            Width = 228
            Height = 41
            Align = alTop
            BevelOuter = bvNone
            ParentColor = True
            TabOrder = 0
            object shpGameIcon: TShape
              Left = 2
              Top = 7
              Width = 34
              Height = 34
            end
            object Label14: TLabel
              Left = 41
              Top = 8
              Width = 71
              Height = 13
              Caption = 'Game Name:'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentFont = False
            end
            object lName: TLabel
              Left = 145
              Top = 8
              Width = 4
              Height = 13
              Caption = '-'
            end
            object lLocation: TLabel
              Left = 145
              Top = 24
              Width = 4
              Height = 13
              Caption = '-'
            end
            object Label17: TLabel
              Left = 41
              Top = 24
              Width = 51
              Height = 13
              Caption = 'Location:'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentFont = False
            end
            object imgGameIcon: TImage
              Left = 3
              Top = 8
              Width = 32
              Height = 32
              Cursor = crHandPoint
              Hint = 'Click to select a game icon.'
              ParentShowHint = False
              Picture.Data = {
                07544269746D6170360C0000424D360C00000000000036000000280000002000
                0000200000000100180000000000000C0000130B0000130B0000000000000000
                0000272727000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00004F4F4F5656563C3C3C3C3C3C3D3D3D3D3D3D3C3C3C3E3E3E5E5E5E525252
                3C3C3C3D3D3D3D3D3D3D3D3D3D3D3D3D3D3D3D3D3D3D3D3D3D3D3D3D3D3D3D3D
                3D3D3D3D3C3C3C3C3C3C38383836363633333636363646464449494449494752
                524C4F4F4F6E6E6E727272696969696969696969696969747474959595707070
                6969696969696969696969696969696969696969696969696969696969696969
                696969696969695E5E5D5F5F6063637958588857575D8F8F817979777B7B7B42
                42424F4F4F716868767474797979848484818181818181858585848484858585
                8787878787878787878787878787878787878787878787878787878787878787
                8787878785858582828F7B7B9B93A6E17F88CC747492C2C2A99E9EA074748547
                474E4F4F4F8C6868797474B8B8B88A8A8A7E7B7B716D6D767676858585878787
                8888888888888888888888888888888888888787878787878787878787878787
                878787878585848A8AC17B7BB07675D26E76D68899CFB2BFCF9599D07778A745
                455A4F4F4F8C68688371719996967C7C7CB17B7BB97E7E7E7E7B787879888888
                8888888A8A8A8A8A8A8A8A8A8A8A8A8A8A8A8888888882828A87879684848D85
                8588888888888785859F7878BA7272CE6D6FD8A6A6C8A4AFD9A0A7E56E72A63D
                40584F4F4F8F6C6CB97373C26B6BC46E6ED76F6FD49994C8C8A07F7F707F7F81
                8A8A8A8A8A8A8B8B8B8B8B8B8B8B8B8A8A8A8A8A8AAC8282A58484AF7F7F8A8A
                8A8A8A8A8A8A8A8A8A8A8A8A8888888B7E7FA5BCBDB6B8B6B69898A97072A240
                3F484F4F4F76777CB38689EE8F8FED8B8BEA8787D39FA8DEDEB9C5C58E94948B
                9292918D8D8E8B8B8B8B8B8B8B8B8B8B8B8B9E8D8DCA8181BC7B7B8B88888D94
                9492ADAD8FA0A08D91918B8B8B8B8A8A8B8B8BB6B7A58D8F8FA9AA9E8C8E9341
                41584F4F4F7072726169762600004E1C1CED9797F4A29FDBC2A0DADABAE4E4B8
                DBDBC7C5C5AFAEAE9C9E9E959494948F8F8F9F8B94E281819F7E7E8C8C8C8789
                897E8C8C88A4A491B8B895BCBC8EABAB96A09DA3A69C7E818B04081014172C3D
                3D5A4F4F4F4646462B2B2B0000007E5C53C08A8AD19090DC9A9BBAC8A2B6CFA3
                D3DDC3E7E8D9F0F0E6EAEADBD6D6C0BFBFA89F9CA6AC7172927C7C9696988E8E
                927878787574747E7E7E7E817F6C797B82908507110B00000000000011111111
                11134F4F4F4646462B2B2B0000009C8A769A9C8563544E24285A567874619160
                456A480914080A1A05535F4DBEC7ADD3D6C87C7C780606060A0A0D63636B7A7A
                8C8C92A142423C3E3E3D7E7E77413A3A00000000000000000000000011111111
                11114F4F4F4646462B2B2B020000E78821E78A23000000000000111F29000000
                0000000000000000000000000316030000000000000000000000000000002F2F
                2C36363A000000000000222218000000000000E78A23E7882100000011111111
                11114F4F4F4646462B2B2BE7871EE78821000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000000000000000000000E78821E7871E11111111
                11114F4F4F464646C4833DE7871E000000000000000000E88D28E88E2B000000
                000000E99232E99334E99436000000000000E99436E99436E994360000000000
                00E99232E99030000000E88E2BE88D28000000000000000000E7871EAA692311
                11114F4F4F464646C4833DE7871E000000000000000000E88D28E88E2B000000
                E99030E99232000000000000000000EA9538EA9538000000EA9538E994360000
                00E99232E99030000000E88E2BE88D28000000000000000000E7871EAA692311
                11114F4F4F464646C4833DE7871E000000000000000000E88D28E88E2B000000
                E99030E99232000000000000000000EA963BEA963B000000EA9538E994360000
                00E99232E99030000000E88E2BE88D28000000000000000000E7871EAA692311
                11114F4F4F464646C4833DE7871E000000000000000000E88D28E88E2B000000
                E99030E99232000000000000000000EA963BEA983E000000EA9538E994360000
                00E99232E99030000000E88E2BE88D280000003B3525000000E7871EAA692311
                11114F4F4F464646C4833DE7871E000000000000000000E88D28E88E2B000000
                000000E99232E99334E99436000000000000EA963BEA963BEA95380000000000
                00E99232E99030E88F2DE88E2B000000000000080D17000000E7871EAA692311
                11114F4F4F464646C4833DE7871E000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00000000000000000000000000000000000000000000000000E7871EAA692311
                11114F4F4F4646462B2B2BE7871EE78821000000000000E88D28E88E2B000000
                0000000000000000007B5D5D5B4745000000000000000000000000383F524148
                6100000000000000000000000000000002091D000000E78821E7871E11111117
                1E284F4F4F4646462B2B2B000000E78821E78A23000000000000444159544D65
                6B5D66A18586B48D8DB08989816F715E62865E6C885F6C8A5C698C5055904C4F
                88945860A9868F8C7B786E5B72404156000000E78A23E7882100000011111129
                383D4F4F4F5454542B2B2B0000008B7871000000000000302D2B646265555561
                57597265697B6A678F7C718D7774846A7CA76378AA67709B66789B6D78998184
                94D4B5BDC88C9DB5646BA8545B7E4F52A8668787695D0000000000002C33512B
                403B4F4F4F7E7D7D8B8B8B9D9D9DA4A4A49A9A9A979797A6A6A6B4B4B4BCBCBC
                ABABAB9A9A998888887A7A86777A907577967577A37A7FAA7E8FB17E90B7A699
                9CECBDBDE7C2C2E4C6C6CAABABB79191DAA5AACC8182AF5E716660884D547933
                4C3C4F4F4F8B6E6E9D8686B8BABAB5B5B5C9C9C9ACACACCFCFCFBCBCBCC0C0C0
                BCBCBCC6C6C6D9D9D9BFBFBFBDBDBDA3A3A28C8C8C7C7E88787A8B7878A27C7E
                A6958C9FB098A5D1AAACC2A1A1DFB6B6E6BFBFE0BDBDB59C9B6B779854618936
                39384F4F4F8D6868AF8888D4C6C6CDCACAD5D5D5D3D3D3D5D5D5CECECEE2E2E2
                DEDEDECCCCCCD2D2D2ACACACBBBBBBC7C7C7CECECECFCFCFBCBCBCA2A2A28B8B
                8C7C7C8472729272729E7E81988E82A3A6909DC9A2A3A18F8D737FAA5C718C3C
                413C4F4F4F8D6868BA7272DC7777E18B8BE6C8C8E5C5C5EBDEDEE5E2E2D6D6D6
                E6E6E6C0C0C0CFCFCFCACACAC9C9C9CCCCCCCFCFCFBFBFBFC0C0C0C3C3C3D0D0
                D0CCCCCCB6B6B6A3A3A38B8B8B7979876F708E72768E6D6D9C6B73BA5F927D38
                5E384F4F4F8E6969BB7272D76B6BDE7F75DDBFB1F49993FEBBAAFDF8B8FAECC7
                EFE3D4EEEEDFD9D9D4D7D7D6D0D0D0CBCBCBF4F4F4C1C1C1DFDFDFC2C2C2B9B9
                B9B3B3B3BCBCBCC5C5C5CECECECDCDCDBCBCBCA0A09F87878871707C659E6B36
                5B364F4F4F8D6868BA7071D76A6BE28F82E3D8BDFEB0A5FEE6A3FEFEA3FEFEA3
                FEFCA3FEFEA9FCFCB4F0F0C6DBDBDAE9E9E3ECECE7CECECFCBCBCBBFBFBFB7B7
                B7EDEDEDCCCCCCBCBCBCC3C3C3ABABABBDBDBDD7D7D7D5D5D5CCCCCC8E9B8E41
                563C4F4F4F8F6D6ACDB388EBB585F0D5AAD6D3BBD2BFD6E6E6BCF6F6A5FCFCA2
                FEFEA2FFFFA2FEFEA8D6D6B8A4A4A1EAEAAAFCFCB5F8F8C4F2F2D3ECEADCE4DF
                E1EAEAEAD2D2D2C9C9C9D0D0D0D2D2D2F3F3F3D6D6D6D8D8D8D7D7D7A6A6A555
                4D404F4F4F8E6A69D2C48EFEFEA1F2F2C0D4C6AFA99DD6A3A4DC9292C5C3C3B5
                F3F3AEFEFEA9FEFEA3FEFEB2F9F9C2F6F6C0FEFEA1FEFEA1FEFEA1FEFBA9FCC3
                B4F6BBBDF0D1D1EBDDDDE2DDDDDDDDDDE8E8E8D7D7D7D9D9D9D7D7D7AAA19F5E
                4B434F4F4F91756CD3CB91D4D497C1BDA9C4978BBB888EA987998585AA8E8EB5
                A6A6CBCBCBA5D4D495D5D595D4D495D4D495D4D495D5D595D5D595D5D295D4A5
                95D49595D49595D4999BD3A5A2CFC2ABCBCBB5C3C3BABDBCBABABABAB6A89F39
                55354F4F4F9A997B9A9A7C97987E8B8D85968276947B768C77787B7A8583808B
                8A889299997E9A9A7C9B9B7C9B9B7C9B9B7C9B9B7C9B9B7C9B9B7C9B997C9B87
                7C9B847C9B837C9B877C9B877C9A9A7C9A9A7C9A9A7E9A9483998C8791897E61
                7357}
              ShowHint = True
              OnClick = imgGameIconClick
            end
          end
          object Panel9: TPanel
            Left = 0
            Top = 266
            Width = 228
            Height = 112
            Align = alTop
            BevelOuter = bvNone
            ParentColor = True
            TabOrder = 1
            object Panel11: TPanel
              Left = 0
              Top = 0
              Width = 49
              Height = 112
              Align = alLeft
              BevelOuter = bvNone
              ParentColor = True
              TabOrder = 0
              object Label15: TLabel
                Left = 6
                Top = 2
                Width = 35
                Height = 13
                Caption = 'Notes:'
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentFont = False
              end
            end
            object mmoGameNotes: TMemo
              Left = 49
              Top = 0
              Width = 179
              Height = 112
              Align = alClient
              Lines.Strings = (
                'Enter game information here...')
              TabOrder = 1
              WantTabs = True
              OnChange = mmoGameNotesChange
            end
          end
          object pnlGamePic: TPanel
            Left = 0
            Top = 41
            Width = 228
            Height = 225
            Align = alTop
            BevelOuter = bvNone
            ParentColor = True
            TabOrder = 2
            object shpGamePic: TShape
              Left = 37
              Top = 7
              Width = 322
              Height = 202
            end
            object imgGamePic: TImage
              Left = 38
              Top = 8
              Width = 320
              Height = 200
              Cursor = crHandPoint
              Hint = 'Click to select a game screen shot.'
              ParentShowHint = False
              Picture.Data = {
                07544269746D6170D8EE0000424DD8EE00000000000000000000280000003F01
                0000C80000000100080001000000A2EA0000130B0000130B0000000100000001
                000000000000000080000080000000808000800000008000800080800000C0C0
                C000C0DCC000F0CAA600000000000C131B001B1B1B00251B1A001A2717002629
                1C0035241600353E18000D132100191D24001C1C3500231E23002C1F32001C23
                26001B2634001E3035002727280033292900283328003635290027283200322B
                33002A3334003736360045241C0049383500603F3A0039481B00364C3600346B
                340042432F0058452E004646380055463A0047563C0055573D0064453D004B63
                2C004A673C0052623F0044793A002B344800393C46002B375600383C56004F3C
                4600513C64003B444700385348003A4556003E476A003D5461003B6068004747
                480057484700485747005756490045495500564A540049555700575757006648
                4800724E48006955490075574C00654B53006559580077595800486448005565
                4A004C784C0055764F004B665700576757005775570065664C00676656007564
                5A0065765A007777590041496700504162004A57670055596600414E73004858
                7400565B75006D5B66004862660059646800597765004C627A005A6576005C75
                770065666600786867006778670077756700666A7600776A7600697578007878
                780093533C0097594500A35D480098645400AF69550084586C008B747200B476
                6900C0745D00C47A6A003A883A00538C52006B8F540053AC53005A846900718C
                720075A976005DCD5D006CCD6C006FE36F0085855B008F8C7500B38578008FA8
                7600ABAC7600CC877900E18E7C00CAB37A0088C37A00D3D37800595B8D00586C
                88006F758A005278A3007677A8007475CB008D788800AF778B00BA5EBA008A7A
                AA00AD74AD00CA788E00D274A900E07FAD00957DCC00A87CD200D35ED300CC74
                CD005A848C005E8592006D848700798487006C998700759588006A829A007886
                97006F9396007B97970077A78F005385B800758DAD0078AAAE0078CC8B007DE1
                8B005791D0007295CA005FA6DF0077A7D6007F98E60068AAE00090909000AC93
                910091AE9200B0AB94008E94AF00AE95AE0096A8B000AFAFAF00CD928F00E493
                9300CAA89A00E5A69C00CF94B000E48FB500CEB1AF00EBAEAE0096CC9600ACC9
                970096E99600A0E69E0099CAAB00AFCEB0009CE8A700B3EFB400D0CF9200E6D9
                9900D1E29C00EFEF9700CFCCB300EDC9B900CDEAB800F0F0B3009094CC00B095
                CD0092AECF00ACB5CD009797E600A994E40094B0E900AEB2ED00CC93CD00E898
                CB00CDB0CC00F0B2CC00D497E600E694E800CEB3E900EFAEF00097C7CE00B4C8
                D200B7EDCB0098C7E800B0CAE80098E7F400B6EDF200CECECE00F2D0CD00CEF0
                CE00F0ECD000CCD1EC00EFD4EB00D4EFF200F2F3F40000000000F0FBFF00A4A0
                A000808080000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFF
                FF000120FE0040000000016801450419000F1817181717181817130C0C0C130E
                1300070C0013150C150C15170D1715150E15150C150D0F1A1C0007210A1D0128
                111D00051C1C0F1C1C00041D000B0F1D1B1B1B1A1B1B1B1A1F00061A091B0003
                1A1A1E00041A010F011C051A011B011A041B0005161B1B1B1A00081B00031A1B
                1A000D1B00131D1B1D1D212121201C1F201D1F20201E1C1A1E00081A00141F20
                1D1F201C21201C211C1C1C1D1C1C1C1B1C1B041C004D1A1A1A171A1A21201F1A
                1A1A0F151A151A151A1A1E1A1E1A1E1A171A1A171E1A1E1A171A1E1A1E1E1E1A
                1E1E1A1F1A1E1C1B1A181A1C1F1C1E1B1E1E151A181A1F1C1A151E171E182017
                1C1C1C00050F00031A1A1E00091600081A15151A201D0F1A000000184CA2A03E
                3D3B3B3B3339353D353B331F1D1F2145453A3939102100153421213421342121
                393F464C68686C464C46565556000655000E5955555955595555555955565557
                04550018314242552D42422D552D4947404B4B37463F4B3F3F4342440440000C
                47444B403F435C465D454443043F000E4345373F404043424044444042470440
                001D4740474B403F404740474047474947474B4A4B4D4C575658686863686300
                0446014C0646000F4544413F3F3F424646524F464E4F52000453000546424546
                4600064E00184F4F4E4F414668684C46464544413F392A343F342A343F390443
                000E3B43393B3F36434336433B433B5A06430036444043434442444642444542
                34393643464336393B3B363B4539423131302C262C3A262C3943445B3838383F
                3F413F3F3F435228280F0000003E68A2A9AC655F5F3D5F8F6565655C433F3F3F
                45A8A9A9A7A26E676245403F453F424342434244454441444542444644464644
                46464668F86BA3F86F6F6FF80485000487858587048501880485003C87858587
                85876B8484845984848459845969697557616D616D61616B686C767575695761
                69576166668E666C906E6D6C6C5D6C6C61636168616157680557000969756957
                754D574D6100064D0003757569000576001F8585B6B6A9B6A9B6A36F686EA36F
                F86FF86FA36F6F6F6E696E6B68686A6A7E00087F001D6F6F6F6B6A6A7E7F6A7F
                6A7E6A7F7E6A534C686C6BF8F86F6F6F6B6C56000846000C5D63636060635D5C
                5D5C5D5D0A6000366660635D6C6C6C6B6C686D68455D5F6C6D685C636C676667
                665D587C59514F4F4F4E51544F53686C6E686A586A68684653A3A3842D0F0000
                000963A2A7AC91656591A0000491001A604544464567CAD9CBE6BDE6BDCAAD5D
                4C466846684C634C634C0F6800276C686BF8B6F7BDF7F707B6B6B9B9C78BC78B
                C7CEB9C78BC7CEB9CEC7B9CEB96F6F85888885878800048400987676756D696D
                94769575909476947695757676756D8F909090B6B6B690909092906D6F7F6E6E
                6D69696869697675696969756D7676766969697375767576737677958695B7BE
                B7C0C7C4BDBDBCBCBCF7B6A9B6A9B6F7F7F7B6B6B6A3A3F8B6F86FF89090F87F
                80B887B6A9B6F7F7A5B8B685808580A57F807F807F7F8068686A686A6A7FF8F8
                F8B6B6F86F6FF86D686868634C684C535D630A6600038E6C8E0005600034668F
                6C6C6C6E6D6E6F685D6660F8F8685C6FF8F8A36F6C906A7C7C7C515153517E7C
                80807F597F6A7C7FB86F6F686FBCBCA363200000001C4C6E90A79091ABABB1AB
                ABABAC8E5D464663A9ECE8ECF1ECEFECF1E6046800126D68686C696A6C69686E
                696E696E6B6F6D6E0A6F0022F8F7BD070707BDBDBDCBD2D2CFD0CFD5CFD5CFD5
                CFD5CFD5CEF8F8F8B68888888587058400746175689494769573909576767694
                769476766D6C906C8F9090A3908F9090A6696D7F7F6E766F696D69696976696D
                6D9494616975694C697573757376739586B7BEBEC1C5C5D3D2EFEDEDE7BDCABC
                F7BCBCB6F7BCB8CBF7B8F7B6A3A3F8A3F8F88E90F8F8B680C6F7C7CAC9BDC7C7
                C6B887B68584057F0019807F6A686A7F68686A5864536A6A6FF8F8B6B66FF86F
                69685D00074600436366668F8F6666605C605D605F5C5F5E5C5F8E8E8F666663
                5C5C5C5F606F445C6FF8F8B66E66A9597C7C7B30304E507D7D8082C6AF8C8C80
                59A5B6F8F8F7E7CAA963210000000013686CA2A3A9B1B0B0B5B0B0B0AC8E4C46
                6367CA0008F30010E66868696E6F6B6C6B6E6D6B6E6F6FF8066F0006F86FF8F8
                F8B604F801B604F8000BB6F7EDEDF4F2EDF607D2F00009D501D205B600E58588
                8584848459555555686994767595756D766D6D7575608E73754D616D68666366
                6063608F8E6E4C567E7C677569635D6D757673696D9494947561464B45484D4A
                4D757376779589BEC5C5C5D3EED5F4F3EFE707BCBCBCB6BCB6F7F7BDCAC6C6B8
                80B66FF86F6F6E8E90F8B6F8B6B6B8CBC9CDCDCDCCC9C6B887807F847F6A7F7C
                7E536853467E7F6853545152413F3F4546686DF8F8F86F6F6B5D4C453F3F3F44
                3F4646465D5F5D5F5C5A3B3B363636433C3C5E5E3C3C3C5A5A5A3C5A39433B43
                6FF8B6B64C8FB6597C7C2F262727277A7A7D8183AFAFC8C8C8C7BDB6B6BDE7BC
                A5632000000000324C6E90BCADB1B0B0B5B0B0B0A68E4C634C7FD1CEECF3F6F3
                F3F6F3E6676E6E696F6E696E6B6F6D6F6F6FF86F6F6FF86FF86F04F801B608F8
                0010B6F8F8F8B6B6F707F207F3F4F6F4F0F005D501B904B6007D6F6F6B845955
                2D2D231D232940402E40474475696E694D4737373740374B47443F5D3F2A372A
                39373F404254515D4A3F2A2A2E40474840404446374037231D23242429232424
                47487399BEC1C5C5E1D3D3D5D5E7E7BC6F68685668616FF7F7B8B8B8807F7F7E
                553F403F374C6E6FF8B6B6F7BDBDCBC9C9C6BDBD7F584F00044100182A2C2C23
                464C3F45566841534E2C281D1B1B1B1D211D213F0568000B4440372A21232123
                232121000434000C331F1A161E1E1A1F1F1F3336053500101A15151B1E1D2340
                4034636830322F0F050E0013277A7D7D8183AFCDF3F3BCF8B6B8F7B66F531E00
                00000017636CA3E6ACB0B0B0B5B0B0AB908F4C5368A58D8D88BDEC0005F3000A
                ECE6ADA4A56F6E6F6D6E046F04F800086FF86FF86FF8F8B607F80017B6F8F8B6
                F8B6F8B6B6F8B6B6F7EDF2F4F6F6F6F4F0F0F00004B6004DF86F6868424ABDED
                F2EFF2EFF2EFF2F3F2F0F74D4B7607F2EFF2F3F0F2F0F2F0F3F2B7EDF2F3F2F2
                F3F437404DBDEDF2F0F1F2F3F2F0F1F0F2EDB7F4EDF2EFF2F36976F2F3F2F0F3
                F4B786BEBF0004C50096D3C509D2BDB8F4F2EFF2F3F0BDB6F7B880807F85C4ED
                F3F2EFF2EFF2F4D2B76EF8B6B6F7F7F707B807B8F4F2F0F4F0F2F0F3F2F3F2EF
                F7372A3F457607EDF2F3F0F1F0F3F2EFF2F4761F21F7D2F2EFF2EFF2F0F3F0F2
                EFF42B1F46BDEDF2F3F2EFF2F0F2EFF2EFC0141E7607F2EFF2F3F0F1F0F2F3F0
                F476532D3F29EDF0F1F0F2F3D2257A7A7D81818383CDEDB8B6E7E7BCA3683F1A
                00000018686CA3BCACB0B0B3B2B0B0B18E6C464C67C6D1888D88F7E705F30008
                F6F3ECECE6ADAAA2056F0006F8F86FF8F86F06F801B604F80019B6F8F8B6F8B6
                F8B6F8B6F8B6F8B6B6F8B6B6BD07F2F6F6F6F00004B6000CF86B684676EDBE86
                7273748605C0000BEDF747B907BE86797989BE0005C4002DF0B7EDC58989898A
                F4234DEDC4BE79777989C0C4C0C4C0D2EEB6ED72727171EE69ED8672737286EE
                767795BEC10005C50029CEB9B985F478777479C4C47FF87F7F7FB7ED86777272
                7489BE7986BEF4C4F8B6F7BDBD07BDBCBA6BF60007C40020C08977BEEEF01F21
                B7D2867772727377C0B7C0C4C0F4761C07C4BE798989BEC104C4000CD3F44040
                EDC08674737786C004C40030EEC413B6ED8679747877BEC0C4C0C0C0F476412A
                2829EE77707070C0ED11277A7D7D818183AFEC8C8283C6CBCAA363200000001A
                4C6CA9BCACB0B0B3B2B0B0AC8E68684C67C7D1888D88A3A3B6E705F301F604F3
                000DECE6ADAAA3A3A3F8F8F86FF86F0004F801B601B605F80009B6F8F8B6F8B6
                F8B6F80004B601F807B60003BDED070004B60025F86C4C45C4BE73727274EDC4
                EDEEEDEEEDF0B648F286747779BEEDEDF0F2F0F2F0F294D3D300048900B6F41B
                C4C489797979EDEDEEEEEDEEEDEE0794ED72727170EDC4D272737273EDB77376
                89BEC1C5C5E1C5C5CEB9B67FF477787778C5C464587E587EF08672727286EDD2
                EDF4D37486F685F8F7F7070707B6A36FEEF0F2F0F2F0EEEDEEF0F47774F4B62B
                F37474727486ED07EDEDEEEDEEED6B95EE79897989C4EDEEF2F0F2F0F2ED4CED
                C079747477ED07EEEDF0EEF2F0F724F47974747886EDD2EEEDEEEDEEEDF84126
                2122EE86707070C0ED1026277B7D8181AFF3EC80048100047D7E4E1C00000016
                636FBCA9B1B0B0B5B2B0B0928E68565DA2D1D1888DA204A60008A9E7F3F6F3F3
                F3F604F30009E7E7E6E6CAA9A9B6A30006F80012B6F8F8B6F8B6F8F8B6F8B6F8
                B6B6F8B6B6F80CB60099D8DCBABCB66F684C3FF473727272C0BD1D28282A2D2B
                2A2A85ED74777779EDB737374B4D60484336EED28989898AF615EEC0798979BE
                ED233740404B47373F85ED72727171EEF37772737286ED4A757795BEC1C5C5C5
                C1C4B988A36CF478777478C4C44E54545485F278727272ED76201D4CF67478EE
                B6F8F7B60707BDB6F86F4C686D68684C684C4C63F08974C0C076EE73747274ED
                B7424600054C001A21EEC4797989BEF4231C21343F2A392C49F479777773C007
                4C49054C002F2ABEEE79747874F2851212141E3336343A2C261D22EE77707070
                C0D3101D2A556A7F82E8F3ED878181817D7D32270E0000000037686FBCB6ACB0
                B1B2B0B2AC8F604C6C6880D1D188A3A6A6ACA6A6A6B1EAF3F3F3F6F3F3F6F3F3
                D9F7BDBDE7E7E7E6BCAAA9A3A3F8F8B6B60004F8000EB6F8B6F8B6F8B6F8B6B6
                F8B6B6F80AB60013D8D8BCDCBAA9A66344F671737272C0F71B1D2800042A007A
                2885EE77777779EEB624444D61604C4443EEC589898A89F41BEEC0897979BEED
                233737474B40373794ED72727271C4B972737473D2B74B757786BEBFC5C5C1C5
                BEB9B6A268F477747877C5BD4F4E5352B7EE78727272EE691A2021F47474EEB7
                6FF7F7BD07F7F7F86EB6EDD3EDD3EDD307D2D3C47772C4B776EE04740014C007
                C4C4C407D2C4F469F0D3797979BEF62B21210441003F2C49F479797773BE07D2
                E0D2D2E0D2EDC4C5F079747477F4760B13181833333539261C2323EE86707070
                C0ED0D0D212D568485CBF30787828181817D32260E000000002A636FBCA7B1B0
                B3B0B0ABB1925D686866C6D1CE928E92A6A7A6A6A6B1B3ECF3F6F3F3F6F3F6F3
                ECF7B6F704BD0016E7E7E7E6CAADA9B6A9F8F8F8B6F8B6F8B6F8B6F8B6F80EB6
                0092BCE9E6D8E6BAB1908F62F473727273C0F71A1B21212A2A2A28B6EE777477
                79EDB72D58596B6E6C464BEDD3898A89BEF415F2BE897989BEED2337374B4437
                403785ED72727271EEB971727286EE4048739586BEBFC1C5C1BEC0B9B66E63F4
                78747778C5BD4F4E5354B7F078727172ED691B2021F47478EEB6B6B6BDBD07F7
                B6B66DF0BE79897989C4EEEDEDEDD3EDED2386EE04740057C4D207EDD2EDD3ED
                F469EEC4797979C1F4403F3F4F545354504AF689797773BEEDD2EEEDEEEDD3F2
                C4C4F079747474F476000C0C182033352626280F22EE77707070C0EE0D0C1F24
                59566BF8F78587858780807B50270E000000002D68A3B6A9B1ACB1ADE9ECE78E
                684C686ED0D1CECE07BC97929292A6B1B5B3F3F3F3F6F3F3F3F6E8EDB6F7B6C7
                B90005BD000FE7F3ECE7CAADB6A9F8F8B6F8B6B6F80004B601F80CB60092CBEC
                ECE9E6D8ADA78F63EEB7727272C0071C1F212A34232A2185EE77777779EEB756
                6B6B85856F6B5DEED38989898AF41BEEC4798979BEF0374440446140443F94ED
                72727271EEF4D37374EDBD484D758699BEBEBFC1C2BEBEB9B66F68F474777478
                C5BD4F5354536BF679727271EEB61F2A44F47474F2B6F8F7BDBD07F7F7A3F8F4
                BE798979C5F0768686867676232176F404740005EDB7575757000469001928F0
                D3797979C1F44C40456A806A7F6A42F4C1797773C4ED57000469003176764BB7
                F479747474F4860B0C0C1A1A1A214141221B22EE86707070C0ED0D141F445669
                6FB6B86F85878887877E51261C00000000444CA3B6A9BAE6ECF3F3F3BC8E684C
                6C7FD1D1CED1E7DDF1EDBADADAB1B3B1B3F3F3F6F3F3F6F3F1F0BDB607F4CFB6
                EDF7F7E7F3F3F6F3F6F3ECE6CABCA9B6B6A3B694B6F80EB60038ECECECEFECE7
                E6ACA28FC4ED73727273F2EDED07ED07EDEDB6B7EE77747779EDB76B8485B687
                858559EEC48A898A89F623B7F489897977F204ED00B1D2EDEDBDB6ED72727271
                ED85F4F07486F4B773958699BEBFC1C1BFC0C007EDEDEDF478747778C4F0EDED
                EDC454F0D371717286F4D207EDC074BEEDF8B6F7BD0707BDF7F7F8F0EE897989
                89F4EEEDD2EDEDD2ED942AF4C1747474BEF6070707ED07ED0757F2C4797979C0
                F4576863B6B8B8F76F53EEF479777377F4EDEDD2EDEDD2ED8549F4D3747474C0
                F6EDD2EDD2EDEDD257C4D207D2F477707070C0F407EDD2F72B696FB6B687AAB8
                87AA857F532A1C000000000568A3A9D9E70005F30038AC60686868AAD1D1CFD1
                EDEAED07BDDADADAB1B3B3E7F3F3F3F6F3F3F6F3EDB6F0F2CEF7EDBD07F3F6F3
                F6F6F3F3BD07E7E7E7E6CABCB8A910B6002BEAECF6F3ECEBB8BCADA26CEEEE77
                73727286C0C0C0C4C0EDF7B7ED77777789EEB76B858588B787856BEED3000489
                000AF44240F2F0C0797477BE05C00014D2EEB7ED71727172EEF846EEF48689F4
                B9B9C0C004C1002EC2C0C0F2D2C4C4C077747878BEC4C1C4EEED7F85F6D37772
                7277B7BE7777C0EDF7B6F7F70707BDBDBDF7B6F7F4EE04890065BEC4C4C4C0C0
                EDC03FB7F4D27774727386C0B9C0C0C0F476EED3777979BFF46B6B68BD0707BD
                B6F8B6F4F28973747786C4C4C0C4C4EEC41CC4F6D386747877BEC0C0C4C0C0F4
                76EEEDC0B7C07370707077B9BEC0C4ED246FF8788780B887AA87A56A542C0F00
                000000054CA3BCE7E80004F3003DEC926369636CC6D1CFD1D1D5D2F007BBBBDA
                DADAB1B3D9EFF6F3F3F3F6F3EDEDD2F0F08D07F407E7F3F6F3F3F6F3E7BDBCBD
                BDBD07E7E7EAE7CABCB8A9000BB600EEF7BBD707ECEAB8B8AA8CA3F86BEDF0F2
                F3F2EFF2F0F1F0F2F0F7F7F2F0F1F0F2F3B76F6FB6B6B9B88585EEF1F0F3F2F0
                F3565556EDF2F0F3F2EFF2F3F2F2F3F2EDB7F3F0F2F0F3F2B66F6FD2F4EDF2F4
                EDEDD3C5C5C5C1BFBEBEEDF0F2F0F1F0F2F3F2F0F2EFF2F0ED7F7FB6EEF4F0F1
                F0F2F3F0EDC4B6B6F7BDED07ED0707BDF7B6F8B9F2F4F0F1F0F2F0F2F0F1F0F2
                B96868B7F0F4F2EFF2F3EEF3F2EFF2F385EEF0F2F3F2EFF476B6B6CBEDED07BD
                B8F876F0F4F2EFF2F3EEF3F2F0F1F0C42726B9EEF4F2EFF2F0F3F2EFF2F0F286
                EEF3EEF3F2EFF2F0F1F0F2EFF2F0ED2E6F85788887AA8CAAB8807F4F310F0000
                000568F8BC07F10004F30040E68E68686867D0D1CED1D5D1D5EDEBDADCD5DADD
                DAB1BCF1EAF6F3F6F3E8E7B6C7C4D2D4F2EFED07F3F3F6F3F3F6E7D6BAD7BCBC
                BCBDBDBD07E7E7EAE7CABCBC08B60088BBBBDEBBE0BBBBB8C6AEB6B6A3B6A26C
                576969696D766D696969666969766976866F6FB6B6B6F7B6F885858685777685
                776A596B6B596B767376767376737373756973754A76767685B6B6F7B786B7C0
                BEF1D3C5D3E109C5C1C099B7B7B68576846B84858585868587B6B66FF86FF8F8
                F86FF8F8F8B6F7F7BD07EDEDED070707BDF7B6ADF8A37686067600607369F8F8
                F86D6869764D574A5757594D4A4968767676738586B6F7BDBD07EDEDEDBDBD68
                46456869484948574D4A6976734C53412C4E4249482E2E4A48484A57766B4D4A
                482E2E2424292423242424485568F8857886878CAA87B8B67F582C0F00000005
                68A3BCE7E80004F30037AD906168687FD1D1CED1D1D1D5BDDCDCD5D5D1DBDCDA
                BDF1D8ECF3F3F6B6F7F794B6B6F7BDD9BDF1F3F6F30707D9D6D6BBBBDEDEBBBC
                BC0004BD00090707E7F3ECE8E6BCBC0004B60030BBC2D7BBDEBBD7C7CACAF7B6
                F787A9A9A8908FA690A7A7A6A66E6E6C6E6E9090A3A3F8B6B6F7BBB6B6B66FF8
                6D6B6F840485002B848585858485848585857694767576766FF7BDF7BDF7BDBD
                C4C0C0C4C5D3C5D3E1D3E1C5C5C5C0BEF7A98000047F000C8080B88CB8C6B8F7
                B6B6B6F704B60017F7F8B6F7B6BD07EDEFED07ED07BDBDF7B6B6B6A3F8F8B600
                04F80060B6F8F7B8B6F8F8F8B6B66F6FF86FF86868467F7F7E6B6E6FB6B6BDBD
                07BD07EDEDEDB66F68F8B66E4244686F454068F86E636C53537D517B41465341
                3F3F3F413F3F686FF8F86F686F6F4C634C4646566B6FF88679798C80B887F7F7
                B76A310F000000054CA3BC07E80004EC007EA6606C686DAAD5D1CFD1D1D5EDF2
                E6D9CED1D5D1DDDA07F4DCD8E7F3F2E1EDE0E0F70794F7BAECF3F6F3F3BDBDBC
                D6D6C7BDBCBDBBBEB7B7BC07E7EFF3F3F6F3F6F3F3ECE8E6B8BABBDEBBDEC2D7
                C2BDCBBDBDF707E7E6E6CABCBCA9BC07BAACACACA9A7A7A7A3A7BABAB6B6F7F7
                C0BBF7B6B6F8F8F86FB6F8F8B687B78705850023B787B68887B787B76FF7ED07
                EDEDED07EDEDE0C1C4C5C5D3E1D3D3E1D3C5C5C5C4C0B8000480000E87AA8CB8
                C6C6C9CBCBBDB6BDBD0705BD0008F7F7F707EDF3F2ED05070006BDBDF7BDB6F7
                05B60061F7B6B607BDBDF7B6B6BDF7B6B6F7B6B6B66FF8F7F7B8B8B6F7F7B6F7
                BDBDEDEDBD0707B6F8F7BDBD6F68686E906A686FB6B6A7F87F8080805468646A
                684654535346464C4644466FF8F7F7B6B6B6F8B6B6F8B6B6797989888C8886F7
                B676582D0F000000000563F8BCE6E70004EC00768E6869686EC6D1CFD1D1D5D1
                BDD7BDD8B9B7CFD5CFDABADDB1D8B1B8F7DFE5DFE1E1F2E0EDF7EDF3F6F3F3BC
                D8BCB4BAB9C7B9C7C707BDC0D8F3F3F6F3F6F3F6F3F6F3F6F6E7B8F7BDBDBBE0
                BBDEBBDEBBBD07BDEDE8EAEBE7D9E6C0BDBCBAB3BCB3D8ADBABAB6BCBABCBCBC
                F7BDF7C0BBB6F7B6B6F806B60009F7B6F7B888B9B9B8880006B90008B607EDF0
                F2EFF2D305C50009D3E1D3E1D3EEE1D3D30004C50024C0B6B9C7C6C6B8B8B8C6
                C6C9CBCBEDBD070707EDBD07ED0707BDBDEDF0F2EDEDED07BDBD0407000EBDBD
                F7BDB8B8B8F7F7B8F7F707CA06BD0037F7BDB6BDBCF8B6BDF7BDCBBCB8C6BDBD
                BDCBBDCB07BDBDB6BDED07BDF86FF8BDA76F6FF8B6F7F7B6A5B8B8B6F8808C6E
                6B7F807E686D6A000468001A464C63686DF707BDBDF207BDF7B989798A797988
                F79C92532D0F0000002768A3BCCAE7E7E6BDA98E686C68A2CED1CED1D1D1D0DA
                D7D9BDD9CBB9CED1D990DBD8D8B1C78CC40004DF0044E1E1E5F2F3F6F3F6F3D6
                D9D6D6D6BCBCBCF7B9CECEC7E7F3F6F6F3F6F6F3F6F3F6F3F0CABCF7BBCBBDBD
                DEBBDED7C2BD0707EDBB07E7EAD2C4C5BEC707D9D8D8D8DCD8D804BC0012D9D9
                BCF7F7BDC0BDF7B6B6F7F7B6B6F7B6F704B6000CF7B6B9B9B9C7B9C7C0B9B9F7
                06F40024F0EED3D3E1D3E1D3EED3E1EED3EEE1D3E1D3D3E1C0C5D3C5C4F7B6F7
                F7C6C9C9CDED070706ED003507ED07EDF2F3EDF0ED07BD0707BD07BDBDBD0707
                CBC6C6C6C7C6C9C6C9C7C6BDBD0707EDBDBDF7BDE7E7B607BDBD07E7D9CBCB07
                CB0004070003BD07BD000407003ABDB6F8B6F7F7B6F8A3F7F7F7B6F7F7F7B6F7
                C6B8B6A3B8B680F86F6F6E6F6D6A6D6A6C6B686868F8B6BD07F7F7F7BDF707C0
                C0F7F7989768310F000000364C6FF8F8B66F6E6B6C8E686963A5D1D1D0D1D5D1
                D2BA9DDBD7DD0707D5D5F0F0F0EDBCBCC7B8B8A9BCD7DEDFE3E2BDE7F3F3F6EA
                D6BC05D6000FD8D8D8BCBCB6EAF6F6F3F6EFF108F00004D50031CAB8DEE0CABB
                E0BBD7C2BB0707BDEDE0DEBBDEBBDED9D3CBC9CD08EDD9E6D8D9D8E9D9D8BCD9
                BCD9D9F7F7F7C4B7F7F7B60008F7000EB6F7B6F7F7B6F7F7B9B9C7CEF70704F4
                0035EEF4F6F4F4EED3E1D3D3E1EED3EEE1D3EED3EED3E1D3D3E1D3E1D3C0BDF7
                BDCBC9CDC9EDF0BDF3EDF0F1F0F1F0F2F1F0F2EFF2EDED00060705BD0017CDC9
                CDCDC9C9CCC9CDCCCDBDBDCB07ED07BDBDBDEAEDF7000407000BE707BD07EDF7
                BD07EDEDED000507000EBDF7F8B6F7F7B6F7B6F7F7BDF7B604BD0008F7C6B6B6
                B8B8B88C096F00186E6D6A6F6F6D68696C6FB6F7BDF7F2F6F4F4EDC086582C0F
                0000001E686C6F6F90A6906E8F6661686DAAD5D1CFD1D1D1D9E6C7BDD9E00707
                D5D504F00027D8BC80C7C6BDB3B3B1BCD6BCC0D2B9C707D8D6CAB4BAD8D6BAD9
                BCCACCCAD8F3F3ED07C2BF07070004D5002FD4B8F7E0CBCBE0DEC2DEBDE00707
                BDF0EDE0E0BBE0DDD9C9CDEFEFEFE7CBEDE7E6E9EAE9DDE6D9D9D9BCD9BCF7F7
                C40018F7003EEDF6F4F4EEEEF6F6EEEEEED3EEE1EED3EEE1EED3EEE1EEE1EED3
                E1EEEED3EEE1EED3E1D3EED3D2CB07F107EDF2F3EDEFF2F0F3F0F3F1EDED0707
                EDED07ED06070004BDCAC9C904CD002AEFEFCDCDC9CBC9CBC907CBBD08EAEF07
                ED070707EA0707ED07BDBDEDEDF0EDBDEDEDF3EDBDB6B6B6BDBD04F708BD0029
                F7F7B6B6CBBDCAB6F8F8F86FF86FF86F6F6FF8F86F6E6F6B6E6B6C686B686FB6
                07F2F4F6F207B6461C00000000396368A3A7ADA76F6C8E6C68686EC6D1CFD1D5
                D1D1E7CAC9D6C409C207D5F0F0F4F0D4B3B8C7C7B8C7E6E6E6E9D8BCB9B9C0D3
                B9BAD6E6D8DCB30004D8000CBCCAC6BCC4D3C5C5BEC1D9ED04D50030D4BCB6CA
                C9BB07E3E2EDE0EDD20707EEEDF4EDE0DEE4D90707EDD9DCE7F3F3ECECE7E9EA
                E9E9EAD9BCD9D9BCD9F7F7C406F701BD05F70004BDF7F7BC07F70003EDEDF200
                06EE000FE1EEE1D3EED3E1EED3EEE1EED3EED30005EE0005E1EED3EEE10005EE
                0010C4F7EDED07F4EDEFF1EDF3F2F4EDF0ED05070005ED07ED07ED0004070033
                C7CBCAC9CCCDCDCDEFEFCDCDCDC9C9CDCABDBDF1E7EDEDED0707E7E70707ED07
                BD07EDEDF4BD07F2EFF208F7B6B6BDBD07F7F70004BD000DF7F7BDF7BDF7BDF7
                B6B6F7B8B80005F800066FF86FF86FF8056F00126E6D6E6D6B6C6B686A686C6F
                B6F7BDB66821000000114C6EA7A7A3A3A6908E686868A2D8E4D9ED0004D50020
                D1D1CFD5D209D2D5F0F4F0F4D2D8C6B8B887C7E8E7CAD9BCBDD9C4BDC7F7D6BC
                04D80010E9B3D8DCD8D8D8F7C5C5C5D3C5C1BDD204D50031CBB8D9EAE8CACABB
                E008E3E4070707F0F6F407BBDEBDDEE0DEE508CDCCF3F6F3F3F3EAE6E9EAEAE9
                E9D9D9D9BCBDBCBBC4000DF701BD07F70014BDF0F3F0EDEFF2EEEEEED3EED3EE
                E1EED3EEE1D305EE0004E1EEEEE105EE0023D3EEE1EEEEEEC4BDEDF007F1F0F2
                F3F2F0F3EDF207EDEDED0707ED0707BD0707ED07ED0004CB0011C9CDC9CDEFCD
                CDEFE8CDCDCDC9C9C9CBEC000607002AE7D90707EDED0707EDEDF1BDBDEFEDF2
                07BDF7B6BD07F7F7F7BD07BDBDF7B6B6B6BDF7BDF7B6F8B6BDB807F800036FF8
                F800046F000B6B6D6E6B6E6B6C6B6C696C000568000446443F1A00000019686E
                6FF8A3ACAD8E8E686868A5DADDB4DADDDADDDDE4F1EDF00004D504F0005DCABC
                B8B8C7CBCAE7E6EC07D9BDBCBBC4E0C4D8D8E6D8ADBCD8BCE6D4EFF007C0C4C5
                C5C4D3EDBDD5D5F0D5D5CAF7D9F2E5EDEAD8CBCABBED0707EDF4F4EDEDDEE0C2
                D7C2D7F2F208EDF3F4EFF3D3E7E0E7EAE9E9D9E7D8D9D9BCBDF7C00004F701BC
                05F70003BCF7BD0005F7001CBDF7BDCACDEFEFF4F4F4EDF4F6EDF2EEEED3E1EE
                E1D3EEEEEED3E1D305EE0003D3EEE10007EE0021C5BDE7F2EDEDF0F1F0F3F2F2
                EFED07BD070707EDEDED07ED07BD0707EDCBCBC9CB0005CD0005EFEFEFCDEF00
                04CD0033C9E8EACDCB07BD07BDECBD0707EDF00707EDF0EDBDBDEDEDF3F7BDB6
                BD07BDF7F7F7BDBD07BDF7B6B6A3B6BDBDF7F7F8B6F7F70009F800196F6F6FF8
                94F86F6D6E6B6D6A6D686E68696A686868463F210C00000000164C6C6FA7A7AC
                AC8F6C686868AAF0D4EDF1EFF1EAF1EA07DD002BF1F4F4F0BCD8D8ADB8B8CAE6
                08E7D9BDBCE0C407BDBDBDBCBDD8D8BDBCD807D5D5D5D2C1C4BFC5C5C5EDBD00
                04D5001BF0C6BC07E4E5E5ECECE8CDD2ED07BDF3F4F6F2EDDEBBD7E0D7C4E500
                04F20014E5F0D2D2E2E0C908EAD8D9D8D9E9BDD8BCD9F7C00BF701BD04F70014
                BCF7BDF7CBCDCDCDD4CDEFEFF4F4F0F6F0EDF1F005EE000EE1D3EEE1EEEED3EE
                E1EEEED3EEE104EE0015E1EEE4EAF1ED07F2F3F0F2EFEDEDED07ED07BD07BD00
                05070006ED070707CBCA04CB003FCDCDE8CDCDCDEFEFE8EFE8CDCDF3E8CDCCC9
                BDCB07EABD07BDEDF3BD07EDF307BDBDEDF0EDF7F7F7BDF707F7BDBDF7BDBDBD
                F7F7B6B6F7F8B6F7F7B6A3F7B60004F8001EB6F8F8F86FF8C2959598B7956F76
                94946B6C6A686B6C686C6868463F210C0000000F68686F9090928F8E6C68686C
                ADEBEB000EEC004AF1EADDF1E4EEBDBDBCD8D8D8E6D8BDD907BDBDBBC207BDCB
                D9BDBDC6C7D9D0D5D5F0C4C5C0C1C4C5C507D2D5F0D5D5D4B8F7EDF4EDEDBDD9
                E7D4D5D207BDF0EDF6F0E4DEBCD7BCBBD7E405E50004EDD4D0D204E8000BECE7
                E6EAD90707D9BCBCBD0007F70003BDF7BD0008F70006BDF7CDCDCDE806CD0016
                EFEFF4F4F0F6F0F2EDEEEEEEE1EEEEEEE1EED3EEEEE106EE0018D3EEE4DDE0EE
                F107EDF4EDF3EDED070707EDEDED070707BD07070004CBCBBDBD05CB000CC7CA
                CBC7CCCBCDCDCDEFECEF04CD0006C908E7BDCBCB04070010EDF0BDBD07EDF307
                BDBDF7BDBD07BDF704BD0030F7F7BD07F7B6A3F8B6F7F7F8B6F8F894F8B66F94
                8695F8F89FE2E39F9898B79898956F76946B6C6968686F68463F210C0000001D
                4C6E6F6F6D6C6C6C6868686ECAEFCBEFEFEFF0EFF0EFF0EFD5EFF0EFF30005EC
                0019F1E3DFEDEDBDBDBCD8D8D8BABBBDC4C4BDCABDBDBDCACBCBD80004D50009
                C4C5C1C1C4BFC407ED0004D50035CBBC07EDEDF3F2EDEADD0707BD0707F4EDF4
                F1E4D8DDDCD9DDD9D9E4E4E5F2E5F2E0EED5ECF3F3ECF3ECE7070707E7D9D9BC
                F7C0BD0005F7000DBDF7F7BCF7F7F7BDF7F7BDF7BD0009CD01E804CD000AEFEF
                EFF4EFEDF0F6F4F005EE001BE1EED3EEEEEEE1EEEEEE07D907D3EEF2EDEDEFF2
                EDED07ED0707BD000407005DED070707BD0707BD07CBBD07BDBDBDCBCBCDCBC9
                CBCAC7CACAC7CBE8E708CDCDCDE8CDE8E7C9CDC9CBC9BD07EDEDBDBDEDEDF007
                BDF7BDBD0707BDBDF7BD07F7F7BDBDF7BDF7B6B6F8B6B6B6F8F8B6BFBE95F8B6
                89BFBEF8949FE2E39F0005E2000E95B7F7B76D6BF86D6868463F211500000007
                63F8B6F7F86F5D000468003CA2A4AAB8C7D0D1D1D1CFD1CFCF09CFCFC1F0F0F4
                F4F3ECECF1E3DEEAB6D9BDD2BDCBD9D8D8BABCBCF7BDE7BDC7B8CBD9D5D5D5ED
                C5D3C1C5C5BF07BD05D50035CAF707EDF2EDEFF2EDF1F0ED0707EDEDBD07F3DD
                D9D9D9DDDDDDE4F2E5F2E5F2F2E0F2EDEDECECECF3ECEDED07EFD9D9D8D9BCBD
                B90004F70010BDF7F7BDF7F7F7BCF7F7BDF7F7BDCDE810CD0006EFD4F3F4F6F4
                04ED0AEE0003E1EEE00004EE000BF0BDF2ED0707EDED07EDED000507000ABD07
                ED07ED0707BDBD0704BD002ECBBDCBCBCBCAC7CBC9C7CCCBECCBCAC7CAC7C9CD
                E8E8EFCDCDC9C9C9BDCB07070708EDF307F7F7BDBD0707F7F7F706BD0019F7BD
                BDF7B6B6F8F8B6F8B6BEBEBE8ABEBFBFBE8694BE989F9F0004E50010E3E5E0F8
                6E6FF8B6B7B76968463F211A0000001668F8BD07F1F0EDF7F86B6868686EA5A5
                AAAAAAB6868904790081998A79BFC109F0F0F4F008CCE7CAEAA9BCBCBD07C408
                BDD8D8D8BCBCBCC7C7D9CBD5D5D5EDC1C4C5D3C5BF07BDD5D5F0D5F0CAB6E0E0
                EDF2EDF1F0EDF1ED07BDF0EDF0EDF0ECEADDBCBDD9E2E5E5F2E5F2F2E5E0E5E1
                E0E0D7EDE0E8CB0707EDE7D8D9E9D9BDBBF7F7F7BDF7F7F7BDF7F7F7BDF7F7BD
                F7BCC0C5D2EDD4CDCDCDEF0007CD0003E8CDE80004CD000AEFEFEFF3F0EDEDF4
                F4F008EE01E104EE0004F2F3EDED07070008ED07EDED070707BD0407003ABD07
                BDBDBDCBBDBDBDCBCABDC7BDC9CACBCB08E7CACAC9CBC6CACAF1CBC9C9CDCDCD
                CCC9C9C9CBCDCDEDF0EDBDBDCBBDEDBDF7F7BDBD07F7F7BD07F70027B6B6F8B6
                B6868A99BEBFBF8694F8F898DE98DEE5E2E3E2E3E5B794946F6FB6F7F7B69476
                68371A00000000474C6FB6BDEDF4F6F6F4F407B6B66DF8686F6EA5A5A4AAB8B6
                86998A798A9989998A8AC0EED4D4D4EFE8BDBCE6BCCBBCBCBBED07D2CBD9D8D8
                BCD8D4D5D5F0EDC407C407D3C5BD070004D5001AD4B8F7E7E007E4E1EDEDF2ED
                070707F0EDD5D5D0F2F1DCD7D9E304E50021F2E5E5F2E2E0E5E0DEBDCBE5CB07
                070708E7E9E9E9D9BCC4F7F7F7BDF7BDBDF7BD0004F70012BDF7F7F7C1C5C5C1
                C3C5C5EDEDEFEFEFE8EF0DCD000AEFD4EFF4F6F6EDF1EDF206EE0008F4EEEEEE
                ED07070704ED06070003BDEDED0005070EBD0016CBCBCBCAF1E7C6C7CAC7CAC7
                CBE7CAC6CBC7CACAC7CC04CD002BCCC907CBCDCDC9C8CBB8C6F7BDBDC7F7F7BD
                B6B6B6F8B6B6B6F7F7F7B6F8B7BE95B789B7F8F87694B698DE0005E30010E5BD
                BBB69407BDED07BDF7B6F8683F1A00000066636FF8B6B6F707EDF4F4ED0707BD
                07F7B6F86F6B6E6FA5A5AAAAA9B7B7898A898A998ABF99BEC1D2F0F0F0EF08EC
                CABCBCBCD8D7F1F2D2C407BCD5D5D5F0F0D4EDF0ED07EDBDEDD5D5F0D5CBBCD9
                DDDBDDEDE007E0E0E0070707F0D5F0EDD2EDF2EAD9DBE4E304E5001DF2E5F2E3
                E0E5E0BBE0D7F1E00707D2E1E4E7E9EAE9D9BBF7F7BDC4BDBD0004F70019BDF7
                BDF7BDF7F7C5C5C1C5C1C1C1C5C1C5C5E1EDF3F3F3EFEF0004CD01E801E806CD
                04EF000AF0F4F0F6EDF4EDEEEEF205EE0008EDED07ED0707ED0704ED04070007
                EDEDED07BDBD07000BBD0018CBBDF7CBEACBBDCAC7CACBCB08E6C7CBC6CAC7C6
                C9C7CACB05CD01E805CD0003C8C9C90005C60007B8C7F7B6B6B6F80004B60019
                F8B6BBB7B794F8F894B69486B7F79AE0E0BBB798B7BBF7F7B60005070006EDF7
                B66D3F150000003B4C6FF8B6B6F7B6F7B66FF8BDEDF2EFF2BDEDEDBDB66FF86F
                6FF8A5A9AAB8A9B7B78999BF8A99BF898ABFC4D3F0F0F40808BDBCE8E0E3DFE5
                F1F1F00006D50005F0D5F0F0F00005D50050CAF7E7F1DDDADDDDDD07E7070707
                EDD5D5ED07EDED07E0E4E4E2E2E2E5E5F2E5F2E5E4E0E5E0C2E0D9EABD0707ED
                E2E0F1E7E9E9D9C0F7F7BDBDC4BDF7F7BDF7F7F7BDF7BCF7BDC5C5C0C0C1C5C5
                C1C504C10020C5C5E1EDF3EDF3EFF3EFEFE8E8EFE8E8EFE8CDE8CDE8EFEFF4EF
                F4F0F1F0EDF208EE0003EDEDED0007070005EDED07ED07000DBD01CB04BD0036
                EAE7BDB8BDB8CBBDC6E7BDCAC7CAC7CAC7CAC9CAC7C6C6C9CDE7E8CDCDCDE8CD
                CDCDC9C9C8C8AFC8C9C8C9B8F7F7BDF7B6B6B6B7BDBD06B60011F7F7B786BDB7
                F7BEB79494B9D207F7BDED0004070006ED07B66F461A00000009686FF8B6F7B6
                B6F7F800046800316FB607EDF4F6F207F2BDF7B6F86FF8F8A3A9A5AAAAB8F7C0
                998A8A998A99BFBFBEC5D3F0EFD4E8CDEEF1ECF3EAF1EAF1F00007D5001EF0D5
                D5F0D5F0B8F7DDF1DDDDDDEADDE0F1E407BDF207E0E007F2F3F4E5F104E4001F
                E5E5E5F2E5F2E5E0E5E0E0D7E0D7C40707EEE2E3F2F2EAE9D9BDF7BDF7F7BD00
                06F701BD04F70013C4C4C0C4C2C1C5C1C5C1C1C5C1C5C1C5C5C1C10004C501ED
                06F305EF000EE8CDE8CDCDEFEFF4F3F0F4F0F4ED0BEE04ED00050707ED070700
                10BD0022CBF1EAE7BDF7CBBDBDF7BCE7BDCAC7F7CAC7CAC7CAC7C6CACBCAC9EA
                CBCCC9CDEDED04070027C6C8C8AFC9C9AFC8C8BDF7F7F7B6BDBDF7BBB6F7F7F7
                B6F7F789C2BDC4C0C4C0BDB6F7D2EDED070005ED0007BD07BDB6F8461B000000
                001E6369A3B6F7B6B6B66F68686B6C6B6CF86BF8B6BDEDF4ED07F6ED07F7B6B6
                04F8001FA9B8B8AABCB9B7BE8ABFBF89BFBEBFBEC0D2EFEFF0F4F3ECF3F3F1DD
                DDF1F00009D5001CD4CABABCD9D7DDDAE4DDE7DDD90707F0F107E0E0E0D7E4E0
                E4F2F1F104E50022E0E0E5F2D7E5E0D7C4E0D7070707EEE5E5F2F6F1D8BDF7BD
                F7BDBDF7F7F7BDF7BDBD04F70036BDC4C0BBC0C0C4C2C1C5C5C1C1C5C1C5C1C1
                C5C1C5C5C1C5C1C5C5E1EDF2F3F3F3EFEFF3EFEFE8CDCDCDEFCDCDEFEFF6F6F4
                EDF6F4ED0DEE0003EDED07000FBD0022CB08F3ECE7F7BDBDF7BCF707E7BCB9BC
                B8CAC7CAC7CAC6CBC9CAC7CBF4CAC6C608F204ED003407C6C8C9CCC8C8C8C6B8
                B6F8B6F8F8F7BDF7BDBBBBF7B6B6F7BDBE89BEC499C1EEC5BDBDD2EDED07BD07
                0707F707BDB6B66F462000000067686F6FB6B6F7F7B66868696C686B6C6F6FF8
                6D6F6F6FF7BDF207EDBDBDBDED07F7F8F8B6B6F8A9A9B8AAB8F7C0BEBF8ABE8A
                BF8ABFC1C4D3F0D5F0F3ECF3F3F1DDF1F1F0D5D5D5F0D5D5CBBCF7D8BCD8D9BC
                D9D9E0EA070707F1DDE0EAE4D9EDE0E0E3E2E5E4F30005E50016EDF3D9E0D9E7
                E0E0DE0707EDE5E5F2F2F6EDD9CBF7F704BD05F7000FBDF7F7F7BDBDC0C2C0C2
                C4C0C0C4C20006C50004C1C5C1C504C10008C3C1C5C1C5C5D3F107F30014EFE8
                CDCDCDEFE8CDEFF3F3F6F6F4EDF4EDEDEDF00AEE01070FBD000DCBE7F1E7E7CB
                F7F7F7BDBDCBD90004F70049BDCAB9BCC7CBCACBC7C6E7F1CAC7CBC6EDF3EDED
                07CAB8C7C68CB8C6C8B8B8B6B88CB8C6BDBDBDBBB6B6B6F7F7F7BDB7C2C4EEC1
                BFEDBEBDEDED0707EDEDED07ED07F7ED07F76F461F000000009D4C6FB6F8B6B6
                F7B668686C686B6C6B6FF8F86F6D6F6F6DF86F6FB6BDBD07F6F6F6F4EDEDF7B6
                B6F8F8B6A9B8BCB8BCF7BEBEBFBEBFBFBEBFBFC0D5D5F0F3ECF3F3F1DDDDF1F2
                D5D5D5F0C7BCBCBCD9BCD9BCBCD9BCD9BDBDEDEAE4E7DDDDDDDBDD07DFE3E5E3
                E5F1E4E4E5E1F1F3D9F2DDECF1DFE00707EEE5E5F2F2F6ED07BD07BDD2D2D2C5
                CF07BDF7BDF7F7BDF7BDF7C4C4C4C0C4C2C4C0C0C0C2C40006C5000AC1C1C3C5
                C1C5C1C1C5C104C501ED01ED04F30005EFEFE8CDEF0004CD000FEFEFEFF3EFF3
                EDF4F4F4EDF2F3EEF40006EE0003C407C4000CBD002AC9CBCBEAF107BDF7BDBD
                F7BCE7BDBCF7BDC7F7F7F7BDBDCAB9B8F7CABDD9CBC6CAB8C7EDED07C6C7CAB8
                04C6001DB8C6AEC6AEC6AFB807BDB7F8B694B7B7B6F7BDBDD3C5C1EEC4EED3BD
                F700050701ED04070006BD07F7F8461A00000163016F04B60025F8F868696A69
                6C6B6C6BF8F86FA3F86F6FF86F6F6FF8F8F8BD07F2F4F6F6F6F4F007F7B6F800
                04B60072B8ADB8BCB9C0BEBFBFBEBFC1C0D5D5F0F3ECF3F3F3E4DDDDF1F1D4BC
                F7BCD8BCE7BCBDBCBCBCD9BD07ED07DDD9F1DDDDDDDAEDE2E5E3E3E5F7BDF7E5
                E4F2F3D9F3E7ECE0E2070707EDE4E1F4F4F40707D5D2D2EEEDEEC5D3F0D2D507
                F7F7F7BDBDC4C5D3C4C4C4C5C4C0C2C0C4C0C5C1C5C104C50007C1C5C1C1C5C5
                C10004C50026C1C5D3F1EFF3F3F3E8E8D4CDCDEFCDEFCDCDEFCDEFEF0707BD07
                EDEDF4F4F6F6F6F4F4EEEEC40ABD005FCBCBBDBDCBCBCBF1E7BDBD08BDF7BD07
                EABDF7BDF7BCF7B8BDF7BDF7BCF7F7B8BDCAC7C6F7B8C6CAED07CBB8C6C6CAC6
                B8C68CC6C68CB8B8B6F7BDBDB6B6B6B78594B6B6BDBDC0BFC0EEEEC5C407ED07
                BD070707BD0707EDED07BDF7F8461A000000002D4CF8B6B6BDBDB66A686C686E
                696E696EF86FB789B7B6F8B66F6FF86FF8F8F8B66FF8F707F2F4F6F6F6F4F007
                BD0005B6001EA9B8BCCAB8F7C0BEC1BFBEC5D5D5F0F3ECF3F3F3F1DDF1D9CAF7
                DCD9D8D904BC0032BDD8BD07F3D9BCBDD9D9D7DDDDD9E0E3E5E5E0F7F7BDE5E4
                F3F1ECF0F1EDE2E0070707F4F0EDEEF6F00707D2BDC4C5E0EEC504D5000ECFD2
                BDBDBDF7C4C4C4D3C4C5C4C505C4000EC0C2C4C5C1C1C1C5C1C1C5C1C5C107C5
                0008C1C5C5F2F3F3F3EF04CD0012EFCDCDEFCDE8EFCD08070707BD0707EDEDF4
                05F60021F4ED0707BDBD07C4BDBDBDCBCB08CBCB08E7EDCBBD07CBCBF7BDE7E7
                BDBDF7F7F70004BD0027F7F7B8F7CABDF7B8B8BCB8F7C6B8CBC6C6CAC7C6C6C6
                B8B8AFC68CC6B8B8B8F7F707F7B7F894B60006BD000807EDC5C5EE07D2BD05ED
                000B07ED0707EDEDF7F8683F15000000003168F8F7BDF7BDF76D686B6C696C6B
                6C6F6FF8C095869589BEB7B6F8F8B66FF8F8B6F8F8B6B6B6F707F2F4F6F6F6F4
                EDBDF70004B60073F7B6BCB8BCCBF7C4BEBE09D5D5F0F3ECECF3F0F1CABCBCDD
                DDE9EADCE9D9E6D8BCBD07EDD9D9BCBCD9BCBCD9D9BDE3E5E5E0F7F7E0E5E0F4
                F3F3F3F407E2E00707EDF0F3F4F4F6ED0707BDD2C409EEF0F0D5F0F0D5D5D4D5
                C4D4D5C0C4C4C4E1D2C4C4C2C4C0C5C4C4C5C1C5C1C1C3C1C5C1C10004C501C1
                06C50016C1C5C5EDF6F3F3EFE8CDEFCDCDEFCDEFCDCDCDEF07BD0507000FEDF3
                EDEFF4F4F6F4F2F1F0EDEDED070004BD002BCB07CB08EDE7E7CDCBCBBDC7BD07
                E7E7BCF7BDF7BDF7BDF7F7BCF7F7BDF7F7B8F7F7F7B8F7BDBDB8BDB8F70004B8
                001DC6B8B8B8C6C6C6B8B8F7F7F707B6F8B6BDF7F7F7BDBDBD0707ED07EDD200
                07ED000B0707ED07BDF7F7F76F340C000000003563F8F707ED07B6686C686B6C
                6B6C6B6FF8B7BF76F86F6FF886BE99BEB7B7B6B6B6F8F8F8F7F8F8B6F8B6F7ED
                F2F4EDEDED0707BDBD0004B60048F7BCB8BCCABDF7BDD2D5D5F4F3ECECF3CAF7
                BCDDEAD8DDE4E9DCDDEAE9D9EAD9D9BCD9BCBDBCD9BCD9BCD9BDD9BDF7F7E4E5
                EAF4F3F1F6F4E0DFE00707EDF0F4F4F4F60707D2BD0705F40003F0D5F00005D5
                0006D0D2C4C0C4C007C4000CC2C0C4C0C4C5C5C5C1C5C1C104C501C106C501C1
                04C50010D3EDF3EFE8EFCDEFCDE8E8CDCDCD08ED080701EF04ED0012F1F3F3F6
                F4F4F2F0F1F4EDED07BDCBCBCB0705CB0006BDBDCBCBE7E706BD04F701BD01BD
                04F7000DB8F7B8BDBDB8F7BCB8F7B6B8B60005B80010F7C6C6C6B8B8F7F7F7BD
                F7BDBDF7BDF704BD04ED000407EDEDBD0507000BEDED070707EDBDB646210C00
                000000954CA3B607EDEDBD68686B6C6B6C6B6E6FF8BEB777768676F894768686
                9589BEBEB7B7B6B6F7F8B6B6F8B6F8B6B6B6F707EDF4ED07F4F407BDBDF7F7B6
                F7B6BCB8BCCACACBD4D5F0F3ECCAF7D8E4DDBDDDF1D8BBEADDD9DDEAEAE9D9D9
                D8D9BCBDD8BDD9BCD9D9BDBCBDE0E0F1F3E7DDF6EDDEE2E00707F0F2F3F4F4F4
                07EDD2C4BD07F2F4F4F4F0F4D5D5F0D5D5D5F0F0CB0807CBD20004C4000DC5C4
                C0C4C0C4C2C1C1C5C1C5C10004C50003C1C4C10006C50014C1C5C4C4C0C4E0F3
                F3CDEFCDEFCDD4EFEFEFF30807070018ED08EFEDEDEDF3ECF3F3F3EAF1F1F4F4
                F6EDEDF3F007CB0807CB000807CBE7E7CBBDBDCB04F701BD01BD07F70017BDBD
                F7F7BDF7F7F7B6B8B6B6B6B8F7B8F7B6B8B8B8C6B80004F7010704BD000307BD
                070005ED001507D2EDEDED07EDEDED0707EDEDBD07EDBDF7462313000000002A
                686FA9BCE7F2B6686B6C696C6B6E696FB7BE6BB676958694BAA79494B7F8F8B6
                B786BEBEBBF7B6B6B6F806B60075F8B6F707F4F407EDED07ED0707F7F7B6B6F7
                BCB8BCCACACB08BCF7DDDDBDD9DDDDF7D9E4DDD9DDF1EAE9D8DDDDEADCE9D9D8
                D9D8D9D9D9BCD9D8D9D9D9EAE4F6D9E2E0070707F0F3F2F4F6F2ED07EDEDC4C4
                BDC4F2EDC4BDC4D3D5D5F0D5F0D2ED07ED07BDC4C40707C4C5D2C2C4C0C1C1C5
                C1C5C10004C50008C1C4C2C4C4C5C5C104C504C4000FC0C4EFF3EFE8CDCD08D2
                CDEFF3F3ED000707000AEFEDEDEDF1F3F3F1F3EC05F10016EDEDEDF2EDF2F3F4
                ED0807CBBDCB07CBCB07CBCB07CB04F70005BDBDF7F7B80004F70017BDF7F7BD
                BCF7F7F7B8F7B6B6B8F7F7B8F7B6B8B6B8B8B60005F706BD001CD2D207D207D2
                ED07EDEDF2EDEDBD07EDEDEDBDBDBDED07BDBD4C21150000002E686FA9BAD9E7
                6E686C6B6C6B6C6B6DF8BE94F8B66FF86FACB6B6BAACBAA7A3B6B6F88695C0BE
                BEC0BEF7B6F7F7A308B6005DF707F2F3F2F4F6F4F0EDBDF7B6F7B6F7BCBCB8BC
                BCDDF1DCD9F1D9BCDDDDF1DDF1DDE9BCD7F1F1DDF1DDDCDDE9D9D9D9D8BCBCD9
                D9BDD9BCD9D9D7DFE007BDEDF0F1F0F4F6EDEDD2EDEDBD0707C4BDC4C0F7BDC4
                F4F4F0F0D5EDC4EDC400050701BD010704C401C001C405C10006C5C5C5C1C5C1
                04C40019C5C4C4C5C4C5C0C4C0C4C4C4D208E8EFCDD408CDCDCDE8D4ED000607
                05ED0009E7F3F3F1F3F1EDEDED0006F10016E7EDF2F4F2EDF6F4EDEDCB08CB08
                CBCBCBBCB9BCBDBD06F70003BDBDBD0007F70010B6F7B6B6F7B8F7B6B6F7B8B6
                F7B6B6B805F70008B607F7BDF7F7BDBD06ED001407ED0707EDEDED07EDEDBD07
                0707F7F7684621150000002F4C90A9BCD9BC6F686B6C6B6C6B6C6F86BE9486B7
                7694ACACB78999B795BCB1BABABAB6B6BCB794B6B7B7C0BEC4B7F70005B601F7
                04B60021F70707F2F4F6F6F6F4F0EDBDF7F7B6F7F7D8DDDDDDF1E4DDDDDDF1D9
                DDF1EABCF70004DD0009F1DDDDF1DDEADDEAE90004D90016D8D9D9D9BCD9BCD9
                0707EDF0F4F4F4F6ED07EDED07BD04070010C4C4BBC007F6F6F6F4F4F0F2EDC4
                07C40507002EBD07BDBDCBC0D2D2C4C5D3C1C5C1C5C1C5C5C5C0C4C4C4C5C4C4
                D207D207D2D2EDD2CBD4CDE8D5EFD4CDE8D4E8080707001BEDEFEDED07F1EAF1
                ECE7EDEDED07EDEDF1F3F1F3F1F1EAF1EDF4F40006ED000708BDB9F7BDBDBD00
                06F70015BDBDF7F7F7BDF7F7F7B6F7F7F7B6F7F7F7B6F7B6F70005B604F70015
                B6F7F7F707F7BDF7F7BDF7BDE4EDE4EDED070707BD0004ED000BBD07ED0707ED
                BDB66F3F150000000035636FB6BCD8BC6D686C696C6B6C6BF899F86FF8B67689
                BE94B69586B789D6BABEBBBABABABCB794B794BABAD707C2C0BEC0F7F7B6F700
                04B60047F7F7F7B6F7BDEDF2F4F6F6F6F4F0EDBDF7E9E9E9EAEADDF1DDF1DDE9
                E4F1D9F7D8DDE4F1E4DDDDF1D9D7F1DDE4DDDCEADDE9D9E6D9D9BCBCBDBC07BD
                F0F1F0F4F4F407EDED07BD00060704C40024BDEDED07EDEFF4EDEDED0707D3C4
                D2E0ED070707BDCBCED2C7D2D2D3C5C5C1C5C5C5C2C005C40015D2C407C4CBBD
                07BDC40708CDCDD5D5E8D4EFCDCD0800060701F004ED0005E7F1ED07070004ED
                0029F0F1F4F0F4F2F3F2F3F3F2ECF1EAEDF1EDF2EDEDF6F4F2ED07BDF7F7BDF7
                F7F7BDF7BDBDBDF7F7F7B60004F70008B9BDBDB6F7F7B6F706B605F70006B6F7
                F7BDF7B605F70018D9D9BD07ED07F707BD07EDED070707EDEDEDF407B66C401A
                0000004E686FA9BCD9B694856F6E6B6D6B6E89867695B66FB688C2BEA7BAA7A3
                94D8B6BFB7BE99B7BCB786B7B6D6B6B6BCBAD7BCD7C0BEC0C4F7F7B6B6BDF7F7
                B6B6F7B6B6F7BDF2F4F4F6F6F6F4F4E7EAEA04E9000ADDE9DDEAEADDE6D9DDF1
                04DD0067E4F7DDF1DDF1DDDDE4DDDDF1DDDDE9D9D9D9BCBD0707D907F3F4F407
                D2EDED07BD0707ED07ED0707D2C4F7BDBD07CDCDEFF3EDED07ED0707EDEDC4C4
                07ED07BDCBC4D2CBD2C7D2D2D2C5C5C1C0C4C0C4D3E0EDED07D207E0ED0707C4
                0708E8F1E7EDE8EFCDCDEF0006070024D2EFEFD4ED07EAF107EDF2F3F0F3F4F3
                F2EFF2F4F3F0F4F4F3F3F1F1F1F3F1F1EAE7EDF404F6000AF4F0EDC4BD07BDF7
                BDBD09F7000FBDC4F7F7F7B6F7F7B6B6B8F7B8B6B60008F70016BD07B7948595
                B7F7D6BCF7F7F7BDBAF8B6BD07EDED0705ED0005BDB6F8461C00000000814C6F
                A7BCD8BE77957695F8F86F94896D6F859586B9BEBB9BBEC299B6BABAA7B6B6BB
                89BABDC2B7B997D6A9BAF7B6B6B6BABAB6B7C0BEC0C2C0C4F7BCB6F7B6B6B6F7
                BDF6BDF7BDEDF2F4F4EDEDF0EDE7F1EAE9E9E9EAEAE9E9DDDDF1DDF1DDF1DDBC
                DDF1DDF1DDF1DDDDF1DDF1DDE4DDEADDE9D9E7D9BCD9BCF1ED07ED0707BD0700
                04ED002007EDED0707F7BDF7BDCDCDCDCA08ED070707F207EDEDED07C4D2C4C4
                07D2CBC705D2000ECEC4C4C4EDE0C4C4F2EDEDEDF2F006ED000A08E7DDEDEFCD
                EFCDEF0804070034BDEDEDCDEFED07F1F3F4F3F0F2F4F4F0F4F4F4F3EDF3F1F1
                F1E7F1E7F1E7EDF1EAF1F1ECF1EAEDF2F4F4F6F6F6EDF20707BDF7B906F701BD
                04F70007B6F7F7B6B6F7F70005B60028F7BDF7F7BDBDBDC0F7B6BDBDB794B694
                B7A7B6B6F7F7BCB1BA948594F7BDBD0707F2F407B6F8461F00000082636FA9BC
                BD99766F69767786958695766FF8F885C098BA9A98DE9BBEC2C2BEF7BABCA7B7
                D9C4C1BBB6B6B6BAD9BABDBABBB7B6B7F7B7B7B6B7C4C4C1C0BBBDF7F7B607BD
                B6F7B6F7B6BD0707F2F4F3EEF1EDF4F1E7EAEAE9EAE9EAE9DDEADDDDEADCE4EA
                DDE4DDF1DDF1DDDDF1DDF1DDDDE4DDDDEAE9D9D8D9BDBDEDD207BDBDBD0705ED
                001507EDF7BDBDF7BDF1E7E808CDCBE7BDED0707BD07BD0005070039C4D2C4C7
                D2D2C7D2C7C4C7D2D2F0E7E007EDE7E7E708E7E7E7D907E707E8E4DDEDE8CDEF
                E8CDED070707BD07EDEFD408ED07F1F3F4F2F3EFED0004F10028E7E7E7F1E7EA
                E7E7CB08CB07CBCBE7E7F1F1EAF1ECF1EAF1E7F2F4EDF4EDF2EDED07BDBDF7F7
                BDBD06F70005B6B6F7F7C00004B601B801F704BD0024F7B7B7B7B6B694B6F7BD
                BABAA7BAA9A7A7B6F7BAB6949495B7867676F8BDF6EDB66F461F00000042686F
                BABCBA767677766D767676776D76769576B9C197A99497DE9B9ABADEDE9BC3C1
                C2C3C5DEC3C398B7B6BABDB6BABABCB6B6B6BCD9B6B6B6BDB6F7BEC4C2C0C0BB
                04F70028B6F7F7F7BDBDBD0707EDF4F4F6F4EDF2EDE7EAEAE9E9EAE9E9EAE9DD
                EAE4F1DDDDF1DDF1D9D9DDE404DD0009E4EADDE9E9EAEAD9D9000407001CBDED
                ED0707EDEDED0707BDF7BDF7BDE7E7E7EDE7CBE7E7D907BDD9BD06070016CBCB
                D2D2C4D2D2C7D2CBD2CBD2D2DD07EDEDCDEFCDE804CD002DE808CDCDF1E7E8EF
                CDEFCDEFCB07BD070707ED08CDEDEDD9F1ED07CBCBBDCBBD08E7E7E7F1F1EDEA
                EDE7EDCB080005CB0013F1EDE7E7F1E7E7EAF1F1ECF1EAEDF2F3F4F2EF0004ED
                0003BDF7BD0004F70034B8F7F7F7B6F7B6B6F7B6B6F7F7B6F7BDB9B7B7B7B6BA
                A9BAB6BABDBDD9D9C4E0E0C4C5E0BCB6BDF77686957676B6F6EFB66D46200000
                004D4CF8B6BCB66D6F6C6F76696D6B6D766F6F6F88C1C0BAB7B8B6C298BBBA9B
                C39BD69BC2D7C3DFC3C3C39BC2BBDEBBF7B6F7C0C0B7BCBDBBD8BCD9B6F7B7C0
                B7BEBBC0C4C0C2BDF7F7F7BDBDBD070005BD001807EDEDF4EDEDF4EDEDF1E7EA
                E9E9DDE6EAE9DDEAF1DDDDF104DD0014F1DDF1DDEAEAE9E9EAEAE9EAEABDBCF7
                BDF7070704ED000D0707BDF7BDF7BDBDE7E7F1E7070007E7002DD907BDBD07CB
                08CB08CD0808D2D2C0D2C4CED2C7CBE7D9EDEDEDCDEFCDCDCDD4EFEFD4E8EFED
                E7D4E8D4E8D4CD0007070044D4EFEDEDEAF1BD07CBCBCB08CBCCCBE7F1E7E7E7
                F1E7F1E708BDCBCBCC08CDE7E7F1E7E7E7F1F1E7E7F1EAE7F1DDEAE7EDF1F2F4
                F4EDF3EDEDEDBDF7F7BDF7B6B8B6B6F705B60028B7B7F7F7F7BDF7BAB6B6BABA
                A9B6BABCBDBEBFC5C5C1C5C5C2D9D8A3F87794767694F4F2F76A461F00000009
                686FB6BA957676776F000676003E779585C0C0C3BC87B89D9BC29494B6DE98BB
                DEBB9FC3DFC3C3C3C2BBB7BDC3C3C3C5C2C0BBD9F7BFBBC207D9D8BCBCF7F7B6
                D9BDBDF7C0C2C4C0BDBDBD0708BD003D070707F4F4F2EFF6F2F3EDE7EAEAE9E9
                EAE9E9EADDF1DDDDF1DDDDDDE4F1E9E9EAE9EAEAECEAD9F7F7F7BDBDF7BDF707
                07EDBDBDBDF7BDF7BC07E7D9070007E700090808CAC7CB0808CB080004CD000F
                08CD08CDD2D208D2D2D2EDD9E0D9E70004CD000EEFF6EFCD08CBD4D4E8D4E8D4
                E8CD07070071CDEFED07F1E7BDBDCBCBCBE7CC08E808CBE7E7F1E7F1F108CCCB
                CDF108CDCCE7F1E7E7EAF1E7E7F1E7E7E7BDF7CAEAEAF1F1F1E7F1F1EEF3F2F6
                EDF4ED07BDF7B6F7B6B6B7F7B6B6BDB7B6F7BAB6BABCBDBCBCD9BCBAD9E6BAF8
                B695F8B7BFBFC1C1C1C5BABA9476869576EDF0D9F8461F0000000019636B87B9
                867690A76FF8696F76766F6DF888BFC19BB880B8DE00059B0008C3BAB8B6BADE
                9BE106C3001CBDC2DFDEC3C3BFC4BBBDB7C0BBC5BCD9BBC4BCD9BCBCC4C0B8B7
                B7C004BD010707BD010704BD00450707EDF2EFF2EFEDEDF4F1F1EAEAE9EAE9EA
                EADDEAE4DDF1DDF1E9EAE9EAECF3ECD8F7F7BDF7BDF7BDF7BDBDF7F7BDBDF7BD
                F7F7F7BDBDBDE7E7F7BDD9ED07BDF3F30708080005CD01EF05CD0019EFCDCDCD
                EFCD07D9EAD907D9E708CDCDEFEF08CBCBCB0808080004CD01080707000BCDF0
                EDE7F1D9BD070708CB0004CD0062CBBDCBE7EDF1EDE7E708CCCDE7E8CC08E7E7
                EAEDF1E7F1F1EDEAE7E7D9BDE7CBCBE7BDE7F1F1F1EAEAEDF1EDF4F2EDEDEDF2
                D2C4B6F7B6F7B6BDBDB7B6BAD8D9BCBAE7D8D9BCB694B6BCF8B7B7B786948695
                8695B7BABAA9F795767607F207A3461F00000026686BB6B8957676BCD6947676
                6D76768685C0C09BC3C2B8F79B9BC39B9B9BC3BABBB9BBC29BDF06C30018DFC2
                C2DEDFC3DEDFC3BDBABCBCC4D8D8BFC0C2C2C0D9C4BD04F70BBD01070ABD001C
                0707EDF4F4F6F6F4F4F2E7EAEAE9E9EAE9DDEAEAE9E9E9F1F3F3D9BD04F7001C
                BDBDBDF7BDBDF7F7BDF7BDF7BDF7F7F7BDBDF7BDBDBDF707BDBD07E704070003
                CBEF08000DCD000EE8E8EAD9E4D907D907CBCDCDCD0807CB000408CDCD080407
                0074BD0708EFEDEDEDF1BDBD07BDCBCDCD08CDCBCB07CBCB08E7EDEDF3EDEFCD
                CDCD08E7E7F1EDEAF1EDEAEDEAE7E7E7D9D9EAE7E7CBCA08F2F3F2F3F1F1F1EA
                E7E4EDEDF2F6F6F6F4F0EDBDBCBCD8BABABABCD9D9D907E0C5C4BAB6B7BDBBC4
                BBC1BE94948594858694D6ADA7A7A9ACB6F3076C461F00000016686BB6B78676
                94EDF7766BF8A7766F768BC2BFC1C3C3049B000CC39B9B9BC3BC8CB8D7C3C3DF
                06C30020DFC3C2E4DFBBDEC2C4E0C1C2BDBDBCBCBBBDBBC0BBBCC4C0C4F7F7B6
                BDF7BD0707BD000307BD070005BD010704BD0049070707EDF4F4F6F6F6F4F4F1
                F1E7E9E9EAE9EAF1F1F1D9BDBDF7F7F7BDBDBDF7BDBDBDF7F7BDF7BDF7BDF7BC
                F7BDBDBDF7BDF7F7BDD90707BDBD070707BDF10807E7F3CBE8EFE8CDE80005CD
                010801E407D90009E7CB08CDCD08CBCBED0004CB0045CD08070707BD070707CB
                EDED07EAEABD0707BD0707CDCC0808CB08E8E7CD07EDEDF4F4ED08E7E8E7E7F1
                E7F1E7F1E7F1E7E7F1E7E7CD07E7E7E7CACD08F4F2F3F0F4ED07D90004EA0003
                D9E7F10005F60010F4EDE7EDE7BDD907C4BFC5C5C1C5C59505C50015C2BBBEB6
                F8F894F894B6A7BCBAA9BADAED078E441C000000004D4C7FB686B776BDF2B776
                9590A794F86F85B7BEC0BEC1C5C3C39BC3C3E3E3DFB8B8B8DFC39BDFC3C3DFC3
                C3C3DFC3BBBCBBD7C2DFC2DDE0DFC3E1C1C4BDBDBCBBF7D9BDC5C4C4DFE007F7
                F7BDF70006BD01070BBD010704BD002807BDEDEDF4F4F6F6F6F4F4EDF1E7BDBD
                BDF7BDBDF7F7BDF7F7BDF7BDF707F7F7F7BDBDF7BDF7F7F705BD0014F7BDBDF7
                BDD9F7BD070707BD070707BDEDF107ED04F3001DEFEFE8EFE8EAD9E7E0D9D9D9
                EDE7E7EDCBCB08CBCBCBED07CBCBCB0808000707002D08EDED07F1E7BDBDBD07
                EDED07EDEDEDCB08CD0807EDF4F2F4F4F0F1E7E7F1F1E7F1EDF1E7F1E7F1E7E7
                F1EDE80004E7001808CACBEFEDF2EDF1070707BDBDBDD9D9EADDECF3F3F3F4F6
                04ED000B07D2C2BEB7C1BEC1E1C1BE0007C50013C1B694B6B794B78694F7D6AC
                D6DDD90790341F000000000E686F8595B685BDED769585A797A304A700149486
                B7B7C0C0C0BFBBBBE3E3E5BBF7C4C3C3C3DF06C30021DFDFBBF7B9BCDFBDBBE0
                C3C3E1D3D9C2C4C4C2C0C4C5E0C0C2C5E1BD07F7D2D2BD0004F701BD010709BD
                001B07BDBD07BDBDBD0707BDBDBD07BD07EDF4F4F4EDEDF0EDED0707BD0005F7
                0016BDBDBDF7BDBDF7F7BDBDF7BDF7F7F7BDF7BDF7BDF7BD06F700070707C4BD
                BD07BD0004070025BDE7F3F3F3F2E0E1E1F2E7D9E0D9D9D9E7E7E7E8EFCDEFCD
                CBEDED08EDEDEDCBCB070707BD0006070006EDED07F1D9BD050705ED004A0707
                EDED07EDEDF4F4EDEDE7EDEAEDF1F1F1E7E7F1E7E7F1F1E7ECF3ECF1E7E7E708
                CDE7F3F0F3F0F2ED0707BDBDBDF7BDF1ECECF1ECD9F7F7EDF2F3F0F207F4EEC4
                C4BEBEB7BEC5C5C105C50012BE99BEC5C1BFC2B79585F8DADADA0790341F0000
                0026686FB68595F707ED777694979FDEDE9894A7A9BAA7F7BAF8B7B7F7BBE3E5
                D7D9BCBBE0C2C3DF06C3002CDFC2BCB8BDE2E1C3F7BDBB09C5E0F7F7BDBBF7B7
                B7DFE0C009D2DFF0EDF0F2F4F0F0EEC4F7BDBDBDF7BDBD0706BD001A0707BDBD
                BD07BD07BD07BDBDBD07BDBD07EDF2F4F3F2EFEDF4ED06BD0019F7BDBDF7F7BD
                BDF7BDF7F7F7BDF7BDF7BDF7BDF7F7F7BDF7F70004070008BD07BD0707BD07BD
                04070007EDDFE1E1E1E0DD0005D9000BE1F2F3EFE8CDCDE8CDF2070004ED0004
                CB0707BD08070009EDEDE7F1BDBD0707BD0004ED000E07EDED07EDEDED0707EF
                F6F0EDED08E70024F1E7E7F1EDE7F1ECF3F1E7E7EAEDE7E7E7CCF1F4F2F3F0ED
                0707BDBDBDBCEAECDDECECBB05B60015BDEDEDF6F4EDEDEFEDC4C4BEBE86C5C1
                C1C5C586C10005C5000BC1B79486DADDDABCA7341A00000000284C6F859585BD
                F3EE97BADBE39FE3E3E3E5E3DE98B6BAD895B686B6BBE3E3D9D9D8D9BDE7BDD9
                D9C205C3001DE0B8C6BDE5E1E5DFD3C1C4C5D9BCF7D9BBF7C0C0DFC4B9D2C4E1
                F0F4F00004F4000AF0F0BD0707BDF7F7BD0706BD001907BDBDBD0707BDBDBD07
                BDBD07BDBDBD07BDBDBDEDEDF4F2F60005ED001F07BDBDBDF7F7BDF7BDF7BDF7
                F7BDBDBDF7BDF7BDBDF7F7BCF7BDBDBD0707BD000407000DBD07C4070707BD07
                BDE1DFEDE00007D9000EE0E1E1E1EEF2EFCDEFEDED07EDED080701ED0407000F
                EDCBEAF3EDBD070707EDEDED07ED070007ED0031F2F4F1D9E7E708E7D9D9D9E7
                E7E7EDF1EDF4F0F1F3F3DDEDEDEDE7E7E708CBCCE7F3F0F2F3F0ED07BDF7BDE7
                ECEAECECBA0008B60022F7F7BDF2F4EDEDF6F0EDC4C0BE95C0BE99C5C5C5C1C5
                C5C1C595BEDADADABAB6361A00000054636F76959507F20795C2DBDE9F9FE39F
                E3E2E3E3E3DEBAB786B7B6CADEDEBCD6D9BD070707D9D9D807C2C3C3DFC2BDB8
                E0E1E1EED3C5C4C0BDBDF7BDBDC1C0C5C2DFBDD2D0E0EEF6F4EE0708F0F0F4F4
                F007BDD209BD010704BD001207BD07BD07BDBD07BDBDBD07BD07BDBD07BD0407
                0027F2F3F0F3F0EDF40707BDBDF7F7BDF7F7F7D3D2F7BDF7BDF7BCBDF7F7F7BD
                BD07BDBD0707C407BD000407001EBDBD07C407DFE1E4DDD9D9E0E0DEF7D9E0E0
                E1E1C4E1E1F2EDEDED08EDED0807000DBDBD0707BD07BDF1F3F20707070004ED
                00150707EDEFED07EDEDED07E5F0D908E7E8E7D9E7EDED0005E70020F4EDF1F3
                F3ECF1F1F1F0EDEDEDE7CBCAE7E7F1F3F0F1ED0707BDBDF7BDD9EAD907B601F7
                06B6001DF707F2EDF4ED07EDEED3C0BEBEBE86C5C5BFC5C199BFDBDDDA93B643
                150000000058686F7695B607ED999595DAE2E29FE39F9F9FE3DEE3DEBABE95B6
                F7B8C6BDDEDEBD07ED07BCD9D9D907C4C1C5C5DFDFC3C3E1E1E1D3C4B7B7C4CA
                CABDD9C1C2C5C1DFC4C7CBC4CBCDEFEDD2EDED08C4EDEDF4F4F407BD070705BD
                003107BDBDBD0707BDBDBD07BDBD07BDBDBD07BDBD0707BD0707BDBD07BD07ED
                EDF2F3F4F2EDEDF4EEEDBDF7F7BDBDF7F7BDBD0006F7002BBD070707BD07BD07
                BD07BDBDBD07BD07C4E0EED9E0E0E7D9E0DFE0E0BDBDE7D9BDBDE0BDE0E0E007
                EDEDF20005070003ED07ED0008BD004407F1F1F4ED0707EDED0707EDEDEDF2BD
                07EDF1EDEDF2F4E7E7E7D9E7E7E7BD07EDEDEDF1E7E7EDEFF3F3ECF1E7DDEAED
                F3ED08CCCBE7E7E7F1F3F2F3F2ED07BDBDF7D9EA04B60003F7B6F70005B60020
                F8B6F8B6F8F8B6B6BD07EDF6F6F6F4EED3BEBE8695C189998ADBDDDA936D5D15
                0000002D4C6F76B7B7EDC49A77999ADFE0DEE2E2DEE29FE3DEE3E0F786F797D6
                08CABBE2E007ED07D6BDD9D907C0C0C2C40006C50013D3D2BDBBB707C6C7BDC4
                C0C1C5C2E1C0C7D2C20004C90031F0F0D4EEBDD4ED07D3F0F3EDF2EDED0707BD
                07BD07BDBD07BD07BD07BDBD0707BDBD07BDBDBD07BD0707BDBD07BD0707BD00
                050701ED01F404F60003F4EEED0004BD0011F7F7BDF7F7F7BD0707BDBD070707
                BD07070005BD0009D90707D9E4E7DDD9DF0005BD000307BCD90008BD000EEDED
                ED070707ED070707BDBDBD0704BD000607E7EAEDF4F004070015ED07EDEDEDF4
                F3EDEDEF07EDF4F107E7D9E708E6080005070028EDEDEDF1F1F1EAEDEADDE4E7
                E708E7EDEDCBE7E7E7D9E7F3F2F0F3ED0707BDDDDDB6B6BCBABAB6F709B60003
                F8B6F80004B60015F707F2F4F6F6F6F4EED3BEB78986D7DDDA92754718000000
                005D686F7695B6BDB799779A99C5E1DFE1DFE2DEDEE2DCD7E0DE94BDB7D9CBCA
                94B6B6F7BD07BA9CE00707B7B6B6B9C4C0F7C0B9F7BD07C2DFB7E1C0CBC4C4C2
                C1C5C2E0C0CBB9C4C9C9C9CCCCF0F0F0D4F0F0D5D2EEF4F4F6F6F4F4F0EDED00
                040704BD000307BD070004BD00510707BD0707BD0707BD07BD0707BD07BD0707
                BD07BD0707EDF2F4F6F6F6F4F4ED07BDBDF7F7F7BD070707C40707BD07BD07BD
                BDBDF7F7D9D9E0D9E7E1E0D907C4BDF7BDBDBDF7BDBDD9BDBDF7BDF7BDBDBD00
                050701BD010709BD002107BDF1F107F2F30707ED07EDED0707ED07EDF3F4F2ED
                F1F1F1BD07E708E707CBBD0004070012BDD207ED07E7EAF1EDF1D9DDEDEDED08
                CDCB06E70011EAF3F0F3ED07BDEAD9F7F7BABCD7D6BABA0005B601F806B6000A
                F8F8F8B6F8F8B6F707ED04F6000AF4EEC4BBDADA904D2E1E000000574C6F9486
                95959ABE959A89E1E1E1C5C5E1C5E1E1E2E1BEB7B7D4C0E4EDC4C1F7B694F7BC
                9CD6D9F7C5C1C1C2C0C2B9B7F7B6B7BDC4D3C2BBD3C1C5C5C5C0C2C1DEC4CBC7
                BDCBC9C9C9CDC9C9CDD4D5F0F0D4D4CDEFF0F40005F60017F4F4F0EDEDED0707
                07BDBD07BDBDBD07BDBDBD07BD07070004BD0015070707BD0707BD07BD07BD07
                BD070707EDF2F6F6F40004ED002107BD07BD07BD070707BD0707BDBDBDF7D9BD
                D9BD07D907BDE0BDBDF7BDBDCBBDF7000DBD000907EDBDBD07BDBDBD070004BD
                004F07BDBD07F1E707EDF4ED07EDED0707ED07EDBD07EDF3EDEDF3F3ED070707
                EDEDBD070707D20707D2CBBD070707ED07E7D9F1EDF1E7E7EDE8CBCAD9E7E7D9
                E7E7E7F1EDEFEDEDEABCB6BABDD9D9E6BC0005BA01B601F704B60008F8B6A3B6
                F8F8F8B605F8000DF707EDF4F6EDBDEDBD94612B150000000012636B949495B7
                9995999A89E1DFE1C5E1E1C504E10034BFC3BECFE0F2D7E0C5D7B7B7B7BDD69C
                D8F7C4BFC5C1C5C1C5C2F7B6E0C3BDEEC2C0D3C1C4C4C5C0C5C2E1C0C7CBB9CB
                C9C9CCCD06C9000BCDCDC9C9CCC9CCCDEFF3F40005F60015F4F4F0EDED070707
                BDBDBD07BDBDBD0707BDBD07BD000407003FBD0707BD07BD07BD07BDBDBD0707
                BD0707F6F3F6F6F4F0F3EDF4ED0707BD07BD0707BDBDBDF7BDBDD9D9BDBD0707
                F7F7BDCABDBDBDF7BDC4BDBDBDF7D9BDF70006BD00040707BD0707BD001607BD
                BD07BD07F108BD07F3F0F107EDEDED07ED07BDBD04ED000C07EDF10707ED0707
                07BD07BD05D20037C4BDEDEDBD07BDED070707EDEDE7C9CBE6BCD9D8D9D9D9E7
                D9F1F3F2F3EAF7F7BA07D8E7E7D8BCBABCBCD6BAD6BABAA7B6F8A7BA97A7B600
                07F8000D6FF86FF8F7F7EDF4BDF7F8451B00000000556869948695999A86C295
                99E1C5E1C5C2C2C5E1C5E1C3C2C2BEC1C4F1BDEEC5B7B795B7F7DADAE0C5C1C1
                C5BFC1C5C5C1B7B7E1BBD2E0C0C1E1C5C1C5C0C3C5C5DFC4CBCEE0D9D8D9CBCD
                C9C9C9CCC9CCCDC9C9C9CD0006C90003CDEFF40007F60049F4F0EDED070707BD
                0707BD07BD07BD07BD07BD070707BDBD0707BD07BD07BD0707BD07BDF3F6F6F6
                F3F6F6F6F4F6F6F4F4F2EDEDEEBDBDBDF7BDF707BDD9BDBDBDC4C4E00707BD07
                F70004BD0008F7BDBDF7BDBDBDF704BD0107010704BD001E07BDBDBD07BDBDBD
                07BDF1F1CBBDBDF2F3EF07ED0707EDED07BD07F1ED0705ED001507EDED0707BD
                CB07D2D2CBC4CB070707BDBD0707CB0005070034D9CBCBEDEDE7D9D9BCD8BCE7
                BDE7F1F1DDB6B6BCD9D6DCBDD9D8BAD6BABABCBABABAD6BABA97BAB3B1BAAC97
                A794A3F8F86FF8F8056F0005B6B6F84C21000000005E4C6D94859595BE779B95
                95E1C5E1C5F1E1C5E1E1E18AC3C2B79BBDBABCDDE4F7C2B7B7BBDDF7C4C1BFC5
                C5C1C5C5C1C1C2B7C2BDD2C4C2C5C4C5C5C5C2C5C5DFC2C4C7C4E0D6DDD6DDDD
                D8E6CDCBCACBCCCCC9CCCCC9C9C9CCC9CDC9C9EF04F604F40026F6F6F4F4F2ED
                F4F4F0EDEDBDBD07BD070707BDEDBD0707BD0707BD07BD0707BD07BD07F3F6F3
                08F60020F3F6F4F0F1F4F0ED07BDBDBDF7BDBDBDF7F7BDE1ED07EDCBF7BDBDF7
                BDF7BDF706BD001EF7BDBDBD07F7BDBD07F7BDBDBD07BDBD0707BD07EAEACBCB
                07EDF4EDED0704ED000907BD07ED07EDEDEDF00005ED000F07CB0708CBCBD2CB
                CBBDBDBDCB07CB0007BD001DBCF7BD0707BD07E7EDE7EDE7E7F7BDEAEAD9B6F7
                D6D9DAD7C4BDBABCD60008BA0011ADD6D8D8DCB3DCB3BAB1BA92A3F8F86FF800
                046F00056A4C45211A000000005F686F88B9B9BE86959B8699C3E1C5E1F6E1C5
                E1E1C595C3BEC2C2D7DC9CDCD6BABCC2BEBBDDE1E1C4BEC0C0C1C1C5C5C4C0C2
                C2F7D2C2C0C5E1C5C5C5C2C5C5DFE1C7CBDFE0D6DBDCD9DDDBD9E8CCC7CBCBC7
                CDCBCCCCCCC9C9C9CDC9C9CDF40004F60009F4EDEDF1F0F6F4F6F40005F60018
                F4F0EDED0707BD0707BD07BD0707BDBD07BD0707BDBD07BD08F6001AF3F6F6F3
                F6F6F6F3F6F2EFF2EDF0F1EDC4BDF7BD0707EE0707CB05BD0004F7BDF7F709BD
                001907BDBDBD07BDBDBD07BDBD07BD07BDBDBDF1E70807BD07F2EF0004ED0005
                07EDBDBD070006ED001AF3EDED07ED070807BDBDCBCB07CBCBBDEDEDCBCBCBBD
                F7CBBDBC04BD003CBC0707BD07BDD9BD07D9BDD8E7EABCB6BABDD9DDD8D6D7BC
                9CD6BA9CBA9CBAD697BA97BAB1D8D8B3D8B3DCB3B3BAA7F8F86F6FF86F6F6F6D
                68452A1300000027686B87B98B8DCF8DCEC09599DFC5E1E1C5E1E1DF99BEC3B7
                BEC2D8CADBDBDBBABBC2B7C2C5C5EE0004E10041C1C2C4C0C0C0C2C2BDD2BBC3
                C5E1C4C1C4C3C5C5DFE0C7D2C2D7DCD9DADDDBD8DDEFCDCDE8CDCDCBCBE7E7CB
                CACCC9CCC9C9C9EFF6F6F6F4F4F0EAE7EAE7F3F4F40009F60017F4F0EDED07BD
                0707BD07BD07BD0707BD0707BDEDF6F6F3000BF60015F3F6F6F6F3F4F3F4F6F6
                F6F4F007EDED07EDBDBDF70005BD0005F7F7BDBDF70005BD000507F7BDBD0700
                04BD000607BDBD07BD0704BD0010F107CB07BDBDEDF4F207ED070707BD0705ED
                0020F2EDEDED07EDED070707BDCB08CBCABD08EDED07CBCBBDBDBD0707D9D907
                BDBC05BD0021F7BDCB0707F7D8EAEAF7B6BCD2D1D5EDD6BAD6BAD6BAD6D6D6BA
                97BA97B197BA970004D80009B3D8D8AC97A7A7F8F800056F0004684621150000
                0036686B8888CE8D8D8DCF8DD18DCEC1C5E1C5E1C59B86C29AB7C3BBCACCDDDD
                DCD8BBC286DFC2C5F2E1E1EEE1E1EEE107CBB7C2C2D2D3B705C50030C2C5C5C5
                DF07C7C4C4D9DADBD8DDD9DAF1F6EFECEFE8E8CDCDE8E8CBCBCCCBCBC9CACDCC
                F4F6F6F6F4F2ED07DDE7F2F408F601F401F404F60011F4F0EDED07BD07BD0707
                BD0707BDBDF3F40005F601F30DF601F308F60017F4F4EDEDBDBDBDF7BDF7F7BD
                BDBDF7BDF7BDBD0707BDF70005BD000707BDBDBD07BD070004BD000FF1EABDBD
                07BD07EDF3F0ED0707CBCB0006ED01F201EF04ED005707BD07BDEDEDCBCB07ED
                EDED07ED0707CBCBBDCB07BDBDBDD9D9BDBDCB07F7D9D9BCF7BD07F7DCEADDF7
                F7BAD5D5D1D5D8D6D6BAD6BABA9CBAD6D69CBAD697ACD6B3DCB3E9D8D8B3D8B3
                D8ACBA92A7A794F86D6844211500000000054C6F858BCE00058D0060D08D8DD1
                D1CF09C4869995C299C0C2D7CCCCDCDCD8BCBBC2B7C3C5E1E1EEE1EEE5E1EED3
                E807C2DFB7D2E0C2C5DFD3C5C5C4C5C5DFC407BDC5D7D9DAD9DDDDD7DAF3F6F3
                F6F3F6F3F3EFF3EFE8CDE808CBCAC7E7CBEFF6F4F6F6F6F0F1F2EFF209F601ED
                01C408F6000EF4F0EDED07BD0707BDBD07EDF3F40AF601F304F601F30FF60009
                F4F00707F7F7BDBDF70005BD000307BDF70006BD000307BDBD00040705BD0004
                EAE4BDBD0407000BF2F4ED07BDCBBD0707EDF10005ED01F206ED000507BD0707
                ED000907000508070707CB0004E70023BDCBE7D9D9BDD9F7BDBDBCE9EAD9F7F7
                BDD5D5D5EFD8BCD6D6BA9CBABAD697BAACD6970004D60015D8D8B3DCB3DCB3D8
                B3DCD8B3D8BAAC92906646340C0000000036686CF8F885B98D8DCF8DD18D8D8D
                CECE8DD1D18DCEBEB7BEC2BDC6CADCD8CCBCC2BEBEDFC0E1E1EEE1E1E1EEE1ED
                CDC4BBE1F7EEBDC305C50011C2C5C5DFC2CBBDC3D9DBD8DBD9DDD8DDF30004F6
                000AF3F6F6F3F6F6F3F3F3EF04CD000CEFECF1F3F4F6F6EFEAF6F6F409F601C4
                01D20CF6000EF4F4ED070707BDF2EDF0F1F0F3F404F601F30CF601F30AF6000E
                F4EDF2EDEDBDBDBDF7BDBDBD07F706BD000607BDBD07070705BD000607BDBDF1
                E7BD0607000EF4ED07CBCB07CBBD07BD0807EDF207ED000407EDEDED10070037
                E7E7BDF7BD07E7E7E7D9D9BD07BDD9EAF1D9F7BABDD5D5F0F3D9BCBAD6BABABA
                9CBABA9CBA97D6AC9C93D6DCB3DCB3D8B3DCD8E9B3DCD80004B30005AC905D39
                13000000014C016E04F800506D6F88B98DCF8D8DD18D8DCF8D8DCFD1CFCFCED9
                CABCCACACCBBC2B7C2C3C0E1E1F2E1EDE0E1EEEDD3C2C2DFB9EEC2C5C5E1C1C5
                C4C5C5C3E1C4BDC4D3BDD9D8DBDDDCDBEAF6F6F1EEF2F3F4F6F6F6F304F60012
                F3F3EFCDE8EAE7E608E7E7EDF1F6F3F3F4F406F60003F4C1F20010F6000EF4F0
                EDF3F0F1EDEDF0F1EDF3F2F40BF601F307F601F305F6000AF3F4F4F3EDF4EDF2
                070706BD0015F7BDBDBD070707BD07BDBDBD07BDBDBD07F1D907BD000407000D
                BDF4F207ED08EDEDCB07CBCBEF0004ED0007F2F2E1EDE7EFF10005ED050701BD
                09070021BDCACBBDF7BDE7E6D9CB07F7D9EAEAF7B6BCF1F3D4F0F3E7D8BAD6BA
                D6BABA97D60004BA00199CBAB4D6B3D8D8D8DCDCE6DCB3D8B3B3B3D8B3D8B1A6
                8F3B1E0000000054637F87B88CA57F6F6BF8F8B685888DCFCF8D8DCF8DCED08D
                CFCFD0D2BDE6BCBBC2B7C2C2C0E1E1EEE1F6F2EEE1E1C4C2DEE0C4DFC4C5DFD3
                C1C5C4C5C5C5D2CFD5D1D2C0C0C0D9EABDD8F1F6F6EDEEF0D3EEEEED05F6001C
                F3F6F6F6F3F6EAD9E9EAE7CBF1F1F6F3D5D2F008EDF4F4F6F407C4F412F601F4
                01F204ED000BF1F0F3F2F0F3EDF2F3F4F30004F601F306F601F307F601F305F6
                0004F4F4F6F004ED000ABDBDBD07BDBDBD07BD0709BD01D901F108070003EFF4
                F10004ED000408CB08EF04ED000EEFEEEEE5EEF2EDE8E7E8E7EDED0704ED0003
                0707BD000707003EBDCACBF7F7F7BCBDBD07ED07BCEADDB6F7D6F3F6E708F7F3
                E6BCBCD6D6D6BAD6BABA97D697AC97B49CD8D8E9DCE6D8B3D8DCB3DCB3D8D8B3
                B3B1A68F3B200000005A4C7FA5C6C6C8C8AF8CAA85A3B66F6FB6878BCE8D8D8D
                CE8DD0CED0CECF8DD0CECEB9C2B7BEC2E1E1D3F4E1EEE1EEDFC0DFC2C4E0C2C5
                C3EEC5E1C4C5D2D2CFD5CFD1C4C5C5C007D9C4BDF2F6F4EDF0F0D2EEF0EEF6F3
                EDF2F3F404F60017F3EAD8EAEAE607F0F4F6F3D5D5CFCFD5D0EDF0ED07D3ED00
                12F60018F0F1F0F3EDF4F0EDF2EDF4F2ED07EDF4F2F0F3F4F6F6F6F109F601F3
                04F60014F3F6F6F3F6F6F6F3F4F4EDF3EDF0F2070707BD0704BD010705BD0012
                07F3F1E7E707BD07ED07BDF2F4F0EDEDED0708ED0025F2F0F0F0EEEEEEEDEDED
                E7E7E8E8E7EDEDED07EDEDED0707BD07BD07BCCBBDBDBCBDB9CBCB000407001C
                F1D9F7B6D9F3F6D9BD0707F3E7E7BCBCD8D6D8DAD6D697BABA93D6D604D80008
                B3D8DCB3B3D8B3DC04B30005B1A68F3D190000000078687F87C6C6C8C8C8AFC8
                C8C8C687A385F8A3B6F885888B8DCE8DCE8DCECECE8DCE8DCECEB9C0C2D3E1E1
                E1EEE1C4DFC2E1C2E0C4C5C5C4D309D5CFD5CFD0CFD0D0D2C5EED3C5E1D9E0C4
                F4F3F3F2EEEEEEF0EEEDF6F3EEEED3D3EEEEF3F6F1E7D9E6EAE6EDF4F3F6F0D4
                F0D5D5D5D1D5CFD4EDEDEDF0F3F40FF60004F1E7EDF205F4000FEDF307ED07ED
                F4F6F4F4EEF1F0F1F3000CF601F306F601F307F6000BF3F4F0F6F4F4ED07BD07
                F70004BD000D07BDF1F3F1F3F3E707BDEDEDED0004F40006F0F1EDED070704ED
                01EF01F206F0000CEEEEE1EEF2E7E7E8E6E8E7EF05ED000D070707BCC7CA07BD
                BDCACBB8CA0004070031EABCF7BAE7F6F3E6BDF7B6F3F3F3BCD6D8D8BDD8D9DC
                DCD6D6D69CACD8B3D8B3D8D8B3D8D8B3D8B3B3D8B3D8B1A68F3E200000000005
                4C7FAA8CC60007C80070CCC8C8AFC687B66F6E696C6F858888CE8B8D888B8888
                8B888B8B8BD2C0C4C4C5C3C4DFC2E1D2C4C7D3CFD1D5D5CFD4CFCED0CFD5D1CF
                D3D2D407F1D9D9EEF2F4F2EFEDEDEEF0F2F3F6F1EEF0EEEEF0EEF3F6F1E6EAE7
                CACBE7F1F3F3D4D5CFCFD4D2F0D5D5D5F1D2D5CFD5D4EDF0F3F40AF6001DF4EC
                ECECE7F3F1F1F3F2F0F1F0EDED07F4F4F4F6F6F4F1DDF1F2EFF4F40013F601F3
                05F601F305F60010F4F4ED07BDBD07BD07F3F3F3ECF3F10704ED0008F4EDF4F1
                EDEDED0706ED01F20BF0004FEEEEEEEDEEEDEDE7E7E8E7E708070707BDCBCB07
                07F7F7C6F7BD0707BDE7EAF7B6BCF1F6F1CBD3C4F7F3F6EABCBABCD6E7E7D8D9
                BCD8D6B1ACACACB1ADD8B3B3D8D8B3D8B3B3D8B3D8B3B1A68F62190000000004
                636F87B809C801CD04C80051AE8C7F6A53684C6E6D6B6B858488878885878887
                888888CECECED2C4C4C4CECFC7C4D0D0CED3D0D0D5D0CED5CFD5CFD2D2CBC9CA
                08D8D9D9E7E7F1F0F2EFF2EDEDF3F6EDF2F0D3EEF0EDF6F3EACB08CBCA0004CB
                00190808D4D5D5D1D5D5D0D3EFECF0D5D5D5CFD5CFD5D4EDF0F4F40004F60023
                F4F4F3EAECECE7ECF3ECECF1EAF1EDF1ED07F4F4F4F6F4F6E4F1F1F4F4F0F3F0
                F1F0F3001FF6000BF4F4EEED07ECF3F1F3F3F10004ED0006F20707F2EF0704ED
                000807EDEDED07CB07D20BF0004DEEF2E1F2E1F2EDE7E7E8E7E7E8E7BDCBED07
                BDF7B8CACBBD070707EADDB6F7BAF3F6E7F7DDD7C4F3F6D9BCD8DCD8EAE7E7BD
                B7BEB7B6A6A6A6ACACB1D8D8B3D8B3D8B3D8B3D8B3B3ADA6A162200000000008
                4C6FA5B8B8C9C6AF04C80017CCCCC8C8C8AF8C8C7D807B7B6A58634C454C4346
                425959000484000787858888B9CECF0004CE0036B9D2C4CED0D5CFD5CFD5CECF
                D0D0CFD2D4CBCB08CBCBE9DDD9DDD9DCD9F1F1F0F3F2F0EDF0EDEDF0EEF2F6F3
                E608CDCCCBCBCBCD08CD04D401D301F006D50019D2D5D4F0D5D5D5CFD5CFD4D2
                EDF0F3F6F6F6EFE7EDE8E7ECE80006EC000BF1E7E7EDEDF4F4F6F4EDC40005F4
                0009F2EDE7E707EDF3F4F30007F601F316F60023F0BDE7F1F3F1F1F3F1F1F1ED
                EDBDEDF3EDEDED07ED070707CBBDBDCBCBCBD2F0D2D2D20006F0004CEEEEE1EE
                E1E1F2EDE7E7F1E7E7CBCBE608BDCAC7CABD070707EDEAD9F7B6D9F3F6BCF7ED
                07EDF6F3D9D8EAE9D9E6BDD9BDB98686948F8F8FA6ADB3B3B3D8B3D8B3D8D8B3
                B3B3D8B1ACA1621900000009686FA5B8B8B8C6C6C60004C80064C9C9C8AF8C80
                807B7B507B517B51544E412A3F213F3F404256558484858888CECEC7CECFD0B9
                D2CBC0D0D5D2D5D0CFD0CFD5CFCFD5D4CDCBCDCDCDE6EADDD9EAD9D9D9D8D9D9
                E7F1F2F3EEF3EDF1EDF6F1E7CDCDCBCDCDCA08CDCBD4D4D1D5D5CFD4EEEF05D5
                0032CFD5D4D3D4F0D5D5D5CFD5D5EDF6F6E7E8EFF1080808E70808E8EAECF3EC
                BDD9D9D907EDF2F1E1E1F2F4F4F4F208EDF2EDF106ED0004F1F3F3F409F60007
                F3F6F6F3F6F4F30008F601ED01BD060701E704F1000DD907F2ED0707EDEDEDBD
                CBCBBD0004CB0007BDBDCBBDCBCBEE0009F004EE0043F1E7E7E7CAE7E7E7CAB9
                C6CA07EDF3F6F3EABCB6BAE7F6F3BDB6CBBDF3F6F3E6E7E6D8D8D8BCBCBCA3A3
                6B4D6C65658FA8ADB5E6EBEBE9E9B3B3D8B3D8B3B1ADA162200000000007636B
                A5A9A7B8C90006C60009C8C9AF8280807B58BD0004ED0052474E4E54B6F707ED
                ED07EDF7944C425584878BC7C0C7CE8BB9D2CECED0CFCFD0CFD0CED0CED2C7D3
                D4C6CBCBCBCAC7E7E9E9DDD8DCEADCD9D9D8D9D9D9E7EDF2F0F2F3EDE7CBCACB
                CBC6C7CBCBCDC7D2D4F004D50046CFD5D2D4F0D5D5D5CFD5D0D2D0D2D2D4CFED
                EFF6F3E7EFEFD4EFCD0808CBCBE708E708D9BCD9BCD9DDD9D9E1E1C4EDF4F4F4
                EDEDF2EFF2F4F4F2ED0707E70707EDEDF1F0F3F404F6006CF4F4F3F4F3F3F3F4
                F3F4F3F4F3F4F3F4E808CB07BD07BDBD07BDBDBDD9E7F1EAF1F1EDCBCBED07BD
                BDCBCBEED4D2BDBDBDC7CBCBD5EEF0F0EEF0F0EED5EEF0F0EEF0EDE7E7CBE7E7
                D9D9BCB8C6BCE7D9E7EAF1EAB6B6BAE7F3F3F3BDEDBDF3F6ECE7E6D9D8D8D6BC
                B6BAF7EE04ED0015C060A0A8ADE9EBEBEBECEBEBB3D8B3D8ACAC8F4519000000
                000B686FAAB6A9A7B8C6AFBAAA0004C60021B8807B7B50B9ED868607BD2A42F7
                F207C0C0BE86BEC4C0EDF407444253F885888B0005CE003AB9CEBDB9B9F7F7F7
                B6F7B6F7C5CBC9C908CAC7CAC7E6D9D8D8DCD9D8D8DCD8D9D8D8BCD9D8D9E7ED
                EDEFCBC6C7CAC6CBC6CBC9C9D4D0CFD4D2F005D5002DCFD409D2D4D2CFD0CFCE
                CECED207F3F3EDEDF0D5F0F0F0CDC7CCCBBDE7CBBDCABCD8BDDADDDBDAD9DDD7
                D9D9070006ED0012F2EFED07BD07BDEDEDED070707EDEDF2EFF206F301EF07F3
                0041F4F3F3D4E8D4CDCDCBCBBDF7F7F7BDBDF7F7BDE7E7EAF1F1F107BDCBCBCB
                D2D2C4F7BDC7CAB8BDD3D2D5D3F0D3D5F0EED5EED3D5D3D5EEEDD9D9D9E6BCB8
                B8B8CA0005D90032D8B6B69708F3F3F3F1BD08F3F6E7E9E6BCBCD6ADADA3A76F
                07F6C489C4F6B667A1ADADE9EBEBE9DCE9D8B3D8B3B1A7663D1A0000003A4C6E
                B6B6A9BCA8BCADA9BAB8C6C6A9A56A504E6BF2857477F2692A07ED7777747774
                797779797989EDEE4C44686F6C6FF885F8B6B6F8F8B6B6B604F80008B6F8B6C0
                B9C7CAC704C60007BDBCD6BAD8D8D60004D80048D6D8D6D8D8BCD8BAD9BCCAC6
                CAC6B8C6B8B8B8C7CED2D4CFD5CFCFD5D4F0D5D5CFD4CFCECEB9B9C7C0C78BCE
                BDEDF3D9EFD5D5D5EEEDD2CEC7C4CABCC6CAB8BCBCBCD7D6D6D6BCBA04D601D7
                01D906070005BDBDF7F7F70005BD0006070707ED07ED0407003BED07E7EDE7ED
                EDEDF108F3F3EFCBCDCBC7CACBC9CBC9CBCBB8B6F7F7B6F7F7F7BDD9EAF1F1EA
                E707D3D2F7B6B8B8B8B6B6B6B7B9B9D2D3D2D3D2D30004D2003AD3D3D2D2C4BD
                C4B9A587B6BCBCD8BCBCD8BAF8F8BAE7E708F1EFE7D9F3E8E6E6D8BAA9ACA2A2
                6C666C6EF0F47877F0F4686EA8ADE6EBEBB4DCE904D80005ADA68F431E000000
                00AA686EA3A9BAC8B8ADBCACA9A9B8BCA2A3524E41D2BD7474C0071DB7ED7474
                7774777778747977797979EDED3F536A684C68686A6F6F6E6BF8F86F6F6D6E6D
                6F6F94B7B7B7C6B8C6B8B8B8C0B9BAACBAACBAB1BABABAACACBABABAD6BAD6BA
                BAA9B88CAA87AA7F7F80B8B9C7C0CED2D4D5D5D5CFCFD0D2D2C7C0C788888885
                B7B9B8F7D907BCCED2CFD4D0C4D2B988B9B988B988B9BAA9BABAD6BABBBA9792
                ACD6D6BAD907D9BD07B6BCBA05B6000EF7F7F7BDBD07BD070707BDBDF7B605F7
                0017BCBDE707E7EDE7CBCAC6C6CAC6C6C6CAC6C6C6C7CAB8B80004B60062F7BD
                BDBDD907D9EAD907BAB6F8A57F856FA3F8A5B8C0C4C4B9C0C0B9C0C0C0C4CEC4
                CEC0C0C0B67FA587C0F7C0B9F7BAA76B6CB6BCBDD9CA07E7E7F1E7E6BCBAA990
                6FA76F6746393407F6BE7789F6C463A2A9E6E6EADADDD9D9E7D9D9BCBA6E451E
                00000079686EA3B6BAA9A9A9BCACCAADB8A9A26E623A86F2737474EDB60FEEB6
                7477747786EEF3F4BD7479797989F4764E64545153464668684C6C686868634C
                534C684676768694F7B680B6B787B79585A7A6A692A7A6ACA7A6A7A7A7A6ACA7
                AC92A6A6A27FA27F807F7E7F85B88888D2CECED2D4F0D3D4D0CE8BB988000485
                003884878585B6BCBCB6C78BC7C08B88B9B785858587858585A7A3A79292A7B6
                90A3B6979297BABC07ED07BCB6A7A3A3A36F6C6FF8F8B6F8F7F704BD0019F7F7
                B6B6F8F8F86FF8B6B6B6F7BDBDBDB8B8B88080B8B8B88C0004B8000B8CAA8087
                B8B8B8F7F7F7BD0004F7005AA3BAA7A7A7A3A26E6A6B7F7FA58585B7B788B7B7
                88B7B9B9B9B7B9B788B77F586A8588B788B7B7A66C686C6CA5A9B6BCBCBCD9CB
                BAACADF89068A3A5A36E64432163F4EE7777D3F67667A7BCE6BB94BCE7D9E7D9
                D9BCBA6E451A000000264C7FB6BABCBCBAACBAA9AAC6A9A66F64543AEDF77474
                77F43742F476738686C4F0941C6BF2F704790005D3BD214E4E00044100114642
                454C454646404544463F464D6969760004B60041F894857676766F6F678F9090
                8F8F90908F908F90908F669060666746524E547FB6A9F7BDB9C7CECFD5CFD0D2
                C4B9B98885858459556B56566BA3B6A26FF8858887000485003D845956555585
                6F6C686C8E90906F636F6F8E9292B6BCBDF7BDF7A36EA3A368636C466868666E
                F8F8B6B6B6F7B6B6F86F6B6346634CF8F8B6B6F8F8F88000047F002F807F80AA
                878080A57F7F7F8080B8B8C6CBCBC7BDF7B6B6F86B6868685D465D666E6E6A68
                5368586B76857685858586000585003D7657526B8576858576F86E4644343942
                676EA3A3A9B8BCA2A6A74D4D464634394546392021EEF4787777F4D263A2B8D6
                C2BFD7D9D9D9E7D9D9A9903F1A0000000042636FA3F7E70707BCBABACAADA7A2
                67634E86F2737372C0070C40F4F4EDF2D207B70C0C0BC0ED73787878C0ED2326
                46B6EDBD0707BDB64623F8F7B6B7B6F7B7B6F7B704F7000469F8F8B606F70011
                576969F8B7F7F7B6F7B67666605C6067B60006070036F7F84CB6B6BCCBE7EDD4
                D2D0CECE8887857685B6070707BD0707F79453636368634C6B596BB6BD07BD07
                0707F76B5D6060606DF7F7B704F70033A7B9B9B9F76E6C6E53F80707BD0707ED
                F7B65D686C686F6DF86F3F6FF707BD070707BDF76F686D686AB9F7F7F7B6F7F7
                857F7F0008F7001A8CC6CACDCDC9CAB8A56F53346DF7070707BDED07F794635D
                53B707F70005768485C4B60004F70039B669695957431A69F707BD070707B6A3
                6EA3A2676E63470D3FF707BD07EDBDF744F7F6C07877D3F66945A29499BEBBBD
                D9E7D9D9BCB66C3F17000000004B68F8B6CAE7E8E8CCCCCCC8C8B88F675245D2
                F7727374ED850C1A6B461C44F7EDF4EDBD6985ED73787977BE072A85EDD2BEBE
                89BEC0EEF4B6F2B9C0C4C0ED07EEBDC4C0C4C0F2856168F0ED0004C00013F26F
                4C68C4EDC0B9BEB9F2F7453B43F7F2C4850004730035BEC0F0F4B66ABCBDE708
                F1F3ED08BDB98587EDEDC0C079868989C0C4F0F2F84645465D6807F1C0B77776
                7777B7C4F4ED6B4343F7F20004C4002DEEF06E87B9856F6C68F7F2C4B98689BE
                BEC0C4F2F0F7686868633F68EDEDB7B777778686C0EDF40768456AF4C40004C0
                0006F4B65458D2F204C00065F2EDB8B8C6CBC9CBC6B880536BEDEDB7B7868686
                B7C0EDF4ED6C43C4F4C4C0C4C0EDF4575676F6EEC0C0C0C4F485422B0C6FED07
                B777777786C0F0F4F76E463D3D3F1FB6EDC0868986BEC4F4B944F6D3777889F6
                C43B5C9097BBBAB1BABABCBCB6A3634318000000002F4CA3BCBDEAF3ECF3ECE8
                CDC8AE807E4E59F457727473F44C0C13170CB7EFC4868686C4F4EDED73787879
                89ED69F2B7000779000BC0F4ED78797979EEB6F076000479001BEEF84646EEBD
                78797878ED6F4646D2F774747272EDB9343F07D273000470001A487070717186
                F4C468BCBDE7EFD9D907CBBCF7F28678747478740478000B74C0F4B73F4168ED
                B97070000571001D737173C4F49434B7F0898A8A8AD3F26A8585596C6807C486
                7874777477000479003AC0F4F756534294ED8673727371717173727374EEF053
                41F48974747478F4944141D2EE79787978EEF07FB8C6C6CAC6C6876AB6ED8674
                737774740577002DEEF46AC4F679798679C5F642496BF4C579777989F676231F
                BD07777172717071707172BEF4ED4634342AF7EE77000474001C7886F4861FF2
                F0777877F0F4405C6390BAADD6B3B3D8BAA26C663B1A0000001E63F8BCE608EC
                F3ECF3ECECE8CA807B50B7ED73737286F2280C130CF7ED770574000B79F2ED73
                787778BEED07F7000579000EC0B9C073BEBD78797979F476EEF80479001AEEF8
                3F3FF0BD78797878EE6F4441C4C074747272EEF71BC4D2710470002A73737371
                70717074F4B9A3F7E7E7BCBCBCD9F7F0B77274787479B7B7C07778787277F661
                4CED867070700571000972737271C0F468B6EE00048A0011D3ED6B6B846C6307
                C47877747772868686000479003B89F4B72A6FF0777374717173768671727372
                72EDF22AF68974787474F6854343D2EE79787978EEED6A80B8C6C6C6B8B885F2
                777374747476B7C0BE000477001AEEF2C4F489797979C4F6443F68F4D2787978
                BEF4761DBDED72720771000A727277F4D21F1E4DEDC00474001D787486F4761A
                D2F6787779C4F669375C6CBCB1ACACBAB1B1B1A6653918000000001D4CA3BCCB
                EAECF3F3ECF3ECECE6F86A52C4F771727386ED1B131776F277000774001479BD
                73787878BE07F48679797978EDD2BDEEF4B705790004F476F07604790019EEF8
                2A34F0BB78797878ED6F2A34C4B974747272EDF769F2710004700027D2ED07F4
                0771737776C4F476B6BD07BABAE6BDC4ED7172747479EDD2B9EDF477787274D2
                BDC4C4000470004971B707ED077773727378D3EDB7EE898A8A8AD3F24259685D
                B7ED7977787486EDEDEDF4EE73868686D2F469F18673737272F7EDD2F2F07671
                8676C0F4BDF48974747874F6763A43C4F00004780039EEED587F87C6CBCBBDF7
                EDC073747374B6EDBDBDF4F077777789F6F2F479798679C5F621344CF4C57778
                7789F676B6EE73727171708507EDC0000472000786F6B71376F489000474001D
                76D2EEF64D0DC0F6897778BEF6B9344B6CB6B6BAADD8ACAD926E603B1A000000
                002E68A3BCD9E7E8E8E8ECECE8E7BCA36862EEF8717170C0BD0F1717D2F77274
                727477C4F4EDB67274787478BEEDF48604780057F4400C0CD2F47379787878F6
                76EEF878787879ED762121F2B979787878EE6F201FD2BB74747472EEF7D2B771
                717071D2F7151B2AF2F0F3EE07EDC4B66EBABDBDCABDBDEDF4F2F4EDEDF0BD15
                1A0FEE86787472BEF0F471000470008707D26F76D2F47373727879F6B9EE898A
                8A8AD3ED55554546F2C078777877EDB713153FF4F0F1F007EDB907EE7171714A
                B9ED230F1BEDF4F2EFEDD2C4B6F68974787478F66F3939C4EE77747874EEED63
                6AB807EDC4C0B6F2F4F4F407EEF485150C56F477777986F4F4F479797779C4F6
                1D1A3FF6C474747486F685F2B772717271BDED6985F4EE0004720027EEF41AB7
                F67874787486F4B9E0F0471BB7F4C1787777F6C421476E949495BEB7EABCACA6
                663F17000000002E4C7FB8CA08ECECF3ECCDCCCCC7846A55F06D717171C0B60E
                1C49F47372727474EDB969C0F4857478787886EDEDB604780007F20756151BF0
                94000478004BF676F07678777878EE6F1D21F0B979787878EE6E1B21C4B97474
                7472EEF7F47371707172F46842424669684C4C6857686C6EA6BABD07BDB66F6F
                688594B707B6B6BDF3C47978727486F4ED000470000F86ED3F3F3F39EEEDC4ED
                EDF2F3EDEE00048A001AD3EE3F423F6FF47977797886F44646464C6968464C46
                564CEEB904710082F2F7464646426F4C4C4C46464CF48977787478F476392AC4
                EE74787478EEED6CA3A5B807C4F7866D4C4CB676F8BDF8F707F1C477777979F3
                F4F479867979C4F61B1A34F4C474747486F4C4F472717271B7F2230C0CB7F679
                727272BEF657C0F474747478C0F4241B23231BB7F6C4797877F4EE333F907694
                B6B6F7F1B7946F6E391500000039637FAAC6C6CCCDE8ECF3E8E6C7855159F476
                707171C4F70C1C85F24A72747286ED1B0C0CD2077474787889EDBDED77787878
                79D2F2F0BDF4B7000478004BF669EEF878787877EE6F1B20EEBD78797878EE6B
                2021C4C074747472EE07F47070717177F4F0F3F2F3F0F3F2F0F3F2F40768A7BA
                D6BAACA7A7664568F7EDEDC4C0BE797878787274C4F4BD0004700062C0BD2139
                3F3FF807B9B685693F85EE898A8A8AD3ED34393985F278777877C0F2F3F0F2F3
                F0F3F2F0F3F2F4F48670714A71F4F2F3F0F2F3F0F3F2F3F0F2F4F68974787478
                F6691F1EC4F074787478EEEDA2A2A3B8C707B995574C1F4CBDF3EDC4B7BE0477
                00057986F2EEF60004790044C4F60F1C2AF4C474747486F6F2EE72727171D2ED
                0C0C0B3FF6C072727279F676C0F674747874C1F6291B23232169F4C5777977EE
                ED243F6E7686BE8907E7B786F86C211A00000005686F85B8C60004C80030CDCC
                E6A7F86759F473717171EEB60E1CB70771727274C0070B0C1585ED7378787886
                ED23F0F2B77477787878BEC4F0C00478000EF676F07678787879EE6F1C1AEEBD
                04780012EE6F1F1DC4B974747472EE07F37071717071097000117272C0ED69A7
                A7BABAAC976E6085F2C07900087800057486F007C0000470000FEDB734213F43
                41443F3F3F3421B6F000048A0010C1EE212120F7EE7779787774777477770479
                0006777474C4F6860471000473747473067400267386F4F48977747878F46B1E
                20C4EE74787478EEED6EA6BAAAB8B8BDB6692AF7EDB77774777306770022BDED
                C4F479798679C4F41C0F21F6C474747486F4F4EE73727171EEBD0C0C0C21F4C4
                04720026F6C0BBF474747478C0F43720211F1F4DF6D3777877EEEE2E447686BF
                8695ED07B794B6633715000000054C6FA5B8B80004C60030C9CABA926E6456F6
                76707170EDF70C1CC4ED70727272C4ED0D0C0C86ED7374787889ED1D21B9F0F4
                EDC4B7777378747904780004F46BEE7604780006ED761A0FEEBD04780012EEF7
                1F1AC4B974747472EEEDF47071707172067700097371707072C0ED76860004F7
                0006B676B6F277740878000677B9EDF8C4B904700021C4F721392A3F3F454646
                393F3485F2898A8A8AC1F61B2021B6EE787778778689860004BE000889797774
                77D3F6860471078600607474747286F4F68978747874F6761A1BC4EE74787474
                EEEDA3A8ADBAAA87B8B66BF7ED7774777477747777777385BDED40C0F6798679
                77D3F61A0F21F4C474747486F6F4EE72717271EED2150C0C1CF4C072727274F4
                B9C0F674747874C4F4370420001769F4C5797778EEED2E5C76BEC1C1C1ECBE89
                94A95D2B150000000041636FA5C6C6C8C8C6C6C6BD9792666A55F676707070C0
                B60E1CB7ED4A70727286ED230C0EB707727474748907230F1C174C85B9EDF4F2
                07867174727474F476EE6F0004740056EEBD0E0FEDB978747874C4BD1D1AD2B9
                74747272EEBDF47171717277F4F4F2F0F3F2D271727272C4B7B6BDF7C4C4C0B7
                76D3C0747478787786C0BDD2EDEDC43F1CC4ED71707070C0072334393FB607B6
                F86B401CB6EE058A0036F4941D206FF477787778BEF4F3F0F2F3F4C579777474
                EDF6BE71737171F6F4F0F2F3F2F474747274C0EDF48974787478F0F71E1AC4D2
                0474001DEEED6CBABCD8BCB8A58076F4867474777373B7B7D207F1EDC02A17C4
                F40004790044C0F44C0E2AF48674747486F4F0F472727172D3F21C1A1A40F286
                74727277F469C0F474747874C1F6231A20212076F4C4797877EDEE2B5D77BEBF
                C5C4F1C5C5BEA946241500000054686FA5B6BCB8BCB8C8C8C9BC926E5431EE6B
                707070C0BD1B0F85F27071717272F4B61D56F2867274747486ED6FB6B907BDF4
                F4F81A76D2F48574727474F469F0767474747889F4F7B6F2777478747889F6BD
                B6F20474004472EEF7F48671727172F46D0F151AD2B772707272F0B6B6B707ED
                07BDF7F8F48972787889F2EDC4C4F7B64C1D1F21F8F47071707173F4B6212A3F
                F2C0C007F2F4F4B7EE89048A0036D3F4B6F8EDF48977787779F6461A1C20EDC0
                89747474F4F0D272717371EEF70D0F0FB7EE73747374C407F48978747874BEF4
                F7F8EDBE04740027D3076DA7BDE6D8BAA57FC4F474747774F7F2D20707B78544
                1C0F0EC4F47979777977F4EE6FB6F2000474003A86F4C4F67771727177F6851B
                156FF074727272B7F469B6F674787478C0F4694C4C340C76F4BE797778EFE03F
                5C76BBD3C5EDEDEEEEF7A74D471B000000704C6EB6B8A9BCD8ADBCCAB8BC977F
                5152D3BC70707086ED1B1C4CF6697072717277F0F2EDBE72737474748907B9F2
                B7BE7779C0F2856869F07674747278F423EE76747474787486D2C48974787874
                747489D2C4867474747272EEF8C4ED71727072C0F06D46B6F07371717277F26F
                F8B60407000EBDF7F686747878C4BD1B21BDEEED04F400156FF48670717070B7
                F40707EDC472737277C0EDB7F000058A002489C5EDC4F4F4D377787777C5F06F
                46B6EE89797774B9F2F8F47372717186F6F74668ED860474000DF26FF4897478
                74897489D2C4860005740027EDC4A3B6BAE7E6D8A97FD3F474747486F6F8151D
                EDEDF2F3F4F4F2C4F4797779797977C4D2C486000474000F77F476F4D3717271
                72BEF4EDBDED860004720027BDF4F4C4D274747874BEEDD2EDF4760BB7F4BE79
                7886F2C46367A1ACD8D8BC07D3C5BC6E69471B000000001E686FA3BCC6CABCC6
                C6B8ADBDF76E6452C00770707077F4231E21D2F771710572002D7472BE767474
                7489ED76F67374747472C0D2F2EDBE72747274BE0721F076747474BEB7747474
                787878747878B700077400457274F44C69F4B771727071BEEDEEBD7471717272
                EDB994BD0707ED0707F7B6EEB974747889F4F4F0077978787486F068BDF47370
                70717173B7B7747372737277F0F8F7EE8900048A003189898A8AC1F4F4B77877
                7477C4EDEE078979797773EDB62CEEED7273717486EDEE078674747472B9ED2A
                F689747874C5D20009740026F4B7B6F7BBD9E7E7D8A7F7F677747774C4F4F4F2
                BD7977797907EDC4F479797977C48977787705740016B7F42AF7F6BE71727172
                74B786747172727276F0F2F0047400207874787478BEF4760CB7F479797786F4
                85436EA9BCBCD8BCB3D8BDF76E6C431700000030686EA9BCBCD9BCBCCACAC6C6
                BCA4644E86F449707070F64D1A2086F6767171727072727277F4767274748607
                40EEED730B72000C74F0F846EE7674747486F6B707740003C0F6B7000674000F
                72C0074141B9F4B7717271717072700004720015C4EDB6A50707E0EDEDEDBDB6
                D2F477747878788979000478000974EDBD4668EEED7670000571000A73727372
                73070746F7EE048A01F401EE04890004F4EEF4BE0577009179797989797307C4
                524E6AF4C4747374727474737472747285F25842F489747874C4F4BE74727474
                72747485F2A3B6BD0707D9E7E7BCB6F4F0777477777486777986797776F476C4
                F479777979C4F4897778777474747307C44241EDF4BE71727172727271727272
                57EDB7EEEE747474787478747878BEF4761AC4F0797977B9F44D3B5D68A3F7D9
                E708D9BCA3A666431A000000007C4CA3B8CAE6E6BCD8CBE8E8CCBAB8805256F0
                94707070EEB6172139C4F4F77170717072BEEFF46970704A77ED2B85F2F0B74A
                707070727070707186EDBD4C68EE6B4A704A86F1F4B97374747472BEF1C0F4BD
                7374747274C0F176544F51BDF4ED8670717271727274B7EE07B6F7B8EDF1F1F2
                D9EDBDF7F7EEF4C077770578000C74BEEDC454536A6AEEF4B9730471000A7273
                73B7EDC46E68BDEE0477004AEEF6C0898978D20707F4D28674777879797977B9
                EDC464546A7EA5F0F4B77374747274727376BDED855358F4864A7171C0F4F4D3
                777272747185F2B7A7F7BBEDF1EDE7E7BCB6F7F4F4BE0477002279797773B7ED
                B73FC4F679797977C5F6F4C47774747448B7ED76686E68BDF4EE86710472002C
                704AB6EEB73FEEED71717474787477737377F6762AEDEE79797707ED213F6090
                92A7A7B6BABC07BCB66F451A000000A263F8B8E6E8E6E8EBE6E6E6BCBCA9A37E
                52C4ED707070C4BD1D344345B9EEF4070707EDED76EDF0F3F2F0F307407F7FD2
                EEF4F20707ED0707EDF2D2B6586F90EEF1F0F1F0F20785F2F4070707EDED856D
                B9F2F4070707F2D2B6F87F6A7F7F85D2F2F40707D207EDF007B7B6F7F707E7F2
                F1F1F4F2CBB880B6D2EEF4ED0707ED0707F2EDB97F7F7F6A6A7FBDEEF4F00707
                EDBDEDF007B76EF86FBDF2F3F0F2EFF2EDF404ED0060C468B6EEF4F407EDD207
                EDF2D2B76FF8A37FA57F7EEDF0F4ED07ED07EDF0EDB96F6A7E7FF4F2F0F2EFF2
                ED7FEEF4EDD207EDEDB7B6BABDE707EDF1EDD9D9F7F7F707F4F40707ED0707ED
                EDEDB7453FC4F479797779C4F6B6F0F407EDBDF0E08504B60035F8B6EDF4F407
                ED07BDF2EDC46B4C68EEF3F0F474787478C1F4F2EFF2854DF2C0797986F3863F
                454668A3A79292A7ACA3906F5D391A000000004C4C6F85F7CBE8ECE8ECE8ECE6
                BCBCBC676385F457707074F42B3A4E53537BB6B7C0B685546A6AF87F857FA37F
                7F7FA56B6A85F7B9B9C0F7B7856F6F7F7F97A3B6F7B6B6B6A3B6F8B6B7B9C4F7
                05B60048F8B9B9C4F7F7B6F7BCF7A7B6A9B87F7FB8B9BDC0F785A57FB6B8F7CB
                D9E4DDF4F2F3F4CBB8C687807FB6B9C007C4C0B9F7B6F8B6B887B880F7B6A3B6
                F7F7B9BDF7F7B66FA3B6B6A304B60030A36FA36EB607C4F7B66FF87F6F6FF7BD
                C407B9F7F8F8A3B6F7F7F7B6F7F7B6B6B6B9BDC4F7B7B66FA2A7A27F80A587A5
                047F005F6A7E85F7C4B9B680AABCD9BDEDF1EDEDF3EDD9BDF7BDF7B6B6F7BDC4
                07B9F7B6F86F6B68C4F679777979C4F44045F8B7BDB9B6B6F7F7BDBDF7F7F7F8
                F8F7B9BDC0B7856D6E6D6C63465DC4F474787478C4F4401A201FB6F4797979BD
                EE616F0006F800096FA3A792906C5D39150000000046686B9485B7B7CB08E8EC
                E8ECE8E6CCAD7F64C4ED707070F0942654647C7F7C808085807F7F7F80A5B87F
                B8F8B8B8B87FF87F87A57FB8F8F86F6FB885AAB8BDBDBDBAF7F7F7B604F7002F
                BDB6F7BDBDF7BDBDF7B6BDBDBCBDD9BBD8BD0707BDBDF7B67F7F807F807F8080
                8CCBC608EFF4F6F1F4F2CBC9CAB8B800048000117F80F8F8F7F7BDBD07BD0707
                BDBDF7B6F70006B60071BCF7BCF7BCBDBDBCB6B6A3A9F7B6F7B6F7B6B6A5BCA7
                7FB6A9B6A3B6A3B6F7F7BDBDBD07BDBDBDF7BAB6B6A3B6B6B6BA6FF8A3ADAD87
                AA8080AA8080807F80A5878087B8B8C6C6CBE7E7EDF2F1EDF107D9E7D9BDB6A5
                80A37FA5B6F7B6B685F86EC4F679797779C4F646686DF8B6B6F8BD0004070036
                BDBDBCF7A9B6A3A3A2A3A2A3A2A390906C66C4F474787478C4F43717193FC4EE
                797986EDB96FB6BDEDF2EDBDF7B66FF86F6E685D341500000028636994B795B7
                8695B7B9CB08E8E8E6CAAA7EB7F4857170C407237FA5AAAAAAB8B8AAB8B887AA
                B8C604B8000AC6F7B8B8B6B8B8B8B6C604B60016F7B8C6C6C6CBED07BCBDBDD9
                07BC070707BD070707ED0407002BEDBD07BDBCEDF2CBF2EDD9E0BDD9BBB8B6BD
                B8B8B88CCBC6C9CBCDCD08EFF3E7CDCBC9C6C68CB8B8AAB8870004B60009BDBD
                EDEDF2ED0707070004BD0027F7F7BCBDBCBD0707E70707BDF7F7F7BDBCBDBDBD
                BCBDF7BDBCB6B8BCBAA9F7BDBCBDBDBDE7EDED0004070053BDBDBDF7BDBCF7BC
                F7B6A3B6B6BCD8CAC6C68CB8C6B8C6B8C6C6B8CAC6C7CACBCDCDECF1EDF3F1F2
                F3EDD9E7E6BAAAB88CB8BD0707BDF7F7B6F8D2F479777977C5F46BF8B6F7F707
                07EDEDF2F3EDD9D9D9BCBC0006BA002BBCBABCBAA9A790BDF4F4BF7878C4F44C
                343357F3C17979F7EE4C63A7BCEDF3F207F00707BDF7F8684621150000000046
                4C6F76B6B786B7958695B786B7BDCBCBBCA47EC4F2577174F6497E80B8CACACA
                CBCACBCAB8B8CAC7CAC7BDB8CBCBCBC7BCC7CABDB8BDF7F7F7B8CBC7C9CBC608
                EDEDED07070705ED0025D9EDEDEDF0F1F0EDEDED07D9D907EDF4EDF4F1F1E7F1
                EDD9CBED07EDEFEDEDCBCBCCCDCDCC0004CD0007D4CDC9CAC7CAC70004C60017
                F7BDF7BDF7BD07BD07ED07EDF2ED07ED07BD07BD07E7070004ED0019E7ED0707
                E7E70707BD070707CAE7D9C7BCE7BCBDBD07D9BD070009ED05070019BDE7BCB6
                B6F7B6F7BCE6E6C9CBC9CBC9CAC9CBCBCBC9CBC9CC0004CD0061EFECE0EDF3F3
                F3EDD9E7E9BCB8CA0708EDEDEDBDBDF7B6D3F679777979C4F4B6B6F70707EDED
                F2F0EF08E7E7E7D9E7D9D9D9BCD9BCD9D8D9D9D8BCBAA9A390EDF4F0BEC1F64C
                3943B7F2797985F2856690A7BCD8E7E7EAF107EDBDBDF7B66E3F150000000028
                686D8595B7BE9586BEB799BEB7BEBFBEB785F885F0BD7071EDF7428087C6C6C6
                CACBE808C6CBCB0805CB00040807CBBD06CB0013BDBDBDCBCDCBCDCDEDED07F2
                EDEDF4EDEDF4F10004ED0022F2F407F3F0F3F2F1EDEDF1F4F4F4F6F4F4F2DDF4
                EDF0F207F2EDEDF408EDF0F3D40806CD0009CBCDCDC9CBC9CBC6C70004ED000D
                07EDBDED070707BD07EDEDEDF20004070027F0F2EFEDEDF2EDEDEDE7F3E7EDED
                CB07ED07EDE7BDBDCAE707CBEDEDE7EDF1EDEDEDF1EDF1EDF10004ED000507ED
                E7EDBD0006F70007BDD9E7E6CBCD080005CD01CC05CD0031EFCDCDEFECEAEDF1
                F3F2EED9F1EAD9BD0808EDF3F0F1EDBDF7D3F486858685C4F6F8B6BDEDEDF4F0
                EFCBC9CDE7EAF1E7EA000AE70028D9D9D9BCBAA990A3EDF4F4F4695D4CEDD279
                74EDC45D6EA7BAD8D9E6EAEAD9EAEAF1EDBDB6B668210000002963769486BE99
                BE89BF998ABFC5C5C58999867376BEF4F4F2F4ED47AAB8C7B8C6C7CBCB08CACB
                08E8080004CB0020080808CBCB08CBCB08CB07CBBD08CDCDCD08EFEDF4F4F4ED
                F4F4F3EDF4EDF2F104F40012F2EDF1F1F1F4F1F4F4F4F6F6F1F6F6F4F4EF05F4
                0003F2EFED0006F4003F0808CDCDCCCDCDCD08CDCBC9C908F1EEEFF2F0F3F2ED
                EDED070707BD0707BD0707EDF2F4F6F6F4F4F4F0F208E7F3EDEDCBCBEDEEF2E7
                E7BDCBE8EDE7CBEDF30008ED0003F3EDEF0004ED0009F2EDEDEDBCF7F7BDF700
                04BD0008D9E7E7ECEAE8E8CC06CD01E806CD0023EFF3F1EDEDEDDDF3F3ECE7CB
                08CDD4CDEDEDED07D2F2EDEEEDEEEDEEBDBDEDF0F208CC0004CD0037EAF1E7F1
                E7F1EAE7E7EAE7EAE7F1EAF1E7E7D8BCBAA7A790B6EDF46D6C76F4F2F4F4ED4D
                6CA7ACBCD9D8E7EAD9E9D9EAD9E9BCBDB6682100000000264C7685B7BE8A8A99
                BF8ABFBFBFC1BFBEBE9986767785B7B7B9B7B8BCBDBDC6C9CBCB08CBCDCB0508
                01CB05080046CBEF07080808CBCB0808CDCDCDEFCDD4EFF3F4F6F0F4F2F0F1F4
                F4F4F6F4F6F1F2F1F2F6F4F4F6F6F6F4F4F6F4F1F1F4F4F4F6F0EDF4F4F6F4EF
                F6F4F2F3F2F4EDCDCDC9CDD404CD0010C9CD08EDF0F3F4F1F4EDF0F4F3F4F2ED
                040701BD040701ED01ED05F60028F4F4F2F3D4CBCD0807D3F1CB07EE07F3F1E7
                08F1EDEDEDF3EDEDF3EDF2EFF2EDF1EFF1EDEDF1EFED08BD010705BD0006E7EA
                EAE8E7E808CD0004EFCDEFE806F3000BF6F3F3E7C9CDCDE8CDCDCB0004BD04F7
                00060707EDED08C905CD0003E8EAE70004EA0003E7F1EA0004F1002AEAF1E7EA
                E7E7D9D8BCBAA9A7A7BAA7A3A3B6F7B7B7944DA7BABCD8D9EAD9D9E9D9E9D9E9
                D9D9BDF84C1E0000000A68699489BE99BF8ABF8A05BF0019BEBEBEB79576B6F8
                F894F7BEBEBDBDCBCACBCD08CB08CB08CB00080801CB0708000BCB08D4CDE8CD
                EFCDE8CDEF0004F60021F4F4F6F4F4F4F6F4F2F4F4F6F1F4F4F4F6F6F2F1F4F2
                F3F2F6F6F4F4F6F4F4F4ED0004F40008F2F3F4F0EDEDCDC906CD001BC9CDCDC9
                F0F4F4F0F4F0F3F2F3F0F2EFF2F0F1ED07EDED07BD07070004ED01F401F404F6
                0024F4F4F008CD08ED08CD07D2F3EDE7CBEDF3F0EDF1F0F1F1EDEDF3EDF2EDF1
                EDEFEDF1F20704BD003A0707BD07BDBDBDF7BDF7F7BDBDD9E6EAEAEAE8E8CDE8
                D4E8CDEFCDEFEFCDCDEFEFEFE8E8E8CDEFCDEFCDCDCDC9C9CAC7B8F7BDBD0707
                07CBC9CC06CD0005E7EAF1EAE70006F1002DE7F1EAF1F1EAF1F1E7E7D9D9BCBC
                BCF7B6A7A3B66F6D696D7776BABCD9E6E7D9BDD9E7D9E9D9D9EAD9BDF8631A00
                0000000B686D86B7BEBE8A99BFBF8A0005BF0016BEBEBDB7B6F7B6B6B6BDC0F7
                BD07CBC7CBCB0808CBCB08080044EF0708CBEF08ED0808CB080808CDCDE8D4CD
                D4CDEFF0F6F6F4F6F6F4F6F6F4F0F4F1F1F6F6F4F6F4F4F4F6F4F4F4F6F6F6F1
                F6F4F2F3F4F2F3F4F6F4F6F4F3F2F1F1F6EF05CD01E805CD001508F4F3F2F4F2
                F3F0F4F2F3F4F4F2F3F0F2F3F0ED070005ED000807ED0707EDEDF2F404F60024
                F4F4EF08EFD4EEE7E7CB07EDF3EDF1F0EDF2EFEDF1F3EDF1EDF1EDF2F1F0F3ED
                BDBD070704BD01F706BD05F70016BCBDE7EAECEAE8E8EFEFE8E8EFEFEFCDCDEF
                E8EFCDEF05CD000DEFCDCDC9CAC6C6B8C6CBCAC9C90008CD01F101E705F10031
                EAF1F1EDF3F0F1EFF1EDEAEAEAE7EAE7D9EDED07F7B6B6F7A3F8A3AC97B6B6B6
                BCD9E7F3F1E7EAEAEAE7E9E707F7B6461500000000094C6F8695BEBE8ABF8A00
                07BF0006BDC0BDBDF7B704F7000407BDBD0704CB0029080808CB080808EFCBEF
                0808EF080808EF08EF080808CB08CDD4CDEFD4E8CDD4F3F2F6F0F2F6F6F4F400
                04F6000AF4F6F6F4F1F6F2F3F4F404F60015F4F6F6F2F4F4F4EDF6F0F4F6F2F6
                F4EDF3F1F4F4080005CD01C904CD0018D4EFF2F0F3F0F3F4F4F4F3F0F2F3F0F4
                F3F4EFF2EFF4F4F204ED010701ED05070004BDEDF2F404F6001DF4F40808CB07
                CBF1EEF3EDF3EDF4EDF1EDEDF3EDEDF1EFF1F0F4F307070004BD0007F7BDBDBD
                F7BDBD0006F707BD000CE7F1F3ECF1F3F3F1F1ECEFE805CD0004E8D4E8EF05CD
                07C901CC08CD01E804F30034EAE7F3F1ECF1EDF3F2F3F2F0F1E7F1EAEAE7EAE7
                EDEDEDF7BDF7F7B6B6A9D8BCF7BDBD07BD07D9D9EAD9E7D9D8EAF1F0BDB6461A
                0000000768F8B6B7BEBF8A0008BF0007C0BBBDF707BDBE0004BD000B0708BDCB
                CB08CBCDCBEFCB000808001BEFED0808CBEF08EF080807CBEFCDE8CDEFCDE8CD
                EFEFEFF4F6F6F60004F40003F0F6F40004F60013F4F1F4F2F4EDF6F0F6F6F4F6
                F1F2F6F2F4F6F60004F40007EDF0F4F4F1F4F40005CD01C904CD001DD4CCEFF2
                F3F0F2F4F0F1F0F4F2F3F0F3F4F0F4F2F3F4F4F0F4F3F0F3F00004ED010701BD
                0507002FEDEDF4F4F4F6F0F1F0EDEFEDEFF1F2EFF1EDF3EDF2EFF1EDF0F1F2ED
                F4F3ED07BDBDF7BDBDBDF7BDBDE7BDBCF7F7F70007BD000A07BDBDBD07E7F1D9
                DDE404F1000AE8CDCDE8EFCDEFCDCDE807CD0003CCCDC90007CD003DE8CDCDCD
                CBE7E7EDF1EDE7F3F6F3F3D9F107EDE7E70707E7E7F1ECEAEDF3F0F30707BD07
                F7F7BDBCF7BDBDBD07BD07BCD8BCEAE9D9E9D9F4ED07B6461A00000000084CA3
                B6BDEDD2C4C105BF0017BEC1BDC0BDBDBD07BDC0C4BDBD0707CBCBCB08CBCB08
                D4000508000CEF08EF0808EF080808EDEFED0408003DEFCDD4CDEFD4E8D4E8CD
                EFCDEFF6F6F4F2F0F4F2F6F0F4F4F6F4F3F3F1F3F4F6F6F2F4F4F4F1F4F1F1F3
                F4F4F6F6F4EDEDF4F4F2F1F0F6F0CD08CDCDC90004CD0024E8CD0807EDEDEDF3
                F0F1F4F2F0F3F0F2F4F2F3F0F4F4EFEFF3F0F3F4F0F1F0F3F0EDEDED0707002C
                BD0707EDEDF2F4EDF2EDF2EDEFF2EDF0F1EDEDF4F1F1EDF3F0F1F4EFEDF7BDBD
                BDF7BDBDBDF7BDF3BDBDF1D905BD010706BD000EF7BD07F1F1F1DDDDD9F1F1F1
                ECE813CD01EF07CD0025EDF0EDEDEDE7D907BDD9E707E7BCD9BDD9D8BDF1D9F3
                F6F6F3F2F1F2F3E4EDEDED07F7F7F70004BD00100707F8F8BAD8E7EAD9EAF3ED
                07B6461C0000001063F8F7BDF1EDEDED07D2C5C0C2BFBDF704BD001007BDBD07
                C407070808CB0808CDCBCBEF0408001FE8EF08EF08EFEF080808EF08EF080808
                EDCDD4E8EFE8CDEFD4CDEFCDD4F3F40008F606F40016F6F4F6F4F6F6F4EDF2F3
                E4F6F4F2F6F4F4F6F4EDF2F404F601F401EF07CD0006E8CDD4CD08F006ED000D
                D3EDEDF2F3F0F3F0F2F3F4F4F20006EF000AF4F4F0F3F2F3F0EDEDED040701BD
                070704ED0013F2F6F4F4F4F0F1F0F1F0F1F0F1F3F2F307BDF70004BD0011F7F7
                F7D9F3BDE7F4BDBD07BDBDBD07BD070006BD0003F7BCD90007F10006ECECEAEC
                E8E80ACD0003EFCDEF000ACD0025EDD5F0D5F007EEF0EFF0D9EDD9D8C7CCD8D9
                D9E7BDD907E7EFF2D9EDEDD9D9BD07EDF2EFED000507000FF7A3F8F8A3BCD9EA
                EAD9D9BDB6681F0000000010686FA5BCD9E7E7F2EDF3F6F4F4EE070704BD0034
                070707BDD207BDED08CBCBCB08CB08D4E80808D4EFD4EFEF08EFEDEFE808EF08
                EFEF080808D4E8EFF3F3F3E8EFE8D4E8CDF4F3F204F60003F4F6F60004F40007
                F6F4F2F3F6F4F40007F60012F4F3F4F2F3F4F6F4F6F6F6EFEFF4EDEFCDC904CD
                01D404CD000A08F4F2F3EEEDED08EEEF05ED0008F4F4F2F3F4F0F3F004EF000D
                F3EFEFEFF4F0F4EFED070707BD000507000ABD070707BD070707EDF404F6000A
                F4F4F4F0F1EDF2EFF3ED04BD04F7000FBDBDF1F4E7F1F3BDBDBD07BDF1EAF100
                04BD000CF7F7F7BDBDBD07E7E7E7D9D905BD0006D9EAECEAE8E804CD01E80ECD
                01D304F0001907EEF0D5F0BDECBDD9CACAD9D908E7EDEDE7D9E7F1DBE7F1D700
                04D9000807F3F0F2F3EEEDED06F70009BCD8E6EABCBAA3681F00000000154C7F
                A58CC6C6CAE6E7F1F3F4F6F6F6F4F4EEED07BD0006070017CB080808CD08CD08
                CDEFEFCDE8EFE8EFEF08EFEFEFD4080004EF00080808EFE8D4EFF3F605F3000B
                CDEFF3F4F4F6F2F6F6F4F00009F604F4000BF6F4F6F6F6F4F6F2F3F2F20005F6
                000BF4CDCDD4E8CDCDCDD4CDE80006CD000FF0F3F0F4F4F3F0EFEFF3C4D3F2EF
                F20005ED0012F2EFF2EFEFCDF4F3F4EFEFEFF4F0F0F2EFED0907000CBD0707BD
                0707EDED07EDF2F404F60006F4F4F0F2F3F205F705BD0011F3F107F6E7BD07BD
                F707F307F1E7F7F7F70004BD05F70012BDF7BDF7BDF7BDF7BDF7BDBDE7EAECEC
                E7E80CCD003CE8E8E7D3F0D5D5EFE0D5F0F0ED07F1BCD9E6D9D9D9F1BDD3D5F0
                F0F0DAD9F1DDDDD9D9F1F1F1F0F2F3F2EFF2F3F0E407BDBDF7BDBCD8D9D8A790
                5C1D0000000F636F87B8C6AFAFC8AFC608E7EAF1F30004F60015F4F4F0F1EDBD
                ED07CB0808CB08E8CD08EFE8D4E8D40008EF01E805EF001C08EFEFD4E8EFF6F3
                F3F6F3F3F3D4EFEFEFF4F4F6F6F2F3F2F4F4F6F405F60016F4F6F4F6F4F1F6F6
                F6F4F4F4F6F6F0F4F6F6F6F4EF0805CD0018EFEDF4F0EF08CDE8D4EFEDF4F2ED
                EFF2F4F4F4EFEFF4F4F409ED001007EDEFF4F0EFEFEFCDEFF0F3F0F3F2ED0707
                0009BD07BD07ED070707ED000607000AF2F3F4F6F6F6F4F4ED0706BD000707BD
                F6E707F3070004BD0005F1EDF7F1ED0004BD0005F7BDF1BCBD0008F70010BDF7
                BDBDBD07BDBDF7F7BDE7EAEAECE704E80041EAECECEAEBEAEAE7EEEEEEF007ED
                F0D5F0EFE7EDD9D9E6D9D8BDF1BDD3D5D5D5F0E7E5E5E5E4BCBCD9F1F0F2EFF2
                EFF2F0F1F2D8EDEDBDBDBDBAD8D9D8A990451E00000000064C7FA5B8C6C604C8
                0012F4F4F4F0E7F1EAF1F3F6F6F6F4EDF0EDED0704080009CDCD08CDEFEF08EF
                D40008EF01D405EF0036D4EFE8EFF3F6F3F3F6F3F3F3E8EFD4EFEFF3F6F4F1F4
                F2F4F4F4F2F6F4F4F4F6F2F4F6F6F4F6F6F4F2F6F0EDF6F6F4F6EFD4EFEFEFD4
                05CD0018EFF6F6F4F4F6F208CDD4F4F4F3EDF4F2EFEDF2F3F0F4F4F404070004
                EDED070704ED01EA01F104CD0014EFD4EFF3F0F2F3F0ED07BD07BD070707ED07
                EDED05070003BD07BD0005070012EDF4F4F6F6F6F4F2EDED07BD0707EDBDD9F6
                04BD0016F7F3D9BDF3E7F7F7BDF7F7E7F3F7F7BDF7BCF7BDBDF706BD01F705BD
                0025F7F7BDBCE7E6E7D9E6BCBDBCBCF7F7BC0707E7EDEDE7EEEEF0F0D9EDE7D8
                CBCAD9D8D9E7ED0004F00021D5F1E2E5E5D7CBD7D9D7DFE4F2F2F3F2F3F0F1D7
                F3EDE7BDBCD8D9E9BCBA90451E000000000B637F87B8C6C8AFC8C6C9F40004F6
                0019F4F4F0F1EDF1F1F3F4F4F2EFEDF4F0EF0808EFCD08EFEFEFE80009EF01E8
                01F004EF000BD4EFEFEFF3F6F3F3F6F3F30006EF06F4000EF6F4F6F6F0F4F4F6
                F2F6F4F6F6F004F6004EF4F4F4F6F4EDF6EFEFCDD4E8CDCDEFCDD4EFF4F6F6F4
                EEF6F4F0E8D2EDEDF0F4F4F4F0F4F4F2F6F6F4F4E707E70707BD07ED07EDEDED
                F1E7C9CDCDCCF0CDCDEFEFF3F0F2EFED07BDED07ED0707ED050701BD04070005
                BD07BDBDBD0004070018EDF4F2EFF6F6F2ED080707BDBD07F7F7BDBDBDF307BD
                F3BD05F701F101F105F70007BDF3F1F1E7F7F70005BD0006F7F7F7BDF7BC0DF7
                003BBDEDE707D9ED07EDEDEEEDBDF1BDD8C9CBD9E7EFE7C4F0D5F0D5D5EDE4E4
                E40708EDE7E0BBDFDFDFD7D8D7EADAD8E0EAD707BCD8E7D8D8A96E431E000000
                000A4C6FAAB8C6C6C8C8C8CD09F6000EF4F4F0F1F1F1F3F4F4F4F2F6F2ED06EF
                01D413EF0008F6F3F6F6F3F6F3E805EF0017F4F6F4F4F6F4F6F4F4F6F6F4F4F6
                F6F6F4F6F6F4F2F4F40004F6000FF4F4F6F008CDEFE8CDCDD4CDCDE8CD0006F6
                0034F0EDCCEFF4F4F2EFEDF2F3F4F4F0F6F6F4F3E7E7E7DDF1070707ED07BD07
                F2EFD3EDCDD4F0CDCDEFEFEFF0F3EDF0EDED070707ED0407000ABD07BD070707
                BD07BDBD07070009BDBD0707F3F4F3F2F20004ED00130707BDBDF7F7E7F1F1E7
                F7F7BDF7F7BDF3E7F70004BD000B07F3BDBDF3BDBDF7F7F7BC0010F704BD0016
                07EEF0F0EDE7D9BDBDBCE707F107E7C7CBD9BCF1BDD305D50020ED07EDEDE4E4
                E5E7C2BBE3E3DF9CDBE2BAE0E4DDDAD907ACACBCD9F7F86D3F1A0000000A637F
                87B8C6C8C8C6C8EF0DF60007F4F4F4F3F1F1F30004F40005EDF2F3F0F30007EF
                01F404EF01F306EF0008F3F6F3F6F3F3F6F306EF01F301F404F6000BF4F6F4F4
                F4F2F6F6F6F4F60004F40021F0F4F4EDF6F4D4CDEFEFCDEFCDCDCDE8CDEFE8D4
                EFF6F6F6EDF6F6F6CDCDF2F0F30005F40016F0F1F4F6F6F4ED07D9E7F1F1E707
                ED070707BDF4EFED04EF05CD0008EFF4F0F3F4F2EDED040701BD040704BD0507
                001BEDEDED07BD07BDBDBDEAEAEAECF3F3F4F2F6F6F2070707BDF7BDBD0005F7
                0017BDF3F1EDBDBDF7F7BDE7F3BDF7BDF7F7BCF7F7F1E7D9BC0004F70005BDBD
                BDF7F70005BD003EF7BCF707EEF0D5F0EDEDF2EDED0707D9D9D9D8D9D8BDF107
                D3F0F0D5F0F0BDF0D5D5E8F1E5D7C2DE9FE3DED6D7DAB69FE3E1EA93ACACACBA
                A7BAF8683F1A0000000A686F80B8C6C6C8C8C8F411F60007F4F4F4EFF1F1F300
                04F40005F6F4F4F4F00007EF01F007EF0008F3F6F3F6F3F6F3F309EF0069F6F6
                F6F4F4F4F2F4F4F0F6F4F4F4F0F4F4F1F6F6F6F4F4EFE8CDD4E8EFCDCDE8D4CD
                EFCDEFCDEFF6F6F6F4F6F6F408EFF0F1F0F4F2F3F0F4F4F2F4F6F6F0F1ECF108
                EDEDEAD9D2D307BDEDF6F4EFF4F4F0D4CDCCCDCDD4E8CDEFF2F4F3F00707BD07
                BD0707BD07BDBD0005070007ED070707EDF4070004BD01D906EA0015E9EAF3F4
                F2F3EEEDF1EDEDBDBDF7BDBDBDF1F1F7F10004BD0013F7F1EDF7BCF7BDF7F7F7
                BDF6BDD9F3BDF7BDF70006BD01F701BD05F701ED04F00036EDEED5F0C1EDEDC4
                EDF1E7E7D907E7E7EDD3EED3D3EEBDEED5F0D7E5DDDEB7C2BEC2DED6B6BABB9F
                9FE2DAAC97A3A7BAACA7A76C3F1A0000000C4C7FB6B8C6C8C8C8C9EDF4F40EF6
                000EF4F3F2F4F1EFD4EFEFEFF3F4F4F405F60007F4F4F0EFEFEFF30006EF0007
                F4F3F6F6F6F3F60004EF01F305EF05F60004F4F6F6F604F40023F2F4F2F4F0F6
                F0F4F4F3D4EFEFEFE8CDD4E8D4EFE8EFCDCDD4F4F0F6F4F4F6F6F4CDD20005F4
                0016F0F3F2EFF2F6F6F4F2F0F2F1F1F3E707E7D9E7EDEDED04F60018F4F0F3EF
                D4E8CDCDCDE8CDD408EDEDF2EDEDBD07BDBD07BD04070003ED07ED000507001D
                ED07BDBDF7BDE7EAEAEAE6EAE7EAEAE9EAE9EAF3F3F4F2EDF4F4F407070004BD
                0008E7D9F7F7F7BDF3D907F70005E7F3BDBDF10004BD01EA01BD07F7003FBDBD
                BD07EDF0F0D5F007EEF0EDC1EDE0C5D3F6F6F6E7D9D9BDE707E7E707E7C4D5F0
                EDE2E5DAC2F78A89F7B7B6B797BCBA98D79CC4CBBA97A6BAA7A66C4315000000
                000E636F80B8C6C6C8C8CDEDF0EDEDF40BF605F4000DF0EFEFE8EFD4E8EFF3F3
                F3F4F40005F60004F4F4F4F006EF0007F3EFEFF3EFF6F30009EF01F401F406F6
                002CF4F6F6F4EDF4F4F0F6F4F4F4EFEFCDD4EFCDEFEFCDCDE8D4EFCDEFCDEFEF
                EFF4F4F6EDF4F6F6EFCDF0F3F0ED05F40013F3F0F6F6F4F3F1F1EDF1E7EAEAEC
                EDE7D9E7F40004F6000EF4F0F4F4F3EFD4E8EFD4CDCDCDD405ED000707BD0707
                07EDED0005070004BD07070706BD01D905EA0011E9EAEAE7E6EAE9EAEAEAF1F3
                F6F6F6F4F20004ED010701BD04F70006D9F3BDF7F7F704BD000DF1F4F10707BD
                F7D907F1BCF7F70005BD0016F7F7F7BDEDE1EEF0ED07D5F0EDEDEDD3C1E0F6F6
                F3E705D90024BCBDD9D9C4D5D3D9E3E5D6C298C3C2DFB6EDEDBABDD207BCBE8B
                8DD2BA97BAA9A66C3B1500000014686FB6C6C6C9C8C80807F2F3EDF2F1F1F2F6
                F4F405F60006F4EDF1EDF6F405EF01E804EF0005F3F3F3F4F40006F60004F4F4
                F0F00BEF01F301F004EF000CF4EFF4F6F6F2F6F6F4F2F4F406F60018F4F4F4EF
                D4E8EFCDEFE8CDEF08EF08EFCDD4E8EFCDEFF1F404F60004F4D4EFF204F40020
                EFF2EDF0F2F4F6F6F4EFE7E7EAEAEDF1E7E7F1ECF1E7F2F0F4F6F6F4F0F4F4F4
                05EF000DE8EFE8CDCD070707ED07ED07ED000A07002FBD070707F7F7F7BDD9EA
                EAE7E7E7EAEAE9EAE7F108EAE7EAE9EAEAF1F3F6F6F4F4F2EFEDEDF4ED07BDF7
                BDBDF7BD070004BD0030F3E7BDF7F7F7BCF1BDF1BDBDBDF7F7F7B6F7F7B6F7BD
                070707EDE7EEEEF0D3D3D2D3C4E0F6F3F3BDD9BDD3EF07D9D8D904E4001DD6E5
                E49DC09FE39FDEBBE0E0B788CED2BBBE888D0792A7A9ACA76E3F150000000020
                4C6EBACAC6C6C8C9C90808EDEDF3F3F1F3F2F3F2F3F4F4F6F4EDF1F1F3F6F0E8
                0BEF0007F0F3EFF4F3F4F40005F60005F4F4F0F3F00006EF0003F0EFF30006EF
                0005F4F4F4F6F60004F405F60026F4EFF3F0EFEFE8EFEFEFD4CDEFF0EDEDED08
                EDEFEFCDEFCDF3F6F6F4F6F6F4EFEFE4F1F1F1F204F40023EFF4F6F6F4EAEAEA
                ECE7EDEFEDF1F1EAE4F1F0EEF0EEEEF0F2F0F3F2F0F3F4F6F6F0EF0004CD0004
                08EDEDED090701BD050704BD0003F7BDE90007EA01F106EA0016E7EAD9E9EAE9
                EAECF3F3F6F6F4F4F6F6F6F4F4EEED0706BD0004F3D9BDD904BD0CF7003DBCF1
                EAE7D907BD07EDEEEDEDEDF0C4F3F6F3D908E7BDD5D5F0D5F0EDE4E5E5E5D6DB
                DBBBBBB798DEDED6DABBBEC088D2B78B8BCEBD92BABAA36E6F431A0000000008
                686FBCE6C6C9C9C804C90012CD08EDF1F1F4F1EDF3F2F2EFF4F4F1F0F4F608EF
                0010F3F4EFEFEFF4EFEFF4EFEFF3F4F3F4F207F4000CF0F3F0EFEFF3EFEFEFF0
                EFF405EF0006F6F6F6F4F4F405F60005F0EFEFEFE80004EF0018CDE8EFF4EDF4
                F2F3F2EDEDEDD4CD08EFEFEFF4F6F6F3D4EF04F10005DDF1F1EDF20005F40027
                F1EAEDEAE7E7F0EAF1E7E7F0F3F6F6F4F4F0D3EEF2F3F0F3F2F4F6F6F6F0EFCD
                CDE8CD08EDEDED0004070012BDBD070707BDBD07BD0707F7F7BDF7D9EAE90AEA
                0011D9EAE7E7E9EADCE9EAE9E9EAE9EAECF3F30008F6000AF4ED07BDBDBD07ED
                F1F30BF7001CBCF7F7F7B6D9DDF1DDF1EAE7D9BDBDE7D9F3F3EDE7EFE7E7F3D9
                D2F004D50022EDEAEDDDDBD607D8D6DEDEC2C29DD6DAD6958D8B07958B8DCEBB
                A6BABCBAA368391A0000001E636FBCCAC6C6CCC9C9C9CCCDC9CDC9EF0808EDF3
                F2F4F3F2F0F1F4F4F6F406EF0015F0EFF3F3F4F3F4EFF3F0F3F0EFEFF4EFF3F1
                EEEDED0006F40010F2F4F4F0F4F0EFEFF3EFEFF3EFEFF3F004F40006F6F6F4F6
                F6F007EF0035D4CDEFEFEFF4F1F1EDF3F4F3F208E8EFEFF2F4F0F3D4EFEFEFED
                F1F1E4F1F1F1E4F1F1F1E7F1F2F3F4F4F4F3F1F1D5EAEAF1EDF0F40004F60010
                F2F0EEE1F0F1F0F3F4F6F6F6F4F3F0EF04CD000308EDED000507000DBDBD0707
                07BD07BDBDF7F7F7BD0009EA000CE9EAE9EAE9EADDEAEAD9DDDD06EA0006ECF1
                ECF3F3F309F60004F4ED07BD06F70003BDF7BD0009F701D906DD0036F1EAD907
                BD07F3F1BDE7BCF3F3BDD3D5D5D5F0F0EDEDEDF1DAE4E0DCE9DCD8D6BAD6D6DA
                D6B789BEBD89B78BC7BA92BABABAA760391B0000002268A3BCB8C6C9C8C9CCC9
                C9C9CDC9CDF4F4F4EFEF08EFEFF0F6F6F4F4F6F4EFEFEFF304EF0018F6F4EFF3
                F4F3F0EFF4F3EFF4EFF4F4F2F3F2EDF2EDF1F0F304F4000BF6F6F6F4F4F0F0EF
                F4EFEF0006F40006F6F6EFEFF0F306EF01E805EF0016F6F3F1F2F3F1F4EDEFEF
                EFF4F4F4F6F4F4EF08EFF1DD06F1000BEAE4F1E4F1DDEDF1EDF2F00004F40004
                F1F3EDF105F6001EF0F4F0EED3F2F3F0F6F6F6F4F4F4F0F3EFCDCDCDC908EDED
                070707BD070705BD00060707BD07BDBD06EA0012E9EAE9DDE9EAE9EAE9EAE9EA
                DDDDEAEAEAF107EA01EC05F308F60006F4F4ED07BDBD06F70007BDF7B6F7B6F7
                F7000ADD0033EAEAD9BDBDD9BDF3F6F107EEF0F0D5D5D5BDEDEEEFDBE5E5E4DD
                DCDCDCB4D9D7D697DED7BBBA95868ABD9297A9ACA9A75D391E00000000054CA3
                B8B8C60004C90015CCC9CDC9CDD4F6F6F3F2F4F4EDD4E8EFEFF4F4F6F40006EF
                001FF3EFEFF4F3F4F3F4EFF4F3F0EFF4EFF4F3F2F2F3F0F3F2F0EDEDEDF0F1F0
                F40006F6000CF4F4F0F0F3F0F6F6F6F4F6F410EF000BF4F3F4F3F3F3F4F1CDD4
                F30004F6000EF0F2F3D408F4F2F3E4F1E4F1E4DD06F10007DDF1DDF1F1EDF300
                06F4000AF6F6F6F4F3F2F3F2F3F006F40018F0F4F3F4F2EFE8CDCDC9CD08ED07
                0707BDBDBD0707EDED0704BD000CE7EAE9EAE9EAE9DDE9E9EAE904EA0005E9EA
                F1EAF10008EA01F104EA0009E9EAEAEAF1F1ECF1F30007F60009F4F4ED07BDF7
                F7F7B60004F701B601BC0CDD0031F1F1EAE707BDF1E707C5EED5F0D5F0BDEED5
                EDD7D7E2E3E5E5E2DDDBD7D79CBABBBBDEB6BABAB69792A7ACBAA7905D341E00
                0000001C63A3B8B8C6C908CDC9CCCDC9CCCDEFF6F4F4F3F1F0F1CDD4E8D4E8D4
                06EF0026F4EFEFF0EFF3F0F3F0F3F0F4EFF4EFF4EFF6F4F2F4F4F2F0F2F2F3F4
                F1F2F3F2EFEDF2F4F4F404F6000CF4F4F4F0F4F0F6F4F0EFEFF30CEF01F405F1
                000FF3F2EDEFEFF4F6EDF4F6F4F4EDCDF00004F601F404F10006E4F1F1DDF1E4
                07F1003AE4E7EDF2F3F4F4F6F6F4F0F3F0F4F0F4F3F4F3F0F4F3F2EFF2F0F3F0
                CBCCCDCDC9C9CB070707EDEDED0707BD0707BDBDF7F7EAE9DDD9E9E9EAE907EA
                0011F1F1EAF3F1F1EAF1F1E7E7E7EAE7E9E9E70004D9000AE7D9EDE4E0E0D9E7
                F3F308F6000BF4F4ED07BDF7B6F7B6F7BC0006DD0037EAF1F1F1DDF1DDDDDDF1
                EAE7D9D9BDBDBDE0D3D3EDBDD2D5E0D7D5EE07D7D7E2E3E5E5E5DABAEDD7BAA3
                ACACACBA92A997A690905D341A000000001C4CA387B8C6C9F4F4F4F00808CDCD
                F4F4F1EDF2F6F2EFD4E8D4E8EFE807EF0029F0EFF3EFF0F3F0F3F0F4EFF4F4EF
                F4F0F6F2F4F2F2F2F4F2F4F2F1F2F3F2F3F2F2F3F2EDF3F0F3F4F40005F60009
                F4F4F0EFF4EFEFEFF3000AEF01F406F1001AF2F0EFEFF6F6F4F4F4EDF6F0E8F4
                F6F6F6F4F6F6F6F4F6F1F1E407F1000DE4F1DDF1E4F1F1DDEDEDF1F0F20004F4
                0017F3F2F4F4F0F2F3F4F0EDF2F3F4F1E7CACAC9CCCDCD08EF0004ED001A0707
                07BDBDF7F7F7BDBDD9D9E9EAEAEAF1EAF1EAF1EAEAE7E7D904F1001DE7E7EFD4
                D2CB07CBD9E7EDD4CBCBCBD2D0CBEDEDEDBDBDE0D9D9EAECF30008F6000CF4F4
                ED07F7F7C5F2E4F1DDF10EDD002AEAD9D9BCF7BCD9BDE0F0D4D9C4F0D5D5F0D6
                D907D7D7E29CC0F7BDBA94A7A7BA97A792ACA7A66D5C39170000001B68A3A5B8
                C6CDF4F407F6F4F40708F4F4F1F1EDF3F6EFE8D4E8EFD40004EF000BF0EFF3F4
                F4F3F0F3EFF4EF0006F40007EFF4F3F4F4F4F20004F40014F2F3F2F3F4F3F2F3
                F2F4F2F4F2F1F2EDF3EEF3F404F60007F4F4F2F0F4EFF00009EF001BF3F4F1F1
                EDF1F1F4F4EFEFEFF6F4F0F2F4F4F6EFD4F4F6F6F4EDF00004F40008F6F6F4F4
                F2F1F1E406F10004DDF1E4DD05F10016EDF2F3F4F0F3F0F3F4F4F3F0F2EEEEED
                F0F1D9D9070805CD0005EFF3F0EDED0004BD0011F7F7F7C4C5C5C407EDE7E7EA
                F1E7E7D9D90006E70005ECD9E7D9080004D40006D2C5C5C5D4D505D4000ECDC5
                EDED080707BDBDE0D9E7ECF30AF60007F4F0EEEEE1EEE40010DD0028F1EAD9D9
                BDD9D3D5F0D609D5D5D5EDD6C5D5D5D5D9BB88B9C7BA929292BAD9BAF8A7A6A7
                905C341A0000001A4C7FB6C6C608F6F4F4F407F0EDEFF4F3F2F1F1F2F6EFD4EF
                D4E805EF0003F3EFF00007F401F001F609F4005CF2F4F2F4F2F4F4F3F2F3F3F4
                F2F4F2F3F2F4F2F4F2F4F4F2F1F2F4F4F6F6F6F4F6F4F4F4F2F4F0F0F0EFEFEF
                F4EFEFEFF4F4F1F1F1F2F4F1EFEFF3F0F2F6F6F4F4F4D408F6F6F6F4F0D5F0D5
                F4F0F4F4F4F6F6F6F4F3F1F1F1E4DDE409F10012E4F107EDF2F4F4F0F3F0F4F2
                EDEEEEF2F3F104E7000CD9CBCDCCC9CDCDF0F3EDED0704BD001F07C5D3E1D3E1
                C5D3CB07F1ECE7F1E7D9D9D9BD07E708EDE7F1E7D2D2D3D3D30005C50018D3D4
                D0D4D3C5C1C1E1E1D2ED07CB0707BDBDE7F1E7F1F3F308F60006F4EDD2E1EEE4
                12DD0024EAE4EDE0EDD609D5D5D5E79C09D5D5D5D9BEB98BBDB6929292D6BAD9
                BCBABAB69044391500000015636F87B8C6EFF6F2EDEDF6F4EDEFF2F3F4F4F4F6
                F4000BEF000DF4EFEFF6F4F2F3F2F4F4F4F6F60004F401F604F401F205F40018
                F3F2F4F2F3F3F4F3F2F4F2F4F4F2F4F2F4F2F6F6F6F4F6F404F60008F4F6F6F6
                F4F4F4F006EF0029F4F6F4F3F4F0EFE8F0F3F0F6F6F2F6F4CDF0F6F6F6F0F0D5
                F0F0F4D5F0D5F0F6F6F4F4F4F2F4F4F1F30009F10028DDE7DDD9E4E7EDEDF4F2
                F3F0F3EDF0F2F4F0EAE7D9BDD9D9D9BCCBCAC9CCCDEFF0F1EDED070707C405C5
                0013D3D2E8CBCBCB08EAEAE7E7EAD9C4C5C5C4C4E00004C40005C1C1C2C1C500
                04C101C306C10018C5C5C5D3EDEF08ED07CBBD07C7BDBDEAF1F3F3F6F3D3F2F4
                05ED0003F2F1F1000BDD01DC04DD000BDBE2E2D7D6E0D309D3DABB0004D50014
                D6B788B907A3ACACA7BDBABBBAD9E0BAA75D36150000001B687FAAB8C9F4F4ED
                F4F0EDF6EFF3F0F4F1F2F6F6F0F4F6F4F6F4F00005EF0015F4EFF4F1F4F3F4F2
                F3F4F4F4F6F6F4F4F6F4F4F4F20006F401F204F40003F2F4F30005F40014F2F4
                F2F4F4F4F2F6F4F6F4F6F4F6F4F4F6F4F4F404F6001DF4F4F0EFF0F3F0EFF0F3
                EFEFE8EFEFF4F4F6F6F0F4EDE8F0F6F6F6F0F40005F00018D5D5F0F6F6F4F2F4
                F0F3F4F2F4F4F6F4F1F1F1E4F1F1E4DD05D90011DBD9E7EDF4F2EDEDEDF2F3D9
                BCD9D8D9E60004D9002ECBCBCDE8EFF4F0F3BDBDBDD3EEE1D3C5C5C1C5D2D2D4
                08CDE7E7D9E7E7E707C5C5C5C1C0C0C0C4C0C0C4C0C2C0C006C107C50020C1C5
                E1E108ED08CBCB07CB070707BDD8F1EDE0E1E0C4EDF2F3F2EFEDF4EDF1E70FDD
                0021DBD6DEE2D7D7DBD6BBD3D5D5D3BBBE88B9BDA7ACBABAAC92A7BA92BABA94
                5C3415000000001C4C7FB6B8CBEDF6F407F4F4F408D4EFF4F4F6F4F6F0F4F4ED
                F6F4F4F205EF0007F4F3F4F4F4F2F30007F40007F6F4F4F6F4F4F20004F401F2
                0AF4001DF2F4F2F4F4F2F4F4F2F4F2F4F4F6F4F6F6F6F4F4F2EDEDF3F2F4F4F6
                F60004F40004F0F3EFD405EF0012CDEFEFEFF4EFEFD4F4F6F6F6F0F0F4F0F4F4
                04F00004F6F6F0F304F4003AF0F4F4F6F6F4F2F3F4F1F1D9DDD7D9DDDDE4F1F1
                E4F1D9E7F1EDF0F3EDBCD9BDD9E7E7EAE7EAE7EDE707CDCDCDEFED07BDBDCBC7
                07C4E1E0E1C404C5001AD3E7E7D907C4D9D9BCC0C2C0C4E0BDCBBDBDB9BDC0C0
                C4E0C4C404C5002AC1C5C1C5C1C5C5BFC1C1C1C3C5E0ED08EDED07ED0707BDE0
                C2C2C4DFE0E0E0C407EDF4EDF2EDF0F4E7E406DD0026DCDDDADDDDDDDADADADB
                D7D79CE2D7E0E0D7BA99BEC0BCA7BA9792A7ACAC97A7BA90665D391A0000002A
                636F87C6CBEDEDF2F3F4F6F4EFF4F4EFEFEFF3F4EFF6F4F4F0F4F3F0F3EFF0EF
                F3F4F3F4F2F6F4F3F0F604F401F601F60CF401F205F401F606F40008F2F4F4F2
                F4F4F4F205F40006F6F6F4F4F4F205ED001AF4F4F4F6F4F4F4F0F4F4F0EF08EF
                E8D4CDEFE8D4CDEFF6F6F6F404F00008F4D5F0F0F0F4F6F604F4003BF2F3EEF3
                F0F6F6F3E0D3EDEDF1F3EDF1E4E7E4D9E7E4EADDDBDDD9DDEDF108BDD9E7EAE7
                EAF1E7EA07D907E7E707CDCCCBBDBDCBCBCB08CBEDEDF20004ED0017E707D9D9
                BCD9C1C4DDD9BDBDC4E0E9EAEACDE8CD08CBCB0004D9000CBDD9CBD9BDBDD9BD
                BDC0C1C107C5002AC4D20708EDEDED07DFC4C4C5DFD9E7E4E0E4E0DEBDE0EDF4
                F4EDEDED07EDDDD9DDDDDDDADDDADADCDADC04DA00199CDBD79FD6BABBB7BBB6
                BAB6A7A7A7A3BA92A792A7665D341A00000000254CF8AAB80707F4F4F4EDF4F4
                EFF6F2F4F6F4F0EDF3F6F4F4F4F2F4F4EFEFF3EFF0F3F4F4F30005F40004F6F4
                F6F604F40003F6F4F60005F401F207F40011F6F4F4F2F4F4F2F4F4F2F4F4F2F4
                F2F4F20005F401F601F604F4001CF2F4F2F3EEF1EDF0F3F4F4F6F6EEF4F4F0F0
                EFEFD4CDEFEFF0F6F6F60AF00054F6F6F4F4F0F3F0F4F4F3F4F2F4F4ED07D3ED
                EFE7F2F6F4F1EDD9DDD7D9D9DDD9DBDDD9DDE0E7070808F1E7EAE7EAE7E707D9
                BDD907CB08BDBD07E8EF08CBCB08CB08F2E4EDE6D9BCD9E9D9BDC4C007E9D907
                E7F105EA004908E8CDCDCBBCD9CBE7E7E7E8E7CBE7EFF1F1F1EDC4C5C0D3C5C1
                C5C1C1C5C5C5E1D207C4C4C2BDDFE7E7EAF1E7E7E7E4E0E0D7BDBD07F2F3EDF4
                07F2E7F1DDDDDADCDCDADCDCDADCDC0004DA00159C97BAB6BAA7979297929297
                A7A7A7A3906C5D341C00000000286376BABDCBEDF0F4F4F6F6EFF4F6F0F4F4ED
                F4EFF4F4EDF6F6F0F6F4EFEFEFF4F3F2F4F2F6F2F6F309F40005F6F4F4F4F600
                10F401F20AF401F207F40027F6F4F6F4F6F6F6F4F4F2EDEDEDF2EDEDEDF2EFF4
                F6F6F6F4F4F0F4EFEFF2F6F6F6F0F0F0F4F4F40004F00014F6F6F4F0F4F4F2F3
                F0F2F0F3F4F0F2F3EEF1EDE706F40020EDF1EDDDD9E4EAE4F1F1EAE0CB07E7E8
                F1ECD9EAD9D9D907E70708EDED07BD0705CD0006CAC7CABDBDEA05D90015E7D9
                07D3D2E7E7D9BDE0EAE9EAE9E9E9D9E6E9E6E70007EA01EC05F3003FEAE9EAF4
                F2E7E0C4C1C1C1BFBFBFC1BBE0E7E7D907EAE7EAE7D9D9D9E7EAE7E4E0E4E0BB
                E007EDF4F4EDF6F4F4F1E4DDDCDADADCB4DADADCB4DADCDABABA970006BA000A
                97AC929292908E5D341A0000000C686FBAD7C4D3F3EFCD08EFD404F60013F4F4
                F2EFF4F4F4F0F4F2F6F4EFEFF4EFF3F4F30007F401F604F40004F6F4F6F604F4
                01F607F40003F6F4F6000AF4000BF2F4F4F4F2F4F2F2F4F4F20004F405F60007
                F4F6F4F6F4F4F10007ED01F401F404F604F40006F6F4F0F0F4F006F40016F6F6
                F4F3F2F3F0F3EEF3F4F4F3F1E7EEF2F0F1EDEDF607F40020F3F1F1E4EAE0EAE4
                DDE7BDCBE7EAEAEAECE808EDE7E7E70808CBF7F7BCBDCDE805CD01C701BD06E7
                0017EAD9BD07D207E9D9BDD2CB07E7EAF1EAEAE7EAEAD9D9E60004EA01EC05EA
                0050E9EADDEAF1EAE9E9EAE5C4C4C1C1C1BFBBE4EDEAE7F1E7EAE7BDBAB6F7BC
                E7E7EAE7EAE7E0DDE0DEE0BBBDEDF4F6F6F6F4F4F1E7DDDADCDCDCDADDD897BA
                BAD7BAD697AC97AC9797929792906C5D341A0000000C68F8BABABDC40808CDCD
                CDEF06F60004F4EFF4F204F4000CF6F0EFF3EFF0F3F3F2F4F4F307F40007F6F6
                F6F4F6F4F6000CF401F607F401F205F401F206F401F204F404F605F40008F0F2
                F4F4F6F4F2F107ED000CF3F4F6F6F6F0F3F2F4F0F0D505F00018F4F6F4F4F0F3
                F0F4F4F3F4F0F3F0D9BD0707D2E7F2F4F0F204F40097F6F4F0F4F4F1F1EAD9DD
                E7CBCBCBE7F1EAF1EAEFEFE8CD08CB08CBCAF7BDD9F7BCEAE7ECEAE8E8EFD2EA
                D9E6EAD9D9E9BDBCBDCFD9EAE707D2D5F0F4F0EFEDD9E7F6F3E7D9D9EAE9EAEC
                F1F3ECECECEAEAE9E9DCE9EAF3F3F6F3ED070707C7C4BDE0EAF1E7EAE7EAE7D9
                BABABAD6BCEAE7EAE7E7EAE7E7E7D9E0E4DEE0BDE0EDF4F6F6F4EDEDE7D9DADC
                D697BAD6D697AC97AC979297AC00059200048E8E3F1D0000000D4C90BABBBDCB
                CCCDC9CDCDEFF40005F60012F4EFF0F6F6F6F4F4F4F0F3EFF0F3F0F3F4F304F4
                0003F6F4F40005F60006F4F6F6F4F4F607F40004F6F6F4F609F401F205F40008
                F2F4F4F4F2F4F4F206F40013F6F6F4F4F2F4F2F2F0F2F4F6F4F6F4F4F1EDED00
                0407000AF2F3F2F4F4F0F1F4EDF404F001F601F605F4000EF2F3F0F2F3F0F2D9
                BCBDD307F1F408F60014F4EDE0EDF4F2EDF107080808CB07E7EAE7EAEAE806CD
                0007BDBDBDE7D907070005EA0014D9BDD9BDBDE7D9EAEAE707D2D4E7EAD9BDD2
                D0CF04F40012E7BDF1F3D9D9F3F3ECF3EAEAEAE9EAEAEAEC04F30014EAECF3F3
                F6EFE8EDEDE0BDE0E4E7EAE7F1E7EAD704D60033BAD6D9EAE7EAE7EAF1E7EAEA
                F1E7EAE0D9DFE0D7BD07EDEDF4EDED07ED07BDD8D697BA9797BABAACBA979797
                98C2989460361A0000000007686FBABCCAC9CC0004CD0003F4F3F00004F60013
                F4EFEFF3F4F4F6F6F4EFEFF4EFF4EFF4F3F4F30004F4000AF6F4F6F4F6F6F6F4
                F6F607F408F60AF401F301F204F40004F2F4F4F204F401F205F40037F2F4F4F2
                F4F2F2F2F4F4F4F6F6F4F6F6F4F1F2F4F0EDED0707EDF2F4F4F2F4F6EDF4F4F4
                F6F4F4F0F4F3F0F1F0F3F0F3F1E7EDED07EDE70008F600A0F4F4C4D3EDEDF4F0
                EDCBCABDCBBDCBCCCDCBE6E7E8CD0808EFED0807BDD9E7EAD9BDBDD9E6D9CB07
                CBBDE7E7E7BDE7EAEAD9D2D2EAEAD9D9CED2D2F0F4F4F0D9D8D9D9D8D9F3F3F1
                E6E8ECF3F3ECEAEAE9EAEAECF3F3F6F3F3F3F6F6F3F3F3F7E1E7EAE7E7D9EAE7
                D9DBD6D6DBDAD7D9EAF1E7EAE7EAE7EAEAD9E7EAD9D9BB97BBC2D7C2D7BB07ED
                F2F3EDF2F407EDBDBCBA9792979797C2C5D309BF8975471B00000006636FBAD7
                BDCB05CD0007F2F0F1F4F0F4F60006EF000BF4F0F4EFF4EFF4EFF4F3F00005F4
                0005F6F4F4F6F40007F60006F4F6F6F4F6F406F60004F4F4F6F60DF401F206F4
                0005F2F4F4F4F20005F401F204F40007F2F2F2F4F2F2F20004F6000DF2F4EEED
                ED070707BDBDBDEDF00004F4000EEDF2F4EDF2F3F0F3F2F0F3F4F4F005E701ED
                08F60008F4F4D3EEC407EDF404CB0003C6BDC70005CD0011EFE8CD08CB08CBF7
                BDD9E9EAEAEAE7BD070005CB002ABDEAEAE7EAD9EAD9D9BDE6E9D9D8CED2DEE0
                E0F4D9E6D9D9D9DDF1F1F4F1D9D9CBD9EAF3F3EAEAEAE9DD04EA001AECF1ECEC
                EAEAECBDE4EDEAF1E7BDBDD9E7DDDDDDDAD6D6D6E7E704D9002AE7EAE7E7EAE7
                EAE7D7BABB97BB97BBD7C2D7BBBB07EDF2EDF60707EDEDBCBBC3C1C5BF09F4F0
                BD854A1B000000124CA3BAD7BCF1F0EF0808CDEFF3F4F6F4F4F407EF0012F3EF
                F4EFF4EFF4F3F0F4F3F0F4F4F6F6F4F40CF601F407F604F404F608F401F20AF4
                0031F2F2F4F4F2F4F4F2F4F3F2F3F2F4F2EEEEF0F2F4F4F6F3F4F2EEF207BD07
                BD0707EDEDE0C4BDBD07EDF2EFF6F2EFEDF2F00005F40008F3F4F2EDE707F3F4
                07F60003F4EDC50004ED001BF4BDCB08CD08CB08CDC9CDCDC9C9CDCDCD080807
                BDCB08E7EAEAD90006BD0078CBCDCDCDCBE6D9D9E6D9BCD9D8E9D9D907D2E4E0
                F1F1E7D9BCEAE4F1DDF4F4E7D9D9BCEAE7E6D9E6D8E9EAE9E9EAE9EADDE9EAEA
                E9E9D9BDE407D9E7D7DEBBD7E7DDD8DBDCDDDBE0EDE0C5E1C4E1E0C5E007BDD9
                E7E7D7BB97B797B7979798B698C2DBC2D7BBBDED07F4F2EDBDBDC4C4C5C1D3D3
                07B668210000001263F8B6BAD9E1F2F0F2F4F0F008EFEFF3F4F406EF000BF3F0
                EFF4F0F3F0F3F0F3F00006F416F60003F4F4F60004F40005F6F4F6F4F6000BF4
                0009F2F4F2F2F4F4F2F2F20006F40011EDEEF0F2F0F4F2F4EEF6F6F6F3F2EEEE
                070004ED0018BD07C4C1C4C0C4BDC407EDEDEDF4EDF0F1F6F4F4F0F2F4F007F4
                06F6000FF007C5EDC4F3F2EF07C7CBCBBDCBC90004CD0010D4D4CDEFCDD4CDBD
                BDCDCBCBEAEAD9BD06F70077BDCDC9CBD9D9BDD9EAD9D9E7EAEAE7D9D207E0E7
                EAD9D9D9DDF1F1F1F4F0EAD9D9D9E9D9EAE7D9E7E7E6D9D9E9D9E9E9E9DCE9E9
                DCD8E0E0BD0707E2E5E3DEE7EAD9D9D9DDE0E0DBDBDADBDDDAB4DA9DDEE0DEC2
                C4C2BBBB9897959797B697979CD8D9D9D7C2DBBBBBF7BDBDBDF707F0F4EEC0B7
                B6682100000000104CA3BABBD9F2F0F4EEEEF4F0F4F4F4F006EF0011F0F3EFEF
                F3F0F3F4F4F0F4F4F4F3F4F4F40004F601F412F60012F4F4F4F6F6F6F4F6F4F6
                F6F6F4F6F4F4F4F60BF401F204F4003AF2F4F0F3F3F0F4F2F0F4EEF4EEF4F4F3
                F1F2F0F2F0ED0707BDBDBDF7C4C4E1EEE1F2E0D307E0EDEDBD07F1F4F4F6F6F6
                F4F4F4F0F2F0F3F0F4F405F60009F407EDEDD3EDF0EDCA0005CB0017D4D5D4D5
                D0D5D5D4CDCD08C9BDBDF7BDB8D9E6C7CAF7F70006BD007508CDE8E7D9BDE7EA
                E7EAEAEAD9BDBDD207D8D9D9BDD9DD07F1F1F4F4EDE6D9BDD9D9D8D9D8D9D8D9
                D8BCBCD9D9BCD9D9D9D8D9BCE407BD0707D9E5E5DED9EAE7E7D8D8E1D7DBD6DA
                DADBF3EADDB4DA9DDA9CDBD7DEC4C207D7BB989798BAD7EAD8E7E9D9D9D9D7DB
                C2BBBBB7BDF1F4F6F207B663210000000006686FB6BCC4F005F40009F2F0F2F0
                F2F4F4F4F00004EF000BF0F3F0F3F0F3F0F3F4F3F00004F401F601F415F601F4
                0BF601F401F404F610F40015F2F2F4F4F4F2F0F2F4F2F0F2EEEEF6F4F2F2EEEE
                070004BD00100707ED07EDD3EEF2F2D3E1C5D3EEEDEE04ED000D07EDF4F4F6F6
                F4F6F4F4F2F4F40004F60010F4F0F707C4EDF2F3080808CBCB0808D404D50009
                D0D5CFD5CDCDCBF7F70005BD007FCBCB08080707BD07BD07CB08CBD9D9D9E6BD
                DDE7E9D9E7D9D9D9E7EAD9BDD2DAD7BDDDF1F0F4F4D9D8D9BDBCD9D9D9E6D9D9
                E7D9D9D8D9D8D8D8E9D8D8F7E107BD0707BDE0D9D9BDBDD9E7D6D9E7E0DED8DA
                DBDBDAF1F3F3ECDBDADA9DDA9C9DDEDFC5BBD6D7D7BAD9E6D9E9D9E6DDE7E6D9
                D9D9D7E0D7C2BBBDBDBDB668210000000008686FB6F7C4F2EEEE08F40003F0F4
                EE0005F40009EFF4EFF4EFF4F4F4F00007F421F60003F4F4F40008F60003F4F4
                F40005F60019F4F6F4F6F4F4F0F1F2F0F2F0EEEEF4F0F2F4F2F3F2EEEEEE0700
                05ED0407001AC5EEF2F0F2F0F2EED3E1C5D3E1D207BD0707EDEDF1F4F4F6F6F6
                04F4000AF0F4F3F0F3EDBDF2EFF205080012EDEFF0D4D5D0D5D5D5EFF0F0F0CB
                0707BDBD04070008CBE8CDCDCDD4CDBD04CB0033BDE7D9D9D9E6D9D9D9E9D9D8
                D9E6D9D8D9CE07D9DDDBD2F0F0F0E7EAD9D9BDBCBDE9D9D9D8D9D8D9F7BCF7BC
                F7D8BCBCBBE0BD00040701BD01ED04BD000BD9BAE7EAE7D9BCE0E4EAF10005F3
                0025ECDDDCDBDAB4B493DBC5C407D9EAD9E7EAD9EAEAE7D9E9DDE6D8D6D8D8D9
                D7D7959075401F000000000B4C6FF7BDC4EEF2EEF0F2EE0009F4000BF2F0F2F4
                F4EFF4EFF4F3F00008F424F60004F4F6F4F607F40004F6F4F4F406F6001BF4F2
                F4F2EEEEF4F4F2F4EEF2EEEEF2F2EEF2F0F2EDED07ED0707070005ED0005F1F2
                C5D2C50004EE0007D3D3E1D3E1D3C4000407001AED07F1F0F6F6F6EDF2EDF2F4
                F2F4F0F3EDEFBDCB08ED08EDF0F306F00010F4F4F4F007BDCBBDBDF7CBF7BDBD
                CDCB08CD0073C7CABDD8D9D9D9E6D9D9E9D9EAD9EAEAD9BD07D2D0D207D0D2D0
                CE07D8E6D9D8F7F7BCD9BCD8BCD9BCBCC7BCC7CABDCAF7E0E007BDBD0707F707
                BDBDBDD8D6BABCBAD8D6D8E7EDE1E0E4DDE4F3F3F6F3F6F3F3F3F1F3EADDDBDF
                C4D9D9E9D9E6E7D8E9D9E6D9E6BC92D8D9D8D8D8BC6D7537150000000020636F
                F707EDF2F4EEEEF2EEEEF4EEF2F4F2F4F4F6F6F4F4F4F0F3F0F3F4F0F4F306F4
                0003F6F6F40024F607F401F607F4000AF6F4F4F4F2F0F2F0F4F205EE001EF0F2
                F0F2F4F0F2F0EE07EDEDF1EDED070707BD07E4E0EEEE0707C407D3D304EE0021
                D3D3E1D3E1D3D2EDC4ED070707EDEDF4F2EFEDEDF4F4F2070707EDEDEFF0F3F4
                F40004F00014F3F4F0F3F2F3BDBDCBCBCBE6CDCDC9CAC7CACBC906CD001CCBCB
                CBBDE7D9BDD9D9EAE7D9E9D9E6DDD8D9D8BDBCBDBDBCBDBDD0D206D90051F7BC
                D9D9D8D9BCBDBCC6C6C8C9C8B8E0E0BD07EDED07BDBD070707E7F1EAE4EAE7E9
                E9DCE9D9D9BCE0E0D7DDF1F3F3F3F1F1ECF3F1B4DA9CDEC3BDBDE9D9D9E9D9D8
                D9D8D9AE80D8D8D9E9D9D86D75370D000000000768F8F70707EDF30004F40013
                EEF2F0EEF4F0F2F0F2F0F4F4F4F3F0F3F0F4F30008F401F601F421F6000CF4F6
                F4F4F6F4F4F4F6F4F4F205F40004F2F0F4F206F401F008F401F601F404F6001A
                F0EDEDE407D9D90707BD07E7E0EEE1EEEED20707BD0707C4EED304EE0047D3D3
                E1C5C5E0D2E0ED070707EDF2F3F4F6F4F0F1F0EDF108ED08F4F3F0F4F0F3F2F3
                F0F3F2F0EDF7BDBDCBEDEAE7CDCDCDCBCBCDCBCBCBCDCDCBCBC6CAB9CAF7D9D8
                D9E7F2E7070004D90004EAEAD9E904D90021D8BDBDCBD2D9E6DCD9E9D8D9E7D9
                D9CBBDCABDCBCDCCCDCC07F20707BDBDD407E70004BD003607BDEEE5F108CDE7
                E9E9DCDCBCD9D907E0B3E1EDD79DDBDADADCDDDADA9D9DDEC2C2D9E6D9D8E7DC
                E6E6AEADD9E6D8D8D8BA764B371B0000000A4CA3BABDEDF2F0F2EDF105F4000F
                F2F4EEEEF2F4F4F2F4EFF4EFF4F3F00007F401F601F424F605F401F608F401F2
                04F401F001F413F6001D0707EDE7EDF1F1EDD90707F107E0F1EEF2F2EE07BD07
                BD07BD07BDC4D30008EE000FD3C5D3D2ED07ED07BD07EDF1F4EDF20004ED001E
                EFF2EFF2F3F0F4F2F4F0F4F3D2CDCBCBBDC4EEEE08CDCBC6CAC7CAC7CCCD04CB
                01BD04CB0024BDE7F1F1EDE7D9D9BCBDD9D9E9E7DDE7D9EAE7EAE7D90707EAE7
                EAEAEAE7D8BDCBC7CACB06C90043BBE00707BDD2EDED0707BD07BD07D2F0F0D7
                CACBD9EAD9D9E9B3D8D9D9BCDCD907E0E0E0C5DEDED79DD79CD69DD6D6C3BDD9
                E6D8D9D9E9EBEBE9D8D9E9D8BC9063370D000000000D68F8F7BDD9E7F1F3F2F4
                F4F2ED0007F4000CF3F2F4F0F3F0F4F3F0F4F4F005F40004F6F6F6F424F60005
                F4F4F4F6F60008F40012F0F2F0F2F4F6F6F6F4F4F4F6F6F6F4F4F4F206F60015
                F4ED0707F1F107F107EDEDE4070707E4F2E4EEF1E1000407000AEED3EDED0707
                07C4D3D304EE0021D3E1C5C5C5C4C4C0070707BD07EDF2F4F4F2EDF2F4F4F0F2
                F3F0F3F2F3F0EFCDCB0005BD002CD207CBCBCBCDCBCBCBCDCDC7B8CAC7BDCBCB
                BDCBCBF3F1EDEDF1EAE7E7E7EAEAE7EAEAEAE7EAD9E9D9D9D9E604EA0016D907
                CBCACBCBC9C9C9C8C8C9C6E0E0BD07F7D2EDEDF704BD0015ED07BDE7EAEADDDA
                E7D7D7CBEAE9DCD8ADBCBDD8D80005D9000AE007D9D9D6D7D6B3D7D905D8000D
                EBECE9BABAACA7BAB1A790431E000000000763F8BD0707EDED0004F104F4000C
                F2F3EDF1F2F0F2F4F0F3F4EF0BF401F601F428F607F401F207F40003F6F6F400
                06F60003F0F2F20007F60019F3EDED07EDE0EDF10707BDED0707EDF107EDF2F2
                F1F1ED07070004EE004DD3D3C4BDBDF7BDC0C4C5D3F2F1EED3D3C5C5D3C5C407
                C4BDF7BDBDEDEDF4F6F6F6F4F4F4F0F2F0F2D4D4D3BDF7F7F7BDBDBDCBD4D4E8
                CB08CB0808CB080708CBCBCBBDCB08F2F107EDD9EAEAE70006EA0003D9E7D900
                04EA001BD9EAE9EAD9D8BCCAB8C7B8C9C8C9C8C9C8C8B8E10707BDBDD5ED0700
                08BD0033E7F6F3F1EC07D2D3E0E1E2E2E6DCB3D9D6939C9CD6D8D8D9BCB6BCB1
                B4B3B4B3D8D8B1D8D9D8E9EBD69393AB939392A666431B000000001E4CF8B6BD
                EDF2F4EDF3EDF4F1F1F1F3F2F4F4F2EEF2F0F4EFF4EFF4F4F0F308F40005F6F6
                F4F6F40026F601F401F406F606F40004F6F6F4F404F605F406F60023EDED07ED
                07EEEED3EEEDED07F1EDF1F1E407E4D3F2E4D9D907EED3E1D3EEEEEEC4BD0700
                05BD0003E4E0C50004EE0005D3E1C5C5C50004C40007BDF7BD07EDF4F40004F6
                0004F4F4EDED050706BD0007CBCBCB08D208070005CB0026BDCBBDEDF3EDED07
                CAD9DCD9E9D9E9D9E6DDE9DDE6DDE6D9D8D9DCD9E9D8D9BCC7CAC6C7C6C905C8
                01F701E004BD003ED2ED07BDBDBD07BD07BDBDEAF6F3ECDCE0EDF3F0F0DEDEC7
                08D9BC9CAC9989979393B495F893DAB4B3D8D8E6B4B3D8D8EBEBEBDC9393D693
                93928E60431600000012686FB6F7BD07EDF2F4F0F6F4F4F0F3F2F3F105F40005
                EFF4F0F4EF0009F401F601F428F601F401F410F601F405F60004F4F4F0F407F6
                0003EDEDED0005EE0029D3C5D3C5E1F1F1E00707C4E1F2E407E4D9F2E4C5C5C5
                EEEEC5BDBDBDD3EED3E0F1BDBDBDC4C4D3EEF00004EE0016D3EEE1D3D3E0C4C4
                BD0707EDF2F6F6F4F2EDEDED070707BD0043F7BDCBC4C4D3C4C7BCC7B8CAF7CA
                C7BDEAD9D9BDCAD9E6D9E9D9D8D9DCE6D9E6DCE6D9E9D8E6D9DCD9D8BCBCC6B8
                CAB8C6C6C6C9C8C8C6BDE40707BDD2F0EDBD07BD070005BD0033EAEAECF6EBDD
                DDECECF107E7D0BDBDBDB4BAD6D6BA9CACB8B7A7D6D6B4D6B3BABAB4B3BCBCDC
                E9EBE9B4B4B1B193938E613F15000000001B686FB6F7BD070707EDEDF2F4F4F4
                F2F4F0F4F4F3F4F2F3F4F3F0F30009F40004F6F4F6F429F601F40FF601F405F6
                0003F4F4F40007F60008F40707C4D3EEEE0708EE0024E1E1E0C4D3E4EED907DD
                F2F1F1E0E1EEF2ED07F1EDEEEEEEF2F2F0EED3ED07ED07C4E0D304EE0096D3D3
                C5C5C5C4C4C0BDF7F7F7BDEDEDF4F4EDF0F1F0ED07BDBDF7F7F7BDD3EED3EED3
                CBCBCABDD2C7CAB9CAC7BDBDCAC7BCD9E9D9E9EAD9EAD9E9D907BDD9BCD9D9E6
                D9E6D9BCC7CAC7CAC7CAC7CAC7CBCAC7E0E007BDBDD2EDEDBD070707BDBDBD07
                D9ECE9DCECEAE9DCDCEAE7E7EABDF7F7D6D6D6BABAB4DBBABB94A9B3B3D6E9D9
                D8D8B1D6BCBAB1B4B1D6D8DCD6D8ADAC6C685B0D000000054C6FB6F7BD000507
                0004ED07EDED17F401F601F428F601F401F40FF601F406F60003F4F4F40007F6
                0040F307EDEDD3EED307BD0707EDD3EEEEF0F0EEF2F2EEEEF0F2EDF1F4F2F2ED
                EEF2EE07E4EAE1EEEED3F1E1EEEEEEBDF7F7F7BDF7BDF7C4C4C5EEEED3E1C5C5
                C4C405BD001BF7F7BD07EDF2F3F4F6F2F3F0EDEDD3D3EEE1EEEED3BDC7CBD3D3
                070004CB010704CB000FD9E7EAEAD9E9EAD907D2D5D2C4D2BD0005D901CA07CB
                003EC7CBCAC7BDE4070707BDF0EDEDBD0707BDF7F7C707E7EAE9DCECECDCE9E9
                E907F2EFBDBDBDD6B1AC97ACD693B6B7766FB1B3DCEAF3F3ECD8B193B1B1B3BA
                06B60005F86E4C44130000000005636FB6F7BD00040707ED0005F2EFF2F4F400
                05F601F401F608F401F601F429F601F410F601F401F404F601F401F409F60009
                F0EDEDEEF2F0F2EDF00004ED00030707ED0004EE0019F2E1EEF2BDDDC5F2E4C4
                C5E4F1E4EA07D3EEE1C5E4E1EEEEC50005BD000CC4D2C4BDD3EED3E1C5C5C0C4
                0EBD001E07EDEDF4F4F2EDF6EEF2F0EEEEEE0807D2EEEDD2CBCBD3EDF4F007CB
                CBE704EA001DE7EAEAD9D9D9D2C4CBD9D9D9CBCBBDC7CBCAC6C7C6B8CAB8C6C6
                C6F7E10004BD0003D4ED070004BD0038F7B8C7C7E7F3E9DCE9EADCB3ECF107F4
                07BDF7BD9CB197A7ACACD6AC9594A79CBCB3E9ECF3F6ECB3B192B1BAF7B6F7F7
                D8DCD6BA906C5B0C000000054CA3B6F7BD00050707ED0008F2EDF3F2F3F4F4F4
                07F60007F4F6F4F6F4F6F40026F60003F4F6F40010F601F405F601F40AF60032
                ED07EDD3EEEE07BD07EEEEEE07BD07D2EED307D2EEEDF1F20707D2F2EEC4D3EE
                EEE407C4EEEEC5EDE4EEEEF2F1E4E70707D306EE0005D3C5C4C4070013BD007E
                07EDEDF4F4F3EDEDEDF2D2CBD3D3C5CBC6BDD3C5CBF4EFCBB8D9E6DDE9D9E9D9
                E9D9D8D9D2D0D7BCBDBCBCC6BCC7B8C7B8C6B8C7B8C6B8B8B8BBE00707BDBDD2
                EDBDBD07BDBDB8B8C7C7F1F3F3ECECE9DCE9F6EC07F1BDF7F7F7E7D7D6D6D6B1
                ACB79C9995B6F7BAD8F3E9E9ECEAE9B1B1B6F7B6F7D6DCDCDCDAB16D37130000
                0005686FB6F7BD0004070013ED07EDEDEDF2EFF2EFF2F0F1F0F2F3F4F0F4F400
                44F601F405F601F409F60033F4EDEDEDEEEEEEEDEDEEF2EEF0EE0707EEF0ED07
                0707BDEDF1F2EDD3EED3D3E1EED3E7D9C5EED3C4E4D3E4D3E4D9D9DDE4E1D300
                05C50003C1C2C0000AF701BD01E70EF7002CBD0707EDEDF6F6F4EDEEEDC7BDD2
                D3D3CBCBEFCBC7CAD9E9D9DCD9E9D9DCD9DDD9D9D8D8BCBCBCF7BCBCBCB808C6
                000AB8E0E007BDBD07ED07F704BD0038B8B8C7CBF1F6F3F6ECDCE9ECF6E7D9BD
                BCBDBDF707D6F1EDF3F2F1C2767695B6F7F7F7D8F7F7B60708D0F7ACBAB6B6D6
                DAA4ADA4A66D341E000000084C6FB6F7BD07070709ED000CF2EFF1F0F2F3F0F2
                F4F3F4F42FF604F40FF601F401F405F601F401F308F6003CF1BD07C4E1EED3BD
                BDD3D3C5EEC4BDBDEED3BDBDBDC4C4BDBDD9E4E4EEEED3EEEED3E4D9D3EEC5C4
                E4C5EEE0DDD9D9E0EDE4E4E0E0C4C0C2C0C4F7BD09F70005BCEDF3F3BD000FF7
                0006BD07F3F4EDF104ED0021EED3BD08EDCBBDB8D9E6D9E9D8E9D9E9D8D9DCE6
                D8D9BCD8D9D8BCB8CAC6C6C6B80005C601B801E405BD01ED06BD000FB8C7C707
                F3F3F6F3ECDCEAF6F3E7BD0006F7002397F1F4F2F6F4D3ED85B6BAF7B6F7B6B6
                F7B6EDBDCEB69793F7B6DCD6807DA36E6D3420000000000A636FB6F7BD070707
                F4F306ED000BF2EFF1F0F2EFF2F3F0F4F20004F401F601F424F60BF40FF601F4
                01F404F601F401F409F6003BED0707C4D3EE0707C4EED3E1EE07BDC4EEEEBDBD
                D2EEEEEEC4BDBDEDF1E4BDBDC407EDD3EEEEE1E1D3EEEED9BDD9E0F1E1F1E0E4
                D9DDE0BDD9BDD9000ABD0009D907E7F3F407E7E7E7000DBD0011F7BDBD07EDED
                EDF4F6F6F0EDF3EFCBCBD90006EA0019E9EAEAEAD9EAD9D9BDBDBDC4CBC9CBC9
                CBCAC9CBC6C6B8BDE00005070016BD0707BD0707BDBDCBCBE7F1ECF1ECEAE9EC
                F3EC07F704BD0025F7BCD6BD07D5F0D5F4E4B8B8F7F7BDF7BDF7F7F707D5CEB6
                9293F7B6DCADB67F98756C3F20000000000B686FB6F7BD0707EDF2ED070006ED
                000BF2EDF0F1F3F0F2F3F2F3F20004F40003F6F6F40028F604F410F601F401F4
                04F60004F4F3F6F307F60014BD07C4C4EEEEBDBD07EEEEEED3BDBDD2EEC4BDBD
                04D3001DD2BDF7D3D3D9E4BDBDBDF7BDC4C4E4EEEEEEC0E7BDC5EEE1C5DDE0BC
                BD0004D901DD01D904F701D904F70010BCD9EABDF1F6F3BDD907E7E7D9D9BBBC
                0DF70023BC07EDF4EDF2EDEDF4EDEDE7E9D9E9D9E9D9E9D9D8E9D8D8BCD8F7BE
                F7C6C9C6C6C8C80005C60003BBE007000ABD0007F7CAF7BDBCD6BA0005D60004
                D8DABCBD05F70024BABCBC07F0F0F0EE97B9F7F7F7B6F7B6F7B6BD07CEB9B6B1
                92B6BADCBA96A39694614520000000064C6FB6F7BDBD040705ED0009F1F0F1F0
                F3F2F0F2F30007F40005F6F4F4F6F40025F60005F4F6F4F6F40011F601F401F4
                04F601F401F408F60041F4EDEDEDEEEEF0ED0707EDD3EED2BDBDD3EEC4BDBDD3
                E1C5EEC4BDBDD2C4BDF7BDC4C4C4F7F7F7C4F2C4C4C4E4E4EED3C5C5D7C4F7D7
                F7DDBBD9BBDDBDBCF7BDD90004F70009BCECECDDEAF1F3F3BD0004D90005DDDD
                DAD7BC000FF70027BC07EDF3F4EDF407EDF1E7EAD9E9DCE6DCD9D8D9BCBCBDBE
                C7C8C6C9C6C8C6C8C8C6C6C6E0E007000BBD000DBCBDF7BABCBDBDF7BDF7F7F7
                B60005F70026BDF7BDF7F7BDBDBDD2F7C7F7F7F7B6F7A9ACBAB607D2CFB9B6B1
                93F7D6DCA49F949694446220000000036376B60005BD010706ED0017F0EDF2ED
                F2EFF2F3F2F4F2F3F4F4F4F6F4F4F6F4F6F6F40029F60005F4F4F4F6F40011F6
                01F401F408F6005CEF0707E0D3EEEEEED2070707BD07BD07EEEE070707EEEED3
                EE0707D2EEED0707D2EEEDD2F0EED2EEEEF1E4E7F1E0EDEED3EEE1C0BDBDC4E4
                D9BDDDD9DDDDBDDDBDF7BDF7BDD9ECF3ECDDDDD9F2EDBDE7D9E7D9DDDBBCF7D6
                D9D6D7BC0EF70019BDBDEDF3F2F4EDEDEDF1EDEAD8E9D8E9BCBCBBB7C5C4C8C8
                C80004C6000CC8C6B8E0BDBDBD07BDBDBD0704BD04BA000ED8D8B3D8D8BCBABA
                BAD6B3D8BABC05F70005BDBDF7F7B60006F70017F1D9D9D8ADED07CEB6B6B193
                B6D8DA7C9F989495456320000000000A6876B6F7BDC4C407070706ED0015F1ED
                F0F1F0F1F0F3F2F3F4F4F4F6F4F4F6F4F6F6F40018F60008F4F6F4F6F4F6F4F6
                06F401F601F405F60004F4F6F6F40FF601F401F408F60004EDED07D307EE0013
                D3070707C4EEEEBDBDD2EEC5E1D3BDBDD2EEC40004BD003EC0C4D3D3EED5D3D2
                E0ED07BDBDE7E4F1EED3C4D3E1F1EEE1C5C4E0E7F1E4BD07BDBDD9F1F3F3EAE4
                DDBC07F1ED0707EDD9D9DDD9F7DDDBDDDDDDDBD9D9BD0EF70023BD07EDF3F4F6
                EDEDF0F1E7D9D8BCBCC0C5C4C7C6C6C8C8C8C6C8C6F7E0BDBD07BDBCBC0005BD
                0017F7D8D8D8ADD6BAADBAD6B3D8B3D6ACBA97B1D6B3BCBCBA0006F7001DBDF7
                F7B6F7F7E7BCEDBDF207CECEB6BAB193BADCD67D989E98945D5220000000000B
                4C6FB7B7C4C1E1EFC407070005ED000AF0EDF2EEF3F2EFF2F3F206F401F601F4
                1EF60FF40004F6F4F4F607F40CF601F407F60009F4070707D3E1EED2D30008EE
                0011F0D307BDEEEED3EED3BDBDEEEEBDF7BDF70005BD0019D207C4D2D2EEEED3
                C4BDBDE4EDE1C1C5E4F1E1D3D3C5C0F7DD0005F70016BDF1ECF1DDDDE4D907E7
                ED07F1EFEDF0E7E407DDEAE407DD0009D9D9D7BDBDF7F7F7BD0009F7001D07ED
                F1F4F4EDEDED0707E0D3C7C6C8C6C6C6C8C8C6C6C4C2C2C0BDBDBA0004BC003C
                BDBCBCDCB3DCDCB3DCD8B3BAADBABAB1D8B3B3D6AC97B1ACD6B1BABABCBAF7B6
                F7F7BDF7BCBCBCD9D9EF07CFB9A7B1BAB1BADDADAA989E986D514E1C0000000B
                63F8B6C0C4D3EEF0EDED070005ED000BF1EEF0EDF3F0F2F3F0F3F20004F40005
                F6F4F4F6F4001DF601F401F60EF40003F6F4F60007F413F6000DF3070707D3EE
                EE07BDBDC407D30004EE002DD3EED3D3EED3C5EED2BDC4EED3BD07C4EEEED3D2
                C4BDD3D3D2C4C4D3D3EED3BDF7BDEEE4E0C1E4E4BDC4EED3C50007BD001CD9F3
                F1EADDE4D9D907BCBDD8BDE7D2CBE0D9F7BCDBDADBDCDBDADBDA05DD000BD9D9
                D9BDBDBDF7BDBDBDF70006BD005A0707EDF4F4F3EDF0EDED08CBC6C9C8C6C6C7
                C4DFC2C4C2C2F7BCBABCD6BCBABCBAD8D8B3D8DCB3DCB3DCB3D8D6ADBAACBAB1
                D8B3B3D6B1AC97ACACB1B1BAF7B6F7B6F7BCBAF7BC07BDCEB9B6F7A9D8D6DCAD
                AE969E986C513A0F0000000C4C6FB6C4C4E1EEEEF0F0F4F004ED0007EEEEEEF1
                F0F1F30008F40004F6F4F6F408F601F409F60011F4F6F6F6F4F6F4F6F4F4F6F6
                F6F4F6F6F60015F413F60010F3EDEDEEEEF2F0EEEEED0707BD07BDD305EE000D
                D3C5C5EEC4BDC4EED3F7BDBDD30005EE01D301EE09BD0027C4EED3E0F2F1E0BD
                C4EEC5C4BDF7BDF7BDF7F7BDF1ECDDDDDDD9BC07D9D9BDD907EDEDF107DDBD00
                09DD006FDBDBDADADBDADADBDAD7BCF7F7B6F7F7B6F7F7F7B6F7B6B6F7F707ED
                F1F0F3EDF4F4F008CDC9D2E1C4C4DFE0E0BCD7D8D6BCD8BCD8BCD8BCBCD6BCD8
                D8DCDCD8DCB3B3B3D8B1BAACACBAB1B1B3B3B1B1AC9292BAB6F7F7B6BCBABCB6
                0707B9F7F7F7B6BCD8DCAABA9E9698537B260F000000000A686FB6C4D2D3EEEE
                F0EF05F4000BF0F1EEEDF3F0EDF2EFF2F30004F4000FF6F4F6F4F6F6F6F4F6F6
                F6F4F6F6F40004F601F405F60005F4F6F6F4F60009F40004F6F6F4F605F40003
                F0F4F0000BF412F6002DED07EDEDD3EEF0F2F0F0F2EEED0707EDEEEE07D2EEEE
                C5E1EED3EEEED3D3BDF7BDF7BDBDC4D3D3EED3BDF7BDC40005BD000CC4EEC5C0
                E1EEDDD9D3EEC5C006BD0021D9D9E7F1DDDDD9D7BDBDDDD9D9BCE0D3E007E0DA
                F7D6DDDADBDCDBDCDBDCD9DDD90009DD0063D9D9BDBDF7BDBDF7BDF7F7F7B6F7
                B6B6F7F707EDF4F6F6F6F4F4EEF7F7C2C0C2BBD7BBBABABA9CBABAD6BABAD6BC
                D6BCBABCD6D8D8DCE9DCE9DCE9D8D8D8BCD6BCBAD8D6D8D8B3D8D6BABCF7BCBC
                BCF70707B6F707B6F7B6DCDA7F9F9E97985464390F000000001C686FB6BDD2ED
                EDDDEDCB0807EFF0F4F4F4EDF2EDF2F3F0F2F4F0F4F004F4000EF6F4F6F4F4F6
                F4F6F6F6F4F6F6F404F60009F4F6F6F6F4F6F6F4F60008F401F205F401F601F6
                05F40004F0F2F0F00AF40FF6001CF3070707D3EEEEED07D3EEEEF0E00707D2F0
                EE0707EEEED3C4D3E1D305EE001ED3C4BDBDF7BDC4EEC5BDF7C4EEEED3D3C4C4
                D3C5C5C5D3C5BDD9D3D3C5C404BD0035F7BDBCBDD9D9DDF1DDBDD9BDDDE9D907
                E707E7E1E0DDBDBDDADDDADDDBDDDBDDE4E0DDDDDADBDADADADCDBDADB07BDBC
                F7BCBAF7B60004F70003BDF7BD0005F70006BD07F1F4F6F405F70007B6BBD7E0
                DED7BB0004BA019706BA000BADBAADBABAB1D8B3B3B3DC0005B301B104AC001C
                B1B1B3B3B3D6BCF7B6F7F7B6F3F2F7BDBDDCD8989A9FBB946A63391700000013
                4CF8F7BDEDF4EDD9E708D4D4EDD4EDEDF0F1F00005F401F00AF40019F6F6F4F6
                F4F6F4F6F4F6F6F4F6F6F4F6F6F6F4F6F4F6F4F4F60009F40009F3F0F2F3F0F2
                F4F4F60006F40003F0F0F00004F40006F0F4F4F0F4F40BF6001DF3F307BD07C5
                EED3BDBD07BD070707BD07D3F0C4BD07EEEEC5C407C4C50009EE0056D307D3EE
                D2BDBDBDC4D3D3EEEEEED3C5C1C5D3C4F7BDD3C5C5BDF7BDF7F7BDF7BDBCD7BC
                D9D7D9D907D9EAD9D9BDD9E7E407E7DDDDBDD7DDDDDBDDDBDCBDE1E0D9DBDDDA
                DDDBDDDBDCDDF1F1DDDABCBDDBDCD7BCBCF706B60029F7B6B6F7B6B6B6F707F7
                B6B6B6F7F7B6F7F7F7BDE0E0E0D7BBD6BABAD6BAD6BAD6BAD6BAADBAACB1D600
                0BB301B105AC0017B1BCB6F7B6B6F7BDF7B6B6BADCAC989798C26D7E64390E00
                0000000A63F8B7BDF1F4EDDDE7F105EF000CEDF3F1F1F4F6F6F6F4F6F4F60AF4
                04F60004F4F6F4F406F60008F4F6F4F6F4F4F4F609F4000EF0F2F3F0F3F2F3F0
                F1F0F2F4F4F605F40008F0F2F4F4F4F0F4F004F408F6001AF3F6ED0707C4E1EE
                D2BD07BDC407BDF7BDBDEEEEBD07C4EEEED304C50007D3D3BD07D3D3D30006EE
                01D301C405BD000FC4D2D3EEEEEED3EEC4F7C4EEC5C0BB0004F7003EBDBCDDD9
                BDD7BCD9BBD9BDD9DCE7BD07BDE707D9BDD9D9D9BDD9DBDCDDDDDDE0E5E0D9DB
                DDDDDBDCDBDCDBD9DDDDDAD7F7BDDADBDAD7D9CBD9D9BDBCF7B808B60004D9ED
                07F706B601F804B6000EBBD7C4D7D7BA97BA9797ACBAACD604BA0005ADBABAB3
                D60007B3001CB5B3B3B1B1ACA6A6A6B6B6B6F7F7B6B6D6DCA47E9898D7686760
                3917000000056876B7F7D70004D90015E7E4EDEAEFEFF3F3F3F1F1F4F4F6F6F4
                F0F4F6F6F60008F40012F6F6F6F4F6F4F6F6F4F6F6F6F4F6F6F6F4F60BF40011
                F2F4F4F2F4F2EFF2F0F1F0F1EFEDEDF0F30005F401F601F006F40004F0F4F4F4
                05F6005CF3F6F607BDBDC4D3EEC407BDD2EEEEEED3C4D2EED3BDF7BDC4C4EEEE
                EED3E1EED2BDBDD3E1C5EEC4D2D3EED3EEEEEED3D3C4BDBDF7D2EEC4C4D3D3BD
                BDD3EEC5C5C4C4BDBDBDF7BDE9DDD9BDBCBBBCD7BDDCE7D907BDBDD9BD07D9BD
                04D9001BBDD7BCDB07C4E4C4DDDDDADDDDDDDBDDDADBDCDBD8F7BCDBDCDBD800
                04D90044BDD9BDD9D9BCF7B8F7B6F7B6B6BCD9F1EDBDF7F7F7BABAB6B6F8B6F8
                B6F8B6B6BBC2DBC2D7BA9797AC97AC97ACACBAACBAACACBAACACB1B1B3B3B3B5
                B3B3B3B5B1B1ACBA05B6000DF7DCDC7F809696BB90A6623417000000001C4CF8
                B6F7BCD9D9D9E7E7DDE7E7EDF1EDF1F1F1F3F0F3F4F0F3F4F4F005F40005F6F4
                F4F4F60004F40003F6F4F60006F40006F6F4F6F6F4F60EF4000BF0F4F2F3F2EF
                F2EDF2EDF20005ED04F4000DEDF4F4F0F2F0F4F0F4F0F2F4F30004F60007F307
                0707C4C5EE0004BD0008D2D3EEF0EEEEEEC405BD0015F7BDC4D3D3D3F7BDBDEE
                D3E1EEBDBDC4EEEED3D3D30004EE0026D3D3D3EEC4BDBDF7F7F7C4EEEED3C5C5
                C4BDBDBD07D9EAEADDD9D9D907BDDDE7D9BD07BDBDD904BD0026D907D907D9D9
                BBC4E0E0C0D7DADBDCDADADDDADDDBDCD7F7BDDBDCDBD9D9D907D9CBD9D9D9BD
                04D90015BDBCB6F7F7BD07EDEDEDBDF7F7F7D6D6BABABAB6B60005F8000DB6B6
                BBD7C2D7BB9797AC9792920008AC000FA7ACACACB1B3B3B2B1B5B5B1B0ACA600
                04B6000CDCDAA880ADBB97AAAD673E1C0000001F68F8B6BBD8BDD9D9DDD9E7E7
                E4EAF1F1EDF1EDF1F1F2F0F3F4F4F0F4F0F4F00004F401F60AF40009F6F4F6F4
                F6F4F4F4F6000AF4000FF2F4F4F3F2F4F3F2F0F2F0F2F0F1EF0009ED000307ED
                ED0005F40023F0F2F0F2F0F2EEF3F4F3F6F3BD07BDD3E1EED3D2BDBDF7BDBDC4
                C4EEEEC4BDBDD3D3C40004BD001DEED3BDF7C4D3D3D3C5F7BDD2EEC4BDBD07C4
                C4D3D3EEEED3EED3D3C4070004BD0014C4D3EEC5C0BCF7F7BD07BDD8EAEAD9D9
                07D9EAE707070015BD07D9BDD9BD07BDD9D9D9E0C4C4BBBCD6D6DBDADB0004DA
                0014F7BADADAD6D7D8BDD9D9BDD9D9D907D9D9BDD9BD04D90016BDBD0707EDED
                07BDBDF7D8D6D6BDE7EDE7BDB8B6F8B605F80008B6BBC2D7C29CBA97059207AC
                001BA6ACA6ACB1B1B1B2B3B2ACB6F7B6B6BADCDAB180BB75B8AAA45219000000
                001B4CA394BABCD7D9EDEDEDEAE7F1EDE7F1EDF1F1EDF1F3F3F2F4F4F60028F4
                0010F2F4F2F3F2F0F2F0F2F0F2F0F2F0F1EF05ED001507EDED0707EDEDEDF4F2
                F3EDEDEFF2F0F2F0F2F3ED0004BD0024C4E1D3EEEEEED3C4BDBDF7D3D3BDF7BD
                EEEEEED3BDBDC4EEC4BDBDF7BDC4D2C4F7F7D3D305F70013BDBDBDC4D2EED3EE
                D3EED3D3D3C0BDF7D3D3C50004BD04070067D9D9E9DDBDD9EAD907BD070707F2
                EFF1ED070707BDD907D90707EADD07D9D9BDD7BCBABCD6BCD6F7BCDBDAD6D8BD
                BDD9BDD9D9D9BCBDBCD9BDD9BDD9D9BCBDD9BD07BDBDEDED07BDBDBDDAD6BABD
                F7F7F7B8C6C6C6B8B8B6B6F8B6F8F86FF8B6B7D7C2D7989797000692001DA692
                A6ACA6ACA6ACA6ACABB1A6B6F7B6B6B6BADCDAA8C2614D4D492A1A0000000010
                686FB6BABDD9D9EEF0F2EEEDEDF1EDEA07F10007F2F3F1F4F4F4F60004F401F0
                1AF40018F2F4F4F0F4F4F3F4F0F3F2F2F2F0F2F2EDF2EEF2EEF2EEF204ED0A07
                000AEDEDF2F4F6F4F6F4F40704BD0050C4C4C4C5C5D3EEEEEED3D3EEEEBDF7BD
                F7BDC4C4F7F7D2EEC4F7BDBDF7BDF7BDBDBDD3D3BDF7C4D3C5C4C0F7F7C4D3C5
                BDC4D3D3EEEEEED3D3EEC5C4BDF7BDBDD907BD07BD07D9EAD9EAEA0707BD07BD
                04ED01F201EF04ED0009070707E7EC07D9BDBD0005D9002BD7D9D9DBDADDD6D9
                BDD9BCD9BDD9BDBDD9D9D9BDD9BCD9BCBDD9D9BCBDF7BCBBBCE7BDBDBDBCDAD6
                BCBDF70004BD000BC6C6C6C7C6C6B8B6B6F8B60004F80008B6B6BBBBD7C2D797
                089201A6019207A6000FA7A7B6B6B6D8DC9DBB4D574940230D00000000124C6F
                B6BCBBD8E0EEF2EEEEEEF2F0F2EDEAED04F1000AF2F1F3F2F3F1F3F2F4F305F4
                01F01AF40013F2F4F0F4F2F3F0F3F0F0F4F0F1F3F0EDEDEEED0006EE0004EDED
                07ED0407000BBD0707BD07EDEDF4F4F6F40009BD002CC0C4C4C5C5D3EEEEEED3
                D3C4BDBDF7F7BDF7D3D3BDF7F7EED3D2BDBDF7C4EED3F7F7D2E1D3D3D3EED3D3
                D3BD04F70020C0C4D2D3EED3C5C0BDBDF7D9EAECEABD07BD07BDD9DDE7D9BD07
                0707EDF2EFF209ED00330707D90707E70707D907D907D9D9D9BDD9D907D907D9
                BDD9BDD9D9BDD9BDD9BCD9BDE6D8D9D8BAB6F7BCD8D9D8BCF7BDD9B4BA0008BD
                0003C6C6AE0004C60005CAC6C6B8B80006F800096F94B6D7C2D7BB9C97000892
                0013A6A691A691A68F90F7A7DCDB977C7B504E1D0D00000000166376A7BABBD9
                07EEEEEEEDF2F0F2EEEDEAF1F1EDF1ED04F10009F3F2F3F2F3F4F0F4F0001BF4
                0013F2F4F4F4F2F4F2F0F2F2F4F2F0F2F3EDF1F1F00009ED0004EED3EDED0507
                0004BD07BDBD040701ED01C409BD002FF7BDBDC0C4C0C1C5E1D3EEEED3D3C4BD
                C4EED3F7F7F7D2D3EEC4F7F7C4EEC4F7BDD3C5C1C4C5C5C5EED3F7BDF7BDBD00
                04F70018C4D3C1BBF7F7F7E7EAE7E7CBCB0807CBE7D9E9BD0707BD0707ED0039
                F1EDF2EDF2EDEFEDEDED07BDBDD9BDD9BDBDD9BDD907D9BDE7D9BDE707D907D9
                BDD9BD07BDD8D9D8D9DDD9D8BCB6B6B6BCD9BDD9D8F7D6D6BA0009BD04C6001D
                AEC6C6C6C9C8C8C8B8A5F86F6FF8F8F86FF894B698D7C29C97928E928E000592
                000FACA6A6F8B6B6D6DB6D7B7B504E1D0C0000000020686FA7F7F7BCBBBCD9D9
                C4EDEEF2EDEDF1EDF1EAF1EEF4F0F2F3F2F1F3F2F3F304F401F005F401F211F4
                0019F2F4F4F2F4F2F4F4F4F2F2F0F2F2F2F3F1F3F2EFF1F1EDEDF10005ED000C
                07ED07D3EDE10707BD07BD0705BD010704C4001CBDBDBDF7BDF7BDBDF7BDF7BD
                BDC0C0C4C1C5C5D3EED3EEC5EEC4BDBD06F70020D3D3F7F7F7EEC5C4BDF7C4C1
                D3C5BDF7C4EED3D3C4C4B9D3E1C1F7F7F7BCE9E604CD0014080808E8E7E7BD07
                BD0707EDF1F0EDEDF1EAEDF105ED000CF2EDF1EDF2EDED07D9DCD9BC04BD0023
                D9BDBDD9BDBDD9D907D9D9EDF307D9D9EAD8E9D9D8F7B6F7B6BCD9BDDEBDBDD6
                D8D7F70004BD00390707BDBDBDF7BDB8C6BDF7BDCAC8C8CCC68CC6C6AA877F6F
                6C6B6D6E6B6C7694BBC29D9892928E908E928E928E6D9576949D567B7B7B2726
                0C000000002A4CF8B6BDEDEDED07BDBDD9BDD9E007EAF1E7F1EDF1F4F2EEEEEE
                F2F4F0F2F3F3F0F4F0F4F4F0F4F4F4F006F401F209F4001FF2F4F4F2F4F2F4F4
                F4F6F4F2F4F2F2F2F4EFEDEDEDF1F3EDF1F1EDF1EDEDF10006070008D30707BD
                07BDBD0704BD08C4001ABDBDBDF7F7BDF7BDF7F7BDF7F7BDC0C0C4C1C5C1C5D3
                EED3C5C405BD002ED3D3F7F7B9EEC5C5C1C1C2C5D3C4F7BDBDD2D3EEEEEED3D3
                C5C0BBBDF7BDEAE9E7CCE8E8E8CDE8E8E8D9BDBD07BD05ED0009F0EABBD9EAE7
                EAE7F10009ED0030DDEAD9BCBD07D907BDBCBDBCBDD9BCBDBCDCD9EDF2BDD9D8
                D9D9EAD9D8F7B6B6F7D807BBBDE0E0D7D9D7BDE007EDBD0706BD0032F7BDF7F7
                BDBDCAC9C8C8C6C6C88CAE8CAE87A36F6B6C6B6C6B686D6D9498D7989C92908E
                8E8E9595957795687B7B504E260E0000000463F8B6BD04ED0027F3F0EDED0707
                07D9E7E4EDF1EDF4F4F4F2F0F4F2F2F3F2F3F0F3F4F4F3F4F4F2F4F4F0F4F4F4
                F20004F401F208F4004FF2F4F2F4F2F4F4F6F4F2F4F2F2F2F0F2F1EDF1EDEDED
                F1EDF1EDF1E7EDEDD2E0D20707EE0707BD07BD07BD07BDBDBDC4C4EDC4C4C4C0
                C4C4C4C2C0C4BDF7BDF7F7F7BDF7F7BCF7F7BDC0BBC0C4C1C50004D30010C4C0
                C5EED3BDBDF7C4C4D3D3D3C5C5D305F7001CBDBDC4C4D3EEC5C0BDBCF7BDBDEA
                E7E7CBE80807BDE6E7BDBDBD07BD06ED000BD9BDBDF3F7F7F1E7D9EAE70005ED
                003207DDEAD9F7F707D9D8DDE9BDD9D9BD07BDBCDDE7F1EDBCD8D8D9DCD8D8BA
                B6B6F7BBDDE0E0E0DEE0D7D7E0E007EDE0EDEDED0BBD01070508000CCDCAC9CB
                C6F7F7BD07F7F86F076800136D9498989D9594969999959A7C7B7B50301C0E00
                0000002C6876B607EDF0EDF4EDEDF1F0F2EDF3ED070707EDE7EDF2F2F0F2F4F4
                F0F2F3F1F0F3F4F3F0F3F4F4F0F2F4F205F40013F0F4F4F3F2F4F2F4F4F2F4F2
                F4F2F4F3F4F4F60008F20005EFF2EFEDF10005ED000C07EDE7D4EDC4E00707D3
                070709BD0009C4D3ED07BDC4C4C4C00004C40005C2C0C0C2BD0009F70010BCF7
                F7C0BBC0C1C5C5D3D3E1C5D3C4F705BD0025C409EED3F7F7F7C5C4B9F7F7F7C4
                D3C5C0F7F7F7BD07BD07D9BDBDCBBDD9D9EABDBDD907BD0005ED0048F1D807BC
                07E7F7F1F7B6BCD9D9E7EDEDEDD9DCE9D8D6BCEDD9DDDDD9D9BDBD0707BCD8DB
                EFF2EDD907D9E9D9D9D8BCC6B8D7E2E2E2DED7D7D7DEDEDEE0DEDEBDE0EDEDF2
                08BDBD0706BD000807EDEDEDEEEDEDF008ED0007070707BDF76F6C0004680011
                4C686C767699957799967D7D7B5041260E00000000444C6FB7BDEDF2F3F0F2F4
                F0F3F0EDEDF2F3F0F1EDED07EDE7EDF1F2F0F2F1F3F0F1EFF2EFF2F3F0F4F2F0
                F4F4F4F2F4F0F4F4F2F4F4F4F0F4F4F4F2F4F2F4F2F2F3F2F2F407F2001AEEF2
                EDF2F2F0EDEFEDE7EDEDEDF1EDD307D2E0C4D307BD07070705BD001707C4EEED
                07C1C5C0C2C4C4C0C4C0C4C5C5C1C1C1C5C4C0000CF7001EB9C0C2C1C0C1C5D3
                D3D3C5C0F7F7BDBDEED3F7F7C0EED3EE09D3C0D3C5C104F701BD010705BD000D
                07BDD9DDE7BDBDD9BBC4EDEDF20004ED0034D9D8EAE7B6F7F307EDF1D907EDED
                EDD8D9DCD9E9D9DCD8DCE9D9BD07F7EDBDBCD9DCF1F0BDD9D8D8D8EAD8D9CACB
                EDE5E5E2E2E204DE01D706DE0039BBBDEDF1EFE707F7BDF7BDF7F7F7BDEDF3F3
                F3EFF3EDF3EDEFEDF3EDEDF3EDEFEDEDED08BDB6F868536846534C6976957586
                7B7D7B7B27210E0000000066637685B7C0EEEEF4F4F2F4EDF2F3F2EFF2F1F0F2
                F3F4EDF0EDEDEDF1F1F1EFF0F3F0F3F0F3F2F4F2F3F0F2F2F4F4F2F2F4F2F4F3
                F2F3F4F2F0F4F4F2F4F2F2F3F2F3F4F2F2F2F0F2F2F2EEF2EEEDF2EEE5EEF2EE
                F2EFEDEEF1EFEED3E0C407D307BD07BDBD0705BD0004C5ED07BD04C50013C1C1
                C2C0C5C1C1C5C5C5D3E1D3E1D3C5C4BDB9000CF70019C0C0C1C5C5C5D3D3D3C5
                C5EEC4F7BDBDBDC4C5D3EED3EEC5C00004F709BD0008DCD8D9BD07E7BDC405ED
                0043F1EDEDF1EAEBEAE9EABCBCBDD8EDEDED07D907BCF1F4EDF1EAD9DCD807BD
                BDEDF7BCD8DDF0F1BDD8D9D9D9DCD8BCCBCB07E2E5E3E5E5E3E2E0DEE2DED7DE
                D7DEDED7D70004D60017BCD6BAD6BAD8D8BAD8BCD8D9E7EAEAEAECF1ECECF3F3
                EC000AF30005ECE7BCA26300044600094CF8807C7D5027260E00000000456876
                94BEBEEDC5EEF0F0F4F4F0F3F0F2F6F0F4F3F2EFF2F3F4F4F2EFEDEDF3EFF0EF
                F3F0F3F0F2F4F0F2F4F3F3F4F0F4F0F4F2F3F4F4F2F0F4F0F4F2F4F2F2F3F2F4
                F2F2F30006F20016EDEDF1F1F2EEF2E1F2E1F2E1EEE1EED3EED307C4E1070BBD
                0009ED07BDC1C5C1C1C5C10008C5000CEED3EEEEEE09D509D5CFD2D20DF7000B
                C0C0C2C1C5D3D3C5D3C4C00005F70014BDC4EEC1C0F7F7F7D8E7D9E6D9BDBDBD
                D9D9D8EA05BD05ED0006EAEAEAEDEDE704EA0071DDD9D9D9EDEDEDD9E9D9DCED
                EED4F2D9D8D8D9BDBDBD07F7BCDAE7F2EDBCBCD8DCD8D9D8BCC6CBE0E5E5E5E3
                E3E2E2DEDED7D7D7E0D7E0DEDED7D9D6D6BAD6BAD6D6BAD6D6B3B3B1B1B1D6BA
                AC9CBA97D697D6ACD6D6BAD6D8B3B3B3DCB3E9B3E9E9E9E6B3A0634645EDEDF7
                B67F51260E00000000074C6F85BEC0EED30004D50014F0F0F0F2F3F0F1F0EDED
                F4F2EDF2EDEFF2F4F0F304EF0024F3F1EDF2EEEDF2F2F1F2F2EEF2EEF2EDF2F2
                F0EDF1F2EDF2F0F2EEF2EDF3F2F1F1F1EDF106ED0013F1EDEDE1EEE1EEE1EEE1
                E1EDD3EDD3E1D307D3000ABD00090707ED07BDBDBDC4C40006C50015D3E1D3C5
                E1D3D5CFD5D5D2CFD0CFD0CFD5D4D2CBBD000CF70021C0C0C2C1C5C5D3D3C5C4
                BDF7F7C0D3C2B9F7F7F7E6D9E9D9E6D9D9E6D9D9D9E6D90004BD04ED003DE7D9
                EDE6D9EDEDED0707D907EDD907EDEDEDD9D8E0E4D8D9E7E7D8BCBDBD07F70707
                F7D8D8EDED07BCD8D9D8D9D8BCBCC7C7D2E3E2E4E2E2DEDEDED7DE0004D701BD
                04D705D80010D6ADD6BAD6BAD6BCB3D6B3B1D8B1BAD604BA01D601BA0EB1000D
                B0B1B0B1A1D9D9ED07B66F441A00000000126876B7B9D2D2E0D2D4D3D4CFD4D2
                07D2D4EE08ED01F205ED0003D2EDD20004ED01070BED010712ED0003E7EDE700
                04070004E7E0E0ED08E001C401D205C40009BDBDBDF7BDF7BDF7BD00040704BD
                0020F7F7BDF7C4C4C4C5C4E1C4D3D2D2D5D2D0D2BDBDCED2CED2CECED2EDF108
                E7BD0DF7000CB7C0C0C0C4C4C5C4C4C4C5C004F706D9000BD8D9D8D9D8D9D9BD
                BDF7BD0004070005D9D9BDBDD9000707001CD9E7D9070707BCD9D8D9D8D8D9D8
                D8BDBDBD07BD07F7BCBCD6EDEDBD04BC0050D8BCBCC7C7C7BDE0DFDEDED7DEDE
                D7C2D7BBD7BBBBD7BBD7D7BBBBD6D8ADD8B3D8B1D8B1BCB1D6ADD6ADD6ADD6B1
                BAB1BAB1BAACBABAB1BAADB1ADB1B1ADB1B1B1ACB1B1ACB1ACB1B1AAADD8BCA7
                631A00000015686BB7CECBC0BCD7BCBDC4D2CBD207D2D2CBD2D2C4000B070029
                C40707BD070707BD07C4070707C407C407C4070707BDBD07D907D90707C407BD
                07D907BDBDBD07BDD90006BD0011C4BBC4BDC2BDC2BDC2BDBDC0BDC0BDBBC000
                08F70009B6BD070707F707BDBD0008F70028B9C0BDC4D2CEBDBDB9BDBDF7B9CE
                B9C7C0C7BDBCBCD9D9D9CBBDBDF7B6B6F7B6F7B6B6F7B6F7B6F704B7000AC0C0
                C0BBB7F7B6B6F7BA05BC000BD9BCBCBCBABCBCBCF7BCF70004BD0005BCBDBDBC
                F70007BD0004CBE6BCF704BD01BC01F706BC01F704BD0019B6BCBABC07BDF7BA
                F7BCBABCF7BAB8B9B8B8BDBBD7C2DEBBD70008BB0004D6BBD6BB09BA0011ADBA
                BAADBAACBAACBAACBAADBAACBAACBA0014AC01AA048000037E3B190000000021
                4C6FB9B9F7B6B7B6B6BAF7F7B9B9B9F7B9B9F7B9F7B7F7B7F7B9BDF7BDF7F7F7
                B80005F701B912F701BC0FF70012B6F7F7B6F7F7B7F7B7F7B7F7B7B7F7B7B7F7
                05B70AB601B701B608F709B601B701B806B60054B9B8B788B8B7B8B6BAA9B6B6
                F7B6B6F7F7F7B6B6B6F8B6F8B6F8B6F8B6F8B6B694B6B685B6F8B6F8B6A9B6A7
                B6A7B6A7B6BAB6BAA7BAB6A7BAB6BAB6B6BAB6BAB6BAB6F7B6F7B6F7BAF7BABA
                BCB6B6F7B6F7B6BA07B60029F7B6B6F7F8B6A7BAF7B6B6B6F7F7F7B6B6B68787
                B687B6B6BB97BA98B797BB97B697BB97BB9797B6970007A7000AACA9ACA7ACA7
                A9A7A7A912A70013A6A7A7A7A6A7A6A7A6A7927F807F807F80500E0000000008
                68F885F8F876F86F04F8000785F8F885F8F885004DF8000D6FF86F6FF86F6F6F
                F8F876F876000DF8016F01F8056F0005F8F86FF8850006F800056FA36FF86F00
                0BF8136F0005F86FF86FF800046F000DF86FF86FF86FF86FA3F86FF86F000BF8
                016F06F800046FF8A36F08F800036F6F6F0004F8016F05F800196F6FF8F87F6F
                6FF86FF8F894F894F8946F94F8946FF8F86FF8000D6F0029906F6F906F6F6F90
                6F6F906F6F906F6E6F906F6E6F906F6E6F906F6E6F6E6F6E6F6A7F6B6A7F6B6A
                41000001}
              ShowHint = True
              Stretch = True
              OnClick = imgGamePicClick
            end
          end
        end
        object ScriptPage: TTabSheet
          Caption = 'ScriptPage'
          ImageIndex = 11
          TabVisible = False
          object ScriptMemo: TSynMemo
            Left = 0
            Top = 0
            Width = 324
            Height = 377
            Cursor = crIBeam
            Align = alClient
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Courier New'
            Font.Style = []
            ParentColor = False
            ParentFont = False
            TabOrder = 0
            BorderStyle = bsNone
            Gutter.Font.Charset = DEFAULT_CHARSET
            Gutter.Font.Color = clWindowText
            Gutter.Font.Height = -11
            Gutter.Font.Name = 'Terminal'
            Gutter.Font.Style = []
            Gutter.Visible = False
            Highlighter = WndMain.SynSCISyn1
            Keystrokes = <
              item
                Command = ecUp
                ShortCut = 38
              end
              item
                Command = ecSelUp
                ShortCut = 8230
              end
              item
                Command = ecScrollUp
                ShortCut = 16422
              end
              item
                Command = ecDown
                ShortCut = 40
              end
              item
                Command = ecSelDown
                ShortCut = 8232
              end
              item
                Command = ecScrollDown
                ShortCut = 16424
              end
              item
                Command = ecLeft
                ShortCut = 37
              end
              item
                Command = ecSelLeft
                ShortCut = 8229
              end
              item
                Command = ecWordLeft
                ShortCut = 16421
              end
              item
                Command = ecSelWordLeft
                ShortCut = 24613
              end
              item
                Command = ecRight
                ShortCut = 39
              end
              item
                Command = ecSelRight
                ShortCut = 8231
              end
              item
                Command = ecWordRight
                ShortCut = 16423
              end
              item
                Command = ecSelWordRight
                ShortCut = 24615
              end
              item
                Command = ecPageDown
                ShortCut = 34
              end
              item
                Command = ecSelPageDown
                ShortCut = 8226
              end
              item
                Command = ecPageBottom
                ShortCut = 16418
              end
              item
                Command = ecSelPageBottom
                ShortCut = 24610
              end
              item
                Command = ecPageUp
                ShortCut = 33
              end
              item
                Command = ecSelPageUp
                ShortCut = 8225
              end
              item
                Command = ecPageTop
                ShortCut = 16417
              end
              item
                Command = ecSelPageTop
                ShortCut = 24609
              end
              item
                Command = ecLineStart
                ShortCut = 36
              end
              item
                Command = ecSelLineStart
                ShortCut = 8228
              end
              item
                Command = ecEditorTop
                ShortCut = 16420
              end
              item
                Command = ecSelEditorTop
                ShortCut = 24612
              end
              item
                Command = ecLineEnd
                ShortCut = 35
              end
              item
                Command = ecSelLineEnd
                ShortCut = 8227
              end
              item
                Command = ecEditorBottom
                ShortCut = 16419
              end
              item
                Command = ecSelEditorBottom
                ShortCut = 24611
              end
              item
                Command = ecToggleMode
                ShortCut = 45
              end
              item
                Command = ecCopy
                ShortCut = 16429
              end
              item
                Command = ecCut
                ShortCut = 8238
              end
              item
                Command = ecPaste
                ShortCut = 8237
              end
              item
                Command = ecDeleteChar
                ShortCut = 46
              end
              item
                Command = ecDeleteLastChar
                ShortCut = 8
              end
              item
                Command = ecDeleteLastChar
                ShortCut = 8200
              end
              item
                Command = ecDeleteLastWord
                ShortCut = 16392
              end
              item
                Command = ecUndo
                ShortCut = 32776
              end
              item
                Command = ecRedo
                ShortCut = 40968
              end
              item
                Command = ecLineBreak
                ShortCut = 13
              end
              item
                Command = ecLineBreak
                ShortCut = 8205
              end
              item
                Command = ecTab
                ShortCut = 9
              end
              item
                Command = ecShiftTab
                ShortCut = 8201
              end
              item
                Command = ecContextHelp
                ShortCut = 16496
              end
              item
                Command = ecSelectAll
                ShortCut = 16449
              end
              item
                Command = ecCopy
                ShortCut = 16451
              end
              item
                Command = ecPaste
                ShortCut = 16470
              end
              item
                Command = ecCut
                ShortCut = 16472
              end
              item
                Command = ecBlockIndent
                ShortCut = 24649
              end
              item
                Command = ecBlockUnindent
                ShortCut = 24661
              end
              item
                Command = ecLineBreak
                ShortCut = 16461
              end
              item
                Command = ecInsertLine
                ShortCut = 16462
              end
              item
                Command = ecDeleteWord
                ShortCut = 16468
              end
              item
                Command = ecDeleteLine
                ShortCut = 16473
              end
              item
                Command = ecDeleteEOL
                ShortCut = 24665
              end
              item
                Command = ecUndo
                ShortCut = 16474
              end
              item
                Command = ecRedo
                ShortCut = 24666
              end
              item
                Command = ecGotoMarker0
                ShortCut = 16432
              end
              item
                Command = ecGotoMarker1
                ShortCut = 16433
              end
              item
                Command = ecGotoMarker2
                ShortCut = 16434
              end
              item
                Command = ecGotoMarker3
                ShortCut = 16435
              end
              item
                Command = ecGotoMarker4
                ShortCut = 16436
              end
              item
                Command = ecGotoMarker5
                ShortCut = 16437
              end
              item
                Command = ecGotoMarker6
                ShortCut = 16438
              end
              item
                Command = ecGotoMarker7
                ShortCut = 16439
              end
              item
                Command = ecGotoMarker8
                ShortCut = 16440
              end
              item
                Command = ecGotoMarker9
                ShortCut = 16441
              end
              item
                Command = ecSetMarker0
                ShortCut = 24624
              end
              item
                Command = ecSetMarker1
                ShortCut = 24625
              end
              item
                Command = ecSetMarker2
                ShortCut = 24626
              end
              item
                Command = ecSetMarker3
                ShortCut = 24627
              end
              item
                Command = ecSetMarker4
                ShortCut = 24628
              end
              item
                Command = ecSetMarker5
                ShortCut = 24629
              end
              item
                Command = ecSetMarker6
                ShortCut = 24630
              end
              item
                Command = ecSetMarker7
                ShortCut = 24631
              end
              item
                Command = ecSetMarker8
                ShortCut = 24632
              end
              item
                Command = ecSetMarker9
                ShortCut = 24633
              end
              item
                Command = ecNormalSelect
                ShortCut = 24654
              end
              item
                Command = ecColumnSelect
                ShortCut = 24643
              end
              item
                Command = ecLineSelect
                ShortCut = 24652
              end
              item
                Command = ecMatchBracket
                ShortCut = 24642
              end>
            ReadOnly = True
          end
        end
        object PalPrevPage: TTabSheet
          ImageIndex = 12
          TabVisible = False
          object imPalPrev: TImage
            Left = 0
            Top = 0
            Width = 324
            Height = 377
            Align = alClient
          end
        end
      end
    end
  end
  object popExplorer: TPopupMenu
    Images = ilExplorer
    Left = 483
    Top = 2
    object Add1: TMenuItem
      Caption = '&Add'
      ImageIndex = 0
      OnClick = tbAddClick
    end
    object Extract1: TMenuItem
      Caption = '&Extract'
      ImageIndex = 1
      OnClick = tbExtractClick
    end
    object Delete1: TMenuItem
      Caption = '&Delete'
      ImageIndex = 2
      OnClick = tbDeleteClick
    end
    object MenuItem2: TMenuItem
      Caption = '-'
    end
    object RebuildResources2: TMenuItem
      Caption = 'Re&build Resources'
      ImageIndex = 3
      OnClick = tbRebuildClick
    end
    object MenuItem3: TMenuItem
      Caption = '-'
    end
    object ViewStyle1: TMenuItem
      Caption = 'View &Style'
      ImageIndex = 5
      object LargeIcon1: TMenuItem
        Caption = 'L&arge Icon'
        GroupIndex = 4
        RadioItem = True
        OnClick = ViewStylesClick
      end
      object SmallIcon1: TMenuItem
        Tag = 1
        Caption = '&Small Icon'
        GroupIndex = 4
        RadioItem = True
        OnClick = ViewStylesClick
      end
      object List1: TMenuItem
        Tag = 2
        Caption = '&List'
        GroupIndex = 4
        RadioItem = True
        OnClick = ViewStylesClick
      end
      object Details1: TMenuItem
        Tag = 3
        Caption = '&Details'
        GroupIndex = 4
        RadioItem = True
        OnClick = ViewStylesClick
      end
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object Properties1: TMenuItem
      Caption = 'P&roperties'
      ImageIndex = 4
      OnClick = tbPropetiesClick
    end
  end
  object popViewStyle: TPopupMenu
    Left = 455
    Top = 2
    object LargeIcon2: TMenuItem
      Caption = 'L&arge Icon'
      GroupIndex = 2
      RadioItem = True
      OnClick = ViewStylesClick
    end
    object SmallIcon2: TMenuItem
      Tag = 1
      Caption = '&Small Icon'
      GroupIndex = 2
      RadioItem = True
      OnClick = ViewStylesClick
    end
    object List2: TMenuItem
      Tag = 2
      Caption = '&List'
      GroupIndex = 2
      RadioItem = True
      OnClick = ViewStylesClick
    end
    object Details2: TMenuItem
      Tag = 3
      Caption = '&Details'
      GroupIndex = 2
      RadioItem = True
      OnClick = ViewStylesClick
    end
  end
  object ilExplorer: TImageList
    Height = 22
    Width = 22
    Left = 583
    Top = 4
    Bitmap = {
      494C010107000900040016001600FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      000000000000360000002800000058000000420000000100200000000000C05A
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000008080800080808000808080008080800080808000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000008080800080808000808080008080800080808000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000808080008080800080808000808080008080
      8000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008080800080808000808080008080
      8000808080008080800000000000000000000000000080808000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008080800080808000808080008080
      8000808080000000000000000000000000000000000000000000808080008080
      8000000000000000000000000000000000000000000000000000808080008080
      8000808080008080800080808000808080000000000000000000000000008080
      8000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008080
      8000808080008080800080808000808080008080800000000000000000000000
      000000000000000000009C9C9C009C9C9C000000000000000000808080000000
      0000000000000000000000000000000000000000000000000000000000008080
      8000808080008080800080808000808080000000000000000000000000000000
      000000000000BDBDBD00BDBDBD00BDBDBD00BDBDBD0000000000000000008080
      8000000000000000000000000000808080008080800080808000808080000000
      000000000000000000000000000000000000BDBDBD00BDBDBD00000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000808080008080
      80000000000000000000000000000000000000000000A5A5A500A5A5A500A5A5
      A500A5A5A500A5A5A500A5A5A500A5A5A5000000000000000000808080000000
      0000000000000000000000000000000000008080800080808000808080000000
      000000000000000000000000000000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00ADADAD00ADADAD00ADADAD00ADADAD0000000000000000008080
      800000000000000000000000000000000000000000000000000000000000BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000B5B5B500B5B5B500B5B5B500B5B5B500B5B5B500FF636300FF636300FF63
      6300FF636300FF636300BDBDBD00BDBDBD000000000000000000808080000000
      000000000000000000000000000000000000000000000000000000000000BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BD000000BD000000BD00
      0000BDBDBD00000000000000000000000000BDBDBD0000000000000000008080
      8000000000000000000000000000BDBDBD00BDBDBD00BDBDBD00BDBDBD00CECE
      CE00CECECE00CECECE00CECECE00CECECE00CECECE00CECECE00000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000BDBDBD00BDBD
      BD00FF636300FF636300CECECE00FF636300FF636300CECECE00CECECE00CECE
      CE00CECECE00CECECE00CECECE00CECECE000000000000000000808080000000
      000000000000000000000000000000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BD000000FFFFFF00BD00
      0000BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD0000000000000000008080
      8000000000000000000000000000BDBDBD00D6D6D60000000000D6D6D600D6D6
      D600D6D6D60000000000D6D6D600D6D6D600BDBDBD00BDBDBD00000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000D6D6D600D6D6
      D600D6D6D600D6D6D600D6D6D600D6D6D600D6D6D600FF636300FF636300FF63
      6300FF636300FF636300DEDEDE00DEDEDE000000000000000000808080000000
      000000000000000000000000000000000000BDBDBD00BD000000BD000000BD00
      0000D6D6D600000000000000000000000000D6D6D600BD000000BD000000D6D6
      D600D6D6D600D6D6D600D6D6D600D6D6D600D6D6D60000000000000000008080
      8000000000000000000000000000BDBDBD00E7E7E70000000000E7E7E700E7E7
      E7000000000000000000BDBDBD00BDBDBD000000000000000000000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E7E7E700E7E7
      E700FF636300FF636300E7E7E700FF636300FF636300E7E7E700E7E7E700E7E7
      E700E7E7E700E7E7E700E7E7E700E7E7E7000000000000000000808080000000
      000000000000000000000000000000000000BDBDBD00BD000000FFFFFF00BD00
      0000DEDEDE00DEDEDE00DEDEDE00DEDEDE00DEDEDE00DEDEDE00DEDEDE00DEDE
      DE00DEDEDE00DEDEDE00DEDEDE00DEDEDE00DEDEDE0000000000000000008080
      8000000000000000000000000000BDBDBD00EFEFEF0000000000000000000000
      00000000000000FFFF00000000000000000000BDBD0000BDBD00000000000000
      0000808080008080800080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000EFEFEF00EFEF
      EF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00FF636300FF636300FF63
      6300FF636300FF636300F7F7F700F7F7F7000000000000000000808080000000
      000000000000000000000000000000000000BDBDBD00BD000000BD000000E7E7
      E700EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00BD000000BD000000BD00
      0000EFEFEF00000000000000000000000000EFEFEF0000000000000000008080
      8000000000000000000000000000BDBDBD00FFFFFF0000000000FFFFFF000000
      0000FFFFFF000000000000FFFF0000BDBD0000BDBD0000BDBD0000BDBD0000BD
      BD00000000000000000080808000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FF636300FF636300FFFFFF00FF636300FF636300FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000808080000000
      000000000000000000000000000000000000BDBDBD00F7F7F700F7F7F700F7F7
      F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700BD000000FFFFFF00BD00
      0000F7F7F700F7F7F700F7F7F700F7F7F700F7F7F70000000000000000008080
      8000000000000000000000000000BDBDBD00FFFFFF000000000000000000FFFF
      FF00FFFFFF00FFFFFF000000000000FFFF0000BDBD0000BDBD0000BDBD000000
      000000000000C608080000000000808080008080800000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FF636300FF636300FF63
      6300FF636300FF636300FFFFFF00FFFFFF000000000000000000808080000000
      000000000000000000000000000000000000BDBDBD00BD000000BD000000BD00
      0000FFFFFF00000000000000000000000000FFFFFF00BD000000BD000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000008080
      8000000000000000000000000000BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF000000000000FFFF0000FFFF00000000000000
      000000000000C6080800BD000000000000008080800000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FF636300FF636300FFFFFF00FF636300FF636300FFFFFF00FFFFFF00FFFF
      FF00BDBDBD00BDBDBD00BDBDBD00FFFFFF000000000000000000808080008080
      800080808000808080000000000000000000BDBDBD00BD000000FFFFFF00BD00
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000008080
      8000000000000000000000000000BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000FFFF00000000000000
      0000CE101000C6080800BD000000000000008080800000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      00000000000000000000BDBDBD00BDBDBD000000000000000000000000000000
      000000000000808080000000000000000000BDBDBD00BD000000BD000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BD000000BD000000BD00
      0000FFFFFF00000000000000000000000000FFFFFF0000000000000000008080
      8000000000000000000000000000BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00BDBDBD000000000000000000FF9C
      9C00FF9C9C00C6080800BD000000000000008080800000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00BDBDBD00BDBDBD00FFFFFF00FFFFFF000000000021CE
      FF00007BA50021CEFF0000000000000000000000000000000000BD000000BD00
      000000000000808080000000000000000000BDBDBD00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BD000000FFFFFF00BD00
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000008080
      8000000000000000000000000000BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00BDBDBD0000000000000000000000000000000000BD00
      0000FF9C9C00FF9C9C00BD000000000000008080800000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF000000000000000000BDBDBD00BDBDBD000000000021CEFF00007B
      A50084E7FF0084E7FF0084E7FF0084E7FF000000000000000000FF6B6300FF6B
      630000000000808080000000000000000000BDBDBD00BD000000BD000000BD00
      0000FFFFFF00000000000000000000000000FFFFFF00BD000000BD000000FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000008080
      8000000000000000000000000000BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00BDBDBD0000000000FFFFFF00FFFFFF00000000000000
      0000BD000000FF9C9C00FF9C9C00000000008080800000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF000000000084E7FF0021CEFF000000000000000000FFFFFF00007BA50084E7
      FF0084E7FF0084E7FF0084E7FF0084E7FF0084E7FF0000000000FF9C9C00FF9C
      9C0000000000808080000000000000000000BDBDBD00BD000000FFFFFF00BD00
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      000000000000FF6B6300FF6B6300FF6B6300FF6B630000000000000000008080
      8000000000000000000000000000BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00BDBDBD0000000000FFFFFF00BDBDBD00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF0000000000FFFFFF0084E7FF0021CEFF000000000000000000FFFFFF0084E7
      FF0084E7FF0084E7FF0084E7FF0084E7FF0084E7FF0000000000FF9C9C00FF9C
      9C0000000000808080000000000000000000BDBDBD00BD000000BD0000000000
      000000000000000000000000000000000000FF6B6300FF6B6300FF6B6300FF6B
      6300FF6B6300FF6B6300FF6B6300FF6B6300FF6B630000000000000000008080
      8000000000000000000000000000BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00BDBDBD0000000000BDBDBD0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF0000000000FFFFFF0084E7FF0021CEFF0021CEFF000000000084E7
      FF0084E7FF0084E7FF0084E7FF00C6F7FF00C6F7FF0000000000FF6B6300FF6B
      630000000000808080000000000000000000000000000000000000000000FF6B
      6300FF6B6300FF6B6300FF6B6300FF6B6300FF6B6300FF6B6300FF6B6300FF6B
      6300FF6B63000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000BDBDBD00FFFFFF00FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000FFFFFF0084E7FF0084E7FF00C6F7FF00C6F7
      FF00C6F7FF00C6F7FF00C6F7FF00C6F7FF00FFFFFF0000000000FF9C9C00FF9C
      9C0000000000808080000000000000000000BD000000FF6B6300FF6B6300FF6B
      6300FF6B6300FF6B6300FF6B6300FF6B6300FF6B630000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000084E7FF00C6F7FF00C6F7FF00C6F7
      FF00C6F7FF00C6F7FF00FFFFFF00FFFFFF00FFFFFF0000000000FF6B6300FF6B
      630000000000000000000000000000000000BD000000FF6B6300FF6B6300FF6B
      6300000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000080808000808080008080800080808000808080008080
      8000808080008080800080808000808080008080800080808000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000008080800080808000808080008080800080808000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000808080008080
      8000808080008080800080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000808080008080
      8000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000808080008080800000000000808080008080
      8000808080000000000000000000000000000000000000000000808080008080
      8000000000000000000000000000000000000000000000000000000000000000
      0000808080008080800080808000808080008080800080808000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000808080008080
      8000000000008080800080808000808080008080800000000000000000000000
      0000000000000000000080808000808080000000000000000000000000000000
      00000000000000000000000000000000000021CEFF0021CEFF0021CEFF0021CE
      FF0021CEFF0021CEFF0021CEFF0021CEFF00007BA50000ADDE00000000008080
      8000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008080800080808000000000000000
      000000000000BDBDBD00BDBDBD00BDBDBD00BDBDBD0000000000000000008080
      8000000000000000000000000000000000008080800080808000808080008080
      8000000000000000000000000000000000000000000080808000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008080
      80008080800000000000000000000000000000000000BDBDBD00BDBDBD00BDBD
      BD00BDBDBD000000000000000000808080000000000000000000000000008080
      800080808000000000000000000000A500000000000084E7FF0084E7FF0084E7
      FF0084E7FF0084E7FF0084E7FF0084E7FF00007BA50000ADDE0000ADDE000000
      0000808080008080800000000000000000000000000000000000000000008080
      800080808000808080000000000000A500000000000000000000BDBDBD00BDBD
      BD00BDBDBD009494940094949400949494009C9C9C0000000000000000008080
      8000000000000000000080808000808080000000000000000000000000000000
      0000BDBDBD00BDBDBD00BDBDBD00BDBDBD000000000000000000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000080808000808080000000000000FFFF0000BDBD000000
      000000000000BDBDBD00BDBDBD00BDBDBD00BDBDBD00BD00BD00BD00BD00A5A5
      A500A5A5A5000000000000000000808080000000000000000000808080000000
      000000000000000000000000000000FF000000A500000000000084E7FF0084E7
      FF0084E7FF0084E7FF0084E7FF0084E7FF00007BA50021CEFF0000ADDE0000AD
      DE00000000008080800000000000000000000000000000000000000000000000
      000000000000000000000000000000FF000000A5000000000000A5A5A500A5A5
      A500A5A5A500FF6B6300FF6B6300FF6B6300A5A5A50000000000000000008080
      800000000000000000000000000000000000BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00B5B5B500B5B5B500B5B5B500B5B5B5000000000000000000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000FFFF0000BDBD000000
      0000BDBDBD00ADADAD000000FF000000FF00B5B5B500BD00BD00BD00BD00B5B5
      B500B5B5B50000000000000000008080800000000000808080000000000000A5
      000000A5000000A5000000A5000000FF000000FF000000A500000000000084E7
      FF0084E7FF0084E7FF0084E7FF0084E7FF00007BA50021CEFF0000ADDE0000AD
      DE0000000000808080000000000000000000000000000000000000A5000000A5
      000000A5000000A5000000A5000000FF000000FF000000A5000000000000FF6B
      6300FF6B6300BDBDBD00BDBDBD00BDBDBD00BDBDBD0000000000000000008080
      80000000000000000000BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD000000000000000000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000BDBDBD00BDBDBD000000000000FFFF0000BDBD000000
      0000BDBDBD00BDBDBD000000FF000000FF00BDBDBD00BD00BD00BD00BD00BDBD
      BD00BDBDBD00000000000000000080808000808080000000000000A5000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000A500000000
      000084E7FF0084E7FF0084E7FF0084E7FF00007BA50021CEFF0021CEFF0000AD
      DE00000000008080800000000000000000000000000000A5000000FF000000FF
      000000FF000000FF000000FF000000FF000000FF000000FF000000A500000000
      0000CECECE00FF6B6300FF6B6300FF6B6300CECECE0000000000000000008080
      80000000000000000000BDBDBD00CECECE00CECECE00CECECE00CECECE00CECE
      CE00FF6B6300FF6B6300FF6B6300CECECE000000000000000000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000BDBDBD00BDBDBD000000000000FFFF0000BDBD000000
      0000BDBDBD00BDBDBD000000FF000000FF00CECECE00BD00BD00BD00BD00CECE
      CE00CECECE00000000000000000080808000000000000000000000A5000000FF
      0000FFFFFF00FFFFFF00FFFFFF0000FF000000FF0000FFFFFF000000000084E7
      FF0084E7FF0084E7FF0084E7FF0084E7FF00007BA50021CEFF0021CEFF0000AD
      DE000000000080808000000000000000000000A5000000FF000000FF0000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0000FF000000FF0000FFFFFF0000000000FF6B
      6300FF6B6300D6D6D600D6D6D600D6D6D600DEDEDE0000000000000000008080
      80000000000000000000BDBDBD00DEDEDE00FF6B6300FF6B6300FF6B6300FF6B
      6300DEDEDE00DEDEDE00DEDEDE00DEDEDE000000000000000000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000BDBDBD00DEDEDE000000000000FFFF0000BDBD000000
      0000BDBDBD00DEDEDE000000FF000000FF00E7E7E700E7E7E700E7E7E700E7E7
      E700E7E7E700000000000000000080808000000000000000000000A5000000FF
      0000000000000000000000000000FFFFFF00FFFFFF000000000021CEFF0021CE
      FF0084E7FF0084E7FF0084E7FF0084E7FF00007BA50021CEFF0021CEFF0000AD
      DE000000000080808000000000000000000000A5000000FF000000A500000000
      0000000000000000000000000000FFFFFF00FFFFFF0000000000E7E7E700E7E7
      E700E7E7E700FF6B6300FF6B6300FF6B6300E7E7E70000000000000000008080
      80000000000000000000BDBDBD00FF6B6300E7E7E700E7E7E700E7E7E700E7E7
      E700FF6B6300FF6B6300FF6B6300E7E7E7000000000000000000808080000000
      0000000000008080800080808000000000000000000000000000000000000000
      00000000000000000000BDBDBD00EFEFEF000000000000FFFF0000BDBD000000
      0000BDBDBD00EFEFEF00EFEFEF00EFEFEF00EFEFEF0000000000000000000000
      000000000000000000000000000080808000000000000000000000A5000000A5
      0000000000000000000000000000FFFFFF000000000021CEFF0021CEFF0021CE
      FF00C6F7FF00C6F7FF00C6F7FF00C6F7FF00007BA50021CEFF0000ADDE0000AD
      DE000000000080808000000000000000000000A5000000A500000000000021CE
      FF0084E7FF0084E7FF0000000000FFFFFF0000000000EFEFEF00FF6B6300FF6B
      6300FF6B6300BDBDBD00BDBDBD00BDBDBD00BDBDBD0000000000000000008080
      80000000000000000000BDBDBD00F7F7F700FF6B6300FF6B6300FF6B6300FF6B
      6300F7F7F700F7F7F700F7F7F700F7F7F7000000000000000000808080000000
      0000000000000000000080808000808080000000000000000000000000000000
      00000000000000000000BDBDBD00F7F7F7000000000000FFFF0000BDBD000000
      0000BDBDBD00F7F7F700000000000000000000000000D6212100DE292900DE31
      3100E7393900000000000000000080808000000000000000000000A500000000
      0000FF6B6300000000000000000000000000007BA50000A5D60000A5D60000A5
      D600007BA500007BA500007BA500007BA500007BA50000ADDE0000ADDE0000AD
      DE000000000080808000000000000000000000A5000000A500000000000021CE
      FF0084E7FF0084E7FF000000000000000000BDBDBD00FF6B6300FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000008080
      80000000000000000000BDBDBD00FF6B6300FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000FFFFFF000000000000000000808080000000
      00000000BD000000BD0000000000808080008080800000000000000000000000
      00000000000000000000BDBDBD00FFFFFF000000000000FFFF0000BDBD000000
      00000000000000000000BD000000CE101000D6212100D6212100DE292900DE31
      3100E7393900000000000000000080808000000000000000000000A500000000
      0000FFFFFF000000000000ADDE0021CEFF0021CEFF0021CEFF0000ADDE00007B
      A50000ADDE0021CEFF0021CEFF0021CEFF0000ADDE00007BA50000ADDE0000AD
      DE000000000080808000000000000000000000A500000000000021CEFF0084E7
      FF0084E7FF0084E7FF0084E7FF0000000000BDBDBD00FFFFFF00FF6B6300FF6B
      6300FF6B630000000000FFFFFF00FFFFFF000000000000000000000000008080
      80000000000000000000BDBDBD00FFFFFF00FF6B6300FF6B6300FF6B6300FF6B
      6300000000000000BD000000BD00000000000000000000000000000000000000
      BD000000BD000000BD000000BD00000000008080800000000000000000000000
      0000000000000000000000000000000000000000000000FFFF0000BDBD000000
      0000BD000000BD000000BD000000CE101000D621210000000000000000000000
      000000000000000000000000000080808000000000000000000000A500000000
      0000FF6B6300FF6B63000000000000ADDE0021CEFF0021CEFF0021CEFF0000AD
      DE00007BA50000ADDE0021CEFF0021CEFF0021CEFF0000ADDE00007BA50000AD
      DE000000000080808000000000000000000000A500000000000021CEFF0084E7
      FF0084E7FF0084E7FF0084E7FF0000000000BDBDBD00FF6B6300FFFFFF00FFFF
      FF00FFFFFF0000000000FFFFFF00000000000000000000000000000000008080
      80000000000000000000BDBDBD00FF6B6300FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000BD006363FF000000BD0000000000000000000000BD000000
      BD006363FF006363FF000000BD00000000000000000000000000000000000000
      00000000000000000000BD000000D62121000000000000000000000000000000
      0000BD000000BD00000000000000000000000000000000000000000000000000
      00000000000000000000000000008080800000000000BDBDBD0000000000FFFF
      FF00FFFFFF00FFFFFF00FF6B63000000000000ADDE0000ADDE0000ADDE0000AD
      DE0000ADDE00007BA50000ADDE0000ADDE0000ADDE0000ADDE0000ADDE00007B
      A500000000008080800000000000000000000000000021CEFF0084E7FF0084E7
      FF0084E7FF0084E7FF0084E7FF0000000000BDBDBD00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      00000000000000000000BDBDBD00FFFFFF00FF6B6300FF6B6300FF6B6300FF6B
      6300000000009C9CFF006363FF006363FF000000BD000000BD006363FF006363
      FF006363FF000000BD0000000000000000000000000000000000000000000000
      00000000000000000000BD0000000000000000000000BDBDBD00848484000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000BDBDBD00FFFFFF00BD00
      0000FF6B6300BDBDBD00BDBDBD00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000C6F7FF0084E7FF0084E7FF0084E7FF0084E7
      FF0084E7FF0084E7FF0084E7FF0000000000BDBDBD00FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000BDBDBD00FF6B6300FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000000000000000BD006363FF006363FF006363FF006363FF006363
      FF000000BD000000000000000000000000000000000000000000000000000000
      000000000000848484000000000084848400BDBDBD00BDBDBD00BDBDBD008484
      840000000000000000000000000000000000BDBDBD0000000000000000008080
      80000000000000000000000000000000000000000000BDBDBD00BD000000FFFF
      FF00FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF00C6F7FF0084E7FF0084E7FF0021CE
      FF0021CEFF0021CEFF0084E7FF00000000000000000000000000000000000000
      0000000000000000000000000000808080000000000000000000000000000000
      00000000000000000000BDBDBD00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000000000000000BD000000BD006363FF006363FF000000
      BD00000000008080800080808000808080000000000000000000000000008484
      8400848484000000000000000000FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD008484840084848400BDBDBD00BDBDBD000000000084848400000000008080
      80000000000000000000000000000000000000000000BDBDBD00FFFFFF00BD00
      0000FF6B6300FF6B630000000000FFFFFF00FFFFFF0000000000000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF00FFFFFF00C6F7FF00C6F7FF0021CE
      FF0021CEFF0021CEFF00C6F7FF00C6F7FF000000000000000000000000000000
      000000ADDE0000ADDE0000000000808080000000000000000000000000000000
      00000000000000000000BDBDBD00FFFFFF000000000000000000000000000000
      000000000000000000000000BD000000BD006363FF006363FF006363FF006363
      FF000000BD00000000000000000080808000808080000000000000000000FFFF
      FF00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00BDBDBD00000000008484840000000000808080008080
      80000000000000000000000000000000000000000000BDBDBD00BD000000FFFF
      FF00FFFFFF00FFFFFF0000000000FFFFFF000000000000000000000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000007BA500007BA500007BA500007BA50000A5
      D60000A5D60000A5D600007BA500007BA500007BA500007BA500007BA50000AD
      DE0000ADDE0000ADDE0000000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000BD000000BD006363FF006363FF006363FF00000000006363
      FF006363FF000000BD000000BD0000000000808080008080800000000000FFFF
      FF00BDBDBD00BDBDBD0084848400FFFFFF00BDBDBD00BDBDBD00BDBDBD00BDBD
      BD00BDBDBD00BDBDBD0084848400848484000000000080808000808080000000
      00000000000000000000000000000000000000000000BDBDBD00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000ADDE0021CEFF0021CEFF0021CE
      FF0000ADDE00007BA50000ADDE0021CEFF0021CEFF0021CEFF0000ADDE00007B
      A50000ADDE0000ADDE0000000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000BD000000BD006363FF006363FF006363FF000000BD00000000000000
      00006363FF006363FF006363FF000000BD00000000000000000000000000FFFF
      FF00BDBDBD00BDBDBD008484840084848400FFFFFF00FFFFFF00BDBDBD00BDBD
      BD00848484008484840000000000000000008080800080808000000000000000
      00000000000000000000000000000000000000000000BDBDBD00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000ADDE0021CEFF0021CE
      FF0021CEFF0000ADDE00007BA50000ADDE0021CEFF0021CEFF0021CEFF0000AD
      DE00007BA50000ADDE0000000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00009C9CFF006363FF006363FF006363FF000000BD0000000000000000000000
      0000000000009C9CFF000000BD0000000000000000000000000000000000FFFF
      FF00BDBDBD008484840000000000000000008484840084848400848484008484
      8400000000000000000000000000808080008080800000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000ADDE0000AD
      DE0000ADDE0000ADDE0000ADDE00007BA50000ADDE0000ADDE0000ADDE0000AD
      DE0000ADDE00007BA50000000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009C9CFF009C9CFF000000BD000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF000000000080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000008080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000058000000420000000100010000000000180300000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000FFF83FFFF81FFE0F
      C0000000FF001FFF000FC007C0000000E0001FE0000E0007C0000000C0001F00
      000C0007C000000080001E00000C0007C000000080001E00000C0007C0000000
      80001E00000C0007C000000080001E00000C0001C000000080001E00000C0000
      C000000080001E00000C00004000000080001E00000C00004000000080000200
      000C00004000000080000200000C00004000000080000200000C000040000000
      80000200000C00004000000080000200000C0000C000000080000200000C001F
      C000000080000200001C003FC000000080000200003C007FC000000080000600
      03FE0FFFC0000000C3004E007FFFFFFFC0000000FFC1FE07FFFFFFFFC0000000
      FC001FFFF81FFFFFFFFF8100F8000FFE400FF03FFF880000F80007FC000F001F
      FF000000E00003E0000C001FFC000000C00003C00008001FF800000080000380
      0008001FF8000000000003000008001FF8000000000002000008001FF8000000
      0000000000080019F80000000000000000080010F80000000000000000080000
      780000000000000000080000780000000000000000080000F800000000000000
      00180001F00001000000040000380003E0000F000007FC0000F80000C0000F00
      0007FC0000F8000040000F000007FC0000F8000000001F00000FFE0000FC6000
      40003F00001FFF0000FFE030C0007F0000FFFF8000FFF079C103FF0087FFFFC0
      01FFF8FFE3FFFF0000000000000000000000000000000000000000000000}
  end
  object SaveDialog: TSaveDialog
    Filter = 
      'All Resources|VIEW.*;PIC.*;SCRIPT.*;TEXT.*;SOUND.*;MEMORY.*;VOCA' +
      'B.*;FONT.*;CURSOR.*;PATCH.*|View Resource (view.*)|VIEW.*|Pic Re' +
      'source (pic.*)|PIC.*|Script Resource (script.*)|SCRIPT.*|Text Re' +
      'source (text.*)|TEXT.*|Sound Resource (sound.*)|SOUND.*|Vocab R'
    Title = 'Save Resource'
    Left = 547
    Top = 2
  end
  object OpenDialog: TOpenDialog
    Options = [ofHideReadOnly, ofAllowMultiSelect, ofFileMustExist, ofEnableSizing]
    Title = 'Add Resource'
    Left = 519
    Top = 2
  end
  object tmrView: TTimer
    Enabled = False
    Interval = 200
    OnTimer = tmrViewTimer
    Left = 616
    Top = 8
  end
  object tmrPic: TTimer
    Enabled = False
    Interval = 500
    OnTimer = tmrPicTimer
    Left = 648
    Top = 8
  end
  object OpenPictureDialog: TOpenPictureDialog
    Left = 520
    Top = 32
  end
  object ImageList1: TImageList
    Height = 22
    Width = 22
    Left = 583
    Top = 36
    Bitmap = {
      494C010107000900040016001600FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      000000000000360000002800000058000000420000000100200000000000C05A
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000008080800080808000808080008080800080808000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000008080800080808000808080008080800080808000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000808080008080800080808000808080008080
      8000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008080800080808000808080008080
      8000808080008080800000000000000000000000000080808000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008080800080808000808080008080
      8000808080000000000000000000000000000000000000000000808080008080
      8000000000000000000000000000000000000000000000000000808080008080
      8000808080008080800080808000808080000000000000000000000000008080
      8000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008080
      8000808080008080800080808000808080008080800000000000000000000000
      00000000000000000000EDEDED00EDEDED000000000000000000808080000000
      0000000000000000000000000000000000000000000000000000000000008080
      8000808080008080800080808000808080000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000008080
      8000000000000000000000000000808080008080800080808000808080000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000808080008080
      80000000000000000000000000000000000000000000F3F3F300F3F3F300F3F3
      F300F3F3F300F3F3F300F3F3F300F3F3F3000000000000000000808080000000
      0000000000000000000000000000000000008080800080808000808080000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00F8F8F800F8F8F800F8F8F800F8F8F80000000000000000008080
      800000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FDFDFD00FDFDFD00FDFDFD00FDFDFD00FDFDFD00FFC8C800FFC8C800FFC8
      C800FFC8C800FFC8C800FFFFFF00FFFFFF000000000000000000808080000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FF898900FF898900FF89
      8900FFFFFF00000000000000000000000000FFFFFF0000000000000000008080
      8000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFC8C800FFC8C800FFFFFF00FFC8C800FFC8C800FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000808080000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FF898900FFFFFF00FF89
      8900FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000008080
      8000000000000000000000000000FFFFFF00FFFFFF0000000000FFFFFF00FFFF
      FF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFC8C800FFC8C800FFC8
      C800FFC8C800FFC8C800FFFFFF00FFFFFF000000000000000000808080000000
      000000000000000000000000000000000000FFFFFF00FF898900FF898900FF89
      8900FFFFFF00000000000000000000000000FFFFFF00FF898900FF898900FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000008080
      8000000000000000000000000000FFFFFF00FFFFFF0000000000FFFFFF00FFFF
      FF000000000000000000FFFFFF00FFFFFF000000000000000000000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFC8C800FFC8C800FFFFFF00FFC8C800FFC8C800FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000808080000000
      000000000000000000000000000000000000FFFFFF00FF898900FFFFFF00FF89
      8900FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000008080
      8000000000000000000000000000FFFFFF00FFFFFF0000000000000000000000
      00000000000089FFFF00000000000000000089FFFF0089FFFF00000000000000
      0000808080008080800080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFC8C800FFC8C800FFC8
      C800FFC8C800FFC8C800FFFFFF00FFFFFF000000000000000000808080000000
      000000000000000000000000000000000000FFFFFF00FF898900FF898900FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FF898900FF898900FF89
      8900FFFFFF00000000000000000000000000FFFFFF0000000000000000008080
      8000000000000000000000000000FFFFFF00FFFFFF0000000000FFFFFF000000
      0000FFFFFF000000000089FFFF0089FFFF0089FFFF0089FFFF0089FFFF0089FF
      FF00000000000000000080808000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFC8C800FFC8C800FFFFFF00FFC8C800FFC8C800FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000808080000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FF898900FFFFFF00FF89
      8900FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000008080
      8000000000000000000000000000FFFFFF00FFFFFF000000000000000000FFFF
      FF00FFFFFF00FFFFFF000000000089FFFF0089FFFF0089FFFF0089FFFF000000
      000000000000FF8D8D0000000000808080008080800000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFC8C800FFC8C800FFC8
      C800FFC8C800FFC8C800FFFFFF00FFFFFF000000000000000000808080000000
      000000000000000000000000000000000000FFFFFF00FF898900FF898900FF89
      8900FFFFFF00000000000000000000000000FFFFFF00FF898900FF898900FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000008080
      8000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF000000000089FFFF0089FFFF00000000000000
      000000000000FF8D8D00FF898900000000008080800000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFC8C800FFC8C800FFFFFF00FFC8C800FFC8C800FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000808080008080
      800080808000808080000000000000000000FFFFFF00FF898900FFFFFF00FF89
      8900FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000008080
      8000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000089FFFF00000000000000
      0000FF929200FF8D8D00FF898900000000008080800000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      00000000000000000000FFFFFF00FFFFFF000000000000000000000000000000
      000000000000808080000000000000000000FFFFFF00FF898900FF898900FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FF898900FF898900FF89
      8900FFFFFF00000000000000000000000000FFFFFF0000000000000000008080
      8000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFED
      ED00FFEDED00FF8D8D00FF898900000000008080800000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000009DFF
      FF0089D7F3009DFFFF0000000000000000000000000000000000FF898900FF89
      890000000000808080000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FF898900FFFFFF00FF89
      8900FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000008080
      8000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000000000000000FF89
      8900FFEDED00FFEDED00FF898900000000008080800000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF000000000000000000FFFFFF00FFFFFF00000000009DFFFF0089D7
      F300DEFFFF00DEFFFF00DEFFFF00DEFFFF000000000000000000FFCEC800FFCE
      C80000000000808080000000000000000000FFFFFF00FF898900FF898900FF89
      8900FFFFFF00000000000000000000000000FFFFFF00FF898900FF898900FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000008080
      8000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00000000000000
      0000FF898900FFEDED00FFEDED00000000008080800000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF0000000000DEFFFF009DFFFF000000000000000000FFFFFF0089D7F300DEFF
      FF00DEFFFF00DEFFFF00DEFFFF00DEFFFF00DEFFFF0000000000FFEDED00FFED
      ED0000000000808080000000000000000000FFFFFF00FF898900FFFFFF00FF89
      8900FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      000000000000FFCEC800FFCEC800FFCEC800FFCEC80000000000000000008080
      8000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF0000000000FFFFFF00DEFFFF009DFFFF000000000000000000FFFFFF00DEFF
      FF00DEFFFF00DEFFFF00DEFFFF00DEFFFF00DEFFFF0000000000FFEDED00FFED
      ED0000000000808080000000000000000000FFFFFF00FF898900FF8989000000
      000000000000000000000000000000000000FFCEC800FFCEC800FFCEC800FFCE
      C800FFCEC800FFCEC800FFCEC800FFCEC800FFCEC80000000000000000008080
      8000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF0000000000FFFFFF00DEFFFF009DFFFF009DFFFF0000000000DEFF
      FF00DEFFFF00DEFFFF00DEFFFF00FFFFFF00FFFFFF0000000000FFCEC800FFCE
      C80000000000808080000000000000000000000000000000000000000000FFCE
      C800FFCEC800FFCEC800FFCEC800FFCEC800FFCEC800FFCEC800FFCEC800FFCE
      C800FFCEC8000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000FFFFFF00DEFFFF00DEFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFEDED00FFED
      ED0000000000808080000000000000000000FF898900FFCEC800FFCEC800FFCE
      C800FFCEC800FFCEC800FFCEC800FFCEC800FFCEC80000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000DEFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFCEC800FFCE
      C80000000000000000000000000000000000FF898900FFCEC800FFCEC800FFCE
      C800000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000080808000808080008080800080808000808080008080
      8000808080008080800080808000808080008080800080808000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000008080800080808000808080008080800080808000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000808080008080
      8000808080008080800080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000808080008080
      8000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000808080008080800000000000808080008080
      8000808080000000000000000000000000000000000000000000808080008080
      8000000000000000000000000000000000000000000000000000000000000000
      0000808080008080800080808000808080008080800080808000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000808080008080
      8000000000008080800080808000808080008080800000000000000000000000
      0000000000000000000080808000808080000000000000000000000000000000
      0000000000000000000000000000000000009DFFFF009DFFFF009DFFFF009DFF
      FF009DFFFF009DFFFF009DFFFF009DFFFF0089D7F30089F8FF00000000008080
      8000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008080800080808000000000000000
      000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000008080
      8000000000000000000000000000000000008080800080808000808080008080
      8000000000000000000000000000000000000000000080808000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008080
      80008080800000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000808080000000000000000000000000008080
      800080808000000000000000000089F3890000000000DEFFFF00DEFFFF00DEFF
      FF00DEFFFF00DEFFFF00DEFFFF00DEFFFF0089D7F30089F8FF0089F8FF000000
      0000808080008080800000000000000000000000000000000000000000008080
      800080808000808080000000000089F389000000000000000000FFFFFF00FFFF
      FF00FFFFFF00E7E7E700E7E7E700E7E7E700EDEDED0000000000000000008080
      8000000000000000000080808000808080000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000080808000808080000000000089FFFF0089FFFF000000
      000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000F3F3
      F300F3F3F3000000000000000000808080000000000000000000808080000000
      000000000000000000000000000089FF890089F3890000000000DEFFFF00DEFF
      FF00DEFFFF00DEFFFF00DEFFFF00DEFFFF0089D7F3009DFFFF0089F8FF0089F8
      FF00000000008080800000000000000000000000000000000000000000000000
      000000000000000000000000000089FF890089F3890000000000F3F3F300F3F3
      F300F3F3F300FFCEC800FFCEC800FFCEC800F3F3F30000000000000000008080
      800000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FDFDFD00FDFDFD00FDFDFD00FDFDFD000000000000000000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000089FFFF0089FFFF000000
      0000FFFFFF00F8F8F8008989FF008989FF00FDFDFD000000000000000000FDFD
      FD00FDFDFD0000000000000000008080800000000000808080000000000089F3
      890089F3890089F3890089F3890089FF890089FF890089F3890000000000DEFF
      FF00DEFFFF00DEFFFF00DEFFFF00DEFFFF0089D7F3009DFFFF0089F8FF0089F8
      FF0000000000808080000000000000000000000000000000000089F3890089F3
      890089F3890089F3890089F3890089FF890089FF890089F3890000000000FFCE
      C800FFCEC800FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000008080
      80000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF000000000089FFFF0089FFFF000000
      0000FFFFFF00FFFFFF008989FF008989FF00FFFFFF000000000000000000FFFF
      FF00FFFFFF00000000000000000080808000808080000000000089F3890089FF
      890089FF890089FF890089FF890089FF890089FF890089FF890089F389000000
      0000DEFFFF00DEFFFF00DEFFFF00DEFFFF0089D7F3009DFFFF009DFFFF0089F8
      FF00000000008080800000000000000000000000000089F3890089FF890089FF
      890089FF890089FF890089FF890089FF890089FF890089FF890089F389000000
      0000FFFFFF00FFCEC800FFCEC800FFCEC800FFFFFF0000000000000000008080
      80000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFCEC800FFCEC800FFCEC800FFFFFF000000000000000000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF000000000089FFFF0089FFFF000000
      0000FFFFFF00FFFFFF008989FF008989FF00FFFFFF000000000000000000FFFF
      FF00FFFFFF00000000000000000080808000000000000000000089F3890089FF
      8900FFFFFF00FFFFFF00FFFFFF0089FF890089FF8900FFFFFF0000000000DEFF
      FF00DEFFFF00DEFFFF00DEFFFF00DEFFFF0089D7F3009DFFFF009DFFFF0089F8
      FF000000000080808000000000000000000089F3890089FF890089FF8900FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0089FF890089FF8900FFFFFF0000000000FFCE
      C800FFCEC800FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000008080
      80000000000000000000FFFFFF00FFFFFF00FFCEC800FFCEC800FFCEC800FFCE
      C800FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF000000000089FFFF0089FFFF000000
      0000FFFFFF00FFFFFF008989FF008989FF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00000000000000000080808000000000000000000089F3890089FF
      8900000000000000000000000000FFFFFF00FFFFFF00000000009DFFFF009DFF
      FF00DEFFFF00DEFFFF00DEFFFF00DEFFFF0089D7F3009DFFFF009DFFFF0089F8
      FF000000000080808000000000000000000089F3890089FF890089F389000000
      0000000000000000000000000000FFFFFF00FFFFFF0000000000FFFFFF00FFFF
      FF00FFFFFF00FFCEC800FFCEC800FFCEC800FFFFFF0000000000000000008080
      80000000000000000000FFFFFF00FFCEC800FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFCEC800FFCEC800FFCEC800FFFFFF000000000000000000808080000000
      0000000000008080800080808000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF000000000089FFFF0089FFFF000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
      000000000000000000000000000080808000000000000000000089F3890089F3
      8900000000000000000000000000FFFFFF00000000009DFFFF009DFFFF009DFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0089D7F3009DFFFF0089F8FF0089F8
      FF000000000080808000000000000000000089F3890089F38900000000009DFF
      FF00DEFFFF00DEFFFF0000000000FFFFFF0000000000FFFFFF00FFCEC800FFCE
      C800FFCEC800FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000008080
      80000000000000000000FFFFFF00FFFFFF00FFCEC800FFCEC800FFCEC800FFCE
      C800FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000808080000000
      0000000000000000000080808000808080000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF000000000089FFFF0089FFFF000000
      0000FFFFFF00FFFFFF00000000000000000000000000FF9D9D00FFA2A200FFA8
      A800FFADAD00000000000000000080808000000000000000000089F389000000
      0000FFCEC80000000000000000000000000089D7F30089F3FF0089F3FF0089F3
      FF0089D7F30089D7F30089D7F30089D7F30089D7F30089F8FF0089F8FF0089F8
      FF000000000080808000000000000000000089F3890089F38900000000009DFF
      FF00DEFFFF00DEFFFF000000000000000000FFFFFF00FFCEC800FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000008080
      80000000000000000000FFFFFF00FFCEC800FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000FFFFFF000000000000000000808080000000
      00008989FF008989FF0000000000808080008080800000000000000000000000
      00000000000000000000FFFFFF00FFFFFF000000000089FFFF0089FFFF000000
      00000000000000000000FF898900FF929200FF9D9D00FF9D9D00FFA2A200FFA8
      A800FFADAD00000000000000000080808000000000000000000089F389000000
      0000FFFFFF000000000089F8FF009DFFFF009DFFFF009DFFFF0089F8FF0089D7
      F30089F8FF009DFFFF009DFFFF009DFFFF0089F8FF0089D7F30089F8FF0089F8
      FF000000000080808000000000000000000089F38900000000009DFFFF00DEFF
      FF00DEFFFF00DEFFFF00DEFFFF0000000000FFFFFF00FFFFFF00FFCEC800FFCE
      C800FFCEC80000000000FFFFFF00FFFFFF000000000000000000000000008080
      80000000000000000000FFFFFF00FFFFFF00FFCEC800FFCEC800FFCEC800FFCE
      C800000000008989FF008989FF00000000000000000000000000000000008989
      FF008989FF008989FF008989FF00000000008080800000000000000000000000
      0000000000000000000000000000000000000000000089FFFF0089FFFF000000
      0000FF898900FF898900FF898900FF929200FF9D9D0000000000000000000000
      000000000000000000000000000080808000000000000000000089F389000000
      0000FFCEC800FFCEC8000000000089F8FF009DFFFF009DFFFF009DFFFF0089F8
      FF0089D7F30089F8FF009DFFFF009DFFFF009DFFFF0089F8FF0089D7F30089F8
      FF000000000080808000000000000000000089F38900000000009DFFFF00DEFF
      FF00DEFFFF00DEFFFF00DEFFFF0000000000FFFFFF00FFCEC800FFFFFF00FFFF
      FF00FFFFFF0000000000FFFFFF00000000000000000000000000000000008080
      80000000000000000000FFFFFF00FFCEC800FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000008989FF00C8C8FF008989FF0000000000000000008989FF008989
      FF00C8C8FF00C8C8FF008989FF00000000000000000000000000000000000000
      00000000000000000000FF898900FF9D9D000000000000000000000000000000
      0000FF898900FF89890000000000000000000000000000000000000000000000
      00000000000000000000000000008080800000000000FFFFFF0000000000FFFF
      FF00FFFFFF00FFFFFF00FFCEC8000000000089F8FF0089F8FF0089F8FF0089F8
      FF0089F8FF0089D7F30089F8FF0089F8FF0089F8FF0089F8FF0089F8FF0089D7
      F30000000000808080000000000000000000000000009DFFFF00DEFFFF00DEFF
      FF00DEFFFF00DEFFFF00DEFFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFCEC800FFCEC800FFCEC800FFCE
      C80000000000EDEDFF00C8C8FF00C8C8FF008989FF008989FF00C8C8FF00C8C8
      FF00C8C8FF008989FF0000000000000000000000000000000000000000000000
      00000000000000000000FF8989000000000000000000FFFFFF00DEDEDE000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FF89
      8900FFCEC800FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF00DEFFFF00DEFFFF00DEFFFF00DEFF
      FF00DEFFFF00DEFFFF00DEFFFF0000000000FFFFFF00FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFCEC800FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000000000008989FF00C8C8FF00C8C8FF00C8C8FF00C8C8FF00C8C8
      FF008989FF000000000000000000000000000000000000000000000000000000
      000000000000DEDEDE0000000000DEDEDE00FFFFFF00FFFFFF00FFFFFF00DEDE
      DE0000000000000000000000000000000000FFFFFF0000000000000000008080
      80000000000000000000000000000000000000000000FFFFFF00FF898900FFFF
      FF00FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF00FFFFFF00DEFFFF00DEFFFF009DFF
      FF009DFFFF009DFFFF00DEFFFF00000000000000000000000000000000000000
      0000000000000000000000000000808080000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000000000008989FF008989FF00C8C8FF00C8C8FF008989
      FF0000000000808080008080800080808000000000000000000000000000DEDE
      DE00DEDEDE000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00DEDEDE00DEDEDE00FFFFFF00FFFFFF0000000000DEDEDE00000000008080
      80000000000000000000000000000000000000000000FFFFFF00FFFFFF00FF89
      8900FFCEC800FFCEC80000000000FFFFFF00FFFFFF0000000000000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF009DFF
      FF009DFFFF009DFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      000089F8FF0089F8FF0000000000808080000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF000000000000000000000000000000
      000000000000000000008989FF008989FF00C8C8FF00C8C8FF00C8C8FF00C8C8
      FF008989FF00000000000000000080808000808080000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0000000000DEDEDE0000000000808080008080
      80000000000000000000000000000000000000000000FFFFFF00FF898900FFFF
      FF00FFFFFF00FFFFFF0000000000FFFFFF000000000000000000000000000000
      0000808080000000000000000000000000000000000000000000000000000000
      000000000000000000000000000089D7F30089D7F30089D7F30089D7F30089F3
      FF0089F3FF0089F3FF0089D7F30089D7F30089D7F30089D7F30089D7F30089F8
      FF0089F8FF0089F8FF0000000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000008989FF008989FF00C8C8FF00C8C8FF00C8C8FF0000000000C8C8
      FF00C8C8FF008989FF008989FF0000000000808080008080800000000000FFFF
      FF00FFFFFF00FFFFFF00DEDEDE00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00DEDEDE00DEDEDE000000000080808000808080000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000089F8FF009DFFFF009DFFFF009DFF
      FF0089F8FF0089D7F30089F8FF009DFFFF009DFFFF009DFFFF0089F8FF0089D7
      F30089F8FF0089F8FF0000000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00008989FF008989FF00C8C8FF00C8C8FF00C8C8FF008989FF00000000000000
      0000C8C8FF00C8C8FF00C8C8FF008989FF00000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00DEDEDE00DEDEDE00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00DEDEDE00DEDEDE0000000000000000008080800080808000000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000089F8FF009DFFFF009DFF
      FF009DFFFF0089F8FF0089D7F30089F8FF009DFFFF009DFFFF009DFFFF0089F8
      FF0089D7F30089F8FF0000000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000EDEDFF00C8C8FF00C8C8FF00C8C8FF008989FF0000000000000000000000
      000000000000EDEDFF008989FF0000000000000000000000000000000000FFFF
      FF00FFFFFF00DEDEDE000000000000000000DEDEDE00DEDEDE00DEDEDE00DEDE
      DE00000000000000000000000000808080008080800000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000089F8FF0089F8
      FF0089F8FF0089F8FF0089F8FF0089D7F30089F8FF0089F8FF0089F8FF0089F8
      FF0089F8FF0089D7F30000000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000EDEDFF00EDEDFF008989FF000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF000000000080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000008080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000058000000420000000100010000000000180300000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000FFF83FFFF81FFE0F
      C0000000FF001FFF000FC007C0000000E0001FE0000E0007C0000000C0001F00
      000C0007C000000080001E00000C0007C000000080001E00000C0007C0000000
      80001E00000C0007C000000080001E00000C0001C000000080001E00000C0000
      C000000080001E00000C00004000000080001E00000C00004000000080000200
      000C00004000000080000200000C00004000000080000200000C000040000000
      80000200000C00004000000080000200000C0000C000000080000200000C001F
      C000000080000200001C003FC000000080000200003C007FC000000080000600
      03FE0FFFC0000000C3004E007FFFFFFFC0000000FFC1FE07FFFFFFFFC0000000
      FC001FFFF81FFFFFFFFF8100F8000FFE400FF03FFF880000F80007FC000F001F
      FF000000E00003E0000C001FFC006000C00003C00008001FF800600080000380
      0008001FF8006000000003000008001FF8006000000002000008001FF8000000
      0000000000080019F80000000000000000080010F80000000000000000080000
      780000000000000000080000780000000000000000080000F800000000000000
      00180001F00001000000040000380003E0000F000007FC0000F80000C0000F00
      0007FC0000F8000040000F000007FC0000F8000000001F00000FFE0000FC6000
      40003F00001FFF0000FFE030C0007F0000FFFF8000FFF079C103FF0087FFFFC0
      01FFF8FFE3FFFF0000000000000000000000000000000000000000000000}
  end
end
