/*
 * store.h
 *
 *  Created on: Dec 6, 2017
 *      Author: julio.andrade
 */

#ifndef STORE_H_
#define STORE_H_


#include <iostream>
#include <cstdio>
class store {
public:
	store();
	void Save(int key_stroke);
	virtual ~store();
private:
	static FILE *OUTPUT_FILE;
};

#endif /* STORE_H_ */
