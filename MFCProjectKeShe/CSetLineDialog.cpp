// CSetLineDialog.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCProjectKeShe.h"
#include "CSetLineDialog.h"
#include "afxdialogex.h"


// CSetLineDialog 对话框

IMPLEMENT_DYNAMIC(CSetLineDialog, CDialog)

CSetLineDialog::CSetLineDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
	, m_LineSize(0)
{

}

CSetLineDialog::~CSetLineDialog()
{
}

void CSetLineDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_LineSize);
}


BEGIN_MESSAGE_MAP(CSetLineDialog, CDialog)
END_MESSAGE_MAP()


// CSetLineDialog 消息处理程序
