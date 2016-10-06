/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SalesData.h
 * Author: HydraSniper
 *
 * Created on October 5, 2016, 10:02 PM
 */

#ifndef SALESDATA_H
#define SALESDATA_H

struct SalesData {
    string divname; //Name of the Division
    float fiquart; //First Quarter
    float sequart; //Second Quarter
    float thquart; //Third Quarter
    float foquart; //Fourth Quarter
    float total; //Total Annual Sales
    float avgqt; //Average Quarterly Sales 
};


#endif /* SALESDATA_H */

