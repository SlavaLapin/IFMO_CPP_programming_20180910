//В кинотеатре n рядов по m мест в каждом (n и m не превосходят 20). 
// В двумерном массиве хранится информация о проданных билетах, число 1 означает, 
// что билет на данное место уже продан, число 0 означает, что место свободно. 
// Поступил запрос на продажу k билетов на соседние места в одном ряду. 
// Определите, можно ли выполнить такой запрос.
//
//Формат входных данных
//        Программа получает на вход числа n и m. Далее идет n строк, содержащих m чисел (0 или 1), разделенных пробелами. Затем дано число k.
//Формат выходных данных
//        Программа должна вывести номер ряда, в котором есть k подряд идущих свободных мест. 
// Если таких рядов несколько, то выведите номер наименьшего подходящего ряда. 
// Если подходящего ряда нет, выведите число 0.
//
//Sample Input:
//
//3 4
//0 1 0 1
//1 0 0 1
//1 1 1 1
//2
//Sample Output:
//
//2

#include "t06_cinema.h"
#include <iostream>


using namespace std;

int t06_cinema() {
    int *arr, n, m, k;
    int res = 0;
    cin >> n >> m;
    arr = (int*) malloc(sizeof(int)*n*m);
    for(int i = 0; i < n*m; i++){
        cin >> arr[i];
    }
    cin >> k;

    for(int i = 0; i < n; i++){
        int adj = 0;
        int prev = 1;
        for(int j = 0; j < m; j++){

            if(arr[(m*i)+j] == 0) {
                if (prev == 0) {
                    adj++;
                } else {
                    adj = 1;
                    prev = 0;
                }
            }

            if((arr[(m*i)+j] == 1)&&(prev == 0)){
                prev = 1;
            }
        }
        if (adj >= k){ res = i+1; break;}
    }

        cout<<res;

    free(arr);
    return 0;
}
