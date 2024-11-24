// CDlgimage.cpp: 구현 파일
//

#include "pch.h"
#include "gPrj.h"
#include "afxdialogex.h"
#include "CDlgimage.h"


// CDlgimage 대화 상자

IMPLEMENT_DYNAMIC(CDlgimage, CDialogEx)

CDlgimage::CDlgimage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CDlgimage, pParent)
{
	m_pParent = pParent;
}

CDlgimage::~CDlgimage()
{
}

void CDlgimage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgimage, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_UP_PARENT, &CDlgimage::OnBnClickedBtnUpParent)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgimage 메시지 처리기


#include "gPrjDlg.h"
void CDlgimage::OnBnClickedBtnUpParent()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	static int n = 100;
	
	CgPrjDlg* pDlg = (CgPrjDlg*)m_pParent;
	pDlg->callFunc(n++);
}


BOOL CDlgimage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	MoveWindow(0, 0, 640, 480);
	
	InitImage();
	
	    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}



void CDlgimage::InitImage()
{
	int nWidth = 640;
	int nHeigth = 480;
	int nBpp = 8;

	m_image.Create(nWidth, -nHeigth, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0;i < 256;i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}
	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, nWidth * nHeigth);

}


void CDlgimage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	if (m_image)
		m_image.Draw(dc, 0, 0);

	drawData(&dc);
}

void CDlgimage::drawData(CDC* pDC)
{
	CRect rect;
	CPen pen;
	pen.CreatePen(PS_SOLID, 5, RGB(0xff, 0, 0));
	CPen* pOldPen = pDC->SelectObject(&pen);

	for (int i = 0; i < m_nDataCount; i++) {
		rect.SetRect(m_ptData[i], m_ptData[i]);
		rect.InflateRect(2,2);
		pDC->Ellipse(rect);
	}
	pDC->SelectObject(pOldPen);
}