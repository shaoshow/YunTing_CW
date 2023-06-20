#pragma once


// CW 对话框

class CW : public CDialogEx
{
	DECLARE_DYNAMIC(CW)

public:
	CW(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CW();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit CW_01;
	afx_msg void OnBnClickedOk26();
	CListCtrl m_List;
	afx_msg void OnBnClickedOk29();
	afx_msg void OnBnClickedOk27();
	afx_msg void OnBnClickedOk28();
	afx_msg void OnBnClickedOk30();
	afx_msg void OnBnClickedOk31();
	afx_msg void OnBnClickedOk5();
	afx_msg void OnBnClickedOk3();
	afx_msg void OnBnClickedOk2();
	CEdit P_id;
	CEdit zhongko;
	afx_msg void OnBnClickedOk6();
	afx_msg void OnBnClickedOk10();
	afx_msg void OnBnClickedOk14();
	afx_msg void OnBnClickedOk18();
	afx_msg void OnBnClickedOk22();
	CEdit M_id;
	CEdit B_id;
	CEdit G_id;
	CEdit MR_id;
	CEdit S_id;
	afx_msg void OnBnClickedOk7();
	afx_msg void OnBnClickedOk11();
	afx_msg void OnBnClickedOk15();
	afx_msg void OnBnClickedOk19();
	afx_msg void OnBnClickedOk23();
	afx_msg void OnBnClickedOk8();
	afx_msg void OnBnClickedOk12();
	afx_msg void OnBnClickedOk16();
	afx_msg void OnBnClickedOk20();
	afx_msg void OnBnClickedOk24();
	afx_msg void OnBnClickedOk4();
	afx_msg void OnBnClickedOk9();
	afx_msg void OnBnClickedOk13();
	afx_msg void OnBnClickedOk17();
	afx_msg void OnBnClickedOk21();
	afx_msg void OnBnClickedOk25();
	afx_msg void OnBnClickedOk32();
};
