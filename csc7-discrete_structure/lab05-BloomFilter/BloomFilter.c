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
	Date: 9 May 2016
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GeneralHashFunctions.h"


int main(int argc, char* argv[])
{
	const int SIZE=15, SIZE2=75;
	char *key = "Jiwon Yoo";
	char *key2[20];
	FILE *fp;
	int bfilter[SIZE], bfilter2[SIZE2];
	int rs,js,pjw,elf,bkdr,sdbm,djb,dek,bph,fnv,ap;
	int i, len=36;

	printf("\n\n ===== part 1 =====\n");
	memset( bfilter,0,sizeof(bfilter));
	printf("Key: %s\n",key);

	rs= RSHash(key,len)%SIZE;
	js= JSHash(key,len)%SIZE;

	printf("RSHash: %d\n", rs);
	printf("JSHash: %d\n", js);

	bfilter[ rs ] = 1;
	bfilter[ js ] = 1;

	for( i=0;i<SIZE;++i) printf("%d ",bfilter[i]);
	printf("\n");

	printf("\n\n ===== part 2 =====\n");
	memset( bfilter2,0,sizeof(bfilter2));
	fp = fopen("data.dat","r");
	printf(" (kn/m)**k = 1%%\n");
	printf(" m=75, k=9, n=5\n");
	while( fscanf(fp, "%s",*key2)!=EOF ) {
	  rs=RSHash(*key2, len)%SIZE2;
	  js=JSHash(*key2, len)%SIZE2;
	  pjw=PJWHash(*key2, len)%SIZE2;
	  elf=ELFHash(*key2, len)%SIZE2;
	  bkdr=BKDRHash(*key2, len)%SIZE2;
	  sdbm=SDBMHash(*key2, len)%SIZE2;
	  djb=DJBHash(*key2, len)%SIZE2;
	  dek=DEKHash(*key2, len)%SIZE2;
	  bph=BPHash(*key2, len)%SIZE2;
	  fnv=FNVHash(*key2, len)%SIZE2;
	  ap=APHash(*key2, len)%SIZE2;
	  printf("### key=%s \n",*key2);
	  printf("rs=%d\njs=%d\npjw=%d\nelf=%d\nbkdr=%d\nsdbm=%d\ndjb=%d\ndek=%d\nbph=%d\nfnv=%d\nap=%d\n\n",
			rs,js,pjw,elf,bkdr,sdbm,djb,dek,bph,fnv,ap);
	  bfilter2[rs] = 1;
	  bfilter2[js] = 1;
	  bfilter2[pjw] = 1;
	  bfilter2[elf] = 1;
	  bfilter2[bkdr] = 1;
	  bfilter2[sdbm] = 1;
	  bfilter2[djb] = 1;
	  bfilter2[dek] = 1;
	  bfilter2[bph] = 1;
	  bfilter2[fnv] = 1;
	  bfilter2[ap] = 1;
	}
	for( i=0;i<SIZE2;++i) printf("%d ",bfilter2[i]);
	printf("\n");
	fclose(fp);
	return 0;
}
