//
// Created by vant on 18-10-12.
//

#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int r;
    while ((r = getopt(argc, argv, "ef：")) != -1) {

        switch (r) {
            case 'e':
                printf("entered e\n");
                break;
            case 'f':
                printf("entered f\n");
                break;
            case '?':
                printf("?\n");
                break;
            case ':':
                printf(":\n");
                break;
        }
    }
}