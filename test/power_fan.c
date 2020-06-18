
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>


int get_fan(char*buf){
		FILE* fp = popen("ipmi-sensors | grep FAN","r");
		if(NULL == fp){
				return -1;
		}

		const char* l = "ID | Name | Type | Reading | Units | Event\n";
		strcpy(buf,l);

		int size = fread(buf+strlen(l),1024,1,fp);
		if(size <= 0){
				pclose(fp);
				return -1;
		}

		pclose(fp);
		return 0;
}

int get_power(char*buf){
		FILE* fp = popen("ipmi-sensors | grep PS","r");
		if(NULL == fp){
				return -1;
		}

		const char* l = "ID | Name | Type | Reading | Units | Event\n";
		strcpy(buf,l);

		int size = fread(buf+strlen(l),1024,1,fp);
		if(size <= 0){
				pclose(fp);
				return -1;
		}

		pclose(fp);
		return 0;
}

int main(){
	char buf[1024] = {'\0'};
	get_fan(buf);
	printf("%s\n",buf);
	char buf1[1024] = {'\0'};
	get_power(buf1);
	printf("%s\n",buf1);
	return 0;
}
