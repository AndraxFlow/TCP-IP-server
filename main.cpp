// #include <iostream>

// // парсинг IPv4-адреса и порта в std::string
// std::string getHostStr(const TcpServer::Client& client) {
//     uint32_t ip = client.getHost();
//     return std::string() + std::to_string(int(reinterpret_cast<char*>(&ip)[0])) + '.' + 
//         std::to_string(int(reinterpret_cast<char*>(&ip)[1])) + '.' +
//         std::to_string(int(reinterpret_cast<char*>(&ip)[2])) + '.' +
//         std::to_string(int(reinterpret_cast<char*>(&ip)[3])) + ':' +
//         std::to_string( client.getPort ());
// }

// int main() {
//     // Создание экземпляра сервера
//     TcpServer server(8080, [](DataBuffer data))
// }