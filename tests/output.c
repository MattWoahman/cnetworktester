#include <stdio.h>
int main() {

int pingSuccess = 1;
char* domainName = "parzival.ctcr.local";

printf("What Horizon server do you want to test?\n");
// add user input and assignment to variable
printf("What do you want to test?\n");
//add test selection / tests

char* testType = "network connection test";


printf("You chose %s... is that correct? (y/n)\n", testType);
// Connection test

printf("Pinging %s ...\n\n", domainName); 

//add ping test
//add trcroute
if (pingSuccess == 0) {
	printf("Success! You can reach %s!\n", domainName); //change this to the ip/domain name
} else {
	printf("Failed! You cannot reach %s.\n", domainName);
}

return 0;

}
