#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    //创建套接字
    int clnt_sock = socket(AF_INET, SOCK_STREAM, 0);

    //向服务器（特定的IP和端口）发起请求
    struct sockaddr_in serv_addr = {};
    serv_addr.sin_family = AF_INET;             //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    serv_addr.sin_port = htons(1234);           //端口

    connect(
        clnt_sock,
        (struct sockaddr*)&serv_addr,
        sizeof(serv_addr)
    );

    //读取服务器传回的数据
    char buffer[40];
    read(clnt_sock, buffer, sizeof(buffer) - 1);

    printf("Message form server: %s\n", buffer);

    //关闭套接字
    close(clnt_sock);

    return 0;
}
