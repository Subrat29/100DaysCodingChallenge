#include <iostream>
using namespace std;

int main()
{
    int number;
    while (true)
    {
        cin >> number;
        if (number == 42)
        {
            {
                break;
            }
        }
        std::cout << number << std::endl;
    }
    return 0;
}