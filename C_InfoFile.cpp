#include "pch.h"
#include "C_InfoFile.h"
C_InfoFile::C_InfoFile()
{

}
C_InfoFile::~C_InfoFile()
{

}
//获取会员信息
void C_InfoFile::GitMember()
{
	connect_db();

	if (!this->lies1.empty()) {
		this->lies1.clear();
	}
	string query_str = "SELECT * FROM member";
	vector<vector<string>> results; // 存储结果集的二维 vector
	if (mysql_query(&mysql, query_str.c_str())) {
		cerr << "Error: " << mysql_error(&mysql) << endl;
		return;
	}
	else {
		MYSQL_RES* res = mysql_use_result(&mysql);
		MYSQL_ROW row;
		while ((row = mysql_fetch_row(res))) {
			vector<string> temp;
			for (unsigned int i = 0; i < mysql_num_fields(res); ++i) {
				temp.push_back(row[i]);
			}
			results.push_back(temp);
		}
		mysql_free_result(res);
	}
	// 将结果集导入到 vector 中，并输出
	vector<vector<string>>::iterator it1;
	vector<string>::iterator it2;
	for (it1 = results.begin(); it1 != results.end(); ++it1) {
		Member temp;
		for (it2 = it1->begin(); it2 != it1->end(); ++it2)
		{
			temp.member_id = stoi(*it2);
			++it2;
			temp.name = *it2;
			++it2;
			temp.phone_num = *it2;
			++it2;
			temp.address = *it2;
		}
		this->lies1.push_back(temp);
	}
	close_db();
	/*vector<Member>::iterator it3;
	for (it3 = lies1.begin(); it3 != lies1.end(); ++it3)
	{
		cout << it3->member_id << '\t' << it3->phone_num << '\t' << it3->name << '\t' << it3->address << endl;
	}*/
}
//获取宠物信息
void C_InfoFile::GitPet()
{
	connect_db();
	if (!lies2.empty()) {
		lies2.clear();
	}
	string query_str = "SELECT * FROM pet";
	vector<vector<string>> results; // 存储结果集的二维 vector
	if (mysql_query(&mysql, query_str.c_str())) {
		cerr << "Error: " << mysql_error(&mysql) << endl;
		return;
	}
	else {
		MYSQL_RES* res = mysql_use_result(&mysql);
		MYSQL_ROW row;
		while ((row = mysql_fetch_row(res))) {
			vector<string> temp;
			for (unsigned int i = 0; i < mysql_num_fields(res); ++i) {
				temp.push_back(row[i]);
			}
			results.push_back(temp);
		}
		mysql_free_result(res);
	}
	// 将结果集导入到 vector 中，并输出
	vector<vector<string>>::iterator it1;
	vector<string>::iterator it2;
	for (it1 = results.begin(); it1 != results.end(); ++it1) {
		Pet temp;
		for (it2 = it1->begin(); it2 != it1->end(); ++it2)
		{
			temp.pet_id = stoi(*it2);
			++it2;
			temp.pet_name = *it2;
			++it2;
			temp.breed = *it2;
			++it2;
			temp.gender = *it2;
			++it2;
			temp.age = stoi(*it2);
		}
		lies2.push_back(temp);
	}
	/*vector<Pet>::iterator it3;
	for (it3 = lies2.begin(); it3 != lies2.end(); ++it3)
	{
		cout << it3->pet_id << '\t' << it3->pet_name << '\t' << it3->breed << '\t' << it3->gender << '\t' << it3->age << endl;
	}*/

	close_db();
}
//获取医疗病例信息
void C_InfoFile::GitMedicalRecord()
{
	connect_db();

	if (!lies3.empty()) {
		lies3.clear();
	}
	string query_str = "SELECT * FROM MedicalRecord";
	vector<vector<string>> results; // 存储结果集的二维 vector
	if (mysql_query(&mysql, query_str.c_str())) {
		cerr << "Error: " << mysql_error(&mysql) << endl;
		return;
	}
	else {
		MYSQL_RES* res = mysql_use_result(&mysql);
		MYSQL_ROW row;
		while ((row = mysql_fetch_row(res))) {
			vector<string> temp;
			for (unsigned int i = 0; i < mysql_num_fields(res); ++i) {
				temp.push_back(row[i]);
			}
			results.push_back(temp);
		}
		mysql_free_result(res);
	}
	// 将结果集导入到 vector 中，并输出
	vector<vector<string>>::iterator it1;
	vector<string>::iterator it2;
	for (it1 = results.begin(); it1 != results.end(); ++it1) {
		MedicalRecord temp;
		for (it2 = it1->begin(); it2 != it1->end(); ++it2)
		{
			temp.record_id = stoi(*it2);
			++it2;
			temp.pet_id = stoi(*it2);
			++it2;
			temp.symptom = *it2;
			++it2;
			temp.diagnosis = *it2;
			++it2;
			temp.medical_expense = *it2;
		}
		lies3.push_back(temp);
	}
	/*vector<MedicalRecord>::iterator it3;
	for (it3 = lies3.begin(); it3 != lies3.end(); ++it3)
	{
		cout << it3->record_id << '\t' << it3->pet_id << '\t' << it3->symptom << '\t' << it3->diagnosis << '\t' << it3->medical_expense << endl;
	}*/
	close_db();

}
//获取宠物美容信息
void C_InfoFile::GitGrooming()
{
	connect_db();
	{
		if (!lies4.empty()) {
			lies4.clear();
		}
		string query_str = "SELECT * FROM Grooming";
		vector<vector<string>> results; // 存储结果集的二维 vector
		if (mysql_query(&mysql, query_str.c_str())) {
			cerr << "Error: " << mysql_error(&mysql) << endl;
			return;
		}
		else {
			MYSQL_RES* res = mysql_use_result(&mysql);
			MYSQL_ROW row;
			while ((row = mysql_fetch_row(res))) {
				vector<string> temp;
				for (unsigned int i = 0; i < mysql_num_fields(res); ++i) {
					temp.push_back(row[i]);
				}
				results.push_back(temp);
			}
			mysql_free_result(res);
		}
		// 将结果集导入到 vector 中，并输出
		vector<vector<string>>::iterator it1;
		vector<string>::iterator it2;
		for (it1 = results.begin(); it1 != results.end(); ++it1) {
			Grooming temp;
			for (it2 = it1->begin(); it2 != it1->end(); ++it2)
			{
				temp.register_id = stoi(*it2);
				++it2;
				temp.pet_id = stoi(*it2);
				++it2;
				temp.grooming_date = *it2;
				++it2;
				temp.grooming_expense = *it2;
			}
			lies4.push_back(temp);
		}
		/*vector<Grooming>::iterator it3;
		for (it3 = lies4.begin(); it3 != lies4.end(); ++it3)
		{
			cout << it3->register_id << '\t' << it3->pet_id << '\t' << it3->grooming_date << '\t' << it3->grooming_expense << endl;
		}*/
	}
	close_db();
}
//获取寄养信息
void C_InfoFile::GitBoarding()
{
	connect_db();
	{
		if (!lies5.empty()) {
			lies5.clear();
		}
		string query_str = "SELECT * FROM Boarding";
		vector<vector<string>> results; // 存储结果集的二维 vector
		if (mysql_query(&mysql, query_str.c_str())) {
			cerr << "Error: " << mysql_error(&mysql) << endl;
			return;
		}
		else {
			MYSQL_RES* res = mysql_use_result(&mysql);
			MYSQL_ROW row;
			while ((row = mysql_fetch_row(res))) {
				vector<string> temp;
				for (unsigned int i = 0; i < mysql_num_fields(res); ++i) {
					temp.push_back(row[i]);
				}
				results.push_back(temp);
			}
			mysql_free_result(res);
		}
		// 将结果集导入到 vector 中，并输出
		vector<vector<string>>::iterator it1;
		vector<string>::iterator it2;
		for (it1 = results.begin(); it1 != results.end(); ++it1) {
			Boarding temp;
			for (it2 = it1->begin(); it2 != it1->end(); ++it2)
			{
				temp.register_id = stoi(*it2);
				++it2;
				temp.pet_id = stoi(*it2);
				++it2;
				temp.boarding_start_date = *it2;
				++it2;
				temp.boarding_end_date = *it2;
				++it2;
				temp.boarding_expense = *it2;
			}
			lies5.push_back(temp);
		}
		/*vector<Boarding>::iterator it3;
		for (it3 = lies5.begin(); it3 != lies5.end(); ++it3)
		{
			cout << it3->register_id << '\t' << it3->pet_id << '\t' << it3->boarding_start_date << '\t' << it3->boarding_end_date << '\t' << it3->boarding_expense << endl;
		}*/
	}
	close_db();
}
//获取销售信息
void C_InfoFile::GitSalesRecord()
{
	connect_db();
	{
		if (!lies6.empty()) {
			lies6.clear();
		}
		string query_str = "SELECT * FROM SalesRecord";
		vector<vector<string>> results; // 存储结果集的二维 vector
		if (mysql_query(&mysql, query_str.c_str())) {
			cerr << "Error: " << mysql_error(&mysql) << endl;
			return;
		}
		else {
			MYSQL_RES* res = mysql_use_result(&mysql);
			MYSQL_ROW row;
			while ((row = mysql_fetch_row(res))) {
				vector<string> temp;
				for (unsigned int i = 0; i < mysql_num_fields(res); ++i) {
					temp.push_back(row[i]);
				}
				results.push_back(temp);
			}
			mysql_free_result(res);
		}
		// 将结果集导入到 vector 中，并输出
		vector<vector<string>>::iterator it1;
		vector<string>::iterator it2;
		for (it1 = results.begin(); it1 != results.end(); ++it1) {
			SalesRecord temp;
			for (it2 = it1->begin(); it2 != it1->end(); ++it2)
			{
				temp.sale_id = stoi(*it2);
				++it2;
				temp.pet_id = stoi(*it2);
				++it2;
				temp.sale_date = *it2;
				++it2;
				temp.sale_price = *it2;
			}
			lies6.push_back(temp);
		}
		/*vector<SalesRecord>::iterator it3;
		for (it3 = lies6.begin(); it3 != lies6.end(); ++it3)
		{
			cout << it3->sale_id << '\t' << it3->pet_id << '\t' << it3->sale_date << '\t' << it3->sale_price << endl;
		}*/
	}
	close_db();
}
void C_InfoFile::GitUsers()
{
	connect_db();
	{
		if (!lies7.empty()) {
			lies7.clear();
		}
		string query_str = "SELECT * FROM users";
		vector<vector<string>> results; // 存储结果集的二维 vector
		if (mysql_query(&mysql, query_str.c_str())) {
			cerr << "Error: " << mysql_error(&mysql) << endl;
			return;
		}
		else {
			MYSQL_RES* res = mysql_use_result(&mysql);
			MYSQL_ROW row;
			while ((row = mysql_fetch_row(res))) {
				vector<string> temp;
				for (unsigned int i = 0; i < mysql_num_fields(res); ++i) {
					temp.push_back(row[i]);
				}
				results.push_back(temp);
			}
			mysql_free_result(res);
		}
		// 将结果集导入到 vector 中，并输出
		vector<vector<string>>::iterator it1;
		vector<string>::iterator it2;
		for (it1 = results.begin(); it1 != results.end(); ++it1) {
			users temp;
			for (it2 = it1->begin(); it2 != it1->end(); ++it2)
			{
				
				temp.username = *it2;
				++it2;
				temp.password = *it2;
			}
			lies7.push_back(temp);
		}
		/*vector<SalesRecord>::iterator it3;
		for (it3 = lies6.begin(); it3 != lies6.end(); ++it3)
		{
			cout << it3->sale_id << '\t' << it3->pet_id << '\t' << it3->sale_date << '\t' << it3->sale_price << endl;
		}*/
	}
	close_db();
}
