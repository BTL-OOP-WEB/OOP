#include "ham_tao_lao.h"
#include <iostream>

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void dangNhap(const string& vaiTro) {
    string ten, matKhau, tenFile = vaiTro + ".txt"; // Tên file tương ứng với vai trò
    bool timThay = false;

    cout << "Nhap ten dang nhap: ";
    cin >> ten;
    cout << "Nhap mat khau: ";
    cin >> matKhau;

    ifstream file(tenFile); // Mở file tương ứng với vai trò
    if (!file) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    string dong;
    while (getline(file, dong)) {
        istringstream iss(dong);
        string tenNguoiDung, mk;
        iss >> tenNguoiDung >> mk;

        // So sánh tên và mật khẩu
        if (ten == tenNguoiDung && matKhau == mk) {
            timThay = true; // Đánh dấu là tìm thấy

            if (vaiTro == "KhachHang") {
                int diemTichLuy;
                iss >> diemTichLuy; // Lấy điểm tích lũy
                KhachHang khachHang(ten, matKhau, diemTichLuy); // Khởi tạo KhachHang
                menuKhachHang(khachHang); // Gọi hàm menu cho khách hàng
            } else if (vaiTro == "NhanVien") {
                NhanVien nhanVien(ten, matKhau); // Khởi tạo NhanVien
                menuNhanVien(nhanVien); // Gọi hàm menu cho nhân viên
            } else if (vaiTro == "GiamDoc") {
                GiamDoc giamDoc(ten, matKhau); // Khởi tạo GiamDoc
                menuGiamDoc(giamDoc); // Gọi hàm menu cho giám đốc
            }
            break; // Thoát khỏi vòng lặp khi đã tìm thấy
        }
    }

    if (!timThay) {
        cout << "Sai ten dang nhap hoac mat khau!" << endl; // Thông báo lỗi
    }

    file.close(); // Đóng file sau khi hoàn thành
}

void dangKy(const string& vaiTro) {
    string ten, matKhau, tenFile = vaiTro + ".txt";

    cout << "Nhập tên đăng ký: ";
    cin >> ten;
    cout << "Nhập mật khẩu: ";
    cin >> matKhau;

    ofstream file(tenFile, ios::app);
    if (!file) {
        cout << "Không thể mở file!" << endl;
        return;
    }

    file << ten << " " << matKhau << endl;
    file.close();
    cout << "Đăng ký thành công!" << endl;
}

void menuKhachHang(KhachHang& khachHang) {
    int luaChon;
    do {
        cout << "1. Thêm sản phẩm vào giỏ hàng" << endl;
        cout << "2. Xóa sản phẩm khỏi giỏ hàng" << endl;
        cout << "3. Hiển thị giỏ hàng" << endl;
        cout << "4. Thanh toán" << endl;
        cout << "5. Thoát" << endl;
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                // Thêm sản phẩm vào giỏ
                // Gọi hàm themVaoGioHang() từ KhachHang
                break;
            }
            case 2: {
                // Xóa sản phẩm khỏi giỏ
                // Gọi hàm boSanPham() từ KhachHang
                break;
            }
            case 3: {
                khachHang.hienThiGioHang();
                break;
            }
            case 4: {
                khachHang.thanhToan();
                break;
            }
            case 5:
                cout << "Thoát khỏi hệ thống." << endl;
                break;
            default:
                cout << "Lựa chọn không hợp lệ!" << endl;
        }
    } while (luaChon != 5);
}

void menuNhanVien(NhanVien& nhanVien) {
    vector<SanPham*> dsSanPham; // Danh sách sản phẩm
    int luaChon;
    vector<string> ca;  // Khai báo vector<string> ca để lưu các ca làm việc
    int soCa;
    
    do {
        cout << "===== Menu Nhân Viên =====" << endl;
        cout << "1. Nhập sản phẩm" << endl;
        cout << "2. Xóa sản phẩm" << endl;
        cout << "3. Đăng ký ca làm" << endl;
        cout << "0. Thoát" << endl;
        cout << "Nhập lựa chọn của bạn: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                // Nhập sản phẩm
                int soLuong;
                string ngaySanXuat, hanSuDung, loaiSanPham;
                double giaTien;

                cout << "Nhập loại sản phẩm (Thit/Ca/Keo/Nuoc/RauCu): ";
                cin >> loaiSanPham;
                cout << "Nhập số lượng: ";
                cin >> soLuong;
                cout << "Nhập ngày sản xuất: ";
                cin >> ngaySanXuat;
                cout << "Nhập hạn sử dụng: ";
                cin >> hanSuDung;
                cout << "Nhập giá tiền: ";
                cin >> giaTien;

                // Thêm sản phẩm vào danh sách
                if (loaiSanPham == "Thit") {
                    string loaiThit;
                    cout << "Nhập loại thịt: ";
                    cin >> loaiThit;
                    dsSanPham.push_back(new Thit(soLuong, ngaySanXuat, hanSuDung, loaiThit, giaTien));
                } else if (loaiSanPham == "Ca") {
                    string loaiCa;
                    cout << "Nhập loại cá: ";
                    cin >> loaiCa;
                    dsSanPham.push_back(new Ca(soLuong, ngaySanXuat, hanSuDung, loaiCa, giaTien));
                } else if (loaiSanPham == "Keo") {
                    string loaiKeo;
                    cout << "Nhập loại kẹo: ";
                    cin >> loaiKeo;
                    dsSanPham.push_back(new Keo(soLuong, ngaySanXuat, hanSuDung, loaiKeo, giaTien));
                } else if (loaiSanPham == "Nuoc") {
                    string loaiNuoc;
                    cout << "Nhập loại nước: ";
                    cin >> loaiNuoc;
                    dsSanPham.push_back(new Nuoc(soLuong, ngaySanXuat, hanSuDung, loaiNuoc, giaTien));
                } else if (loaiSanPham == "RauCu") {
                    string loaiRauCu;
                    cout << "Nhập loại rau củ: ";
                    cin >> loaiRauCu;
                    dsSanPham.push_back(new RauCu(soLuong, ngaySanXuat, hanSuDung, loaiRauCu, giaTien));
                } else {
                    cout << "Loại sản phẩm không hợp lệ!" << endl;
                }

                cout << "Sản phẩm đã được thêm thành công!" << endl;
                break;
            }
            case 2: {
                // Xóa sản phẩm
                int index;
                cout << "Nhập chỉ số sản phẩm cần xóa (0 - " << dsSanPham.size() - 1 << "): ";
                cin >> index;

                if (index >= 0 && index < dsSanPham.size()) {
                    delete dsSanPham[index]; // Giải phóng bộ nhớ
                    dsSanPham.erase(dsSanPham.begin() + index);
                    cout << "Sản phẩm đã được xóa thành công!" << endl;
                } else {
                    cout << "Chỉ số không hợp lệ!" << endl;
                }
                break;
            }
            case 3: {
                cout << "Nhap so ca lam viec muon dang ky (1 - 5): ";
                cin >> soCa;

                // Kiểm tra số lượng ca làm hợp lệ
                if (soCa >= 1 && soCa <= 5) {
                    for (int i = 0; i < soCa; ++i) {
                        string caLam;
                        cout << "Nhap ca lam viec thu " << i + 1 << ": ";
                        cin >> caLam;
                        ca.push_back(caLam);  // Thêm ca làm vào vector
                    }

                    nhanVien.dangKyCaLam(ca);
            }
            case 0:
                cout << "Thoát chương trình!" << endl;
                break;
            default:
                cout << "Lựa chọn không hợp lệ!" << endl;
                break;
        }

    } }while (luaChon != 0);

    // Giải phóng bộ nhớ cho danh sách sản phẩm
    for (SanPham* sp : dsSanPham) {
        delete sp;
    }
}
void menuGiamDoc(GiamDoc& giamDoc) {
    int luaChon;
    do {
        cout << "1. Diem danh nhan vien\n";
        cout << "2. Xuat luong nhan vien\n";
        cout << "3. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                // Thực hiện điểm danh nhân viên, bạn cần chuẩn bị danh sách nhân viên trước
                vector<NhanVien*> dsNhanVien;  // Giả sử bạn đã có danh sách nhân viên
                giamDoc.diemDanhNhanVien(dsNhanVien);  // Gọi hàm điểm danh
                break;
            }
            case 2: {
                // Xử lý xuất lương cho nhân viên
                NhanVien* nhanVien = nullptr;  // Giả sử bạn đã có con trỏ nhân viên
                giamDoc.xuatLuongNhanVien(nhanVien);  // Gọi hàm xuất lương
                break;
            }
            case 3:
                cout << "Thoat menu giam doc\n";
                break;
            default:
                cout << "Lua chon khong hop le, vui long chon lai!\n";
                break;
        }
    } while (luaChon != 3);
}
