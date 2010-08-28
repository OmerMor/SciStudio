object WndTextEdit: TWndTextEdit
  Left = 196
  Top = 173
  Width = 432
  Height = 279
  Caption = 'Text Editor'
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
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 0
    Top = 149
    Width = 424
    Height = 3
    Cursor = crVSplit
    Align = alBottom
  end
  object CoolBar1: TCoolBar
    Left = 0
    Top = 0
    Width = 424
    Height = 49
    AutoSize = True
    Bands = <
      item
        Control = MenuBar1
        ImageIndex = -1
        MinHeight = 21
        Width = 420
      end
      item
        Control = ToolBar1
        ImageIndex = -1
        MinHeight = 22
        Width = 420
      end>
    object MenuBar1: TMenuBar
      Left = 9
      Top = 0
      Width = 133
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
      Width = 236
      Height = 22
      Align = alNone
      AutoSize = True
      EdgeBorders = []
      Flat = True
      HotImages = WndMain.ilEditBarsH
      Images = WndMain.ilEditBars
      TabOrder = 1
      Transparent = True
      object tbNew: TToolButton
        Left = 0
        Top = 0
        Hint = 'New'
        ImageIndex = 0
        ParentShowHint = False
        ShowHint = True
        OnClick = tbNewClick
      end
      object tbOpen: TToolButton
        Left = 23
        Top = 0
        Hint = 'Open'
        ImageIndex = 1
        ParentShowHint = False
        ShowHint = True
        OnClick = tbOpenClick
      end
      object tbSave: TToolButton
        Left = 46
        Top = 0
        Hint = 'Save'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = Save1Click
      end
      object tbWriteScriptHeader: TToolButton
        Left = 69
        Top = 0
        Hint = 'Write script header'
        ImageIndex = 38
        ParentShowHint = False
        ShowHint = True
        OnClick = tbWriteScriptHeaderClick
      end
      object ToolButton6: TToolButton
        Left = 92
        Top = 0
        Width = 2
        ImageIndex = 8
        Style = tbsSeparator
      end
      object tbViewAsMessageBox: TToolButton
        Left = 94
        Top = 0
        Hint = 'View as Message Box'
        ImageIndex = 37
        ParentShowHint = False
        ShowHint = True
        OnClick = tbViewAsMessageBoxClick
      end
      object ToolButton3: TToolButton
        Left = 117
        Top = 0
        Width = 2
        ImageIndex = 2
        Style = tbsSeparator
      end
      object tbCopy: TToolButton
        Left = 119
        Top = 0
        Hint = 'Cope selected text'
        ImageIndex = 6
        ParentShowHint = False
        ShowHint = True
        OnClick = tbCopyClick
      end
      object ToolButton2: TToolButton
        Left = 142
        Top = 0
        Width = 2
        ImageIndex = 8
        Style = tbsSeparator
      end
      object tbAdd: TToolButton
        Left = 144
        Top = 0
        Hint = 'Add Entry'
        ImageIndex = 39
        ParentShowHint = False
        ShowHint = True
        OnClick = tbAddClick
      end
      object tbDelete: TToolButton
        Left = 167
        Top = 0
        Hint = 'Delete Entry'
        ImageIndex = 40
        ParentShowHint = False
        ShowHint = True
        OnClick = tbDeleteClick
      end
      object tbMoveUp: TToolButton
        Left = 190
        Top = 0
        Hint = 'Move Entry Up'
        ImageIndex = 19
        ParentShowHint = False
        ShowHint = True
        OnClick = tbMoveUpClick
      end
      object tbMoveDown: TToolButton
        Left = 213
        Top = 0
        Hint = 'Move Entry Down'
        ImageIndex = 18
        ParentShowHint = False
        ShowHint = True
        OnClick = tbMoveDownClick
      end
    end
  end
  object EditPanel: TPanel
    Left = 0
    Top = 152
    Width = 424
    Height = 100
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object NamePanel: TPanel
      Left = 0
      Top = 0
      Width = 424
      Height = 23
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 0
      object NameLabel: TLabel
        Left = 0
        Top = 0
        Width = 45
        Height = 23
        Align = alLeft
        Alignment = taCenter
        AutoSize = False
        Caption = 'Name:'
        Layout = tlCenter
      end
      object NameEdit: TEdit
        Left = 45
        Top = 0
        Width = 379
        Height = 21
        MaxLength = 64
        TabOrder = 0
        OnChange = NameEditChange
      end
    end
    object Panel2: TPanel
      Left = 0
      Top = 23
      Width = 424
      Height = 77
      Align = alClient
      BevelOuter = bvLowered
      TabOrder = 1
      object EditBox: TMemo
        Left = 1
        Top = 1
        Width = 422
        Height = 75
        TabStop = False
        Align = alClient
        BorderStyle = bsNone
        ScrollBars = ssBoth
        TabOrder = 0
        OnChange = EditBoxChange
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 49
    Width = 424
    Height = 100
    Align = alClient
    BevelOuter = bvLowered
    TabOrder = 2
    object ListView: TListView
      Left = 1
      Top = 1
      Width = 422
      Height = 98
      Align = alClient
      BorderStyle = bsNone
      Columns = <
        item
          Caption = 'Index'
          Width = 40
        end
        item
          Caption = 'Name'
          Width = 80
        end
        item
          AutoSize = True
          Caption = 'String'
        end>
      GridLines = True
      HotTrackStyles = [htHandPoint, htUnderlineHot]
      ReadOnly = True
      RowSelect = True
      TabOrder = 0
      ViewStyle = vsReport
      OnChange = ListViewChange
      OnDblClick = ListViewDblClick
    end
  end
  object MainMenu1: TMainMenu
    Images = WndMain.ilEditBars
    Left = 288
    Top = 8
    object File1: TMenuItem
      Caption = '&File'
      object New1: TMenuItem
        Caption = '&New'
        ImageIndex = 0
        ShortCut = 16462
        OnClick = tbNewClick
      end
      object Open1: TMenuItem
        Caption = '&Open'
        ImageIndex = 1
        ShortCut = 16463
        OnClick = tbOpenClick
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
      object N3: TMenuItem
        Caption = '-'
      end
      object WriteScriptHeader1: TMenuItem
        Caption = 'Write Script &Header'
        ImageIndex = 38
        OnClick = tbWriteScriptHeaderClick
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
    object Entries1: TMenuItem
      Caption = 'E&ntries'
      object Add1: TMenuItem
        Caption = '&Add'
        ImageIndex = 39
        ShortCut = 16449
        OnClick = tbAddClick
      end
      object Delete1: TMenuItem
        Caption = '&Delete'
        ImageIndex = 40
        ShortCut = 16452
        OnClick = tbDeleteClick
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object MoveUp1: TMenuItem
        Caption = 'Move &Up'
        ImageIndex = 19
        OnClick = tbMoveUpClick
      end
      object MoveDown1: TMenuItem
        Caption = 'Move &Down'
        ImageIndex = 18
        OnClick = tbMoveDownClick
      end
    end
    object View1: TMenuItem
      Caption = '&View'
      object AsMessageBox1: TMenuItem
        Caption = 'As &Message Box'
        ImageIndex = 37
        OnClick = tbViewAsMessageBoxClick
      end
    end
    object Edit1: TMenuItem
      Caption = '&Edit'
      object Copy1: TMenuItem
        Caption = '&Copy'
        ImageIndex = 6
        ShortCut = 16451
        OnClick = tbCopyClick
      end
    end
  end
  object OpenDialog: TOpenDialog
    Filter = 'SCI Text Resource (text.*)|text.*|All Files (*.*)|*.*'
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Left = 314
    Top = 10
  end
  object SaveDialog: TSaveDialog
    Options = [ofHideReadOnly, ofPathMustExist, ofEnableSizing]
    Left = 338
    Top = 10
  end
end
