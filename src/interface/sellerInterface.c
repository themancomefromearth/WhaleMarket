#include "interface/interface.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sell() {
    User* seller = getUser(curUser);
    Good* g = (Good*)malloc(sizeof(Good));
    printf("Please input the information of your product ...\n");
    printf("Name: ");
    scanf("%s", g->name);
    printf("Price: ");
    char buffer[MAX_LEN];
    scanf("%s", buffer);
    g->price = atof(buffer);
    while (g->price <= 0) {
        illegalMessage();
        printf("Please Try Again: ");
        scanf("%s", buffer);
        g->price = atof(buffer);
    }
    printf("Description: ");
    scanf("%s", g->description);
    strcpy(g->seller_id, seller->id);
    addGood(g);
    free(g);
}

static HANDLER handler[] = {sell, inv, inv, inv, inv, inv, inv};
make_interface(S, ELLER)
