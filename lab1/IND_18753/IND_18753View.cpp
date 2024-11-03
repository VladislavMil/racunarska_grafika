
// IND_18753View.cpp : implementation of the CIND18753View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "IND_18753.h"
#endif

#include "IND_18753Doc.h"
#include "IND_18753View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIND18753View

IMPLEMENT_DYNCREATE(CIND18753View, CView)

BEGIN_MESSAGE_MAP(CIND18753View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CIND18753View construction/destruction

CIND18753View::CIND18753View() noexcept
{
	// TODO: add construction code here

}

CIND18753View::~CIND18753View()
{
}

BOOL CIND18753View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CIND18753View drawing

void DrawRegularPolygon(CDC* pDC, int cx, int cy, int r, int n, float rotAngle)
{
	if (n < 3) return;

	float angleOffset = rotAngle * 3.14 / 180.0f;

	CPoint* points = new CPoint[n];

	float angleIncrement = 2 * 3.14 / n;

	for (int i = 0; i < n; i++)
	{
		float alfa = i * angleIncrement + angleOffset;
		points[i].x = cx + r * cos(alfa);
		points[i].y = cy - r * sin(alfa);
	}

	pDC->Polygon(points, n);

	delete[] points;
}

void DrawGrid(CDC* pDC, int cellSize) {

	CPen pen(PS_SOLID, 1, RGB(255, 255, 255));
	CPen* pOldPen = pDC->SelectObject(&pen);

	for (int x = 0; x <= 500; x += cellSize) {
		pDC->MoveTo(x, 0);
		pDC->LineTo(x, 500);
	}
	for (int y = 0; y <= 500; y += cellSize) {
		pDC->MoveTo(0, y);
		pDC->LineTo(500, y);
	}

	pDC->SelectObject(pOldPen);
}

void CIND18753View::OnDraw(CDC* pDC)
{
	CIND18753Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	
	CBrush* gray = new CBrush(RGB(221, 221, 221));
	CPen* Grid = new CPen(PS_SOLID, 1, RGB(221, 221, 221));
	CBrush* oldBrush = pDC->SelectObject(gray);
	pDC->Rectangle(0, 0, 500, 500);

	CPen olovka(PS_SOLID, 5, RGB(0, 0, 255));
	CPen* oldPen = pDC->SelectObject(&olovka);

	//Zuti trougao
	CBrush cetkaZuti(RGB(255, 255, 0));
	pDC->SelectObject(&cetkaZuti);
	POINT pts2[3] = { {163, 250}, {313, 250}, {313, 100} };
	pDC->Polygon(pts2, 3);

	//Beli trougao
	CBrush cetkaLinije(HS_BDIAGONAL, RGB(0, 150, 255));
	pDC->SelectObject(&cetkaLinije);
	POINT pts1[3] = { {163, 250}, {313, 250}, {313, 400} };
	pDC->Polygon(pts1, 3);

	//Zeleni paralelogram
	CBrush cetkaZeleni(RGB(0, 255, 0));
	pDC->SelectObject(&cetkaZeleni);
	POINT pts4[4] = { {313, 100}, {313, 175}, {388, 100}, {388, 25} };
	pDC->Polygon(pts4, 4);

	//Crveni trougao
	CBrush cetkaCrveni(RGB(255, 0, 0));
	pDC->SelectObject(&cetkaCrveni);
	POINT pts3[3] = { {313, 175}, {388, 250}, {388, 100} };
	pDC->Polygon(pts3, 3);

	//Ljubicasti trougao
	CBrush cetkaLjubicasti(RGB(255, 0, 255));
	pDC->SelectObject(&cetkaLjubicasti);
	POINT pts5[3] = { {313, 325}, {388, 250}, {388, 325} };
	pDC->Polygon(pts5, 3);

	//Roze kvadrat
	CBrush cetkaRoze(RGB(255, 150, 150));
	pDC->SelectObject(&cetkaRoze);
	pDC->Rectangle(313, 325, 388, 400);

	//Narandzasti trougao
	CBrush cetkaNarandzasti(RGB(255, 150, 0));
	pDC->SelectObject(&cetkaNarandzasti);
	POINT pts6[3] = { {313, 400}, {388, 475}, {388, 400} };
	pDC->Polygon(pts6, 3);

	olovka.DeleteObject();
	CPen newOlovka(PS_SOLID, 4, RGB(0, 0, 255));
	pDC->SelectObject(&newOlovka);

	//Unutar zutog trougla
	pDC->SelectObject(&cetkaZuti);
	DrawRegularPolygon(pDC, 270, 205, 25, 5, 0);
	cetkaZuti.DeleteObject();

	//Unutar belog trougla
	pDC->SelectObject(&cetkaLinije);
	DrawRegularPolygon(pDC, 270, 300, 25, 4, 90);
	cetkaLinije.DeleteObject();

	//Unutar crvenog trougla
	pDC->SelectObject(&cetkaCrveni);
	DrawRegularPolygon(pDC, 355, 175, 20, 6, 0);
	cetkaCrveni.DeleteObject();

	//Unutar ljubicastor trougla
	pDC->SelectObject(&cetkaLjubicasti);
	DrawRegularPolygon(pDC, 365, 305, 15, 7, 0);
	cetkaLjubicasti.DeleteObject();

	//Unutar narandzastog trougla
	pDC->SelectObject(&cetkaNarandzasti);
	DrawRegularPolygon(pDC, 365, 423, 15, 8, 0);
	cetkaNarandzasti.DeleteObject();
}


// CIND18753View printing

BOOL CIND18753View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CIND18753View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CIND18753View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CIND18753View diagnostics

#ifdef _DEBUG
void CIND18753View::AssertValid() const
{
	CView::AssertValid();
}

void CIND18753View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIND18753Doc* CIND18753View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIND18753Doc)));
	return (CIND18753Doc*)m_pDocument;
}
#endif //_DEBUG


// CIND18753View message handlers


void CIND18753View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CDC* pDC = GetDC();

	if (pDC != nullptr) {

		DrawGrid(pDC, 25);
		ReleaseDC(pDC);
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
