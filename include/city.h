#ifndef CITY_H
#define CITY_H

typedef struct _city
{
    char state;
    char* card_code;
    char* city_name;
    int population;
    float area;
    float gpd;
    int tourist_sites_count;
} City;

#endif
