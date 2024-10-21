#include "DangNhap.h"
#include <iostream>
#include <conio.h>
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
                string lichLamViec; // Khai báo biến lichLamViec
                iss >> lichLamViec; // Đọc lịch làm việc từ file
                NhanVien nhanVien(ten, matKhau, lichLamViec); // Khởi tạo NhanVien với lichLamViec
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

    //sai thi cho dang nhap lai hoac dang ky
}

void dangKy(const string& vaiTro) {
    string ten, matKhau, tenFile = vaiTro + ".txt";
    
    cout << "Nhap ten dang ky: ";
    cin >> ten;
    cout << "Nhap mat khau: ";
    cin >> matKhau;

    // Mở tệp để ghi thông tin
    ofstream file(tenFile, ios::app);
    if (!file) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    // Thêm thông tin vào tệp
    if (vaiTro == "KhachHang") {
        file << ten << " " << matKhau << " 0" << endl; // 0 điểm tích lũy cho khách hàng
    } else if (vaiTro == "NhanVien") {
        file << ten << " " << matKhau << " 00000000" << endl; // chuỗi 00000000 cho nhân viên
    }

    file.close();
    cout << "Dang ky thanh cong!" << endl;
}


void menuKhachHang(KhachHang& khachHang) {
    int luaChon;
    vector<SanPham*> dsSanPham;
    docDuLieuTuFile("input.txt", dsSanPham);
    do {
        cout << "1. Them san pham vao gio hang" << endl;
        cout << "2. Xoa san pham khoi gio hang" << endl;
        cout << "3. Hien thi gio hang" << endl;
        cout << "4. Thanh toan" << endl;
        cout << "5. Thoat" << endl;
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                // Thêm sản phẩm vào giỏ
                string tenSanPham;
                int soLuong;
                cout << "Nhap ten san pham: ";
                cin >> tenSanPham;
                cout << "Nhap so luong: ";
                cin >> soLuong;

                
                SanPham* sanPham = khachHang.timSanPham(tenSanPham, dsSanPham);
                if (sanPham != nullptr) {
                    khachHang.themVaoGioHang(sanPham, soLuong);
                    cout << "San pham da duoc them vao gio hang." << endl;
                } else {
                    cout << "San pham khong ton tai!" << endl;
                }
                break;
            }
            case 2: {
                // Xóa sản phẩm khỏi giỏ
                string tenSanPham;
                int soLuong;
                cout << "Nhap ten san pham can xoa: ";
                cin >> tenSanPham;
                cout << "Nhap so luong can xoa: ";
                cin >> soLuong;

                // Giả sử bạn có một hàm tìm kiếm sản phẩm trong giỏ hàng
                SanPham* sanPham = khachHang.timSanPhamTrongGioHang(tenSanPham); // Bạn cần cài đặt hàm này
                if (sanPham != nullptr) {
                    khachHang.boSanPham(sanPham, soLuong);
                    cout << "San pham đa đuoc xoa khoi gio hang." << endl;
                } else {
                    cout << "San pham khong co trong gio hang!" << endl;
                }
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
                cout << "Thoat khoi he thong." << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
        }
    } while (luaChon != 5);
}


void menuNhanVien(NhanVien& nhanVien) {
    vector<SanPham*> dsSanPham; // Danh sách sản phẩm
    int luaChon;
    vector<string> ca;  // Khai báo vector<string> ca để lưu các ca làm việc
    int soCa;
    
    do {
        cout << "===== Menu Nhan Vien =====" << endl;
        cout << "1. Nhap san pham" << endl;
        cout << "2. Xoa san pham" << endl;
        cout << "3. Dang ky ca lam" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                // Nhập sản phẩm
                int soLuong;
                string ngaySanXuat, hanSuDung, loaiSanPham;
                double giaTien;

                cout << "Nhap loai san pham (Thit/Ca/Keo/Nuoc/RauCu): ";
                cin >> loaiSanPham;
                cout << "Nhap so luong: ";
                cin >> soLuong;
                cout << "Nhap ngay san xuat: ";
                cin >> ngaySanXuat;
                cout << "Nhap han su dung: ";
                cin >> hanSuDung;
                cout << "Nhap gia tien: ";
                cin >> giaTien;

                // Thêm sản phẩm vào danh sách
                if (loaiSanPham == "Thit") {
                    string loaiThit;
                    cout << "Nhap loai thit: ";
                    cin >> loaiThit;
                    dsSanPham.push_back(new Thit(soLuong, ngaySanXuat, hanSuDung, loaiThit, giaTien));
                } else if (loaiSanPham == "Ca") {
                    string loaiCa;
                    cout << "Nhap loai ca: ";
                    cin >> loaiCa;
                    dsSanPham.push_back(new Ca(soLuong, ngaySanXuat, hanSuDung, loaiCa, giaTien));
                } else if (loaiSanPham == "Keo") {
                    string loaiKeo;
                    cout << "Nhap loai keo: ";
                    cin >> loaiKeo;
                    dsSanPham.push_back(new Keo(soLuong, ngaySanXuat, hanSuDung, loaiKeo, giaTien));
                } else if (loaiSanPham == "Nuoc") {
                    string loaiNuoc;
                    cout << "Nhap loai nuoc: ";
                    cin >> loaiNuoc;
                    dsSanPham.push_back(new Nuoc(soLuong, ngaySanXuat, hanSuDung, loaiNuoc, giaTien));
                } else if (loaiSanPham == "RauCu") {
                    string loaiRauCu;
                    cout << "Nhap loai rau cu: ";
                    cin >> loaiRauCu;
                    dsSanPham.push_back(new RauCu(soLuong, ngaySanXuat, hanSuDung, loaiRauCu, giaTien));
                } else {
                    cout << "Loai san pham khong hop le!" << endl;
                }

                cout << "San pham da duoc them thanh cong!" << endl;
                break;
            }
            case 2: {
                // Xóa sản phẩm
                int index;
                cout << "Nhap chi so san pham can xoa (0 - " << dsSanPham.size() - 1 << "): ";
                cin >> index;

                if (index >= 0 && index < dsSanPham.size()) {
                    delete dsSanPham[index]; // Giải phóng bộ nhớ
                    dsSanPham.erase(dsSanPham.begin() + index);
                    cout << "San pham da duoc xoa thanh cong!" << endl;
                } else {
                    cout << "Chi so khong hop le!" << endl;
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

                    nhanVien.dangKyCaLam();
                }
                break; // Thêm break ở đây để tránh lặp vô hạn
            }
            case 0:
                cout << "Thoat chuong trinh!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
        }

    } while (luaChon != 0);

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
                // Xu ly xuat luong cho nhan vien
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

