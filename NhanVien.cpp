#include "NhanVien.h"
#include <iostream>

NhanVien::NhanVien(const string& ten, const string& matKhau, const string& lichLamViec) 
    : User(ten, matKhau), lichLamViec(lichLamViec);

// Hàm trả về số ca đã làm
int NhanVien::getSoCaDaLam() const {
    return caLamViec.size(); // Trả về số lượng ca đã đăng ký
}

// Hàm lấy tên người dùng
string NhanVien::getTenNguoiDung() const {
    return ten;
}

// Hàm nhập thêm sản phẩm vào kho
void NhanVien::nhapSanPham(SanPham* sanPham, int soLuong) {
    // Kiểm tra xem sản phẩm đã tồn tại trong kho chưa
    bool daTonTai = false;
    for (auto& sp : khoHang) {
        if (sp == sanPham) { // So sánh địa chỉ sản phẩm
            sp->themSanPham(soLuong); // Cập nhật số lượng nếu đã có sản phẩm
            daTonTai = true;
            break;
        }
    }

    if (!daTonTai) {
        sanPham->themSanPham(soLuong); // Nếu chưa có sản phẩm trong kho, thêm mới
        khoHang.push_back(sanPham); // Thêm sản phẩm vào kho của nhân viên
    }

    cout << "Đã nhập " << soLuong << " sản phẩm vào kho." << endl;
}

// Hàm xóa sản phẩm khỏi kho
void NhanVien::xoaSanPham(SanPham* sanPham, int soLuong) {
    int slHienTai = sanPham->getSoLuong(); // Sử dụng getter để lấy số lượng hiện tại
    if (slHienTai >= soLuong) {
        sanPham->setSoLuong(slHienTai - soLuong); // Sử dụng setter để cập nhật số lượng
        cout << "Đã xóa " << soLuong << " sản phẩm khỏi kho." << endl;
    } else {
        cout << "Không đủ số lượng sản phẩm để xóa." << endl;
    }
    if (sanPham->getSoLuong() <= 0) {
        cout << "Sản phẩm đã hết hàng." << endl;
    }
}

// Hàm đăng ký ca làm việc cho nhân viên
void NhanVien::dangKyCaLam(const vector<string>& ca) {
    if (ca.size() >= 1 && ca.size() <= 5) {
        caLamViec = ca;
        cout << "Đã đăng ký ca làm việc thành công." << endl;
    } else {
        cout << "Số ca đăng ký không hợp lệ. Chọn ít nhất 1 và tối đa 5 ca." << endl;
    }
}

// Hiển thị thông tin của nhân viên
void NhanVien::hienThiThongTin() const {
    cout << "Nhân viên: " << getTenNguoiDung() << endl; // Sử dụng hàm getTenNguoiDung()
    cout << "Số ca làm việc đã đăng ký: " << getSoCaDaLam() << endl;
}
