#ifndef USER_H
#define USER_H

#include <string>
#include <cstdlib>
#include <thread>
#include "Date.h"
#include "LinkedList.h"
#include <list>

inline void clearScreen() {
#ifdef _WIN32
    system("cls");
#endif
}

using namespace std;

class User {
protected:
    string ten;     
    string matKhau;  

public:
    User(const string& ten, const string& matKhau); 
    virtual void hienThiThongTin() const = 0; 
    string getTen() const; 
    string getMatKhau() const; 
};

#endif // USER_H
