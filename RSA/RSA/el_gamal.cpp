//// Lab12_ElGamal.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
////
//
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int p1;
////взяли какое-то число P
////нужно взять некоторое число g, которое будет первообразным корнем Р по модулю P
////случайное число x
////берём y=g^x mod p
////(y, g, p) - public key
////x - secret key
////k - псп(закодированная хуйня?)
////a = g^k mod p
////b = m*y^k mod p
//
//int gcd(int a, int b) {
//    int r;
//    while (a % b > 0) {
//        r = a % b;
//        a = b;
//        b = r;
//    }
//    return b;
//}
//
//int power(int a, int b, int c) {
//    int x = 1;
//    int y = a;
//    while (b > 0) {
//        if (b % 2 != 0) {
//            x = (x * y) % c;
//        }
//        y = (y * y) % c;
//        b = int(b / 2);
//    }
//    return x % c;
//}
//
////int power(int x, int y, int n) {
////    int result = x % n;
////    for (int i = 1; i < y; i++) {
////        result = (result * x) % n;
////    }
////
////    return result;
////}
//
//void FastExponention(int bit, int n, int* y, int* a)
//{
//    if (bit == 1) {
//        *y = (*y * (*a)) % n;
//    }
//
//    *a = (*a) * (*a) % n;
//}
//
//int FindT(int a, int m, int n)
//{
//    int r;
//    int y = 1;
//
//    while (m > 0)
//    {
//        r = m % 2;
//        FastExponention(r, n, &y, &a);
//        m = m / 2;
//    }
//
//    return y;
//}
//
//bool isPrime(int a, int i)
//{
//    int n = i - 1;
//    int k = 0;
//    int m, T;
//
//    while (n % 2 == 0)
//    {
//        k++;
//        n = n / 2;
//    }
//
//    m = n;
//    T = FindT(a, m, i);
//    if (T == 1 || T == i - 1) {
//        return true;
//    }
//
//    for (int j = 0; j < k; j++)
//    {
//        T = FindT(T, 2, i);
//        if (T == 1) {
//            return false;
//        }
//        if (T == i - 1) {
//            return true;
//        }
//    }
//
//    return false;
//}
//
//int keyGen2() {
//    int key;
//    do {
//        do
//            key = rand() + 256;
//        while (key % 2 == 0);
//
//    } while (!isPrime(2, key));
//    return key;
//}
//
//int genKey(int p) {
//    int key;
//    key = (rand() % p) + (int)(pow(2, 20));
//    while (gcd(p, key) != 1)
//        key = (rand() % p) + (int)(pow(2, 20));
//    return key;
//}
//
//vector<int> encrypt(string msg, int q, int h, int g) {
//    vector<int> encrypted;
//    int key = genKey(q);
//    int s = power(h, key, q);
//    p1 = power(g, key, q);
//    for (int i = 0; i < msg.size(); i++)
//        encrypted.push_back(msg[i]);
//    cout << "g^k: " << p1 << endl;
//    cout << "g^ak: " << s << endl;
//
//    for (int i = 0; i < encrypted.size(); i++) {
//        int num = s * (int)(encrypted[i]);
//        encrypted[i] = num;
//    }
//    return encrypted;
//}
//
//string decrypt(vector<int> encrypted, int key, int q) {
//    string decrypted;
//    int h = power(p1, key, q);
//    for (int i = 0; i < encrypted.size(); i++) {
//        int num = encrypted[i] / h;
//        decrypted.push_back(encrypted[i] / h);
//    }
//    return decrypted;
//}
//
//int main()
//{
//
//    string s = "aboba";
//    cout << endl;
//
//    int q = rand() % (int)(pow(2, 20)) + (int)(pow(2, 10));
//    //int q = 107;
//    int g = rand() % q + 2;
//    //int g = 67;
//    int key = genKey(q);
//    int h = power(g, key, q);
//    vector<int> enc2 = encrypt(s, q, h, g);
//    for (int i = 0; i < enc2.size(); i++) {
//        cout << "Enc2: " << enc2[i] << " ";
//    }
//    cout << endl;
//    string decr2 = decrypt(enc2, key, q);
//    cout << "Decr2: " << decr2 << endl;
//}