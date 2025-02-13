#include "lab11.h"

struct Database_t{
    Car** skuSort;
    Car** priceSort;
    int size;
};
//For this function I malloced everything and sorted it into two arrays to use in later functions
Database * makeDatabase(Car *cars, int size){
    Database *base = malloc(sizeof(Database));
    if(!base){
        return NULL;
    }
    Car** sku = malloc(sizeof(Car*)*size);
    if(!sku){
        free(base);
        return NULL;
    }
    Car** price = malloc(sizeof(Car*)*size);
    if(!price){
        free(sku);
        free(base);
        return NULL;
    }

    base->size = size;
    base->skuSort = sku;
    base->priceSort = price;
    for(int i =0; i<size; i++){
        sku[i] = &cars[i];
        price[i] = &cars[i];
    }

    for(int i = 1; i< size; i++){
        Car * car = sku[i];
        int j =i-1;
        while(j >=0 && sku[j]->SKU > car->SKU){
            sku[j+1] = sku[j];
            j = j-1;
        }
        sku[j+1] = car;   
    }
    for(int i = 1; i< size; i++){
        Car * car = price[i];
        int j =i-1;
        while(j >=0 && price[j]->price > car->price){
            price[j+1] = price[j];
            j = j-1;
        }
        price[j+1] = car;   
    }
    return base;
}
//This function simply prints the sorted array by SKU
void printSKU_Sorted(Database *db){
    for(int i = 0; i<db->size; i++){
        printf("%d", db->skuSort[i]->SKU);
        if(i+1 != db->size){
            printf(", ");
        }
    }
    printf("\n");
    return;
}
//This function simply prints the sorted array by Price
void printPriceSorted(Database *db){
    for(int i = 0; i<db->size; i++){
        printf("$%f", db->priceSort[i]->price);
        if(i+1 != db->size){
            printf(", ");
        }
    }
    printf("\n");
    return;
}
//Look for the SKU then returnt he PN using binary search
unsigned long long getPN_FromSKU(Database *db, int SKU){
    int max = db->size - 1;
    int low = 0;
    int n = (((max))/2);
    while(low <= max){
        if(db->skuSort[n]->SKU == SKU){
            return db->skuSort[n]->OEM_PN;
        } else if(db->skuSort[n]->SKU > SKU){
            max = n-1;
            n = ((low + max)/2);
        } else if(db->skuSort[n]->SKU < SKU){
            low = n+1;
            n = ((low + max)/2);
        }
    }
    return -1;
}
//Look for the Price then returnt he SKU by binary search
int getSKU_FromPrice(Database *db, double price){
    int max = db->size;
    int low = 0;
    int n = (((max))/2);
    while(low <= max){
        if(db->priceSort[n]->price == price){
            return db->priceSort[n]->SKU;
        } else if(db->priceSort[n]->price > price){
            max = n-1;
            n = ((low + max)/2);
        } else if(db->priceSort[n]->price < price){
            low = n+1;
            n = ((low + max)/2);
        }
    }
    return -1;
}
//Free everything
void destroy(Database *db){
    free(db->skuSort);
    free(db->priceSort);
    free(db);
}
