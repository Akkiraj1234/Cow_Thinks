#include <httplib.h>

void fetch_data_from_server(const std::string& url) {
    httplib::Client client(url.c_str());
    auto res = client.Get("/");
    if (res) {
        std::cout << "Response: " << res->body << std::endl;
    } else {
        std::cerr << "Failed to connect to server." << std::endl;
    }
}
