//#include <windows.h>
//#undef IN
//#define IN 




#include <iostream>
#undef IN
#undef OUT

#include <winsock2.h>
#undef IN
#undef OUT

int init_sockets()
{
    WSADATA data{};
    int result = WSAStartup(MAKEWORD(2, 2), &data);
    if (result != 0)
        return result;

    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock != INVALID_SOCKET)
    {
        // Use the socket...
        closesocket(sock);
    }

    WSACleanup();
    return 0;
}
