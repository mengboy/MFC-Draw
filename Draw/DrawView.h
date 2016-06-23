
// DrawView.h : CDrawView ��Ľӿ�
//

#pragma once


class CDrawView : public CView
{
//private:
protected: // �������л�����
	CDrawView();
	DECLARE_DYNCREATE(CDrawView)

// ����
public:
	CDrawDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChoice();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	HCURSOR cross;
	HCURSOR arrow;
	CPoint chosen_position;
	CPoint instant_position;
	CPoint point;
	bool is_leftButton_down = false;
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void OnInitialUpdate();
	afx_msg void DrawBezier(CPoint start, CPoint control_first, CPoint control_second, CPoint end);
	CPoint control_first;
	CPoint control_second;
	int start = 0;
	int a, b;
	bool Under_painting = false;
	afx_msg void OnFileSave();
};

#ifndef _DEBUG  // DrawView.cpp �еĵ��԰汾
inline CDrawDoc* CDrawView::GetDocument() const
   { return reinterpret_cast<CDrawDoc*>(m_pDocument); }
#endif

