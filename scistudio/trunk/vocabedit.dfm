object WndVocabEdit: TWndVocabEdit
  Left = 205
  Top = 108
  Width = 473
  Height = 398
  Caption = 'Vocabulary Editor'
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
  object Shape4: TShape
    Left = 120
    Top = 1
    Width = 31
    Height = 21
    Brush.Color = clBtnFace
    Pen.Color = clBtnText
  end
  object SpeedButton3: TSpeedButton
    Left = 121
    Top = 2
    Width = 29
    Height = 19
    Caption = 'Add'
    Flat = True
  end
  object CoolBar1: TCoolBar
    Left = 0
    Top = 0
    Width = 465
    Height = 49
    AutoSize = True
    Bands = <
      item
        Control = MenuBar1
        HorizontalOnly = True
        ImageIndex = -1
        MinHeight = 21
        Width = 461
      end
      item
        Control = ToolBar1
        ImageIndex = -1
        MinHeight = 22
        Width = 461
      end>
    object MenuBar1: TMenuBar
      Left = 9
      Top = 0
      Width = 100
      Height = 21
      Align = alNone
      AutoSize = True
      ButtonHeight = 21
      ButtonWidth = 47
      Flat = True
      ShowCaptions = True
      TabOrder = 0
      Menu = MainMenu1
    end
    object ToolBar1: TToolBar
      Left = 9
      Top = 23
      Width = 448
      Height = 22
      Align = alLeft
      ButtonWidth = 25
      EdgeBorders = []
      Flat = True
      HotImages = WndMain.ilEditBarsH
      Images = WndMain.ilEditBars
      TabOrder = 1
      Transparent = True
      Wrapable = False
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        ImageIndex = 0
        OnClick = New1Click
      end
      object ToolButton2: TToolButton
        Left = 25
        Top = 0
        ImageIndex = 1
        OnClick = Open1Click
      end
      object ToolButton3: TToolButton
        Left = 50
        Top = 0
        ImageIndex = 2
        OnClick = Save1Click
      end
      object ToolButton4: TToolButton
        Left = 75
        Top = 0
        Width = 2
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButton5: TToolButton
        Left = 77
        Top = 0
        ImageIndex = 6
        OnClick = Copy2Click
      end
      object ToolButton6: TToolButton
        Left = 102
        Top = 0
        Width = 2
        ImageIndex = 4
        Style = tbsSeparator
      end
      object ToolButton7: TToolButton
        Left = 104
        Top = 0
        ImageIndex = 34
        OnClick = FindWord1Click
      end
    end
  end
  object Panel6: TPanel
    Left = 0
    Top = 49
    Width = 343
    Height = 322
    Align = alClient
    BevelOuter = bvLowered
    TabOrder = 1
    object ListView: TListView
      Left = 1
      Top = 47
      Width = 341
      Height = 274
      Align = alClient
      BorderStyle = bsNone
      Columns = <
        item
          Caption = 'Group'
          Width = 45
        end
        item
          Caption = 'Type'
          Width = 110
        end
        item
          AutoSize = True
          Caption = 'Words'
        end>
      Enabled = False
      GridLines = True
      HideSelection = False
      HotTrackStyles = [htHandPoint, htUnderlineHot]
      Items.Data = {1D0000000100000000000000FFFFFFFFFFFFFFFF000000000000000000}
      ReadOnly = True
      RowSelect = True
      PopupMenu = PopupMenu1
      TabOrder = 0
      ViewStyle = vsReport
      OnChange = ListViewChange
      OnColumnClick = ListViewColumnClick
    end
    object ToolBar3: TToolBar
      Left = 1
      Top = 23
      Width = 341
      Height = 24
      AutoSize = True
      ButtonWidth = 90
      Caption = 'ToolBar3'
      EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
      EdgeOuter = esNone
      Flat = True
      HotImages = WndMain.ilEditBarsH
      Images = WndMain.ilEditBars
      List = True
      ShowCaptions = True
      TabOrder = 1
      Wrapable = False
      object tbAddWord: TToolButton
        Left = 0
        Top = 0
        Caption = 'Add Group'
        ImageIndex = 39
        OnClick = tbAddWordClick
      end
      object tbDeleteGroup: TToolButton
        Left = 90
        Top = 0
        Caption = 'Delete Group'
        ImageIndex = 40
        OnClick = DeleteGroup1Click
      end
    end
    object Panel9: TPanel
      Left = 1
      Top = 1
      Width = 341
      Height = 22
      Align = alTop
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      object Label3: TLabel
        Left = 4
        Top = 4
        Width = 80
        Height = 14
        Caption = 'Word Groups'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBtnText
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        Layout = tlCenter
      end
    end
  end
  object Panel1: TPanel
    Left = 343
    Top = 49
    Width = 122
    Height = 322
    Align = alRight
    BevelOuter = bvLowered
    Color = clWindow
    Enabled = False
    TabOrder = 2
    object Splitter1: TSplitter
      Left = 1
      Top = 199
      Width = 120
      Height = 3
      Cursor = crVSplit
      Align = alTop
    end
    object Panel8: TPanel
      Left = 1
      Top = 202
      Width = 120
      Height = 119
      Align = alClient
      BevelOuter = bvLowered
      TabOrder = 0
      object ListBox: TListBox
        Left = 1
        Top = 43
        Width = 118
        Height = 75
        Align = alClient
        BorderStyle = bsNone
        ItemHeight = 13
        PopupMenu = PopupMenu2
        TabOrder = 0
      end
      object Panel3: TPanel
        Left = 1
        Top = 1
        Width = 118
        Height = 18
        Align = alTop
        TabOrder = 1
        object Label2: TLabel
          Left = 4
          Top = 2
          Width = 36
          Height = 13
          Caption = 'Words'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          Layout = tlCenter
        end
      end
      object ToolBar2: TToolBar
        Left = 1
        Top = 19
        Width = 118
        Height = 24
        ButtonWidth = 58
        Caption = 'ToolBar2'
        EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
        EdgeOuter = esNone
        Flat = True
        HotImages = WndMain.ilEditBarsH
        Images = WndMain.ilEditBars
        List = True
        ShowCaptions = True
        TabOrder = 2
        Wrapable = False
        object ToolButton8: TToolButton
          Left = 0
          Top = 0
          Caption = 'Add'
          ImageIndex = 103
          OnClick = ToolButton8Click
        end
        object ToolButton9: TToolButton
          Left = 58
          Top = 0
          Caption = 'Delete'
          ImageIndex = 104
          OnClick = DeleteWord1Click
        end
      end
    end
    object Panel7: TPanel
      Left = 1
      Top = 23
      Width = 120
      Height = 176
      Align = alTop
      BevelOuter = bvLowered
      TabOrder = 1
      object TypeListBox: TCheckListBox
        Left = 1
        Top = 19
        Width = 118
        Height = 156
        Align = alClient
        BorderStyle = bsNone
        ItemHeight = 13
        TabOrder = 0
        OnClick = TypeListBoxClick
      end
      object Panel10: TPanel
        Left = 1
        Top = 1
        Width = 118
        Height = 18
        Align = alTop
        TabOrder = 1
        object Label1: TLabel
          Left = 4
          Top = 2
          Width = 37
          Height = 13
          Caption = 'Types '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          Layout = tlCenter
        end
      end
    end
    object Panel4: TPanel
      Left = 1
      Top = 1
      Width = 120
      Height = 22
      Align = alTop
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
    end
  end
  object MainMenu1: TMainMenu
    Left = 240
    Top = 104
    object File1: TMenuItem
      Caption = '&File'
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
      object Exit1: TMenuItem
        Caption = 'E&xit'
        ImageIndex = 28
        OnClick = Exit1Click
      end
    end
    object Edit1: TMenuItem
      Caption = '&Edit'
      OnClick = Edit1Click
      object Copy2: TMenuItem
        Caption = '&Copy'
        ImageIndex = 6
        ShortCut = 16451
        OnClick = Copy2Click
      end
    end
    object Search1: TMenuItem
      Caption = '&Search'
      object FindWord1: TMenuItem
        Caption = '&Find Word'
        ImageIndex = 34
        ShortCut = 16454
        OnClick = FindWord1Click
      end
    end
  end
  object OpenDialog: TOpenDialog
    Filter = 
      'Vocabulary Resource (vocab.000,vocab.900)|vocab.000,vocab.900|Vo' +
      'cabulary Resource 0 (vocab.000)|vocab.000|Vocabulary Resource 1 ' +
      '(vocab.900)|vocab.900'
    Left = 194
    Top = 2
  end
  object SaveDialog: TSaveDialog
    Filter = 
      'Vocabulary Resource 0 (vocab.000)|vocab.000|Vocabulary Resource ' +
      '1 (vocab.900)|vocab.900'
    Left = 226
    Top = 2
  end
  object PopupMenu1: TPopupMenu
    Left = 272
    Top = 104
    object AddGroup1: TMenuItem
      Caption = '&Add Group'
      OnClick = tbAddWordClick
    end
    object DeleteGroup1: TMenuItem
      Caption = '&Delete Group'
      OnClick = DeleteGroup1Click
    end
    object Copy1: TMenuItem
      Caption = '&Copy'
      OnClick = Copy2Click
    end
  end
  object PopupMenu2: TPopupMenu
    Left = 304
    Top = 104
    object AddWord1: TMenuItem
      Caption = '&Add Word'
      OnClick = ToolButton8Click
    end
    object DeleteWord1: TMenuItem
      Caption = '&Delete Word'
      OnClick = DeleteWord1Click
    end
  end
end
