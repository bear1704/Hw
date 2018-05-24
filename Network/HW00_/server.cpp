#include <ctime>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 128

void error_handling();


int main(int argc, char *argv[])
{
/*
  struct timespec ts_start;
 clock_gettime(CLOCK_MONOTONIC, &ts_start);
  std::cout << ts_start.tv_nsec << std::endl;
*/

  int serv_sock;
  char message[BUF_SIZE];
  int str_len;
  socklen_t clnt_adr_sz;

  struct sockaddr_in serv_adr, clnt_adr;
  if(argc != 2)
  {
    std::cout << "Usage : " << argv[0] << " " << std::endl;
    exit(1);
  }

  serv_sock = socket(PF_INET, SOCK_DGRAM, 0);
  if(serv_sock == -1)
    error_handling();

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));

    if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
        error_handling();

    while(1)
    {
      clnt_adr_sz = sizeof(clnt_adr);
      str_len = recvfrom(serv_sock, message, BUF_SIZE, 0, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
      sendto(serv_sock, message, str_len, 0, (struct sockaddr*)&clnt_adr, clnt_adr_sz);
      std::cout << message << std::endl;

    }
    close(serv_sock);
    return 0;

}


void error_handling()
{
  std::cout << "error_handling" << std::endl;
  exit(1);
}
