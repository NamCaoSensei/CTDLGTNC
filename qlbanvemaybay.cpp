// Sinh viên hãy lập trình giải bài toán quản lý vé máy bay, trong chương trình thực hiện các công việc sau:
// Câu 1. (2 -) Định nghĩa một cấu trúc Vé máy bay, bao gồm các trường thông tin như sau: Mã vé (kiểu số nguyên),
//   khởi hành (chuỗi ký tự),
// đến (kiểu chuối ký tự), giá vé (kiểu số thực). 
// Câu 2. (2 -) Viết hàm nhập vào một mảng gồm n vé máy bay
// Câu 3. (1 -) Viết hàm xuất ra mảng n vé máy bay vừa nhập.
// Câu 4. (2 -) Sử dụng phương pháp sắp xếp nhanh (Quick sort), viết hàm sắp xếp các vé máy bay theo chiều tăng dần của giá vé
// Câu 5. (1.5 -). Áp dụng chiến lược chia để trị (bằng thuật toán tìm kiếm nhị phân). Viết hàm tìm kiếm các vé máy bay có giá vé bằng X.
// Câu 6. (1.5 -). Viết hàm chính thực hiện:
// -       (0.5 -) Nhập vào n vé máy bay và hiển thị các vé máy bay vừa nhập
// -       (0.5 -) Sắp xếp n vé máy bay theo chiều tăng dần của giá vé.
// -       (0.5 -) Sử dụng hàm tìm kiếm hiển thị các vé máy bay có giá vé bằng X (X do người dùng nhập vào)

#include <iostream>
#include <string>

using namespace std;

struct vemaybay{
    int mave;
    string khoihanh;
    string den;
    double giave;
};

void nhapmangve(vemaybay a[], int n){
    for(int i=0; i<n; i++){
        cout << "Nhap thong tin ve may bay thu " << i+1 << ":\n";
        cout << "Ma ve: ";
        cin >> a[i].mave;
        cin.ignore(); // Xóa ký tự newline còn lại trong bộ đệm
        cout << "Khoi hanh: ";
        getline(cin, a[i].khoihanh);
        cout << "Den: ";
        getline(cin, a[i].den);
        cout << "Gia ve: ";
        cin >> a[i].giave;
        cin.ignore();
    }
}

void xuatmangve(vemaybay a[], int n){
    cout << "Danh sach ve may bay:\n";
    for(int i=0; i<n; i++){
        cout << "Ve thu " << i+1 << " | "
        << "Ma ve: " << a[i].mave << " | "
        << "Khoi hanh: " << a[i].khoihanh << " | "
        << "Den: " << a[i].den << " | "
        << "Gia ve: " << a[i].giave << "\n";
    }
}

void hoanvi(vemaybay &a, vemaybay &b){
    vemaybay temp = a;
    a = b;
    b = temp;
}

int partition(vemaybay a[], int low, int high) {
    double pivot = a[high].giave; // Chọn giá vé của phần tử cuối cùng làm pivot
    int i = low - 1; // Chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        if (a[j].giave < pivot) {
            i++;
            hoanvi(a[i], a[j]);
        }
    }
    hoanvi(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(vemaybay a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high); // Chia mảng thành hai phần

        quickSort(a, low, pi - 1); // Sắp xếp phần bên trái
        quickSort(a, pi + 1, high); // Sắp xếp phần bên phải
    }
}

void timkiemnhiphan(vemaybay a[], int n, double x) {
    int left = 0;
    int right = n - 1;
    int vitritimthay = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid].giave == x) {
            vitritimthay = mid;
            break;
        } else if (a[mid].giave < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (vitritimthay != -1) {
        int batDau = vitritimthay;
        int ketThuc = vitritimthay;
        
        while (batDau > 0 && a[batDau - 1].giave == x) batDau--;
        while (ketThuc < n - 1 && a[ketThuc + 1].giave == x) ketThuc++;

        cout << "\n=> TIM THAY cac ve co gia " << x << ":\n";
        for (int i = batDau; i <= ketThuc; i++) {
            cout << "Ma ve: " << a[i].mave 
                 << " | Tu: " << a[i].khoihanh 
                 << " | Den: " << a[i].den 
                 << " | Gia: " << a[i].giave << endl;
        }  
    }
    else {
        cout << "Khong tim thay ve may bay co gia ve " << x << ".\n";
    }
}

int main()
{
    int n;
    cout << "Nhap so luong ve may bay: ";
    cin >> n;

    vemaybay* a = new vemaybay[n];
    nhapmangve(a, n);
    xuatmangve(a, n);

    quickSort(a, 0, n - 1);
    cout << "\nDanh sach ve may bay sau khi sap xep theo gia ve tang dan:\n";
    xuatmangve(a, n);

    double x;
    cout << "\nNhap gia ve can tim kiem: ";
    cin >> x;
    timkiemnhiphan(a, n, x);

    delete[] a;
}   
