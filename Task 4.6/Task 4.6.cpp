#include <iostream>
#include <Windows.h>
using namespace std;

void task_1();
void task_2();
void task_3();
void task_4();
void draw_dice(int value);
void dice_roll(bool& player_move, int& player_score, int& computer_score);

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
    int player_score = 0, computer_score = 0;
    bool player_move = false;
    for (int i = 0; i < 6; i++)
    {
        system("cls");
        cout << "Игрок\t|\tКомпьютер\n";
        cout << player_score << "\t|\t" << computer_score << "\n\n";
        system("pause");
        dice_roll(player_move, player_score, computer_score);
    }
    system("cls");
    cout << "Со счётом " << player_score << " : " << computer_score;
    if (player_score > computer_score) cout << " победил игрок!";
    else if (player_score < computer_score) cout << " победил компьютер!";
    else cout << " игра закончилась ничьей!";
    cout << "\n\n";
}

void draw_dice(int value)
{    
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
    system("pause");
}

void dice_roll(bool& player_move, int& player_score, int& computer_score)
{
    int value = 0;
    system("cls");
    if (player_move)
    {
        cout << "Ход игрока\n\n";
        system("pause");
        cout << "\n\n";
    }
    else
    {
        cout << "Ход компьютера\n\n";
        Sleep(1000);
    }
    srand(time(NULL));
    value = rand() % 6 + 1;
    if (player_move) player_score += value;
    else computer_score += value;
    player_move = !player_move;
    draw_dice(value);
}