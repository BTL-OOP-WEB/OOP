#ifndef GIAMDOC_H
#define GIAMDOC_H

#include "User.h"
#include "NhanVien.h"
#include <vector>

class GiamDoc : public User {
public:
    GiamDoc(const string& ten, const string& matKhau);

    void diemDanhNhanVien(const vector<NhanVien*>& dsNhanVien);
    void xuatLuongNhanVien(NhanVien* nhanVien); // 1 ca là 100k
    void hienThiThongTin() const override; // Implement hàm ảo từ User
};

#endif // GIAMDOC_H
