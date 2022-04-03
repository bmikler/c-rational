#include <iostream>
#include "rational.h"


Rational::Rational(int numerator, int denominator) {

    if (denominator == 0) {
        throw std::invalid_argument("denominator can`t be 0");
    }

    if ((numerator < 0 && denominator < 0) || (numerator > 0 && denominator < 0)){
        numerator *= -1;
        denominator *= -1;
    }

    this->numer = numerator;
    this->denom = denominator;  
}

Rational::Rational(const Rational& other) {
    this->numer = other.numer;
    this->denom = other.denom;
}

Rational Rational::normalize(const Rational& other) {

    int greatestCommonDivisor = Rational::greatestCommonDivisor(other.numer, other.denom);

    int normalizedNumer = other.numer / greatestCommonDivisor ;
    int normalizedDenom = other.denom / greatestCommonDivisor ;

    Rational normalizedRational(normalizedNumer, normalizedDenom);

    return normalizedRational;
}

Rational Rational::normalized(int numerator, int denominator) {

    int greatestCommonDivisor = Rational::greatestCommonDivisor(numerator, denominator);

    int normalizedNumer = numerator / greatestCommonDivisor ;
    int normalizedDenom = denominator / greatestCommonDivisor ;

    Rational normalizedRational(normalizedNumer, normalizedDenom);

    return normalizedRational;
}

int Rational::greatestCommonDivisor(int numerator, int denominator) {

    int greatestCommonDivisor = 1;
    int max;

    if (denominator < numerator) { 
        max = denominator;
    } else {
        max = numerator;
    }

    for (int i = 1; i <=  max; i++) {
        if ((numerator % i == 0) && (denominator % i == 0)) {
            greatestCommonDivisor = i;
        }
    }

    return greatestCommonDivisor;

}

Rational& Rational::operator=(const Rational& other) {
    if(&other != this){
        this->numer = other.numer;
        this->denom = other.denom;
    }

    return *this;
}

Rational& Rational::operator=(int i) {
    this->numer = i;
    this->denom = 1;

    return *this;
}

std::ostream& operator<<(std::ostream &os, const Rational &rational) {

    if (rational < 0) {
       return os << "(" << rational.numer << "/" << rational.denom << ")"; 
    } else {
        return os << rational.numer << "/" << rational.denom;
    }
}

std::istream& operator>>(std::istream &is, Rational &rational) {
    std::cout << "Numerator: ";
    is >> rational.numer;
    std::cout << "Denumerator: ";
    is >> rational.denom;

    return is;
}

Rational Rational::operator+(const Rational& other) const{

    int resultNumerator = numer * other.denom + other.numer * denom;
    int resultDenumerator = denom * other.denom;

    Rational result(resultNumerator, resultDenumerator);

    return Rational::normalize(result);

}

Rational Rational::operator-(const Rational& other) const{
    int resultNumerator = numer * other.denom - other.numer * denom;
    int resultDenumerator = denom * other.denom;

    Rational result(resultNumerator, resultDenumerator);

    return Rational::normalize(result);
}

Rational Rational::operator*(const Rational& other) const{
        
    int resultNumerator = numer * other.numer;
    int resultDenumerator = denom * other.denom;

    Rational result(resultNumerator, resultDenumerator);

    return Rational::normalize(result);
        
}

 Rational Rational::operator/(const Rational& other) const{

    int resultNumerator = numer * other.denom;
    int resultDenumerator = denom * other.numer;

    Rational result(resultNumerator, resultDenumerator);

    return Rational::normalize(result);

}

Rational Rational::operator+() const{

    int resultNumer = numer;

    if (numer < 0) {
        resultNumer *= -1;
    }

    Rational result(resultNumer, denom);

    return result;

}

Rational Rational::operator-() const{

    Rational result(numer * (-1), denom);

    return result;

}


bool Rational::operator==(const Rational& other) const{
    if(numer * other.denom == other.numer * denom){
        return true;
    } else {
        return false;
    }
}

bool Rational::operator>=(const Rational& other) const{
    if(numer * other.denom >= other.numer * denom){
        return true;
    } else {
        return false;
    }
}    


bool Rational::operator<=(const Rational& other) const{
    if(numer * other.denom <= other.numer * denom){
        return true;
    } else {
        return false;
    }
}

bool Rational::operator>(const Rational& other) const{
    if(numer * other.denom > other.numer * denom){
        return true;
    } else {
        return false;
    }
}    


bool Rational::operator<(const Rational& other) const{
    if(numer * other.denom < other.numer * denom){
        return true;
    } else {
        return false;
    }
}

Rational operator+(const Rational& r, int i){
    Rational r2 = i;
    return r + r2;
}

Rational operator+(int i, const Rational& r){
    return operator+(r, i);
}

Rational operator-(const Rational& r, int i){
    Rational r2 = i;
    return r - r2;
}

Rational operator-(int i, const Rational& r){
    Rational r2 = i;
    return r2 - r;
}

Rational operator*(const Rational& r, int i){
    Rational r2 = i;
    return r * r2;
}
Rational operator*(int i, const Rational& r){
    return operator*(r, i);
}

Rational operator/(const Rational& r, int i){
    Rational r2 = i;
    return r / r2;
}
Rational operator/(int i, const Rational& r){
    Rational r2 = i;
    return r2/r;
}

