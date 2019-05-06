#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int get_mem_useage(){
		int fd = open("/proc/meminfo",O_RDONLY);
		if(fd < 0){
				return 0;
		}
		char* buf = calloc(1,1024*10);
		if(buf == NULL){
				return 0;
		}

		int size = read(fd,buf,1024*10);
		if(size < 0){
				return 0;
		}

		printf("%s\n",buf);

		int mem_free = 0,mem_total = 0;
		char tmpbuf1[32],tmpbuf2[32];

		char*ptotal = strstr(buf,"MemTotal:");
		if(NULL == ptotal){
				return 0;
		}
		sscanf(ptotal,"%s%d%s",tmpbuf1,&mem_total,tmpbuf2);

		printf("mem_total = %d\n",mem_total);

		char*pfree = strstr(buf,"MemFree:");
		if(NULL == pfree){
				return 0;
		}
		sscanf(pfree,"%s%d%s",tmpbuf1,&mem_free,tmpbuf2);
		printf("mem_free = %d\n",mem_free);
		//printf("%s\n%s\n",tmpbuf1,tmpbuf2);

		free(buf);
		close(fd);
		return 100 - (mem_free * 100  / mem_total);
}

int get_cpu_useage(){
		FILE* fp = popen("top -bn 1","r");
		if(NULL == fp){
				printf("%d-debug",__LINE__);
				return 0;
		}
		char buf[1025] = {'\0'};
		if(buf == NULL){
				printf("%d-debug",__LINE__);
				pclose(fp);
				return 0;
		}

		int size = fread(buf,1024,1,fp);
		if(size <= 0){
				printf("%d-debug",__LINE__);
				pclose(fp);
				return 0;
		}

		printf("%s\n",buf);

		char* p_buf = strstr(buf,"id,");
		printf("%s\n",p_buf);
		char tmp[32] = {'\0'};
		strncpy(tmp,p_buf-5,2);
		printf("%s\n",tmp);

		pclose(fp);
		return 100 - atoi(tmp);
}


int main(){
		//printf("mem_useage = %d\n",get_mem_useage());
		printf("cpu_useage = %d\n",get_cpu_useage());
}
