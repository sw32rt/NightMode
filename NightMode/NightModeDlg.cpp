
// NightModeDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "NightMode.h"
#include "NightModeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNightModeDlg ダイアログ



CNightModeDlg::CNightModeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NIGHTMODE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNightModeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNightModeDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CNightModeDlg メッセージ ハンドラー

BOOL CNightModeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	CRect rect;
	HWND hDeskWnd = ::GetDesktopWindow(); //この関数でデスクトップのハンドルを取得
	::GetWindowRect(hDeskWnd, rect); //デスクトップのハンドルからその(画面の)大きさを取得
	MoveWindow(rect, TRUE);

	// 現在のウィンドウスタイルを取得
	UINT style = ::GetWindowLong(this->GetSafeHwnd(), GWL_EXSTYLE);
	// ウィンドウスタイルにWS_EX_LAYEREDを追加
	style |= WS_EX_LAYERED;
	// ウィンドウにスタイル適用
	::SetWindowLong(this->GetSafeHwnd(), GWL_EXSTYLE, style);
	// ウィンドウの透明度を設定(127が透明度、0〜255で指定)
	this->SetLayeredWindowAttributes(0, 127, LWA_ALPHA);

	// ウィンドウ背景色のブラシを作成する．
	m_brDlg.CreateSolidBrush(RGB(0, 0, 0));

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CNightModeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CNightModeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



HBRUSH CNightModeDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	return (HBRUSH)m_brDlg;

	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO: ここで DC の属性を変更してください。

	// TODO: 既定値を使用したくない場合は別のブラシを返します。
	return hbr;
}
