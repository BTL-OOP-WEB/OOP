#include "User.h"

User::User(const string& ten, const string& matKhau) : ten(ten), matKhau(matKhau) {} 

// Hàm trả về tên người dùng
string User::getTen() const {
    return ten;
}

// Hàm trả về mật khẩu người dùng
string User::getMatKhau() const { 
    return matKhau;
}

