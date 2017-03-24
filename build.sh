
echo Starting Build
echo Starting linux build
gcc *.c *.h -o landlord.out
echo Finished linux build
echo Starting windows build
x86_64-w64-mingw32-gcc *.h *.c -o landlord.exe
echo Finished windows build
echo Build ended
