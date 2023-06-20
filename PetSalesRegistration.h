#pragma once

#include"C_InfoFile.h"
// PetSalesRegistration 对话框

class PetSalesRegistration : public CDialogEx
{
	DECLARE_DYNAMIC(PetSalesRegistration)

public:
	PetSalesRegistration(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~PetSalesRegistration();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void SetSalesRecord(SalesRecord salesRecord);
	CEdit s_EDIT1;
	CEdit s_EDIT2;
	CEdit s_EDIT3;
	CEdit s_EDIT4;
	CString str;
	SalesRecord salesRecord;
};
