﻿// Homework11.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>



class big_integer {
private:
    std::vector<int> biginteger;

    void modern10(std::vector<int>& vec) {
        for (int k = 0; k < vec.size(); k++) {
            if (k == (vec.size() - 1)) {
                if (vec[k] >= 10) {
                    vec.push_back(vec[k] / 10);
                    vec[k] = vec[k] % 10;
                }
            }
            else if (vec[k] >= 10) {
                vec[k + 1] = vec[k + 1] + (vec[k] / 10);
                vec[k] = vec[k] % 10;
            }
        }
    }

public:
    big_integer (const std::string& input){
        char tmp;
        for (int i = 0; i < input.size(); i++) {
            tmp = input[i];
            biginteger.push_back(std::stoi(&tmp));
        }
    }

    void const print() {
        for (auto it = biginteger.begin(); it != biginteger.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    ~big_integer() {
        biginteger.clear();
    }

    big_integer(big_integer& other) {
        biginteger = std::move(other.biginteger);
    }

    big_integer(std::vector<int> neww) {
        biginteger = neww;
    }
    
    big_integer& operator = (big_integer&& other) {
        if (&other != this) {
            biginteger = other.biginteger;
            other.biginteger.clear();
        }
        return *this;
    }
    big_integer operator + (big_integer other) {
        std::reverse(biginteger.begin(), biginteger.end());
        std::reverse(other.biginteger.begin(), other.biginteger.end());
        if (biginteger.size() < other.biginteger.size()) {
            biginteger.resize(other.biginteger.size());
        }
        std::vector<int> tmp;
        int tmp2;
        int nextten = 0;
        for (int i = 0; i < biginteger.size(); i++) {
            if (i >= other.biginteger.size()) {
                tmp.push_back(biginteger[i]);
            }
            else {
                tmp2 = biginteger[i] + other.biginteger[i];
                if (tmp2 >= 10) {
                    if (i == 0) {
                        tmp2 -= 10;
                        nextten = 1;
                    }
                    else {
                        tmp2 -= 10;
                        biginteger[i + 1] += 1;
                    }
                }
                tmp.push_back(tmp2);
            }
        }
        if (nextten == 1) {
            tmp.push_back(1);
        }
        std::reverse(tmp.begin(), tmp.end());
        big_integer ret(tmp);
        return ret;
    }
    big_integer operator * (big_integer other) {
        std::reverse(biginteger.begin(), biginteger.end());
        std::reverse(other.biginteger.begin(), other.biginteger.end());
        std::vector<int> tmpsum1;
        std::vector<int> tmpsum2;
        int tmp;
        int nextten = 0;
        for (int i = 0; i < other.biginteger.size(); i++) {
            
            for (int j = 0; j < biginteger.size(); j++) {
                tmp = biginteger[j] * other.biginteger[i];
                tmpsum1.push_back(tmp);
            }
            //here was modern10 v1.0
            modern10(tmpsum1);
            for (int g = 0; g < i; g++) {
                tmpsum1.insert(tmpsum1.begin(), 0);
            }
            if (tmpsum2.size() < tmpsum1.size()) {
                tmpsum2.resize(tmpsum1.size());
            }
            for (int l = 0; l < tmpsum1.size(); l++) {
                tmpsum2[l] = tmpsum2[l] + tmpsum1[l];
            }
            modern10(tmpsum2);
            tmpsum1.clear();
        }
        std::reverse(tmpsum2.begin(), tmpsum2.end());
        big_integer ret(tmpsum2);
        return ret;
    }
};

int main()
{
    auto number2 = big_integer("114575");
    auto number1 = big_integer("78524");
    number1.print();
    number2.print();
    auto result = number1 * number2;
    result.print();
    //std::cout << result; // 193099

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
