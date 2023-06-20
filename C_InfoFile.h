#pragma once
#include<iostream>
#include<string>
#include <vector>
#include"mysql.h"
#include <list>
using namespace std;
// 数据库连接参数
static const char* host = "localhost";  // 数据库主机名为本地
static const char* user = "root";  // 数据库用户名为root
static const char* passwd = "zhong1020";  // 数据库密码为123456
static const char* db = "yunting_data";  // 连接的数据库名称为yunting_宠物管理系统
static const unsigned int port = 3306;  // 连接的数据库端口号为3306
static MYSQL mysql;
//连接数据库
static  bool connect_db() {
	mysql_init(&mysql);
	mysql_set_character_set(&mysql, "utf8");//ͬһ�ַ���
	if (!mysql_real_connect(&mysql, host, user, passwd, db, port, NULL, 0)) {
		cerr << "Error: " << mysql_error(&mysql) << endl;
		return false;
	}
	return true;
}
// 关闭数据库连接
static  void close_db() {
	mysql_close(&mysql);
}
// 执行SQL命令
static bool execute_sql(const string& sql) {
	if (mysql_query(&mysql, sql.c_str())) {
		cerr << "Error: " << mysql_error(&mysql) << endl;
		return false;
	}
	return true;
}
// 会员表Member
struct Member {
	int member_id;      // 会员编号
	string name;        // 姓名
	string phone_num;   // 手机号码
	string address;     // 地址
};
// 宠物表Pet
struct Pet {
	int pet_id;         // 宠物编号
	string pet_name;    // 宠物名称
	string breed;       // 品种
	string gender;      // 性别
	int age;            // 年龄
};
// 医疗病历表MedicalRecord
struct MedicalRecord {
	int record_id;      // 病历编号
	int pet_id;         // 宠物编号
	string symptom;     // 症状
	string diagnosis;   // 诊断结果
	string medical_expense;  // 医疗费用
};
// 美容登记表Grooming
struct Grooming {
	int register_id;        // 登记编号
	int pet_id;             // 宠物编号
	string grooming_date;   // 美容日期
	string grooming_expense; // 美容费用
};
// 寄养登记表Boarding
struct Boarding {
	int register_id;                // 登记编号
	int pet_id;                     // 宠物编号
	string boarding_start_date;     // 寄养起始时间
	string boarding_end_date;       // 寄养结束时间
	string boarding_expense;         // 寄养费用
};
// 销售记录表SalesRecord
struct SalesRecord {
	int sale_id;            // 销售编号
	int pet_id;             // 宠物编号
	string sale_date;       // 销售日期
	string sale_price;       // 销售价格
};
//管理员用户表users
struct users
{
	string username;//用户名
	string password;//密码
};
class C_InfoFile
{
public:
	C_InfoFile();
	~C_InfoFile();
	vector<Member> lies1;
	vector<Pet> lies2;
	vector<MedicalRecord> lies3;
	vector<Grooming> lies4;
	vector<Boarding> lies5;
	vector<SalesRecord> lies6;
	vector<users> lies7;
	void GitMember();
	void GitPet();
	void GitMedicalRecord();
	void GitGrooming();
	void GitBoarding();
	void GitSalesRecord();
	void GitUsers();
};