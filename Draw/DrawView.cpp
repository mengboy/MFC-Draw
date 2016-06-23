
// DrawView.cpp : CDrawView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Draw.h"
#endif

#include "DrawDoc.h"
#include "DrawView.h"
#include "Cpen.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

BEGIN_MESSAGE_MAP(CDrawView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_CHOICE, &CDrawView::OnChoice)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_CREATE()
	ON_COMMAND(ID_FILE_SAVE, &CDrawView::OnFileSave)
END_MESSAGE_MAP()

// CDrawView 构造/析构

CDrawView::CDrawView()
{
	// TODO: 在此处添加构造代码

}

CDrawView::~CDrawView()
{
}

BOOL CDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDrawView 绘制

void CDrawView::OnDraw(CDC* /*pDC*/)
{
	CDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CDrawView 打印

BOOL CDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDrawView 诊断

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawDoc* CDrawView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDoc)));
	return (CDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawView 消息处理程序

void CDrawView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	OnChoice();
}


void CDrawView::OnChoice()
{
	// TODO: 在此添加命令处理程序代码
	CRect rect;
	GetClientRect(rect);//获得窗体的大小
	Cpen * m_CpenDlg;
	// 创建非模态对话框实例   
	m_CpenDlg = new Cpen;
	m_CpenDlg->Create(IDD_DIALOG_PEN_STYLE, NULL);
	//设置位置
    m_CpenDlg->SetWindowPos(&CWnd::wndTop, rect.right - 80, rect.top + 50, 0, 0, SWP_NOSIZE);
	// 显示非模态对话框   
	m_CpenDlg->ShowWindow(SW_SHOW);
		 
	
}		 



void CDrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	is_leftButton_down = true;
	//画点
	if (shape == 0)
	{
		if (is_leftButton_down)
		{
			is_leftButton_down = false;
			CClientDC dc(this);
			dc.SetPixel(point, RGB(0, 0, 0));
		}
	}
	//画线
	if (shape == 1 || shape == 2 || shape == 3 || shape == 4 || shape == 5)
	{
		::SetCursor(cross);
		chosen_position = instant_position = point;
	}
	if (shape == 7)
	{
		if (!Under_painting)
		{
			::SetCursor(cross);
			chosen_position = instant_position = point;
		}
		else
		{
			::SetCursor(cross);
			instant_position = point;
		}
	}
	CView::OnLButtonDown(nFlags, point);
}


void CDrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC *pDC;
	pDC = GetDC();
	if (shape == 1)
	{
		//CPoint now_point = point;
		if ((nFlags == MK_LBUTTON) && is_leftButton_down)
		{
			::SetCursor(cross);
			pDC->SetROP2(R2_NOT);
			//undraw old line
			pDC->MoveTo(chosen_position);
			pDC->LineTo(instant_position);
			//draw new line
			pDC->MoveTo(chosen_position);
			pDC->LineTo(point);
			instant_position = point;
		}
		else
		{
			::SetCursor(arrow);
		}
	}
	if (shape == 2)
	{
		if ((nFlags == MK_LBUTTON) && is_leftButton_down)
		{
			::SetCursor(cross);
			CPen pen(pen_style, pen_weight, RGB(color_R, color_G, color_B));
			pDC->SelectObject(&pen);
			pDC->MoveTo(chosen_position);
			pDC->LineTo(point);
			chosen_position = point;//将当前坐标作为下一个起点
		}
		else
		{
			::SetCursor(arrow);
		}
	}
	if (shape == 3)
	{
		if ((nFlags == MK_LBUTTON) && is_leftButton_down)
		{
			::SetCursor(cross);
			CBrush *OldBrush;
			OldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);
			pDC->SetROP2(R2_NOT);
			//undraw old 
			pDC->Rectangle(CRect(chosen_position, instant_position));
			//draw new 
			pDC->Rectangle(CRect(chosen_position, point));
			pDC->SelectObject(OldBrush);
			instant_position = point;
		}
		else
		{
			::SetCursor(arrow);
		}
	}

	if (shape == 4)
	{
		if ((nFlags == MK_LBUTTON) && is_leftButton_down)
		{
			::SetCursor(cross);
			//CClientDC dc(this);
			CBrush *OldBrush;
			OldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);//创建一个不填充的画刷
			int r;                 //圆的半径
			pDC->SetROP2(R2_NOT);
			pDC->MoveTo(chosen_position);
			pDC->LineTo(instant_position.x, instant_position.y);
			r = sqrt((chosen_position.x - instant_position.x)*(chosen_position.x - instant_position.x)
				+ (chosen_position.y - instant_position.y)*(chosen_position.y - instant_position.y));
			pDC->Ellipse(chosen_position.x - r, chosen_position.y - r, chosen_position.x + r, chosen_position.y + r);

			pDC->MoveTo(chosen_position);
			pDC->LineTo(point);
			r = sqrt((chosen_position.x - point.x)*(chosen_position.x - point.x)
				+ (chosen_position.y - point.y)*(chosen_position.y - point.y));
			pDC->Ellipse(chosen_position.x - r, chosen_position.y - r, chosen_position.x + r, chosen_position.y + r);
			instant_position = point;

			pDC->SelectObject(OldBrush);
			
		}
		else
		{
			::SetCursor(arrow);
		}
	}

	if (shape == 5)
	{
		if ((nFlags == MK_LBUTTON) && is_leftButton_down)
		{
			::SetCursor(cross);
			CBrush *OldBrush;
			OldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);
			pDC->SetROP2(R2_NOT);
			//undraw old line
			//pDC->RoundRect(CRect(chosen_position, instant_position));
			pDC->RoundRect(CRect(chosen_position, instant_position), CPoint(15, 15));
			//draw new line
			pDC->RoundRect(CRect(chosen_position, point), CPoint(15, 15));
			pDC->SelectObject(OldBrush);
			instant_position = point;

		}
		else
		{
			::SetCursor(arrow);
		}
	}
	if (shape == 7)
	{
		if (!Under_painting)
		{
			if ((nFlags == MK_LBUTTON) && is_leftButton_down)
			{
				::SetCursor(cross);
				
				pDC->MoveTo(chosen_position);
				pDC->LineTo(chosen_position.x, point.y);
				//undraw old line
				pDC->SetROP2(R2_NOT);
				pDC->MoveTo(chosen_position);
				pDC->LineTo(chosen_position.x, instant_position.y);
				//draw new line
				instant_position = point;
			}
		}
		else if (Under_painting)
		{
			::SetCursor(cross);
			CClientDC dc(this);
			b = point.x - chosen_position.x;
			int instant_b = instant_position.x - chosen_position.x;

			//dc.SetROP2(R2_NOT);
			CBrush *OldBrush;
			OldBrush = (CBrush*)dc.SelectStockObject(NULL_BRUSH);
			//dc.Ellipse(chosen_position.x - instant_b, chosen_position.y - a, chosen_position.x + instant_b, chosen_position.y + a);
			dc.Ellipse(chosen_position.x - b, chosen_position.y - a, chosen_position.x + b, chosen_position.y + a);
			dc.SetROP2(R2_NOT);
			dc.Ellipse(chosen_position.x - b, chosen_position.y - a, chosen_position.x + b, chosen_position.y + a);
			dc.SelectObject(OldBrush);

			instant_position = point;
		}
		else
		{
			::SetCursor(arrow);
		}
	}
	//if (shape == 6)
	//{
	//	if ((nFlags == MK_LBUTTON) && is_leftButton_down)
	//	{
	//		DrawBezier(chosen_position,control_first, control_second, point);
	//		control_first = point;
	//		DrawBezier(chosen_position, control_first, control_second, point);
	//	}
	//	else if ((nFlags == MK_RBUTTON) && is_leftButton_down)
	//	{
	//		DrawBezier(chosen_position, control_first, control_second, point);
	//		control_second = point;
	//		//start = 1;
	//		DrawBezier(chosen_position, control_first, control_second, point);
	//	}
	//	/*else if (start)
	//	{
	//		DrawBezier();
	//		start = 0;
	//	}*/
	//}
	CView::OnMouseMove(nFlags, point);
}


void CDrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC *pDC;
	pDC = GetDC();
	if (shape == 1)
	{
		if (is_leftButton_down)
		{
			is_leftButton_down = false;
			::SetCursor(arrow);
			CPen pen(pen_style, pen_weight, RGB(color_R, color_G, color_B));
			pDC->SelectObject(&pen);
			pDC->MoveTo(chosen_position);
			pDC->LineTo(instant_position);
		}
	}
	if (shape == 3)
	{
		if (is_leftButton_down)
		{
			is_leftButton_down = false;
			::SetCursor(arrow);
			CPen pen(pen_style, pen_weight, RGB(color_R, color_G, color_B));
			pDC->SelectObject(&pen);
			pDC->Rectangle(CRect(chosen_position, instant_position));
		}
	}
	if (shape == 4)
	{
		if (is_leftButton_down)
		{
			int r;                 //圆的半径
			r = sqrt((chosen_position.x - instant_position.x)*(chosen_position.x - instant_position.x)
				+ (chosen_position.y - instant_position.y)*(chosen_position.y - instant_position.y));
			CPen pen(pen_style, pen_weight, RGB(color_R, color_G, color_B));
			pDC->SelectObject(&pen);
			pDC->Ellipse(chosen_position.x - r, chosen_position.y - r, chosen_position.x + r, chosen_position.y + r);
		}
	}
	if (shape == 5)
	{
		if (is_leftButton_down)
		{
			is_leftButton_down = false;
			::SetCursor(arrow);
			CPen pen(pen_style, pen_weight, RGB(color_R, color_G, color_B));
			pDC->SelectObject(&pen);
			pDC->RoundRect(CRect(chosen_position, instant_position), CPoint(15, 15));
		}
	}
	if (shape == 7)
	{
		if (!Under_painting)
		{
			if (is_leftButton_down)
			{
				is_leftButton_down = false;
				a = instant_position.y - chosen_position.y;
			}
			Under_painting = true;
		}
		else if (Under_painting)
		{
			CClientDC dc(this);
			CPen pen(pen_style, pen_weight, RGB(color_R, color_G, color_B));
			CPen* pOldPen = (CPen*)dc.SelectObject(&pen);
			CBrush *OldBrush;
			OldBrush = (CBrush*)dc.SelectStockObject(NULL_BRUSH);
			dc.Ellipse(chosen_position.x - b, chosen_position.y - a, chosen_position.x + b, chosen_position.y + a);
			dc.SelectObject(OldBrush);

			::SetCursor(arrow);
			Under_painting = false;
		}
	}
	CView::OnLButtonUp(nFlags, point);
}

//画贝塞尔曲线
void CDrawView::DrawBezier(CPoint start, CPoint control_first, CPoint control_second, CPoint end)
{
	CPoint ppt[4];
	ppt[0] = start;
	ppt[1] = control_first;
	ppt[2] = control_second;
	ppt[3] = end;
	CClientDC dc(this);
	dc.SetROP2(R2_NOT);
	dc.PolyBezier(ppt, 4);
	/*dc.MoveTo(ppt[0]);
	dc.LineTo(ppt[1]);
	dc.MoveTo(ppt[2]);
	dc.LineTo(ppt[3]);*/
}






void CDrawView::OnFileSave()
{
	// TODO: 在此添加命令处理程序代码
	HWND hwnd = this->GetSafeHwnd();
	HDC hDC = ::GetWindowDC(hwnd);//获取DC      


	RECT rect;
	::GetWindowRect(hwnd, &rect);//获取屏幕大小     
	HDC hDCMem = ::CreateCompatibleDC(hDC);//创建兼容DC      

	HBITMAP hBitMap = ::CreateCompatibleBitmap(hDC, rect.right - rect.left, rect.bottom - rect.top);//创建兼容位图      
	HBITMAP hOldMap = (HBITMAP)::SelectObject(hDCMem, hBitMap);//将位图选入DC，并保存返回值      

	::BitBlt(hDCMem, 0, 0, rect.right - rect.left, rect.bottom - rect.top, hDC, 0, 0, SRCCOPY);//将屏幕DC的图象复制到内存DC中      

	CImage image;//需要#include <atlimage.h>     
	image.Attach(hBitMap);
	image.Save(_T("img.bmp"));//如果文件后缀为.bmp，则保存为为bmp格式     
	image.Detach();

	::SelectObject(hDCMem, hOldMap);//选入上次的返回值      

									//释放      
	::DeleteObject(hBitMap);
	::DeleteDC(hDCMem);
	::DeleteDC(hDC);
		// TODO: Add your command handler code here  
	//CClientDC dc(this); 
	//CDC   memDC;
	//CRect  rect; 
	//GetClientRect(rect); 
	//memDC.CreateCompatibleDC(&dc);
	//CBitmap bm;
	//int Width = rect.Width();
	//int Height = rect.Height();
	//bm.CreateCompatibleBitmap(&dc, Width, Height);
	//CBitmap*  pOld = memDC.SelectObject(&bm);
	//memDC.BitBlt(0, 0, Width, Height, &dc, 0, 0, SRCCOPY);
	//memDC.SelectObject(pOld);  BITMAP  btm;
	//bm.GetBitmap(&btm);
	//DWORD  size = btm.bmWidthBytes * btm.bmHeight;
	//LPSTR lpData = (LPSTR)GlobalAllocPtr(GPTR, size);
	//BITMAPFILEHEADER   bfh;  /////////////////////////////////////////////  BITMAPINFOHEADER  bih;  bih.biBitCount = btm.bmBitsPixel;  bih.biClrImportant = 0;  bih.biClrUsed = 0;  bih.biCompression = 0; 
	//bih.biHeight = btm.bmHeight;
	//bih.biPlanes = 1;
	//bih.biSize = sizeof(BITMAPINFOHEADER);
	//bih.biSizeImage = size;
	//bih.biWidth = btm.bmWidth;
	//bih.biXPelsPerMeter = 0;
	//bih.biYPelsPerMeter = 0;
	//GetDIBits(dc, bm, 0, bih.biHeight, lpData, (BITMAPINFO*)&bih, DIB_RGB_COLORS);
	////bm.GetBitmapBits(size,lpData);//此函数在处理5-5-5模式的16位色下会出现颜色混乱 
	//bfh.bfReserved1 = bfh.bfReserved2 = 0; 
	//bfh.bfType = ((WORD)('M' << 8) | 'B');
	//bfh.bfSize = 54 + size;
	//bfh.bfOffBits = 54;
	////CFileDialog dlg(false,_T("BMP"),_T("*.bmp"),OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,_T("*.bmp|*.bmp|*.*|*.*|")); 
	//CFileDialog dlg(false, _T("BMP"), _T("*.bmp"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,	"位图文件(*.bmp)|*.bmp|", NULL);
	//if (dlg.DoModal() != IDOK)
	//	return;
	//CString filename = dlg.GetFileName() + ".bmp"; //if (dlg.DoModal()!=IDOK)   //return;  CFile  bf; 
	//CString ss = dlg.GetPathName();
	//if (bf.Open(ss, CFile::modeCreate | CFile::modeWrite))
	//{
	//	bf.WriteHuge(&bfh, sizeof(BITMAPFILEHEADER));
	//	bf.WriteHuge(&bih, sizeof(BITMAPINFOHEADER));
	//	bf.WriteHuge(lpData, size); 
	//	bf.Close();
	//	AfxMessageBox("保存成功");
	//}
	//GlobalFreePtr(lpData);
}
