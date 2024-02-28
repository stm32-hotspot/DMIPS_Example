#include "dhrystone.h"
#include "stdlib.h"

/* Macro definitions */

#ifndef REG_ENABLE
Boolean Reg = false;  //this variable is used to output on the terminal if the register declarations are enabled
/* REG becomes defined as empty */
/* i.e. no register variables   */
#else
Boolean Reg = true;
#endif

#define Too_Small_Time (2*HERTZ)  //the test should run for a minimum of 2 seconds


/* Global Variables: */
Rec_Pointer     Ptr_Glob, Next_Ptr_Glob;
int             Int_Glob;
Boolean         Bool_Glob;
char            Ch_1_Glob, Ch_2_Glob;
int             Arr_1_Glob [50];
int             Arr_2_Glob [50] [50];

uint32_t            Begin_Time, End_Time, User_Time;
float           Microseconds, Dhrystones_Per_Second;


/* Private Variables: */
extern uint8_t receive[];
/*****/

/* main program, corresponds to procedures        */
/* Main and Proc_0 in the Ada version             */
void start_Test()
{
	One_Fifty       Int_1_Loc;
	REG   One_Fifty       Int_2_Loc;
	One_Fifty       Int_3_Loc;
	REG   char            Ch_Index;
	Enumeration     Enum_Loc;
	Str_30          Str_1_Loc;
	Str_30          Str_2_Loc;
	REG   uint32_t             Run_Index;
	REG   uint32_t             Number_Of_Runs;
	char temp[100];

	/* Initializations */

	Next_Ptr_Glob = (Rec_Pointer) malloc (sizeof (Rec_Type));
	Ptr_Glob = (Rec_Pointer) malloc (sizeof (Rec_Type));

	Ptr_Glob->Ptr_Comp                    = Next_Ptr_Glob;
	Ptr_Glob->Discr                       = Ident_1;
	Ptr_Glob->variant.var_1.Enum_Comp     = Ident_3;
	Ptr_Glob->variant.var_1.Int_Comp      = 40;
	strcpy (Ptr_Glob->variant.var_1.Str_Comp,"DHRYSTONE PROGRAM, SOME STRING");
	strcpy (Str_1_Loc, "DHRYSTONE PROGRAM, 1'ST STRING");

	Arr_2_Glob [8][7] = 10;
	/* Was missing in published program. Without this statement,    */
	/* Arr_2_Glob [8][7] would have an undefined value.             */
	/* Warning: With 16-Bit processors and Number_Of_Runs > 32000,  */
	/* overflow may occur for this array element.                   */
	Serial_PutString((uint8_t*)"\n\rDhrystone Benchmark, Version 2.1 (Language: C)\n\n\r");
	if (Reg)
	{
		Serial_PutString((uint8_t*)"Program compiled with 'register' attribute\n\n\r");
	}
	else
	{
		Serial_PutString((uint8_t*)"Program compiled without 'register' attribute\n\n\r");
	}
	start:
	Serial_PutString((uint8_t*)"Please give the number of runs through the benchmark: ");
	{
		Serial_GetString();
		Number_Of_Runs = atoi((char*)receive);
	}
	sprintf(temp,"\rExecution starts, %u runs through Dhrystone\n\r", Number_Of_Runs);
	Serial_PutString((uint8_t*)temp);

	/***************/
	/* Start timer */
	/***************/
	Begin_Time=startTimer();
	

	for (Run_Index = 1; Run_Index <= Number_Of_Runs; ++Run_Index)
	{

		Proc_5();
		Proc_4();
		/* Ch_1_Glob == 'A', Ch_2_Glob == 'B', Bool_Glob == true */
		Int_1_Loc = 2;
		Int_2_Loc = 3;
		strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 2'ND STRING");
		Enum_Loc = Ident_2;
		Bool_Glob = ! Func_2 (Str_1_Loc, Str_2_Loc);
		/* Bool_Glob == 1 */
		while (Int_1_Loc < Int_2_Loc)  /* loop body executed once */
		{
			Int_3_Loc = 5 * Int_1_Loc - Int_2_Loc;
			/* Int_3_Loc == 7 */
			Proc_7 (Int_1_Loc, Int_2_Loc, &Int_3_Loc);
			/* Int_3_Loc == 7 */
			Int_1_Loc += 1;
		} /* while */
		/* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
		Proc_8 (Arr_1_Glob, Arr_2_Glob, Int_1_Loc, Int_3_Loc);
		/* Int_Glob == 5 */
		Proc_1 (Ptr_Glob);
		for (Ch_Index = 'A'; Ch_Index <= Ch_2_Glob; ++Ch_Index)
			/* loop body executed twice */
		{
			if (Enum_Loc == Func_1 (Ch_Index, 'C'))
				/* then, not executed */
			{
				Proc_6 (Ident_1, &Enum_Loc);
				strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 3'RD STRING");
				Int_2_Loc = Run_Index;
				Int_Glob = Run_Index;
			}
		}
		/* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
		Int_2_Loc = Int_2_Loc * Int_1_Loc;
		Int_1_Loc = Int_2_Loc / Int_3_Loc;
		Int_2_Loc = 7 * (Int_2_Loc - Int_3_Loc) - Int_1_Loc;
		/* Int_1_Loc == 1, Int_2_Loc == 13, Int_3_Loc == 7 */
		Proc_2 (&Int_1_Loc);
		/* Int_1_Loc == 5 */

	} /* loop "for Run_Index" */

	/**************/
	/* Stop timer */
	/**************/
	End_Time=stopTimer();



	Serial_PutString((uint8_t*)"\rExecution ends\n\n");
	Serial_PutString((uint8_t*)"Final values of the variables used in the benchmark:\n\n\r");
	Serial_PutString((uint8_t*)"");
	sprintf(temp,"Int_Glob:            %d\n\r", Int_Glob);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"        should be:   %d\n\r", 5);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"Bool_Glob:           %d\n\r", Bool_Glob);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"        should be:   %d\n\r", 1);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"Ch_1_Glob:           %c\n\r", Ch_1_Glob);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"        should be:   %c\n\r", 'A');
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"Ch_2_Glob:           %c\n\r", Ch_2_Glob);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"        should be:   %c\n\r", 'B');
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"Arr_1_Glob[8]:       %d\n\r", Arr_1_Glob[8]);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"        should be:   %d\n\r", 7);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"Arr_2_Glob[8][7]:    %d\n\r", Arr_2_Glob[8][7]);
	Serial_PutString((uint8_t*)temp);
	Serial_PutString((uint8_t*)"        should be:   Number_Of_Runs + 10\n\rPtr_Glob->\n\r");
	sprintf(temp,"Ptr_Comp:          %d\n\r", (int) Ptr_Glob->Ptr_Comp);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"        should be:   (implementation-dependent)\n\r");
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"  Discr:             %d\n\r", Ptr_Glob->Discr);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"        should be:   %d\n\r", 0);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"  Enum_Comp:         %d\n\r", Ptr_Glob->variant.var_1.Enum_Comp);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"        should be:   %d\n\r", 2);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"  Int_Comp:          %d\n\r", Ptr_Glob->variant.var_1.Int_Comp);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"        should be:   %d\n\r", 17);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"  Str_Comp:          %s\n\r", Ptr_Glob->variant.var_1.Str_Comp);
	Serial_PutString((uint8_t*)temp);
	Serial_PutString((uint8_t*)"        should be:   DHRYSTONE PROGRAM, SOME STRING\n\rNext_Ptr_Glob->\n\r");
	sprintf(temp,"  Ptr_Comp:          %d\n\r", (int) Next_Ptr_Glob->Ptr_Comp);
	Serial_PutString((uint8_t*)temp);
	Serial_PutString((uint8_t*)"        should be:   (implementation-dependent), same as above\n\r");
	sprintf(temp,"  Discr:             %d\n\r", Next_Ptr_Glob->Discr);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"        should be:   %d\n\r", 0);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"  Enum_Comp:         %d\n\r", Next_Ptr_Glob->variant.var_1.Enum_Comp);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"        should be:   %d\n\r", 1);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"  Int_Comp:          %d\n\r", Next_Ptr_Glob->variant.var_1.Int_Comp);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"        should be:   %d\n\r", 18);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp," Str_Comp:          %s\n\r",Next_Ptr_Glob->variant.var_1.Str_Comp);
	Serial_PutString((uint8_t*)temp);
	Serial_PutString((uint8_t*)"        should be:   DHRYSTONE PROGRAM, SOME STRING\n\r");
	sprintf(temp,"Int_1_Loc:           %d\n\r", Int_1_Loc);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"        should be:   %d\n\r", 5);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"Int_2_Loc:           %d\n\r", Int_2_Loc);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"        should be:   %d\n\r", 13);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"Int_3_Loc:           %d\n\r", Int_3_Loc);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"        should be:   %d\n\r", 7);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"Enum_Loc:            %d\n\r", Enum_Loc);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"        should be:   %d\n\r", 1);
	Serial_PutString((uint8_t*)temp);
	sprintf(temp,"Str_1_Loc:           %s\n\r", Str_1_Loc);
	Serial_PutString((uint8_t*)temp);
	Serial_PutString((uint8_t*)"       should be:   DHRYSTONE PROGRAM, 1'ST STRING\n\r");
	sprintf(temp,"Str_2_Loc:           %s\n\r", Str_2_Loc);
	Serial_PutString((uint8_t*)temp);
	Serial_PutString((uint8_t*)"        should be:   DHRYSTONE PROGRAM, 2'ND STRING\n\n\r");


	User_Time = End_Time - Begin_Time;

	if (User_Time < Too_Small_Time)
	{
		Serial_PutString((uint8_t*)"\rMeasured time too small to obtain meaningful results\n\rPlease increase number of runs\n\r");
		goto start;
	}
	else
	{

		Microseconds = (float) User_Time * Mic_secs_Per_Second 
				/ ((float) HERTZ *  ((float) Number_Of_Runs));
		Dhrystones_Per_Second = ((float) HERTZ   * (float) Number_Of_Runs)
                        		/ (float) User_Time;

		sprintf (temp,"CPU freq: %d\n\r",HERTZ);
		Serial_PutString((uint8_t*)temp);
		sprintf (temp,"MDK-ARM version: %d (Read the version as xyz = x.yz)\n\r",__UVISION_VERSION);
		Serial_PutString((uint8_t*)temp);
		sprintf (temp,"ARM Compiler version: %d (Read the version as xyz0000 = x.yz0000) \n\r",__ARMCC_VERSION); //for ARM Compilers 5 you might have to use the macro __CC_ARM
		Serial_PutString((uint8_t*)temp);
		sprintf(temp,"Microseconds for one run through Dhrystone: %6.1f \n\r", Microseconds);
		Serial_PutString((uint8_t*)temp);
		sprintf(temp,"Dhrystones per Second:                      %6.1f \n\r", Dhrystones_Per_Second);
		Serial_PutString((uint8_t*)temp);
		sprintf(temp,"DMIPS:                      %6.1f \n\r", (Dhrystones_Per_Second/VAX_DHRYSTONE_VALUE));
		Serial_PutString((uint8_t*)temp);
		sprintf(temp,"DMIPS/MHz:                      %6.1f \n\r", ((Dhrystones_Per_Second/VAX_DHRYSTONE_VALUE)*MEGA_HERTZ)/HERTZ);
		Serial_PutString((uint8_t*)temp);
	}

}

/******************/


/* executed once */
void Proc_1 (REG Rec_Pointer Ptr_Val_Par)

{
	REG Rec_Pointer Next_Record = Ptr_Val_Par->Ptr_Comp;
	/* == Ptr_Glob_Next */
			/* Local variable, initialized with Ptr_Val_Par->Ptr_Comp,    */
	/* corresponds to "rename" in Ada, "with" in Pascal           */

	structassign (*Ptr_Val_Par->Ptr_Comp, *Ptr_Glob);
	Ptr_Val_Par->variant.var_1.Int_Comp = 5;
	Next_Record->variant.var_1.Int_Comp
	= Ptr_Val_Par->variant.var_1.Int_Comp;
	Next_Record->Ptr_Comp = Ptr_Val_Par->Ptr_Comp;
	Proc_3 (&Next_Record->Ptr_Comp);
	/* Ptr_Val_Par->Ptr_Comp->Ptr_Comp
                        == Ptr_Glob->Ptr_Comp */
	if (Next_Record->Discr == Ident_1)
		/* then, executed */
	{
		Next_Record->variant.var_1.Int_Comp = 6;
		Proc_6 (Ptr_Val_Par->variant.var_1.Enum_Comp,
				&Next_Record->variant.var_1.Enum_Comp);
		Next_Record->Ptr_Comp = Ptr_Glob->Ptr_Comp;
		Proc_7 (Next_Record->variant.var_1.Int_Comp, 10,
				&Next_Record->variant.var_1.Int_Comp);
	}
	else /* not executed */
		structassign (*Ptr_Val_Par, *Ptr_Val_Par->Ptr_Comp);
} /* Proc_1 */


/******************/
/* executed once */
/* *Int_Par_Ref == 1, becomes 4 */
void Proc_2 (One_Fifty   *Int_Par_Ref)
{
	One_Fifty  Int_Loc;
	Enumeration   Enum_Loc;

	Int_Loc = *Int_Par_Ref + 10;
	do /* executed once */
		if (Ch_1_Glob == 'A')
			/* then, executed */
		{
			Int_Loc -= 1;
			*Int_Par_Ref = Int_Loc - Int_Glob;
			Enum_Loc = Ident_1;
		} /* if */
	while (Enum_Loc != Ident_1); /* true */
} /* Proc_2 */

/******************/
/* executed once */
/* Ptr_Ref_Par becomes Ptr_Glob */
void Proc_3 (Rec_Pointer *Ptr_Ref_Par)
{
	if (Ptr_Glob != Null)
		/* then, executed */
		*Ptr_Ref_Par = Ptr_Glob->Ptr_Comp;
	Proc_7 (10, Int_Glob, &Ptr_Glob->variant.var_1.Int_Comp);
} /* Proc_3 */

/*******/
/* executed once */
void Proc_4() /* without parameters */
{
	Boolean Bool_Loc;

	Bool_Loc = Ch_1_Glob == 'A';
	Bool_Glob = Bool_Loc | Bool_Glob;
	Ch_2_Glob = 'B';
} /* Proc_4 */

/*******/
/* executed once */
void Proc_5() /* without parameters */

{
	Ch_1_Glob = 'A';
	Bool_Glob = false;
} /* Proc_5 */




#ifdef  NOSTRUCTASSIGN
memcpy (d, s, l)
register char   *d;
register char   *s;
register int    l;
{
	while (l--) *d++ = *s++;
}
#endif
