// PetGrooming.cpp: 实现文件
//

#include "pch.h"
#include "YunTing_宠物店管理系统.h"
#include "PetGrooming.h"
#include "afxdialogex.h"
#include"C_InfoFile.h"

// PetGrooming 对话框

IMPLEMENT_DYNAMIC(PetGrooming, CDialogEx)

PetGrooming::PetGrooming(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

PetGrooming::~PetGrooming()
{
}

void PetGrooming::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT7, g_EDIT1);
	DDX_Control(pDX, IDC_EDIT9, g_EDIT2);
	DDX_Control(pDX, IDC_EDIT8, g_EDIT3);
	DDX_Control(pDX, IDC_EDIT10, g_EDIT4);
	if (this->str == "更新")
	{
		g_EDIT1.SetWindowTextW((CString)to_string(this->grooming.register_id).c_str());
		g_EDIT1.SetReadOnly(TRUE);
		g_EDIT2.SetWindowTextW((CString)to_string(this->grooming.pet_id).c_str());
		g_EDIT3.SetWindowTextW((CString)this->grooming.grooming_date.c_str());
		g_EDIT4.SetWindowTextW((CString)this->grooming.grooming_expense.c_str());
	}
}


BEGIN_MESSAGE_MAP(PetGrooming, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &PetGrooming::OnBnClickedButton1)
END_MESSAGE_MAP()


// PetGrooming 消息处理程序


void PetGrooming::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (this->str == "更新")
	{
		Grooming/*(修改成相对于的类)*/ metp;
		CString strText;
		g_EDIT1.GetWindowText(strText);
		string str = (LPCSTR)(CStringA)strText;
		metp.register_id = stoi(str);

		g_EDIT2.GetWindowText(strText);
		str = (LPCSTR)(CStringA)strText;
		metp.pet_id = stoi(str);

		g_EDIT3.GetWindowText(strText);
		metp.grooming_date = (LPCSTR)(CStringA)strText;

		g_EDIT4.GetWindowText(strText);
		metp.grooming_expense = (LPCSTR)(CStringA)strText;

		C_InfoFile file;
		str = "UPDATE grooming SET PetId=" + to_string(metp.pet_id) +
			", GroomingDate='" + metp.grooming_date +
			"', GroomingFee=" + metp.grooming_expense +
			"  WHERE GroomingId = " + to_string(this->grooming.register_id);
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
		Grooming/*(修改成相对于的类)*/ metp;
		CString strText;
		g_EDIT1.GetWindowText(strText);
		string str = (LPCSTR)(CStringA)strText;
		metp.register_id = stoi(str);

		g_EDIT2.GetWindowText(strText);
		str = (LPCSTR)(CStringA)strText;
		metp.pet_id = stoi(str);

		g_EDIT3.GetWindowText(strText);
		metp.grooming_date = (LPCSTR)(CStringA)strText;

		g_EDIT4.GetWindowText(strText);
		metp.grooming_expense = (LPCSTR)(CStringA)strText;

		C_InfoFile file;

		str = "INSERT INTO grooming(GroomingId,PetId, GroomingDate, GroomingFee) VALUES(" + to_string(metp.register_id) + "," + "'" + to_string(metp.pet_id) + "'" + "," + "'" + metp.grooming_date + "'" + "," + metp.grooming_expense + ")";

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

void PetGrooming::SetGrooming(Grooming grooming)
{
	this->grooming = grooming;
}
