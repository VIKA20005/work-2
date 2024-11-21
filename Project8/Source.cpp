//Задание 2
//Создайте интерфейс IMath.В нём должно быть четыре метода :
//? int Max() — возвращает максимум;
//? int Min() — возвращает минимум;
//Практическое задание
//1
//? float Avg() — возвращает среднеарифметическое;
//? bool Search(int valueToSearch) — ищет valueSearch
//внутри контейнера данных.Возвращает true, если
//значение найдено.Возвращает false, если значение
//не найдено.
//Класс, созданный в первом задании Array, должен
//имплементировать интерфейс IMath.
//Метод Max — возвращает максимум среди элементов
//массива.
//Метод Min — возвращает минимум среди элементов
//массива.
//Метод Avg — возвращает среднеарифметическое
//среди элементов массива.
//Метод Search — ищет значение внутри массива.Возвращает true, если значение найдено.Возвращает false,
//если значение не найдено.
//Напишите код для тестирования полученной функциональности.

#include <iostream>
#include <vector>

using namespace std; 


class IOutput 
{
public:
    virtual void Show() = 0; 
    virtual void Show(const char* info) = 0; 
    virtual ~IOutput() = default;
};


class IMath 
{
public:
    virtual int Max() = 0; 
    virtual int Min() = 0; 
    virtual float Avg() = 0; 
    virtual bool Search(int valueToSearch) = 0; 
    virtual ~IMath() = default;
};


class Array : public IOutput, public IMath 
{
private:
    vector<int> arr; 

public:
    
    Array(const vector<int>& data) : arr(data) {}

   
    void Show() override 
    {
        cout << "Элементы массива: ";
        for (int num : arr) 
        {
            cout << num << " ";
        }
        cout << endl;
    }

    
    void Show(const char* info) override 
    {
        cout << info << endl;
        Show(); 
    }

    
    int Max() override 
    {
        if (arr.empty()) return 0;
        int maxVal = arr[0]; 
        for (int num : arr) 
        {
            if (num > maxVal) 
            {
                maxVal = num;
            }
        }
        return maxVal;
    }

    
    int Min() override 
    {
        if (arr.empty()) return 0; 
        int minVal = arr[0]; 
        for (int num : arr) 
        {
            if (num < minVal) 
            {
                minVal = num;
            }
        }
        return minVal;
    }

    
    float Avg() override 
    {
        if (arr.empty()) 
        {
            return 0.0f; 
        }
        int sum = 0;
        for (int num : arr) 
        {
            sum += num;
        }
        return static_cast<float>(sum) / arr.size(); 
    }

    
    bool Search(int valueToSearch) override 
    {
        for (int num : arr) 
        {
            if (num == valueToSearch) 
            {
                return true;
            }
        }
        return false; 
    }
};


int main() 
{
   
    vector<int> data = { 1, 2, 3, 4, 5 };
    Array myArray(data);

    myArray.Show();

    
    myArray.Show("Дополнительное сообщение: Массив целых чисел");

    
    cout << "Максимум: " << myArray.Max() << endl;
    cout << "Минимум: " << myArray.Min() << endl;
    cout << "Среднее арифметическое: " << myArray.Avg() << endl;

    
    int valueToSearch = 3;
    if (myArray.Search(valueToSearch)) 
    {
        cout << "Значение " << valueToSearch << " найдено в массиве." << endl;
    }
    else 
    {
        cout << "Значение " << valueToSearch << " не найдено в массиве." << endl;
    }

    
    valueToSearch = 10;
    if (myArray.Search(valueToSearch)) 
    {
        cout << "Значение " << valueToSearch << " найдено в массиве." << endl;
    }
    else 
    {
        cout << "Значение " << valueToSearch << " не найдено в массиве." << endl;
    }

    return 0;
}