pushd %~dp0

if not exist lib\Windows\VS2017\x86\Debug mkdir lib\Windows\VS2017\x86\Debug
if not exist lib\Windows\VS2017\x86\Release mkdir lib\Windows\VS2017\x86\Release
"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\devenv.com" CppUTest_VS2017.sln /Build "Debug|x86" /project CppUTest_VS2017 /ProjectConfig "Debug|Win32"
"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\devenv.com" CppUTest_VS2017.sln /Build "Release|x86" /project CppUTest_VS2017 /ProjectConfig "Release|Win32"

"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\devenv.com" CppUTest_VS2017.sln /Build "Debug|x86" /project ApplicationLib_VS2017 /ProjectConfig "Debug|Win32"
"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\devenv.com" CppUTest_VS2017.sln /Build "Release|x86" /project ApplicationLib_VS2017 /ProjectConfig "Release|Win32"

"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\devenv.com" CppUTest_VS2017.sln /Build "Debug|x86" /project AllTests_VS2017 /ProjectConfig "Debug|Win32"
"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\devenv.com" CppUTest_VS2017.sln /Build "Release|x86" /project AllTests_VS2017 /ProjectConfig "Release|Win32"

examples\AllTests\Debug\AllTests.exe -v -ojunit

RunTup.cmd

popd
