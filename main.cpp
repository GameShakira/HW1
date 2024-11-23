#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

// Задача 1
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Задача 2
void reverseArray(vector<int>& arr) {
    reverse(arr.begin(), arr.end());
}

// Задача 3
string textToMorse(const string& text) {
    map<char, string> morse = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
        {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
        {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
        {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
        {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
        {'Z', "--.."}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"},
        {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
        {'0', "-----"}, {' ', " "}
    };

    string result;
    for (char c : text) {
        char upperC = toupper(c);
        if (morse.count(upperC)) {
            result += morse[upperC] + " ";
        }
    }
    return result;
}

// Задача 4
string compressString(const string& str) {
    string result;
    int count = 1;
    for (size_t i = 1; i <= str.size(); ++i) {
        if (i < str.size() && str[i] == str[i - 1]) {
            ++count;
        } else {
            result += str[i - 1];
            if (count > 1) {
                result += to_string(count);
            }
            count = 1;
        }
    }
    return result;
}

// Задача 5
void printRectangle(int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

// Задача 6
void findNumbersWithSum15() {
    for (int i = 1000; i < 10000; ++i) {
        int sum = 0, num = i;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        if (sum == 15) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Задача 7
double finalScore(const vector<int>& scores) {
    int total = scores.size();
    int passed = count_if(scores.begin(), scores.end(), [](int score) { return score > 2; });
    double average = std::accumulate(scores.begin(), scores.end(), 0.0) / total;

    if (passed < total / 2) {
        return 2;
    } else {
        return average;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    // Задача 1
    cout << "\nЗадача 1: НОД" << endl;
    int a = 48, b = 18;
    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << endl;

    // Задача 2
    cout << "\nЗадача 2: Реверс массива" << endl;
    vector<int> arr = {1, 2, 3, 4, 5};
    reverseArray(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Задача 3
    cout << "\nЗадача 3: Текст в Азбуку Морзе" << endl;
    string text = "Hello World";
    cout << "Morse: " << textToMorse(text) << endl;

    // Задача 4
    cout << "\nЗадача 4: Сжатие строки" << endl;
    string inputStr = "daabbbccccc";
    cout << "Сжатый вариант: " << compressString(inputStr) << endl;

    // Задача 5
    cout << "\nЗадача 5: Прямоугольник" << endl;
    printRectangle(4, 5);

    // Задача 6
    cout << "\nЗадача 6: Четырехзначные числа с суммой 15" << endl;
    findNumbersWithSum15();

    // Задача 7
    cout << "\nЗадача 7: Финальная оценка" << endl;
    vector<int> scores = {3, 4, 5, 2, 5};
    cout << "Финальная оценка: " << finalScore(scores) << endl;

    return 0;
}
