#include "NhanVien.h"
#include "SanPham.h"
#include <iostream>

using namespace std;

NhanVien::NhanVien(const string& ten, const string& matKhau, const string& lichLamViec) 
    : User(ten, matKhau), lichLamViec(lichLamViec) {}

// Hàm trả về số ca đã làm
int NhanVien::getSoCaDaLam() const {
    int soCaDaLam = 0;
    for (char c : lichLamViec) {
        if (c == '1') {
            soCaDaLam++;
        }
    }
    return soCaDaLam; // Trả về số lượng ca đã đăng ký
}

// Hàm lấy tên người dùng
string NhanVien::getTenNguoiDung() const {
    return ten; // Giả sử `ten` là thuộc tính trong lớp User
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
// Hàm đăng ký ca làm việc cho nhân viên
void NhanVien::dangKyCaLam() {
    lichLamViec.clear(); // Khởi tạo lại chuỗi lịch làm việc

    cout << "Nhập lịch làm việc (8 ký tự, từ trái qua phải: CN, T2, T3, T4, T5, T6, T7): ";
    cin >> lichLamViec;

    // Kiểm tra độ dài chuỗi
    if (lichLamViec.length() != 8) {
        cout << "Lịch làm việc không hợp lệ! Vui lòng nhập 8 ký tự." << endl;
        return;
    }

    // Kiểm tra các ký tự có phải là '0' hoặc '1' không
    for (char c : lichLamViec) {
        if (c != '0' && c != '1') {
            cout << "Lịch làm việc không hợp lệ! Vui lòng nhập chỉ '0' hoặc '1'." << endl;
            return; // Thoát nếu có ký tự không hợp lệ
        }
    }

    this->lichLamViec = lichLamViec; // Cập nhật lịch làm việc
    cout << "Đã đăng ký lịch làm việc thành công: " << lichLamViec << endl;
}

void NhanVien::hienThiThongTin() const {
    cout << "Ten: " << ten << ", Mat khau: " << matKhau << ", Lich lam viec: " << lichLamViec << endl;
}