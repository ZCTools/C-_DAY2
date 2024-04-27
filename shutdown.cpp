// Şaka virüsü
#include <windows.h> // Kütüphaneyi ekleyemedim:(
#include <iostream>
#include <cstdlib>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // MessageBox'u göster
    MessageBox(NULL, TEXT("Bilgisayarınız 5 saniye sonra kapanacaktır."), TEXT("Kapanma Uyarısı"), MB_OK);

    // Kullanıcı OK'a bastıktan sonra, bilgisayarı kapat
    system("shutdown /s /t 5");

    return 0;
}
