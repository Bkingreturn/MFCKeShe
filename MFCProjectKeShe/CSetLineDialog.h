#pragma once


// CSetLineDialog 对话框

class CSetLineDialog : public CDialog
{
	DECLARE_DYNAMIC(CSetLineDialog)

public:
	CSetLineDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSetLineDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 设置线宽
	int m_LineSize;
};
