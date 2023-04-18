/*
File: Transmit_Data_Header.h
Author: Phan Trong Nguyen
Date: 
Description:
*/
#ifndef Traffic
#define Traffic

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum
{
    MAY_BAY_THUONG_MAI,
    MAY_BAY_TRUC_THANG,
    XE_MAY,
    XE_KHACH,
    XE_DAP,
    TAU_THUY,
    CA_NO,
} CAC_LOAI_PHUONG_TIEN;

typedef enum
{
    DUONG_HANG_KHONG,
    DUONG_BO,
    DUONG_THUY
} CAC_LOAI_DUONG_DI;

typedef union
{
    CAC_LOAI_PHUONG_TIEN may_bay_thuong_mai;
    CAC_LOAI_PHUONG_TIEN may_bay_truc_thang;
} BAY;

typedef union
{
    CAC_LOAI_PHUONG_TIEN xe_khach;
    CAC_LOAI_PHUONG_TIEN xe_may;
    CAC_LOAI_PHUONG_TIEN xe_dap;
} BO;

typedef union
{
    CAC_LOAI_PHUONG_TIEN tau_thuy;
    CAC_LOAI_PHUONG_TIEN ca_no;
} THUY;

typedef union
{
    BAY bay;
    BO bo;
    THUY thuy;
    CAC_LOAI_PHUONG_TIEN phuong_tien;
    CAC_LOAI_DUONG_DI DUONG;
} LOAI_DUONG_DI;

void LANE(LOAI_DUONG_DI *loai_duong_di, LOAI_DUONG_DI *loai_phuong_tien);
void Chose_Price(LOAI_DUONG_DI loai_phuong_tien);


#endif