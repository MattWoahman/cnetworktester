#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int netcontest(char* domainName);

int netcontest(char* domainName){
	printf("Pinging %s ...\n\n", domainName);
	int test = 0;
	//if (pingtest == success) { test = 0};
	//if (pingtest == failure) { test = 1};
	return test;
}
//need to see if I can override the function or make port have a default value (blast's port)
int portcontest(char* domainName, int port);

int agentservicetest(void);

int main(void) {

FILE* fp;

int pingSuccess = 1;



char testType;

int input;
int count = 0;
int yn;

printf("VMWare blast connection tester\n\n");
// add user input and assignment to variable
while ( yn != 'y') {
	
	printf("What do you want to test?\n");
	printf("1. Network Connection\n");
	printf("2. Blast server\n");
	printf("3. Trace route\n\n");

	//add test selection / tests
	fflush(stdin);
	
	input = fgetc(stdin);
	char* tests[3] = {"Network Connection", "Blast server", "Trace route"};
	int utest = (input - '0');
	printf("You chose %s... is that correct? (y/n)\n", tests[utest - 1]);


	fflush(stdin);
	yn = fgetc(stdin);
}
fflush(stdin);
if (input == '1'){
	int dn;
	printf("What is your domain/ip address?\n");
	char buffer[50];
	char* domainInput = fgets(buffer,50,stdin);
	char domainName[strlen(domainInput)-1];
	for (int i = 0; i < (strlen(domainInput) - 1); i++) {
		domainName[i] = domainInput[i];
	}
	printf("%s is your domain name\n", domainName);
	pingSuccess = netcontest(domainName);
}

//add ping test
//add trcroute
if (pingSuccess == 0) {
	printf("Success! You can reach your domain!\n"); //change this to the ip/domain name
} else {
	printf("Failed! You cannot reach your domain.\n");
}

return 0;

}
