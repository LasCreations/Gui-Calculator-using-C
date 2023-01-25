//Creating a scientific calculator


#include<gtk/gtk.h>

#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include <math.h>

typedef struct{
	GtkWidget *window;
	GtkWidget *grid;
	GtkWidget *button[45];
}calc;

GtkWidget *box;

#define SIZE 10

char input_buffer[100] = {0};
char output_buffer[100] = {0};

bool clear_buffer = false;
bool add=false;
bool mul = false;
bool divv = false;
bool sub = false;

float result = 0.0;
static float num[SIZE];
int count = 0;

static void calculate(GtkButton *button, gpointer data){

	const gchar* text = gtk_button_get_label(button);

	if( (strcmp("+", text)==0) ||   (strcmp("-", text)==0) ||  (strcmp("/", text)==0) ||  (strcmp("x", text)==0) ||  (strcmp("=", text)==0) ){
		
		num[count] = atof(input_buffer);
		count++;
		clear_buffer = true;

		if(strcmp("+",text)==0){
			add = true;
		}
		if(strcmp("-",text)==0){
			sub = true;
		}
		if(strcmp("/",text)==0){
			divv = true;
		}
		if(strcmp("x",text)==0){
			mul = true;
		}
	}

	if(strcmp("=",text)==0){
		int x = sizeof(num)/sizeof(num[0]);
		
		if(add){
			for(int i=0; i<x; i++){
				result += num[i];
			}
		}

		if(divv){
			result = num[0]/num[1];
		}

		if(sub){
				if(result == 0.0){
					result = num[0]*2;
				}
			for(int i=0; i<x; i++){
				result -= num[i];
			}
		}
	
		if(mul){
			result = num[0]*num[1];
		}

		add = false;
		mul = false;
		divv = false;
		sub = false;
		
		gtk_entry_set_text(GTK_ENTRY(box), "");
		sprintf(output_buffer, "%.3f", result);
		gtk_entry_set_text(GTK_ENTRY(box), output_buffer);
		result = 0.0;
	}
	else{
		if(clear_buffer){
			memset(input_buffer,0,strlen(input_buffer));
			clear_buffer = false;
		}else{
			strncat(input_buffer,text, 1);
		}
		
			strncat(output_buffer,text, 1);
			gtk_entry_set_text(GTK_ENTRY(box), output_buffer);
	}
		
	if(strcmp("C",text)==0){
		gtk_entry_set_text(GTK_ENTRY(box), "");
		memset(input_buffer,0,strlen(input_buffer));
		memset(output_buffer,0,strlen(output_buffer));

		count = 0;
		int x = sizeof(num)/sizeof(num[0]);
		
		for(int i=0; i<x; i++){
				num[i] = 0;
		}

		add = false;
		mul = false;
		divv = false;
		sub = false;
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
	widget.button[15] = gtk_button_new_with_label("C");
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

	g_signal_connect(widget.button[0],"clicked",G_CALLBACK(calculate), NULL);
	g_signal_connect(widget.button[1],"clicked",G_CALLBACK(calculate), NULL);
	g_signal_connect(widget.button[2],"clicked",G_CALLBACK(calculate), NULL);
	g_signal_connect(widget.button[3],"clicked",G_CALLBACK(calculate), NULL);
	g_signal_connect(widget.button[4],"clicked",G_CALLBACK(calculate), NULL);
	g_signal_connect(widget.button[5],"clicked",G_CALLBACK(calculate), NULL);
	g_signal_connect(widget.button[6],"clicked",G_CALLBACK(calculate), NULL);
	g_signal_connect(widget.button[7],"clicked",G_CALLBACK(calculate), NULL);
	g_signal_connect(widget.button[8],"clicked",G_CALLBACK(calculate), NULL);
	g_signal_connect(widget.button[9],"clicked",G_CALLBACK(calculate), NULL);
	g_signal_connect(widget.button[10],"clicked",G_CALLBACK(calculate), NULL);
	g_signal_connect(widget.button[11],"clicked",G_CALLBACK(calculate), NULL);
	g_signal_connect(widget.button[12],"clicked",G_CALLBACK(calculate), NULL);
	g_signal_connect(widget.button[13],"clicked",G_CALLBACK(calculate), NULL);
	g_signal_connect(widget.button[14],"clicked",G_CALLBACK(calculate), NULL);
	g_signal_connect(widget.button[15],"clicked",G_CALLBACK(calculate), NULL);
	g_signal_connect(widget.button[16],"clicked",G_CALLBACK(calculate), NULL);

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
