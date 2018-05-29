
// MFCProjectKeSheView.cpp: CMFCProjectKeSheView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCProjectKeShe.h"
#endif

#include "MFCProjectKeSheDoc.h"
#include "MFCProjectKeSheView.h"
#include "CDrawDialog.h"
#include "CSetLineDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCProjectKeSheView

IMPLEMENT_DYNCREATE(CMFCProjectKeSheView, CView)

BEGIN_MESSAGE_MAP(CMFCProjectKeSheView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_YUAN, &CMFCProjectKeSheView::OnYuan)
	ON_COMMAND(ID_TUOYUAN, &CMFCProjectKeSheView::OnTuoyuan)
	ON_COMMAND(ID_JUXING, &CMFCProjectKeSheView::OnJuxing)
	ON_COMMAND(ID_SHANXING, &CMFCProjectKeSheView::OnShanxing)
	ON_COMMAND(ID_ZHIXIAN, &CMFCProjectKeSheView::OnZhixian)
	ON_COMMAND(ID_XIANKUAN, &CMFCProjectKeSheView::OnXiankuan)
	ON_COMMAND(ID_YANSE, &CMFCProjectKeSheView::OnYanse)
	ON_COMMAND(ID_TIANCHONG, &CMFCProjectKeSheView::OnTianchong)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCProjectKeSheView 构造/析构

CMFCProjectKeSheView::CMFCProjectKeSheView()
{
	// TODO: 在此处添加构造代码
}

CMFCProjectKeSheView::~CMFCProjectKeSheView()
{
}

BOOL CMFCProjectKeSheView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCProjectKeSheView 绘图

void CMFCProjectKeSheView::OnDraw(CDC* pDC)
{
	CPen newPen, *oldPen;
	CBrush newBrush, *oldBrush;
	CMFCProjectKeSheDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
	switch (m_nSign)
	{
	case 1:
		newPen.CreatePen(PS_SOLID, pDoc->lineSize, pDoc->color);
		oldPen = pDC->SelectObject(&newPen);
		newBrush.CreateSolidBrush(pDoc->m_colorRuond);
		oldBrush = pDC->SelectObject(&newBrush);
		pDC->Ellipse(x, y, size, size);
		pDC->SelectObject(oldPen);
		pDC->SelectObject(oldBrush);
		break;
	case 2:
		int t;
		t= size - 5;
		newPen.CreatePen(PS_SOLID, pDoc->lineSize, pDoc->color);
		oldPen = pDC->SelectObject(&newPen);
		newBrush.CreateSolidBrush(pDoc->m_colorRuond);
		oldBrush = pDC->SelectObject(&newBrush);
		pDC->Ellipse(x, y, size,t);
		pDC->SelectObject(oldPen);
		pDC->SelectObject(oldBrush);
		break;
	case 3:
		newPen.CreatePen(PS_SOLID, pDoc->lineSize, pDoc->color);
		oldPen = pDC->SelectObject(&newPen);
		newBrush.CreateSolidBrush(pDoc->m_colorRuond);
		oldBrush = pDC->SelectObject(&newBrush);
		pDC->Rectangle(x, y, size, size);
		pDC->SelectObject(oldPen);
		pDC->SelectObject(oldBrush);
		break;
	case 4:
		
		break;
	case 5:
		newPen.CreatePen(PS_SOLID, pDoc->lineSize, pDoc->color);
		oldPen = pDC->SelectObject(&newPen);
		newBrush.CreateSolidBrush(pDoc->m_colorRuond);
		oldBrush = pDC->SelectObject(&newBrush);
		pDC->MoveTo(size, size);
		pDC->LineTo(x, y);
		pDC->SelectObject(oldPen);
		pDC->SelectObject(oldBrush);
		break;
	default:
		break;
	}
	
	
}


// CMFCProjectKeSheView 打印

BOOL CMFCProjectKeSheView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCProjectKeSheView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCProjectKeSheView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCProjectKeSheView 诊断

#ifdef _DEBUG
void CMFCProjectKeSheView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCProjectKeSheView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCProjectKeSheDoc* CMFCProjectKeSheView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCProjectKeSheDoc)));
	return (CMFCProjectKeSheDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCProjectKeSheView 消息处理程序


void CMFCProjectKeSheView::OnYuan()
{
	// TODO: 在此添加命令处理程序代码
	m_nSign = 1;
	CDrawDialog dlg;
	int result = dlg.DoModal();
	if (result == IDOK) {
		x = dlg.m_x;
		y = dlg.m_y;
		size = dlg.m_size;
		Invalidate();
	}
	InvalidateRect(NULL, TRUE);
}


void CMFCProjectKeSheView::OnTuoyuan()
{
	// TODO: 在此添加命令处理程序代码
	m_nSign = 2;
	CDrawDialog dlg;
	int result = dlg.DoModal();
	if (result == IDOK) {
		x = dlg.m_x;
		y = dlg.m_y;
		size = dlg.m_size;
		Invalidate();
	}
	InvalidateRect(NULL, TRUE);
}


void CMFCProjectKeSheView::OnJuxing()
{
	// TODO: 在此添加命令处理程序代码
	m_nSign = 3;
	CDrawDialog dlg;
	int result = dlg.DoModal();
	if (result == IDOK) {
		x = dlg.m_x;
		y = dlg.m_y;
		size = dlg.m_size;
		Invalidate();
	}
	InvalidateRect(NULL, TRUE);
}


void CMFCProjectKeSheView::OnShanxing()
{
	// TODO: 在此添加命令处理程序代码
	m_nSign = 4;
	CDrawDialog dlg;
	int result = dlg.DoModal();
	if (result == IDOK) {
		x = dlg.m_x;
		y = dlg.m_y;
		size = dlg.m_size;
		Invalidate();
	}
	InvalidateRect(NULL, TRUE);
}


void CMFCProjectKeSheView::OnZhixian()
{
	// TODO: 在此添加命令处理程序代码
	m_nSign = 5;
	CDrawDialog dlg;
	int result = dlg.DoModal();
	if (result == IDOK) {
		x = dlg.m_x;
		y = dlg.m_y;
		size = dlg.m_size;
		Invalidate();
	}
	InvalidateRect(NULL, TRUE);
}


void CMFCProjectKeSheView::OnXiankuan()
{
	// TODO: 在此添加命令处理程序代码
	CMFCProjectKeSheDoc* pDoc = GetDocument();
	CSetLineDialog dlg;
	int result = dlg.DoModal();
	if (result == IDOK) {
		pDoc->lineSize = dlg.m_LineSize;
		Invalidate();
	}
	InvalidateRect(NULL);
}


void CMFCProjectKeSheView::OnYanse()
{
	// TODO: 在此添加命令处理程序代码
	CMFCProjectKeSheDoc* pDoc = GetDocument();
	CColorDialog dlg(pDoc->color);
	if (dlg.DoModal() == IDOK)
		pDoc->color = dlg.GetColor();
	InvalidateRect(NULL);
}


void CMFCProjectKeSheView::OnTianchong()
{
	// TODO: 在此添加命令处理程序代码
	CMFCProjectKeSheDoc* pDoc = GetDocument();
	CColorDialog dlg(pDoc->m_colorRuond);
	if (dlg.DoModal() == IDOK)
		pDoc->m_colorRuond = dlg.GetColor();
	InvalidateRect(NULL);
}


void CMFCProjectKeSheView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nFlags&&MK_SHIFT)
	{
		CClientDC a(this);
		a.SetPixel(point.x, point.y, RGB(255, 255, 255));
	}
	CView::OnMouseMove(nFlags, point);
}
