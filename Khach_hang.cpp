#include <iostream>
#include <vector>
#include <string>
#include "Khach_hang.h"
#include "SanPham.h"

using namespace std;

KhachHang::KhachHang(const string& ten, const string& matKhau, const int& diemTichLuy) : User(ten, matKhau), diemTichLuy(diemTichLuy){}

void KhachHang::themVaoGioHang(SanPham* sanPham, int soLuong) {
    sanPham->themSanPham(soLuong);
    gioHang.push_back(sanPham);
    cout << "Đã thêm " << soLuong << " sản phẩm vào giỏ hàng." << endl;
}

void KhachHang::boSanPham(SanPham* sanPham, int soLuong) {
    for (auto it = gioHang.begin(); it != gioHang.end(); ++it) {
        if (*it == sanPham) {
            sanPham->banSanPham(soLuong);
            gioHang.erase(it);
            cout << "Đã xóa sản phẩm khỏi giỏ hàng." << endl;
            return;
        }
    }
    cout << "Không tìm thấy sản phẩm trong giỏ hàng." << endl;
}

void KhachHang::thanhToan() {
    double tongTien = 0.0;
    for (auto& sp : gioHang) {
        tongTien += sp->giaTien;
    }

    cout << "Tổng tiền trước khi áp dụng giảm giá: " << tongTien << " VND" << endl;
    
    // Hỏi khách hàng có muốn sử dụng điểm tích lũy để giảm giá không
    suDungDiem();
    
    // Sau khi trừ tiền giảm giá, hiển thị tổng tiền còn lại
    cout << "Tổng tiền cần thanh toán: " << tongTien << " VND" << endl;
    
    // Tính điểm tích lũy mới sau khi thanh toán
    diemTichLuy += tongTien / 100000; // Cứ mỗi 100k sẽ được 1 điểm
    cout << "Bạn đã tích thêm: " << tongTien / 100000 << " điểm" << endl;

    // Xuất hóa đơn
    xuatHoaDon();

    // Làm trống giỏ hàng sau khi thanh toán
    gioHang.clear();
}

void KhachHang::suDungDiem() {
    if (diemTichLuy > 0) {
        cout << "Bạn có " << diemTichLuy << " điểm. Bạn có muốn sử dụng điểm để giảm giá không? (1: Có, 0: Không): ";
        int luaChon;
        cin >> luaChon;
        
        if (luaChon == 1) {
            double giamGia = diemTichLuy * 1000; // Mỗi điểm trị giá 1000 VND
            cout << "Bạn đã giảm: " << giamGia << " VND từ điểm tích lũy." << endl;
            diemTichLuy = 0; // Sau khi sử dụng, điểm sẽ về 0
        }
    } else {
        cout << "Bạn không có điểm tích lũy để sử dụng." << endl;
    }
}

void KhachHang::hienThiGioHang() const {
    cout << "Giỏ hàng của bạn:" << endl;
    for (auto& sp : gioHang) {
        sp->inThongTin();
    }
}

void KhachHang::hienThiThongTin() const {
    cout << "Tên khách hàng: " << getTen() << endl;
    cout << "Điểm tích lũy: " << diemTichLuy << endl;
}

void KhachHang::xuatHoaDon() const {
    cout << "Hóa đơn của bạn:" << endl;
    for (auto& sp : gioHang) {
        sp->inThongTin();
    }
    cout << "Cảm ơn bạn đã mua sắm tại cửa hàng!" << endl;
}

SanPham* KhachHang::timSanPhamTrongGioHang(const string& tenSanPham) {
    for (SanPham* sanPham : gioHang) {
        // Giả sử bạn đã có phương thức getTenSanPham() trong lớp SanPham
        if (sanPham->getTenSanPham() == tenSanPham) {
            return sanPham; // Trả về con trỏ đến sản phẩm
        }
    }
    return nullptr; // Nếu không tìm thấy
}

string KhachHang::getTenSanPham() const {
    return "Tên khách hàng: " + getTen(); // Hoặc bất kỳ tên nào mà bạn muốn trả về
} 

SanPham* KhachHang::timSanPham(const std::string& tenSanPham, const std::vector<SanPham*>& danhSachSanPham) const {
    for (auto& sanPham : danhSachSanPham) {
        if (sanPham->getTenSanPham() == tenSanPham) {
            return sanPham;
        }
    }
    return nullptr;
}


