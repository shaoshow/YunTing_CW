#pragma once
// JiLu 对话框
#include"C_InfoFile.h"
class JiLu : public CDialogEx
{
	DECLARE_DYNAMIC(JiLu)

public:
	JiLu(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~JiLu();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void SetMember(Member member);
	CEdit m_EDIT1;
	CEdit m_EDIT2;
	CEdit m_EDIT3;
	CEdit m_EDIT4; CString str;
	Member member;
};
