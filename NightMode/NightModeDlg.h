
// NightModeDlg.h : ヘッダー ファイル
//

#pragma once


// CNightModeDlg ダイアログ
class CNightModeDlg : public CDialogEx
{
private:
	CBrush m_brDlg;		// ダイアログの背景色ブラシ(ここを追加する)
// コンストラクション
public:
	CNightModeDlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NIGHTMODE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
