#include "../declare/DangNhap.h"
#include "../declare/Date.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

void dangNhap(const string& vaiTro) {
    string ten, matKhau, tenFile = "../resources/" + vaiTro + ".txt";
    bool timThay = false;
    int soLanThu = 0; 

    ifstream file(tenFile);
    if (!file) {
        cout << "Khong the mo file!" << endl;
        return;
    }
    
    while (soLanThu < 2) {
        cout << "                \033[38;5;33m[DANG NHAP]\033[0m" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "| \033[38;5;214m~\033[0m Nhap ten dang nhap:                   |"<< endl;
        cout << "| \033[38;5;214m~\033[0m Nhap mat khau:                        |"<< endl;
        cout << "-------------------------------------------" << endl;
        if (soLanThu>0)  cout << "Tai khoan hoac mat khau sai! Vui long thu lai.\n";
        cout.flush();
        setCursorPosition(24, 2); 
        cin >> ten;
        cout.flush();
        setCursorPosition(19, 3);
        cin >> matKhau;

        clearScreen();

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

        if (timThay) {
            break;
        } else {
            soLanThu++;
            file.clear();
            file.seekg(0);
        }
    }

    if (!timThay) {
        cout << "Nhap sai 2 lan. Dang xuat!\n";
    }

    file.close();
}

void dangKy(const string& vaiTro) {
    string ten, matKhau, tenFile = "../resources/" + vaiTro + ".txt";
    int in=0;
    while (true) {
        clearScreen();
        cout << "                \033[38;5;33m[DANG KY]\033[0m" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "| \033[38;5;214m~\033[0m Nhap ten dang nhap:                   |"<< endl;
        cout << "| \033[38;5;214m~\033[0m Nhap mat khau:                        |"<< endl;
        cout << "-------------------------------------------" << endl;
        if (in==1) cout << "\033[38;5;196mTen khong duoc vuot qua 15 ky tu va khong duoc it hon 6 ky tu. Vui long nhap lai.\033[0m";
        else if (in==2) cout << "\033[38;5;196mTen da ton tai. Vui long nhap ten khac.\033[0m";
        else if (in==3) cout << "\033[38;5;196mMat khau phai dai hon 10 ky tu va it hon 20 ky tu. Vui long nhap lai.\033[0m";
        else if (in==3) cout << "\033[38;5;196mMat khau phai co it nhat 1 chu hoa, 1 chu so va 1 ky tu dac biet. Vui long nhap lai.\033[0m";
        cout.flush();
        setCursorPosition(24, 2); 
        cin >> ten;
        cout.flush();
        setCursorPosition(19, 3);
        cin >> matKhau;

        if (ten.length() > 15 || ten.length() < 6) {
            in=1;
            continue;
        }

        ifstream file(tenFile);
        bool tenTrung = false;
        string line;
        while (getline(file, line)) {
            if (line.find(ten) == 0) {  
                tenTrung = true;
                break;
            }
        }
        file.close();

        if (tenTrung) {
            in=2;
            continue;
        }

        bool coChuHoa = regex_search(matKhau, regex("[A-Z]"));
        bool coChuSo = regex_search(matKhau, regex("[0-9]"));
        bool coKyTuDacBiet = regex_search(matKhau, regex("[^A-Za-z0-9]"));
        bool doDaiHopLe = matKhau.length() > 10 && matKhau.length() < 20;

        if (!doDaiHopLe) {
            in=3;
            continue;
        }
        if (!coChuHoa || !coChuSo || !coKyTuDacBiet) {
            in=4;
            continue;
        }
        break;
    }

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
        file << ten << " " << matKhau << " 0 " << " "
            << ngaySinh.getNgay() << " " << ngaySinh.getThang() << " " << ngaySinh.getNam() << " " << hoTen
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
    } else {
        file << ten << " " << matKhau;
    }

    file.close();
    cout << "Dang ky thanh cong!" << endl;
}

void menuKhachHang(KhachHang& khachHang) {
    int luaChon;
    vector<SanPham*> dsSanPham;
    docDuLieuTuFile("../resources/input.txt", dsSanPham);
    int koThanhToan=0;
    do {
        cout << "---------\033[38;5;49m[MENU KHACH HANG]\033[0m---------" << endl;
        cout << "|           Ban muon:             |"<< endl;
        cout << "|         \033[38;5;214m~\033[0m 1. Mua hang           |"<< endl;
        cout << "|     \033[38;5;214m~\033[0m 2. Hien thi gio hang      |" << endl;
        cout << "|       \033[38;5;214m~\033[0m 3. Thanh toan           |"<< endl;
        cout << "|          \033[38;5;214m~\033[0m 4. Thoat             |"<< endl;
        cout << "-----------------------------------" << endl;
        if (koThanhToan == 1) cout << "Gio hang cua ban hien tai rong. Khong the thanh toan." << endl;
        cout.flush();
        setCursorPosition(22, 1); 
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
                if (khachHang.neuGioHangRong()){ 
                    koThanhToan = 1; 
                    break;
                } else {
                    khachHang.thanhToan(dsSanPham); 
                }
                return;
            }
            case 4:
                luaChon=5;
                break;
            default:
                cout << "Thoat khoi he thong." << endl;
        }
    } while (luaChon != 5);
}

void menuNhanVien(NhanVien& nhanVien) {
    vector<SanPham*> dsSanPham; 
    int luaChon;
    vector<string> ca;  
    int soCa;

    do {
        cout << "----------\033[38;5;49m[MENU NHAN VIEN]\033[0m---------" << endl;
        cout << "|           Ban muon:             |"<< endl;
        cout << "|       \033[38;5;214m~\033[0m 1. Nhap san pham        |"<< endl;
        cout << "|       \033[38;5;214m~\033[0m 2. Xoa san pham         |" << endl;
        cout << "|      \033[38;5;214m~\033[0m 3. Dang ky ca lam        |"<< endl;
        cout << "|          \033[38;5;214m~\033[0m 4. Thoat             |"<< endl;
        cout << "-----------------------------------" << endl;
        cout.flush();
        setCursorPosition(22, 1); 
        cin >> luaChon;
        clearScreen();

        switch (luaChon) {
            case 1: {
                int soLuong;
                string ngaySanXuat, hanSuDung, loaiSanPham;
                double giaTien;

                cout << "Nhap loai san pham (Thit/Ca/Keo/Nuoc/RauCu/GiaVi/Banh/Giay/ChenBat/DoDongHop): ";
                cin >> loaiSanPham;
                cout << "Nhap so luong: ";
                cin >> soLuong;
                cout << "Nhap gia tien: ";
                cin >> giaTien;

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
                int index;
                cout << "Nhap chi so san pham can xoa (0 - " << dsSanPham.size() - 1 << "): ";
                cin >> index;

                if (index >= 0 && index < dsSanPham.size()) {
                    delete dsSanPham[index]; 
                    dsSanPham.erase(dsSanPham.begin() + index);
                    cout << "San pham da duoc xoa thanh cong!" << endl;
                } else {
                    cout << "Chi so khong hop le!" << endl;
                }
                break;
            }
            case 3: {
                nhanVien.dangKyCaLam();  
                break;
            }
            case 4:
                luaChon=5;
                break;
            default:
                cout << "Thoat khoi he thong." << endl;
        }

    } while (luaChon != 0);

    for (SanPham* sp : dsSanPham) {
        delete sp;
    }
}

void menuGiamDoc(GiamDoc& giamDoc) {
    int luaChon;
    do {
        cout << "------------\033[38;5;49m[MENU GIAM DOC]\033[0m------------" << endl;
        cout << "|              Ban muon:              |"<< endl;
        cout << "|    \033[38;5;214m~\033[0m 1. Xuat thong tin nhan vien    |"<< endl;
        cout << "|    \033[38;5;214m~\033[0m 2. Xuat thong tin san pham     |" << endl;
        cout << "|    \033[38;5;214m~\033[0m 3. Xuat thong tin khach hang   |"<< endl;
        cout << "|            \033[38;5;214m~\033[0m 4. Thoat               |"<< endl;
        cout << "---------------------------------------" << endl;
        cout.flush();
        setCursorPosition(25, 1); 
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
                luaChon=5;
                break;
            default:
                cout << "Thoat khoi he thong." << endl;
        }
    } while (luaChon != 4);
}


