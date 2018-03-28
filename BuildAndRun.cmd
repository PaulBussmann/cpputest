pushd %~dp0

if not exist C:\CppUTest\lib\Windows\VS2017\x86\Debug mkdir C:\CppUTest\lib\Windows\VS2017\x86\Debug
if not exist C:\CppUTest\lib\Windows\VS2017\x86\Release mkdir C:\CppUTest\lib\Windows\VS2017\x86\Release
"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\devenv.com" /Build Debug CppUTest_VS2017.sln
"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\devenv.com" /Build Release CppUTest_VS2017.sln

popd
