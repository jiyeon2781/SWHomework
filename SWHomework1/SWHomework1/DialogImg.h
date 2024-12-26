#pragma once
#include "afxdialogex.h"

// CDialogImg 대화 상자

class CDialogImg : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogImg)

public:
	CDialogImg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDialogImg();

private:
	CWnd* parentDlg;
	CImage img;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_IMG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	void InitImage();
	void SettingDrawValue(int x, int y);
	void SettingActionValue(int x1, int y1, int x2, int y2);
	void SaveImagePath(CString savePath);
	void UpdateDisplay();
	void ResetBackground();
	void LoadResultImage(CString imgPath);
	bool FindCircleCenter();
	void DrawCenter(CDC* pDC);
	void DrawCircle(bool isBackground = true);
	bool IsInCircle(int x, int y);

private:
	int imgWidth = 800;		// Image Width Size
	int imgHeight = 600;	// Image Height Size
	int imgBpp = 8;			// Image Bit
	int colorCnt = 256;		// Image Max Color Count
	int circleMaxSize = 50;	// Max Circle Size

	int speed = 1;			// Action : Move Speed
	int movement = 10;		// Action : Movement

	int colorGray = 140;	// Color : Gray
	int colorWhite = 255;	// Color : White

	CPoint start, end, cur;
	int radius;

	CString path;

	unsigned char* fm;

public:
	afx_msg void OnPaint();
	int GetCircleMaxSize();
	int GetImageWidth();
	int GetImageHeight();

	bool isCenterDraw = false;
};
