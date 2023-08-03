// Homework11.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class big_integer {
private:
    std::vector<int> biginteger;

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


};

int main()
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    number1.print();
    number2.print();
   // auto result = number1 + number2;
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
