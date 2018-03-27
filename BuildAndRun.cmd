pushd %~dp0

"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\devenv.com" /Build Debug CppUTest_VS2017.sln

C:\CppUTest\examples\AllTests\Debug\AllTests.exe -v -ojunit

RunTup.cmd

popd
