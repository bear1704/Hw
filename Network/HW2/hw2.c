/*
Student ID : 20133222
Name : Park soo chan
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 100

void error_handling(char *message);
void display();

#define MAXCLIENT (16)
int clienttcpSocket[MAXCLIENT];	// max 16 clients


int main(int argc, char **argv) {


  int tcpServ_sock;

  struct sockaddr_in tcpServer_addr;
  struct sockaddr_in tcpClient_addr;
  struct sockaddr_in newTcp_addr;

  // initialize the client socket descriptors
  for(int i = 0; i < MAXCLIENT; i++) {
  	clienttcpSocket[i] = -1;;	// max 128 clients

  }

  int slot;
	int data_read;
	int remain_socket = 0;
	int denySocket;
  socklen_t clnt_len;

	char denyMessage[80] = "\nServer Connection Capacity is full, connection denied, byebye!\n";

  fd_set reads, temps;
  int fd_max;


  char str[BUFSIZE];
  int option = 2;

  char *tcpport = NULL;


  if(argc != 2) {
    printf("Usage : %s <tcpport> \n", argv[0]);
    exit(1);
  }

  tcpport = argv[1];

  display();



  tcpServ_sock = socket(PF_INET, SOCK_STREAM, 0);
  if(tcpServ_sock == -1)
	  error_handling("socket() error");

		clnt_len = sizeof(tcpClient_addr); //개인
  memset(&tcpServer_addr, 0 , sizeof(tcpServer_addr));
  tcpServer_addr.sin_family = AF_INET;
  tcpServer_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  tcpServer_addr.sin_port = htons(atoi(tcpport));

  setsockopt(tcpServ_sock, SOL_SOCKET, SO_REUSEADDR, (const void *)&option, sizeof(int));
  if( bind(tcpServ_sock, (struct sockaddr *) &tcpServer_addr, sizeof(tcpServer_addr)) == -1 )
	  error_handling("bind() error");


  if(listen(tcpServ_sock, 5)==-1)
    error_handling("listen() error");

  FD_ZERO(&reads);
  FD_SET(tcpServ_sock, &reads);
  fd_max = tcpServ_sock;


  while(1) {

    int nfound = 0;

    temps = reads;

    nfound = select(fd_max+1, &temps, 0, 0, NULL);

	if(FD_ISSET(tcpServ_sock, &temps)) {
		// Input from the client for new connection
		// This request will arrive after UDP sent
			remain_socket = 0;
					for(int k=0 ; k<MAXCLIENT ; k++)
					{
						if(clienttcpSocket[k] == -1)
						{
							remain_socket = 1;  //남은 배열공간이 있으면 무조건 1
						}
					}



					for(int i=0 ; i<MAXCLIENT ; i++)
					{
								if(remain_socket != 1)
							{
								printf("connection limit is full\n");
								denySocket = accept(tcpServ_sock,(struct sockaddr*)&tcpClient_addr , &clnt_len);
								write(denySocket,denyMessage,strlen(denyMessage));
								close(denySocket);
								break;
							}  //연결 꽉찼을때 연결 거부하기

							if(clienttcpSocket[i] == -1)
						{


								clienttcpSocket[i] = accept(tcpServ_sock,(struct sockaddr*)&tcpClient_addr , &clnt_len);
								FD_SET(clienttcpSocket[i],&reads);
								printf("connection from host %s , port %d, socket %d \n",inet_ntoa(tcpClient_addr.sin_addr),
																	ntohs(tcpClient_addr.sin_port), clienttcpSocket[i]);
								fd_max++;
								break;
								//연결 처리하기
							}

					}//for

  		FD_CLR(tcpServ_sock, &temps); //아마 서버소켓 set 1로 되있던거 다시 받을수있게 0으로 초기화인듯

	} else {

		for(int i = 0; i < MAXCLIENT; i++) {
		  if (FD_ISSET(clienttcpSocket[i], &temps)) {
				data_read = read(clienttcpSocket[i],str,BUFSIZE);

				if(data_read > 0){
				for(int j=0 ; j< MAXCLIENT ; j++)
				{
					if(j != i)
				write(clienttcpSocket[j],str,strlen(str));

			  }//for
					memset(str,NULL,BUFSIZE); //스트링 배열을 깨끗하게 비워준다(다음 채팅을 위하여)
			}//if
			else{
				printf("Connection Closed %d\n" , clienttcpSocket[i]);
				close(clienttcpSocket[i]);
				FD_CLR(clienttcpSocket[i], &reads);
				clienttcpSocket[i] = -1;


			}//else
			FD_CLR(clienttcpSocket[i], &temps); //이 또한 소켓 1->0 SET
			// NEED TO IMPLEMENT HERE
		}// big if 151
		}//for
	} //else


  }//while End
}//main End

void display() {
	printf("Student ID : 20133222 \n");
	printf("Name : Soochan Park  \n");

}

void error_handling(char *message) {
  fputs(message, stderr);
  fputc('\n', stderr);
  perror("hw2 error");
  exit(1);
}
