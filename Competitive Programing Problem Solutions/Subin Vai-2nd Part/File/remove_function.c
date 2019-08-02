#include<stdio.h>
#include<stdlib.h>
int main(){
    char *file_name;
    file_name = "cse1.jpg";
    int return_value;
    return_value = remove(file_name);
    if(return_value != 0){
        perror("File removed failed");
        return EXIT_FAILURE;
    }
    printf("%s removed successfully\n",file_name);

    return 0;
}
