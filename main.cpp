// main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "BinaryTree.h"
using namespace std;
int main() {
    BinaryTree MyTree; // создание дерева
    int element;
    // корнем является тот элемент, который ты ввел 1-м
    for (int i = 0; i < 6; ++i) {
        cin >> element;
        MyTree.Insert(element);
    }
    cout << "Бинарное дерево: " << endl << MyTree << endl;
    for (int i = 0; i < MyTree.Size(); ++i) {
        if (MyTree.Find(i)) {
            cout << "Элемент " << i << " находится на дереве!" << endl;
        }
    }
    if (MyTree.Size() == 6) { // В данном случае, если в дереве все 10 элементов разные, то он зайдет
        cout << "Второй тест выполнен" << endl;
    }
    cout << "Введите элемент для удаления: ";
    cin >> element;
    MyTree.Erase(element); // удаляешь тот элемент, который является корнем, который вводил первым
    cout << MyTree << endl;
    if (MyTree.Size() == 5) {
        cout << "Четвертый тест выполнен" << endl;
    }
    MyTree.Clear();
    if (MyTree.Size() == 0) {
        cout << "Пятый тест выполнен" << endl;
    }
    cout << MyTree << endl;
    return 0;
}


