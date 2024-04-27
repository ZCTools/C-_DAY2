// IP Tracert
#include <iostream>
#include <curl/curl.h>
#include <json/json.h>

// Bu fonksiyon, libcurl tarafından çağrılır ve aldığı veriyi saklar
size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *data) {
    data->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    // libcurl için gereken değişkenlerin tanımlanması
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    // Curl oturumunun başlatılması
    curl = curl_easy_init();
    if(curl) {
        // IP konumlandırma servisine HTTP isteği gönderme
        curl_easy_setopt(curl, CURLOPT_URL, "http://ip-api.com/json"); // IP-API servisi
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // HTTP isteğinin gerçekleştirilmesi
        res = curl_easy_perform(curl);
        // Hata kontrolü
        if(res != CURLE_OK) {
            std::cerr << "Curl error: " << curl_easy_strerror(res) << std::endl;
        }
        else {
            // Yanıtın JSON olarak ayrıştırılması
            Json::Reader reader;
            Json::Value root;
            if(reader.parse(readBuffer, root)) {
                // Ülke ve şehir bilgilerinin alınması
                std::string country = root["country"].asString();
                std::string city = root["city"].asString();
                // Konsola yazdırma
                std::cout << "Ülke: " << country << std::endl;
                std::cout << "Şehir: " << city << std::endl;
            }
            else {
                std::cerr << "JSON parsing error!" << std::endl;
            }
        }
        // Curl oturumunun sonlandırılması
        curl_easy_cleanup(curl);
    }
    else {
        std::cerr << "Curl initialization failed!" << std::endl;
    }
    return 0;
}
