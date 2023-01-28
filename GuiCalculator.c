/*
 * @file GuiCalulator.c
 * @author Lascelle Mckenzie
 * @date December 21, 2022
 * @brief Creating a scientific calculator
	Key functions to check over 
	g_print("%s\n",equation);
	GDK_BUTTON_PRESS
	GDK_BUTTON_RELEASE
	GDK_BUTTON_PRESS
	GDK_2BUTTON_PRESS
	GDK_BUTTON_RELEASE
	gtk_label_set_text(GTK_LABEL(label[0]),"Wah gwan");
	view[0] = gtk_text_view_new(); 
	view[1] = gtk_text_view_new();
	gtk_widget_set_visible(label[2],false);
	gtk_widget_set_visible(label[3],false);
	gtk_text_view_set_editable(GTK_TEXT_VIEW(view[0]),false);
	gtk_text_view_set_editable(GTK_TEXT_VIEW(view[1]),false);
	To Change Color of view
	GdkRGBA text_color;
	gdk_rgba_parse (&text_color, "white");
	gtk_widget_override_color (box, GTK_STATE_FLAG_INSENSITIVE, &text_color);
	gtk_widget_set_sensitive(GTK_WIDGET(view[0]),FALSE);
	gtk_widget_set_sensitive(GTK_WIDGET(view[1]),FALSE);
	
	⁰ ¹ ² ³ ⁴ ⁵ ⁶ ⁷ ⁸ ⁹ ⁺ ⁻ ⁼ ⁽ ⁾  
	₀ ₁ ₂ ₃ ₄ ₅ ₆ ₇ ₈ ₉ ₊ ₋ ₌ ₍ ₎  
	ᵃ ᵇ ᶜ ᵈ ᵉ ᶠ ᵍ ʰ ⁱ ʲ ᵏ ˡ ᵐ ⁿ ᵒ ᵖ ʳ ˢ ᵗ ᵘ ᵛ ʷ ˣ ʸ ᶻ  
	ᴬ ᴮ ᴰ ᴱ ᴳ ᴴ ᴵ ᴶ ᴷ ᴸ ᴹ ᴺ ᴼ ᴾ ᴿ ᵀ ᵁ ⱽ ᵂ  
	ₐ ₑ ₕ ᵢ ⱼ ₖ ₗ ₘ ₙ ₒ ₚ ᵣ ₛ ₜ ᵤ ᵥ ₓ 
	ᵅ ᵝ ᵞ ᵟ ᵋ ᶿ ᶥ ᶲ ᵠ ᵡ  
	ᵦ ᵧ ᵨ ᵩ ᵪ   
*/

#include<math.h> 
#include<stddef.h>
#include<stdint.h> 
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<gtk/gtk.h>

typedef struct{
	GtkWidget *window;
	GtkWidget *grid;
	GtkWidget *button[45];	
}calc;

GtkWidget *box;
GtkWidget *label[4];
GtkWidget *ButtonLabel[24];

char *buffer = NULL;

bool Is_Shift_Active;
bool Is_Alpha_Active;


/*       BASIC MATH EQUATIONS       */
static double Add(float x, float y){
	g_print("\n%lf",x+y);
	return x+y;
}

static double Subtract(float x, float y){
	g_print("\n%lf",x-y);
	return x-y;
}

static double Multiply(float x, float y){
	g_print("\n%lf",x*y);
	return x*y;
}

static double Divide(float x, float y){
	g_print("\n%lf",x/y);
	return x/y;
}


/*     MATHEMATIC FUNCTIONS      */
static long double Power(int base, int exponent){
	double x = pow(base, exponent);
	g_print("%lf",x);
	return x;	
}

static float Factorial(int num){
	float factorial=1;
	for(size_t i = 1; i<=num; i++){
		factorial = factorial * i;	
	}
	g_print("\n%f", factorial);
	return factorial;
}

static long double CubeRoot(double x){
	double result;
	result = cbrt(x);
	g_print("\n%lf",result);
	return result;
}

static long double SquareRoot(double x){
	double result;
	result = sqrt(x);
	g_print("\n%lf",result);
	return result;
}

/*       Trigonomitry       */
static long double SinFunc(int x){

	double result = sin(x);
	g_print("\n%lf",result);
	return result;
}

static long double InverseSinFunc(double x){

	double result = asin(x);
	g_print("\n%lf",result);
	return result;
}

static long double CosFunc(double x){
	double result = cos(x);
	g_print("\n%lf",result);
	return result;
}

static long double InverseCosFunc(double x){
	double result = acos(x);
	g_print("\n%lf",result);
	return result;
}

static long double TanFunc(double x){
	double result = tan(x);
	g_print("\n%lf",result);
	return result;
}

static long double InverseTanFunc(double x){
	double result = atan(x);
	g_print("\n%lf",result);
	return result;
}

static long double RandomNumber(){
	 srand((unsigned int) time(NULL));
	 g_print("\n%.3f", ((float) rand() / (float)(RAND_MAX)));
}

/**
 * @detail
 * @param  equation 
 * @return NULL 
 */
static void SplitEquation(char *equation){
/*	
	int *numPtr = NULL;
	int numcount=0;
	
	for(size_t i=0;i<strlen(equation);i++){	
		if(isdigit(equation[i])){
			numcount++;	
		}
		else if(isalpha(equation[i])){



		}
	}
	
	numPtr = (int*) malloc(numcount * sizeof(int));

	for(int i=0; i<numcount; i++)
		numPtr[i] = equation[i] - '0'; //Convert a char to int
	
	for(size_t i=0;i < (sizeof(numPtr)/4) + 1;i++){  //Amount of elements in the thing
		g_print("%d\n",numPtr[i]);
	}

	free(numPtr);
*/
}

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
static void AddToBuffer(const char *text){
	if(buffer==NULL){
		buffer = (char *) malloc (strlen(text));
		strcpy (buffer, text);
	}else{
		buffer = (char *) realloc (buffer, ((strlen(buffer)) + (strlen(text)))); 	
		strcat(buffer, text);
	}
	gtk_entry_set_text(GTK_ENTRY(box), buffer);
}

/**
 * @detail
 * @param  text 
 * @return NULL 
 */

static void RemoveFromBuffer(){
	if(buffer!=NULL){
		buffer[strlen(buffer)-1] = '\0';
		gtk_entry_set_text(GTK_ENTRY(box), buffer);
	}
}

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
static void ClearBuffer(){
	free(buffer);
	buffer = NULL;
	gtk_entry_set_text(GTK_ENTRY(box), " ");
}

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
gboolean Shift_Clicked(GtkWidget *widget, GdkEventButton *event, gpointer user_data){
		
	/*
	Power(8, -1);
	Factorial(7);
	CubeRoot(8);
	SquareRoot(9);
	Add(1,2);
	Subtract(10, 8);
	Divide(4, 2);
	Multiply(5, 10);
	SinFunc(10);
	CosFunc(10);
	TanFunc(10);
	InverseSinFunc(0.2);
	InverseCosFunc(0.3);
	InverseTanFunc(10);
	RandomNumber();
	*/

	if(event->type == GDK_BUTTON_PRESS){
		switch(Is_Shift_Active){
			case true:
				gtk_widget_hide(label[2]);
				Is_Shift_Active = false;
				break;
			case false:
				if(!Is_Alpha_Active){
					gtk_widget_show(label[2]);
					Is_Shift_Active = true;
				}
				if(Is_Alpha_Active){	
					gtk_widget_hide(label[3]);
					Is_Alpha_Active = false;
					gtk_widget_show(label[2]);
					Is_Shift_Active = true;
				}
				break;
		}	
	}	
	return TRUE;
}

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
gboolean Alpha_Clicked(GtkWidget *widget, GdkEventButton *event, gpointer user_data){
		
	if(event->type == GDK_BUTTON_PRESS){
		switch(Is_Alpha_Active){
			case true:
				gtk_widget_hide(label[3]);
				Is_Alpha_Active = false;
				break;
			case false:
				if(!Is_Shift_Active){
					gtk_widget_show(label[3]);
					Is_Alpha_Active = true;
				}
				if(Is_Shift_Active){
					gtk_widget_hide(label[2]);
					Is_Shift_Active = false;
					gtk_widget_show(label[3]);
					Is_Alpha_Active = true;
				}
				break;
		}	
	}	
	return TRUE;
}

/*Dynamically allocating the memory for the string
 * First We get allocate the size of the buffer by using the size of the
 * text of the button that was entered and the allocate it if the buffer is empty
 * If the buffer is not empty then we reallocate space to the memory of the buffer by adding the 
 * current size of the buffer to the current size of the preceeding text.
 * If C is pressed the we free the memory and then set the buffer back to NULL
 * and output an empty screen
*/
/**
 * @detail
 * @param  text 
 * @return NULL 
 */
static void GetInput(GtkButton *button, gpointer data){

	const gchar* text = gtk_button_get_label(button);
	if(strcmp("ON/CLR",text)==0 || strcmp("AC",text)==0){
		ClearBuffer();
	}
	else if(strcmp("=",text)==0){
		SplitEquation(buffer);
	}
	else{
		if(strcmp("DEL", text)==0){
			RemoveFromBuffer();
		}
		else{
			AddToBuffer(text);	
		}
	}
}

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
static void activate(GtkApplication *app, gpointer user_data){
	calc widget;

	widget.window = gtk_application_window_new(app);
	gtk_window_set_position(GTK_WINDOW(widget.window),GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(widget.window),"Scientific Calculator");
	gtk_window_set_default_size(GTK_WINDOW(widget.window), 400, 500);
	gtk_container_set_border_width(GTK_CONTAINER(widget.window),10);

	widget.grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(widget.window),widget.grid);

	box= gtk_entry_new();

	label[0] = gtk_label_new (" ");
	label[1] = gtk_label_new ("0.");
	label[2] = gtk_label_new ("🅂");
	label[3] = gtk_label_new ("🄰");

	ButtonLabel[0] = gtk_label_new ("x!");
	ButtonLabel[1] = gtk_label_new ("nPr");
	ButtonLabel[2] = gtk_label_new ("Rec(  :");
	ButtonLabel[3] = gtk_label_new ("∛");
	ButtonLabel[4] = gtk_label_new ("d/c");
	ButtonLabel[5] = gtk_label_new ("ˣ√");
	ButtonLabel[6] = gtk_label_new ("10ˣ");
	ButtonLabel[7] = gtk_label_new ("eˣ   e");
	ButtonLabel[8] = gtk_label_new ("A");
	ButtonLabel[9] = gtk_label_new ("B");
	ButtonLabel[10] = gtk_label_new ("C");
	ButtonLabel[11] = gtk_label_new ("sin⁻¹   D");
	ButtonLabel[12] = gtk_label_new ("cos⁻¹   E");
	ButtonLabel[13] = gtk_label_new ("tan⁻¹   F");
	ButtonLabel[14] = gtk_label_new ("STO");
	ButtonLabel[15] = gtk_label_new ("X");
	ButtonLabel[16] = gtk_label_new ("Y");
	ButtonLabel[17] = gtk_label_new ("M");
	ButtonLabel[18] = gtk_label_new ("INS");
	ButtonLabel[19] = gtk_label_new ("OFF");
	ButtonLabel[20] = gtk_label_new ("Rnd");
	ButtonLabel[21] = gtk_label_new ("Ran#");
	ButtonLabel[22] = gtk_label_new ("π");
	ButtonLabel[23] = gtk_label_new ("%");

	gtk_editable_set_editable(GTK_EDITABLE(box), FALSE);
	gtk_widget_set_sensitive(GTK_WIDGET(box),FALSE);
	
	widget.button[0] = gtk_button_new_with_label("0");
	widget.button[1] = gtk_button_new_with_label("1");
	widget.button[2] = gtk_button_new_with_label("2");
	widget.button[3] = gtk_button_new_with_label("3");
	widget.button[4] = gtk_button_new_with_label("4");
	widget.button[5] = gtk_button_new_with_label("5");
	widget.button[6] = gtk_button_new_with_label("6");
	widget.button[7] = gtk_button_new_with_label("7");
	widget.button[8] = gtk_button_new_with_label("8");
	widget.button[9] = gtk_button_new_with_label("9");
	widget.button[10] = gtk_button_new_with_label(".");
	widget.button[11] = gtk_button_new_with_label("+");
	widget.button[12] = gtk_button_new_with_label("-");
	widget.button[13] = gtk_button_new_with_label("x");
	widget.button[14] = gtk_button_new_with_label("÷");
	widget.button[15] = gtk_button_new_with_label("ON/CLR");
	widget.button[16] = gtk_button_new_with_label("=");	
	widget.button[17] = gtk_button_new_with_label("SHIFT");
	widget.button[18] = gtk_button_new_with_label("ALPHA");
	widget.button[19] = gtk_button_new_with_label("MODE");
	widget.button[20] = gtk_button_new_with_label("x⁻¹");
	widget.button[21] = gtk_button_new_with_label("nCr");
	widget.button[22] = gtk_button_new_with_label("Pol(");
	widget.button[23] = gtk_button_new_with_label("x³");
	widget.button[24] = gtk_button_new_with_label("aᵇ/ᶜ");
	widget.button[25] = gtk_button_new_with_label("√");
	widget.button[26] = gtk_button_new_with_label("x²");
	widget.button[27] = gtk_button_new_with_label("^");
	widget.button[28] = gtk_button_new_with_label("log");
	widget.button[29] = gtk_button_new_with_label("ln");
	widget.button[30] = gtk_button_new_with_label("(-)");
	widget.button[31] = gtk_button_new_with_label("₀,,,");
	widget.button[32] = gtk_button_new_with_label("hyp");
	widget.button[33] = gtk_button_new_with_label("sin");
	widget.button[34] = gtk_button_new_with_label("cos");
	widget.button[35] = gtk_button_new_with_label("tan");
	widget.button[36] = gtk_button_new_with_label("RCL");
	widget.button[37] = gtk_button_new_with_label("ENG");
	widget.button[38] = gtk_button_new_with_label("(");
	widget.button[39] = gtk_button_new_with_label(")");
	widget.button[40] = gtk_button_new_with_label(",");
	widget.button[41] = gtk_button_new_with_label("M+");
	widget.button[42] = gtk_button_new_with_label("DEL");
	widget.button[43] = gtk_button_new_with_label("AC");
	widget.button[44] = gtk_button_new_with_label("ANS");
	widget.button[45] = gtk_button_new_with_label("EXP");

	/*  (X-Position, Y-Position, X-Span, Y-Span)  */
	//First Row
	gtk_grid_attach(GTK_GRID(widget.grid),label[0],0,0,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),label[2],1,0,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),label[3],2,0,1,1);
	//Second Row
	gtk_grid_attach(GTK_GRID(widget.grid),box,0,1,6,1);
	//Third Row
	gtk_grid_attach(GTK_GRID(widget.grid),label[1],4,2,2,1);
	//Fourth Row
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[17],0,3,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[18],1,3,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[19],2,3,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[15],3,3,1,1);
	//Fifth Row
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[0],0,4,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[1],1,4,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[2],2,4,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[3],3,4,1,1);
	//Sixth Row
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[20],0,5,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[21],1,5,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[22],2,5,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[23],3,5,1,1);
	//Seventh Row
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[4],0,6,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[5],3,6,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[6],4,6,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[7],5,6,1,1);
	//Eigth Row
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[24],0,7,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[25],1,7,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[26],2,7,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[27],3,7,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[28],4,7,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[29],5,7,1,1);
	//Ninth Row
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[8],0,8,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[9],1,8,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[10],2,8,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[11],3,8,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[12],4,8,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[13],5,8,1,1);
	//Tenth Row
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[30],0,9,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[31],1,9,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[32],2,9,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[33],3,9,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[34],4,9,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[35],5,9,1,1);
	//Eleventh Row
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[14],0,10,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[15],3,10,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[16],4,10,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[17],5,10,1,1);	
	//Twelveth Row 
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[36],0,11,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[37],1,11,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[38],2,11,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[39],3,11,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[40],4,11,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[41],5,11,1,1);
	//Thirteenth Row
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[18],3,12,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[19],4,12,1,1);
	//Fourteenth Row
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[7],0,13,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[8],1,13,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[9],2,13,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[42],3,13,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[43],4,13,1,1);
	//Fifteenth Row
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[4],0,14,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[5],1,14,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[6],2,14,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[13],3,14,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[14],4,14,1,1);
	//Sixteenth Row
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[1],0,15,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[2],1,15,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[3],2,15,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[11],3,15,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[12],4,15,1,1);
	//Seventeenth Row
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[20],0,16,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[21],1,16,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[22],2,16,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),ButtonLabel[23],4,16,1,1);
	//Eighteenth Row
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[0],0,17,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[10],1,17,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[45],2,17,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[44],3,17,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[16],4,17,1,1);	

	//Each button onclick will go the getinput function	
	g_signal_connect(widget.button[17], "button-press-event", G_CALLBACK(Shift_Clicked), NULL);
	g_signal_connect(widget.button[18], "button-press-event", G_CALLBACK(Alpha_Clicked), NULL);
	g_signal_connect(widget.button[0],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[1],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[2],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[3],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[4],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[5],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[6],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[7],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[8],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[9],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[10],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[11],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[12],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[13],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[14],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[15],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[16],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[19],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[20],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[21],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[22],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[23],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[24],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[25],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[26],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[27],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[28],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[29],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[30],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[31],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[32],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[33],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[34],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[35],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[36],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[37],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[38],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[39],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[40],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[41],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[42],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[43],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[44],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[45],"clicked",G_CALLBACK(GetInput), NULL);

	gtk_widget_show_all(widget.window);

	gtk_widget_hide(label[2]);
	gtk_widget_hide(label[3]);
	Is_Shift_Active = false;
	Is_Alpha_Active = false;
}

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
int main(int argc, char **argv){
	GtkApplication *app;
	gtk_init(&argc, &argv);
	int status;
	app = gtk_application_new("org.gtk.calculator", G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect(app,"activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);
	return status;
}
