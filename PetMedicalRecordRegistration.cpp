// PetMedicalRecordRegistration.cpp: 实现文件
//

#include "pch.h"
#include "YunTing_宠物店管理系统.h"
#include "PetMedicalRecordRegistration.h"
#include "afxdialogex.h"
#include"C_InfoFile.h"

// PetMedicalRecordRegistration 对话框

IMPLEMENT_DYNAMIC(PetMedicalRecordRegistration, CDialogEx)

PetMedicalRecordRegistration::PetMedicalRecordRegistration(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

PetMedicalRecordRegistration::~PetMedicalRecordRegistration()
{
}

void PetMedicalRecordRegistration::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT7, m_EDIT1);
	DDX_Control(pDX, IDC_EDIT9, m_EDIT2);
	DDX_Control(pDX, IDC_EDIT8, m_EDIT3);
	DDX_Control(pDX, IDC_EDIT10, m_EDIT4);
	DDX_Control(pDX, IDC_EDIT16, m_EDIT5);
	if (this->str == "更新")
	{
		m_EDIT1.SetWindowTextW((CString)to_string(this->medicalRecord.record_id).c_str());
		m_EDIT1.SetReadOnly(TRUE);
		m_EDIT2.SetWindowTextW((CString)to_string(this->medicalRecord.pet_id).c_str());
		m_EDIT3.SetWindowTextW((CString)this->medicalRecord.symptom.c_str());
		m_EDIT4.SetWindowTextW((CString)this->medicalRecord.diagnosis.c_str());
		m_EDIT5.SetWindowTextW((CString)this->medicalRecord.medical_expense.c_str());
	}

}


BEGIN_MESSAGE_MAP(PetMedicalRecordRegistration, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &PetMedicalRecordRegistration::OnBnClickedButton1)
END_MESSAGE_MAP()


// PetMedicalRecordRegistration 消息处理程序


void PetMedicalRecordRegistration::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (this->str == "更新")
	{
		CString strText;
		MedicalRecord   metp;
		string str ;
		metp.record_id = this->medicalRecord.record_id;
		m_EDIT2.GetWindowText(strText);
		str = (LPCSTR)(CStringA)strText;
		metp.pet_id = stoi(str);
		m_EDIT3.GetWindowText(strText);
		metp.symptom = (LPCSTR)(CStringA)strText;
		m_EDIT4.GetWindowText(strText);
		metp.diagnosis = (LPCSTR)(CStringA)strText;
		m_EDIT5.GetWindowText(strText);
		metp.medical_expense = (LPCSTR)(CStringA)strText;

		C_InfoFile file;

		str = "UPDATE medicalrecord SET PetId=" + to_string(metp.pet_id) +
			", Symptoms='" + metp.symptom +
			"', Diagnosis='" + metp.diagnosis +
			"', MedicalFee=" + metp.medical_expense+
			"  WHERE  MedicalRecordId = " + to_string(this->medicalRecord.record_id);

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
		MedicalRecord   metp;
		m_EDIT1.GetWindowText(strText);
		string str = (LPCSTR)(CStringA)strText;
		metp.record_id = stoi(str);
		m_EDIT2.GetWindowText(strText);
		str = (LPCSTR)(CStringA)strText;
		metp.pet_id = stoi(str);
		m_EDIT3.GetWindowText(strText);
		metp.symptom = (LPCSTR)(CStringA)strText;
		m_EDIT4.GetWindowText(strText);
		metp.diagnosis = (LPCSTR)(CStringA)strText;
		m_EDIT5.GetWindowText(strText);
		metp.medical_expense = (LPCSTR)(CStringA)strText;

		C_InfoFile file;

		str = "INSERT INTO medicalrecord(MedicalRecordId,PetId, Symptoms, Diagnosis,MedicalFee) VALUES(" + to_string(metp.record_id) + "," + "'" + to_string(metp.pet_id) + "'" + "," + "'" + metp.symptom + "'" + "," + "'" + metp.diagnosis + "'" + "," + metp.medical_expense + ")";

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

void PetMedicalRecordRegistration::SetMedicalRecord(MedicalRecord medicalRecord)
{
	this->medicalRecord = medicalRecord;
}
