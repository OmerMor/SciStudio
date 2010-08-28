object DlgSettings: TDlgSettings
  Left = 192
  Top = 107
  BorderStyle = bsDialog
  Caption = 'Settings'
  ClientHeight = 348
  ClientWidth = 352
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 352
    Height = 317
    ActivePage = General
    Align = alTop
    TabOrder = 0
    object General: TTabSheet
      Caption = 'General'
      object GroupBox1: TGroupBox
        Left = 8
        Top = 8
        Width = 329
        Height = 57
        Caption = 'Startup'
        TabOrder = 0
        object cbShowSplashScreen: TCheckBox
          Left = 8
          Top = 16
          Width = 257
          Height = 17
          Caption = 'Show Splash Screen'
          TabOrder = 0
        end
        object cbShowWelcomeScreen: TCheckBox
          Left = 8
          Top = 32
          Width = 257
          Height = 17
          Caption = 'Show Welcome Screen'
          TabOrder = 1
        end
      end
      object GroupBox3: TGroupBox
        Left = 8
        Top = 72
        Width = 329
        Height = 73
        Caption = 'Editors'
        TabOrder = 1
        object Label10: TLabel
          Left = 8
          Top = 44
          Width = 57
          Height = 13
          Caption = 'Max Undos:'
        end
        object cbQuerySaving: TCheckBox
          Left = 8
          Top = 16
          Width = 257
          Height = 17
          Caption = 'Query Saving'
          TabOrder = 0
        end
        object edMaxUndos: TEdit
          Left = 72
          Top = 40
          Width = 33
          Height = 21
          ReadOnly = True
          TabOrder = 1
          Text = '000'
        end
        object udMaxUndos: TUpDown
          Left = 104
          Top = 38
          Width = 16
          Height = 24
          Min = 1
          Position = 1
          TabOrder = 2
          Wrap = False
          OnClick = udMaxUndosClick
        end
      end
      object BitBtn1: TButton
        Left = 57
        Top = 156
        Width = 97
        Height = 25
        Caption = 'C&enter Window'
        TabOrder = 2
        OnClick = BitBtn1Click
      end
      object BitBtn2: TButton
        Left = 161
        Top = 156
        Width = 125
        Height = 25
        Caption = '&Remove From Registry'
        TabOrder = 3
        OnClick = BitBtn2Click
      end
    end
    object Desktop: TTabSheet
      Caption = 'Desktop'
      ImageIndex = 3
      object GroupBox6: TGroupBox
        Left = 8
        Top = 8
        Width = 329
        Height = 49
        Caption = 'Background'
        TabOrder = 0
        object Label3: TLabel
          Left = 21
          Top = 21
          Width = 60
          Height = 13
          Caption = 'Colour (hex)'
        end
        object shBkColour: TShape
          Left = 172
          Top = 17
          Width = 149
          Height = 21
        end
        object SpeedButton1: TSpeedButton
          Left = 172
          Top = 17
          Width = 149
          Height = 21
          Caption = 'Select'
          Flat = True
          OnClick = SpeedButton1Click
        end
        object edBkColour: TEdit
          Left = 85
          Top = 17
          Width = 84
          Height = 21
          TabOrder = 0
          OnChange = edBkColourChange
        end
      end
      object GroupBox2: TGroupBox
        Left = 8
        Top = 64
        Width = 329
        Height = 145
        Caption = 'Tool Bar'
        TabOrder = 1
        object Shape2: TShape
          Left = 104
          Top = 16
          Width = 217
          Height = 65
        end
        object Label9: TLabel
          Left = 113
          Top = 24
          Width = 200
          Height = 49
          Alignment = taCenter
          AutoSize = False
          Caption = '(none)'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          Transparent = True
          Layout = tlCenter
        end
        object Image1: TImage
          Left = 105
          Top = 17
          Width = 217
          Height = 63
          Stretch = True
        end
        object cbToolBarVisible: TCheckBox
          Left = 8
          Top = 88
          Width = 260
          Height = 17
          Caption = 'Visible'
          TabOrder = 0
        end
        object cbShowTextLabels: TCheckBox
          Left = 8
          Top = 104
          Width = 260
          Height = 17
          Caption = 'Show Text Labels'
          TabOrder = 1
        end
        object cbAlwaysColour: TCheckBox
          Left = 8
          Top = 120
          Width = 260
          Height = 17
          Caption = 'Always Colour'
          TabOrder = 2
        end
        object bcToolbarBitmap: TCheckBox
          Left = 8
          Top = 16
          Width = 57
          Height = 17
          Caption = 'Bitmap'
          TabOrder = 3
          OnClick = bcToolbarBitmapClick
        end
        object Button1: TButton
          Left = 24
          Top = 37
          Width = 73
          Height = 25
          Caption = 'Select'
          TabOrder = 4
          OnClick = Button1Click
        end
      end
    end
    object Explorer: TTabSheet
      Caption = 'Explorer'
      ImageIndex = 1
      object GroupBox4: TGroupBox
        Left = 8
        Top = 8
        Width = 329
        Height = 73
        Caption = 'Startup'
        TabOrder = 0
        object Label1: TLabel
          Left = 8
          Top = 24
          Width = 114
          Height = 13
          Caption = 'Default Resource Type:'
        end
        object DefaultResourceType: TComboBox
          Left = 176
          Top = 20
          Width = 145
          Height = 21
          Style = csDropDownList
          ItemHeight = 0
          TabOrder = 0
        end
        object cbShowPreview: TCheckBox
          Left = 8
          Top = 48
          Width = 257
          Height = 17
          Caption = 'Show Preview'
          TabOrder = 1
        end
      end
      object GroupBox5: TGroupBox
        Left = 8
        Top = 136
        Width = 329
        Height = 145
        Caption = 'List View Properties'
        TabOrder = 1
        object Label2: TLabel
          Left = 8
          Top = 121
          Width = 49
          Height = 13
          Caption = 'View Style'
        end
        object cbFlatScroll: TCheckBox
          Left = 8
          Top = 16
          Width = 257
          Height = 17
          Caption = 'Flat Scroll Bars'
          TabOrder = 0
        end
        object cbHotTrack: TCheckBox
          Left = 8
          Top = 49
          Width = 257
          Height = 17
          Caption = 'Hot Track'
          TabOrder = 1
        end
        object cbHandPoint: TCheckBox
          Left = 24
          Top = 65
          Width = 241
          Height = 17
          Caption = 'htHandPoint'
          TabOrder = 2
        end
        object cbUnderlineC: TCheckBox
          Left = 24
          Top = 81
          Width = 241
          Height = 17
          Caption = 'htUnderlineCold'
          TabOrder = 3
        end
        object cbUnderlineH: TCheckBox
          Left = 24
          Top = 97
          Width = 241
          Height = 17
          Caption = 'htUnderlineHot'
          TabOrder = 4
        end
        object cbGridLines: TCheckBox
          Left = 8
          Top = 32
          Width = 257
          Height = 17
          Caption = 'Grid Lines'
          TabOrder = 5
        end
        object cbViewStyle: TComboBox
          Left = 64
          Top = 117
          Width = 105
          Height = 21
          Style = csDropDownList
          ItemHeight = 0
          TabOrder = 6
        end
      end
      object GroupBox7: TGroupBox
        Left = 7
        Top = 88
        Width = 330
        Height = 41
        Caption = 'Editors'
        TabOrder = 2
        object cbSepScrWnds: TCheckBox
          Left = 8
          Top = 16
          Width = 257
          Height = 17
          Caption = 'Open scripts in the seperate editor windows'
          TabOrder = 0
        end
      end
    end
    object System: TTabSheet
      Caption = 'System'
      ImageIndex = 3
      object GroupBox8: TGroupBox
        Left = 8
        Top = 8
        Width = 329
        Height = 265
        Caption = 'File Associations'
        TabOrder = 0
        object Label4: TLabel
          Left = 8
          Top = 88
          Width = 126
          Height = 13
          Caption = 'Associate SCI Studio with:'
        end
        object Label5: TLabel
          Left = 8
          Top = 158
          Width = 313
          Height = 26
          AutoSize = False
          Caption = 
            'SCI Studio will load views, pics, fonts, cursors and text resour' +
            'ces from the command line as well.'
          WordWrap = True
        end
        object Label6: TLabel
          Left = 8
          Top = 188
          Width = 313
          Height = 52
          AutoSize = False
          Caption = 
            'However, since they are named .000-.999, it would not be a good ' +
            'idea to associate all of them with SCI Studio, as many of you mi' +
            'ght not want to have 1000 registry entries you may not even use.'
          WordWrap = True
        end
        object Label7: TLabel
          Left = 8
          Top = 246
          Width = 313
          Height = 13
          AutoSize = False
          Caption = 'You can associate them manually if you wish.'
          WordWrap = True
        end
        object Label8: TLabel
          Left = 8
          Top = 22
          Width = 313
          Height = 39
          AutoSize = False
          Caption = 
            'If you would like the ability to right click on a game'#39's folder ' +
            'and have the option of opening it with SCI Studio, check the box' +
            ' below.'
          WordWrap = True
        end
        object cbAsResourcemap: TCheckBox
          Left = 24
          Top = 104
          Width = 257
          Height = 17
          Caption = 'Resource.map files'
          TabOrder = 0
        end
        object cbAsSC: TCheckBox
          Left = 24
          Top = 120
          Width = 257
          Height = 17
          Caption = 'Script source files (*.sc)'
          TabOrder = 1
        end
        object cbAsSH: TCheckBox
          Left = 24
          Top = 136
          Width = 257
          Height = 17
          Caption = 'Script header files (*.sh)'
          TabOrder = 2
        end
        object cbFolderShortcut: TCheckBox
          Left = 24
          Top = 64
          Width = 257
          Height = 17
          Caption = 'Open Game shortcut in folder submenus'
          TabOrder = 3
        end
      end
    end
  end
  object CancelBtn: TButton
    Left = 271
    Top = 321
    Width = 81
    Height = 25
    Cancel = True
    Caption = '&Cancel'
    TabOrder = 1
    OnClick = CancelBtnClick
  end
  object OKBtn: TButton
    Left = 95
    Top = 321
    Width = 81
    Height = 25
    Caption = '&OK'
    Default = True
    TabOrder = 2
    OnClick = OKBtnClick
  end
  object ApplyBtn: TButton
    Left = 183
    Top = 321
    Width = 81
    Height = 25
    Caption = '&Apply'
    TabOrder = 3
    OnClick = ApplyBtnClick
  end
  object ColorDialog: TColorDialog
    Ctl3D = True
    Options = [cdFullOpen]
    Left = 268
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Filter = 'Bitmaps (*.bmp)|*.bmp'
    Left = 240
  end
end
