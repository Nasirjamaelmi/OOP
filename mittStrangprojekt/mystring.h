#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

class Mystring
{
public:
    ~Mystring();
    Mystring();
    Mystring(const char*cstr);
    Mystring(const Mystring& otherString);
    Mystring(Mystring &&stringToMove);

    const Mystring& operator=(const Mystring& otherString);
    const Mystring& operator=(Mystring&& stringToMove);
    const Mystring& operator+=(const Mystring& otherString);

    bool operator==(const Mystring& otherString) const;
    char& operator[](int ix);
    char  operator[](int ix) const;

    int size() const;
    const char* c_str() const;
private:
    char* m_cstr;
    int m_size;
};

bool operator !=(const Mystring& a, const Mystring& b);


std::ostream& operator<<(std::ostream& out, const Mystring& str);

#endif // MYSTRING_H
