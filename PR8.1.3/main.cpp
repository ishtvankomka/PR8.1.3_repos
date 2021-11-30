#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
bool Include(const char* s, const char* cs)
{
    const char* r = strstr(s, cs);
    if (r != NULL)
        return true;
    else
        return false;
}
char* Change(char* s, const char* cs)
{
    char* t = new char[strlen(s)];
    char* p;
    long int pos1 = 0;
    long int pos3 = 0;
    *t = 0;
    while (p = strstr(s + pos1, cs))
    {
        pos3 = p - s + 3;
        strncat(t, s + pos1, pos3 - pos1 - 3);
        strcat(t, "**");
        pos1 = pos3;
    }
    strcat(t, s + pos1);
    strcpy(s, t);
    return t;
}
int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    char cs1[] = "AGA";
    char cs2[] = "OGO";
    char a1[] = "Modified string (param) : ";
    char a2[] = "Modified string (result): ";
    if (Include(str, cs1) && Include(str, cs2))
    {
        cout << "yes" << endl;
        char* dest = Change(str, cs1);
        dest = Change(str, cs2);
        cout << a1 << str << endl;
        cout << a2 << dest << endl;
    }
    else
        if (Include(str, cs1))
        {
            cout << "yes" << endl;
            char* dest = Change(str, cs1);
            cout << a1 << str << endl;
            cout << a2 << dest << endl;
        }
    else
        if (Include(str, cs2))
        {
            cout << "yes" << endl;
            char* dest = Change(str, cs2);
            cout << a1 << str << endl;
            cout << a2 << dest << endl;
        }
        else
        {
            cout << "no" << endl;
            cout << a1 << str << endl;
            cout << a2 << str << endl;
        }
    return 0;
}
