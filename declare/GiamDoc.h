#ifndef GIAMDOC_H
#define GIAMDOC_H

#include <vector>
#include "User.h"
#include "SanPham.h" 
#include "NhanVien.h"

class NhanVien;

class GiamDoc : public User {
public:
    GiamDoc(const string& ten, const string& matKhau);

    void diemDanhNhanVien(const vector<NhanVien*>& dsNhanVien);
    void xuatLuongNhanVien(NhanVien* nhanVien); 
    void hienThiThongTin() const override; 
    void xuatDanhSachNhanVien(const vector<NhanVien*>& dsNhanVien);
};

#endif // GIAMDOC_H
