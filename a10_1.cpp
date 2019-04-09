/*
Alex Hughes
CS 110B
4/8/19
Professor Dave
Assignment 10.1

Building on my previous fraction class assignment, this assignments calls for implimentation of multiple fraction objects.
I've added iverloading operators, all six relational operators, the four basic arithmetic operators, shorthand arithmetic
operators and increment decrement operators.
 */





#include <iostream>
#include <string>
using namespace std;

class Fraction
{
public:
    Fraction();

    Fraction(int wholeNumber);

    Fraction(int num, int den);

    friend Fraction operator+(const Fraction& left,
                              const Fraction& right);

    friend Fraction operator-(const Fraction& left,
                              const Fraction& right);

    friend Fraction operator*(const Fraction& left,
                              const Fraction& right);

    friend Fraction operator/(const Fraction& left,
                              const Fraction& right);

    friend ostream& operator<<(ostream& out,
                               const Fraction &f);

    friend istream& operator>>(istream& in,
                               Fraction &f);

    friend bool operator<(const Fraction& left,
                          const Fraction& right);

    friend bool operator<=(const Fraction& left,
                           const Fraction& right);

    friend bool operator>=(const Fraction& left,
                           const Fraction& right);

    friend bool operator>(const Fraction& left,
                          const Fraction& right);

    friend bool operator==(const Fraction& left,
                           const Fraction& right);

    friend bool operator!=(const Fraction& left,
                           const Fraction& right);

    Fraction operator+=(const Fraction& right);

    Fraction operator-=(const Fraction& right);

    Fraction operator*=(const Fraction& right);

    Fraction operator/=(const Fraction& right);

    Fraction operator++();

    Fraction operator++(int);

    Fraction operator--();

    Fraction operator--(int);


private:
    int numValue;
    int denomValue;
};




Fraction::Fraction()
{
    numValue = 0;
    denomValue = 1;
}






Fraction::Fraction(int wholeNumber)
{
    numValue = wholeNumber;
    denomValue = 1;
}






Fraction::Fraction(int num, int den)
{
    assert(den != 0);
    numValue = num;
    denomValue = den;
}






Fraction operator+(const Fraction& left, const Fraction& right)
{
    int modNum1;
    int modNum2;
    int modDen;

    modDen = left.denomValue * right.denomValue;
    modNum1 = left.numValue * right.denomValue;
    modNum2 = right.numValue * left.denomValue;

    Fraction result = Fraction(modNum1 + modNum2, modDen);
    return result;
}






Fraction operator-(const Fraction& left, const Fraction& right)
{
    int modNum1;
    int modNum2;
    int modDen;

    modDen = left.denomValue * right.denomValue;
    modNum1 = left.numValue * right.denomValue;
    modNum2 = right.numValue * left.denomValue;

    Fraction result = Fraction(modNum1 - modNum2, modDen);
    return result;
}






Fraction operator*(const Fraction& left, const Fraction& right)
{
    Fraction result = Fraction(left.numValue * right.numValue, left.denomValue * right.denomValue);
    return result;
}






Fraction operator/(const Fraction& left, const Fraction& right)
{
    Fraction result = Fraction(left.numValue * right.denomValue, left.denomValue * right.numValue);
    return result;
}






ostream& operator<<(ostream& out, const Fraction &f)
{
    if(abs(f.numValue) > f.denomValue)
    {
        out << ((f.numValue - f.numValue % f.denomValue) / f.denomValue);

        if(f.numValue % f.denomValue != 0)
        {
            out << "+" << abs(f.numValue % f.denomValue) << "/" << f.denomValue;
        }
    }
    else if(f.numValue == f.denomValue)
    {
        out << f.numValue;
    }
    else if(f.numValue == 0)
    {
        out << 0;
    }
    else
    {
        out << f.numValue << "/" << f.denomValue;
    }

    return out;
}






istream& operator>>(istream& in, Fraction &f)
{
    int temp;
    in >> temp;
    if (in.peek() == '+')
    {
        in.ignore();
        in >> f.numValue;
        in.ignore();
        in >> f.denomValue;
        if(temp < 0)
        {
            temp *= -1;
            f.numValue += temp * f.denomValue;
            f.numValue *= -1;
        }
        else
        {
            f.numValue += temp * f.denomValue;
        }
    }
    else if (in.peek() == '/')
    {
        in.ignore();
        in >> f.denomValue;
        f.numValue = temp;
    }
    else
    {
        f.numValue = temp;
        f.denomValue = 1;
    }

    return in;
}






bool operator<(const Fraction& left, const Fraction& right)
{
    if(left.numValue * right.denomValue < right.numValue * left.denomValue)
        return true;
    else
        return false;
}






bool operator<=(const Fraction& left, const Fraction& right)
{
    if(left.numValue * right.denomValue <= right.numValue * left.denomValue)
        return true;
    else
        return false;
}






bool operator>(const Fraction& left, const Fraction& right)
{
    if(left.numValue * right.denomValue > right.numValue * left.denomValue)
        return true;
    else
        return false;
}






bool operator>=(const Fraction& left, const Fraction& right)
{
    if(left.numValue * right.denomValue >= right.numValue * left.denomValue)
        return true;
    else
        return false;
}






bool operator==(const Fraction& left, const Fraction& right)
{
    if(left.numValue * right.denomValue == right.numValue * left.denomValue)
        return true;
    else
        return false;
}






bool operator!=(const Fraction& left, const Fraction& right)
{
    if(left.numValue * right.denomValue != right.numValue * left.denomValue)
        return true;
    else
        return false;
}






Fraction Fraction::operator+=(const Fraction& right)
{
    *this = *this + right;

    return *this;
}






Fraction Fraction::operator-=(const Fraction& right)
{
    *this = *this - right;

    return *this;
}






Fraction Fraction::operator*=(const Fraction& right)
{
    *this = *this * right;

    return *this;
}






Fraction Fraction::operator/=(const Fraction& right)
{
    *this = *this / right;

    return *this;
}






Fraction Fraction::operator++()
{
    numValue += denomValue;
    return *this;
}






Fraction Fraction::operator++(int)
{
    Fraction temp(numValue, denomValue);
    numValue += denomValue;
    return temp;
}






Fraction Fraction::operator--()
{
    numValue -= denomValue;
    return *this;
}






Fraction Fraction::operator--(int)
{
    Fraction temp(numValue, denomValue);
    numValue -= denomValue;
    return temp;
}






//[INSERT YOUR CODE HERE, FIRST YOUR CLASS DECLARATION, FOLLOWED BY YOUR CLASS
//MEMBER FUNCTION DEFINITIONS!]

void BasicTest();
void RelationTest();
void BinaryMathTest();
void MathAssignTest();
string boolString(bool convertMe);

int main()
{
    BasicTest();
    RelationTest();
    BinaryMathTest();
    MathAssignTest();
}





void BasicTest()
{
    cout << "\n----- Testing basic Fraction creation & printing\n";

    const Fraction fr[] = {Fraction(4, 8), Fraction(-15,21),
                           Fraction(10), Fraction(12, -3),
                           Fraction(), Fraction(28, 6), Fraction(0, 12)};

    for (int i = 0; i < 7; i++){
        cout << "Fraction [" << i <<"] = " << fr[i] << endl;
    }



}





string boolString(bool convertMe) {
    if (convertMe) {
        return "true";
    } else {
        return "false";
    }
}


void RelationTest()
{
    cout << "\n----- Testing relational operators between Fractions\n";

    const Fraction fr[] =  {Fraction(3, 6), Fraction(1,2), Fraction(-15,30),
                            Fraction(1,10), Fraction(0,1), Fraction(0,2)};

    for (int i = 0; i < 5; i++) {
        cout << "Comparing " << fr[i] << " to " << fr[i+1] << endl;
        cout << "\tIs left < right? " << boolString(fr[i] < fr[i+1]) << endl;
        cout << "\tIs left <= right? " << boolString(fr[i] <= fr[i+1]) << endl;
        cout << "\tIs left > right? " << boolString(fr[i] > fr[i+1]) << endl;
        cout << "\tIs left >= right? " << boolString(fr[i] >= fr[i+1]) << endl;
        cout << "\tDoes left == right? " << boolString(fr[i] == fr[i+1]) << endl;
        cout << "\tDoes left != right ? " << boolString(fr[i] != fr[i+1]) << endl;
    }

    cout << "\n----- Testing relations between Fractions and integers\n";
    Fraction f(-3,6);
    int num = 2;
    cout << "Comparing " << f << " to " << num << endl;
    cout << "\tIs left < right? " << boolString(f < num) << endl;
    cout << "\tIs left <= right? " << boolString(f <= num) << endl;
    cout << "\tIs left > right? " << boolString(f > num) << endl;
    cout << "\tIs left >= right? " << boolString(f >= num) << endl;
    cout << "\tDoes left == right? " << boolString(f == num) << endl;
    cout << "\tDoes left != right ? " << boolString(f != num) << endl;

    Fraction g(1,4);
    num = -3;
    cout << "Comparing " << num << " to " << g << endl;
    cout << "\tIs left < right? " << boolString(num < g) << endl;
    cout << "\tIs left <= right? " << boolString(num <= g) << endl;
    cout << "\tIs left > right? " << boolString(num > g) << endl;
    cout << "\tIs left >= right? " << boolString(num >= g) << endl;
    cout << "\tDoes left == right? " << boolString(num == g) << endl;
    cout << "\tDoes left != right ? " << boolString(num != g) << endl;
}





void BinaryMathTest()
{
    cout << "\n----- Testing binary arithmetic between Fractions\n";

    const Fraction fr[] = {Fraction(1, 6), Fraction(1,3),
                           Fraction(-2,3), Fraction(5), Fraction(-4,3)};

    for (int i = 0; i < 4; i++) {
        cout << fr[i] << " + " << fr[i+1] << " = " << fr[i] + fr[i+1] << endl;
        cout << fr[i] << " - " << fr[i+1] << " = " << fr[i] - fr[i+1] << endl;
        cout << fr[i] << " * " << fr[i+1] << " = " << fr[i] * fr[i+1] << endl;
        cout << fr[i] << " / " << fr[i+1] << " = " << fr[i] / fr[i+1] << endl;
    }

    cout << "\n----- Testing arithmetic between Fractions and integers\n";
    Fraction f(-1, 2);
    int num = 4;
    cout << f << " + " << num << " = " << f + num << endl;
    cout << f << " - " << num << " = " << f - num << endl;
    cout << f << " * " << num << " = " << f * num << endl;
    cout << f << " / " << num << " = " << f / num << endl;

    Fraction g(-1, 2);
    num = 3;
    cout << num << " + " << g << " = " << num + g << endl;
    cout << num << " - " << g << " = " << num - g << endl;
    cout << num << " * " << g << " = " << num * g << endl;
    cout << num << " / " << g << " = " << num / g << endl;
}






void MathAssignTest()
{
    cout << "\n----- Testing shorthand arithmetic assignment on Fractions\n";

    Fraction fr[] = {Fraction(1, 6), Fraction(4),
                     Fraction(-1,2), Fraction(5)};

    for (int i = 0; i < 3; i++) {
        cout << fr[i] << " += " << fr[i+1] << " = ";
        cout << (fr[i] += fr[i+1]) << endl;
        cout << fr[i] << " -= " << fr[i+1] << " = ";
        cout << (fr[i] -= fr[i+1]) << endl;
        cout << fr[i] << " *= " << fr[i+1] << " = ";
        cout << (fr[i] *= fr[i+1]) << endl;
        cout << fr[i] << " /= " << fr[i+1] << " = ";
        cout << (fr[i] /= fr[i+1]) << endl;
    }

    cout << "\n----- Testing shorthand arithmetic assignment using integers\n";
    Fraction f(-1, 3);
    int num = 3;
    cout << f << " += " << num << " = ";
    cout << (f += num) << endl;
    cout << f << " -= " << num << " = ";
    cout << (f -= num) << endl;
    cout << f << " *= " << num << " = ";
    cout << (f *= num) << endl;
    cout << f << " /= " << num << " = ";
    cout << (f /= num) << endl;

    cout << "\n----- Testing increment/decrement prefix and postfix\n";
    Fraction g(-1, 3);
    cout << "Now g = " << g << endl;
    cout << "g++ = " << g++ << endl;
    cout << "Now g = " << g << endl;
    cout << "++g = " << ++g << endl;
    cout << "Now g = " << g << endl;
    cout << "g-- = " << g-- << endl;
    cout << "Now g = " << g << endl;
    cout << "--g = " << --g << endl;
    cout << "Now g = " << g << endl;
}



/*
Ouput:

/Users/alexhughes/CLionProjects/a10_1/cmake-build-debug/a10_1

----- Testing basic Fraction creation & printing
Fraction [0] = 4/8
Fraction [1] = -15/21
Fraction [2] = 10
Fraction [3] = -4
Fraction [4] = 0
Fraction [5] = 4+4/6
Fraction [6] = 0

----- Testing relational operators between Fractions
Comparing 3/6 to 1/2
	Is left < right? false
	Is left <= right? true
	Is left > right? false
	Is left >= right? true
	Does left == right? true
	Does left != right ? false
Comparing 1/2 to -15/30
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
Comparing -15/30 to 1/10
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
Comparing 1/10 to 0
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
Comparing 0 to 0
	Is left < right? false
	Is left <= right? true
	Is left > right? false
	Is left >= right? true
	Does left == right? true
	Does left != right ? false

----- Testing relations between Fractions and integers
Comparing -3/6 to 2
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
Comparing -3 to 1/4
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true

----- Testing binary arithmetic between Fractions
1/6 + 1/3 = 9/18
1/6 - 1/3 = -3/18
1/6 * 1/3 = 1/18
1/6 / 1/3 = 3/6
1/3 + -2/3 = -3/9
1/3 - -2/3 = 9
1/3 * -2/3 = -2/9
1/3 / -2/3 = 0+3/-6
-2/3 + 5 = 4+1/3
-2/3 - 5 = -5+2/3
-2/3 * 5 = -3+1/3
-2/3 / 5 = -2/15
5 + -1+1/3 = 3+2/3
5 - -1+1/3 = 6+1/3
5 * -1+1/3 = -6+2/3
5 / -1+1/3 = -3+3/-4

----- Testing arithmetic between Fractions and integers
-1/2 + 4 = 3+1/2
-1/2 - 4 = -4+1/2
-1/2 * 4 = -2
-1/2 / 4 = -1/8
3 + -1/2 = 2+1/2
3 - -1/2 = 3+1/2
3 * -1/2 = -1+1/2
3 / -1/2 = -6

----- Testing shorthand arithmetic assignment on Fractions
1/6 += 4 = 4+1/6
4+1/6 -= 4 = 1/6
1/6 *= 4 = 4/6
4/6 /= 4 = 4/24
4 += -1/2 = 3+1/2
3+1/2 -= -1/2 = 4
4 *= -1/2 = -2
-2 /= -1/2 = 4
-1/2 += 5 = 4+1/2
4+1/2 -= 5 = -1/2
-1/2 *= 5 = -2+1/2
-2+1/2 /= 5 = -5/10

----- Testing shorthand arithmetic assignment using integers
-1/3 += 3 = 2+2/3
2+2/3 -= 3 = -1/3
-1/3 *= 3 = -3/3
-3/3 /= 3 = -3/9

----- Testing increment/decrement prefix and postfix
Now g = -1/3
g++ = -1/3
Now g = 2/3
++g = 1+2/3
Now g = 1+2/3
g-- = 1+2/3
Now g = 2/3
--g = -1/3
Now g = -1/3

Process finished with exit code 0


 */
