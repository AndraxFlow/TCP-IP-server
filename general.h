#ifndef GENERAL_H
#define GENERAL_H

#ifdef _WIN32
#else
#define SD_BOTH 0
#endif

#include <cstdint>
#include <cstring>
#include <cinttypes>
#include <malloc.h>


// IP 127.0.0.1
uint32_t LOCALHOST_IP = 0x0100007f;

// Код состояния сокета
enum class SocketStatus : uint8_t {
    connected = 0,
    err_socket_init = 1,
    err_socket_bind = 2,
    err_socket_connect = 3,
    disconnected = 4
};

// Буфер данных куда у нас будут приниматься данные от другой стороны
struct DataBuffer
{
    int size = 0;
    void* data_ptr = nullptr;

    DataBuffer() = default; // конструктор по умолчанию
    DataBuffer(int size, void* data_ptr) : size(size), data_ptr(data_ptr){} // параметризированный конструктор 
    DataBuffer(const DataBuffer& other) : size(other.size), data_ptr(malloc(size)){memcpy(data_ptr,other.data_ptr, size);} // конструктор копирования
    DataBuffer(DataBuffer&& other) : size(other.size), data_ptr(other.data_ptr){other.data_ptr = nullptr;} // конструктор перемещения
    ~DataBuffer() {if(data_ptr) free(data_ptr); data_ptr = nullptr;}// деструктор

    bool isEmpty(){return !data_ptr || !size;}

    operator bool() {return data_ptr && size;}
};
// в последней версии библиотеки typedef от std::vector<uint8_t>
// Тип сокета
enum class SocketType : uint8_t {
  client_socket = 0,
  server_socket = 1
};

// Базовый класс TCP клиента
class TcpClientBase {
public:
  typedef SocketStatus status;
  virtual ~TcpClientBase() {};
  virtual status disconnect() = 0;
  virtual status getStatus() const = 0;
  virtual bool sendData(const void* buffer, const size_t size) const = 0;
  virtual DataBuffer loadData() = 0;
  virtual uint32_t getHost() const = 0;
  virtual uint16_t getPort() const = 0;
  virtual SocketType getType() const = 0;
};

#endif /*GENERAL_H*/

