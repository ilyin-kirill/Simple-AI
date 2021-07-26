// AI_ilyin1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
using namespace std;
#include "Web.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
void recognize()
{
    Web NW1;
    NW1.mul_w();
    NW1.Sum();
    if (NW1.Rez())
        cout << "True, Sum - " << endl;
    else cout << " - False, Sum = " << endl;
}
int** data_in(string path)
{
    int** input = new int*[5];
    ifstream in;
    int inchar;
    in.open(path);
    for (int j = 0; j < 5; j++) {
        input[j] = new int[3];
        for (int i = 0; i < 3; i++) {
            in >> inchar;
            input[j][i] = inchar;
        }
    }
    return input;
}
void data_out(int** output, ostream& f)
{
    for (int j = 0; j < 5; ++j) {
        for (int i = 0; i < 3; ++i) {
            f << output[j][i] << " ";
        }
        f << endl;
    }
}
int main()
{
    Web NW1;
    ifstream in;
    ofstream out;
    string path_w;
    string a;
    bool c;
    cout << "Enter the name of weight file:" << endl;
    cin >> path_w;
    int** weight = data_in(path_w);
    for (int j = 0; j < 5; ++j) {
        for (int i = 0; i < 3; ++i) {
            NW1.weight[j][i] = weight[j][i];
        }
    }
    for (int k = 1; k < 48; k++) {
        int** input = data_in(to_string(k)+".txt");
        data_out(input, cout);
        for (int j = 0; j < 5; ++j) {
            for (int i = 0; i < 3; ++i) {
                NW1.input[j][i] = input[j][i];
            }
        }
        NW1.recognize();
        cout << "Correct?" << endl;
        cin >> c;
        if (c == false)
            if (NW1.Rez()) NW1.decW(input);
            else NW1.incW(input);
    }
    for (int j = 0; j < 5; ++j) {
        for (int i = 0; i < 3; ++i) {
            weight[j][i] = NW1.weight[j][i];
        }
    }
    out.open(path_w);
    data_out(weight, out);
}

