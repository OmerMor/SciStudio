object DlgViewFont: TDlgViewFont
  Left = 192
  Top = 107
  Width = 358
  Height = 247
  BorderStyle = bsSizeToolWin
  Caption = 'View Font'
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Scaled = False
  OnClose = FormClose
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object scrFont: TScrollBox
    Left = 0
    Top = 0
    Width = 350
    Height = 220
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
