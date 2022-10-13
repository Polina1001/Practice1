#include <iostream>
using namespace std;
int main()
{ // 1)
    
    cout << "\n\n\t\tTask 1\n";
    setlocale(0, "");
    cout << "int:" << sizeof(int) << "\n";
    cout << "short int:" << sizeof(short int) << "\n";
    cout << "long int:" << sizeof(long int) << "\n";
    cout << "float:" << sizeof(float) << "\n";
    cout << "double:" << sizeof(double) << "\n";
    cout << "long double:" << sizeof(long double) << "\n";
    cout << "char:" << sizeof(char) << "\n";
    cout << "bool:" << sizeof(bool);

    // 2)
    cout << "\n\n\t\tTask 2\n";
    cout << "Enter int: ";
    int input;
    cin >> input;
    int a = sizeof(int) * 8; // a = 32
    int mask = 1 << a - 1; // 1000...00

    int idz_output = mask - 1, idz_input, idz_counter = 0; // идз
    idz_input = input; // идз

    for (int i = 1; i <= a; i++)
    {
        cout << ((input & mask) ? 1 : 0);


        if (i == 1 || i % 8 == 0)
            cout << " ";

        input <<= 1;
    }
    cout << "\n";


    // идз 2 (int)
    
    for (int i = 1; i <= a; i++)
    {
        (idz_input & mask) ? idz_counter += 1 : idz_counter += 0;
        idz_input <<= 1;
    }
    idz_output >>= 31 - idz_counter;

    for (int i = 1; i <= a; i++)
    {
        cout << ((idz_output & mask) ? 1 : 0);
        if (i == 1 || i % 8 == 0)
            cout << " ";

        idz_output <<= 1;
    }


    // 3)
    cout << "\n\n\t\tTask 3\n";
    union {
        int tool;
        float f;
    };
    cout << "Enter float: ";
    cin >> f;

    idz_input = tool; // идз
    idz_output = mask - 1; // идз
    idz_counter = 0; // идз

    for (int i = 1; i <= a; i++)
    {
        cout << ((tool & mask) ? 1 : 0);
        if (i == 1 || i % 8 == 0)
            cout << " ";
        tool <<= i;
    }
    cout << "\n";

    // идз 3 (float)

    for (int i = 1; i <= a; i++)
    {
        (idz_input& mask) ? idz_counter += 1 : idz_counter += 0;
        idz_input <<= 1;
    }
    idz_output >>= 31 - idz_counter;

    for (int i = 1; i <= a; i++)
    {
        cout << ((idz_output & mask) ? 1 : 0);
        if (i == 1 || i % 8 == 0)
            cout << " ";
        idz_output <<= 1;
    }

    // 4)

    cout << "\n\n\t\tTask 4\n";
    union {
        double d;
        int arr[2];
    };
    cout << "Enter double: ";
    cin >> d;

    int idz_output0 = mask - 1, idz_output1 = mask - 1; 
    int idz_input0 = arr[0], idz_input1 = arr[1], idz_counter0 = 0, idz_counter1 = 0;
    idz_counter = 0;

    for (int i = 1; i <= a; i++) 
    {
        cout << ((arr[1] & mask) ? 1 : 0);
        if (i == 1 || i % 8 == 0)
            cout << " ";
        arr[1] <<= 1;
    }
    for (int i = 1; i <= a; i++)
    {
        cout << ((arr[0] & mask) ? 1 : 0);
        if (i % 8 == 0)
            cout << " ";
        arr[0] <<= 1;
    }
    cout << "\n";
    
    //идз 4 (double)
    for (int i = 1; i <= a; i++)
    {
        (idz_input0 & mask) ? idz_counter0 += 1 : idz_counter0 += 0;
        idz_input <<= 1;
    }
    idz_output0 >>= 31 - idz_counter0;

    for (int i = 1; i <= a; i++)
        for (int i = 1; i <= a; i++)
        {
            (idz_input1 & mask) ? idz_counter1 += 1 : idz_counter1 += 0;
            idz_input <<= 1;
        }
    idz_output1 >>= 31 - idz_counter1;

    for (int i = 1; i <= a; i++)
    {
        cout << ((idz_output0 & mask) ? 1 : 0);
        if (i == 1 || i % 8 == 0)
            cout << " ";
        idz_output0 <<= 1;
    }
    for (int i = 1; i <= a; i++)
    {
        cout << ((idz_output1 & mask) ? 1 : 0);
        if (i == 1 || i % 8 == 0)
            cout << " ";
        idz_output1 <<= 1;
    }

    int c;
    cin >> c;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
