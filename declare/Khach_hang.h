#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <vector>
#include <string>
#include "User.h"
#include "SanPham.h"
#include "NhanVien.h"

using namespace std;

class KhachHang : public User {
private:
    vector<SanPham*> gioHang;  
    int diemTichLuy;           
    string hoTen;              
    Date ngaySinh;             
    string sdt;                

public:
    // Constructor cập nhật thêm các thuộc tính mới
    KhachHang(const string& ten, const string& matKhau, const int& diemTichLuy, const string& hoTen, const Date& ngaySinh, const string& sdt);

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
    SanPham* timSanPham(const std::string& tenSanPham, const std::vector<SanPham*>& danhSachSanPham) const;
    virtual string getTenSanPham() const;
};

#endif // KHACHHANG_H
