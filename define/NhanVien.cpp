#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>  
#include "../declare/NhanVien.h"
#include "../declare/SanPham.h"
#include "../declare/Date.h"

using namespace std;

NhanVien::NhanVien(const string& ten, const string& matKhau, const string& hoTen, const Date& ngaySinh, const string& sdt, const string& lichLamViec)
    : User(ten, matKhau), hoTen(hoTen), ngaySinh(ngaySinh), sdt(sdt), lichLamViec(lichLamViec) {}

void NhanVien::docDanhSachNhanVien(std::vector<NhanVien*>& dsNhanVien) {
    std::ifstream file("../resources/NhanVien.txt");
    if (!file) {
        std::cerr << "Khong the mo file NhanVien.txt" << std::endl;
        return;
    }
    std::string ten, matKhau, lichLamViec, hoTen, sdt;
    int ngay, thang, nam;

    while (file >> ten >> matKhau >> lichLamViec) {
        hoTen.clear();
        char ch;
        while (file.get(ch) && !isdigit(ch)) {
            hoTen += ch;
        }
        file.putback(ch);
        
        file >> ngay >> thang >> nam >> sdt;

        Date date(ngay, thang, nam);
        NhanVien* nhanVien = new NhanVien(ten, matKhau, hoTen, date, sdt, lichLamViec);
        dsNhanVien.push_back(nhanVien);
        std::cout << "Nhan vien " << nhanVien->getTen() << " da duoc them vao danh sach." << std::endl;
    }

    file.close();
}

int NhanVien::getSoCaDaLam() const {
    int soCaDaLam = 0;
    for (char c : lichLamViec) {
        if (c != '0') {
            soCaDaLam++;
        }
    }
    return soCaDaLam;
}

string NhanVien::getHoTen() const {
    return hoTen;
}

Date NhanVien::getNgaySinh() const {
    return ngaySinh;
}

string NhanVien::getSdt() const {
    return sdt;
}

string NhanVien::getCaLam() const {
    return lichLamViec;
}

void NhanVien::nhapSanPham(vector<SanPham*>& khoHang, const string& loaiSanPham, int soLuong) { 
    bool daTonTai = false;

    for (auto& sp : khoHang) {
        if (sp->getTenSanPham() == loaiSanPham) { 
            sp->themSanPhamVaoDoHang(soLuong);
            daTonTai = true;
            break;
        }
    }

    if (!daTonTai) {
        
        cout << "Sản phẩm mới cần được thêm vào kho!" << endl;
    }

    cout << "Đã nhập " << soLuong << " sản phẩm vào kho." << endl;
}
void NhanVien::xoaSanPham(SanPham* sanPham, int soLuong) {
    int slHienTai = sanPham->getSoLuong(); 
    if (slHienTai >= soLuong) {
        sanPham->setSoLuong(slHienTai - soLuong); 
        cout << "Da xoa " << soLuong << " san pham khoi kho." << endl;
    } else {
        cout << "Khong du so luong san pham de xoa." << endl;
    }
    if (sanPham->getSoLuong() <= 0) {
        cout << "San pham da het hang." << endl;
    }
}

void NhanVien::dangKyCaLam() {
    lichLamViec = "0000000"; 

    cout << "Dang ky lich lam viec cho tung ngay trong tuan:" << endl;
    const string ngayTrongTuan[7] = {"Chu Nhat", "Thu Hai", "Thu Ba", "Thu Tu", "Thu Nam", "Thu Sau", "Thu Bay"};

    int ngay = 0;

    while (ngay < 7) {
        bool validInput = false;

        while (!validInput) {
            cout << ngayTrongTuan[ngay] << ": " << endl;
            cout << "1. Ca sang" << endl;
            cout << "2. Ca chieu" << endl;
            cout << "3. Khong lam" << endl;
            cout << "4. Quay lai chon ngay khac" << endl;
            cout << "Lua chon cua ban (1-4): ";

            int luaChon;
            cin >> luaChon;

            switch (luaChon) {
                case 1:
                    lichLamViec[ngay] = '1'; 
                    cout << "Ban da chon lam ca sang." << endl;
                    validInput = true;
                    ngay++;
                    break;
                case 2:
                    lichLamViec[ngay] = '2'; 
                    cout << "Ban da chon lam ca chieu." << endl;
                    validInput = true;
                    ngay++;
                    break;
                case 3:
                    lichLamViec[ngay] = '0'; 
                    cout << "Ban da chon khong lam viec ngay nay." << endl;
                    validInput = true;
                    ngay++;
                    break;
                case 4:
                    if (ngay > 0) {
                        ngay--; 
                        cout << "Quay lai chon ngay truoc." << endl;
                    } else {
                        cout << "Ban dang o ngay dau tien, khong the quay lai." << endl;
                    }
                    validInput = true;
                    break;
                default:
                    cout << "Lua chon khong hop le! Vui long nhap lai." << endl;
            }
        }
    }

    ifstream fileIn("../resources/NhanVien.txt");
    if (!fileIn) {
        cout << "Khong the mo file NhanVien.txt!" << endl;
        return;
    }

    vector<string> lines;
    string line;
    bool found = false;

    while (getline(fileIn, line)) {
        if (line.find(this->getTen()) != string::npos) {
            vector<string> tokens;
            stringstream ss(line);
            string token;

            while (ss >> token) {
                tokens.push_back(token);
            }

            if (!tokens.empty()) {
                tokens.back() = lichLamViec;
                found = true;
            }

            line = "";
            for (size_t i = 0; i < tokens.size(); ++i) {
                line += tokens[i];
                if (i != tokens.size() - 1) {
                    line += " ";
                }
            }
        }

        lines.push_back(line);
    }

    fileIn.close();

    if (!found) {
        cout << "Khong tim thay nhan vien voi ten dang nhap nay." << endl;
        return;
    }

    ofstream fileOut("../resources/NhanVien.txt");
    if (!fileOut) {
        cout << "Khong the mo file NhanVien.txt de ghi!" << endl;
        return;
    }

    for (const string& updatedLine : lines) {
        fileOut << updatedLine << endl;
    }

    fileOut.close();

    cout << "Da dang ky lich lam viec thanh cong: " << lichLamViec << endl;
}

void NhanVien::hienThiThongTin() const {
    cout << "Ho ten: " << hoTen << endl;
    cout << "Ngay sinh: " << ngaySinh.getNgay() << "/" << ngaySinh.getThang() << "/" << ngaySinh.getNam() << endl;
    cout << "So dien thoai: " << sdt << endl;
    cout << "Lich lam viec: " << lichLamViec << endl;
}

