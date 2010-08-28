object DlgResRebuild: TDlgResRebuild
  Left = 223
  Top = 177
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Resource Rebuilder'
  ClientHeight = 212
  ClientWidth = 312
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  Scaled = False
  OnActivate = FormActivate
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Status: TLabel
    Left = 0
    Top = 0
    Width = 312
    Height = 25
    Align = alTop
    Alignment = taCenter
    AutoSize = False
    Caption = 'Rebuilding Resources...'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = True
    Layout = tlCenter
    WordWrap = True
  end
  object Panel1: TPanel
    Left = 4
    Top = 25
    Width = 304
    Height = 22
    BevelOuter = bvNone
    BorderStyle = bsSingle
    TabOrder = 0
    object ProgressGauge: TCGauge
      Left = 0
      Top = 0
      Width = 300
      Height = 18
      Align = alClient
      BorderStyle = bsNone
      ForeColor = clBlue
    end
  end
  object OKButton: TButton
    Left = 230
    Top = 182
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    Enabled = False
    TabOrder = 1
    OnClick = OKButtonClick
  end
  object pnlClient: TPanel
    Left = 0
    Top = 48
    Width = 313
    Height = 131
    BevelOuter = bvNone
    TabOrder = 2
    Visible = False
    object Shape1: TShape
      Left = 17
      Top = 1
      Width = 17
      Height = 15
      Brush.Color = clBlue
    end
    object Label1: TLabel
      Left = 41
      Top = 2
      Width = 77
      Height = 13
      Caption = 'New Game Size:'
    end
    object Label2: TLabel
      Left = 128
      Top = 2
      Width = 86
      Height = 13
      Caption = 'XX,XXX,XXX bytes'
    end
    object Label3: TLabel
      Left = 223
      Top = 2
      Width = 65
      Height = 13
      Caption = 'XX,XXX.XX KB'
    end
    object Label4: TLabel
      Left = 223
      Top = 20
      Width = 65
      Height = 13
      Caption = 'XX,XXX.XX KB'
    end
    object Label5: TLabel
      Left = 128
      Top = 20
      Width = 86
      Height = 13
      Caption = 'XX,XXX,XXX bytes'
    end
    object Label6: TLabel
      Left = 41
      Top = 20
      Width = 64
      Height = 13
      Caption = 'Space Freed:'
    end
    object Shape2: TShape
      Left = 17
      Top = 19
      Width = 17
      Height = 15
      Brush.Color = clFuchsia
    end
    object Pie4: TPie
      Left = 77
      Top = 47
      Width = 160
      Height = 80
      Angles.StartAngle = 180
      Angles.EndAngle = 90
      Brush.Color = clPurple
    end
    object Pie3: TPie
      Left = 77
      Top = 47
      Width = 160
      Height = 80
      Angles.StartAngle = 180
      Angles.EndAngle = 90
      Brush.Color = clNavy
    end
    object Pie2: TPie
      Left = 77
      Top = 41
      Width = 160
      Height = 80
      Angles.StartAngle = 180
      Angles.EndAngle = 90
      Brush.Color = clFuchsia
    end
    object Pie1: TPie
      Left = 77
      Top = 41
      Width = 160
      Height = 80
      Angles.StartAngle = 180
      Angles.EndAngle = 90
      Brush.Color = clBlue
    end
  end
end
