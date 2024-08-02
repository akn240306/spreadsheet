#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
    long long n, int1 = 0, int2 = 0, tmp = 0, reminder = 0, count2 = 0, int3 = 0, int4 = 0;
    cin >> n; //số case từng test
    string s[1000]; //dùng string để lưu từng case
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
                v.push_back(int2 % 26 - 1 + 'A');    //đây là đoạn biến đổi theo cthuc như trong note t ghi
                int2 = int2 / 26;                    //cái v.push_back hiểu đơn giản là nạp ký tự vào sau chuỗi, search gg để hiểu thêm
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
                if (count2 == 0) { //đọc dòng /* phía dưới trước
                    reminder = s[i][j] - 'A' + 1;   //reminder để tính số dư khi lấy kí tự biến đổi sang số chia cho 26
                    ++count2;                       //vd BC23 thì BC biến đổi thành 55 / 26 dư 3 => reminder = 3
                }                                   //nhưng vì là chuỗi nên t phải làm cồng kềnh nnay
                else {
                    int4 = (s[i][j] - 'A' + 1) * 26 * count2; /*đây là cthuc ban đầu t nghĩ ra nma vì vướng cái count2 nên mới phải chia 2 TH count2 */
                    ++count2;                                  //int4 là kí tự sau khi biến đổi thành số
                }                                              //vd BC23 thì int4 = 55
            }
            int4 += reminder;
            cout << "R" << int3 << "C" << int4 << endl;
            reminder = 0; count2 = 0; int3 = 0; int4 = 0;   //  reset biến
        }
    }
}
