
// MFCProjectKeSheView.h: CMFCProjectKeSheView 类的接口
//

#pragma once


class CMFCProjectKeSheView : public CView
{
protected: // 仅从序列化创建
	CMFCProjectKeSheView();
	DECLARE_DYNCREATE(CMFCProjectKeSheView)

// 特性
public:
	CMFCProjectKeSheDoc* GetDocument() const;
	int m_nSign;
	int x;
	int y;
	int size;
	int numquad; //调色板数 
	int flagOpen; //标志是否打开bmp 
	BITMAPINFO* pbi; //记录图像细节 
	BYTE* lpbuf; //图像数据 
	RGBQUAD* quad; //调色板 
	BITMAPFILEHEADER bf;//文件头 
	BITMAPINFOHEADER bi; //信息头 
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
	virtual ~CMFCProjectKeSheView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnYuan();
	afx_msg void OnTuoyuan();
	afx_msg void OnJuxing();
	afx_msg void OnShanxing();
	afx_msg void OnZhixian();
	afx_msg void OnXiankuan();
	afx_msg void OnYanse();
	afx_msg void OnTianchong();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnFileSave();
};

#ifndef _DEBUG  // MFCProjectKeSheView.cpp 中的调试版本
inline CMFCProjectKeSheDoc* CMFCProjectKeSheView::GetDocument() const
   { return reinterpret_cast<CMFCProjectKeSheDoc*>(m_pDocument); }
#endif

