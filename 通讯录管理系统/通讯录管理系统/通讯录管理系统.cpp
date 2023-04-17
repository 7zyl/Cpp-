#include<iostream>
#include<string>
using namespace std;
#define MAX 1000

//��ϵ�˽ṹ��
struct Person {
	string m_name;
	int m_sex;								//1��ʾ�У�2��ʾŮ
	int m_age;
	string m_phone;
	string m_address;
};

//ͨѶ¼�ṹ��
struct Addressbooks {
	struct Person personArray[MAX];		//ͨѶ¼�б������ϵ������
	int m_size;											//ͨѶ¼�е�ǰ��¼��ϵ�˸���,
};

//�����ϵ��
void AddPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;

		//�Ա�
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "��---1" << endl;
		cout << "Ů---2" << endl;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "�����������������" << endl;
		}

		//����
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[abs->m_size].m_age = age;

		//�绰
		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;

		//��ͥ��ַ
		string address;
		cout << "�������ַ��" << endl;
		cin >> address;
		abs->personArray[abs->m_size].m_address = address;

		abs->m_size++;													//�����һλ��ϵ�ˣ����++
		cout << "��ӳɹ�" << endl;
		system("pause");													//�������������
		system("cls");														//����
	}
}

//��ʾ��ϵ��
void ShowPerson(Addressbooks* abs)
{
	if (abs->m_size == 0)												//���ͨѶ¼�Ƿ�Ϊ��
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������" << abs->personArray[i].m_name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_age << "\t";
			cout << "�绰��" << abs->personArray[i].m_phone << "\t";
			cout << "��ַ��" << abs->personArray[i].m_address << endl;
		}
	}
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ���ڣ����ڷ�����ϵ�������±��ţ������ڷ���-1
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

//ɾ����ϵ��
void DeletePerson(Addressbooks* abs)
{
	cout << "������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	if (IsExist(abs, name) == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		for (int i = IsExist(abs, name); i < abs->m_size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
			abs->m_size--;
		}
		cout << "ɾ���ɹ�" << endl;
		system("pause");
		system("cls");
	}
}

//������ϵ��
void FindPerson(Addressbooks* abs)
{
	cout << "����������ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	if (IsExist(abs, name) == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		cout << "�ҵ���" << endl;
		cout << "������" << abs->personArray[IsExist(abs, name)].m_name << "\t";
		cout << "�Ա�" << (abs->personArray[IsExist(abs, name)].m_sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[IsExist(abs, name)].m_age << "\t";
		cout << "�绰��" << abs->personArray[IsExist(abs, name)].m_phone << "\t";
		cout << "��ַ��" << abs->personArray[IsExist(abs, name)].m_address << endl;
	}
	system("pause");
	system("cls");
}

//�޸���ϵ��
void ModifyPerson(Addressbooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = IsExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		//�޸�����
		cout << "������������" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_name = name;

		//�޸��Ա�
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "��---1" << endl;
		cout << "Ů---2" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_sex = sex;
				break;
			}
			cout << "�����������������" << endl;
		}

		//�޸�����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_age = age;

		//�޸ĵ绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_phone = phone;

		//�޸ĵ�ַ
		cout << "�������ַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_address = address;

		cout << "�޸ĳɹ�" << endl;
	}
	system("pause");
	system("cls");
}

//�����ϵ��
void CleanPerson(Addressbooks* abs)
{
	abs->m_size = 0;			//�����ڼ�¼��ϵ��������Ϊ0�����߼����
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}

void showMenu()														//�˵�����
{
	cout << "**************************" << endl;
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
}


int main()
{
	Addressbooks abs;			//����ͨѶ¼�ṹ�����
	abs.m_size = 0;				//��ʼ��ͨѶ¼�е�ǰ��Ա����,����һ����ϵ�����0

	int select = 0;					//�����û�ѡ������ı���
	while (1)
	{
		showMenu();				//չʾ�˵�
		cout << "��������Ҫʵ�ֵĹ��ܣ�";
		cin >> select;
		switch (select)
		{
		case 1:
			AddPerson(&abs);		//���õ�ַ���ݣ���������ʵ��
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
			cout << "��ӭ�´�ʹ��" << endl;
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
