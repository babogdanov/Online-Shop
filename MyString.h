#pragma once
#include <cstring>
#include <iostream>
class MyString
{
private:
    char* content;
public:
    MyString();
    MyString(const char* input);

    MyString(const MyString& from);

    MyString& operator=(const MyString& from);

    ~MyString();

    char* getContent() const;
    void append(char to_append);
    void print();

    friend std::ostream& operator <<(std::ostream& out, const MyString&);
    friend std::istream& operator >>(std::istream& in, MyString&);
};

