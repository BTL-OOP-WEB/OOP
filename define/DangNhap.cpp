#include "../declare/DangNhap.h"
#include "../declare/Date.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

void doiMatKhau(const string& vaiTro, const string& tenNguoiDung) {
    string tenFile = "../resources/" + vaiTro + ".txt";
    string dong;
    bool timThay = false;

    ifstream fileIn(tenFile);
    if (!fileIn) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    vector<string> noiDungFile;
    while (getline(fileIn, dong)) {
        istringstream iss(dong);
        string ten, mk, hoTen, sdt, lichLamViec;
        int diem, d, m, y;
        
        iss >> ten >> mk;

        if (ten == tenNguoiDung) {
            timThay = true;
            string matKhauMoi;

            while (true) {
                cout << " \033[38;5;214m~\033[0m Nhap mat khau moi: ";
                matKhauMoi = nhapMatKhau();
                bool coChuHoa = regex_search(matKhauMoi, regex("[A-Z]"));
                bool coChuSo = regex_search(matKhauMoi, regex("[0-9]"));
                bool coKyTuDacBiet = regex_search(matKhauMoi, regex("[^A-Za-z0-9]"));
                bool doDaiHopLe = matKhauMoi.length() > 10 && matKhauMoi.length() < 20;

                if (!doDaiHopLe || !coChuHoa || !coChuSo || !coKyTuDacBiet) {
                    cout << "\033[38;5;196mMat khau khong hop le. Vui long thu lai.\033[0m" << endl;
                } else {
                    break;
                }
            }

            if (vaiTro == "KhachHang") {
                iss >> diem >> d >> m >> y >> sdt;
                getline(iss, hoTen);
                dong = ten + " " + matKhauMoi + " " + to_string(diem) + " " + to_string(d) + " " + to_string(m) + " " + to_string(y) + " " + sdt + hoTen;
            } else if (vaiTro == "NhanVien") {
                iss >> lichLamViec >> d >> m >> y >> sdt;
                getline(iss, hoTen);
                dong = ten + " " + matKhauMoi + " " + lichLamViec + " " + to_string(d) + " " + to_string(m) + " " + to_string(y) + " " + sdt + hoTen;
            } else if (vaiTro == "GiamDoc") {
                dong = ten + " " + matKhauMoi;
            }
        }
        noiDungFile.push_back(dong);
    }
    fileIn.close();

    if (timThay) {
        ofstream fileOut(tenFile);
        for (const string& line : noiDungFile) {
            fileOut << line << endl;
        }
        fileOut.close();
    } else {
        cout << "Khong tim thay tai khoan." << endl;
    }
    clearScreen();
}


void quenMatKhau(const string& vaiTro) {
    string tenFile = "../resources/" + vaiTro + ".txt";
    string tenNguoiDung, dong;
    bool timThay = false;

    while (true) {
        cout << "\033[38;5;214m~\033[0m Nhap ten dang nhap de dat lai mat khau: ";
        cin >> tenNguoiDung;
        ifstream fileIn(tenFile);
        if (!fileIn) {
            cout << "Khong the mo file!" << endl;
            return;
        }

        vector<string> noiDungFile;
        while (getline(fileIn, dong)) {
            istringstream iss(dong);
            string ten, mk, hoTen, sdt, lichLamViec;
            int diem, d, m, y;
            
            iss >> ten >> mk;

            if (ten == tenNguoiDung) {
                timThay = true;
                string matKhauMoi;

                while (true) {
                    cout << "\033[38;5;214m~\033[0m Nhap mat khau moi: ";
                    matKhauMoi = nhapMatKhau();
                    bool coChuHoa = regex_search(matKhauMoi, regex("[A-Z]"));
                    bool coChuSo = regex_search(matKhauMoi, regex("[0-9]"));
                    bool coKyTuDacBiet = regex_search(matKhauMoi, regex("[^A-Za-z0-9]"));
                    bool doDaiHopLe = matKhauMoi.length() > 10 && matKhauMoi.length() < 20;

                    if (!doDaiHopLe || !coChuHoa || !coChuSo || !coKyTuDacBiet) {
                        cout << "\033[38;5;196mMat khau khong hop le. Vui long thu lai.\033[0m" << endl;
                    } else {
                        break;
                    }
                }

                if (vaiTro == "KhachHang") {
                    iss >> diem >> d >> m >> y >> sdt;
                    getline(iss, hoTen);
                    dong = ten + " " + matKhauMoi + " " + to_string(diem) + " " + to_string(d) + " " + to_string(m) + " " + to_string(y) + " " + sdt + hoTen;
                } else if (vaiTro == "NhanVien") {
                    iss >> lichLamViec >> d >> m >> y >> sdt;
                    getline(iss, hoTen);
                    dong = ten + " " + matKhauMoi + " " + lichLamViec + " " + to_string(d) + " " + to_string(m) + " " + to_string(y) + " " + sdt + hoTen;
                } else if (vaiTro == "GiamDoc") {
                    dong = ten + " " + matKhauMoi;
                }
            }
            noiDungFile.push_back(dong);
        }
        fileIn.close();

        if (timThay) {
            ofstream fileOut(tenFile);
            for (const string& line : noiDungFile) {
                fileOut << line << endl;
            }
            fileOut.close();
            break;
        } else {
            int luaChon;
            cout << "Khong tim thay tai khoan.\n";
            cout << "\033[38;5;214m~\033[0m 1. Thu lai\n\033[38;5;214m~\033[0m 2. Thoat\n";
            cout << "Nhap lua chon: ";
            cin >> luaChon;

            switch (luaChon) {
                case 1:
                    continue;
                case 2:
                    return;
                default:
                    cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
                    break;
            }
        }
    }
}

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
        cout.flush();
        setCursorPosition(24, 2); 
        cin >> ten;
        cout.flush();
        setCursorPosition(19, 3);
        matKhau = nhapMatKhau();

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
                soLanThu = 3;
                break;
            }
        }

        if (soLanThu < 3) {
                int luaChon;
                cout << "\nNhap sai tai khoan hoac mat khau.\n";
                cout << "\033[38;5;214m~\033[0m 1. Thu lai(ban con " << 3-soLanThu <<" lan thu)\n\033[38;5;214m~\033[0m 2. Quen mat khau\n\033[38;5;214m~\033[0m 3. Thoat\n";
                cout << "Nhap lua chon: ";
                cin >> luaChon;

                switch (luaChon) {
                    case 1:
                        file.clear();
                        file.seekg(0);
                        soLanThu++;
                        continue;
                    case 2:
                        quenMatKhau(vaiTro);
                        file.close();
                        return;
                    case 3:
                        file.close();
                        return;
                    default:
                        cout << "Lua chon khong hop le. Vui long thu lai.\n";
                        soLanThu--;  
                        break;
                }
            }
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
        matKhau = nhapMatKhau();

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
        while (true) {
            cout << "Nhap ngay sinh (dd mm yyyy): ";
            cin >> d >> m >> y;
            if (d > 0 && d <= 31 && m > 0 && m <= 12 && y >= 1900) break;
            else cout << "Ngay sinh khong hop le. Vui long nhap lai.\n";
        }
        while (true) {
            cout << "Nhap so dien thoai (10 chu so): ";
            cin >> sdt;
            if (sdt.length() == 10 && all_of(sdt.begin(), sdt.end(), ::isdigit)) break;
            else cout << "So dien thoai khong hop le. Vui long nhap lai.\n";
        }
        Date ngaySinh(d, m, y);
        file << ten << " " << matKhau << " 0 " << " "
            << ngaySinh.getNgay() << " " << ngaySinh.getThang() << " " << ngaySinh.getNam() << " " 
            << sdt << " " << hoTen << endl;
    } else if (vaiTro == "NhanVien") {
        string hoTen, sdt;
        int d, m, y; 
        string lichLamViec = "0000000";

        cout << "Nhap ho ten nhan vien: ";
        getline(cin >> ws, hoTen);
        while (true) {
            cout << "Nhap ngay sinh (dd mm yyyy): ";
            cin >> d >> m >> y;
            if (d > 0 && d <= 31 && m > 0 && m <= 12 && y >= 1900) break;
            else cout << "Ngay sinh khong hop le. Vui long nhap lai.\n";
        }
        while (true) {
            cout << "Nhap so dien thoai (10 chu so): ";
            cin >> sdt;
            if (sdt.length() == 10 && all_of(sdt.begin(), sdt.end(), ::isdigit)) break;
            else cout << "So dien thoai khong hop le. Vui long nhap lai.\n";
        }
        Date ngaySinh(d, m, y);
        NhanVien nhanVien(ten, matKhau, hoTen, ngaySinh, sdt, lichLamViec);
        file << ten << " " << matKhau << " " << lichLamViec << " "
            << ngaySinh.getNgay() << " " << ngaySinh.getThang() << " " << ngaySinh.getNam() << " "
            << sdt << " " << hoTen  << endl;
    } else {
        file << ten << " " << matKhau;
    }

    file.close();
    cout << "\n";
    cout << "Dang ky thanh cong!" << endl;
}

void menuKhachHang(KhachHang& khachHang) {
    int luaChon;
    vector<SanPham*> dsSanPham;
    docDuLieuTuFile("../resources/input.txt", dsSanPham);
    int koThanhToan=0;
    clearScreen();
    do {
        cout << "---------\033[38;5;49m[MENU KHACH HANG]\033[0m---------" << endl;
        cout << "|           Ban muon:             |"<< endl;
        cout << "|         \033[38;5;214m~\033[0m 1. Mua hang           |"<< endl;
        cout << "|     \033[38;5;214m~\033[0m 2. Hien thi gio hang      |" << endl;
        cout << "|       \033[38;5;214m~\033[0m 3. Thanh toan           |"<< endl;
        cout << "|      \033[38;5;214m~\033[0m 4. Doi mat khau          |"<< endl;
        cout << "|          \033[38;5;214m~\033[0m 5. Thoat             |"<< endl;
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
                clearScreen();
                doiMatKhau("KhachHang",khachHang.getTen());
                break;
            case 5:
                luaChon=6;
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
    clearScreen();
    do {
        cout << "----------\033[38;5;49m[MENU NHAN VIEN]\033[0m---------" << endl;
        cout << "|           Ban muon:             |"<< endl;
        cout << "|       \033[38;5;214m~\033[0m 1. Nhap san pham        |"<< endl;
        cout << "|       \033[38;5;214m~\033[0m 2. Xoa san pham         |" << endl;
        cout << "|      \033[38;5;214m~\033[0m 3. Dang ky ca lam        |"<< endl;
        cout << "|        \033[38;5;214m~\033[0m 4. Doi mat khau        |"<< endl;
        cout << "|          \033[38;5;214m~\033[0m 5. Thoat             |"<< endl;
        cout << "-----------------------------------" << endl;
        cout.flush();
        setCursorPosition(22, 1); 
        cin >> luaChon;
        clearScreen();

        switch (luaChon) {
            case 1: {
                nhanVien.nhapSanPham(dsSanPham);
                break;
            }
            case 2: {
                nhanVien.xoaSanPham(dsSanPham);
                break;
            }
            case 3: {
                nhanVien.dangKyCaLam(nhanVien.getTenNguoiDung());  
                break;
            }
            case 4:
                clearScreen();
                doiMatKhau("NhanVien",nhanVien.getTen());
                break;
            case 5:
                luaChon=6;
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
    clearScreen();
    do {
        cout << "------------\033[38;5;49m[MENU GIAM DOC]\033[0m------------" << endl;
        cout << "|              Ban muon:              |"<< endl;
        cout << "|    \033[38;5;214m~\033[0m 1. Xuat thong tin nhan vien    |"<< endl;
        cout << "|    \033[38;5;214m~\033[0m 2. Xuat thong tin san pham     |" << endl;
        cout << "|    \033[38;5;214m~\033[0m 3. Xuat thong tin khach hang   |"<< endl;
        cout << "|          \033[38;5;214m~\033[0m 4. Doi mat khau          |"<< endl;
        cout << "|            \033[38;5;214m~\033[0m 5. Thoat               |"<< endl;
        cout << "---------------------------------------" << endl;
        cout.flush();
        setCursorPosition(25, 1); 
        cin >> luaChon;
        

        switch (luaChon) {
            case 1: {
                clearScreen();
                giamDoc.xuatThongTinNhanVien();
                break;
            }
            case 2: {
                clearScreen();
                giamDoc.xuatThongTinSanPham();
                break;
            }
            case 3: {
                clearScreen();
                giamDoc.xuatThongTinKhachHang();
                break;
            }
            case 4:
                clearScreen();
                doiMatKhau("GiamDoc",giamDoc.getTen());
                break;
            case 5:
                luaChon=6;
                break;
            default:
                cout << "Thoat khoi he thong." << endl;
        }
    } while (luaChon != 4);
}


