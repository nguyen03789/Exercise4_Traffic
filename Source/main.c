/*
File: main.c
Author: Phan Trong Nguyen
Date: 
Description:
*/
#include "Traffic.c"

int main(int argc, char const *argv[])
{
    LOAI_DUONG_DI cac_loai_phuong_tien, a;
    LANE(&cac_loai_phuong_tien, &a);
    Chose_Price(cac_loai_phuong_tien);
    return 0;
}