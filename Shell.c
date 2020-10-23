#include <stdio.h>
void echo(){

}
int main(){
	char str1[2000];
	printf("Enter name: ");
	scanf("%[^\n]\ns", str1);
	printf("Entered Name: %s\n", str1);
	return(0);
}