#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
    long long n, int1 = 0, int2 = 0, tmp = 0, count2 = 0, int3 = 0, int4 = 0;
    cin >> n; //số case từng test
    string s[100000]; //dùng string để lưu từng case
    char c[10];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for(int j = 1; j < s[i].size(); ++j){
            if(s[i][j] >= '0' && s[i][j] <= '9' && s[i][j+1] == 'C'){
                s[i].push_back('*'); //đoạn này để phân loại 2 TH, vì tao thấy 2 TH khác nhau ở chỗ cái RxCy có xC còn cái còn lại thì không
            }                        //cái nào có dấu * ở đầu là TH1(tức RxCy) còn lại là TH2
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i][s[i].size()-1] == '*') {   //ktra xem có phải là TH1 ko
            for (int j = 1; j < s[i].size()-1; ++j) { //chạy từ j=1 để bỏ qua 'R' và j < s[i].size()-1 để bỏ qua dấu '*'
                if (s[i][j] >= '0' && s[i][j] <= '9') {
                    int1 = int1 * 10 + (s[i][j] - '0'); //int1 là số x trong RxCy (vd R23C55, int1 = 23)
                }
                else {
                    tmp = j; //tmp để lưu dấu 'C' ở đoạn nào (vd R23C55 thì tmp = 3)
                    break;
                }
            }
            for (int j = tmp + 1; j < s[i].size()-1; ++j) { //tương tự vòng lặp để tính int1, đây là vòng để tính int2
                if (s[i][j] >= '0' && s[i][j] <= '9') {     //int2 là số y trong RxCy (vd R23C55, int2 = 55)
                    int2 = int2 * 10 + (s[i][j] - '0');
                }
            }
            vector<char> v; //tạo vector v để lưu giá trị sau khi biến đổi y sang dạng ABC
            do {
                if(int2 % 26 == 0){    //TH chia hết tức kí tự là Z
                    v.push_back(26 - 1 + 'A');    //cái v.push_back hiểu đơn giản là nạp ký tự vào sau chuỗi, search gg để hiểu thêm
                    int2 = int2 / 26;
                    int2 -= 1;
                }else{
                    v.push_back(int2 % 26 - 1 + 'A');    //TH còn lại
                    int2 = int2 / 26;
                }            
            } while (int2 != 0);
            for (int i = v.size() - 1; i >= 0; --i) {   //vì chuỗi sau khi biến đổi bị ngược nên phải chạy i từ v.size()-1
                cout << v[i];   //in ra y sau khi bị biến đổi
            }                   /* thra ban đầu t muốn dùng string, nma string chả hiểu sao t insert nó kêu lỗi nên thôi dùng vector, chứ nếu string dc thì thời gian chạy sẽ nhanh hơn*/
            cout << int1 << endl; //in ra x
            int1 = 0; int2 = 0; tmp = 0; //reset biến sau mỗi TH
        }
        else {
            for (int j = 0; j < s[i].size(); ++j) {
                if (s[i][j] >= '0' && s[i][j] <= '9') {
                    int3 = int3 * 10 + (s[i][j] - '0'); //vd như BC23 thì int3 = 23
                }
                else {
                    tmp = j;    //lưu vị trí của kí tự gần số nhất (vd BC23, tmp để lưu vị trí của C và tmp = 1)
                }
            }
            for (int j = tmp; j >= 0; --j) {    //vòng lặp để đổi từ kí tự sang số
                int4 = int4 + (s[i][j] - 'A' + 1) * pow(26, count2);    //int4 là số sau khi biến đổi từ kí tự
                ++count2;                                               //vd BC23 thì int4 = 55
            }
            cout << "R" << int3 << "C" << int4 << endl;
            count2 = 0; int3 = 0; int4 = 0;   //  reset biến
        }
    }
}
