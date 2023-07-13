set includes="-Ic:\Program Files\MySQL\MySQL Server 8.0\include"
set libs="-Lc:\Program Files\MySQL\MySQL Server 8.0\lib"
g++ -std=c++20 "%cd%\*.cpp" %includes% %libs% -llibmysql -o %cd%\bin\mysql_client.exe