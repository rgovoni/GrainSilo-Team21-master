/*
 * Silo.c
 *
 * Multiple particle dynamics simulation
 *
 * (c) 2016 Joris Remmers TU/e
 */


#include "mylib.h"
#include "mylib.c"

int main( void )

{  
  int          iCyc  = 0;            // Cycle counter
  int          iPlot = 0;            // Plot counter
  char         svgfile[20];          // File name for output
  double       ekin  = 0.0;          // Kinetic Energy

  Plist        plist;
  Clist        clist;

  read_input( "silo.dat" , &plist );
  make_cell( &plist , &clist );
  match_cell( &plist , &clist );
	
  printf("Cells and Particles in linked list:");

  printf("\n---------head-------\n");
  int iCell;
  for ( iCell = 0 ; iCell < MAX_CELLS ; iCell++)
  {
    printf(" %d |", clist.head[iCell]);
  }

  printf("\n--------next-------\n");
  int iPar;
  for ( iPar = 0 ; iPar < plist.ntot ; iPar++)
  {
    printf(" %d | ", clist.next[iPar]);	  
  }
	//test for nearest neighbors


  return 0;
}
