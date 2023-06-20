#pragma once
#include"C_InfoFile.h"
// boardingAlightingPossibility 对话框

class boardingAlightingPossibility : public CDialogEx
{
	DECLARE_DYNAMIC(boardingAlightingPossibility)

public:
	boardingAlightingPossibility(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~boardingAlightingPossibility();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void SetBoarding(Boarding boarding);
	CEdit p_EDIT1;
	CEdit p_EDIT2;
	CEdit p_EDIT3;
	CEdit p_EDIT4;
	CEdit p_EDIT5; CString str;
	Boarding boarding ;
};
