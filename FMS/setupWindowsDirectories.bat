mkdir ..\build-FMS-Desktop_Qt_5_4_1_MSVC2013_64bit-Release\release
mkdir ..\build-FMS-Desktop_Qt_5_4_1_MSVC2013_64bit-Debug\debug
copy "C:\Program Files\MySQL\MySQL Server 5.7\lib\libmysql.dll" ..\build-FMS-Desktop_Qt_5_4_1_MSVC2013_64bit-Release\release\
copy "C:\Program Files\MySQL\MySQL Server 5.7\lib\libmysql.dll" ..\build-FMS-Desktop_Qt_5_4_1_MSVC2013_64bit-Debug\debug\
copyConfig.bat
pause