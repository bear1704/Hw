// Student ID : 20133222
// Name : soochan park(박수찬)

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

#define PROMPT() {printf("\n> ");fflush(stdout);}
#define GETCMD "dl"
#define QUITCMD "quit"


int main(int argc, char *argv[]) {
	char buf[BUFSIZ];


	printf("Student ID : 20133222\n");
		printf("Name : Soochan park\n");



	int sock;
	int clen;
	struct sockaddr_in server_addr;
	struct hostent *hostp;
	int n;
	FILE *fp;

	PROMPT();

	for (;;) {
		if (!fgets(buf, BUFSIZ - 1, stdin)) {   // 입력 받는 부분
			if (ferror(stdin)) {
				perror("stdin");
				exit(1);
			}
			exit(0);
		}

		char *cmd = strtok(buf, " \t\n\r");  //커맨드로 받은 문자열 자르기

		if((cmd == NULL) || (strcmp(cmd, "") == 0)) {
			PROMPT();
			continue;
		} else if(strcasecmp(cmd, QUITCMD) == 0) { //나간다
				exit(0);
		}

		if(!strcasecmp(cmd, GETCMD) == 0) {
			printf("Wrong command %s\n", cmd);  //잘못된 커맨드 확인
			PROMPT();
			continue;
		}




		// connect to a server
		char *hostname = strtok(NULL, " \t\n\r");
		char *pnum = strtok(NULL, " ");
		char *filename = strtok(NULL, " \t\n\r");

		sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

		if(sock < 0){
			perror("socket error : ");
			exit(1);
		}

		if((hostp = gethostbyname(hostname)) == 0){
			fprintf(stderr,"%s: unknown host\n",hostname); // 3rd parameter may ..
			exit(1);
		}
		//hostp = 아이피주소(문자->숫자(아이피))

		//접속할 주소 지정
		memset(&server_addr, 0 , sizeof(server_addr));
		server_addr.sin_family = AF_INET;
		server_addr.sin_port = htons((u_short)atoi(pnum)); //*pnum해야 되나
		memcpy((void *) &server_addr.sin_addr, hostp->h_addr_list[0], hostp->h_length);

		clen = sizeof(server_addr);

		if(connect(sock,(struct sockaddr *)&server_addr, clen) < 0){

			(void) close(sock);
			perror("connect error :");
			exit(1);
		}



		char filen[80];
		strcpy(filen,filename);


		memset(buf,0,BUFSIZ);

		sprintf(buf,"GET %s HTTP/1.0\r\nHost: netapp.cs.kookmin.ac.kr\r\nUser-agent: HW1/1.0\r\nConnection: close\r\n\r\n",filen);

		if(write(sock,buf,strlen(buf)) < 0){
			perror("write");
			exit(1);
		} //서버전송
		n = read(sock,buf,BUFSIZ);

		char cmp[] = {"Content-Length: "};
		char* result;
		char* copy_result;//copy_result : 처음 받는 헤더에 남은 body 부분
		int int_result = 0;//int_result == 현재 받아야할 파일 크기
		int firstBodySize = 0;
		char* originbuf = buf;
		int headerLength;
		int bodyLength;
		int separateFile = 0;
		int fullFile = 0;
		int flag = 0;

		strcpy(originbuf,buf);

		headerLength = strstr(originbuf,"\r\n\r\n") + 4 - originbuf;
		bodyLength = n - headerLength;
		//printf("\n\n=====%d=====\n\n",bodyLength);


		result = strstr(buf,cmp);
				result = strstr(result," ");
				//printf("\n\n=====%s=====\n\n",buf);

				copy_result = strstr(buf,"\r\n\r\n") + 4;
				//printf("\n\n=====%s=====\n\n",copy_result);

		result = result+1;


		result = strtok(result,"C");
		int_result = atoi(result);


		fp = fopen("palladio.JPG","w");
		fwrite((void *)copy_result, sizeof(char),bodyLength/sizeof(char),fp); //처음 보디부분 저장

		printf("Total size :  %d bytes\n\n",int_result);
		fullFile = int_result;
		int_result -= firstBodySize; // 한번 write한거 적용(이미지 용량만이니까 10만 빼는것)



		while(!(n == 0)){

			if(separateFile >= fullFile/10 && separateFile <= fullFile/5 && flag == 0){
					printf("%dkb/%dkb downloaded (10%%)\n",fullFile/10,fullFile);
					flag++;
			}else if(separateFile >= fullFile /5 && separateFile <= fullFile * 3/10 && flag == 1)
			{
				printf("%dkb/%dkb downloaded (20%%)\n",fullFile/5,fullFile);
				flag++;
			}else if(separateFile >= fullFile * 3/10 && separateFile <= fullFile * 4/10 && flag == 2)
			{
				printf("%dkb/%dkb downloaded (30%%)\n",fullFile * 3/10,fullFile);
				flag++;
			}else if(separateFile >= fullFile * 4/10 && separateFile <= fullFile * 5/10 && flag == 3)
			{
				printf("%dkb/%dkb downloaded (40%%)\n",fullFile * 4/10,fullFile);
				flag++;
			}else if(separateFile >= fullFile * 5/10 && separateFile <= fullFile * 6/10 && flag == 4)
			{
				printf("%dkb/%dkb downloaded (50%%)\n",fullFile * 5/10,fullFile);
				flag++;
			}else if(separateFile >= fullFile * 6/10 && separateFile <= fullFile * 7/10 && flag == 5)
			{
				printf("%dkb/%dkb downloaded (60%%)\n",fullFile * 6/10,fullFile);
				flag++;
			}else if(separateFile >= fullFile * 7/10 && separateFile <= fullFile * 8/10 && flag == 6)
			{
				printf("%dkb/%dkb downloaded (70%%)\n",fullFile * 7/10,fullFile);
				flag++;
			}else if(separateFile >= fullFile * 8/10 && separateFile <= fullFile * 9/10 && flag == 7)
			{
				printf("%dkb/%dkb downloaded (80%%)\n",fullFile * 8/10,fullFile);
				flag++;
			}else if(separateFile >= fullFile * 9/10 && separateFile <= fullFile && flag == 8)
			{
				printf("%dkb/%dkb downloaded (90%%)\n",fullFile * 9/10,fullFile);
				flag++;
			}




			memset(buf,0,BUFSIZ);
		n = read(sock,buf,BUFSIZ);

		fwrite(buf,sizeof(char),n/sizeof(char),fp);
		int_result -= n;
		separateFile += n;
	}

		printf("%dkb/%dkb downloaded (100%%)",fullFile,fullFile);
		printf("\ndownload complete");
		fclose(fp);

		close(sock);


		// send the HTTP Request Message to the server

		// receive the HTTP Response Message
		// you need to parse the "Content-Length" header field


		PROMPT();
	}
}
