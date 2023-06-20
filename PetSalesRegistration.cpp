// PetSalesRegistration.cpp: 实现文件
//

#include "pch.h"
#include "YunTing_宠物店管理系统.h"
#include "PetSalesRegistration.h"
#include "afxdialogex.h"
#include"C_InfoFile.h"

// PetSalesRegistration 对话框

IMPLEMENT_DYNAMIC(PetSalesRegistration, CDialogEx)

PetSalesRegistration::PetSalesRegistration(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

PetSalesRegistration::~PetSalesRegistration()
{
}

void PetSalesRegistration::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT7, s_EDIT1);
	DDX_Control(pDX, IDC_EDIT9, s_EDIT2);
	DDX_Control(pDX, IDC_EDIT8, s_EDIT3);
	DDX_Control(pDX, IDC_EDIT10, s_EDIT4);
	if (this->str == "更新")
	{
		s_EDIT1.SetWindowTextW((CString)to_string(this->salesRecord.sale_id).c_str());
		s_EDIT1.SetReadOnly(TRUE);
		s_EDIT2.SetWindowTextW((CString)to_string(this->salesRecord.pet_id).c_str());
		s_EDIT3.SetWindowTextW((CString)this->salesRecord.sale_date.c_str());
		s_EDIT4.SetWindowTextW((CString)this->salesRecord.sale_price.c_str());
	}
}


BEGIN_MESSAGE_MAP(PetSalesRegistration, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &PetSalesRegistration::OnBnClickedButton1)
END_MESSAGE_MAP()


// PetSalesRegistration 消息处理程序


void PetSalesRegistration::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (this->str == "更新")
	{
		SalesRecord/*(修改成相对于的类)*/ metp;
		CString strText;
		s_EDIT1.GetWindowText(strText);
		string str = (LPCSTR)(CStringA)strText;
		metp.sale_id = stoi(str);
		s_EDIT2.GetWindowText(strText);
		str = (LPCSTR)(CStringA)strText;
		metp.pet_id = stoi(str);
		s_EDIT3.GetWindowText(strText);
		metp.sale_date = (LPCSTR)(CStringA)strText;
		s_EDIT4.GetWindowText(strText);
		metp.sale_price = (LPCSTR)(CStringA)strText;
		C_InfoFile file;
		str = "UPDATE salesrecord SET PetId=" + to_string(metp.pet_id) +
			", SaleDate='" + metp.sale_date +
			"', SalePrice=" + metp.sale_price +
			"  WHERE SalesRecordId = " + to_string(this->salesRecord.sale_id);
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
		SalesRecord/*(修改成相对于的类)*/ metp;
		CString strText;
		s_EDIT1.GetWindowText(strText);
		string str = (LPCSTR)(CStringA)strText;
		metp.sale_id = stoi(str);
		s_EDIT2.GetWindowText(strText);
		str = (LPCSTR)(CStringA)strText;
		metp.pet_id = stoi(str);
		s_EDIT3.GetWindowText(strText);
		metp.sale_date = (LPCSTR)(CStringA)strText;
		s_EDIT4.GetWindowText(strText);
		metp.sale_price = (LPCSTR)(CStringA)strText;
		C_InfoFile file;
		str = "INSERT INTO salesrecord(SalesRecordId,PetId,SaleDate, SalePrice) VALUES(" + to_string(metp.sale_id) + "," + "'" + to_string(metp.pet_id) + "'" + "," + "'" + metp.sale_date + "'" + "," + metp.sale_price + ")";
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

void PetSalesRegistration::SetSalesRecord(SalesRecord salesRecord)
{
	this->salesRecord = salesRecord;
}
