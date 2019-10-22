#ifndef CarPrice
#define CarPrice

void readLib(char * fileName, FILE* lib) {
    if (!(lib = fopen(fileName, "r+"))) {
        printf("Can not open file!");
        return -1;
    }
}

void printLib(FILE* lib) {
    while (feof(lib) == 0) {
        char buf[100]
        fgets(buf, 100, lib);
    }
    printf("%s\n", );
}

#endif
