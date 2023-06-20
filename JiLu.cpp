// JiLu.cpp: 实现文件
//

#include "pch.h"
#include "YunTing_宠物店管理系统.h"
#include "JiLu.h"
#include "afxdialogex.h"
#include"C_InfoFile.h"

// JiLu 对话框

IMPLEMENT_DYNAMIC(JiLu, CDialogEx)

JiLu::JiLu(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

JiLu::~JiLu()
{
}

void JiLu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
	
	DDX_Control(pDX, IDC_EDIT7, m_EDIT1);
	DDX_Control(pDX, IDC_EDIT9, m_EDIT2);
	DDX_Control(pDX, IDC_EDIT8, m_EDIT3);
	DDX_Control(pDX, IDC_EDIT10, m_EDIT4);
	if (this->str == "更新")
	{
		m_EDIT1.SetWindowTextW((CString)to_string(this->member.member_id).c_str());
		m_EDIT1.SetReadOnly(TRUE);
		m_EDIT2.SetWindowTextW((CString)this->member.name.c_str());
		m_EDIT3.SetWindowTextW((CString)this->member.phone_num.c_str());
		m_EDIT4.SetWindowTextW((CString)this->member.address.c_str());
	}
}


BEGIN_MESSAGE_MAP(JiLu, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &JiLu::OnBnClickedButton1)
END_MESSAGE_MAP()


// JiLu 消息处理程序


void JiLu::OnBnClickedButton1()
{

	// TODO: 在此添加控件通知处理程序代码
	if (this->str == "更新")
	{
		Member metp;
		CString strText;
		m_EDIT1.GetWindowText(strText);
		string str = (LPCSTR)(CStringA)strText;
		metp.member_id = stoi(str);
		m_EDIT2.GetWindowText(strText);
		metp.name = (LPCSTR)(CStringA)strText;
		m_EDIT3.GetWindowText(strText);
		metp.phone_num = (LPCSTR)(CStringA)strText;
		m_EDIT4.GetWindowText(strText);
		metp.address = (LPCSTR)(CStringA)strText;
		C_InfoFile file;
		str = "UPDATE member SET name='" + metp.name +
			"', phone_num='" + metp.phone_num +
			"', address='" + metp.address +
			"' WHERE member_id = " + to_string(this->member.member_id);
		//MessageBox((CString)str.c_str());
		if (connect_db()) {
			//MessageBox(_T("数据库连接连接成功"));

			if (execute_sql(str)) {
				MessageBox(_T("更新成功"));
				close_db();
				CDialogEx::OnOK();//关闭当前界面窗口
			}
			else {
				MessageBox(_T("更新失败"));
			}
			//file.WriteMember(metp);

		}
		else {
			MessageBox(_T("数据库连接连接失败"));
		}
	}
	else {
		Member metp;
		CString strText;
		m_EDIT1.GetWindowText(strText);
		string str = (LPCSTR)(CStringA)strText;
		metp.member_id = stoi(str);
		m_EDIT2.GetWindowText(strText);
		metp.name = (LPCSTR)(CStringA)strText;
		m_EDIT3.GetWindowText(strText);
		metp.phone_num = (LPCSTR)(CStringA)strText;
		m_EDIT4.GetWindowText(strText);
		metp.address = (LPCSTR)(CStringA)strText;
		C_InfoFile file;
		str = "INSERT INTO member(member_id, name, phone_num, address) VALUES(" + to_string(metp.member_id) + "," + "'" + metp.name + "'" + "," + "'" + metp.phone_num + "'" + "," + "'" + metp.address + "'" + ")";
		//MessageBox((CString)str.c_str());
		if (connect_db()) {
			//MessageBox(_T("数据库连接连接成功"));

			if (execute_sql(str)) {
				MessageBox(_T("添加成功"));
				close_db();
				CDialogEx::OnOK();//关闭当前界面窗口
			}
			else {
				MessageBox(_T("添加失败"));
			}
			//file.WriteMember(metp);

		}
		else {
			MessageBox(_T("数据库连接连接失败"));
		}
	}
	
	
}

void JiLu::SetMember(Member member)
{
	this->member = member;
}
