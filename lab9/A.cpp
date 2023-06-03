#include <iostream>
#include <cmath>

std::string bin(unsigned int n) {

    std::string buffer;

    do
    {
        buffer += char('0' + n % 2);
        n = n / 2;
    }
    while (n > 0);

    return std::string(buffer.crbegin(), buffer.crend());
}

int main(){

    unsigned short n;
    std::string grayCode;
    std::cin >> n;

    for (unsigned int i = 0; i < pow(2,n); i++)
    {
        grayCode = bin(i ^ (i >> 1));

        if (grayCode.length() != n)
        {
            while (grayCode.length() != n)
                grayCode = '0' + grayCode;
        }

        std::cout << grayCode << std::endl;
    }

    return 0;
}