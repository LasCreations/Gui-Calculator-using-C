//Creating a scientific calculator

#include<math.h> 
#include<stddef.h>
#include<stdint.h> 
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<gtk/gtk.h>

typedef struct{
	GtkWidget *window;
	GtkWidget *grid;
	GtkWidget *button[45];
	//GtkWidget *ShiftLabel[];
	
}calc;


bool Is_Shift_Clicked = false;

GtkWidget *box;

char *buffer = NULL;


//Return a string or pointer
static void SplitEquation(char *equation){
	//g_print("%s\n",equation);
		



	for(size_t i=0;i<strlen(equation);i++){
		
		if(isdigit(equation[i])){
			
		}
		else if(isalpha(equation[i])){
			
		}
	}
}

/*
 GDK_BUTTON_PRESS

GDK_BUTTON_RELEASE

GDK_BUTTON_PRESS

GDK_2BUTTON_PRESS

GDK_BUTTON_RELEASE

*/

gboolean clicked(GtkWidget *widget, GdkEventButton *event, gpointer user_data){
	
	if(event->type == GDK_BUTTON_PRESS)
		printf("Pressed\n");
	
	return TRUE;
}

static void ShiftClicked(GtkButton *button, gpointer data){
	Is_Shift_Clicked = true;
}

static void GetInput(GtkButton *button, gpointer data){
	

	const gchar* text = gtk_button_get_label(button);

	/*Dynamically allocating the memory for the string
	First We get allocate the size of the buffer by using the size of the
	text of the button that was entered and the allocate it if the buffer is empty
	If the buffer is not empty then we reallocate space to the memory of the buffer by adding the 
	current size of the buffer to the current size of the preceeding text.
	If C is pressed the we free the memory and then set the buffer back to NULL
	and output an empty screen*/
	
	if(strcmp("ON/CLR",text)==0){
		free(buffer);
		buffer = NULL;
		gtk_entry_set_text(GTK_ENTRY(box), " ");
	}
	else if(strcmp("=",text)==0){
		SplitEquation(buffer);
	}
	else{
		if(strcmp("DEL", text)==0){
			buffer[strlen(buffer)-1] = '\0';
			gtk_entry_set_text(GTK_ENTRY(box), buffer);
		}
		else{
			if(buffer==NULL){
				buffer = (char *) malloc (strlen(text));
				strcpy (buffer, text);
			}else{
				buffer = (char *) realloc (buffer, ((strlen(buffer)) + (strlen(text)))); //buffer is reallocated with new size
				strcat(buffer, text);
			}
			gtk_entry_set_text(GTK_ENTRY(box), buffer);

		}
	}
}

static void activate(GtkApplication *app, gpointer user_data){
	
	calc widget;

	widget.window = gtk_application_window_new(app);
	gtk_window_set_position(GTK_WINDOW(widget.window),GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(widget.window),"Scientific Calculator");
	gtk_window_set_default_size(GTK_WINDOW(widget.window), 400, 320);
	gtk_container_set_border_width(GTK_CONTAINER(widget.window),10);

	widget.grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(widget.window),widget.grid);

	box = gtk_entry_new();
	gtk_editable_set_editable(GTK_EDITABLE(box), FALSE);

	/*
	⁰ ¹ ² ³ ⁴ ⁵ ⁶ ⁷ ⁸ ⁹ ⁺ ⁻ ⁼ ⁽ ⁾  
	₀ ₁ ₂ ₃ ₄ ₅ ₆ ₇ ₈ ₉ ₊ ₋ ₌ ₍ ₎  
 
	ᵃ ᵇ ᶜ ᵈ ᵉ ᶠ ᵍ ʰ ⁱ ʲ ᵏ ˡ ᵐ ⁿ ᵒ ᵖ ʳ ˢ ᵗ ᵘ ᵛ ʷ ˣ ʸ ᶻ  
 
	ᴬ ᴮ ᴰ ᴱ ᴳ ᴴ ᴵ ᴶ ᴷ ᴸ ᴹ ᴺ ᴼ ᴾ ᴿ ᵀ ᵁ ⱽ ᵂ  
 
	ₐ ₑ ₕ ᵢ ⱼ ₖ ₗ ₘ ₙ ₒ ₚ ᵣ ₛ ₜ ᵤ ᵥ ₓ 
 
	ᵅ ᵝ ᵞ ᵟ ᵋ ᶿ ᶥ ᶲ ᵠ ᵡ  
 
	ᵦ ᵧ ᵨ ᵩ ᵪ   

	*/

	//Add text to the buttons and attach them to the grid
	
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
	gtk_grid_attach(GTK_GRID(widget.grid),box,0,0,6,1);






	//Second Row
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[17],0,1,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[18],1,1,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[19],2,1,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[15],3,1,2,1);
	
	//Third Row
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[20],0,2,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[21],1,2,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[22],2,2,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[23],3,2,2,1);

	//Fourth Row
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[24],0,3,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[25],1,3,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[26],2,3,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[27],3,3,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[28],4,3,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[29],5,3,1,1);

	//Fifth Row
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[30],0,4,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[31],1,4,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[32],2,4,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[33],3,4,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[34],4,4,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[35],5,4,1,1);

	//Sixth Row
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[36],0,5,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[37],1,5,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[38],2,5,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[39],3,5,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[40],4,5,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[41],5,5,1,1);
	
	//Seventh Row
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[7],0,6,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[8],1,6,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[9],2,6,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[42],3,6,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[43],4,6,1,1);

	//Eigth Row
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[4],0,7,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[5],1,7,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[6],2,7,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[13],3,7,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[14],4,7,1,1);

	//Ninth Row
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[1],0,8,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[2],1,8,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[3],2,8,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[11],3,8,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[12],4,8,1,1);

	//Tenth Row
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[0],0,9,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[10],1,9,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[45],2,9,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[44],3,9,1,1);
	gtk_grid_attach(GTK_GRID(widget.grid),widget.button[16],4,9,1,1);	
	




	//Each button onclick will go the getinput function


	
	g_signal_connect(widget.button[17], "button-press-event", G_CALLBACK(clicked), NULL);

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
	g_signal_connect(widget.button[17],"clicked",G_CALLBACK(GetInput), NULL);
	g_signal_connect(widget.button[18],"clicked",G_CALLBACK(GetInput), NULL);
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
}


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
