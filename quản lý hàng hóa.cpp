// Sinh viên hãy lập trình giải bài toán quản lý hàng hóa, trong chương trình thực hiện các công việc sau:
// Câu 1. (2 -) Định nghĩa cấu trúc hàng hóa bao gồm các thông tin: Mã hàng hóa, tên hàng hóa, ngày xuất hàng (kiểu ngày/tháng/năm), ví dụ 10/10/2000), giá xuất hàng đi (đơn vị triệu đồng).
// Câu 2. (2 -) Viết hàm nhập vào một mảng gồm n hàng hóa
// Câu 3. (1 -) Viết hàm xuất ra mảng n hàng hóa vừa nhập.
// Câu 4. (2 -) Sử dụng phương pháp sắp xếp chọn trực tiếp(Selection sort), viết hàm sắp xếp các hàng hóa theo chiều tăng dần của giá xuất hàng đi
// Câu 5. (1.5 -). Áp dụng chiến lược chia để trị (bằng thuật toán tìm kiếm nhị phân). Viết hàm tìm kiếm các hàng hóa có giá xuất hàng đi bằng X.
// Câu 6. (1.5 -). Viết hàm chính thực hiện:
// -       (0.5 -) Nhập vào n hàng hóa và hiển thị các hàng hóa vừa nhập
// -       (0.5 -) Sắp xếp n hàng hóa theo chiều tăng dần của giá xuất hàng đi.
// -       (0.5 -) Sử dụng hàm tìm kiếm hiển thị các hàng hóa có giá xuất hàng đi bằng X (X do người dùng nhập vào)

#include <iostream>
#include <string>

using namespace std;

struct HangHoa {
    string maHang;
    string tenHang;
    int ngay, thang, nam;
    float giaXuat;
};

void nhapdanhSachHangHoa(HangHoa ds[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap ma hang hoa: ";
        cin >> ds[i].maHang;
        cout << "Nhap ten hang hoa: ";
        cin.ignore();
        getline(cin, ds[i].tenHang);
        cout << "Nhap ngay xuat (ngay thang nam): ";
        cin >> ds[i].ngay >> ds[i].thang >> ds[i].nam;
        cout << "Nhap gia xuat (trieu dong): ";
        cin >> ds[i].giaXuat;
    }
}

void xuatDanhSachHangHoa(HangHoa ds[], int n) {
    cout << "Danh sach hang hoa:\n";
    for (int i = 0; i < n; i++) {
        cout << "Ma hang: " << ds[i].maHang << ", Ten hang: " << ds[i].tenHang
             << ", Ngay xuat: " << ds[i].ngay << "/" << ds[i].thang << "/" << ds[i].nam
             << ", Gia xuat: " << ds[i].giaXuat << " trieu dong\n";
    }
}

void selectionSort(HangHoa ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (ds[j].giaXuat < ds[minIndex].giaXuat) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(ds[i], ds[minIndex]);
        }
    }
}

void timKiemNhiPhan(HangHoa a[], int n, double X) {
    int left = 0, right = n - 1;
    int viTriTimThay = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid].giaXuat == X) {
            viTriTimThay = mid;
            break;
        }
        if (a[mid].giaXuat < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (viTriTimThay != -1) {
        int batDau = viTriTimThay;
        int ketThuc = viTriTimThay;

        while (batDau > 0 && a[batDau - 1].giaXuat == X) batDau--;
        while (ketThuc < n - 1 && a[ketThuc + 1].giaXuat == X) ketThuc++;

        cout << "\n=> TIM THAY cac hang hoa co gia xuat " << X << " trieu dong:\n";
        for (int i = batDau; i <= ketThuc; i++) {
            xuatDanhSachHangHoa(&a[i], 1);
        }
    } else {
        cout << "\n=> KHONG TIM THAY hang hoa nao co gia xuat " << X << " trieu dong.\n";
    }
}

int main() {
    int n;
    cout << "Nhap so luong hang hoa: ";
    cin >> n;

    HangHoa ds[n];
    nhapdanhSachHangHoa(ds, n);
    xuatDanhSachHangHoa(ds, n);

    selectionSort(ds, n);
    cout << "\nDanh sach hang hoa sau khi sap xep theo gia xuat tang dan:\n";
    xuatDanhSachHangHoa(ds, n);

    double X;
    cout << "\nNhap gia xuat can tim kiem: ";
    cin >> X;
    timKiemNhiPhan(ds, n, X);

    return 0;
}
