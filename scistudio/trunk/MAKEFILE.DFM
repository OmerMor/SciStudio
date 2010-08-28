object DlgMakeFile: TDlgMakeFile
  Left = 375
  Top = 173
  Width = 409
  Height = 300
  BorderStyle = bsSizeToolWin
  Caption = 'Make File Editor'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  Scaled = False
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 0
    Top = 126
    Width = 401
    Height = 2
    Align = alTop
    Shape = bsTopLine
  end
  object Panel1: TPanel
    Left = 0
    Top = 24
    Width = 401
    Height = 102
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label2: TLabel
      Left = 4
      Top = 57
      Width = 69
      Height = 13
      Caption = 'Include Paths:'
    end
    object Label3: TLabel
      Left = 4
      Top = 81
      Width = 47
      Height = 13
      Caption = 'Lib Paths:'
    end
    object Label4: TLabel
      Left = 4
      Top = 33
      Width = 56
      Height = 13
      Caption = 'Game Path:'
    end
    object Label1: TLabel
      Left = 4
      Top = 9
      Width = 62
      Height = 13
      Caption = 'Source Path:'
    end
    object Edit2: TEdit
      Left = 77
      Top = 53
      Width = 322
      Height = 21
      TabOrder = 0
    end
    object Edit3: TEdit
      Left = 77
      Top = 77
      Width = 322
      Height = 21
      TabOrder = 1
    end
    object Edit4: TEdit
      Left = 77
      Top = 29
      Width = 322
      Height = 21
      TabOrder = 2
    end
    object Edit1: TEdit
      Left = 77
      Top = 5
      Width = 322
      Height = 21
      TabOrder = 3
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 128
    Width = 401
    Height = 145
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object Panel4: TPanel
      Left = 0
      Top = 0
      Width = 401
      Height = 153
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 0
      object ListView: TListView
        Left = 0
        Top = 0
        Width = 338
        Height = 153
        Align = alClient
        Columns = <
          item
            AutoSize = True
            Caption = 'Source Files'
          end>
        GridLines = True
        HotTrackStyles = [htHandPoint, htUnderlineHot]
        RowSelect = True
        TabOrder = 0
        ViewStyle = vsReport
      end
      object ToolBar1: TToolBar
        Left = 338
        Top = 0
        Width = 63
        Height = 153
        Align = alRight
        AutoSize = True
        ButtonHeight = 36
        ButtonWidth = 63
        EdgeBorders = []
        Flat = True
        HotImages = WndMain.ilEditBarsH
        Images = WndMain.ilEditBars
        ShowCaptions = True
        TabOrder = 1
        object tbAdd: TToolButton
          Left = 0
          Top = 0
          Hint = 'Add Entry'
          Caption = 'Add'
          ImageIndex = 39
          ParentShowHint = False
          Wrap = True
          ShowHint = True
        end
        object tbDelete: TToolButton
          Left = 0
          Top = 36
          Hint = 'Delete Entry'
          Caption = 'Delete'
          ImageIndex = 40
          ParentShowHint = False
          Wrap = True
          ShowHint = True
        end
        object tbMoveUp: TToolButton
          Left = 0
          Top = 72
          Hint = 'Move Entry Up'
          Caption = 'Move Up'
          ImageIndex = 19
          ParentShowHint = False
          Wrap = True
          ShowHint = True
        end
        object tbMoveDown: TToolButton
          Left = 0
          Top = 108
          Hint = 'Move Entry Down'
          Caption = 'Move Down'
          ImageIndex = 18
          ParentShowHint = False
          ShowHint = True
        end
      end
    end
  end
  object ToolBar2: TToolBar
    Left = 0
    Top = 0
    Width = 401
    Height = 24
    AutoSize = True
    ButtonWidth = 53
    Caption = 'ToolBar2'
    EdgeBorders = [ebBottom]
    Flat = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    HotImages = WndMain.ilEditBarsH
    Images = WndMain.ilEditBars
    List = True
    ParentFont = False
    ShowCaptions = True
    TabOrder = 2
    object ToolButton1: TToolButton
      Left = 0
      Top = 0
      Caption = 'New'
      ImageIndex = 0
    end
    object ToolButton2: TToolButton
      Left = 53
      Top = 0
      Caption = 'Open'
      ImageIndex = 1
    end
    object ToolButton3: TToolButton
      Left = 106
      Top = 0
      Caption = 'Save'
      ImageIndex = 2
    end
    object ToolButton4: TToolButton
      Left = 159
      Top = 0
      Width = 8
      Caption = 'ToolButton4'
      ImageIndex = 3
      Style = tbsSeparator
    end
    object ToolButton5: TToolButton
      Left = 167
      Top = 0
      Caption = 'Close'
      ImageIndex = 28
    end
  end
  object OpenDialog: TOpenDialog
    InitialDir = 'D:\programming\SCIStudio\templates\scripts\menu example'
    Left = 232
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'mak'
    Left = 264
  end
end
