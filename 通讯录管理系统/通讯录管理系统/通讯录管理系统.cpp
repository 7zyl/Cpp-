#include<iostream>
#include<string>
using namespace std;
#define MAX 1000

//联系人结构体
struct Person {
	string m_name;
	int m_sex;								//1表示男，2表示女
	int m_age;
	string m_phone;
	string m_address;
};

//通讯录结构体
struct Addressbooks {
	struct Person personArray[MAX];		//通讯录中保存的联系人数组
	int m_size;											//通讯录中当前记录联系人个数,
};

//添加联系人
void AddPerson(Addressbooks* abs)
{
	//判断通讯录是否已满
	if (abs->m_size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;

		//性别
		int sex = 0;
		cout << "请输入性别：" << endl;
		cout << "男---1" << endl;
		cout << "女---2" << endl;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "输入错误，请重新输入" << endl;
		}

		//年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->m_size].m_age = age;

		//电话
		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;

		//家庭地址
		string address;
		cout << "请输入地址：" << endl;
		cin >> address;
		abs->personArray[abs->m_size].m_address = address;

		abs->m_size++;													//添加下一位联系人，序号++
		cout << "添加成功" << endl;
		system("pause");													//请点击任意键继续
		system("cls");														//清屏
	}
}

//显示联系人
void ShowPerson(Addressbooks* abs)
{
	if (abs->m_size == 0)												//检测通讯录是否为空
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_name << "\t";
			cout << "性别：" << (abs->personArray[i].m_sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_age << "\t";
			cout << "电话：" << abs->personArray[i].m_phone << "\t";
			cout << "地址：" << abs->personArray[i].m_address << endl;
		}
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在，存在返回联系人数组下标编号，不存在返回-1
int IsExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}

//删除联系人
void DeletePerson(Addressbooks* abs)
{
	cout << "请输入要删除的联系人：" << endl;
	string name;
	cin >> name;
	if (IsExist(abs, name) == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		for (int i = IsExist(abs, name); i < abs->m_size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
			abs->m_size--;
		}
		cout << "删除成功" << endl;
		system("pause");
		system("cls");
	}
}

//查找联系人
void FindPerson(Addressbooks* abs)
{
	cout << "请输入想查找的联系人：" << endl;
	string name;
	cin >> name;
	if (IsExist(abs, name) == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << "找到了" << endl;
		cout << "姓名：" << abs->personArray[IsExist(abs, name)].m_name << "\t";
		cout << "性别：" << (abs->personArray[IsExist(abs, name)].m_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[IsExist(abs, name)].m_age << "\t";
		cout << "电话：" << abs->personArray[IsExist(abs, name)].m_phone << "\t";
		cout << "地址：" << abs->personArray[IsExist(abs, name)].m_address << endl;
	}
	system("pause");
	system("cls");
}

//修改联系人
void ModifyPerson(Addressbooks* abs)
{
	cout << "请输入要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = IsExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		//修改姓名
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_name = name;

		//修改性别
		int sex = 0;
		cout << "请输入性别：" << endl;
		cout << "男---1" << endl;
		cout << "女---2" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_sex = sex;
				break;
			}
			cout << "输入错误，请重新输入" << endl;
		}

		//修改年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_age = age;

		//修改电话
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_phone = phone;

		//修改地址
		cout << "请输入地址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_address = address;

		cout << "修改成功" << endl;
	}
	system("pause");
	system("cls");
}

//清空联系人
void CleanPerson(Addressbooks* abs)
{
	abs->m_size = 0;			//将当期记录联系人数量置为0，做逻辑清空
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}

void showMenu()														//菜单功能
{
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
}


int main()
{
	Addressbooks abs;			//创建通讯录结构体变量
	abs.m_size = 0;				//初始化通讯录中当前人员个数,即第一个联系人序号0

	int select = 0;					//创建用户选择输入的变量
	while (1)
	{
		showMenu();				//展示菜单
		cout << "请输入想要实现的功能：";
		cin >> select;
		switch (select)
		{
		case 1:
			AddPerson(&abs);		//利用地址传递，可以修饰实参
			break;
		case 2:
			ShowPerson(&abs);
			break;
		case 3:
			DeletePerson(&abs);
			break;
		case 4:
			FindPerson(&abs);
			break;
		case 5:
			ModifyPerson(&abs);
			break;
		case 6:
			CleanPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
