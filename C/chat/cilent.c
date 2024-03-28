#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")

#define MAX_MESSAGE_LEN 256

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup failed.\n");
        return 1;
    }

    SOCKET client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == INVALID_SOCKET) {
        printf("Error creating socket: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.100"); // 请替换为实际的服务器 IP 地址
    server_addr.sin_port = htons(8888);

    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        printf("Error connecting to server: %ld\n", WSAGetLastError());
        closesocket(client_socket);
        WSACleanup();
        return 1;
    }

    char username[MAX_MESSAGE_LEN];
    char message[MAX_MESSAGE_LEN];

    printf("Enter your username: ");
    fgets(username, MAX_MESSAGE_LEN, stdin);
    username[strlen(username) - 1] = '\0'; // 去除换行符

    send(client_socket, username, strlen(username), 0);

    recv(client_socket, message, sizeof(message), 0);
    printf("%s\n", message);

    while (1) {
        printf("Enter your message (or /quit to exit): ");
        fgets(message, MAX_MESSAGE_LEN, stdin);
        message[strlen(message) - 1] = '\0'; // 去除换行符

        send(client_socket, message, strlen(message), 0);

        if (strcmp(message, "/quit") == 0) {
            break;
        }
    }

    closesocket(client_socket);
    WSACleanup();

    return 0;
}