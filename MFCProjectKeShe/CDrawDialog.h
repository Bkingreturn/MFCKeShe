#pragma once


// CDrawDialog 对话框

class CDrawDialog : public CDialog
{
	DECLARE_DYNAMIC(CDrawDialog)

public:
	CDrawDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDrawDialog();

// 对话框数据

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_x;
	int m_y;
	// 图形尺寸
	int m_size;
};
