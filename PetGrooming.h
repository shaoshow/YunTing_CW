#pragma once
#include"C_InfoFile.h"

// PetGrooming 对话框

class PetGrooming : public CDialogEx
{
	DECLARE_DYNAMIC(PetGrooming)

public:
	PetGrooming(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~PetGrooming();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void SetGrooming(Grooming grooming);
	CEdit g_EDIT1;
	CEdit g_EDIT2;
	CEdit g_EDIT3;
	CEdit g_EDIT4; CString str;
	Grooming grooming;
};
