object DlgFontTest: TDlgFontTest
  Left = 199
  Top = 180
  BorderStyle = bsNone
  Caption = 'Font Tester'
  ClientHeight = 55
  ClientWidth = 560
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  Scaled = False
  OnClose = FormClose
  OnKeyPress = FormKeyPress
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 0
    Top = 0
    Width = 560
    Height = 55
    Align = alClient
    Pen.Width = 2
    OnMouseDown = Shape1MouseDown
  end
  object Button1: TSpeedButton
    Left = 528
    Top = 6
    Width = 26
    Height = 24
    Caption = '×'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    OnClick = Button1Click
  end
  object ImgEnter: TImage
    Left = 11
    Top = 14
    Width = 120
    Height = 20
    Picture.Data = {
      07544269746D61708E000000424D8E000000000000003E000000280000003C00
      00000A0000000100010000000000500000000000000000000000020000000200
      000000000000FFFFFF00FFFFFFFFFFF1FFF0FFFFFFFFFFFBFFF00223B31F1118
      F2E0BB776DBFBBBB6DD0BF776FBFBBBB6DD0B77761BFBBBB6DD087776DBFBBBB
      6DD0B68E334F3470C980BBFF7FFFFFFFFFD003FFFFFFBFFFFFF0}
    Stretch = True
  end
  object Shape2: TShape
    Left = 5
    Top = 41
    Width = 550
    Height = 12
    Pen.Width = 2
  end
  object Image1: TImage
    Left = 10
    Top = 45
    Width = 540
    Height = 4
  end
end
