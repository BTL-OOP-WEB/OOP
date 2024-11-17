#include "../declare/User.h"
#include "../declare/Date.h"
#include "../declare/LinkedList.h"
#include <list>

User::User(const string& ten, const string& matKhau) : ten(ten), matKhau(matKhau) {} 

string User::getTen() const {
    return ten;
}

string User::getMatKhau() const { 
    return matKhau;
}

