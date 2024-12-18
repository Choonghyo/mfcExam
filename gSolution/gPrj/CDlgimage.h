﻿#pragma once
#include "afxdialogex.h"


// CDlgimage 대화 상자

#define MAX_POINT	1000
class CDlgimage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgimage)

public:
	CDlgimage(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgimage();

	CImage m_image;
	CWnd* m_pParent;
	int m_nDataCount = 0;
	CPoint m_ptData[MAX_POINT];


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CDlgimage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnUpParent();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();

private:
	void InitImage();
	void drawData(CDC* pDC);
};
 