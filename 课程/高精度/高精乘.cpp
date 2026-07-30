#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 高精度乘法核心函数
// 传入两个存储着大整数每一位的动态数组 A 和 B
// 返回两者乘积的动态数组 C
vector<int> mul(vector<int> &A, vector<int> &B) {
    // 结果数组的最大长度不会超过两个乘数的长度之和
    // 初始化为 0，方便后续直接进行累加操作
    vector<int> C(A.size() + B.size(), 0);
    
    // 模拟竖式乘法：用 A 的每一位去乘以 B 的每一位
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            // 核心规律：A 的第 i 位乘 B 的第 j 位，结果累加到 C 的第 i+j 位
            C[i + j] += A[i] * B[j];
        }
    }
    
    // 统一处理进位
    int t = 0; // 记录当前的进位
    for (int i = 0; i < C.size(); i++) {
        t += C[i];       // 加上当前位累积的值
        C[i] = t % 10;   // 当前位最终留下的是对 10 取模的结果
        t /= 10;         // 计算向高位的进位
    }
    
    // 去除前导零
    // 比如 0 乘以任何数都是 0，或者乘积长度达不到最大理论长度时，高位会有多余的 0
    while (C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }
    
    return C;
}

int main() {
    // 优化输入输出流速度（算法竞赛常规操作）
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string a, b;
    if (cin >> a >> b) {
        vector<int> A, B;
        
        // 倒序存入数组，个位数存放在索引 0 的位置
        // 这样在处理进位时，可以直接向数组的尾部（也就是高位）追加，非常方便
        for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
        for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
        
        // 调用乘法函数
        vector<int> C = mul(A, B);
        
        // 倒序输出结果
        for (int i = C.size() - 1; i >= 0; i--) {
            cout << C[i];
        }
        cout << "\n";
    }
    
    return 0;
}