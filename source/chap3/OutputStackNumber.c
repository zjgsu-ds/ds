#include "stdio.h"
#include "Container.h"
#include "stdlib.h"

char ch[5] = "abcd";
int n = 4;

void Heap(char *pStack, int iNext, int nCurStack, char *pPathContent, int nPathContent)
{
    char *pStackPush, *pStackPop, *pPopPathContent;
    int iPath = 0;
    if(nCurStack==0 && iNext >= n) {
        // Print the path
        for(; iPath < nPathContent; iPath++)
            printf("%c ", pPathContent[iPath]);
        printf("\n");
    } else {
        if(iNext < n) { // Push a new element
            pStackPush = (char *)malloc(sizeof(nCurStack+1));
            if(nCurStack > 0) {
                memcpy(pStackPush, pStack, sizeof(char)*nCurStack);
            }

            pStackPush[nCurStack] = ch[iNext];
            Heap(pStackPush, iNext+1, nCurStack+1, pPathContent, nPathContent);

            free(pStackPush);
        }

        if(nCurStack >= 1) { // Pop a new element
            pPopPathContent = (char *)malloc(sizeof(nPathContent+1));
            if(nPathContent > 0) {
                memcpy(pPopPathContent, pPathContent, sizeof(char)*(nPathContent));
            }
            pPopPathContent[nPathContent] = pStack[nCurStack-1];
            //printf("%c ", pStack[nCurStack-1]);
            pStackPop = 0;
            if(nCurStack>1) {
                pStackPop = (char *)malloc(sizeof(nCurStack-1));
                memcpy(pStackPop, pStack, sizeof(char)*(nCurStack-1));
            }

            Heap(pStackPop, iNext, nCurStack-1, pPopPathContent, nPathContent+1);

            if(nCurStack>1)
                free(pStackPop);
            free(pPopPathContent);
        }
    }
}

void main()
{
    Heap(0, 0, 0, 0, 0);

    getchar();

    return;
}

