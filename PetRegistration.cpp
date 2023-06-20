// PetRegistration.cpp: 实现文件
//

#include "pch.h"
#include "YunTing_宠物店管理系统.h"
#include "PetRegistration.h"
#include "afxdialogex.h"
#include"C_InfoFile.h"

// PetRegistration 对话框

IMPLEMENT_DYNAMIC(PetRegistration, CDialogEx)

PetRegistration::PetRegistration(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

PetRegistration::~PetRegistration()
{
}

void PetRegistration::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT7, p_EDIT1);
	DDX_Control(pDX, IDC_EDIT9, p_EDIT2);
	DDX_Control(pDX, IDC_EDIT11, p_EDIT3);
	DDX_Control(pDX, IDC_EDIT8, p_EDIT4);
	DDX_Control(pDX, IDC_EDIT10, p_EDIT5);
	if (this->str == "更新") {
		p_EDIT1.SetWindowTextW((CString)to_string(this->pet.pet_id).c_str());
		p_EDIT1.SetReadOnly(TRUE);
		p_EDIT2.SetWindowTextW((CString)this->pet.pet_name.c_str());
		p_EDIT3.SetWindowTextW((CString)this->pet.breed.c_str());
		p_EDIT4.SetWindowTextW((CString)to_string(this->pet.age).c_str());
		p_EDIT5.SetWindowTextW((CString)this->pet.gender.c_str());
	}
	
}


BEGIN_MESSAGE_MAP(PetRegistration, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &PetRegistration::OnBnClickedButton1)
END_MESSAGE_MAP()


// PetRegistration 消息处理程序


void PetRegistration::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (this->str == "更新")
	{
		CString strText;
		Pet/*(修改成相对于的类)*/ metp;
		
		string str;

		
		metp.pet_id =this->pet.pet_id;
		p_EDIT2.GetWindowText(strText);
		metp.pet_name = (LPCSTR)(CStringA)strText;
		p_EDIT3.GetWindowText(strText);
		metp.breed = (LPCSTR)(CStringA)strText;
		p_EDIT4.GetWindowText(strText);
		str = (LPCSTR)(CStringA)strText;
		metp.age = stoi(str);
		p_EDIT5.GetWindowText(strText);
		metp.gender = (LPCSTR)(CStringA)strText;
		
		C_InfoFile file;
		str = "UPDATE pet SET PetName='" + metp.pet_name +
			"', Breed='" + metp.breed +
			"', Gender='" + metp.gender +
			"', Age=" + to_string(metp.age) +
			"  WHERE PetId = " + to_string(this->pet.pet_id);
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
		CString strText;
		Pet/*(修改成相对于的类)*/ metp;
		p_EDIT1.GetWindowText(strText);/*m为该数据类型的首字母，命名规范：数据类型的首字母_EDIT1，后面以此类推*/
		string str = (LPCSTR)(CStringA)strText;
		metp.pet_id = stoi(str);/*该数据类型对应的数据，有多少个数据就赋值多少次*/
		p_EDIT2.GetWindowText(strText);
		metp.pet_name = (LPCSTR)(CStringA)strText;
		p_EDIT3.GetWindowText(strText);
		metp.breed = (LPCSTR)(CStringA)strText;
		p_EDIT4.GetWindowText(strText);
		str = (LPCSTR)(CStringA)strText;
		metp.age = stoi(str);
		p_EDIT5.GetWindowText(strText);
		metp.gender = (LPCSTR)(CStringA)strText;
		C_InfoFile file;
		str = "INSERT INTO pet(PetId,PetName,Breed,Gender,Age) VALUES(" + to_string(metp.pet_id) + "," + "'" + metp.pet_name + "'" + "," + "'" + metp.breed + "'" + "," + "'" + metp.gender + "'" + "," + to_string(metp.age) + ")";
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

void PetRegistration::SetPet(Pet pet)
{
	this->pet = pet;
}
