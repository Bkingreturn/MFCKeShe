// CDrawDialog.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCProjectKeShe.h"
#include "CDrawDialog.h"
#include "afxdialogex.h"


// CDrawDialog 对话框

IMPLEMENT_DYNAMIC(CDrawDialog, CDialog)

CDrawDialog::CDrawDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_x(0)
	, m_y(0)
	, m_size(0)
{

}

CDrawDialog::~CDrawDialog()
{
}

void CDrawDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_x);
	DDX_Text(pDX, IDC_EDIT2, m_y);
	DDX_Text(pDX, IDC_EDIT3, m_size);
}


BEGIN_MESSAGE_MAP(CDrawDialog, CDialog)
END_MESSAGE_MAP()


// CDrawDialog 消息处理程序



