#include "lab11.h"

struct Database_t{
    Car** skuSort;
    Car** priceSort;
    int size;
};

/*
struct Car_t {
    int SKU;
    double price;
    unsigned long long OEM_PN;
};
*/

int main(){
    Car* unsorted = malloc(sizeof(Car)*5);
    unsorted[0] = (Car){10, 5, 1};
    unsorted[1] = (Car){4, 2.9, 2};
    unsorted[2] = (Car){12, 1.78, 3};
    unsorted[3] = (Car){1, 10.5, 4};
    unsorted[4] = (Car){20, 3.1, 5};

    Database *db = makeDatabase(unsorted, 5);

   printSKU_Sorted(db);

   printPriceSorted(db);

   printf("%lld\n", getPN_FromSKU(db, 1));
   printf("%d\n", getSKU_FromPrice(db, 1.78));


    free(unsorted);
}