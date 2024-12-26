// DialogImg.cpp: 구현 파일
//

#include "pch.h"
#include "SWHomework1.h"
#include "afxdialogex.h"
#include "DialogImg.h"
#include <cmath>
#include <windows.h>
#include <iostream>
using namespace std;


// CDialogImg 대화 상자

IMPLEMENT_DYNAMIC(CDialogImg, CDialogEx)

CDialogImg::CDialogImg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_IMG, pParent)
{

}

CDialogImg::~CDialogImg()
{
}

void CDialogImg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CDialogImg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	MoveWindow(0, 80, imgWidth, imgHeight);

	InitImage();
	return TRUE;
}

// Image 초기화
void CDialogImg::InitImage()
{
	img.Create(imgWidth, -imgHeight, imgBpp);

	if (imgBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < colorCnt; i++) rgb[i].rgbRed = rgb[i].rgbBlue = rgb[i].rgbGreen = i;
		img.SetColorTable(0, colorCnt, rgb);
	}
	fm = (unsigned char*)img.GetBits();

	ResetBackground();
}

// background 초기화
void CDialogImg::ResetBackground() {
	fm = (unsigned char*)img.GetBits();

	memset(fm, colorWhite, imgWidth * imgHeight);
}

// Draw 버튼 value 값 지정
void CDialogImg::SettingDrawValue(int x, int y)
{
	start = { x, y };
	cur = { x, y };
	radius = rand() % circleMaxSize;

	ResetBackground();
	DrawCircle(false);
	Invalidate();
}

// Action 버튼 value 값 지정
void CDialogImg::SettingActionValue(int x1, int y1, int x2, int y2)
{
	start = { x1, y1 };
	end = { x2, y2 };

	fm = (unsigned char*)img.GetBits();

	for (int i = 0; i < movement; i++) {
		if (cur.x == end.x && cur.y == end.y) break;

		DrawCircle();

		if (cur.x > end.x) cur.x -= speed;
		else if (cur.x < end.x) cur.x += speed;

		if (cur.y > end.y) cur.y -= speed;
		else if (cur.y < end.y) cur.y += speed;

		DrawCircle(false);

		UpdateDisplay();
		Invalidate(false);

		Sleep(10);
	}
}

// 이미지 저장
void CDialogImg::SaveImagePath(CString savePath)
{
	img.Save(savePath);
}

void CDialogImg::UpdateDisplay()
{
	CPaintDC dc(this);
	img.Draw(dc, 0, 0);
}

// 원 Draw
void CDialogImg::DrawCircle(bool isBackground)
{
	fm = (unsigned char*)img.GetBits();

	int nPitch = img.GetPitch();
	int color = isBackground == true ? colorWhite : colorGray;

	for (int j = cur.y - radius; j <= cur.y + radius; j++) {
		for (int i = cur.x - radius; i <= cur.x + radius; i++) {
			if (IsInCircle(i, j))
				fm[j * nPitch + i] = color;
		}
	}
}

// 원의 범위 확인
bool CDialogImg::IsInCircle(int x, int y) {
	bool bRet = false;

	double dX = x - (cur.x);
	double dY = y - (cur.y);
	double dDist = dX * dX + dY * dY;

	if (radius * radius > dDist) bRet = true;

	return bRet;
}

// 이미지 Load
void CDialogImg::LoadResultImage(CString imgPath)
{
	if (img) img.Destroy();
	img.Load(imgPath);

	if (FindCircleCenter()) isCenterDraw = true;
	else AfxMessageBox(_T("원이 없습니다."));

	Invalidate(false);
}

// 원 중심 여부
bool CDialogImg::FindCircleCenter()
{
	fm = (unsigned char*)img.GetBits();
	int pitch = img.GetPitch();

	CPoint maxCoord = {MININT32, MININT32}, minCoord = {MAXINT32, MAXINT32};
	bool isFind = false;

	for (int j = 0; j < imgHeight; j++) {
		for (int i = 0; i < imgWidth; i++) {
			if (fm[j * pitch + i] != colorGray) continue;
			maxCoord = { max(maxCoord.x, i), max(maxCoord.y, j) };
			minCoord = { min(minCoord.x, i), min(minCoord.y, j) };
			isFind = true;
		}
	}

	if (isFind) {
		cur = { (maxCoord.x + minCoord.x) / 2, (maxCoord.y + minCoord.y) / 2 };
		radius = (maxCoord.x - minCoord.x) / 2;
	}
	return isFind;
}

// X 및 좌표 표시
void CDialogImg::DrawCenter(CDC *pDC)
{
	if (!isCenterDraw) return;
	cout << cur.x << ' ' << cur.y << "\n";

	CRect rect, textRect;

	rect.SetRect({ cur.x - 10, cur.y - 10 }, { cur.x + 10, cur.y + 10 }); 
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(COLOR_RED);
	pDC->DrawText(_T("X"), &rect, (DT_CENTER | DT_VCENTER | DT_SINGLELINE));

	CString str;
	str.Format(_T("[%d, %d]"), cur.x, cur.y);
	textRect.SetRect({ cur.x + 8, cur.y + 8 }, { cur.x + 80, cur.y + 80 });
	pDC->SetTextColor(COLOR_BLACK);
	pDC->DrawText(str, &textRect, (DT_LEFT | DT_SINGLELINE));

	isCenterDraw = false;
}

BEGIN_MESSAGE_MAP(CDialogImg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDialogImg 메시지 처리기
void CDialogImg::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	if (img) img.Draw(dc, 0, 0);
	DrawCenter(&dc);
}

int CDialogImg::GetCircleMaxSize()
{
	return circleMaxSize;
}

int CDialogImg::GetImageWidth()
{
	return imgWidth;
}

int CDialogImg::GetImageHeight()
{
	return imgHeight;
}