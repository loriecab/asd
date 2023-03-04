
#include <iostream>

#include "Header.h"

using namespace std;

std::string res_fanc(bool val) {
  string mes;
  if (val)
    mes = "Запрос обработан";
  else
    mes = "Ошибка запроса";
  return mes;
}

int main(void) {
  setlocale(LC_ALL, "RUS");
  MyArr<int> arr(5);

  // for (int i (0); i < 10; i++)
  // 	arr.push_back(i);
  MyArr<int>::Iterator it = arr.begin();
  while (1) {
    int choice(0);
    int index(0);
    int value{0};

    // MyArr<int>::Iterator it(arr.begin());
    cout << "1: опрос размера списка" << endl
         << "2: очистка списка" << endl
         << "3: проверка списка на пустоту" << endl
         << "4: опрос наличия заданного значения" << endl
         << "5: чтение значения с заданным номером в списке" << endl
         << "6: изменение значения с заданным номером в списке" << endl
         << "7: получение позиции в списке для заданного значения" << endl
         << "8: включение нового значения" << endl
         << "9: включение нового значения в позицию с заданным номером" << endl
         << "10: удаление заданного значения из списка" << endl
         << "11: удаление значения из позиции с заданным номером" << endl
         << "12: вывод элементов списка" << endl
         << "13 установка на новое значение" << endl
         << "14 переход к след. зн." << endl
         << "15 переход к пред. зн." << endl
         << "16 чтение значения" << endl
         << "17 чтение размера" << endl
         << "0: Выход" << endl;

    cout << "Введите номер пункта: ";
    cin >> choice;
    try {
      switch (choice) {
        case 0:
          return 0;
          break;
        case 1:
          cout << arr.get_size() << endl;
          break;
        case 2:
          arr.clear();
          cout << "Список очищен" << endl;
          break;
        case 3:
          if (arr.empty())
            cout << "Список пустой" << endl;
          else
            cout << "Список не пустой" << endl;
          break;
        case 4:
          cout << "Введите индекс: ";
          cin >> index;
          if (arr.check_value(index))
            cout << "Заданное значение существует" << endl;
          else
            cout << "Заданного значения не существует" << endl;
          break;
        case 5:
          cout << "Введите индекс: ";
          cin >> index;
          cout << arr[index];
          break;
        case 6:
          cout << "Введите индекс: ";
          cin >> index;
          cout << "Введите значение: ";
          cin >> value;
          cout << res_fanc(arr.change_value(index, value)) << endl;
          break;
        case 7:
          cout << "Введите значение: ";
          cin >> value;
          if (arr.get_index(value) == 0)
            cout << "Не существет, такого значения" << endl;
          else
            cout << arr.get_index(value) << endl;
          break;
        case 8:
          cout << "Введите значение: ";
          cin >> value;
          arr.push_back(value);
          break;
        case 9:
          cout << "Введите индекс: ";
          cin >> index;
          cout << "Введите значение: ";
          cin >> value;
          cout << res_fanc(arr.set_value(index, value)) << endl;
          break;
        case 10:
          cout << "Введите значение: ";
          cin >> value;
          cout << res_fanc(arr.del_value(value)) << endl;
          break;
        case 11:
          cout << "Введите индекс: ";
          cin >> index;
          cout << res_fanc(arr.erase(index)) << endl;
          break;
        case 12:
          for (int i = 0; i < arr.get_size(); i++) {
            cout << arr[i] << ' ';
          }
          cout << endl;
          break;
        case 13:
          cout << "Введите индекс: ";
          cin >> index;
          *it = arr[index];
          break;
        case 14:
          (*it)++;
          break;
        case 15:
          (*it)--;
          break;
        case 16:
          cout << *it << endl;
          break;
        case 17:
          cout << arr.get_capacity() << endl;
          cout << arr.get_size() << endl;
          break;
      }
    } catch (const char* msg) {
      std::cout << msg << std::endl;
    }

    cout << "\nвведите для продолжения ...\n";
    getchar(), getchar();
    system("clear");
  }

  return 0;
}
