#include "../declare/DangNhap.h"
#include "../declare/Date.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
using namespace std;

void dangNhap(const string& vaiTro) {
    string ten, matKhau, tenFile = "../resources/" + vaiTro + ".txt";
    bool timThay = false;

    cout << "Nhap ten dang nhap: ";
    cin >> ten;
    cout << "Nhap mat khau: ";
    cin >> matKhau;
    clearScreen();

    ifstream file(tenFile);
    if (!file) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    string dong;
    while (getline(file, dong)) {
        istringstream iss(dong);
        string tenNguoiDung, mk;
        iss >> tenNguoiDung >> mk;

        if (ten == tenNguoiDung && matKhau == mk) {
            if (vaiTro == "KhachHang") {
                int diemTichLuy;
                string hoTen, sdt;
                Date ngaySinh;
                iss >> diemTichLuy;
                iss.ignore();
                getline(iss, hoTen);
                int d, m, y;
                iss >> d >> m >> y; 
                ngaySinh = Date(d, m, y);
                iss >> sdt;
                KhachHang khachHang(ten, matKhau, diemTichLuy, hoTen, ngaySinh, sdt);
                menuKhachHang(khachHang);
            } else if (vaiTro == "NhanVien") {
                string hoTen, sdt, lichLamViec;
                int d, m, y;
                iss >> hoTen >> d >> m >> y >> sdt >> lichLamViec;
                Date ngaySinh(d, m, y);
                NhanVien nhanVien(ten, matKhau, hoTen, ngaySinh, sdt, lichLamViec);
                menuNhanVien(nhanVien);
            } else if (vaiTro == "GiamDoc") {
                GiamDoc giamDoc(ten, matKhau);
                menuGiamDoc(giamDoc);
            }
            timThay = true;
            break;
        }
    }

    if (!timThay) {
        cout << "Sai ten dang nhap hoac mat khau!" << endl;
    }

    file.close();
}

void dangKy(const string& vaiTro) {
    string ten, matKhau, tenFile = "../resources/" + vaiTro + ".txt";

    cout << "Nhap ten dang ky: ";
    cin >> ten;
    cout << "Nhap mat khau: ";
    cin >> matKhau;

    ofstream file(tenFile, ios::app);
    if (!file) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    if (vaiTro == "KhachHang") {
        string hoTen, sdt;
        int d, m, y;
        cout << "Nhap ho ten khach hang: ";
        getline(cin >> ws, hoTen);
        cout << "Nhap ngay sinh (dd mm yyyy): ";
        cin >> d >> m >> y; 
        cout << "Nhap so dien thoai: ";
        cin >> sdt;
        Date ngaySinh(d, m, y);
        file << ten << " " << matKhau << " 0 " << hoTen << " "
            << ngaySinh.getNgay() << " " << ngaySinh.getThang() << " " << ngaySinh.getNam() << " "
            << sdt << endl;
    } else if (vaiTro == "NhanVien") {
        string hoTen, sdt;
        int d, m, y; 
        string lichLamViec = "0000000";

        cout << "Nhap ho ten nhan vien: ";
        getline(cin >> ws, hoTen);
        cout << "Nhap ngay sinh (dd mm yyyy): ";
        cin >> d >> m >> y; 
        cout << "Nhap so dien thoai: ";
        cin >> sdt;
        Date ngaySinh(d, m, y);
        NhanVien nhanVien(ten, matKhau, hoTen, ngaySinh, sdt, lichLamViec);
        file << ten << " " << matKhau << " " << lichLamViec << " " << hoTen << " "
            << ngaySinh.getNgay() << " " << ngaySinh.getThang() << " " << ngaySinh.getNam() << " "
            << sdt << endl;
    }


    file.close();
    cout << "Dang ky thanh cong!" << endl;
}




void menuKhachHang(KhachHang& khachHang) {
    int luaChon;
    vector<SanPham*> dsSanPham;
    docDuLieuTuFile("../resources/input.txt", dsSanPham);
    do {
        cout << "1. Di mua hang" << endl;
        cout << "2. Hien thi gio hang" << endl;
        cout << "3. Thanh toan" << endl;
        cout << "4. Thoat" << endl;
        cin >> luaChon;
        clearScreen();

        switch (luaChon) {
            case 1: {
               khachHang.muaHang(dsSanPham);
                break;
            }
            case 2: {
                khachHang.hienThiGioHang();
                break;
            }
            case 3: {
                khachHang.thanhToan();
                break;
            }
            case 4:
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
        clearScreen();

        switch (luaChon) {
            case 1: {
                // Nhập sản phẩm
                int soLuong;
                string ngaySanXuat, hanSuDung, loaiSanPham;
                double giaTien;

                cout << "Nhap loai san pham (Thit/Ca/Keo/Nuoc/RauCu/GiaVi/Banh/Giay/ChenBat/DoDongHop): ";
                cin >> loaiSanPham;
                cout << "Nhap so luong: ";
                cin >> soLuong;
                cout << "Nhap gia tien: ";
                cin >> giaTien;

                // Thêm sản phẩm vào danh sách
                if (loaiSanPham == "Thit") {
                    string loaiThit;
                    cout << "Nhap loai thit: ";
                    cin >> loaiThit;
                    dsSanPham.push_back(new Thit(soLuong, loaiThit, giaTien));
                } else if (loaiSanPham == "Ca") {
                    string loaiCa;
                    cout << "Nhap loai ca: ";
                    cin >> loaiCa;
                    dsSanPham.push_back(new Ca(soLuong, loaiCa, giaTien));
                } else if (loaiSanPham == "Keo") {
                    string loaiKeo;
                    cout << "Nhap loai keo: ";
                    cin >> loaiKeo;
                    dsSanPham.push_back(new Keo(soLuong, loaiKeo, giaTien));
                } else if (loaiSanPham == "Nuoc") {
                    string loaiNuoc;
                    cout << "Nhap loai nuoc: ";
                    cin >> loaiNuoc;
                    dsSanPham.push_back(new Nuoc(soLuong, loaiNuoc, giaTien));
                } else if (loaiSanPham == "RauCu") {
                    string loaiRauCu;
                    cout << "Nhap loai rau cu: ";
                    cin >> loaiRauCu;
                    dsSanPham.push_back(new RauCu(soLuong, loaiRauCu, giaTien));
                } else if (loaiSanPham == "GiaVi") {
                    string loaiGiaVi;
                    cout << "Nhap loai gia vị: ";
                    cin >> loaiGiaVi;
                    dsSanPham.push_back(new GiaVi(soLuong, loaiGiaVi, giaTien));    
                } else if (loaiSanPham == "Banh") {
                    string loaiBanh;
                    cout << "Nhap loai Banh: ";
                    cin >> loaiBanh;
                    dsSanPham.push_back(new Banh(soLuong, loaiBanh, giaTien));
                } else if (loaiSanPham == "Giay") {
                    string loaiGiay;
                    cout << "Nhap loai giay: ";
                    cin >> loaiGiay;
                    dsSanPham.push_back(new Giay(soLuong, loaiGiay, giaTien));
                } else if (loaiSanPham == "ChenBat") {
                    string loaiChenBat;
                    cout << "Nhap loai rau cu: ";
                    cin >> loaiChenBat;
                    dsSanPham.push_back(new ChenBat(soLuong, loaiChenBat, giaTien));
                } else if (loaiSanPham == "DoDongHop") {
                    string loaiDoDongHop;
                    cout << "Nhap loai do dong hop: ";
                    cin >> loaiDoDongHop;
                    dsSanPham.push_back(new DoDongHop(soLuong, loaiDoDongHop, giaTien));
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
                nhanVien.dangKyCaLam();  // Gọi hàm dangKyCaLam
                break;
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
        cout << "1. Xuat thong tin nhan vien\n";
        cout << "2. Xuat thong tin san pham\n";
        cout << "3. Xuat thong tin khach hang\n";
        cout << "4. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        clearScreen();

        switch (luaChon) {
            case 1: {
                giamDoc.xuatThongTinNhanVien();
                break;
            }
            case 2: {
                giamDoc.xuatThongTinSanPham();
                break;
            }
            case 3: {
                giamDoc.xuatThongTinKhachHang(); 
                break;
            }
            case 4:
                cout << "Thoat menu giam doc\n";
                break;
            default:
                cout << "Lua chon khong hop le, vui long chon lai!\n";
                break;
        }
    } while (luaChon != 4);
}


