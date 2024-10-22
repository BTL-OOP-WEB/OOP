#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>
#include <vector>
#include "declare/User.h"
#include "declare/SanPham.h"

struct Date {
    int ngay;
    int thang;
    int nam;

    Date(int d = 1, int m = 1, int y = 2000) : ngay(d), thang(m), nam(y) {}
};

class SanPham;

class NhanVien : public User {
private:
    string hoTen;        // Họ tên nhân viên
    Date ngaySinh;       // Ngày sinh của nhân viên
    string sdt;          // Số điện thoại
    string lichLamViec;  // Lưu danh sách ca làm việc đã đăng ký
    vector<SanPham*> khoHang; // Lưu các sản phẩm mà nhân viên quản lý

public:
    NhanVien(const string& ten, const string& matKhau, const string& hoTen, const Date& ngaySinh, const string& sdt, const string& lichLamViec);

    int getSoCaDaLam() const; // Hàm lấy số ca đã làm
    string getTenNguoiDung() const; // Hàm lấy tên người dùng

    void nhapSanPham(SanPham* sanPham, int soLuong);
    void xoaSanPham(SanPham* sanPham, int soLuong);
    void dangKyCaLam(); // Hàm đăng ký ca làm việc
    void hienThiThongTin() const override; // Implement hàm ảo từ User

    string getHoTen() const; // Hàm lấy họ tên
    Date getNgaySinh() const; // Hàm lấy ngày sinh
    string getSdt() const; // Hàm lấy số điện thoại
};

#endif // NHANVIEN_H
