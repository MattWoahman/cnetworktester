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
//nvm i figured this out lol

char *domainGet(void);

char *domainGet(void){
	printf("What is your domain/ip address?\n");
	char* buffer = malloc(50*sizeof(char));
	char* domainInput = fgets(buffer,50,stdin);
	char domainName[strlen(domainInput)-1];
	for (int i = 0; i < (strlen(domainInput) - 1); i++) {
		domainName[i] = domainInput[i];
	}
	return domainName;
}

int portcontest(char* domainName, int port);

int blastServer(int port);

int blastServer(int port){
	int test = 0;
	printf("Checking blast service status\n\n");
	//test port by either nmapping, netstat, ss, whatever can be done / is OS agnostic
	printf("Checking blast service port\n\n");
	test = 1;
	return test;
}
int agentservicetest(void);

int main(void) {

int pingSuccess = 1;

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
	char* domainName = domainGet();
	printf("%s is your domain name\n", domainName);
	pingSuccess = netcontest(domainName);
}
int blastTrue;
if (input == '2'){
	printf("What port is VMWare blast listening on? (default = 22443)\n");
	fflush(stdin);
	int port;
	char buffer[5];
	char* portInput = fgets(buffer,50,stdin);
	char portParse[strlen(portInput)-1];
	for (int i=0; i<(strlen(portInput)); i++){
		portParse[i] = portInput[i];
		printf("%c", portParse[i]);
	}
	if (strlen(portInput) == 1) {
		port = 22443;
	} else {
		port = atoi(portParse);
	}
	printf("Your port is %d!\n", port);
	blastTrue = blastServer(port);	
}

//add trcroute
if (pingSuccess == 0) {
	printf("Success! You can reach your domain!\n"); //change this to the ip/domain name
} else {
	printf("Failed! You cannot reach your domain.\n");
}

return 0;

}
