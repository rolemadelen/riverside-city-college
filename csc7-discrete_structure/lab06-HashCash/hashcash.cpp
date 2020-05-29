/*
 **************************************************************************
 *                                                                        *
 *           General Purpose Hash Function Algorithms Test                *
 *                                                                        *
 * Author: Arash Partow - 2002                                            *
 * URL: http://www.partow.net                                             *
 * URL: http://www.partow.net/programming/hashfunctions/index.html        *
 *                                                                        *
 * Copyright notice:                                                      *
 * Free use of the General Purpose Hash Function Algorithms Library is    *
 * permitted under the guidelines and in accordance with the most current *
 * version of the Common Public License.                                  *
 * http://www.opensource.org/licenses/cpl1.0.php                          *
 *                                                                        *
 **************************************************************************
*/

/*
	@Author: Jiwon Yoo
	Date: 18 May 2016
*/
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

#include "GeneralHashFunctions.h"

int main(int argc, char* argv[])
{
	// Declare Variables
	const int SIZE = 11, SIZE2=5;
	fstream file("data.dat", ios::in);
	stringstream ss;
    string key;
	int stats[SIZE2] = {0}; // 10^9, 10^8, 10^7, 10^6, 10^5
	string name[SIZE] = {"RS-Hsash","JS-Hash","PJW-Hash","ELF-Hash", 
					"BKDR-Hash","SDBM-Hash","DJB-Hash", "DEK-Hash",
					"FNV-Hash", "BP-Hash", "AP-Hash"};
	// function pointers
	unsigned (*p[SIZE])( const string & );
	p[0] = &RSHash; p[1] = &JSHash; p[2] = &PJWHash;
	p[3] = ELFHash; p[4] = BKDRHash; p[5] = SDBMHash;
	p[6] = DJBHash; p[7] = DEKHash; p[8] = FNVHash;
	p[9] = BPHash; p[10] = APHash;

	// read data from the file and start hashing
	while( file>>key ) {
		cout << "=================Key: " << key <<  endl;
		for(int i=0;i<SIZE;++i) {
			unsigned val = p[i](key);
			cout << (i+1) << ". " << name[i] << " Function Value: " << val << endl;
			// convert # to string
			ss << val;
			string str;
			ss >> str;
			string tempKey = key;
			// append #
			tempKey+=str;
			ss.clear();
			// hash
			cout << "tempkey: " << tempKey << endl;
			val = p[i](tempKey);
			cout << "hashed value: " << val << endl << endl;
			// take statistics on a hash
			if( val<10e5 ) stats[4]++;
			else if( val<10e6 ) stats[3]++;
			else if( val<10e7 ) stats[2]++;
			else if( val<10e8 ) stats[1]++;
			else if( val<10e9 ) stats[0]++;
		}
	}
	file.close();
	
	for(int i=0;i<SIZE2;++i) {
		cout << " hash < 10^" << (9-i) << ": " << stats[i] << endl;
	}
   return 0;

}
