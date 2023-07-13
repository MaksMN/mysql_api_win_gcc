#include <iostream>
#include <mysql.h>

#pragma comment(lib, "libmysql.lib")

using namespace std;

int main()
{
    MYSQL mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;

    int i = 0;

    // Получаем дескриптор соединения
    mysql_init(&mysql);
    if (&mysql == nullptr)
    {
        // Если дескриптор не получен — выводим сообщение об ошибке
        cout << "Error: can't create MySQL-descriptor" << endl;
    }

    // Подключаемся к серверу
    if (!mysql_real_connect(&mysql, "pma.sfubuntu", "dbuser", "dbpass", "console_chat", 3306, NULL, 0))
    {
        // Если нет возможности установить соединение с БД выводим сообщение об ошибке
        cout << "Error: can't connect to database " << mysql_error(&mysql) << endl;
    }
    else
    {
        // Если соединение успешно установлено выводим фразу — "Success!"
        cout << "Success!" << endl;
    }

    mysql_set_character_set(&mysql, "utf8mb4");
    // Смотрим изменилась ли кодировка на нужную, по умолчанию идёт latin1
    cout << "connection characterset: " << mysql_character_set_name(&mysql) << endl;

    mysql_query(&mysql, "SELECT * FROM test"); // Делаем запрос к таблице

    // Выводим все что есть в базе через цикл
    if (res = mysql_store_result(&mysql))
    {
        while (row = mysql_fetch_row(res))
        {
            for (i = 0; i < mysql_num_fields(res); i++)
            {
                cout << row[i] << "  ";
            }
            cout << endl;
        }
    }
    else
        cout << "Ошибка MySql номер " << mysql_error(&mysql);

    // Закрываем соединение с сервером базы данных
    mysql_close(&mysql);

    system("Pause");

    return 0;
}