#include <iostream>
#include <Windows.h>
using namespace std;

void task_1();
void task_2();
void task_3();
void task_4();
void draw_cube(int value);

int main()
{
    setlocale(LC_ALL, "Russian");

    task_2();

    return 0;
}

void task_1()
{
    char symbol = ' ', direction = ' ';
    int length = 0, speed = 0;    
    cout << "Введите символ: ";
    cin >> symbol;
    do
    {
        cout << "Введите длину линии: ";
        cin >> length;
    } while (length < 1);
    do
    {
        cout << "Введите направление линии (v/h): ";
        cin >> direction;        
    } while (direction != 'v' and direction != 'h');
    do
    {
        cout << "Введите скорость отрисовки 1 - 3: ";
        cin >> speed;
    } while (speed < 1 or speed > 3);
    system("cls");
    for (int i = 0; i < length; i++)
    {
        cout << symbol;
        if (direction == 'v') cout << endl;
        else cout << "\t";
        Sleep(speed * 100);
    }
}

void task_2()
{
    draw_cube(3);
}

void draw_cube(int value)
{
    system("cls");
    switch (value)
    {
    case(1):
    {
        cout << "+-------+\n";
        cout << "|       |\n";
        cout << "|   *   |\n";
        cout << "|       |\n";
        cout << "+-------+\n";
    }
    break;
    case(2):
    {
        cout << "+-------+\n";
        cout << "| *     |\n";
        cout << "|       |\n";
        cout << "|     * |\n";
        cout << "+-------+\n";
    }
    break;
    case(3):
    {
        cout << "+-------+\n";
        cout << "| *     |\n";
        cout << "|   *   |\n";
        cout << "|     * |\n";
        cout << "+-------+\n";
    }
    break;
    case(4):
    {
        cout << "+-------+\n";
        cout << "| *   * |\n";
        cout << "|       |\n";
        cout << "| *   * |\n";
        cout << "+-------+\n";
    }
    break;
    case(5):
    {
        cout << "+-------+\n";
        cout << "| *   * |\n";
        cout << "|   *   |\n";
        cout << "| *   * |\n";
        cout << "+-------+\n";
    }
    break;
    case(6):
    {
        cout << "+-------+\n";
        cout << "| *   * |\n";
        cout << "| *   * |\n";
        cout << "| *   * |\n";
        cout << "+-------+\n";
    }
    break;
    }
}