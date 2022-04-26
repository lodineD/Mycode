#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int const max_number = 10000;
    int N;
    cin >> N;
    bitset<max_number + 1> numbers;
    for (int i = 1; i < N; ++i)
    {
        numbers.set(i, 1);
    }
    numbers[1] = 0;
    for (int i = 1; i != N; ++i)
    {
        if (numbers[i])
        {
            for (int j = i * 2; j < N + 1; j += i)
            {
                numbers[j] = 0;
            }
        }
    }
    for (int i = 1; i != max_number; ++i)
    {
        if (numbers[i])
            i == 2 ? cout << i : cout << " " << i;
    }
    return 0;
}
