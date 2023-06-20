// boardingAlightingPossibility.cpp: 实现文件
//

#include "pch.h"
#include "YunTing_宠物店管理系统.h"
#include "boardingAlightingPossibility.h"
#include "afxdialogex.h"
#include"C_InfoFile.h"


// boardingAlightingPossibility 对话框

IMPLEMENT_DYNAMIC(boardingAlightingPossibility, CDialogEx)

boardingAlightingPossibility::boardingAlightingPossibility(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

boardingAlightingPossibility::~boardingAlightingPossibility()
{
}

void boardingAlightingPossibility::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT7, p_EDIT1);
	DDX_Control(pDX, IDC_EDIT9, p_EDIT2);
	DDX_Control(pDX, IDC_EDIT8, p_EDIT3);
	DDX_Control(pDX, IDC_EDIT10, p_EDIT4);
	DDX_Control(pDX, IDC_EDIT11, p_EDIT5);
	if (this->str == "更新")
	{
		p_EDIT1.SetWindowTextW((CString)to_string(this->boarding.register_id).c_str());
		p_EDIT1.SetReadOnly(TRUE);
		p_EDIT2.SetWindowTextW((CString)to_string(this->boarding.pet_id).c_str());
		p_EDIT3.SetWindowTextW((CString)this->boarding.boarding_start_date.c_str());
		p_EDIT4.SetWindowTextW((CString)this->boarding.boarding_end_date.c_str());
		p_EDIT5.SetWindowTextW((CString)this->boarding.boarding_expense.c_str());
	}
}


BEGIN_MESSAGE_MAP(boardingAlightingPossibility, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &boardingAlightingPossibility::OnBnClickedButton1)
END_MESSAGE_MAP()


// boardingAlightingPossibility 消息处理程序


void boardingAlightingPossibility::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	
	if (this->str == "更新")
	{
		Boarding/*(修改成相对于的类)*/ metp;
		CString strText;
		string str;
		metp.register_id = this->boarding.register_id;
		p_EDIT2.GetWindowText(strText);
		str = (LPCSTR)(CStringA)strText;
		metp.pet_id = stoi(str);
		p_EDIT3.GetWindowText(strText);
		metp.boarding_start_date = (LPCSTR)(CStringA)strText;
		p_EDIT4.GetWindowText(strText);
		metp.boarding_end_date = (LPCSTR)(CStringA)strText;
		p_EDIT5.GetWindowText(strText);
		metp.boarding_expense = (LPCSTR)(CStringA)strText;
		str = "UPDATE boarding SET 宠物编号=" + to_string(metp.pet_id) + ", 寄养起始日期='" + metp.boarding_start_date + "', 寄养结束日期='" + metp.boarding_end_date + "', 寄养费用=" + metp.boarding_expense + "  WHERE 寄养登记编号 = "+ to_string(this->boarding.register_id);
		//MessageBox((CString)str.c_str());
		C_InfoFile file;
		if (connect_db()) {
			//MessageBox(_T("数据库连接连接成功"));

			if (execute_sql(str)) {
				MessageBox(_T("更新完成"));
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
		Boarding/*(修改成相对于的类)*/ metp;
		CString strText;
		p_EDIT1.GetWindowText(strText);
		string str = (LPCSTR)(CStringA)strText;
		metp.register_id = stoi(str);
		p_EDIT2.GetWindowText(strText);
		str = (LPCSTR)(CStringA)strText;
		metp.pet_id = stoi(str);
		p_EDIT3.GetWindowText(strText);
		metp.boarding_start_date = (LPCSTR)(CStringA)strText;
		p_EDIT4.GetWindowText(strText);
		metp.boarding_end_date = (LPCSTR)(CStringA)strText;
		p_EDIT5.GetWindowText(strText);
		metp.boarding_expense = (LPCSTR)(CStringA)strText;
		C_InfoFile file;
		str = "INSERT INTO boarding(寄养登记编号,宠物编号,寄养起始日期,寄养结束日期, 寄养费用) VALUES(" + to_string(metp.register_id) + "," + "'" + to_string(metp.pet_id) + "'" + "," + "'" + metp.boarding_start_date + "'" + "," + "'" + metp.boarding_end_date + "'" + "," + metp.boarding_expense + ")";
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

void boardingAlightingPossibility::SetBoarding(Boarding boarding)
{
	this->boarding = boarding;
}
