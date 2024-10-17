#ifndef NHANVIEN_H
#define NHANVIEN_H

#include "User.h"
#include "SanPham.h"
#include <vector>

class NhanVien : public User {
private:
    string lichLamViec; // Lưu danh sách ca làm việc đã đăng ký
    vector<SanPham*> khoHang; // Lưu các sản phẩm mà nhân viên quản lý

public:
    NhanVien(const string& ten, const string& matKhau, const string& lichLamViec);

    int getSoCaDaLam() const; // Hàm lấy số ca đã làm
    string getTenNguoiDung() const; // Hàm lấy tên người dùng

    void nhapSanPham(SanPham* sanPham, int soLuong);
    void xoaSanPham(SanPham* sanPham, int soLuong);
    void dangKyCaLam(const vector<string>& ca); // Hàm đăng ký ca làm việc
    void hienThiThongTin() const override; // Implement hàm ảo từ User
};

#endif // NHANVIEN_H
