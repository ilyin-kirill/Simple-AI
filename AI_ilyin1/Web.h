#pragma once
#include <array>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
class Web
{
public:
    int mul[5][3]; // Тут будем хранить отмасштабированные сигналы
    int weight[5][3]; // Массив для хранения весов
    int input[5][3]; // Входная информация
    int limit = 10; // Порог - выбран экспериментально, для быстрого обучения
    int sum; // Тут сохраним сумму масштабированных сигналов
    void mul_w()
    {
        for (int x = 0; x <= 4; x++)
        {
            for (int y = 0; y <= 2; y++) // Пробегаем по каждому аксону
            {
                mul[x][y] = input[x][y] * weight[x][y]; // Умножаем его сигнал (0 или 1) на его собственный вес и сохраняем в массив.
            }
        }
    }
    void Sum()
    {
        sum = 0;
        for (int x = 0; x <= 4; x++)
        {
            for (int y = 0; y <= 2; y++)
            {
                sum += mul[x][y];
            }
        }
    }
    bool Rez()
    {
        if (sum >= limit)
            return true;
        else return false;
    }
    void recognize()
    {
        mul_w();
        Sum();
        if (Rez()) cout << " - True, Sum = " << sum << endl;
        else cout << " - False, Sum = " << sum << endl;
    }
    void incW(int** inP)
    {
        for (int x = 0; x <= 4; x++)
        {
            for (int y = 0; y <= 2; y++)
            {
                weight[x][y] += inP[x][y];
            }
        }
    }
    void decW(int** inP)
    {
        for (int x = 0; x <= 4; x++)
        {
            for (int y = 0; y <= 2; y++)
            {
                weight[x][y] -= inP[x][y];
            }
        }
    }
};