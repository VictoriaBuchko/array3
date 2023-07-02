#include <iostream>
#include <string>//используется для создания массива с типом данных string в Task 3
using namespace std;

int main() {

    cout << "Task 1-------------------------------------------------------------------------------------------------------\n\n";

    /*Написать программу, копирующую последовательно элементы
     одного массива размером 10 элементов в 2 массива размером
     5 элементов каждый	*/
     
    const int SIZE = 10;
    const int SIZE2 = 5;

    int start = 10;
    int end = 20;

    int arr1[SIZE];
    int arr2[SIZE2], arr3[SIZE2];

    srand(time(0));

    for (int i = 0; i < SIZE; i++)
    {
        arr1[i] = start + rand() % (end - start);
        cout << arr1[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < SIZE2; i++)
    {
        arr2[i] = arr1[i];
        arr3[i] = arr1[i + 5];
    }

    cout << "1 array \t 2 array\n";
    for (int i = 0; i < SIZE2; i++)
    {
        cout << arr2[i] << "\t\t " << arr3[i] << endl;
    }

    cout << "\n\nTask 2-------------------------------------------------------------------------------------------------------\n\n";
    
    /*
    Напишите программу, которая выполняет поэлементную
    сумму двух массивов и результат заносит в третий массив.
    Элементы массивов можно сгенерировать в произвольном
    диапазоне
    */
    const int SIZE4 = 10;

    int start1 = 10;
    int end1 = 20;

    int arr11[SIZE4];
    int arr12[SIZE4];
    int arr13[SIZE4];

    srand(time(0));

    cout << "1 array" << endl;

    for (int i = 0; i < SIZE4; i++)
    {
        arr11[i] = start1 + rand() % (end1 - start1);
        arr12[i] = start1 + rand() % (end1 - start1);
        arr13[i] = arr11[i] + arr12[i];
        cout << arr11[i] << " ";
    }

    cout << "\n2 array" << endl;

    for (int i = 0; i < SIZE4; i++)
    {
        cout << arr12[i] << " ";
    }

    cout << "\n3 array" << endl;

    for (int i = 0; i < SIZE4; i++)
    {
        cout << arr13[i] << " ";
    }

    cout << "\n\nTask 3-------------------------------------------------------------------------------------------------------\n\n";
    
    
    /* Пользователь вводит данные о своих расходах в долларах за неделю (каждый день).
       Написать программу, которая вычисляет:
        ■ среднюю (за неделю) потраченную сумму;
        ■ общую сумму, потраченную пользователем за неделю;
        ■ количество дней и их названия (например, «вторник»),
          когда сумма расхода (в день) превысила 100 долларов.
*/


    const int WEEK = 7;
    string days[WEEK] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    int expenses[WEEK];

    // заполнение масива
    for (int i = 0; i < WEEK; i++)
    {
        cout << "Enter expenses for " << days[i] << ": ";
        cin >> expenses[i];
    }

    // общая сума и среднее арифметическое 
    double totalExpenses = 0;
    for (int i = 0; i < WEEK; i++)
    {
        totalExpenses += expenses[i];
    }
    double average = totalExpenses / WEEK;

    cout << "\nAverage amount spent per week: " << average << "\n\n";
    cout << "Total spend per week: " << totalExpenses << "\n\n";

    //вычесление дней когда сумма расходом выше 100
    int count = 0;
    for (int i = 0; i < WEEK; i++) {
        if (expenses[i] > 100) {
            count++;
            cout << "Spending over $100: " << days[i] << endl;
        }
    }
    cout << "Number of days the expense exceeded $100: " << count << endl;


    cout << "\n\nTask 4-------------------------------------------------------------------------------------------------------\n\n";
    /*
       Известны данные курса валют (курс доллара по отношению
       к евро) за все месяцы года и начисленные проценты за каждый месяц на депозитном счету в евро.
       Все данные вводятся пользователем, в том числе и сумма на депозите в евро.
       Написать программу, которая по запросу пользователя (номер месяца) выводит в консоль размер допустимой суммы,
       которую он может обналичить, при условии, что у него долларовая карта, обналичить можно не более 50% от начисленной
       суммы в том случае, если начисленная сумма в этот месяц составляет не менее 500$.
    */

    const int numMonths = 12;

    double exchangeRates[numMonths];//обменные курсы
    double percentRates[numMonths];//процентная ставка

    //Введите курсы доллара по расчету к евро за каждый месяц (год)
    cout << "Enter dollar to euro exchange rates for each month (year):\n";
    for (int i = 0; i < numMonths; ++i) {

        cout << "Month " << (i + 1) << ": ";
        cin >> exchangeRates[i];
    }

    cout << endl;

    //Введите начисленные проценты за каждый:
    for (int i = 0; i < numMonths; ++i) {
    cout << "Enter the accrued interest for each month:\n";

        cout << "Month " << (i + 1) << ": ";
        cin >> percentRates[i];
    }

    cout << endl;

    double depositAmount;
    cout << "Enter the deposit amount in euros: ";//введите сумму на депозите в евро
    cin >> depositAmount;

    int desiredMonth;
    cout << "Enter the number of the month: ";//введите номер месяца, для которого вы хотите узнать размер допустимой суммы
    cin >> desiredMonth;

    //размер допустимой суммы
    double accruedAmount = depositAmount; //начальная сумма равна сумме на депозитe

    for (int i = 0; i < desiredMonth; ++i) {

        double percent = (accruedAmount * percentRates[i]) / 100.0;//вычисляем сумму процентов за текущий месяц
        accruedAmount += percent;//добавляем сумму процентов к общей накопленной сумме
    }

    double availableAmount = 0;
    if (accruedAmount >= 500) {
        double fiftyPercent = accruedAmount / 2;//вычисляем 50% от общей накопленной суммы

        if (fiftyPercent < depositAmount) {//eсли 50% суммы меньше суммы на депозите

            availableAmount = fiftyPercent;//устанавливаем доступную сумму равной 50% от общей накопленной суммы
        }
        else {

            availableAmount = depositAmount;//устанавливаем доступную сумму равной сумме на депозите
        }
    }

    cout << "Amount allowed: " << availableAmount << endl;//Размер допустимой суммы

    return 0;
}




