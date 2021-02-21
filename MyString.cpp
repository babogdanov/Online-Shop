#include "MyString.h"
using namespace std;
MyString::MyString()
{
    content = new char[1];
    content[0] = '\0';
}

MyString::MyString(const char* input)
{
    int len = strlen(input);
    this->content = new char[len + 1];

    strcpy(this->content, input);
    this->content[len] = '\0';
}
MyString::MyString(const MyString& from)
{
    int len = strlen(from.content);
    this->content = new char[len + 1];
    strcpy(this->content, from.content);
    this->content[len] = '\0';
}

MyString& MyString::operator=(const MyString& from)
{
    if (this != &from)
    {
        delete[] content;

        int len = strlen(from.content);
        this->content = new char[len + 1];
        strcpy(this->content, from.content);
        this->content[len] = '\0';
    }
    return *this;
}

MyString::~MyString()
{
    delete[] this->content;
}

char* MyString::getContent() const
{
    return this->content;
}
void MyString::append(char to_append)
{
    int len = strlen(this->content);
    char* new_content = new char[len + 2];
    strcpy(new_content, this->content);
    new_content[len] = to_append;
    new_content[len + 1] = '\0';
    delete[] this->content;
    this->content = new_content;
}

void MyString::print()
{
    std::cout << this->content << std::endl;
}

std::ostream& operator <<(std::ostream& out, const MyString& string)
{
    for (int i = 0; string.content[i] != '\0'; i++)
    {
        out << string.content[i];
    }
    return out;
}

std::istream& operator >>(std::istream& in, MyString& string)
{

    char c;
    do
    {
        cin.get(c);
        string.append(c);
    } while (c != '\n');

    return in;
}