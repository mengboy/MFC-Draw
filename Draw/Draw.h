
// Draw.h : Draw Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������

#include "Cpen.h"
// CDrawApp:
// �йش����ʵ�֣������ Draw.cpp
//

class CDrawApp : public CWinApp
{
private:
	Cpen  *m_pendlg;
public:
	CDrawApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrawApp theApp;
