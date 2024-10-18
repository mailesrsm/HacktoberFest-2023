#include <iostream>
#include <cmath>
#include <vector>
#include <string>

bool isKaprekar(int n, int base) {
    // Calculate n^2
    long long nSquared = static_cast<long long>(n) * n;
    
    // Convert n and n^2 to the given base
    std::string nStr = "", nSquaredStr = "";
    
    // Convert n to the specified base
    int temp = n;
    while (temp > 0) {
        nStr = std::to_string(temp % base) + nStr;
        temp /= base;
    }

    // Convert n^2 to the specified base
    temp = nSquared;
    while (temp > 0) {
        nSquaredStr = std::to_string(temp % base) + nSquaredStr;
        temp /= base;
    }

    int d = nStr.length();  // Number of digits in n
    int len = nSquaredStr.length();

    // Split n^2 representation into left and right parts
    std::string rightPart = nSquaredStr.substr(len - d);
    std::string leftPart = nSquaredStr.substr(0, len - d);

    // Convert the left and right parts back to decimal
    long long rightValue = rightPart.empty() ? 0 : std::stoll(rightPart);
    long long leftValue = leftPart.empty() ? 0 : std::stoll(leftPart);

    // Check if the sum of left and right equals n
    return (leftValue + rightValue == n);
}

int main() {
    int number, base;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "Enter the base: ";
    std::cin >> base;

    if (isKaprekar(number, base)) {
        std::cout << number << " is a Kaprekar number in base " << base << "." << std::endl;
    } else {
        std::cout << number << " is not a Kaprekar number in base " << base << "." << std::endl;
    }

    return 0;
}
