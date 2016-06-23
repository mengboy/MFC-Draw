// Cpen.cpp : 实现文件
//

#include "stdafx.h"
#include "Draw.h"
#include "Cpen.h"
#include "afxdialogex.h"

// Cpen 对话框

IMPLEMENT_DYNAMIC(Cpen, CDialogEx)

Cpen::Cpen(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_PEN_STYLE, pParent)
{

}

Cpen::~Cpen()
{
}

void Cpen::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_THICKNESS, m_pen_weight);
	DDX_Control(pDX, IDD_PEN_STYLE, m_pen_style);
}


BEGIN_MESSAGE_MAP(Cpen, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_COLOR, &Cpen::OnBnClickedButtonColor)
	ON_CBN_SELCHANGE(IDC_COMBO_THICKNESS, &Cpen::OnCbnSelchangeComboThickness)
	ON_CBN_SELCHANGE(IDD_PEN_STYLE, &Cpen::OnCbnSelchangePenStyle)
	ON_BN_CLICKED(IDC_STRAIGHT_LINE, &Cpen::OnBnClickedStraightLine)
	ON_BN_CLICKED(IDC_CURVE_BIGHT, &Cpen::OnBnClickedCurveBight)
	ON_BN_CLICKED(IDC_RECTANGLE, &Cpen::OnBnClickedRectangle)
	ON_BN_CLICKED(IDC_ELLIPSE, &Cpen::OnBnClickedEllipse)
	ON_BN_CLICKED(IDC_CIRCULAR_BEAD, &Cpen::OnBnClickedCircularBead)
	ON_BN_CLICKED(IDC_CIRCLE, &Cpen::OnBnClickedCircle)
//	ON_BN_CLICKED(IDC_RADIO5, &Cpen::OnBnClickedRadio5)
END_MESSAGE_MAP()


// Cpen 消息处理程序


void Cpen::OnBnClickedButtonColor()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: Add your control notification handler code here   
	COLORREF color = RGB(255, 0, 0);      // 颜色对话框的初始颜色为红色  
	CColorDialog colorDlg(color);         // 构造颜色对话框，传入初始颜色值   

	if (IDOK == colorDlg.DoModal())       // 显示颜色对话框，并判断是否点击了“确定”   
	{
		color = colorDlg.GetColor();      // 获取颜色对话框中选择的颜色值   
		color_R = GetRValue(color);
		color_G = GetGValue(color);
		color_B = GetBValue(color);
	}
}


void Cpen::OnCbnSelchangeComboThickness()
{
	// TODO: 在此添加控件通知处理程序代码
	int pos_pen_weight = m_pen_weight.GetCurSel() + 1;
	pen_weight = pos_pen_weight;

}


void Cpen::OnCbnSelchangePenStyle()
{
	// TODO: 在此添加控件通知处理程序代码
	int pos_pen_styel = m_pen_style.GetCurSel();
	if (pos_pen_styel == 0)
	{
		pen_style = 2;
	}
	else if (pos_pen_styel == 1)
	{
		pen_style = 0;
	}
	else if (pos_pen_styel == 2)
	{
		pen_style = 1;
	}
	else if (pos_pen_styel == 3)
	{
		pen_style = 4;
	}
	else if (pos_pen_styel == 4)
	{
		pen_style = 3;
	}
	
}


void Cpen::OnBnClickedStraightLine()
{
	// TODO: 在此添加控件通知处理程序代码
	shape = 1;
}



void Cpen::OnBnClickedCurveBight()
{
	// TODO: 在此添加控件通知处理程序代码
	shape = 2;
}



void Cpen::OnBnClickedRectangle()
{
	// TODO: 在此添加控件通知处理程序代码
	shape = 3;
}

void Cpen::OnBnClickedCircle()
{
	// TODO: 在此添加控件通知处理程序代码
	shape = 4;
}

void Cpen::OnBnClickedCircularBead()
{
	// TODO: 在此添加控件通知处理程序代码
	shape = 5;
}

//void Cpen::OnBnClickedRadio5()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	shape = 6;
//}


void Cpen::OnBnClickedEllipse()
{
	// TODO: 在此添加控件通知处理程序代码
	shape = 7;
}







