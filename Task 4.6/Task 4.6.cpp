#include <iostream>
#include <Windows.h>
using namespace std;

void task_1();
void task_2();
void task_3();
void task_4();
void draw_dice(int value);
void dice_roll(bool& player_move, int& player_score, int& computer_score);
void round(int level, bool upgraded, int& score, int& computer_score);
void menu();

int main()
{
    setlocale(LC_ALL, "Russian");

    menu();

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
    cout << "\n\n";
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

void task_3()
{
    int level = 0, score = 0, computer_score = 0;
    bool upgraded = false;
    do
    {
        system("cls");
        cout << "Введите уровень сложности (1/2): ";
        cin >> level;
    } while (level < 1 or level > 2);
    round(level, upgraded, score, computer_score);
}

void task_4()
{
    int level = 1, score = 0, computer_score = 0;
    bool upgraded = true;
    char continuation = ' ';
    for (int i = 0; i < 3; i++)
    {
        round(level, upgraded, score, computer_score);
        do
        {
            cout << "\n\nХотите продолжить? y/n ";
            cin >> continuation;
        } while (continuation != 'y' and continuation != 'n');
        if (continuation == 'n') break;
    }    
    if (continuation == 'y')
    {
        level = 2;
        for (int i = 0; i < 2; i++)
        {
            round(level, upgraded, score, computer_score);
            if (i != 1)
            {
                do
                {
                    cout << "\n\nХотите продолжить? y/n ";
                    cin >> continuation;
                } while (continuation != 'y' and continuation != 'n');
                if (continuation == 'n') break;
            }
        }
    }
    system("cls");
    cout << "Ваш счет : " << score << ", счет компьютера: " << computer_score;
    cout << "\n\n";
    system("pause");
}

void round(int level, bool upgraded, int& score, int& computer_score)
{
    int start = 0, end = 0, hp = 0, target_number = 0, player_number = 0, used_hints = 0;
    char hint = ' ';
    srand(time(NULL));
    if (level == 1)
    {
        hp = 5;
        target_number = rand() % 10 + 1;
        start = 1, end = 10;
    }
    else
    {
        hp = 22;
        target_number = rand() % 91 + 10;
        start = 10, end = 100;
    }
    for (int i = 1;;)
    {
        system("cls");
        cout << "Осталось жизней: " << hp << ", использовано подсказок " << used_hints << "\n\n";
        cout << "Какое число загадал компьютер в промежутке от " << start << " до " << end << "?\n";
        cin >> player_number;
        if (player_number == target_number)
        {
            system("cls");
            if (level == 1) score += hp * 5;
            else score += hp * 10;
            cout << "Число угадано с " << i << " попытки, использовано подсказок " << used_hints << ", ваш счет: " << score;
            if (upgraded) cout << ", счет компьютера: " << computer_score;
            cout << "\n\n";
            system("pause");
            break;
        }
        i++, hp--;
        do
        {
            cout << "Хотите взять подсказку? y/n ";
            cin >> hint;
        } while (hint != 'y' and hint != 'n');
        if (hint == 'y')
        {
            hp--, used_hints++;
            if (player_number > target_number) cout << "\nЗагаданное число меньше\n";
            else cout << "\nЗагаданное число больше\n";
            system("pause");
        }
        if (hp < 1)
        {
            system("cls");
            if (level == 1) computer_score += 5 * 5;
            else computer_score += 22 * 10;
            cout << "Смэрт от неугадания\n\n";
            if (upgraded) cout << "Ваш счет: " << score << ", счет компьютера: " << computer_score << "\n\n";
            system("pause");
            break;
        }
    }
}

void menu()
{
    int task = 0;
    void(*list_of_menu[4])() = { task_1, task_2, task_3, task_4 };    
    do
    {
        do
        {
            cout << "Введите номер задачи, 0 - выход: ";
            cin >> task;
        } while (task < 0 or task > 3);
        if (task) list_of_menu[task - 1]();
    } while (task);
}