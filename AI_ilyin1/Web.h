#pragma once
#include <array>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
class Web
{
public:
    int mul[5][3]; // ��� ����� ������� ������������������ �������
    int weight[5][3]; // ������ ��� �������� �����
    int input[5][3]; // ������� ����������
    int limit = 10; // ����� - ������ ����������������, ��� �������� ��������
    int sum; // ��� �������� ����� ���������������� ��������
    void mul_w()
    {
        for (int x = 0; x <= 4; x++)
        {
            for (int y = 0; y <= 2; y++) // ��������� �� ������� ������
            {
                mul[x][y] = input[x][y] * weight[x][y]; // �������� ��� ������ (0 ��� 1) �� ��� ����������� ��� � ��������� � ������.
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