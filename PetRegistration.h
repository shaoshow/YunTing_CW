#pragma once
#include"C_InfoFile.h"

// PetRegistration 对话框

class PetRegistration : public CDialogEx
{
	DECLARE_DYNAMIC(PetRegistration)

public:
	PetRegistration(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~PetRegistration();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void  SetPet(Pet pet);
	CEdit p_EDIT1;
	CEdit p_EDIT2;
	CEdit p_EDIT3;
	CEdit p_EDIT4;
	CEdit p_EDIT5; CString str;
	Pet pet;
};
