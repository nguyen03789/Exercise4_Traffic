/*
File: Traffic.c
Author: Phan Trong Nguyen
Date: 
Description:
*/
#include "Traffic_Header.h"
int a = 1;

//////////////////////
#define KEY_lane(key_lane) key_lane

#define KEY(key) key

#define NAME(name) name

#define CMD(cmd) cmd

#define Display(key_lane, name) \
    if (phim == 9 && a == 0)    \
        printf("Nhan %d: %s\n", key_lane, name);

#define Chose_Key(key_lane, name, cmd)     \
    if (phim != 9 && a == 0)               \
    {                                      \
        if (phim == key_lane)              \
        {                                  \
            printf("Ban chon %s\n", name); \
            cmd;                           \
        }                                  \
    }

#define Display_V(key, name)    \
    if (phim_v == 10 && a == 1) \
        printf("Nhan %d: %s\n", key, name);

#define Chose_Key_V(key, name, cmd)        \
    if (phim_v != 10 && a == 1)            \
    {                                      \
        if (phim_v == key)                 \
        {                                  \
            printf("Ban chon %s\n", name); \
            cmd;                           \
        }                                  \
    }

#define Key_CMD(key_lane, name, cmd)       \
    if (a == 0)                            \
    {                                      \
        Display(key_lane, name)            \
        Chose_Key(key_lane, name, cmd) \
    }

#define Key_CMD_V_B(key, name, cmd)     \
    if (phim == 2 && a == 1)            \
    {                                   \
        Display_V(key, name)            \
        Chose_Key_V(key, name, cmd) \
    }

#define Key_CMD_V_Ba(key, name, cmd)    \
    if (phim == 1 && a == 1)            \
    {                                   \
        Display_V(key, name)            \
        Chose_Key_V(key, name, cmd) \
    }

#define Key_CMD_V_T(key, name, cmd)     \
    if (phim == 3 && a == 1)            \
    {                                   \
        Display_V(key, name)            \
        Chose_Key_V(key, name, cmd) \
    }

#define P(name, cmd)                         \
    case name:                               \
        printf("Gia ve: %d.000 vnd\n", cmd); \
        break;

#define Type_of_lane(...)                                                    \
    void LANE(LOAI_DUONG_DI *loai_duong_di, LOAI_DUONG_DI *loai_phuong_tien) \
    {                                                                        \
        printf("Ban muon di chuyen bang duong nao?\n");                      \
        int phim = 9, phim_v = 10, a = 0;                                    \
        __VA_ARGS__                                                          \
        scanf("%d", &phim);                                                  \
        __VA_ARGS__                                                          \
        a++;                                                                 \
        printf("Vui long chon loai phuong tien\n");                          \
        __VA_ARGS__                                                          \
        printf("nhan 0 : quay lai\n");                                       \
        scanf("%d", &phim_v);                                                \
        __VA_ARGS__                                                          \
    }

Type_of_lane(
    Key_CMD(
        KEY_lane(1),
        NAME("duong hang khong"),
        CMD(loai_duong_di->DUONG = DUONG_HANG_KHONG))
    Key_CMD(
        KEY_lane(2),
        NAME("duong bo"),
        CMD(loai_duong_di->DUONG = DUONG_BO))
    Key_CMD(
        KEY_lane(3),
        NAME("duong thuy"),
        CMD(loai_duong_di->DUONG = DUONG_THUY))
    Key_CMD(
        KEY_lane(0),
        NAME("quay lai"),
        CMD(exit(0)))
    Key_CMD_V_Ba(
        KEY(1),
        NAME("may bay thuong mai"),
        CMD(loai_phuong_tien->bay.may_bay_thuong_mai = MAY_BAY_THUONG_MAI))
    Key_CMD_V_Ba(
        KEY(2),
        NAME("may bay truc thang"),
        CMD(loai_phuong_tien->bay.may_bay_thuong_mai = MAY_BAY_TRUC_THANG))
    Key_CMD_V_B(
        KEY(1),
        NAME("xe may"),
        CMD(loai_phuong_tien->bo.xe_may = XE_MAY))
    Key_CMD_V_B(
        KEY(2),
        NAME("xe dap"),
        CMD(loai_phuong_tien->bo.xe_dap = XE_DAP))
    Key_CMD_V_B(
        KEY(3),
        NAME("xe khach"),
        CMD(loai_phuong_tien->bo.xe_khach = XE_KHACH))
    Key_CMD_V_T(
        KEY(1),
        NAME("tau thuy"),
        CMD(loai_phuong_tien->thuy.tau_thuy = TAU_THUY))
    Key_CMD_V_T(
        KEY(2),
        NAME("ca no"),
        CMD(loai_phuong_tien->thuy.ca_no = CA_NO)))

#define PRICE(...)                                   \
    void Chose_Price(LOAI_DUONG_DI loai_phuong_tien) \
    {                                                \
        switch (loai_phuong_tien.phuong_tien)        \
        {                                            \
            __VA_ARGS__                              \
        default:                                     \
            break;                                   \
        }                                            \
    }
    PRICE(
        P(
            NAME(MAY_BAY_THUONG_MAI),
            CMD(799))
        P(
            NAME(MAY_BAY_TRUC_THANG),
            CMD(999))
        P(
            NAME(XE_DAP),
            CMD(15))
        P(
            NAME(XE_KHACH),
            CMD(495))
        P(
            NAME(XE_MAY),
            CMD(95))
        P(
            NAME(TAU_THUY),
            CMD(599))
        P(
            NAME(CA_NO),
            CMD(899)))