
// DrawView.h : CDrawView 类的接口
//

#pragma once


class CDrawView : public CView
{
//private:
protected: // 仅从序列化创建
	CDrawView();
	DECLARE_DYNCREATE(CDrawView)

// 特性
public:
	CDrawDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // DrawView.cpp 中的调试版本
inline CDrawDoc* CDrawView::GetDocument() const
   { return reinterpret_cast<CDrawDoc*>(m_pDocument); }
#endif

