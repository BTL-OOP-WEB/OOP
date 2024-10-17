#ifndef KHACHHANG_H
#define KHACHHANG_H

#include "User.h"
#include "SanPham.h"
#include <vector>

using namespace std;

class KhachHang : public User {
private:
    vector<SanPham*> gioHang;  // Giỏ hàng của khách hàng
    int diemTichLuy;           // Điểm tích lũy của khách hàng

public:
    KhachHang(const string& ten, const string& matKhau, const int& diemTichLuy);

    void themVaoGioHang(SanPham* sanPham, int soLuong);
    void boSanPham(SanPham* sanPham, int soLuong);
    
    void thanhToan();          // Hàm thanh toán với tích điểm
    void hienThiGioHang() const;
    void hienThiThongTin() const override; // Implement hàm ảo từ User
    
    void suDungDiem();         // Hàm cho khách hàng chọn sử dụng điểm để giảm tiền
    void xuatHoaDon() const;   // Xuất hóa đơn sau khi thanh toán

    // Khai báo hàm tìm sản phẩm trong giỏ hàng
    SanPham* timSanPhamTrongGioHang(const string& tenSanPham);
    // Khai báo hàm timSanPham
    SanPham* timSanPham(const string& tenSanPham, const vector<SanPham*>& dsSanPham);
    virtual string getTenSanPham() const;
};

#endif // KHACHHANG_H
