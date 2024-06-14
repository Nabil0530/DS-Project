#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;
class Node
{
public:
    string Emp_Id, Name, Post, Department;
    float Salary;
    Node *Next_Add;
};
class Employee
{
private:
    Node *Head;

public:
    Employee();
    void Introduction();
    void Login();
    void Control_Panel();
    void Insert();
    void Search_Id();
    void Edit();
    void Del();
    void Display();
    void Salary_Slip();
    void Search_Dept();
};

Employee::Employee()
{
    Head = NULL;
}
void Employee::Introduction()
{
    system("cls");
    cout << "\n\n\n\n\n\n\n";
    cout << "\t\t\t==============================";
    cout << "\n\t\t\t==============================";
    cout << "\n\n\t\t\t  EMPLOYEE MANAGEMENT SYSTEM";
    cout << "\n\n\n\t\t\t\tVERSION : 1.1";
    cout << "\n\n\t\t\t==============================";
    cout << "\n\t\t\t==============================";
    getch();
}
void Employee::Login()
{
p:
    system("cls");
    string user, pass;
    cout << "\n\n";
    cout << "\t\t\t==========================";
    cout << "\n\n\t\t\t\tLOGIN PANEL";
    cout << "\n\n\t\t\t==========================";
    cout << "\n\n\n ENTER USER NAME: ";
    cin >> user;
    cout << "\n\n ENTER PASSWORD: ";
    for (int i = 1; i <= 6; i++)
    {
        pass += getch();
        cout << "*";
    }
    if (user == "Nabil@gmail.com" && pass == "123456")
    {
        cout << "\n\n\n\t\t\tCONGRATULATIONS LOGIN SUCCESS";
        cout << "\n\n\n\t\t\t\tLOADING";
        for (int i = 1; i <= 6; i++)
        {
            Sleep(500);
            cout << ".";
        }
        Control_Panel();
    }
    else if (user != "r.a.ifty2001@gmail.com" && pass == "123456")
    {
        cout << "\n\n\n USER NAME IS WRONG....";
    }
    else if (user == "r.a.ifty2001@gmail.com" && pass != "123456")
    {
        cout << "\n\n\n PASSWORD IS WRONG....";
    }
    else
    {
        cout << "\n\n\n USER NAME & PASSWORD ARE WRONG....";
    }
    getch();
    goto p;
}

void Employee::Control_Panel()
{
p:
    system("cls");
    int x;
    cout << "\n\n\t\t\t==========================";
    cout << "\n\n\t\t\t  EMPLOYEE CONTROL PANEL";
    cout << "\n\n\t\t\t==========================";
    cout << "\n\n\n 1. INSERT RECORD";
    cout << "\n 2. SEARCH RECORD";
    cout << "\n 3. EDIT RECORD";
    cout << "\n 4. DELETE RECORD";
    cout << "\n 5. DISPLAY RECORD";
    cout << "\n 6. SALARY SLIP";
    cout << "\n 7. SEARCH DEPARTMENT";
    cout << "\n 8. EXIT";
    cout << "\n\n YOUR CHOICE";
    cin >> x;
    switch (x)
    {
    case 1:
        Insert();
        break;
    case 2:
        Search_Id();
        break;
    case 3:
        Edit();
        break;
    case 4:
        Del();
        break;
    case 5:
        Display();
        break;
    case 6:
        Salary_Slip();
        break;
    case 7:
        Search_Dept();
        break;
    case 8:
        exit(0);
    default:
        cout << "\n\n ***INVALID CHOICE...PLEASE TRY AGAIN***";
    }
    getch();
    goto p;
}
void Employee::Insert()
{
p:
    system("cls");
    Node *New_Node = new Node;
    cout << "\n\n\t\t\t==========================";
    cout << "\n\n\t\t\t  INSERT EMPLOYEE RECORD";
    cout << "\n\n\t\t\t==========================";
    cout << "\n\n EMPLOYEE ID: ";
    cin >> New_Node->Emp_Id;
    cout << "\n\n EMPLOYEE NAME: ";
    cin >> New_Node->Name;
    cout << "\n\n EMPLOYEE POST: ";
    cin >> New_Node->Post;
    cout << "\n\n EMPLOYEE DEPARTMENT: ";
    cin >> New_Node->Department;
    cout << "\n\n EMPLOYEE SALARY: ";
    cin >> New_Node->Salary;
    New_Node->Next_Add = NULL;
    if (Head == NULL)
    {
        Head = New_Node;
    }
    else
    {
        Node *ptr = Head;
        while (ptr != NULL)
        {
            if (New_Node->Emp_Id == ptr->Emp_Id)
            {
                cout << "\n\n ***DUPLICATE EMPLOYEE RECORD***";
                delete New_Node;
                getch();
                goto p;
            }
            ptr = ptr->Next_Add;
        }
        ptr = Head;
        while (ptr->Next_Add != NULL)
        {
            ptr = ptr->Next_Add;
        }
        ptr->Next_Add = New_Node;
    }
    cout << "\n\n ***EMPLOYEE RECORD INSERTED***";
}
void Employee::Search_Id()
{
    system("cls");
    int found = 0;
    string EmpId;
    cout << "\n\n\t\t\t==========================";
    cout << "\n\n\t\t\t  SEARCH EMPLOYEE RECORD";
    cout << "\n\n\t\t\t==========================";
    if (Head == NULL)
    {
        cout << "\n\n ***LINKED LIST IS EMPTY***";
    }
    else
    {
        cout << "\n\n EMPLOYEE ID FOR SEARCH";
        cin >> EmpId;
        Node *ptr = Head;
        while (ptr != NULL)
        {
            if (EmpId == ptr->Emp_Id)
            {
                system("cls");
                cout << "\n\n\t\t\t==========================";
                cout << "\n\n\t\t\t  SEARCH EMPLOYEE RECORD";
                cout << "\n\n\t\t\t==========================";
                cout << "\n\n EMPLOYEE ID: " << ptr->Emp_Id;
                cout << "\n\n EMPLOYEE NAME: " << ptr->Name;
                cout << "\n\n EMPLOYEE POST: " << ptr->Post;
                cout << "\n\n EMPLOYEE DEPARTMENT: " << ptr->Department;
                cout << "\n\n EMPLOYEE SALARY: " << ptr->Salary;
                found++;
            }
            ptr = ptr->Next_Add;
        }
        if (found == 0)
        {
            cout << "\n\n ***EMPLOYEE ID NOT FOUND";
        }
    }
}
void Employee::Edit()
{
    system("cls");
    int found = 0;
    string EmpId;
    cout << "\n\n\t\t\t==========================";
    cout << "\n\n\t\t\t  MODIFY EMPLOYEE RECORD";
    cout << "\n\n\t\t\t==========================";
    if (Head == NULL)
    {
        cout << "\n\n ***LINKED LIST IS EMPTY***";
    }
    else
    {
        cout << "\n\n EMPLOYEE ID FOR MODIFY: ";
        cin >> EmpId;
        Node *ptr = Head;
        while (ptr != NULL)
        {
            if (EmpId == ptr->Emp_Id)
            {
                cout << "\n\n EMPLOYEE NAME: ";
                cin >> ptr->Name;
                cout << "\n\n EMPLOYEE POST: ";
                cin >> ptr->Post;
                cout << "\n\n EMPLOYEE DEPARTMENT: ";
                cin >> ptr->Department;
                cout << "\n\n EMPLOYEE SALARY: ";
                cin >> ptr->Salary;
                cout << "\n\n ***EMPLOYEE RECORD MODIFY***";
                found++;
            }
            ptr = ptr->Next_Add;
        }
        if (found == 0)
        {
            cout << "\n\n ***EMPLOYEE ID NOT FOUND***";
        }
    }
}
void Employee::Del()
{
    system("cls");
    int found = 0;
    string EmpId;
    cout << "\n\n\t\t\t==========================";
    cout << "\n\n\t\t\t  DELETE EMPLOYEE RECORD";
    cout << "\n\n\t\t\t==========================";
    if (Head == NULL)
    {
        cout << "\n\n ***LINKED LIST IS EMPTY***";
    }
    else
    {
        cout << "\n\n EMPLOYEE ID FOR DELETION";
        cin >> EmpId;
        if (EmpId == Head->Emp_Id)
        {
            Node *ptr = Head;
            Head = Head->Next_Add;
            delete ptr;
            cout << "\n\n ***EMPLOYEE RECORD DELETED***";
        }
        else
        {
            Node *pre = Head;
            Node *ptr = Head;
            while (ptr != NULL)
            {
                if (EmpId == ptr->Emp_Id)
                {
                    pre->Next_Add = ptr->Next_Add;
                    cout << "\n\n ***EMPLOYEE RECORD DELETED***";
                    found++;
                    break;
                }
                pre = ptr;
                ptr = ptr->Next_Add;
            }
            if (found == 0)
            {
                cout << "\n\n ***EMPLOYEE ID NOT FOUND***";
            }
        }
    }
}
void Employee::Display()
{
    system("cls");
    cout << "\n\n\t\t\t==========================";
    cout << "\n\n\t\t\t  DISPLAY EMPLOYEE RECORD";
    cout << "\n\n\t\t\t==========================";
    if (Head == NULL)
    {
        cout << "\n\n ***LINKED LIST IS EMPTY***";
    }
    else
    {
        Node *ptr = Head;
        while (ptr != NULL)
        {
            cout << "\n\n EMPLOYEE ID: " << ptr->Emp_Id;
            cout << "\n\n EMPLOYEE NAME: " << ptr->Name;
            cout << "\n\n EMPLOYEE POST: " << ptr->Post;
            cout << "\n\n EMPLOYEE DEPARTMENT: " << ptr->Department;
            cout << "\n\n EMPLOYEE SALARY: " << ptr->Salary;
            cout << "\n\n ==========================";
            cout << "\n ==========================";
            ptr = ptr->Next_Add;
        }
    }
}
void Employee::Salary_Slip()
{
    system("cls");
    int found = 0;
    string EmpId;
    cout << "\n\n\t\t\t==========================";
    cout << "\n\n\t\t\t  SALARY SLIP GENERATOR";
    cout << "\n\n\t\t\t==========================";
    if (Head == NULL)
    {
        cout << "\n\n ***LINKED LIST IS EMPTY***";
    }
    else
    {
        cout << "\n\n EMPLOYEE ID FOR SLIP: ";
        cin >> EmpId;
        Node *ptr = Head;
        while (ptr != NULL)
        {
            if (EmpId == ptr->Emp_Id)
            {
                system("cls");
                cout << "\n\t\t\t*********************************";
                cout << "\n\t\t\t*                               *";
                cout << "\n\t\t\t*      EMPLOYEE SALARY SLIP     *";
                cout << "\n\t\t\t*                               *";
                cout << "\n\t\t\t*********************************";
                cout << "\n\n\t\t\t EMPLOYEE ID:         " << ptr->Emp_Id;
                cout << "\n\n\t\t\t Name:                " << ptr->Name;
                cout << "\n\n\t\t\t Post:                " << ptr->Post;
                cout << "\n\n\t\t\t DEPARTMENT:          " << ptr->Department;
                cout << "\n\n\t\t\t SALARY:              " << ptr->Salary;
                cout << "\n\n\t\t\t*********************************";
                cout << "\n\t\t\t*********************************";
                found++;
            }
            ptr = ptr->Next_Add;
        }
        if (found == 0)
        {
            cout << "\n\n ***EMPLOYEE ID NOT FOUND";
        }
    }
}
void Employee::Search_Dept()
{
    system("cls");
    int found = 0;
    string dept;
    cout << "\n\n\t\t\t============================";
    cout << "\n\n\t\t\t  SEARCH DEPARTMENT RECORD";
    cout << "\n\n\t\t\t============================";
    if (Head == NULL)
    {
        cout << "\n\n ***LINKED LIST IS EMPTY***";
    }
    else
    {
        cout << "\n\n DEPARTMENT NAME FOR SEARCH: ";
        cin >> dept;
        Node *ptr = Head;
        while (ptr != NULL)
        {
            if (dept == ptr->Department)
            {
                cout << "\n\n EMPLOYEE ID: " << ptr->Emp_Id;
                cout << "\n\n EMPLOYEE NAME: " << ptr->Name;
                cout << "\n\n EMPLOYEE POST: " << ptr->Post;
                cout << "\n\n EMPLOYEE DEPARTMENT: " << ptr->Department;
                cout << "\n\n EMPLOYEE SALARY: " << ptr->Salary;
                cout << "\n\n ==========================";
                cout << "\n ==========================";
                found++;
            }
            ptr = ptr->Next_Add;
        }
        if (found == 0)
        {
            cout << "\n\n ***DEPARTMENT NAME NOT FOUND***";
        }
        else
        {
            cout << "\n\n TOTAL EMPLOYEE : " << found;
        }
    }
}
int main()
{
    Employee obj;
    obj.Introduction();
    obj.Login();
    return 0;
}