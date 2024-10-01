#include <iostream>
#include <Windows.h>
using namespace std;

class MyString
{
//private
    char* str;
    int length;
public:
    MyString()
    {
        length = 80;
        str = new char[length];
    }

    MyString(const char* obj)
    {
        length = strlen(obj);
        str = new char[length + 1];
        strcpy_s(str, length + 1, obj);
    }

    MyString(const MyString& obj)
    {
        length = obj.length;
        str = new char[length + 1];
        strcpy_s(str, length + 1, obj.str);
    }

    ~MyString()
    {
        delete[] str;
    }
    void Print()
    {
        cout << str << endl;
    }
};


int main()
{
    MyString obj1("Hello");
    obj1.Print();

    MyString obj2(obj1);
    obj2.Print();
}
