// Cpen.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Draw.h"
#include "Cpen.h"
#include "afxdialogex.h"

// Cpen �Ի���

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


// Cpen ��Ϣ�������


void Cpen::OnBnClickedButtonColor()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// TODO: Add your control notification handler code here   
	COLORREF color = RGB(255, 0, 0);      // ��ɫ�Ի���ĳ�ʼ��ɫΪ��ɫ  
	CColorDialog colorDlg(color);         // ������ɫ�Ի��򣬴����ʼ��ɫֵ   

	if (IDOK == colorDlg.DoModal())       // ��ʾ��ɫ�Ի��򣬲��ж��Ƿ����ˡ�ȷ����   
	{
		color = colorDlg.GetColor();      // ��ȡ��ɫ�Ի�����ѡ�����ɫֵ   
		color_R = GetRValue(color);
		color_G = GetGValue(color);
		color_B = GetBValue(color);
	}
}


void Cpen::OnCbnSelchangeComboThickness()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int pos_pen_weight = m_pen_weight.GetCurSel() + 1;
	pen_weight = pos_pen_weight;

}


void Cpen::OnCbnSelchangePenStyle()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	shape = 1;
}



void Cpen::OnBnClickedCurveBight()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	shape = 2;
}



void Cpen::OnBnClickedRectangle()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	shape = 3;
}

void Cpen::OnBnClickedCircle()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	shape = 4;
}

void Cpen::OnBnClickedCircularBead()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	shape = 5;
}

//void Cpen::OnBnClickedRadio5()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	shape = 6;
//}


void Cpen::OnBnClickedEllipse()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	shape = 7;
}







