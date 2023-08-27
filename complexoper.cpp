#include <bits/stdc++.h>
using namespace std;

struct Complex {
    double real;
    double imaginary;
};

Complex add(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;
    return result;
}

Complex subtract(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real - num2.real;
    result.imaginary = num1.imaginary - num2.imaginary;
    return result;
}

Complex multiply(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real * num2.real;
    result.imaginary = num1.imaginary * num2.imaginary;
    return result;
}

Complex divide(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real / num2.real;
    result.imaginary = num1.imaginary / num2.imaginary;
    return result;
}

int main() {
    Complex num1, num2;

    cout << "Enter the real and imaginary parts of the first complex number:" << endl;
    cout << "Real Part: ";
    cin >> num1.real;
    cout << "Imaginary Part: ";
    cin >> num1.imaginary;

    cout << "\nEnter the real and imaginary parts of the second complex number:" << endl;
    cout << "Real Part: ";
    cin >> num2.real;
    cout << "Imaginary Part: ";
    cin >> num2.imaginary;

    Complex result_add = add(num1, num2);
    Complex result_subtract = subtract(num1, num2);
    Complex result_multiply = multiply(num1, num2);
    Complex result_divide = divide(num1, num2);

    cout << "\nAddition: " << result_add.real << " + " << result_add.imaginary << "i" << endl;
    cout << "Subtraction: " << result_subtract.real << " + " << result_subtract.imaginary << "i" << endl;
    cout << "Multiplication: " << result_multiply.real << " + " << result_multiply.imaginary << "i" << endl;
    cout << "Division: " << result_divide.real << " + " << result_divide.imaginary << "i" << endl;

    return 0;
}