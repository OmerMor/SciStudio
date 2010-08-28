object DlgCheckVersion: TDlgCheckVersion
  Left = 277
  Top = 226
  BorderStyle = bsNone
  Caption = 'Check for the Latest Version'
  ClientHeight = 172
  ClientWidth = 276
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poMainFormCenter
  Scaled = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 276
    Height = 172
    Align = alClient
    BevelInner = bvRaised
    TabOrder = 0
    object Label3: TLabel
      Left = 5
      Top = 44
      Width = 267
      Height = 23
      Alignment = taCenter
      AutoSize = False
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      Layout = tlCenter
      WordWrap = True
    end
    object Label1: TLabel
      Left = 8
      Top = 115
      Width = 261
      Height = 13
      Cursor = crHandPoint
      Alignment = taCenter
      AutoSize = False
      Caption = 'Click here to go to the download page.'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsUnderline]
      ParentColor = False
      ParentFont = False
      Transparent = True
      Layout = tlCenter
      OnClick = Label1Click
    end
    object Label2: TLabel
      Left = 2
      Top = 2
      Width = 272
      Height = 27
      AutoSize = False
      Color = clBlack
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnHighlight
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
      Layout = tlCenter
      OnMouseDown = Label2MouseDown
    end
    object Image1: TImage
      Left = 2
      Top = 29
      Width = 272
      Height = 8
      Picture.Data = {
        07544269746D61708E020000424D8E0200000000000000000000280000008000
        000008000000010004000200000018020000130B0000130B0000100000001000
        0000B56B1000BD6B1400C5711800D87D1800CF792300CF883C00E3882900EA93
        3B00E59B4F00E39F5B00E9A76800EBB06F00EFB57700F4BA7F00F7BD8C00F7CA
        94000080667587899AABBBBCCCCDCDDDEDEEEEEDDCCBAA999595555545122101
        0010010001000100111122242443463666667787999ABBCDDEEFFFFEDDBBA998
        8775663300000080665778889AAABBBCBCCCDCDDDEDEEEEEDCCBAAA999595555
        45151110001000010001000101112222424343646666777888AAABBCDEEFFFFE
        EDCBAA988877666300000080665778889AAABBBCBCCCDDDDEDEEDEFDDCCCAA99
        9595555554441210001000100010001001112222444434636666777888AAABCC
        DDEFFFFEEDCBBA9887867643000000806667788899AABBBCBCCCDCDDDDEDEEEE
        DDCBBAA999959555544221100100010001000100011112224243446366666777
        8899ABBCDDEEFFFFEDCCBA9988776663000000806665787899AAABBBCCCCCDCD
        DEDEEEEEDDCCBAA9995955555451411010010001000100010011122224443436
        46666778889AAABCCDEEFFFFEDDBBAA988877664000000803665778899AABABC
        BCCCCDDDDDEDEEEFDDCCBAA99995555555251211000100001000010000111222
        42443446366666778889AABCCDEEFFFFEEDCBAA9987756660000003864657778
        899AABBBBCCCCDDDDDEDEEEEEDDCBBAA99959555545251111200003611112224
        24343646666777888AAABBCDDEFFFFFEDCCAA988877664000000003836667788
        88AAABBBBCCCCCDCDDDEDEEEEDCCBBA999958555554422111200003601112222
        444343636666777889AABBCDDEEFFFEEDDBBA998877566000001}
      Stretch = True
    end
    object Label4: TLabel
      Left = 5
      Top = 76
      Width = 267
      Height = 31
      Alignment = taCenter
      AutoSize = False
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      Layout = tlCenter
      WordWrap = True
    end
    object Button1: TButton
      Left = 101
      Top = 138
      Width = 75
      Height = 25
      Caption = 'OK'
      TabOrder = 0
      OnClick = Button1Click
    end
  end
end
