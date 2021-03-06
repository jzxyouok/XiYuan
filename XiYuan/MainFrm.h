// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。  
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。  
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问  
// http://go.microsoft.com/fwlink/?LinkId=238214。
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// MainFrm.h : CMainFrame 类的接口
//

#pragma once
#include "FileView.h"
#include "ClassView.h"
#include "XiYuanStatusBar.h"
#include "DownloadManager.h"

class CMainFrame : public CMDIFrameWndEx, public IDownloadProgress
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:  // 控件条嵌入成员
	CMFCRibbonBar     m_wndRibbonBar;
	CMFCRibbonApplicationButton m_MainButton;
	CMFCToolBarImages m_PanelImages;
	CXiYuanStatusBar  m_wndStatusBar;
	CFileView         m_wndFileView;
	CClassView        m_wndClassView;
	CMFCCaptionBar    m_wndCaptionBar;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnWindowManager();
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	afx_msg void OnViewCaptionBar();
	afx_msg void OnUpdateViewCaptionBar(CCmdUI* pCmdUI);
	afx_msg void OnOptions();
	LRESULT OnMovieDownloadProgress(WPARAM wParam, LPARAM lParam);
	LRESULT OnMovieDownloadStart(WPARAM wParam, LPARAM lParam);
	LRESULT OnMovieDownloadEnd(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

	BOOL CreateDockingWindows();
	void SetDockingWindowIcons(BOOL bHiColorIcons);
	BOOL CreateCaptionBar();
public:
	afx_msg void OnButtonHomepage();
	afx_msg void OnButtonMovie();
	afx_msg void OnButtonAnimation();
	afx_msg void OnButtonTeleplay();
	afx_msg void OnButtonScience();
	afx_msg void OnButtonVariety();
	afx_msg void OnButtonSport();
	afx_msg void OnUpdateEditSearch(CCmdUI *pCmdUI);
	
	
	CString m_search;
	int lastProgress;
	afx_msg void OnButtonSearch();
	afx_msg void OnEditSearch();
	afx_msg void OnButtonQrcode();

	// IDownloadProgress
public:
	virtual void OnDownloadStart(DownloadTaskParams * params);
	virtual void OnDownloadProgress(DownloadTaskParams * params);
	virtual void OnDownloadError(DownloadTaskParams * params, HRESULT hr);
	virtual void OnDownloadCompleted(DownloadTaskParams * params);

public:
	
	afx_msg void OnButton10();
};
BYTE* GenerateBarCode(const char *_pStrInfo, int *_pWidth, int *_pHeight);
bool SaveBmp(char*bmpName, unsigned char*imgBuf, int width, int height, int biBitCount, RGBQUAD *pColorTable);

