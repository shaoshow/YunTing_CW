// CW.cpp: 实现文件
//

#include "pch.h"
#include "YunTing_宠物店管理系统.h"
#include "CW.h"
#include "afxdialogex.h"
#include"C_InfoFile.h"
#include"JiLu.h"
#include"boardingAlightingPossibility.h"
#include"PetGrooming.h"
#include"PetMedicalRecordRegistration.h"
#include"PetRegistration.h"
#include"PetSalesRegistration.h"
// CW 对话框

IMPLEMENT_DYNAMIC(CW, CDialogEx)

CW::CW(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CW, pParent)
{

}

CW::~CW()
{
}

void CW::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT10, B_id);
	DDX_Control(pDX, IDC_LIST4, m_List);
	DDX_Control(pDX, IDC_EDIT9, P_id);
	DDX_Control(pDX, IDC_EDIT8, zhongko);
	DDX_Control(pDX, IDC_EDIT16, M_id);
	DDX_Control(pDX, IDC_EDIT10, B_id);
	DDX_Control(pDX, IDC_EDIT12, G_id);
	DDX_Control(pDX, IDC_EDIT14, MR_id);
	DDX_Control(pDX, IDC_EDIT18, S_id);
}


BEGIN_MESSAGE_MAP(CW, CDialogEx)
	ON_BN_CLICKED(IDOK26, &CW::OnBnClickedOk26)
	ON_BN_CLICKED(IDOK29, &CW::OnBnClickedOk29)
	ON_BN_CLICKED(IDOK27, &CW::OnBnClickedOk27)
	ON_BN_CLICKED(IDOK28, &CW::OnBnClickedOk28)
	ON_BN_CLICKED(IDOK30, &CW::OnBnClickedOk30)
	ON_BN_CLICKED(IDOK31, &CW::OnBnClickedOk31)
	ON_BN_CLICKED(IDOK5, &CW::OnBnClickedOk5)
	ON_BN_CLICKED(IDOK3, &CW::OnBnClickedOk3)
	ON_BN_CLICKED(IDOK2, &CW::OnBnClickedOk2)
	ON_BN_CLICKED(IDOK6, &CW::OnBnClickedOk6)
	ON_BN_CLICKED(IDOK10, &CW::OnBnClickedOk10)
	ON_BN_CLICKED(IDOK14, &CW::OnBnClickedOk14)
	ON_BN_CLICKED(IDOK18, &CW::OnBnClickedOk18)
	ON_BN_CLICKED(IDOK22, &CW::OnBnClickedOk22)
	ON_BN_CLICKED(IDOK7, &CW::OnBnClickedOk7)
	ON_BN_CLICKED(IDOK11, &CW::OnBnClickedOk11)
	ON_BN_CLICKED(IDOK15, &CW::OnBnClickedOk15)
	ON_BN_CLICKED(IDOK19, &CW::OnBnClickedOk19)
	ON_BN_CLICKED(IDOK23, &CW::OnBnClickedOk23)
	ON_BN_CLICKED(IDOK8, &CW::OnBnClickedOk8)
	ON_BN_CLICKED(IDOK12, &CW::OnBnClickedOk12)
	ON_BN_CLICKED(IDOK16, &CW::OnBnClickedOk16)
	ON_BN_CLICKED(IDOK20, &CW::OnBnClickedOk20)
	ON_BN_CLICKED(IDOK24, &CW::OnBnClickedOk24)
	ON_BN_CLICKED(IDOK4, &CW::OnBnClickedOk4)
	ON_BN_CLICKED(IDOK9, &CW::OnBnClickedOk9)
	ON_BN_CLICKED(IDOK13, &CW::OnBnClickedOk13)
	ON_BN_CLICKED(IDOK17, &CW::OnBnClickedOk17)
	ON_BN_CLICKED(IDOK21, &CW::OnBnClickedOk21)
	ON_BN_CLICKED(IDOK25, &CW::OnBnClickedOk25)
	ON_BN_CLICKED(IDOK32, &CW::OnBnClickedOk32)
END_MESSAGE_MAP()


// CW 消息处理程序

//查询所有宠物信息
void CW::OnBnClickedOk26()
{
	// TODO: 在此添加控件通知处理程序代码
	if (connect_db()) {
		//MessageBox(_T("数据库连接连接成功"));
		C_InfoFile file;
		file.GitPet();
		// Delete all rows
		m_List.DeleteAllItems();
		// Delete all columns
		while (m_List.DeleteColumn(0));
		// Reset extended style to default
		//m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP);
		// Reset foreground color, background color and font
		//m_List.SetTextColor(CLR_DEFAULT);
		//m_List.SetBkColor(CLR_DEFAULT);
		//m_List.SetFont(nullptr);
		m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT);
		m_List.InsertColumn(0, _T("宠物编号"), 0, 80);
		m_List.InsertColumn(1, _T("宠物姓名"), 0, 70);
		m_List.InsertColumn(2, _T("种类"), 0, 80);
		m_List.InsertColumn(3, _T("性别"), 0, 50);
		m_List.InsertColumn(4, _T("年龄"), 0, 80);
		
		int i = 0;
		for (vector<Pet>::iterator it = file.lies2.begin(); it != file.lies2.end(); it++)  //将文件数据写入列表
		{
			m_List.InsertItem(i, (CString)to_string(it->pet_id).c_str());
			m_List.SetItemText(i, 1, (CString)it->pet_name.c_str());
			m_List.SetItemText(i, 2, (CString)it->breed.c_str());
			m_List.SetItemText(i, 3, (CString)it->gender.c_str());
			m_List.SetItemText(i,4, (CString)to_string(it->age).c_str());
			i++;
		}

	}
	else {
		MessageBox(_T("数据库连接失败，请重新操作"), _T("提示"));
	}
}
//查询会员信息
void CW::OnBnClickedOk29()
{
	// TODO: 在此添加控件通知处理程序代码
	if (connect_db()) {
		//MessageBox(_T("数据库连接连接成功"));
		C_InfoFile file;
		file.GitMember();
		// Delete all rows
		m_List.DeleteAllItems();
		// Delete all columns
		while (m_List.DeleteColumn(0));
		// Reset extended style to default
		//m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP);
		// Reset foreground color, background color and font
		//m_List.SetTextColor(CLR_DEFAULT);
		//m_List.SetBkColor(CLR_DEFAULT);
		//m_List.SetFont(nullptr);
		m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT);
		m_List.InsertColumn(0, _T("会员编号"), 0, 80);
		m_List.InsertColumn(1, _T("姓名"), 0, 70);
		m_List.InsertColumn(2, _T("手机号码"), 0, 80);
		m_List.InsertColumn(3, _T("地址"), 0, 100);
		int i = 0;
		for (vector<Member>::iterator it = file.lies1.begin(); it != file.lies1.end(); it++)  //将文件数据写入列表
		{

			m_List.InsertItem(i, (CString)to_string(it->member_id).c_str());
			m_List.SetItemText(i, 1, (CString)it->name.c_str());
			m_List.SetItemText(i, 2, (CString)it->phone_num.c_str());
			m_List.SetItemText(i, 3, (CString)it->address.c_str());

			i++;
		}

	}
	else {
		MessageBox(_T("数据库连接失败，请重新操作"), _T("提示"));
	}
}
//宠物寄养查询
void CW::OnBnClickedOk27()
{
	// TODO: 在此添加控件通知处理程序代码
	if (connect_db()) {
		//MessageBox(_T("数据库连接连接成功"));
		C_InfoFile file;
		file.GitBoarding();
		// Delete all rows
		m_List.DeleteAllItems();
		// Delete all columns
		while (m_List.DeleteColumn(0));
		// Reset extended style to default
		//m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP);
		// Reset foreground color, background color and font
		//m_List.SetTextColor(CLR_DEFAULT);
		//m_List.SetBkColor(CLR_DEFAULT);
		//m_List.SetFont(nullptr);
		m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT);
		m_List.InsertColumn(0, _T("寄养登记编号"), 0, 80);
		m_List.InsertColumn(1, _T("宠物编号"), 0, 70);
		m_List.InsertColumn(2, _T("寄养起始日期"), 0, 150);
		m_List.InsertColumn(3, _T("寄养结束日期"), 0, 150);
		m_List.InsertColumn(4, _T("寄养费用"), 0, 100);
		int i = 0;
		for (vector<Boarding>::iterator it = file.lies5.begin(); it != file.lies5.end(); it++)  //将文件数据写入列表
		{
			m_List.InsertItem(i, (CString)to_string(it->register_id).c_str());
			m_List.SetItemText(i, 1, (CString)to_string(it->pet_id).c_str());
			m_List.SetItemText(i, 2, (CString)it->boarding_start_date.c_str());
			m_List.SetItemText(i, 3, (CString)it->boarding_end_date.c_str());
			m_List.SetItemText(i, 4, (CString)it->boarding_expense.c_str());
			i++;
		}
	}
	else {
		MessageBox(_T("数据库连接失败，请重新操作"), _T("提示"));
	}
}
//宠物美容查询
void CW::OnBnClickedOk28()
{
	// TODO: 在此添加控件通知处理程序代码

	
		// TODO: 在此添加控件通知处理程序代码
		if (connect_db()) {
			//MessageBox(_T("数据库连接连接成功"));
			C_InfoFile file;
			file.GitGrooming();
			// Delete all rows
			m_List.DeleteAllItems();
			// Delete all columns
			while (m_List.DeleteColumn(0));
			// Reset extended style to default
			//m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP);
			// Reset foreground color, background color and font
			//m_List.SetTextColor(CLR_DEFAULT);
			//m_List.SetBkColor(CLR_DEFAULT);
			//m_List.SetFont(nullptr);
			m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT);
			m_List.InsertColumn(0, _T("美容编号"), 0, 80);
			m_List.InsertColumn(1, _T("宠物编号"), 0, 70);
			m_List.InsertColumn(2, _T("美容时间"), 0, 150);
			m_List.InsertColumn(3, _T("美容费用"), 0, 70);

			int i = 0;
			for (vector<Grooming>::iterator it = file.lies4.begin(); it != file.lies4.end(); it++)  //将文件数据写入列表
			{

				m_List.InsertItem(i, (CString)to_string(it->register_id).c_str());
				m_List.SetItemText(i, 1, (CString)to_string(it->pet_id).c_str());
				m_List.SetItemText(i, 2, (CString)it->grooming_date.c_str());
				m_List.SetItemText(i, 3, (CString)it->grooming_expense.c_str());
				i++;
			}

		}
		else {
			MessageBox(_T("数据库连接失败，请重新操作"), _T("提示"));
		}
	
}
//宠物医疗病例查询
void CW::OnBnClickedOk30()
{
	// TODO: 在此添加控件通知处理程序代码

	
		// TODO: 在此添加控件通知处理程序代码


			// TODO: 在此添加控件通知处理程序代码
		if (connect_db()) {
			//MessageBox(_T("数据库连接连接成功"));
			C_InfoFile file;
			file.GitMedicalRecord();
			// Delete all rows
			m_List.DeleteAllItems();
			// Delete all columns
			while (m_List.DeleteColumn(0));
			// Reset extended style to default
			//m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP);
			// Reset foreground color, background color and font
			//m_List.SetTextColor(CLR_DEFAULT);
			//m_List.SetBkColor(CLR_DEFAULT);
			//m_List.SetFont(nullptr);
			m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT);
			m_List.InsertColumn(0, _T("病历编号"), 0, 80);
			m_List.InsertColumn(1, _T("宠物编号"), 0, 70);
			m_List.InsertColumn(2, _T("症状"), 0, 150);
			m_List.InsertColumn(3, _T("诊断结果"), 0, 70);
			m_List.InsertColumn(4, _T("医疗费用"), 0, 70);

			int i = 0;
			for (vector<MedicalRecord>::iterator it = file.lies3.begin(); it != file.lies3.end(); it++)  //将文件数据写入列表
			{

				m_List.InsertItem(i, (CString)to_string(it->record_id).c_str());
				m_List.SetItemText(i, 1, (CString)to_string(it->pet_id).c_str());
				m_List.SetItemText(i, 2, (CString)it->symptom.c_str());
				m_List.SetItemText(i, 3, (CString)it->diagnosis.c_str());
				m_List.SetItemText(i, 4, (CString)it->medical_expense.c_str());
				i++;
			}

		}
		else {
			MessageBox(_T("数据库连接失败，请重新操作"), _T("提示"));
		}

	
}
//宠物销售价格查询
void CW::OnBnClickedOk31()
{
	// TODO: 在此添加控件通知处理程序代码

		if (connect_db()) {
			//MessageBox(_T("数据库连接连接成功"));
			C_InfoFile file;
			file.GitSalesRecord();
			// Delete all rows
			m_List.DeleteAllItems();
			// Delete all columns
			while (m_List.DeleteColumn(0));
			// Reset extended style to default
			//m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP);
			// Reset foreground color, background color and font
			//m_List.SetTextColor(CLR_DEFAULT);
			//m_List.SetBkColor(CLR_DEFAULT);
			//m_List.SetFont(nullptr);
			m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT);
			m_List.InsertColumn(0, _T("销售编号"), 0, 80);
			m_List.InsertColumn(1, _T("宠物编号"), 0, 70);
			m_List.InsertColumn(2, _T("销售日期"), 0, 150);
			m_List.InsertColumn(3, _T("销售价格"), 0, 70);

			int i = 0;
			for (vector<SalesRecord>::iterator it = file.lies6.begin(); it != file.lies6.end(); it++)  //将文件数据写入列表
			{

				m_List.InsertItem(i, (CString)to_string(it->sale_id).c_str());
				m_List.SetItemText(i, 1, (CString)to_string(it->pet_id).c_str());
				m_List.SetItemText(i, 2, (CString)it->sale_date.c_str());
				m_List.SetItemText(i, 3, (CString)it->sale_price.c_str());
				
				i++;
			}

		}
		else {
			MessageBox(_T("数据库连接失败，请重新操作"), _T("提示"));
		}


	
}

//查询宠物信息
void CW::OnBnClickedOk2()
{
	// TODO: 在此添加控件通知处理程序代码
	C_InfoFile file;
	file.GitPet();
	CString cstr;
	P_id.GetWindowText(cstr);
	if (cstr.IsEmpty())
	{
		MessageBox(_T("查询不能为空"), _T("提示"));
		return;
	}
	else {
		for (vector<Pet>::iterator it = file.lies2.begin(); it != file.lies2.end(); it++)  //将文件数据写入列表
		{
			if ((CString)to_string(it->pet_id).c_str() == cstr)
			{
				zhongko.SetWindowTextW(_T("宠物编号：") + (CString)to_string(it->pet_id).c_str()
					+ _T("\r\n宠物名字：") + (CString)it->pet_name.c_str() + _T("\r\n宠物品种：")
					+ (CString)it->breed.c_str() + _T("\r\n宠物性别：") + (CString)it->gender.c_str()
					+ _T("\r\n宠物年龄：") + (CString)to_string(it->age).c_str());
				return;
			}
		}
	}
	
	MessageBox(_T("查询不到：")+ cstr, _T("提示"));
}
//查询寄养信息
void CW::OnBnClickedOk6()
{
	// TODO: 在此添加控件通知处理程序代码
	C_InfoFile file;
	file.GitBoarding();
	CString cstr;
	B_id.GetWindowText(cstr);
	if (cstr.IsEmpty())
	{
		MessageBox(_T("查询不能为空"), _T("提示"));
		return;
	}
	else{
	for (vector<Boarding>::iterator it = file.lies5.begin(); it != file.lies5.end(); it++)  //将文件数据写入列表
	{
		if ((CString)to_string(it->register_id).c_str() == cstr)
		{
			zhongko.SetWindowTextW(_T("登记编号：") + (CString)to_string(it->register_id).c_str()
				+ _T("\r\n宠物编号：") + (CString)to_string(it->pet_id).c_str()
				+ _T("\r\n寄养起始时间：") + (CString)it->boarding_start_date.c_str()
				+ _T("\r\n寄养结束时间：") + (CString)it->boarding_end_date.c_str()
				+ _T("\r\n寄养费用：") + (CString)it->boarding_expense.c_str());
			return;
		}
	}
	}
	MessageBox(_T("查询不到：") + cstr, _T("提示"));
}
//查询美容信息
void CW::OnBnClickedOk10()
{
	// TODO: 在此添加控件通知处理程序代码
	C_InfoFile file;
	file.GitGrooming();
	CString cstr;
	G_id.GetWindowText(cstr);
	if (cstr.IsEmpty())
	{
		MessageBox(_T("查询不能为空"), _T("提示"));
		return;
	}
	else {
		for (vector<Grooming>::iterator it = file.lies4.begin(); it != file.lies4.end(); it++)  //将文件数据写入列表
		{
			if ((CString)to_string(it->register_id).c_str() == cstr)
			{
				zhongko.SetWindowTextW(_T("登记编号：") + (CString)to_string(it->register_id).c_str()
					+ _T("\r\n宠物编号：") + (CString)to_string(it->pet_id).c_str()
					+ _T("\r\n美容日期：") + (CString)it->grooming_date.c_str()
					+ _T("\r\n美容费用：") + (CString)it->grooming_expense.c_str());
				return;
			}
		}
	}
	MessageBox(_T("查询不到：") + cstr, _T("提示"));
}
//查询医疗病例信息
void CW::OnBnClickedOk14()
{
	// TODO: 在此添加控件通知处理程序代码
	C_InfoFile file;
	file.GitMedicalRecord();
	CString cstr;
	MR_id.GetWindowText(cstr);
	if (cstr.IsEmpty())
	{
		MessageBox(_T("查询不能为空"), _T("提示"));
		return;
	}
	else {
		for (vector<MedicalRecord>::iterator it = file.lies3.begin(); it != file.lies3.end(); it++)  //将文件数据写入列表
		{
			if ((CString)to_string(it->record_id).c_str() == cstr)
			{
				zhongko.SetWindowTextW(_T("病历编号：") + (CString)to_string(it->record_id).c_str()
					+ _T("\r\n宠物编号：") + (CString)to_string(it->pet_id).c_str()
					+ _T("\r\n症状：") + (CString)it->symptom.c_str()
					+ _T("\r\n诊断结果：") + (CString)it->diagnosis.c_str()
					+ _T("\r\n医疗费用：") + (CString)it->medical_expense.c_str());
				return;
			}
		}
	}
	MessageBox(_T("查询不到：") + cstr, _T("提示"));
}
//查询会员信息
void CW::OnBnClickedOk18()
{
	// TODO: 在此添加控件通知处理程序代码
C_InfoFile file;
	file.GitMember();
	CString cstr;
	M_id.GetWindowText(cstr);
	if (cstr.IsEmpty())
	{
		MessageBox(_T("查询不能为空"), _T("提示"));
		return;
	}
	else {
		for (vector<Member>::iterator it = file.lies1.begin(); it != file.lies1.end(); it++)  //将文件数据写入列表
		{
			if ((CString)to_string(it->member_id).c_str() == cstr)
			{
				zhongko.SetWindowTextW(_T("会员编号：") + (CString)to_string(it->member_id).c_str()
					+ _T("\r\n姓名：") + (CString)it->name.c_str()
					+ _T("\r\n手机号码：") + (CString)it->phone_num.c_str()
					+ _T("\r\n地址：") + (CString)it->address.c_str());
				return;
			}
		}
	}
	MessageBox(_T("查询不到：")+ cstr, _T("提示"));
}
//查询销售信息
void CW::OnBnClickedOk22()
{
	// TODO: 在此添加控件通知处理程序代码
	C_InfoFile file;
	file.GitSalesRecord();
	CString cstr;
	S_id.GetWindowText(cstr);
	if (cstr.IsEmpty())
	{
		MessageBox(_T("查询不能为空"), _T("提示"));
		return;
	}
	else {
		for (vector<SalesRecord>::iterator it = file.lies6.begin(); it != file.lies6.end(); it++)  //将文件数据写入列表
		{
			if ((CString)to_string(it->sale_id).c_str() == cstr)
			{
				zhongko.SetWindowTextW(_T("销售编号：") + (CString)to_string(it->sale_id).c_str()
					+ _T("\r\n宠物编号：") + (CString)to_string(it->pet_id).c_str()
					+ _T("\r\n销售日期：") + (CString)it->sale_date.c_str()
					+ _T("\r\n销售价格：") + (CString)it->sale_price.c_str());
				return;
			}
		}
	}
	MessageBox(_T("查询不到：") + cstr,_T("提示"));
}

//删除宠物信息
void CW::OnBnClickedOk3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cstr;
	P_id.GetWindowText(cstr);
	string s = (LPCSTR)(CStringA)cstr;
	string str = "DELETE FROM pet WHERE PetId = " +s;
	//MessageBox((CString)str.c_str(), _T("提示"));
	C_InfoFile file;
	file.GitPet();
	for (vector<Pet>::iterator it = file.lies2.begin(); it != file.lies2.end(); it++)  //将文件数据写入列表
	{
		if ((CString)to_string(it->pet_id).c_str() == cstr)
		{
			MessageBox(_T("删除信息：\r\n宠物编号：") + (CString)to_string(it->pet_id).c_str()
				+ _T("\r\n宠物名字：") + (CString)it->pet_name.c_str() + _T("\r\n宠物品种：")
				+ (CString)it->breed.c_str() + _T("\r\n宠物性别：") + (CString)it->gender.c_str()
				+ _T("\r\n宠物年龄：") + (CString)to_string(it->age).c_str(), _T("提示"));
			if (connect_db()) {
				if (execute_sql(str)) {
					MessageBox(_T("删除：“") + cstr + _T("”数据成功"), _T("提示"));
				}
				close_db();
			}
			else {
				MessageBox(_T("数据库连接失败"), _T("提示"));
			}
			return;
		}
	}
	MessageBox(_T("无“") + cstr + _T("”的数据"), _T("提示"));
}
//删除寄养信息
void CW::OnBnClickedOk7()
{
	// TODO: 在此添加控件通知处理程序代码
	/*CString cstr;
	B_id.GetWindowText(cstr);
	string s = (LPCSTR)(CStringA)cstr;
	string str = "DELETE FROM boarding WHERE 寄养登记编号 = " + s;
	MessageBox((CString)str.c_str());
	if (connect_db()) {
		if (execute_sql(str)) {
			MessageBox(_T("删除：“") + cstr + _T("”数据成功"));
		}
		else {
			MessageBox(_T("无“") + cstr + _T("”的数据"));
		}
		close_db();
	}
	else {
		MessageBox(_T("数据库连接失败"));
	}*/
	CString cstr;
	B_id.GetWindowText(cstr);
	string s = (LPCSTR)(CStringA)cstr;
	string str = "DELETE FROM boarding WHERE 寄养登记编号 = " + s;
	//MessageBox((CString)str.c_str(), _T("提示"));
	C_InfoFile file;
	file.GitBoarding();
	for (vector<Boarding>::iterator it = file.lies5.begin(); it != file.lies5.end(); it++)
	{
		if ((CString)to_string(it->register_id).c_str() == cstr)
		{
			MessageBox(
				_T("删除寄样信息\r\n寄养登记编号：： ")
				+(CString)to_string(it->register_id).c_str()
				+ _T("\r\n宠物编号：") + (CString)to_string(it->pet_id).c_str()
				+ _T("\r\n寄养起始时间：") + (CString)it->boarding_start_date.c_str()
				+ _T("\r\n寄养结束时间：") + (CString)it->boarding_end_date.c_str()
				+ _T("\r\n寄养费用：") + (CString)it->boarding_expense.c_str(), _T("提示"));
			if (connect_db()) {
				if (execute_sql(str)) {
					MessageBox(_T("删除：“") + cstr + _T("”数据成功"), _T("提示"));
				}
				close_db();
			}
			else {
				MessageBox(_T("数据库连接失败"), _T("提示"));
			}
			return;
		}
	}
	MessageBox(_T("无“") + cstr + _T("”的数据"), _T("提示"));
}
//删除美容信息
void CW::OnBnClickedOk11()
{
	// TODO: 在此添加控件通知处理程序代码
	/*CString cstr;
	G_id.GetWindowText(cstr);
	string s = (LPCSTR)(CStringA)cstr;
	string str = "DELETE FROM grooming WHERE GroomingId = " + s;
	MessageBox((CString)str.c_str());
	if (connect_db()) {
		if (execute_sql(str)) {
			MessageBox(_T("删除：“") + cstr + _T("”数据成功"));
		}
		else {
			MessageBox(_T("无“") + cstr + _T("”的数据"));
		}
		close_db();
	}
	else {
		MessageBox(_T("数据库连接失败"));
	}*/
	CString cstr;
	G_id.GetWindowText(cstr);
	string s = (LPCSTR)(CStringA)cstr;
	string str = "DELETE FROM grooming WHERE GroomingId = " + s;//GroomingId
	//MessageBox((CString)str.c_str(), _T("提示"));
	C_InfoFile file;
	file.GitGrooming();
	for (vector<Grooming>::iterator it = file.lies4.begin(); it != file.lies4.end(); it++)
	{
		if ((CString)to_string(it->register_id).c_str() == cstr)
		{
			MessageBox(
				_T("删除美容信息：\r\n登记编号：")
				+ (CString)to_string(it->register_id).c_str()
				+ _T("\r\n宠物编号：") + (CString)to_string(it->pet_id).c_str()
				+ _T("\r\n美容日期：") + (CString)it->grooming_date.c_str()
				+ _T("\r\n美容费用：") + (CString)it->grooming_expense.c_str(), _T("提示")
			);
			if (connect_db()) {
				if (execute_sql(str)) {
					MessageBox(_T("删除：“") + cstr + _T("”数据成功"), _T("提示"));
				}
				close_db();
			}
			else {
				MessageBox(_T("数据库连接失败"), _T("提示"));
			}
			return;
		}
	}
	MessageBox(_T("无“") + cstr + _T("”的数据"), _T("提示"));
}
//删除医疗病例信息
void CW::OnBnClickedOk15()
{
	// TODO: 在此添加控件通知处理程序代码
	/*CString cstr;
	MR_id.GetWindowText(cstr);
	string s = (LPCSTR)(CStringA)cstr;
	string str = "DELETE FROM medicalrecord WHERE MedicalRecordId = " + s;
	MessageBox((CString)str.c_str());
	if (connect_db()) {
		if (execute_sql(str)) {
			MessageBox(_T("删除：“") + cstr + _T("”数据成功"));
		}
		else {
			MessageBox(_T("无“") + cstr + _T("”的数据"));
		}
		close_db();
	}
	else {
		MessageBox(_T("数据库连接失败"));
	}*/
	CString cstr;
	MR_id.GetWindowText(cstr);
	string s = (LPCSTR)(CStringA)cstr;
	string str = "DELETE FROM medicalrecord WHERE MedicalRecordId = " + s;//MedicalRecordId
	//MessageBox((CString)str.c_str(), _T("提示"));
	C_InfoFile file;
	file.GitMedicalRecord();
	for (vector<MedicalRecord>::iterator it = file.lies3.begin(); it != file.lies3.end(); it++)
	{
		if ((CString)to_string(it->record_id).c_str() == cstr)
		{
			MessageBox(
				_T("删除医疗病例信息：\r\n病历编号：")
				+ (CString)to_string(it->record_id).c_str()
				+ _T("\r\n宠物编号：") + (CString)to_string(it->pet_id).c_str()
				+ _T("\r\n症状：") + (CString)it->symptom.c_str()
				+ _T("\r\n诊断结果：") + (CString)it->diagnosis.c_str()
				+ _T("\r\n医疗费用：") + (CString)it->medical_expense.c_str(), _T("提示")
			);
			if (connect_db()) {
				if (execute_sql(str)) {
					MessageBox(_T("删除：“") + cstr + _T("”数据成功"), _T("提示"));
				}
				close_db();
			}
			else {
				MessageBox(_T("数据库连接失败"), _T("提示"));
			}
			return;
		}
	}
	MessageBox(_T("无“") + cstr + _T("”的数据"), _T("提示"));
}
//删除会员信息
void CW::OnBnClickedOk19()
{
	// TODO: 在此添加控件通知处理程序代码
	/*CString cstr;
	M_id.GetWindowText(cstr);
	string s = (LPCSTR)(CStringA)cstr;
	string str = "DELETE FROM member WHERE member_id = " + s;
	MessageBox((CString)str.c_str());
	if (connect_db()) {
		if (execute_sql(str)) {
			MessageBox(_T("删除：“") + cstr + _T("”数据成功"));
		}
		else {
			MessageBox(_T("无“") + cstr + _T("”的数据"));
		}
		close_db();
	}
	else {
		MessageBox(_T("数据库连接失败"));
	}*/
	CString cstr;
	M_id.GetWindowText(cstr);
	string s = (LPCSTR)(CStringA)cstr;
	string str = "DELETE FROM member WHERE member_id = " + s;
	//MessageBox((CString)str.c_str());
	C_InfoFile file;
	file.GitMember();
	for (vector<Member>::iterator it = file.lies1.begin(); it != file.lies1.end(); it++)
	{
		if ((CString)to_string(it->member_id).c_str() == cstr)
		{
			MessageBox(
				_T("删除会员信息：\r\n会员编号：")
				+ (CString)to_string(it->member_id).c_str()
				+ _T("\r\n姓名：") + (CString)it->name.c_str()
				+ _T("\r\n手机号码：") + (CString)it->phone_num.c_str()
				+ _T("\r\n地址：") + (CString)it->address.c_str(), _T("提示")
			);
			if (connect_db()) {
				if (execute_sql(str)) {
					MessageBox(_T("删除：“") + cstr + _T("”数据成功"), _T("提示"));
				}
				close_db();
			}
			else {
				MessageBox(_T("数据库连接失败"), _T("提示"));
			}
			return;
		}
	}
	MessageBox(_T("无“") + cstr + _T("”的数据"), _T("提示"));
}
//删除销售信息
void CW::OnBnClickedOk23()
{
	// TODO: 在此添加控件通知处理程序代码
	/*CString cstr;
	S_id.GetWindowText(cstr);
	string s = (LPCSTR)(CStringA)cstr;
	string str = "DELETE FROM salesrecord WHERE SalesRecordId = " + s;
	MessageBox((CString)str.c_str());
	if (connect_db()) {
		if (execute_sql(str)) {
			MessageBox(_T("删除：“") + cstr + _T("”数据成功"));
		}
		else {
			MessageBox(_T("无“") + cstr + _T("”的数据"));
		}
		close_db();
	}
	else {
		MessageBox(_T("数据库连接失败"));
	}*/
	CString cstr;
	S_id.GetWindowText(cstr);
	string s = (LPCSTR)(CStringA)cstr;
	string str = "DELETE FROM salesrecord WHERE SalesRecordId = " + s;
	//MessageBox((CString)str.c_str(), _T("提示"));
	C_InfoFile file;
	file.GitSalesRecord();
	for (vector<SalesRecord>::iterator it = file.lies6.begin(); it != file.lies6.end(); it++)
	{
		if ((CString)to_string(it->sale_id).c_str() == cstr)
		{
			MessageBox(
				_T("删除销售信息：\r\n销售编号：")
				+ (CString)to_string(it->sale_id).c_str()
				+ _T("\r\n宠物编号：") + (CString)to_string(it->pet_id).c_str()
				+ _T("\r\n销售日期：") + (CString)it->sale_date.c_str()
				+ _T("\r\n销售价格：") + (CString)it->sale_price.c_str(), _T("提示")
			);
			if (connect_db()) {
				if (execute_sql(str)) {
					MessageBox(_T("删除：“") + cstr + _T("”数据成功"), _T("提示"));
				}
				close_db();
			}
			else {
				MessageBox(_T("数据库连接失败"), _T("提示"));
			}
			return;
		}
	}
	MessageBox(_T("无“") + cstr + _T("”的数据"), _T("提示"));
}

//登记宠物信息
void CW::OnBnClickedOk5()
{
	// TODO: 在此添加控件通知处理程序代码
	PetRegistration P;
	P.str = "添加";
	P.DoModal();
	
}
//添加寄养信息
void CW::OnBnClickedOk8()
{
	// TODO: 在此添加控件通知处理程序代码
	boardingAlightingPossibility P;
	P.str = "添加";
	P.DoModal();
}
//添加美容信息
void CW::OnBnClickedOk12()
{
	// TODO: 在此添加控件通知处理程序代码
	PetGrooming P;
	P.str = "添加";
	P.DoModal();
}
//添加医疗病例信息
void CW::OnBnClickedOk16()
{
	// TODO: 在此添加控件通知处理程序代码
	PetMedicalRecordRegistration P;
	P.str = "添加";
	P.DoModal();
}
//添加会员信息(完成)
void CW::OnBnClickedOk20()
{
	// TODO: 在此添加控件通知处理程序代码
	JiLu P;
	P.str = "添加";
	P.DoModal();//开启会员管理窗口
}
//添加销售信息
void CW::OnBnClickedOk24()
{
	// TODO: 在此添加控件通知处理程序代码
	PetSalesRegistration P;
	P.str = "添加";
	P.DoModal();
}

//更新宠物信息
void CW::OnBnClickedOk4()
{
	// TODO: 在此添加控件通知处理程序代码
	C_InfoFile file;
	file.GitPet();
	CString cstr;
	P_id.GetWindowText(cstr);
	if (cstr.IsEmpty())
	{
		MessageBox(_T("更新不能为空"), _T("提示"));
		return;
	}
	else {
		for (vector<Pet>::iterator it = file.lies2.begin(); it != file.lies2.end(); it++)  //将文件数据写入列表
		{
			if ((CString)to_string(it->pet_id).c_str() == cstr)
			{
				PetRegistration P;
				P.str = "更新";
				P.SetPet(*it);
				P.DoModal();
				return;
			}
		}
	}

	MessageBox(_T("无数据：“") + cstr + _T("”"), _T("提示"));
	
}
//更新寄养信息
void CW::OnBnClickedOk9()
{
	// TODO: 在此添加控件通知处理程序代码
	C_InfoFile file;
	file.GitBoarding();
	CString cstr;
	B_id.GetWindowText(cstr);
	if (cstr.IsEmpty())
	{
		MessageBox(_T("更新不能为空"), _T("提示"));
		return;
	}
	else {
		for (vector<Boarding>::iterator it = file.lies5.begin(); it != file.lies5.end(); it++)  //将文件数据写入列表
		{
			if ((CString)to_string(it->register_id).c_str() == cstr)
			{
				boardingAlightingPossibility P;
				P.str = "更新";
				P.SetBoarding(*it);
				P.DoModal();
				return;
			}
		}
	}
	MessageBox(_T("无数据：“") + cstr+ _T("”"), _T("提示"));
	
}
//更新美容信息
void CW::OnBnClickedOk13()
{
	// TODO: 在此添加控件通知处理程序代码
	C_InfoFile file;
	file.GitGrooming();
	CString cstr;
	G_id.GetWindowText(cstr);
	if (cstr.IsEmpty())
	{
		MessageBox(_T("更新不能为空"), _T("提示"));
		return;
	}
	else {
		for (vector<Grooming>::iterator it = file.lies4.begin(); it != file.lies4.end(); it++)  //将文件数据写入列表
		{
			if ((CString)to_string(it->register_id).c_str() == cstr)
			{
				PetGrooming P;
				P.str = "更新";
				P.SetGrooming(*it);
				P.DoModal();
				return;
			}
		}
	}
	MessageBox(_T("无数据：“") + cstr + _T("”"), _T("提示"));


}
//更新医疗病例信息
void CW::OnBnClickedOk17()
{
	// TODO: 在此添加控件通知处理程序代码
	C_InfoFile file;
	file.GitMedicalRecord();
	CString cstr;
	MR_id.GetWindowText(cstr);
	if (cstr.IsEmpty())
	{
		MessageBox(_T("更新不能为空"), _T("提示"));
		return;
	}
	else {
		for (vector<MedicalRecord>::iterator it = file.lies3.begin(); it != file.lies3.end(); it++)  //将文件数据写入列表
		{
			if ((CString)to_string(it->record_id).c_str() == cstr)
			{
				PetMedicalRecordRegistration P;
				P.str = "更新";
				P.SetMedicalRecord(*it);
				P.DoModal();
				return;
			}
		}
	}
	MessageBox(_T("无数据：“") + cstr + _T("”"), _T("提示"));
}
//更新会员信息
void CW::OnBnClickedOk21()
{
	// TODO: 在此添加控件通知处理程序代码
	C_InfoFile file;
	file.GitMember();
	CString cstr;
	M_id.GetWindowText(cstr);
	if (cstr.IsEmpty())
	{
		MessageBox(_T("更新不能为空"), _T("提示"));
		return;
	}
	else {
		for (vector<Member>::iterator it = file.lies1.begin(); it != file.lies1.end(); it++)  //将文件数据写入列表
		{
			if ((CString)to_string(it->member_id).c_str() == cstr)
			{
				JiLu P;
				P.str = "更新";
				P.SetMember(*it);
				P.DoModal();
				return;
			}
		}
	}
	MessageBox(_T("无数据：“") + cstr + _T("”"), _T("提示"));
}
//更新销售信息
void CW::OnBnClickedOk25()
{
	// TODO: 在此添加控件通知处理程序代码
	C_InfoFile file;
	file.GitSalesRecord();
	CString cstr;
	S_id.GetWindowText(cstr);
	if (cstr.IsEmpty())
	{
		MessageBox(_T("更新不能为空"), _T("提示"));
		return;
	}
	else {
		for (vector<SalesRecord>::iterator it = file.lies6.begin(); it != file.lies6.end(); it++)  //将文件数据写入列表
		{
			if ((CString)to_string(it->sale_id).c_str() == cstr)
			{
				PetSalesRegistration P;
				P.str = "更新";
				P.SetSalesRecord(*it);
				P.DoModal();
				return;
			}
		}
	}
	MessageBox(_T("无数据：“") + cstr + _T("”"), _T("提示"));
}


void CW::OnBnClickedOk32()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("功能暂未开发，敬请期待“") , _T("提示"));
}
