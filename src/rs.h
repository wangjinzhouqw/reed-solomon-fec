/*
 * rs.h
 *
 *  Created on: Sep 14, 2017
 *      Author: root
 */

#ifndef LIB_RS_H_
#define LIB_RS_H_

#ifdef __cplusplus
extern "C" {
#endif

void rs_encode2(int k,int n,char *data[],int size);

int rs_decode2(int k,int n,char *data[],int size);

#ifdef __cplusplus
}
#endif

#endif

/* LIB_RS_H_ */
