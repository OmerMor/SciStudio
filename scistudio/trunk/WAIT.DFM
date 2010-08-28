object DlgWait: TDlgWait
  Left = 329
  Top = 243
  BorderIcons = []
  BorderStyle = bsToolWindow
  Caption = 'Please Wait...'
  ClientHeight = 52
  ClientWidth = 150
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poOwnerFormCenter
  Scaled = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 0
    Top = 0
    Width = 150
    Height = 25
    Align = alTop
    Caption = 'Processing...'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object ProgressBar: TProgressBar
    Left = 0
    Top = 29
    Width = 150
    Height = 23
    Align = alBottom
    Min = 0
    Max = 100
    TabOrder = 0
  end
end
