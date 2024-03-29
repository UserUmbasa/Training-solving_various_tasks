﻿#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
//Задача:
//У вас есть программа, которая считает значение функции f(x) для заданного значения x.Однако текущая реализация 
//функции требует слишком много времени на вычисление для больших x из - за повторных вычислений.Вам необходимо
//провести оптимизацию функции, чтобы ускорить её выполнение, особенно для больших значений x.
//
//Исходный код функции :
//```с++
//double func(double x) {
//    double result = 1.0;
//    for (int i = 1; i <= 1000000; i++) {
//        result += std::pow(x, i) / std::tgamma(i + 1);
//    }
//    return result;
//}
//```
//
//Требуется:
//1. Провести оптимизацию функции `func` для уменьшения времени выполнения, особенно для больших значений x.
//2. Проверить работоспособность новой оптимизированной функции на больших значениях x.

//решение
double func(double x)
{
    double result = 1.0;
    double lhs = 1;
    double rhs = 1;

    for (int i = 1; i <= 10000000; i++)
    {
        //где pow число х в степени i - exponent
        //tgamma факториал ...1*2*3*4 и т.д
        lhs = lhs * x;
        rhs = rhs * i;
        result += lhs / rhs;
    }
    return result;
}
//Предложенный ответ оптимизированной функции вполне соответствует ожиданиям по ускорению выполнения.Произведены следующие оптимизации :
//-Использование отдельных переменных lhs и rhs для хранения значения степени и значения факториала, 
//что позволяет избежать вызова std::pow и std::tgamma на каждой итерации цикла.
//- Произведены прямые вычисления степени и факториала внутри цикла.
//
//Этот код будет работать значительно быстрее и эффективнее исходной версии, особенно для больших значений x и 
//большего количества итераций.
int main()
{
    setlocale(LC_ALL, "Russian");
    auto c = func(2);

    return 0;
}
