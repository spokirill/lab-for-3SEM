#include <iostream>

void hanoi(int N, char source, char auxiliary, char target) {
    if (N == 1) {
        std::cout << "����������� ���� 1 � " << source << " �� " << target << std::endl;
        return;
    }
    hanoi(N - 1, source, target, auxiliary);
    std::cout << "����������� ���� " << N << " � " << source << " �� " << target << std::endl;
    hanoi(N - 1, auxiliary, source, target);
}

int main() {
    int N;  // ���������� ������
    char source, target;  // �������� � ������� �������
    setlocale(LC_ALL, "ru");
    std::cout << "������� ���������� ������: ";
    std::cin >> N;

    std::cout << "������� �������� �������� (A, B, C � �.�.): ";
    std::cin >> source;

    std::cout << "������� ������� �������� (A, B, C � �.�.): ";
    std::cin >> target;

    char auxiliary = (source != 'A' && target != 'A') ? 'A' : ((source != 'B' && target != 'B') ? 'B' : 'C');

    hanoi(N, source, auxiliary, target);

    return 0;
}


