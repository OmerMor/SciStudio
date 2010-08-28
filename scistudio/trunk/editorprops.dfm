object DlgEditorProps: TDlgEditorProps
  Left = 193
  Top = 103
  BorderStyle = bsDialog
  Caption = 'Properties'
  ClientHeight = 307
  ClientWidth = 310
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  Scaled = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 310
    Height = 274
    ActivePage = TabSheet2
    Align = alClient
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'General'
      object GroupBox1: TGroupBox
        Left = 5
        Top = 3
        Width = 295
        Height = 49
        Caption = 'Font'
        TabOrder = 0
        object Label1: TLabel
          Left = 14
          Top = 21
          Width = 31
          Height = 13
          Caption = 'Name:'
          Layout = tlCenter
        end
        object Label2: TLabel
          Left = 211
          Top = 21
          Width = 23
          Height = 13
          Caption = 'Size:'
          Layout = tlCenter
        end
        object cbFontName: TComboBox
          Left = 46
          Top = 17
          Width = 154
          Height = 21
          Style = csDropDownList
          ItemHeight = 13
          TabOrder = 0
          OnChange = cbFontNameChange
        end
        object cbFontSize: TComboBox
          Left = 236
          Top = 17
          Width = 49
          Height = 21
          Style = csDropDownList
          ItemHeight = 13
          TabOrder = 1
          OnChange = cbFontSizeChange
        end
      end
      object GroupBox2: TGroupBox
        Left = 5
        Top = 59
        Width = 295
        Height = 49
        Caption = 'Gutter'
        TabOrder = 1
        object Label3: TLabel
          Left = 186
          Top = 22
          Width = 32
          Height = 13
          Caption = 'Width:'
          Layout = tlCenter
        end
        object cbGutterVisible: TCheckBox
          Left = 9
          Top = 21
          Width = 54
          Height = 17
          Caption = 'Visible'
          TabOrder = 0
          OnClick = cbGutterVisibleClick
        end
        object cbGutterWidth: TComboBox
          Left = 222
          Top = 18
          Width = 62
          Height = 21
          Style = csDropDownList
          ItemHeight = 13
          TabOrder = 1
          OnChange = cbGutterWidthChange
        end
        object cbLineNumbers: TCheckBox
          Left = 81
          Top = 21
          Width = 88
          Height = 17
          Caption = 'Line Numbers'
          TabOrder = 2
          OnClick = cbLineNumbersClick
        end
      end
      object GroupBox3: TGroupBox
        Left = 4
        Top = 115
        Width = 295
        Height = 126
        Caption = 'General'
        TabOrder = 2
        object Label6: TLabel
          Left = 193
          Top = 72
          Width = 44
          Height = 13
          Caption = 'Tab Size:'
          Layout = tlCenter
        end
        object Label5: TLabel
          Left = 153
          Top = 96
          Width = 84
          Height = 13
          Caption = 'Extra Line Space:'
          Layout = tlCenter
        end
        object cbTabSize: TComboBox
          Left = 240
          Top = 68
          Width = 45
          Height = 21
          Style = csDropDownList
          ItemHeight = 13
          TabOrder = 0
          OnChange = cbTabSizeChange
        end
        object cbSmartTabs: TCheckBox
          Left = 9
          Top = 31
          Width = 100
          Height = 17
          Caption = 'Smart Tabs'
          TabOrder = 1
          OnClick = cbSmartTabsClick
        end
        object cbTabsToSpaces: TCheckBox
          Left = 9
          Top = 63
          Width = 100
          Height = 17
          Caption = 'Tabs to Spaces'
          TabOrder = 2
          OnClick = cbTabsToSpacesClick
        end
        object cbTrimTrailingSpaces: TCheckBox
          Left = 9
          Top = 79
          Width = 100
          Height = 17
          Caption = 'Trim Trailing'
          TabOrder = 3
          OnClick = cbTrimTrailingSpacesClick
        end
        object cbAutoIndent: TCheckBox
          Left = 9
          Top = 15
          Width = 100
          Height = 17
          Caption = 'Auto Indent'
          TabOrder = 4
          OnClick = cbAutoIndentClick
        end
        object cbExtraLineSpacing: TComboBox
          Left = 240
          Top = 92
          Width = 45
          Height = 21
          Style = csDropDownList
          ItemHeight = 13
          TabOrder = 5
          OnChange = cbExtraLineSpacingChange
        end
        object cbGroupUndo: TCheckBox
          Left = 9
          Top = 95
          Width = 100
          Height = 17
          Caption = 'Group Undo'
          TabOrder = 6
          OnClick = cbGroupUndoClick
        end
        object cbSmartTabDelete: TCheckBox
          Left = 9
          Top = 47
          Width = 112
          Height = 17
          Caption = 'Smart Tab Delete'
          TabOrder = 7
          OnClick = cbSmartTabDeleteClick
        end
        object cbDragDrop: TCheckBox
          Left = 157
          Top = 15
          Width = 128
          Height = 17
          Caption = 'Drag and Drop Editing'
          TabOrder = 8
          OnClick = cbDragDropClick
        end
        object cbScrollEOF: TCheckBox
          Left = 157
          Top = 31
          Width = 128
          Height = 17
          Caption = 'Scroll Past End of File'
          TabOrder = 9
          OnClick = cbScrollEOFClick
        end
        object cbNoCaret: TCheckBox
          Left = 157
          Top = 47
          Width = 128
          Height = 17
          Caption = 'No Caret'
          TabOrder = 10
          OnClick = cbNoCaretClick
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Colours'
      ImageIndex = 1
      object pnBG: TPanel
        Left = 151
        Top = 38
        Width = 68
        Height = 24
        BevelOuter = bvNone
        BorderStyle = bsSingle
        TabOrder = 5
        object BtnBG: TSpeedButton
          Left = 0
          Top = 0
          Width = 64
          Height = 20
          Caption = 'Background'
          Flat = True
          OnClick = BtnBGClick
        end
      end
      object lbHlNames: TListBox
        Left = 3
        Top = 2
        Width = 142
        Height = 67
        ItemHeight = 13
        TabOrder = 0
        OnClick = lbHlNamesClick
      end
      object cbBold: TCheckBox
        Left = 224
        Top = 11
        Width = 75
        Height = 17
        Caption = 'Bold'
        TabOrder = 1
        OnClick = UpdateAttr1Click
      end
      object cbItalic: TCheckBox
        Left = 224
        Top = 27
        Width = 75
        Height = 17
        Caption = 'Italic'
        TabOrder = 3
        OnClick = UpdateAttr1Click
      end
      object cbUnderlined: TCheckBox
        Left = 224
        Top = 43
        Width = 75
        Height = 17
        Caption = 'Underlined'
        TabOrder = 2
        OnClick = UpdateAttr1Click
      end
      object SCIMemo: TSynMemo
        Left = 3
        Top = 72
        Width = 297
        Height = 169
        Cursor = crIBeam
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Courier New'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        TabOrder = 4
        Gutter.Font.Charset = DEFAULT_CHARSET
        Gutter.Font.Color = clWindowText
        Gutter.Font.Height = -11
        Gutter.Font.Name = 'Terminal'
        Gutter.Font.Style = []
        Highlighter = SynSCISyn1
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
            Command = ecPaste
            ShortCut = 8237
          end
          item
            Command = ecDeleteChar
            ShortCut = 46
          end
          item
            Command = ecCut
            ShortCut = 8238
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
            Command = ecSelectAll
            ShortCut = 16449
          end
          item
            Command = ecCopy
            ShortCut = 16451
          end
          item
            Command = ecBlockIndent
            ShortCut = 24649
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
            Command = ecBlockUnindent
            ShortCut = 24661
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
            Command = ecTab
            ShortCut = 9
          end
          item
            Command = ecShiftTab
            ShortCut = 8201
          end
          item
            Command = ecMatchBracket
            ShortCut = 24642
          end>
        Lines.Strings = (
          '// This is a comment'
          '(instance public Hello of Game'
          #9'(properties'
          #9#9'script 0'
          #9')'
          #9'(method (init)'
          #9#9'(var SomeVar)'#9
          #9#9'Print("Hello World!")'
          #9#9'= SomeVar (* 20 30)'
          #9')'
          ')')
        ReadOnly = True
      end
      object pnFG: TPanel
        Left = 151
        Top = 9
        Width = 68
        Height = 24
        BevelOuter = bvNone
        BorderStyle = bsSingle
        TabOrder = 6
        object BtnFG: TSpeedButton
          Left = 0
          Top = 0
          Width = 64
          Height = 20
          Caption = 'Foreground'
          Flat = True
          OnClick = BtnFGClick
        end
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 274
    Width = 310
    Height = 33
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object BitBtn1: TButton
      Left = 152
      Top = 5
      Width = 75
      Height = 25
      Caption = 'OK'
      TabOrder = 0
      OnClick = BitBtn1Click
    end
    object BitBtn2: TButton
      Left = 232
      Top = 5
      Width = 75
      Height = 25
      Caption = 'Cancel'
      TabOrder = 1
      OnClick = BitBtn2Click
    end
  end
  object ColorDialog: TColorDialog
    Ctl3D = True
    Options = [cdFullOpen, cdSolidColor]
    Left = 248
  end
  object SynSCISyn1: TSynSCISyn
    DefaultFilter = 'C++ files (*.cpp,*.h,*.hpp)|*.cpp;*.h;*.hpp'
    SpaceAttri.Foreground = clNone
    Left = 216
  end
end
