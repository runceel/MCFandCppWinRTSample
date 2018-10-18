
// WinRTMFCAppView.cpp : CWinRTMFCAppView クラスの実装
//

#include "stdafx.h"
// SHARED_HANDLERS は、プレビュー、縮小版、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "WinRTMFCApp.h"
#endif

#include "WinRTMFCAppDoc.h"
#include "WinRTMFCAppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWinRTMFCAppView

IMPLEMENT_DYNCREATE(CWinRTMFCAppView, CView)

BEGIN_MESSAGE_MAP(CWinRTMFCAppView, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CWinRTMFCAppView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CWinRTMFCAppView コンストラクション/デストラクション

CWinRTMFCAppView::CWinRTMFCAppView() noexcept
{
	// TODO: 構築コードをここに追加します。

}

CWinRTMFCAppView::~CWinRTMFCAppView()
{
}

BOOL CWinRTMFCAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CWinRTMFCAppView 描画

void CWinRTMFCAppView::OnDraw(CDC* /*pDC*/)
{
	CWinRTMFCAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}


// CWinRTMFCAppView の印刷


void CWinRTMFCAppView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CWinRTMFCAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CWinRTMFCAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CWinRTMFCAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}

void CWinRTMFCAppView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CWinRTMFCAppView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CWinRTMFCAppView の診断

#ifdef _DEBUG
void CWinRTMFCAppView::AssertValid() const
{
	CView::AssertValid();
}

void CWinRTMFCAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWinRTMFCAppDoc* CWinRTMFCAppView::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinRTMFCAppDoc)));
	return (CWinRTMFCAppDoc*)m_pDocument;
}
#endif //_DEBUG


// CWinRTMFCAppView メッセージ ハンドラー
