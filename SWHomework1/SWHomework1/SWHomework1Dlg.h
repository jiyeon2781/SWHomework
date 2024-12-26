
// SWHomework1Dlg.h: 헤더 파일
//

#pragma once
#include "DialogImg.h"


// CSWHomework1Dlg 대화 상자
class CSWHomework1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CSWHomework1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	CDialogImg* dialogImg;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SWHOMEWORK1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	int mainWidth = 800;
	int mainHeight = 700;

	int x1Num, y1Num, x2Num, y2Num;

public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnDraw();
	afx_msg void OnBnClickedBtnAction();
	afx_msg void OnBnClickedBtnOpen();
	CString GetExecPath();

	void SettingCoordinates();
	bool IsInMapSize();
};
