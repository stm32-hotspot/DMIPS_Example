/* General definitions: */

#include <stdio.h>
#include "main.h"
#include "string.h" /* for strcpy, strcmp */

/* Macros  */ 
#define Mic_secs_Per_Second     1000000.0
                /* Berkeley UNIX C returns process times in seconds/HZ */
								
#define VAX_DHRYSTONE_VALUE 1757.0

//#define REG_ENABLE

#ifndef REG_ENABLE
#define REG
/* REG becomes defined as empty */
/* i.e. no register variables   */
#else
#define REG register
#endif

#ifdef  NOSTRUCTASSIGN
#define structassign(d, s)      memcpy(&(d), &(s), sizeof(d))
#else
#define structassign(d, s)      d = s
#endif

#ifdef  NOENUM
#define Ident_1 0
#define Ident_2 1
#define Ident_3 2
#define Ident_4 3
#define Ident_5 4
  typedef int   Enumeration;
#else
  typedef       enum    {Ident_1, Ident_2, Ident_3, Ident_4, Ident_5}
                Enumeration;
#endif

#define HERTZ									HAL_RCC_GetSysClockFreq()
#define	MEGA_HERTZ            1000000

#define Null 0
                /* Value of a Null pointer */
#define true  1
#define false 0
	



/* Typedef  */ 
typedef int     One_Thirty;
typedef int     One_Fifty;
typedef char    Capital_Letter;
typedef int     Boolean;
typedef char    Str_30 [31];
typedef int     Arr_1_Dim [50];
typedef int     Arr_2_Dim [50] [50];

typedef struct record
    {
    struct record *Ptr_Comp;
    Enumeration    Discr;
    union {
          struct {
                  Enumeration Enum_Comp;
                  int         Int_Comp;
                  char        Str_Comp [31];
                  } var_1;
          struct {
                  Enumeration E_Comp_2;
                  char        Str_2_Comp [31];
                  } var_2;
          struct {
                  char        Ch_1_Comp;
                  char        Ch_2_Comp;
                  } var_3;
          } variant;
      } Rec_Type, *Rec_Pointer;




// Function Definitions
void start_Test();
void Proc_1 (Rec_Pointer); // check if this correct, idk if you need to use REG
void Proc_2(One_Fifty*);
void Proc_3(Rec_Pointer*);
void Proc_4();
void Proc_5();
void Proc_6(Enumeration,Enumeration*);
void Proc_7(One_Fifty,One_Fifty,One_Fifty*);
void Proc_8(Arr_1_Dim,Arr_2_Dim,int,int);
Enumeration Func_1(Capital_Letter,Capital_Letter);
Boolean Func_2(Str_30,Str_30);
Boolean Func_3(Enumeration);
