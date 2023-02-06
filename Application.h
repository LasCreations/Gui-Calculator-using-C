#include<gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct{
	GtkWidget *window;
	GtkWidget *grid;
	GtkWidget *button[45];	
}calc;

GtkWidget *box;
GtkWidget *label[7];
GtkWidget *ButtonLabel[24];

bool Is_Shift_Active;
bool Is_Alpha_Active;
bool Is_Hyperbolic_Active;

//Degree, Radian and Gradian mode
bool Is_Radian_Active;
bool Is_Degree_Active;
bool Is_Gradian_Active;

char *buffer = NULL;

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
static void activate(GtkApplication*, gpointer);

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
gboolean Shift_Clicked(GtkButton *button, GdkEventButton *event, gpointer user_data);

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
gboolean Alpha_Clicked(GtkWidget *widget, GdkEventButton *event, gpointer user_data);

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
gboolean Hyperbolic_Clicked(GtkWidget*, GdkEventButton*, gpointer);

/**
 * @detail Dynamically allocating the memory for the string
 * First We get allocate the size of the buffer by using the size of the
 * text of the button that was entered and the allocate it if the buffer is empty
 * If the buffer is not empty then we reallocate space to the memory of the buffer by adding the 
 * current size of the buffer to the current size of the preceeding text.
 * If C is pressed the we free the memory and then set the buffer back to NULL
 * and output an empty screen
 * @param  text 
 * @return NULL 
 */
static void AddToBuffer(const char *text);

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
static void ClearBuffer();

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
static void RemoveFromBuffer();

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
static void GetInput(GtkButton *button, gpointer data);

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
gboolean X_To_Neg_1_Clicked(GtkButton *button, GdkEventButton *event, gpointer user_data);

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
gboolean Computations_Clicked(GtkButton *button, GdkEventButton *event, gpointer user_data);

/**
 * @detail (1) Rectangular Coordinates (Rec)
           (2) Polar Coordinates (Pol
 * @param  text 
 * @return NULL 
 */
gboolean Polar_Coordinates_Clicked(GtkButton *button, GdkEventButton *event, gpointer user_data);

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
gboolean Cube_Clicked(GtkButton *button, GdkEventButton *event, gpointer user_data);

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
gboolean Fraction_Clicked(GtkButton *button, GdkEventButton *event, gpointer user_data);

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
gboolean SquareRoot_Clicked(GtkButton *button, GdkEventButton *event, gpointer user_data);

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
gboolean Squared_Clicked(GtkButton *button, GdkEventButton *event, gpointer user_data);

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
gboolean Power_Clicked(GtkButton *button, GdkEventButton *event, gpointer user_data);

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
gboolean Log_Clicked(GtkButton *button, GdkEventButton *event, gpointer user_data);

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
gboolean Natural_Log_Clicked(GtkButton *button, GdkEventButton *event, gpointer user_data);

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
gboolean Negative_Clicked(GtkButton *button, GdkEventButton *event, gpointer user_data);

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
gboolean Degree_Clicked(GtkButton *button, GdkEventButton *event, gpointer user_data);

/**
 *
 * @detail
 * @param  text 
 * @return NULL 
 */
gboolean Sine_Clicked(GtkButton *button, GdkEventButton *event, gpointer user_data);

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
gboolean Cosine_Clicked(GtkButton *button, GdkEventButton *event, gpointer user_data);

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
gboolean Tan_Clicked(GtkButton *button, GdkEventButton *event, gpointer user_data);








/**
 * @detail
 * @param  text 
 * @return NULL 
 */
gboolean Number_Clicked(GtkButton *button, GdkEventButton *event, gpointer user_data);

/**
 * @detail
 * @param  text 
 * @return NULL 
 */
gboolean Delete_Clicked(GtkButton *button, GdkEventButton *event, gpointer user_data);


