Big Theta -> both bounds (c1 and c2)
	2n^2 + 3n + 1 == 2n^2 + theta(n)
				  == theta(n^2)
	-- takes the largest bound

Big O -> Upper bound (c2)
Big Omega -> Lower bound (c1)


ex)
Poly(N) = 16N^3 + 256n^2 + 17N + 5235

C1n^3 <= 16n^3+256n^2+17n+5235 <= c2n^3
c1 <= 16 + 256/n + 17/n^2 + 5235/n^3 <= c2 --> as N -> inf
c1 <= 16 <= c2

c1 = 15 && c2 = 17


----------------------------------------		// outer for loop
for(int pos=0; pos<n-1; ++pos)					c(=)  =1
	for(int row=pos+1; row<n; ++row)			c(<)  = n-1
		swap									c(++) = n-1
													// inner for loop
													c(=)  = n-1
													c(<)  = (n-1)(n-1)/2
													c(++) = (n-1)(n-1)/2
														c(swap max) = (n-1)(n-1)/2
														c(swap min) = 0 // already sorted

									-----------------------------------
										C(=)  = 1 + (n-1)
										C(<)  = (n-1) + (n-1)(n-1)/2
										C(++)  = (n-1) + (n-1)(n-1)/2
										C(swap)  = (n-1)(n-1)/2
									-----------------------------------
									// Add all up
									T(n) = (((n-1)^2)/2)C(swap) + ((((n-1)^2)/2) + n-1)C(++) + ((((n-1)^2)/2) + n-1)C(<) + nC(=)
									C(++) = C(<) = C(=) = C(swap)
									
									C1(((n-1)^2)/2) + C2(n-1) + C3N + C4
									// largest bounding is n^2 --> n^2


random 2 digits
--------------------------------------
n		=		++		<		swaps
--------------------------------------
100		100		5049	9999	1887
200		200		20099	39999	5387
400		400		80199	159999	14351
--------------------------------------

random numbers
--------------------------------------
n		=		++		<		swaps
--------------------------------------
100		100		5049	9999	2636
200		200		20099	39999	9410
400		400		80199	159999	38995
--------------------------------------




   		 160k |				(n^2)
   		 140k |			   /
   	  	 120k |			 _/
    	 100k |			/
C(k)      80k |		   /           ------ (n = linear)
      	  60k |	      /      -----/
   	  	  40k |		 /  ----/
    	  20k |	   _/--/
   	       	  |___/  
			  -------------------------------
				1   2    3   4

				 (Hundreds)	

///////////////////////////////////////
let's just look at (less than <)
	summation of C(<) from pos=0 to n-1 	//outer
  + (summation from pos=0 to n-2)(summation from row=pos+1 to n-1) of 2*C(<) // inner
	
->	c(<) (summation of 1 pos=0 to n-2 + (summation pos=0 to n-2)(summation row=pos+1 to n-1) of 2 )
->	c(<) ((n-1)(n-1) summation of 2 from row=pos+1 to n-1  )
->  c(<) ((n-1) + (n-1)n)
->  c(<) (n-1)(n+1) <------ this is the analysis
	ex) n = 100
		c(<) (99)(101)
	


summation of 1 from i=0 to N === N+1
summation of 1 from i=1 to N === N
summation of C(<) from pos=0 to N-2 === C(<) -> C(<)(summation of 1 from pos=0 to n-2)


N		Time		my Computer
40000	7				11
80000   28				44
99999					140
160000  112				
