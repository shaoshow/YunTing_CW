#pragma once
#include"C_InfoFile.h"

// PetMedicalRecordRegistration 对话框

class PetMedicalRecordRegistration : public CDialogEx
{
	DECLARE_DYNAMIC(PetMedicalRecordRegistration)

public:
	PetMedicalRecordRegistration(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~PetMedicalRecordRegistration();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void SetMedicalRecord(MedicalRecord medicalRecord);
	CEdit m_EDIT1;
	CEdit m_EDIT2;
	CEdit m_EDIT3;
	CEdit m_EDIT4;
	CEdit m_EDIT5; CString str;
	MedicalRecord medicalRecord;
};
