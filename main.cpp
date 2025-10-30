
//Сумму элементов массива, расположенных между первым и последним положительными элементами.

#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

template <typename T>
T get_value(const string& error_message)
{
    T value;
    while (!(cin >> value))
    {
        cout << error_message << "\n";
        cout << "Введите значение снова: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}


int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(NULL)));
    int size;
    while (true)
    {
        cout << "Введите размер массива: ";
        size = get_value<int>("Ошибка: Введите целое положительное число.");

        if (size <= 0) {
            cout << "Размер массива должен быть положительным.\n";
        }
        else
        {
            break;
        }
    }

    vector<int> arr(size);

    cout << "Выберите способ заполнения массива:\n";
    cout << "1. Ввод с клавиатуры\n";
    cout << "2. Использование случайных чисел\n";

    int choice;
    while (true)
    {
         choice = get_value<int>("Ошибка: Введите 1 или 2.");
        if (choice == 1||choice == 2)
        {
            break;
        }
        else
        {
            cout << "Неверное значение выберите из предложенных значений\n";
        }

    }

    switch (choice)
    {
    case 1:
        {
            cout << "Введите " << arr.size() << " элементов массива:\n";
            for (int i = 0; i < arr.size(); ++i)
            {
                cout << i+1 << " Элемент: ";
                arr[i] = get_value<int>("Ошибка: Введите целое число.");
            }
            break;
        }
    case 2:
        {

            cout << "Массив заполняется случайными числами...\n";
            for (int i = 0; i < arr.size(); ++i) {
                arr[i] = rand() % 101 - 50;
            }
            break;
        }
    }


    cout << "Массив: [ ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << "]\n";

    int first_positive_index = -1;
    int last_positive_index = -1;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > 0) {
            if (first_positive_index == -1) {
                first_positive_index = i;
            }
            last_positive_index = i;
        }
    }

    if (first_positive_index == -1 || last_positive_index == first_positive_index) {
        cout << "Не найдено двух разных положительных элементов.\n";
        return 0;
    }

    if(first_positive_index == last_positive_index - 1){
        cout << "Последний и первый положительные элементы стоят рядом\n";
        return 0;
    }

    long long sum = 0;
    for (int i = first_positive_index + 1; i < last_positive_index; ++i) {
        sum += arr[i];
    }



    cout << "Cумма элементов между первым и последним положительными: "
         << sum << "\n";

    return 0;
}