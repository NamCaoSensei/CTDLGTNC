// Trên ngôn ngữ C/C++, viết chương trình thực hiện yêu cầu sau:
// Câu 1. (2 -) Định nghĩa một cấu trúc Sinh viên bao gồm các trường thông tin như sau: Mã Sinh viên (kiểu số nguyên), tên Sinh viên (kiểu chuỗi ký tự), lớp (kiểu chuỗi ký tự), - tổng kết (kiểu số thực), hạnh kiểm (Tốt, khá, trung bình, yếu).
// Câu 2. (5 -) Sử dụng chiến lược chia để trị, cài đặt một cấu trúc cây nhị phân tìm kiếm cho kiểu dữ liệu Sinh viên với mã sinh viên làm trường Khóa, với các thao tác: 1) Khởi tạo cây; 2) Tạo mới một nút chứa dữ liệu; 3) Chèn nút vào cây; 4) Tìm kiếm phần tử trong cây; 5) Duyệt cây.
// Câu 3 : (1 -) Trong chương trình chính nhập vào một cây nhị phân tìm kiếm gồm n Sinh viên (n bất kỳ).
// Câu 4: (1 -) Trong chương trình chính sử dụng hàm Duyệt cây liệt kê ra màn hình danh sách tất cả sinh viên có trong cây.
// Câu 5: (1 -) Trong chương trình chính, nhập vào một mã số sinh viên, sử dụng hàm Tìm kiếm phần tử trong cây, hiển thị thông tin sinh viên có mã sinh viên vừa nhập, nếu không có trong cây nhị phân đưa ra thông báo không có sinh viên trong cây.

#include <iostream>
#include <string>

using namespace std;

struct sinhvien{
    int masv;
    string tensv;
    string lop;
    double diemtk;
    string hanhkiem;
};

struct node{
    sinhvien data;
    node *left;
    node *right;
};

void inittree(node *&root){
    root = NULL;
}

node* createnode(sinhvien sv){
    node* p=new node;
    p->data=sv;
    p->left=NULL;
    p->right=NULL;
    return p;
}

void insert(node *&root, sinhvien sv){
    if(root==NULL){
        root=createnode(sv);
    }else if(sv.masv<root->data.masv){
        insert(root->left, sv);
    }else{
        insert(root->right, sv);
    }
}

node* searchnode(node* root, int masv){
    if(root==NULL||root->data.masv==masv){
        return root;
    }else if(masv<root->data.masv){
        return searchnode(root->left, masv);
    }else{
        return searchnode(root->right, masv);
    }
}

void insv(sinhvien sv){
    cout<<"masv: "<<sv.masv<<", tensv: "<<sv.tensv<<", lop: "<<sv.lop<<", diemtk: "<<sv.diemtk<<", hanhkiem: "<<sv.hanhkiem<<endl;
}

void duyetcay(node* root){
    if(root!=NULL){
        duyetcay(root->left);
        insv(root->data);
        duyetcay(root->right);
    }
}

int main(){
    node *root = NULL;
    sinhvien sv;
    int n, masv;
    
    cout<<"Nhap so luong sinh vien: ";
    cin>>n;
    
    for(int i=0; i<n; i++){
        cout<<"Nhap thong tin sinh vien thu "<<i+1<<": "<<endl;
        cout<<"Ma sinh vien: "; cin>>sv.masv;
        cout<<"Ten sinh vien: "; cin.ignore(); getline(cin, sv.tensv);
        cout<<"Lop: "; getline(cin, sv.lop);
        cout<<"Diem tong ket: "; cin>>sv.diemtk;
        cout<<"Hanh kiem: "; cin.ignore(); getline(cin, sv.hanhkiem);
        insert(root, sv);
    }
    
    cout<<"\nDanh sach sinh vien trong cay: "<<endl;
    duyetcay(root);
    
    cout<<"\nNhap ma sinh vien can tim: ";
    cin>>masv;
    
    node *result = searchnode(root, masv);
    if(result != NULL){
        cout<<"\nThong tin sinh vien co ma "<<masv<<": "<<endl;
        insv(result->data);
    }else{
        cout<<"\nKhong tim thay sinh vien co ma "<<masv<<endl;
    }
    
    return 0;
}

