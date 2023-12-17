#include <iostream>

void hanoi(int N, char source, char auxiliary, char target) {
    if (N == 1) {
        std::cout << "Переместить диск 1 с " << source << " на " << target << std::endl;
        return;
    }
    hanoi(N - 1, source, target, auxiliary);
    std::cout << "Переместить диск " << N << " с " << source << " на " << target << std::endl;
    hanoi(N - 1, auxiliary, source, target);
}

int main() {
    int N;  // Количество дисков
    char source, target;  // Исходный и целевой стержни
    setlocale(LC_ALL, "ru");
    std::cout << "Введите количество дисков: ";
    std::cin >> N;

    std::cout << "Введите исходный стержень (A, B, C и т.д.): ";
    std::cin >> source;

    std::cout << "Введите целевой стержень (A, B, C и т.д.): ";
    std::cin >> target;

    char auxiliary = (source != 'A' && target != 'A') ? 'A' : ((source != 'B' && target != 'B') ? 'B' : 'C');

    hanoi(N, source, auxiliary, target);

    return 0;
}


