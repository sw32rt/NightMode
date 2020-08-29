
// NightMode.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CNightModeApp:
// このクラスの実装については、NightMode.cpp を参照してください
//

class CNightModeApp : public CWinApp
{
public:
	CNightModeApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CNightModeApp theApp;
